#include <stdio.h>
#include <stdlib.h>

#define MAX_LIN 80
#define SINAL '-'

void Erro(int num_erro, char *string){
    switch(num_erro){
        case 1: fprintf(stderr,"Sintaxe:\n\nhead [-n] [Arq]\n\n");
                break;
        case 2: fprintf(stderr,"imp. Abrir o arquivo '%s'\n", string);
                break;
    }
    exit(num_erro);
}
main(int argc, char *argv[]){
    FILE *fp = stdin;
    char s[MAX_LIN+1];
    int i = 0;
    int n_lins = 10;

    switch(argc){
        case 1: break;
        // case 2: n_lins = (argv[1][0] == SINAL) ? atoi(argv[1] + 1) : ((fp = fopen(argv[1], "r")) == NULL ? Erro(2, argv[1]) : 0); //não funcionou.

        case 2: if (argv[1][0] ==SINAL)
            n_lins = atoi(argv[1]+1);
            else
                if ((fp = fopen(argv[1],"r")) == NULL)
                    Erro(2,argv[1]);
            break;
        case 3: if (argv[1][0] != SINAL)
            Erro(1, "");
            else{
                n_lins = atoi(argv[1]+1);
                if ((fp = fopen(argv[2],"r")) == NULL)
                    Erro(2,argv[2]);
            }
            break;
        default: Erro(1,"");
    }

    while (fgets(s, MAX_LIN+1, fp)!= NULL && i++ < n_lins)
        fputs(s, stdout);
    fclose(fp);

}
