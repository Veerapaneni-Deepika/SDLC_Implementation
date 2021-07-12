#include "fun.h"
void viewBooks()
{
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    unsigned int countBook = 1;
    printf("\nVIEW BOOKS DETAILS\n");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
        exit(1);
    }
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        printf("\nBook Count = %d\n\n",countBook);
        printf("\nBook id = %u",addBookInfoInDataBase.books_id);
        printf("\nBook name = %s",addBookInfoInDataBase.bookName);
        printf("\tBook authorName = %s",addBookInfoInDataBase.authorName);
        printf("\tBook issue date(day/month/year) =  (%d/%d/%d)\n\n",addBookInfoInDataBase.bookIssueDate.dd,
               addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
        found = 1;
        ++countBook;
    }
    fclose(fp);
    if(!found)
    {
        printf("\nNo Record");
    }
    printf("\nPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
