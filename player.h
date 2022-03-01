/**
* @brief It defines player module
*
* @file player.h
* @author Nicolas Victorino && Ignacio Nunnez
* @version 1.0
* @date 08/02/2022
* @copyright GNU Public License
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

#define MAX_PLAYERS 100
#define FIRST_PLAYER 1
#define MAX_HEALTH_PLAYER 5

/**
  * @brief It creates a new player
  * @author Ignacio Nunnez
  *
  * player_create allocates memory for a new player
  *  and initializes its members
  * @param id the identification number for the new player
  * @return a new player, initialized
  */
Player* player_create(Id id);

/**
  * @brief It destroys a player
  * @author Ignacio Nunnez
  *
  * player_destroy frees the previous memory allocation 
  *  for a player
  * @param player a pointer to the player that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS player_destroy(Player* player);

/**
  * @brief It gets the id of a player
  * @author Ignacio Nunnez
  * 
  * @param player a pointer to the player  
  * @return the id of player
  */
Id player_get_id(Player* player);

/**
  * @brief It sets the name of a player
  * @author Ignacio Nunnez
  * 
  * @param player a pointer to the player
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_name(Player* player, char* name);

/**
  * @brief It gets the name of a player
  * @author Ignacio Nunnez
  * 
  * @param player a pointer to the player
  * @return  a string with the name of the player
  */
const char * player_get_name(Player* player);

/**
  * @brief It sets the id of a player location
  * @author Ignacio Nunnez
  * 
  * @param player a pointer to the player
  * @param location the id of the location
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_location(Player * player, Id location);

/**
  * @brief It gets the id of a player location
  * @author Ignacio Nunnez
  * 
  * @param player a pointer to the player
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
Id player_get_location(Player * player);

/**
  * @brief It sets the id of a player object
  * @author Ignacio Nunnez
  * 
  * @param player a pointer to the player
  * @param object the id of the object
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_object(Player * player, Id object);

/**
  * @brief It gets the id of a player object
  * @author Ignacio Nunnez
  * 
  * @param player a pointer to the player
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
Id player_get_object(Player * player);

/**
  * @brief It sets the health points (HP) of a player
  * @author Ignacio Nunnez
  * 
  * @param player a pointer to the player
  * @param health the number of HP to the player
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_health(Player * player, int health);

/**
  * @brief It gets the health of a player
  * @author Ignacio Nunnez
  * 
  * @param player a pointer to the player
  * @return the number of HP of the player
  */
int player_get_health(Player *player);

/**
  * @brief It prints the player information
  * @author Ignacio Nunnez
  *
  * This fucntion shows the id, name, location and object of the player.
  * @param player a pointer to the player
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS player_print(Player* player);

#endif
