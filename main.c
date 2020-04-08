#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "util.h"


int main(int argc, char const *argv[])
{	
	Jeu* jeu = initialize_jeu();
	char * s = malloc(4 * sizeof(char));
	while(scanf("%s", s) == 1){
		add(jeu, s);
	}
	move(jeu, "PBa2a4");
	printf("Ajout des menaces\n");
	add_menace(get_tuile(jeu->plateau, 'a', '3'), get_tuile(jeu->plateau, 'b', '1'));
	add_menace(get_tuile(jeu->plateau, 'a', '3'), get_tuile(jeu->plateau, 'b', '2'));
	/* printf("Affichage des menaces\n");
	print_menace(get_tuile(jeu->plateau, 'a', '3')); */
	print_plateau(jeu->plateau);
	return 0;
}