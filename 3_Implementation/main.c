#include "fun.h"
int main()
{
    int L=1;
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
        L += 1;
    }while(status == 0 && L <= 3);
    if(L>3)  
    {
        printf("\nLogin Failed\n");
        printf("\t\t\t\tSorry,Unknown User.");
        getchar();
        system(CLS);
    }
    return 0;
}
