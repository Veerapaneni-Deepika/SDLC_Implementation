#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "LTTS_Library.bin"
// Macro related to the books info
#define MAX_BOOK_NAME   50
#define MAX_AUTHOR_NAME 50
#define MAX_STUDENT_NAME 50
#define MAX_STUDENT_ADDRESS 300
#define FILE_HEADER_SIZE  sizeof(sFileHeader)
//structure to store date
typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;
typedef struct
{
    char username[MAX_SIZE_USER_NAME];
    char password[MAX_SIZE_PASSWORD];
} sFileHeader;
typedef struct// to call in program
{
    unsigned int books_id; // declare the integer data type
    char bookName[MAX_BOOK_NAME];// declare the character data type
    char authorName[MAX_AUTHOR_NAME];// declare the charecter data type
    char studentName[MAX_STUDENT_NAME];// declare the character data type
    char studentAddr[MAX_STUDENT_ADDRESS];// declare the character data type
    Date bookIssueDate;// declare the integer data type
} s_BooksInfo;

void addBookInDataBase();
void deleteBooks();
void init();
void login();
void searchBooks();
void updateCredential(void);
void viewBooks();
void printMessageCenter(const char* x);
void headMessage(const char *x);
void welcomeMessage();
int isNameValid(const char *n);
int  IsLeapYear(int year);
int isValidDate(Date *validDate);
int isFileExists(const char *path);

#endif