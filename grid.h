#ifndef __GRID_H__
#define __GRID_H__

#define BLANC 1
#define NOIR 2

#define PION 1
#define TOUR 2
#define CAVALIER 3
#define FOU 4
#define DAME 5
#define ROI 6

#define VIDE 0

typedef struct Jeu{
	int ** plateau;
	int **** pieces;
} Jeu;

Jeu * initialize_jeu();
void initialize_pieces(int **** pieces, int color);
void add(Jeu * j, char* c);
void move(Jeu * j, char* c);

#endif