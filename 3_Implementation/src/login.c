#include "fun.h"
void login()
{
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    int L=0;
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    printf("\nLogin\n");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    do
    {
        printf("\nUsername:");
        fgets(userName,MAX_SIZE_USER_NAME,stdin);
        printf("\nPassword:");
        fgets(password,MAX_SIZE_PASSWORD,stdin);
        if((!strcmp(userName,fileHeaderInfo.username)) && (!strcmp(password,fileHeaderInfo.password)))
        {
            menu();
        }
        else
        {
            printf("\nLogin Failed Enter Again Username & Password\n");
            L++;
        }
    }
    while(L<=3);
    if(L>3)
    {
        printf("\nLogin Failed");
        printf("Sorry,Unknown User.");
        getchar();
        system("cls");
    }
}