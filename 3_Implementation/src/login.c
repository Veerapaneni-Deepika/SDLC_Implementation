#include "fun.h"

error_t login(const char *FILE_NAME,const unsigned char userName[MAX_SIZE_USER_NAME],const unsigned char password[MAX_SIZE_PASSWORD])
{
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    printf("\nLogin\n");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        return FILE_NOT_FOUND;
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    if((!strcmp(userName,fileHeaderInfo.username)) && (!strcmp(password,fileHeaderInfo.password)))
    {
        error_t status_menu=menu(FILE_NAME);
    }
    else
    {
        printf("\nLogin Failed Enter Again Username & Password\n");
        return FAILURE;
    }
    return SUCCESS;
}