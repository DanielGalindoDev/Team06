#include <stdio.h>
#include <stdio.h>


typedef enum
{
    ID,
    KEYWORD,
    NUMERIC_CONSTANT,
    PUNCTUATION,
    LITERAL,
    OPERATOR,
    SPECIAL_CHAR,
    LITERAL_CONST,
    PREPROCCESOR,
    COMMENT,
    NO_TOKEN
}token;

typedef struct 
{
    unsigned short start_index;
    unsigned short end_index;
    token type;
}token_info;

typedef struct lex
{
    token_info tokens[100];
    unsigned short token_count; 
}lexer;


extern const char FA [][97];

token categorizeLexeme(int state);
token isKeyWord(const char *buffer,short start,short end);
void lexicalAnalyzer(const char *buffer,lexer *l);
void printTokenInfo(const char* buffer,token_info t);
