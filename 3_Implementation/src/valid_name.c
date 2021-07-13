#include "fun.h"
int isalphabet(char c);
/// Function to check whether character is valid or not
int isalphabet(char c)
{
    if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
        return 1;
    return 0;
}
error_t isNameValid(const char *name)
{
    error_t validName = SUCCESS;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        /// Checking for every character to be valid or not
        if(!(isalphabet(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = FAILURE;
            break;
        }
    }
    return validName;
}