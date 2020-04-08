#ifndef __UTIL_H__
#define __UTIL_H__

typedef struct tuile Tuile;

// Structure de liste indexant la localisation des pièces menaçant cette case
typedef struct menace{
	Tuile * attaque;
	struct menace * next;
} Menace;


// Structure contenant la pièce présente sur la case et la liste des pièces menaçant cette case
typedef struct tuile{
	int piece;
	struct menace * menace;
} Tuile;

int piece_ctoi(char c);
char piece_itoc(int i);
int color_ctoi(char c);
char color_itoc(int i);

Tuile * get_tuile(Tuile *** plateau, char c, char l);
Tuile ** get_piece_table(Tuile **** pieces, int piece);

void print_plateau(Tuile *** plateau);
void print_piece(int piece);
void print_menace(Tuile * t);

#endif