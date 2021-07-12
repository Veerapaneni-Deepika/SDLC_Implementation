#include "fun.h"
void searchBooks()
{
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\nFile is not opened\n");
        exit(1);
    }
    printf("\nSEARCH BOOKS\n");
    //put the control on books detail
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\nFacing issue while reading file\n");
        exit(1);
    }
    printf("\nEnter Book Name to search:");
    fflush(stdin);
    fgets(bookName,MAX_BOOK_NAME,stdin);
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if(!strcmp(addBookInfoInDataBase.bookName, bookName))
        {
            found = 1;
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
    }
    else
    {
        printf("\nNo Record");
    }
    fclose(fp);
    printf("\nPress any key to go to main menu.....\n");
    getchar();
}
