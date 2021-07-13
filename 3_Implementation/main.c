#include "fun.h"
int main()
{
    const char FILE_NAME[50]= "LTTSLibrary.bin";
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    int login_count=1; 
    error_t status = SUCCESS;
    status = init(FILE_NAME);
    status = welcomeMessage();
    do {
        printf("\nUsername:");
        fgets(userName,MAX_SIZE_USER_NAME,stdin);
        printf("\nPassword:");
        fgets(password,MAX_SIZE_PASSWORD,stdin);
        status=login(FILE_NAME,userName,password);

    }while(status == 0 && login_count <= 3);
    if(login_count>3)   ///Login Times for wrong username and password should be less than 3 other print message Login failed 
    {
        printf("\nLogin Failed\n");
        printf("\t\t\t\tSorry,Unknown User.");
        getchar();
        system(CLS);
    }
    return 0;
}
