#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>

void replaceAll(char *str, const char *pattern, const char *replacement) {
    /**
     * Declara uma variável `regex` do tipo `regex_t`.
     * `regex_t` é um tipo de dado definido na biblioteca POSIX <regex.h>
     * e é usado para armazenar expressões regulares compiladas.
     */
    // Declaração de uma variável do tipo regex_t, que será usada para armazenar
    // a expressão regular compilada. A estrutura regex_t é definida na biblioteca
    // POSIX regex.h e contém todas as informações necessárias para realizar
    // operações de correspondência de padrões com a expressão regular compilada.
    regex_t regex;
    regmatch_t match;
    char buffer[1024];
    char *pos = str;
    int len;

    regcomp(&regex, pattern, REG_EXTENDED);
    buffer[0] = '\0';

    while (regexec(&regex, pos, 1, &match, 0) == 0) {
        strncat(buffer, pos, match.rm_so);
        strcat(buffer, replacement);
        pos += match.rm_eo;
    }
    strcat(buffer, pos);
    strcpy(str, buffer);

    regfree(&regex);
}

void replaceAllFunc(char *str, const char *pattern) {
    regex_t regex;
    regmatch_t match;
    char buffer[1024];
    char *pos = str;
    int len;

    regcomp(&regex, pattern, REG_EXTENDED);
    buffer[0] = '\0';

    while (regexec(&regex, pos, 1, &match, 0) == 0) {
        strncat(buffer, pos, match.rm_so);
        for (int i = match.rm_so; i < match.rm_eo; i++) {
            buffer[strlen(buffer)] = toupper(pos[i]);
        }
        pos += match.rm_eo;
    }
    strcat(buffer, pos);
    strcpy(str, buffer);

    regfree(&regex);
}

int main() {
    char texto[1024] = "0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f";
    regex_t regex9, regexLetras;
    regmatch_t match;

    regcomp(&regex9, "9", REG_EXTENDED);
    printf("%d\n", regexec(&regex9, texto, 1, &match, 0) == 0);
    if (regexec(&regex9, texto, 1, &match, 0) == 0) {
        printf("%.*s\n", match.rm_eo - match.rm_so, texto + match.rm_so);
        printf("%d %d\n", match.rm_so, match.rm_eo);
    }

    regcomp(&regexLetras, "[a-f]", REG_EXTENDED);
    char *pos = texto;
    while (regexec(&regexLetras, pos, 1, &match, 0) == 0) {
        printf("%.*s\n", match.rm_eo - match.rm_so, pos + match.rm_so);
        pos += match.rm_eo;
    }

    replaceAll(texto, "[a-f]", "Achei");
    printf("%s\n", texto);

    strcpy(texto, "0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f");
    replaceAllFunc(texto, "[a-f]");
    printf("%s\n", texto);

    regfree(&regex9);
    regfree(&regexLetras);

    return 0;
}
