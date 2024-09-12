#include <stdio.h>
#include <stdlib.h>
#include "lex.h"

#define MAX_BUFFER 256  

int main(int argc,char* argv[])
{
    
    unsigned char buffer[MAX_BUFFER];
    FILE *pf;
    pf = fopen(argv[1],"r");

    if (pf == NULL)
    {
        puts("Error al abrir el archivo");
        return 1;
    }
    
    int tokenNum = 0; 
    while (fgets(buffer,MAX_BUFFER,pf))
    {
        lexer l;
        lexicalAnalyzer(buffer,&l);
        if (l.token_count > 0) printf("\n\t----------------\n");
        for (int i = 0; i < l.token_count; i++)
        printTokenInfo(buffer,l.tokens[i]);
        if (l.token_count > 0) printf("\t----------------\n");
        tokenNum += l.token_count;
    }
    printf("\nToken Count: %d\n",tokenNum);
    fclose(pf);
}