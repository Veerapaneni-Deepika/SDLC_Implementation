#include<unity.h>
#include "fun.h"
#define PROJECT_NAME    "LibraryManagement"

/* Prototypes for all the test functions */
void testing_get_result(void);
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){

}

#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "AticleworldLibBookS.bin"
    // Macro related to the books info
#define MAX_BOOK_NAME   50
#define MAX_AUTHOR_NAME 50
#define MAX_STUDENT_NAME 50
#define MAX_STUDENT_ADDRESS 300
#define FILE_HEADER_SIZE  sizeof(sFileHeader)

char username[30];
char password[20];
unsigned int books_id; // declare the integer data type
char bookName[50];// declare the character data type
char authorName[50];// declare the charecter data type
char studentName[50];// declare the character data type
char studentAddr[30];// declare the character data type

FILE *fp = NULL;
FILE *tmpFp = NULL;


/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(testing_get_result);
  
  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void testing_get_result(){
    TEST_ASSERT_EQUAL(6, get_result(0, 0));
    TEST_ASSERT_EQUAL(6, get_result(1, 1));
    TEST_ASSERT_EQUAL(6, get_result(2, 2));
    TEST_ASSERT_EQUAL(4, get_result(0, 2));
    TEST_ASSERT_EQUAL(5, get_result(0, 1));
    TEST_ASSERT_EQUAL(4, get_result(1, 0));
    TEST_ASSERT_EQUAL(5, get_result(1, 2));
    TEST_ASSERT_EQUAL(4, get_result(2, 1));
    TEST_ASSERT_EQUAL(5, get_result(2, 0));
}

void test_addBook(void) {
  

}
