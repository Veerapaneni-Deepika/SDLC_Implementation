#include "fun.h"
error_t viewBooks(const char* FILE_NAME)
{
    error_t status = FAILURE;
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    unsigned int countBook = 1;
    printf("\nVIEW BOOKS DETAILS\n");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        return FILE_NOT_FOUND;
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
        return FILE_NOT_FOUND;
    }
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        printf("\nBook Count = %u\n",countBook);
        printf("\nBook id = %u",addBookInfoInDataBase.books_id);
        printf("\nBook name = %s",addBookInfoInDataBase.bookName);
        printf("\nBook authorName = %s",addBookInfoInDataBase.authorName);
        printf("\tBook issue date(day/month/year) =  (%d/%d/%d)\n",addBookInfoInDataBase.bookIssueDate.dd,addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
        printf("\tBook issue date(day/month/year) =  (%d/%d/%d)\n",addBookInfoInDataBase.bookIssueDate.dd,addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
        status = SUCCESS;
        ++countBook;
    }
    fclose(fp);
    if(!status)
    {
        printf("\nNo Record");
    }
    printf("\nPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
    return SUCCESS;
}
