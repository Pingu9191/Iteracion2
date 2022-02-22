/**
* @brief It implements enemy module
*
* @file Enemy.c
* @author Ignacio Nunnez
* @version 1.0
* @date 22/02/2022
* @copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enemy.h"

/**
 * @brief Enemy
 *
 * This struct stores all the information of a enemy.
 */
struct _Enemy {
  Id id;                    /*!< Id number of the Enemy, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the Enemy */
  Id location;              /*!< Id number of the location where the Enemy is*/
  int health;      /*!< The health points of the enemy */
};

/** Enemy_create allocates memory for a new enemy
  *  and initializes its members
  */
Enemy* enemy_create(Id id) {
  Enemy *newEnemy = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newEnemy = (Enemy *) malloc(sizeof (Enemy));
  if (newEnemy == NULL) {
    return NULL;
  }

  /* Initialization of an empty enemy*/
  newEnemy->id = id;
  newEnemy->name[0] = '\0';
  newEnemy->location = NO_ID;
  newEnemy->health = 0;

  return newEnemy;
}

/** enemy_enemy frees the previous memory allocation 
  *  for an enemy
  */
STATUS enemy_destroy(Enemy* enemy) {
  
  /* Error control */
  if (!enemy) {
    return ERROR;
  }

  free(enemy);
  enemy = NULL;
  return OK;
}

/** It gets the id of a enemy
  */
Id enemy_get_id(Enemy* enemy) {
  
  /* Error control */
  if (!enemy) {
    return NO_ID;
  }
  return enemy->id;
}

/** It sets the name of an enemy
  */
STATUS enemy_set_name(Enemy* enemy, char* name) {
  
  /* Error control */
  if (!enemy || !name) {
    return ERROR;
  }

  /* Error control */
  if (!strcpy(enemy->name, name)) {
    return ERROR;
  }
  return OK;
}

/** It returns the name of an enemy
  */
const char * enemy_get_name(Enemy* enemy) {
  
  /* Error control */
  if (!enemy) {
    return NULL;
  }
  return enemy->name;
}

/** It sets the id of an enemy location
  */
STATUS enemy_set_location(Enemy * enemy, Id location) {

  /* Error control */
  if (!enemy || !location) {
    return ERROR;
  }
  
  enemy->location = location;

  return OK;
}

/** It returns the location of an enemy
  */
Id enemy_get_location(Enemy* enemy) {

  /* Error control */
  if (!enemy) {
    return ERROR;
  }

  return enemy->location;
}

/** It sets the health points of an enemy
  */
STATUS enemy_set_health(Enemy * enemy, int health) {

  /* Error control */
  if (!enemy || !health || health < 0) {
    return ERROR;
  }
  
  enemy->health = health;

  return OK;
}

/** It returns the HP of an enemy
  */
int enemy_get_health(Enemy* enemy) {

  /* Error control */
  if (!enemy) {
    return ERROR;
  }

  return enemy->health;
}

/** It prints the enemy information
  */
STATUS enemy_print(Enemy* enemy) {

  /* Error Control */
  if (!enemy) {
    return ERROR;
  }

  /* 1. Prints the Id, name, location and HP of the enemy*/
  fprintf(stdout, "--> Enemy (Id: %ld; Name: %s; Location-id: %ld; Health Points: %d)\n", enemy->id, enemy->name, enemy->location, enemy->health);

  return OK;
}