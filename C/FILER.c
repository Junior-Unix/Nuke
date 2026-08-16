#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]){

    FILE *fp;
    int ch;
    
    if( argc!=2 ){
        printf("Sintxe: \n\n%s Arquivo \n\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1],"r");

    if(fp==NULL){
        printf("Impossível abrir o arquivo <%s>\n", argv[1]);
        exit(2);
    }

    while((ch=fgetc(fp))!=EOF){
        putchar(ch);
    }
    //Investigação do tamanho que um ponteiro de arquivo ocupa na memória.
    printf("%d\n%d\n", &fp[0],strlen(fp));
    //Laço para investigar o endereço de memória de cada posição do ponteiro de arquivo.
    for(int i=0; i<strlen(fp); i++){
        printf("%p\n", fp[i]);
    }
    fclose(fp);

}
