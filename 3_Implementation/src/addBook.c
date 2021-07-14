#include "fun.h"

error_t addBookInDataBase(const char* FILE_NAME)
{
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    error_t status = FAILURE;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        return FILE_NOT_FOUND;
    }
    printf("\nADD NEW BOOKS\n");
    printf("\nENTER YOUR DETAILS BELOW:");
    printf("\nBook ID NO  = ");
    fflush(stdin);
    scanf("%u",&addBookInfoInDataBase.books_id);
    do
    {
        printf("\nBook Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.bookName,MAX_BOOK_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.bookName);
        if (!status)
        {
            printf("\nName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\nAuthor Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.authorName,MAX_AUTHOR_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.authorName);
        if (!status)
        {
            printf("\nName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\nStudent Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.studentName,MAX_STUDENT_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.studentName);
        if (!status)
        {
            printf("\nName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    /*do
    {
        printf("\nEnter date in format (day/month/year) when it was issue: ");
        scanf("%d/%d/%d",&addBookInfoInDataBase.bookIssueDate.dd,&addBookInfoInDataBase.bookIssueDate.mm,&addBookInfoInDataBase.bookIssueDate.yyyy);
        status = isValidDate(&addBookInfoInDataBase.bookIssueDate);
        if (!status)
        {
            printf("\nPlease enter a valid date.\n");
        }
    }
    while(!status);*/
    
    Date d;
    d.dd=addBookInfoInDataBase.bookIssueDate.dd;
    d.mm=addBookInfoInDataBase.bookIssueDate.mm;
    d.yyyy=addBookInfoInDataBase.bookIssueDate.yyyy;
    addDate(&d);
    addBookInfoInDataBase.returnDate.dd=d.dd;
    addBookInfoInDataBase.returnDate.mm=d.mm;
    addBookInfoInDataBase.returnDate.yyyy=d.yyyy;
    
    fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, fp);
    fclose(fp);
    return SUCCESS;
}
