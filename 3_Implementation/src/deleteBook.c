#include "fun.h"

error_t deleteBooks(const char *FILE_NAME)
{
    error_t found = FAILURE;
    int bookDelete = 0;
    sFileHeader fileHeaderInfo = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    printf("Delete Books Details\n");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        return FILE_NOT_FOUND;
    }
    tmpFp = fopen("tmp.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        return FILE_NOT_FOUND;
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, tmpFp);
    
    printf("\nEnter Book ID NO. for delete:");
    scanf("%d",&bookDelete);
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if(addBookInfoInDataBase.books_id != bookDelete)
        {
            fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, tmpFp);
            found = SUCCESS;
        }
        else
        {
            found = FAILURE;
        }
    }
    fclose(fp);
    (found)? printf("\nRecord deleted successfully....."):printf("\nRecord not found");
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin",FILE_NAME);
    return SUCCESS;
}