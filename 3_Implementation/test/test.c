#include "unity.h"
#include "fun.h"
#define PROJECT_NAME "LibraryManagement"

/* Prototypes for all the test functions */
void test_addBook(void);
void test_deleteBook(void);
void test_login(void);
void test_menu(void);
void test_message(void);
void test_searchBook(void);
void test_viewBook(void);
void test_valid_file(void);
void test_valid_year(void);
void test_valid_name(void);
void test_valid_date(void);
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_addBook);
  RUN_TEST(test_deleteBook);
  RUN_TEST(test_login);
  RUN_TEST(test_menu);
  RUN_TEST(test_message);
  RUN_TEST(test_searchBook);
  RUN_TEST(test_valid_date);
  RUN_TEST(test_valid_year);
  RUN_TEST(test_valid_file);
  RUN_TEST(test_valid_name);
  RUN_TEST(test_viewBook);
  
  /* Close the Unity Test Framework */
  return UNITY_END();
}

void test_addBook(void)
{
  TEST_ASSERT_EQUAL(SUCCESS,addBookInDataBase("LTTSLibrary.bin"));
}
void test_deleteBook(void)
{
  TEST_ASSERT_EQUAL(SUCCESS,deleteBooks("LTTSLibrary.bin"));
}
void test_login()
{
  TEST_ASSERT_EQUAL(FAILURE,login("LTTSLibrary.bin","Mounika","Mounika"));
  TEST_ASSERT_EQUAL(SUCCESS,login("LTTSLibrary.bin","deepika","deepika"));
}
void test_menu(void)
{
  TEST_ASSERT_EQUAL(SUCCESS,menu("LTTSLibrary.bin"));
}
void test_message(void)
{
  TEST_ASSERT_EQUAL(SUCCESS,welcomeMessage());
}
void test_searchBook(void)
{
  TEST_ASSERT_EQUAL(NOT_FOUND,searchBooks("LTTSLibrary.bin"));
}
void test_valid_file(void)
{
  TEST_ASSERT_EQUAL(SUCCESS,isFileExists("LTTSLibrary.bin"));  
  TEST_ASSERT_EQUAL(FILE_NOT_FOUND,isFileExists("library.bin"));  
}
void test_valid_name(void)
{
  TEST_ASSERT_EQUAL(SUCCESS,isNameValid("Deepika"));
  TEST_ASSERT_EQUAL(FAILURE,isNameValid("#Deepika#"));
}
void test_valid_year(void)
{
  TEST_ASSERT_EQUAL(0,leap_year(2021));  
  TEST_ASSERT_EQUAL(1,leap_year(2020));
}
void test_viewBook(void)
{
  TEST_ASSERT_EQUAL(SUCCESS,viewBooks("LTTSLibrary.bin"));
}
void test_valid_date(void)
{
  
  Date d1={.dd=31,.mm=2,.yyyy=2021};
  TEST_ASSERT_EQUAL(FAILURE,isValidDate(&d1));
  Date d2={.dd=31,.mm=4,.yyyy=2021};
  TEST_ASSERT_EQUAL(FAILURE,isValidDate(&d2));
}