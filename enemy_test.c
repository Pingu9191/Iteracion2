/** 
 * @brief It tests enemy module
 * 
 * @file enemy_test.c
 * @author Ignacio Nunnez
 * @version 3.0 
 * @date 02-03-2022
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "enemy.h"
#include "enemy_test.h"
#include "test.h"

#define MAX_TESTS 23

/** 
 * @brief Main function for ENEMY unit tests. 
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
    printf("Running all test for module Enemy:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_enemy_create();
  if (all || test == 2) test1_enemy_create();
  if (all || test == 3) test2_enemy_create();
  if (all || test == 4) test1_enemy_destroy();
  if (all || test == 5) test2_enemy_destroy();
  if (all || test == 6) test3_enemy_destroy();
  if (all || test == 7) test1_enemy_get_id();
  if (all || test == 8) test2_enemy_get_id();
  if (all || test == 9) test1_enemy_set_name();
  if (all || test == 10) test2_enemy_set_name();
  if (all || test == 11) test3_enemy_set_name();
  if (all || test == 12) test1_enemy_get_name();
  if (all || test == 13) test2_enemy_get_name();
  if (all || test == 14) test1_enemy_set_location();
  if (all || test == 15) test2_enemy_set_location();
  if (all || test == 16) test3_enemy_set_location();
  if (all || test == 17) test1_enemy_get_location();
  if (all || test == 18) test2_enemy_get_location();
  if (all || test == 19) test1_enemy_set_health();
  if (all || test == 20) test2_enemy_set_health();
  if (all || test == 21) test3_enemy_set_health();
  if (all || test == 22) test1_enemy_get_health();
  if (all || test == 23) test2_enemy_get_health();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_enemy_create(){
  Enemy *e;
  e = enemy_create(NO_ID);
  PRINT_TEST_RESULT(e == NULL);
}

void test2_enemy_create(){
  Enemy *e;
  e = enemy_create(5);
  PRINT_TEST_RESULT(e != NULL);
  enemy_destroy(e);
}

void test1_enemy_destroy(){
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_destroy(e) == ERROR);
}

void test2_enemy_destroy(){
  Enemy *e;
  e = enemy_create(4);
  PRINT_TEST_RESULT(enemy_destroy(e) == OK);
}

void test3_enemy_destroy(){
  Enemy *e;
  e = enemy_create(4);
  PRINT_TEST_RESULT(enemy_destroy(e) == OK);
}

void test1_enemy_get_id(){
  Enemy *e=NULL;
  PRINT_TEST_RESULT(enemy_get_id(e) == NO_ID);
}

void test2_enemy_get_id(){
  Enemy *e;
  e = enemy_create(5);
  PRINT_TEST_RESULT(enemy_get_id(e) == 5);
  enemy_destroy(e);
}

void test1_enemy_set_name(){
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_set_name(e, "Pepe") == ERROR );
}

void test2_enemy_set_name(){
  Enemy *e;
  e = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_name(e, 0) == ERROR);
  enemy_destroy(e);
}

void test3_enemy_set_name(){
  Enemy *e;
  e = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_name(e, "Pepe") == OK);
  enemy_destroy(e);
}

void test1_enemy_get_name(){
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_get_name(e) == NULL);
}

void test2_enemy_get_name(){
  Enemy *e;
  e = enemy_create(5);
  enemy_set_name(e, "Pepe");
  PRINT_TEST_RESULT(strcmp(enemy_get_name(e), "Pepe") == 0);
  enemy_destroy(e);
}

void test1_enemy_set_location(){
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_set_location(e, 5) == ERROR);
}

void test2_enemy_set_location(){
  Enemy *e;
  e = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_location(e, NO_ID) == ERROR);
  enemy_destroy(e);
}

void test3_enemy_set_location(){
  Enemy *e;
  e = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_location(e, 7) == OK);
  enemy_destroy(e);
}

void test1_enemy_get_location(){
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_get_location(e) == ERROR);
}

void test2_enemy_get_location(){
  Enemy *e;
  e = enemy_create(5);
  enemy_set_location(e, 6);
  PRINT_TEST_RESULT(enemy_get_location(e) == 6);
  enemy_destroy(e);
}

void test1_enemy_set_health(){
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_set_health(e, 3) == ERROR);
}

void test2_enemy_set_health(){
  Enemy *e;
  e = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_health(e, MAX_HEALTH_ENEMY + 1) == ERROR);
  enemy_destroy(e);
}

void test3_enemy_set_health(){
  Enemy *e;
  e = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_health(e, MAX_HEALTH_ENEMY - 1) == OK);
  enemy_destroy(e);
}

void test1_enemy_get_health(){
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_get_health(e) == ERROR);
}

void test2_enemy_get_health(){
  Enemy *e;
  e = enemy_create(5);
  enemy_set_health(e, MAX_HEALTH_ENEMY - 1);
  PRINT_TEST_RESULT(enemy_get_health(e) == MAX_HEALTH_ENEMY - 1);
  enemy_destroy(e);
}
