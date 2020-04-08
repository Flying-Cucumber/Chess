#include <stdio.h>
#include "grid.h"

int piece_ctoi(char c){
	switch(c){
		case 'P':
			return PION;
			break;
		case 'T':
			return TOUR;
			break;
		case 'C':
			return CAVALIER;
			break;
		case 'F':
			return FOU;
			break;
		case 'D':
			return DAME;
			break;
		case 'R':
			return ROI;
			break;
	}
}

char piece_itoc(int i){
	switch(i){
		case PION:
			return 'P';
			break;
		case TOUR:
			return 'T';
			break;
		case CAVALIER:
			return 'C';
			break;
		case FOU:
			return 'F';
			break;
		case DAME:
			return 'D';
			break;
		case ROI:
			return 'R';
			break;
		default:
			return ' ';
	}
}

int color_ctoi(char c){
	switch(c){
		case 'B':
			return BLANC;
			break;
		case 'N':
			return NOIR;
			break;
	}
}

char color_itoc(int i){
	switch(i){
		case BLANC:
			return 'B';
			break;
		case NOIR:
			return 'N';
			break;
		default:
			return ' ';
	}
}

Tuile * get_tuile(Tuile *** plateau, char c, char l){
	return plateau[(int)(c - 'a')][(int)(l - '1')];
}

void print_plateau(Tuile *** plateau){
	printf("  A  B  C  D  E  F  G  H\n");
	printf(" +--+--+--+--+--+--+--+--+\n");
	for(int i = 0; i < 8; i++){
		printf("%d|", i + 1);
		for(int j = 0; j < 8; j++){
			int p = plateau[j][i]->piece;
			printf("%c%c|", piece_itoc(p & 0b00111), color_itoc((p & 0b11000) >> 3));
		}
		printf("\n +--+--+--+--+--+--+--+--+\n");
	}
}

void print_piece(int piece){
	printf("%c%c\n", piece_itoc(piece & 0b00111), color_itoc((piece & 0b11000) >> 3));
}

void print_menace(Tuile * t){
	Menace * m = t->menace;
	while(m != NULL){
		print_piece(m->attaque->piece);
		m = m->next;
	}
}

Tuile ** get_piece_table(Tuile **** pieces, int piece){
	return pieces[(piece & 0b11000) >> 3][piece & 0b00111];
}