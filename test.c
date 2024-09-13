#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.h"

#define MAX_BUFFER 256

int main(int argc, char *argv[]) {
    unsigned char buffer[MAX_BUFFER];
    FILE *pf = NULL;

    if (argc > 1) {
        pf = fopen(argv[1], "r");
        if (pf == NULL) {
            puts("Error opening the file, reading from console.");
            pf = NULL;
        }
    } else {
        puts("No file provided, reading from console.");
    }

    int tokenNum = 0;

    if (pf) {
        while (fgets(buffer, MAX_BUFFER, pf)) {
            lexer l;
            lexicalAnalyzer(buffer, &l);
            if (l.token_count > 0) printf("\n\t----------------\n");
            for (int i = 0; i < l.token_count; i++)
                printTokenInfo(buffer, l.tokens[i]);
            if (l.token_count > 0) printf("\t----------------\n");
            tokenNum += l.token_count;
        }
        printf("\nToken Count: %d\n", tokenNum);
        fclose(pf);
    } else {
        printf("Enter lines of text. To finish, enter a line with only the '?' character:\n");
        while (fgets(buffer, MAX_BUFFER, stdin)) {
            if (strchr(buffer, '?') != NULL && strlen(buffer) == 2) {
                break;
            }
            lexer l;
            lexicalAnalyzer(buffer, &l);
            if (l.token_count > 0) printf("\n\t----------------\n");
            for (int i = 0; i < l.token_count; i++)
                printTokenInfo(buffer, l.tokens[i]);
            if (l.token_count > 0) printf("\t----------------\n");
            tokenNum += l.token_count;
        }
        printf("\nToken Count: %d\n", tokenNum);
    }

    return 0;
}
