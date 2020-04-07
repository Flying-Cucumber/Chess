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

int * get_tile(int ** plateau, char c, char l){
	return &plateau[(int)(c - 'a')][(int)(l - '1')];
}

void print_plateau(int ** plateau){
	printf("  A  B  C  D  E  F  G  H\n");
	printf(" +--+--+--+--+--+--+--+--+\n");
	for(int i = 0; i < 8; i++){
		printf("%d|", i + 1);
		for(int j = 0; j < 8; j++){
			int p = plateau[j][i];
			printf("%c%c|", piece_itoc(p & 0b00111), color_itoc((p & 0b11000) >> 3));
		}
		printf("\n +--+--+--+--+--+--+--+--+\n");
	}
}

int ** get_piece_table(int **** pieces, int piece){
	return pieces[(piece & 0b11000) >> 3][piece & 0b00111];
}