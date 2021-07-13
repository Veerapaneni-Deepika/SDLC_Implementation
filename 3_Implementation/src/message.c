#include "fun.h"
error_t welcomeMessage()
{
    system(CLS);
    printf("\n\twww.LTTSLibrary.com");
    printf("\n\tEnter any key to continue.....\n");
    getchar();
    return SUCCESS;
}