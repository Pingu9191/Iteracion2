/** 
 * @brief It declares the tests for the set module
 * 
 * @file set_test.h
 * @author Ignacio Nunnez
 * @version 2.0 
 * @date 04-03-2022
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Non NULL pointer to space 
 */
void test1_set_create();

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Space_ID == Supplied Space Id
 */
void test2_set_create();

void test1_set_destroy();

void test2_set_destroy();

void test1_set_add_id();

void test2_set_add_id();

void test1_set_del_id();

void test2_set_del_id();

void test3_set_del_id();

void test1_set_idInSet();

void test2_set_idInSet();

void test3_set_idInSet();

void test1_set_is_empty();

void test2_set_is_empty();

void test3_set_is_empty();

void test1_set_get_n_ids();

void test2_set_get_n_ids();

void test3_set_get_n_ids();

#endif
