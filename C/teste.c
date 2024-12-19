#include <stdio.h>

int main(void) {
    // Envia o cabeçalho HTTP
    printf("Content-Type: text/html\n\n");

    // Envia o conteúdo HTML
    printf("<html>\n");
    printf("<head>\n");
    printf("<title>Minha Página em C</title>\n");
    printf("</head>\n");
    printf("<body>\n");
    printf("<h1>Olá, Mundo!</h1>\n");
    printf("<p>Esta é uma página gerada por um programa C.</p>\n");
    printf("</body>\n");
    printf("</html>\n");

    return 0;
}