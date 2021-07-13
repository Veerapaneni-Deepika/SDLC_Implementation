#include "fun.h"

int isNameValid(const char *name)
{
    error_t validName = SUCCESS;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = FAILURE;
            break;
        }
    }
    return validName;
}