/**
 * @brief It tests set module
 * 
 * @file set_test.c
 * @author Ignacio Nunnez
 * @version 3.0 
 * @date 04-03-2022
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "set.h"
#include "set_test.h"
#include "test.h"
#include "types.h"

#define MAX_TESTS 18

/** 
 * @brief Main function for SPACE unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 *  
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Set:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_set_create();
  if (all || test == 2) test2_set_create();
  if (all || test == 3) test1_set_destroy();
  if (all || test == 4) test2_set_destroy();
  if (all || test == 5) test1_set_add_id();
  if (all || test == 6) test2_set_add_id();
  if (all || test == 7) test1_set_del_id();
  if (all || test == 8) test2_set_del_id();
  if (all || test == 9) test3_set_del_id();
  if (all || test == 10) test1_set_idInSet();
  if (all || test == 11) test2_set_idInSet();
  if (all || test == 12) test3_set_idInSet();
  if (all || test == 13) test1_set_is_empty();
  if (all || test == 14) test2_set_is_empty();
  if (all || test == 15) test3_set_is_empty();
  if (all || test == 16) test1_set_get_n_ids();
  if (all || test == 17) test2_set_get_n_ids();
  if (all || test == 18) test3_set_get_n_ids();
  

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_set_create() {
    int result;
    Set *s;
    s = set_create();
    result=s!=NULL;
    PRINT_TEST_RESULT(result);
    set_destroy(s);
}

void test2_set_create(){
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(s != NULL);
    set_destroy(s);
}

void test1_set_destroy() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_destroy(s) == ERROR);
}

void test2_set_destroy() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_destroy(s) == OK);
}

void test1_set_add_id() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_add_id(s, 5) == ERROR);
}

void test2_set_add_id() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_add_id(s, 5) == OK);
    set_destroy(s);
}

void test1_set_del_id() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_del_id(s, 5) == ERROR);
}

void test2_set_del_id() {
    Set *s;
    s = set_create();
    set_add_id(s, 5);
    PRINT_TEST_RESULT(set_del_id(s, 3) == ERROR);
    set_destroy(s);
}

void test3_set_del_id() {
    Set *s;
    s = set_create();
    set_add_id(s, 5);
    PRINT_TEST_RESULT(set_del_id(s, 5) == OK);
    set_destroy(s);
}

void test1_set_idInSet() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_idInSet(s, 5) == FALSE);
}

void test2_set_idInSet() {
    Set *s;
    s = set_create();
    set_add_id(s, 5);
    PRINT_TEST_RESULT(set_idInSet(s, 3) == FALSE);
    set_destroy(s);
}

void test3_set_idInSet() {
    Set *s;
    s = set_create();
    set_add_id(s, 5);
    PRINT_TEST_RESULT(set_idInSet(s, 5) == TRUE);
    set_destroy(s);
}

void test1_set_is_empty() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_is_empty(s) == TRUE);
}

void test2_set_is_empty() {
    Set *s;
    s = set_create();
    set_add_id(s, 5);
    PRINT_TEST_RESULT(set_is_empty(s) == FALSE);
    set_destroy(s);
}

void test3_set_is_empty() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_is_empty(s) == TRUE);
    set_destroy(s);
}

void test1_set_get_n_ids() {
    Set *s=NULL;
    PRINT_TEST_RESULT(set_get_n_ids(s) == NO_ID);
}

void test2_set_get_n_ids() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_get_n_ids(s) == 0);
    set_destroy(s);
}

void test3_set_get_n_ids() {
    Set *s;
    s = set_create();
    set_add_id(s, 1);
    PRINT_TEST_RESULT(set_get_n_ids(s) == 1);
    set_destroy(s);
}
