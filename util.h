#ifndef __UTIL_H__
#define __UTIL_H__

int piece_ctoi(char c);
char piece_itoc(int i);
int color_ctoi(char c);
char color_itoc(int i);

int * get_tile(int ** plateau, char c, char l);
int ** get_piece_table(int **** pieces, int piece);

void print_plateau(int ** plateau);

#endif