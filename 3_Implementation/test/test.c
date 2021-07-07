#include<unity.h>
#include "fun.h"
#define PROJECT_NAME    "LibraryManagement"

/* Prototypes for all the test functions */
void testing_get_result(void);
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
