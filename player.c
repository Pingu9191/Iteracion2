/**
* @brief It implements player module
*
* @file player.c
* @author Nicolas Victorino && Ignacio Nunnez
* @version 1.0
* @date 08/02/2022
* @copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

/**
 * @brief Player
 *
 * This struct stores all the information of a player.
 */

struct _Player {
  Id id;                    /*!< Id number of the player, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the player */
  Id location;              /*!< Id number of the location where the player is*/
  Id object;                /*!< Id number of the object the player has*/
};

/** player_create allocates memory for a new player
  *  and initializes its members
  */
Player* player_create(Id id) {
  Player *newPlayer = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newPlayer = (Player *) malloc(sizeof (Player));
  if (newPlayer == NULL) {
    return NULL;
  }

  /* Initialization of an empty player*/
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->location = NO_ID;
  newPlayer->object = NO_ID;

  return newPlayer;
}

/** player_destroy frees the previous memory allocation 
  *  for a player
  */
STATUS player_destroy(Player* player) {
  
  /* Error control */
  if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;
  return OK;
}

/** It gets the id of a player
  */
Id player_get_id(Player* player) {
  
  /* Error control */
  if (!player) {
    return NO_ID;
  }
  return player->id;
}

/** It sets the name of a player
  */
STATUS player_set_name(Player* player, char* name) {
  
  /* Error control */
  if (!player || !name) {
    return ERROR;
  }

  /* Error control */
  if (!strcpy(player->name, name)) {
    return ERROR;
  }
  return OK;
}

/** It returns the name of a player
  */
const char * player_get_name(Player* player) {
  
  /* Error control */
  if (!player) {
    return NULL;
  }
  return player->name;
}
/** It gets the id of a player location
  */
STATUS player_set_location(Player * player, Id location) {

  /* Error control */
  if (!player || !location) {
    return ERROR;
  }
  
  player->location = location;

  return OK;
}

/** It returns the location of a player
  */
Id player_get_location(Player* player) {

  /* Error control */
  if (!player) {
    return ERROR;
  }

  return player->location;
}

/** It gets the id of a player object
  */
STATUS player_set_object(Player * player, Id object) {

  /* Error control */
  if (!player || !object) {
    return ERROR;
  }
  
  player->object = object;

  return OK;
}

/** It returns the object of a player
  */
Id player_get_object(Player* player) {

  /* Error control */
  if (!player) {
    return ERROR;
  }

  return player->object;
}

/** It prints the player information
  */
STATUS player_print(Player* player) {

  /* Error Control */
  if (!player) {
    return ERROR;
  }

  /* 1. Print the id and the name of the object */
  fprintf(stdout, "--> Player (Id: %ld; Name: %s; Location-id: %ld; Object-id: %ld)\n", player->id, player->name, player->location, player->object);

  return OK;
}
