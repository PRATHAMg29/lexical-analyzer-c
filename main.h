#ifndef LEXER_H
#define LEXER_H

//HEADER FILES
#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0
//define a macro name for colors
#define RED       "\033[31m"  
#define RESET     "\033[0m"
#define GREEN     "\033[32m"
#define BBLUE     "\033[94m"
#define BCYAN     "\033[96m"
#define BMAGENTA  "\033[95m"
#define ORANGE    "\033[38;5;208m"

//FUNCTION PROTOTYPES
void lexical_analyzer(FILE *fptr);
int is_keyword(char *word);
int is_identifier(char *word);
int is_number(char *word);
int is_operator(char ch);
int is_delimiter(char ch);

#endif