#include <stdlib.h>
#include <stdio.h>
#include "grid.h"
#include "util.h"

Jeu * initialize_jeu(){

	Jeu * jeu = malloc(sizeof(Jeu));

	//initialisation de la liste des pièces
	jeu->pieces = malloc(2 * sizeof(int ***));
	jeu->pieces[BLANC] = malloc(6 * sizeof(int **));
	jeu->pieces[NOIR] = malloc(6 * sizeof(int **));
	initialize_pieces(jeu->pieces, BLANC);
	initialize_pieces(jeu->pieces, NOIR);

	//initialisation des cases du plateau
	jeu->plateau = malloc(8 * sizeof(int *));
	for(int i = 0; i < 8; i++){
		jeu->plateau[i] = malloc(8 * sizeof(int));
		for(int j = 0; j < 8; j++){
			jeu->plateau[i][j] = VIDE;
		}
	}

	return jeu;
}

void initialize_pieces(int **** pieces, int color){
	pieces[color][PION] = malloc(8 * sizeof(int *));
	pieces[color][TOUR] = malloc(2 * sizeof(int *));
	pieces[color][CAVALIER] = malloc(2 * sizeof(int *));
	pieces[color][FOU] = malloc(2 * sizeof(int *));
	pieces[color][DAME] = malloc(sizeof(int *));
	pieces[color][ROI] = malloc(sizeof(int *));
}

void add(Jeu * j, char* c){

	//récupération des données
	int color = color_ctoi(c[0]);
	int piece = piece_ctoi(c[1]);
	int * tile = get_tile(j->plateau, c[2], c[3]);

	//initialisation de la pièce
	int i = 0;
	while(j->pieces[color][piece][i] != NULL){
		i++;
	}
	j->pieces[color][piece][i] = tile;
	*tile = (color << 3) + piece;
}

void move(Jeu * j, char* c){
	printf("entree dans la fonction de deplacement\n");
	int * depart = get_tile(j->plateau, c[2], c[3]);
	int * arrivee = get_tile(j->plateau, c[4], c[5]);

	printf("nettoyage de la case d'arrivee\n");
	if(*arrivee != VIDE){
		printf("recuperation de la table de la piece");
		int ** pt = get_piece_table(j->pieces, *arrivee);
		printf("recherche de la piece a deplacer");
		int i = 0;
		while(pt[i] != arrivee){i++;}
		pt[i] = NULL;
	}

	printf("deplacement dans la case d'arrivee");
	*arrivee = *depart;
	int ** pt = get_piece_table(j->pieces, *depart);
	int i = 0;
	while(pt[i] != depart){i++;}
	pt[i] = arrivee;
	*depart = VIDE;
}