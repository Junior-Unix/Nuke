#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MENOS '-'
#define MENOS_L "-l"
#define MAX_LIN 80

void Erro_Fatal( int num_erro, char *string);
int stricmp( char *s1, char *s2);
main( int argc, char *argv[]){

	int mostra_linhas = 0;
	int n_linha = 0;
	FILE *fp = stdin;
	char s[MAX_LIN+1];


	switch( argc){
	
		case 1: break;
		case 2: if( stricmp(argv[1], MENOS_L) == 0)
				mostra_linhas = 1;
			else if (( fp = fopen( argv[1], "r")) == NULL)
				Erro_Fatal( 2, argv[1]);
			break;
		case 3: if (argv[1][0] != MENOS)
				Erro_Fatal( 3, argv[1]);
			if (stricmp( argv[1], MENOS_L) != 0)
				Erro_Fatal( 3, argv[1]);
			mostra_linhas = 1;
			if ((fp = fopen( argv[2], "r")) == NULL)
				Erro_Fatal( 2, argv[2]);
			break;
		default : Erro_Fatal( 1, "");
	}

	while ( fgets( s, MAX_LIN+1, fp) != NULL){
		s[strlen(s)-1] = '\0';
			if( mostra_linhas)
				fprintf( stdout, "%d: %d\n", ++n_linha, strlen(s));

	}
	fclose(fp);
}
int stricmp( char *s1, char *s2){
	int i = 0;
	while ( toupper( s1[i]) == toupper( s2[i]) && s1[i] != '\0')
		i++;
	return ( toupper(s1[i]) - toupper(s2[i]));
}
void Erro_Fatal( int num_erro, char *string){
	switch(num_erro){
		case 1:
			fprintf(stderr, "Sintaxe:\nconta [-l] [Arq]\n\n");
			break;
		case 2:
			fprintf( stderr, "Imp. Abrir o arquivo '%s'\n", string);
			break;
		case 3:
			fprintf( stderr, "Opção \"%s\" Inválida \n", string);
			break;
	}
	exit (num_erro);
}
