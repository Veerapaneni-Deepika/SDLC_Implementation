#include "fun.h"
error_t searchBooks(const char *FILE_NAME)
{
    error_t found = FAILURE;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\nFile is not opened\n");
        exit(1);
        return FILE_NOT_FOUND;
    }
    printf("\nSEARCH BOOKS\n");
    //put the control on books detail
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\nFacing issue while reading file\n");
        exit(1);
        return FAILURE;
    }
    printf("\nEnter Book Name to search:");
    fflush(stdin);
    fgets(bookName,MAX_BOOK_NAME,stdin);
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if(!strcmp(addBookInfoInDataBase.bookName, bookName))
        {
            found = SUCCESS;
            break;
        }
    }
    if(found)
    {
        printf("\nBook id = %u\n",addBookInfoInDataBase.books_id);
        printf("\nBook name = %s",addBookInfoInDataBase.bookName);
        printf("\nBook authorName = %s",addBookInfoInDataBase.authorName);
        printf("\nBook issue date(day/month/year) =  (%d/%d/%d)",addBookInfoInDataBase.bookIssueDate.dd,
               addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
        printf("\nBook return date(day/month/year) =  (%d/%d/%d)",addBookInfoInDataBase.returnDate.dd,
               addBookInfoInDataBase.returnDate.mm, addBookInfoInDataBase.returnDate.yyyy);
    }
    else
    {
        printf("\nNo Book");
        return NOT_FOUND;
    }
    fclose(fp);
    printf("\nPress any key to go to main menu.....\n");
    getchar();
    return found;
}
