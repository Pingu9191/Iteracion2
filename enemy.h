/**
* @brief It defines enemy module
*
* @file enemy.h
* @author Ignacio Nunnez
* @version 1.0
* @date 22/02/2022
* @copyright GNU Public License
*/

#ifndef ENEMY_H
#define ENEMY_H

#include "types.h"

typedef struct _Enemy Enemy;

#define MAX_ENEMIES 100
#define FIRST_ENEMY 1

/**
  * @brief It creates a new enemy
  * @author Ignacio Nunnez
  *
  * enemy_create allocates memory for a new enemy
  *  and initializes its members
  * @param id the identification number for the new enemy
  * @return a new enemy, initialized
  */
Enemy* enemy_create(Id id);

/**
  * @brief It destroys an enemy
  * @author Ignacio Nunnez
  *
  * enemy_destroy frees the previous memory allocation 
  *  for an enemy
  * @param enemy a pointer to the enemy that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS enemy_destroy(Enemy* enemy);

/**
  * @brief It gets the id of an enemy
  * @author Ignacio Nunnez
  * 
  * @param enemy a pointer to the enemy  
  * @return the id of the enemy
  */
Id enemy_get_id(Enemy* enemy);

/**
  * @brief It sets the name of an enemy
  * @author Ignacio Nunnez
  * 
  * @param enemy a pointer to the enemy
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_set_name(Enemy* enemy, char* name);

/**
  * @brief It gets the name of an enemy
  * @author Ignacio Nunnez
  * 
  * @param enemy a pointer to the enemy
  * @return a string with the name of the enemy
  */
const char * enemy_get_name(Enemy* enemy);

/**
  * @brief It sets the id of an enemy location
  * @author Ignacio Nunnez
  * 
  * @param enemy a pointer to the enemy
  * @param location the id of the location
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_set_location(Enemy * enemy, Id location);

/**
  * @brief It gets the id of an enemy location
  * @author Ignacio Nunnez
  * 
  * @param enemy a pointer to the enemy
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
Id enemy_get_location(Enemy * enemy);

/**
  * @brief It sets the health points (HP) of an enemy
  * @author Ignacio Nunnez
  * 
  * @param enemy a pointer to the enemy
  * @param health the number of HP to the enemy
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_set_health(Enemy * enemy, int health);

/**
  * @brief It gets the health of an enemy
  * @author Ignacio Nunnez
  * 
  * @param enemy a pointer to the enemy
  * @return the number of HP of the enemy
  */
int enemy_get_health(Enemy *enemy);

/**
  * @brief It prints the enemy information
  * @author Ignacio Nunnez
  *
  * This fucntion shows the id, name, location and health of the enemy.
  * @param enemy a pointer to the enemy
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS enemy_print(Enemy* enemy);

#endif