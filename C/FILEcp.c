#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]){

    FILE *fin, *fout;
    char ch;

    if( argc!=3){
        printf("Sintaxe: \n\n %s Origem Destino \n\n", argv[0]);
        exit(1);
    }

    fin = fopen(argv[1], "rb");
    
    if(fin==NULL){
        printf("Impossível abrir o arquivo %s\n", argv[1]);
        exit (2);
    }

    if((fout = fopen(argv[2], "wb"))==NULL){
        printf("Impossível Criar o arquivo %s\n", argv[2]);
        exit(3);
    }

        while((ch = fgetc(fin))!=EOF)
            fputc(ch, fout);

        fclose(fin);
    fclose(fout);
}