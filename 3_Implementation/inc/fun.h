   #include <stdio.h>
   #include <time.h>
   #include <string.h>
   #include <stdlib.h>
   
   #define MAX_YR  9999
   #define MIN_YR  1900
   #define MAX_SIZE_USER_NAME 30
   #define MAX_SIZE_PASSWORD  20
   
   #define MAX_BOOK_NAME   50
   #define MAX_AUTHOR_NAME 50
   #define MAX_STUDENT_NAME 50
   #define MAX_STUDENT_ADDRESS 300
   #define FILE_HEADER_SIZE  sizeof(sFileHeader)

   #ifndef __FUN_H_
   #define __FUN_H_
    #ifdef _WIN32
        #define CLS "cls"
    #elif __linux__
        #define CLS "clear"
    #endif

    typedef enum error_t {
        FILE_NOT_FOUND = -1,
        FAILURE = 0,
        SUCCESS = 1,
        NOT_FOUND = 2
    }error_t;

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
    
    typedef struct
    {
        unsigned int books_id; // declare the integer data type
        char bookName[MAX_BOOK_NAME];// declare the character data type
        char authorName[MAX_AUTHOR_NAME];// declare the charecter data type
        char studentName[MAX_STUDENT_NAME];// declare the character data type
        Date bookIssueDate;
        Date returnDate;
    } s_BooksInfo;

    error_t welcomeMessage();
    error_t addBookInDataBase(const char *FILE_NAME);
    error_t deleteBooks(const char *FILE_NAME);
    error_t init();
    error_t login(const char *FILE_NAME,const unsigned char username[],const unsigned char password[]);
    error_t menu(const char *FILE_NAME);
    error_t searchBooks(const char *FILE_NAME);
    error_t updateCredential(const char *FILE_NAME);
    error_t viewBooks(const char *FILE_NAME);
    error_t isFileExists(const char *path);
    error_t isNameValid(const char *name);
    error_t isValidDate(Date *validDate);
    Date addDate(Date *d);
    int leap_year(int year);

#endif