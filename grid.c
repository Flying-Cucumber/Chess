#include <stdlib.h>
#include <stdio.h>
#include "grid.h"
#include "util.h"

Jeu * initialize_jeu(){

	Jeu * jeu = malloc(sizeof(Jeu));

	//initialisation de la liste des pièces
	jeu->pieces = malloc(2 * sizeof(Tuile ***));
	jeu->pieces[BLANC] = malloc(6 * sizeof(Tuile **));
	jeu->pieces[NOIR] = malloc(6 * sizeof(Tuile **));
	initialize_pieces(jeu->pieces, BLANC);
	initialize_pieces(jeu->pieces, NOIR);

	//initialisation des cases du plateau
	jeu->plateau = malloc(8 * sizeof(Tuile **));
	for(int i = 0; i < 8; i++){
		jeu->plateau[i] = malloc(8 * sizeof(Tuile *));
		for(int j = 0; j < 8; j++){
			jeu->plateau[i][j] = malloc(sizeof(Tuile));
			jeu->plateau[i][j]->piece = VIDE;
			jeu->plateau[i][j]->menace = NULL;
		}
	}

	return jeu;
}

void initialize_pieces(Tuile **** pieces, int color){
	pieces[color][PION] = malloc(8 * sizeof(Tuile *));
	pieces[color][TOUR] = malloc(2 * sizeof(Tuile *));
	pieces[color][CAVALIER] = malloc(2 * sizeof(Tuile *));
	pieces[color][FOU] = malloc(2 * sizeof(Tuile *));
	pieces[color][DAME] = malloc(sizeof(Tuile *));
	pieces[color][ROI] = malloc(sizeof(Tuile *));
}

void add(Jeu * j, char* c){

	//récupération des données
	int color = color_ctoi(c[0]);
	int piece = piece_ctoi(c[1]);
	Tuile * Tuile = get_tuile(j->plateau, c[2], c[3]);

	//initialisation de la pièce
	int i = 0;
	while(j->pieces[color][piece][i] != NULL){
		i++;
	}
	j->pieces[color][piece][i] = Tuile;
	Tuile->piece = (color << 3) + piece;
}

void move(Jeu * j, char* c){
	
	Tuile * depart = get_tuile(j->plateau, c[2], c[3]);
	Tuile * arrivee = get_tuile(j->plateau, c[4], c[5]);

	if(arrivee->piece != VIDE){
		Tuile ** pt = get_piece_table(j->pieces, arrivee->piece);
		int i = 0;
		while(pt[i] != arrivee){i++;}
		pt[i] = NULL;
	}

	arrivee->piece = depart->piece;
	Tuile ** pt = get_piece_table(j->pieces, depart->piece);
	int i = 0;
	while(pt[i] != depart){i++;}
	pt[i] = arrivee;
	depart->piece = VIDE;
}

void add_menace(Tuile * cible, Tuile * attaque){
	printf("Initialisation de la recherche de la dernière menace\n");
	Menace ** last_menace = &cible->menace;
	printf("Entree dans le while\n");
	while(*last_menace != NULL){
		printf("Menace trouvée! Passage à la suivante\n");
		print_piece((*last_menace)->attaque->piece);
		*last_menace = (*last_menace)->next;
	}
	printf("Définition de la nouvelle dernière menace\n");
	*last_menace = malloc(sizeof(Menace));
	(*last_menace)->attaque = attaque;
	print_menace(cible);
}