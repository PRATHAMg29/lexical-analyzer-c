#include "main.h"

char *keyword[] = {"int","float","char","if","else","while","for","return","do",NULL};

void lexical_analyzer(FILE *fptr)
{
    char ch;
    char word[100];     //temporary array for storing tokens.
    int i = 0;

    while((ch = fgetc(fptr)) != -1)     //loop upto End Of File.
    {
        if(isalnum(ch) || ch == '_')    // Build keywords or identifiers.
        {
            word[i++] = ch;
        }
        else
        {
            if(i != 0)
            {
                word[i] = '\0';
                if(is_keyword(word))    //check if the token is a keyword.
                {
                    printf(GREEN "%s\t\tKeyword\n" RESET,word);
                }
                else if(is_number(word))    //check if the token is a number.
                {
                    printf(BCYAN "%s\t\tNumber\n" RESET, word);
                }
                else if(is_identifier(word))    //check if the token is a identifier.
                {
                    printf(BMAGENTA "%s\t\tIdentifier\n" RESET, word);
                }
                else
                {
                    printf(BBLUE "%s\t\tUnknown\n" RESET, word);    //print unknown otherwise.
                }
                i = 0;
            }

            if(is_operator(ch))     //check if the character read is an operator.
            {
                printf(RED "%c\t\tOperator\n" RESET, ch);
            }
            else if(is_delimiter(ch))   //check if the character is a delimiter.
            {
                printf("%c\t\tDelimiter\n", ch);
            }

            if(ch == '\n')
            {
                printf("\n");
            }
        }
    }
}

int is_keyword(char *word)
{
    for(int i = 0; keyword[i] != NULL ; i++)    //run loop through the array of strings.
    {
        if(strcmp(word, keyword[i]) == 0)   //if keywords match with the word, then return success.
        {
            return SUCCESS;
        }
    }
    return FAILURE;   //return failure otherwise.
}

int is_delimiter(char ch)   //check for delimiter function.
{
    if(ch=='(' || ch==')' || ch=='{' || ch=='}' || ch==';')
    {
        return SUCCESS;
    }
    return FAILURE;
}

int is_number(char *word)
{
    for(int i = 0; word[i]; i++)    //check for number.
    {
        if(!isdigit(word[i]))   //if is not a digit, then return failure.
        {
            return FAILURE;
        }
    }
    return SUCCESS;   //return success otherwise.
}

int is_operator(char ch)    //check for operator function.
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='=' || ch=='<' || ch=='>' || ch=='%')
    {
        return SUCCESS;
    }
    return FAILURE;
}

int is_identifier(char *word)
{
    if(!(isalpha(word[0]) || word[0] == '_'))   //check if 1st character is an alphabet or underscore(_).
    {
        return FAILURE;   //if not, return 0.
    }
    for(int i = 1; word[i]; i++)    //loop through the word and check that the word has only alphabets, numbers or underscore(_).
    {
        if(!(isalnum(word[i]) || word[i] == '_'))
        {
            return FAILURE;   //if not then return failure.
        }
    }
    return SUCCESS;   //return success otherwise.
}