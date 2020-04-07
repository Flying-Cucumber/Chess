#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "util.h"


int main(int argc, char const *argv[])
{	
	Jeu* jeu = initialize_jeu();
	char * s = malloc(4 * sizeof(char));
	int test = 1;
	while(scanf("%s", s)){
		add(jeu, s);
	}
	print_plateau(jeu->plateau);
	return 0;
}