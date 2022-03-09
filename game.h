/** 
 * @brief It defines the game interface
 * 
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "player.h"
#include "object.h"
#include "enemy.h"

typedef struct _Game
{
  Player *player;//Id player_location;
  Object *object[MAX_OBJECTS];//Id object_location;
  Space *spaces[MAX_SPACES];
  Enemy *enemy;
  T_Command last_cmd;
} Game;

/**
  * @brief Creates the base of a new game
  * @author Profesores PPROG
  *
  * Sets to NO_ID all ids for he game
  * @param game a pointer to the game
  * @return allways Ok
  */
STATUS game_create(Game *game);

/**
  * @brief Updates the game
  * @author Profesores PPROG
  *
  * 
  * @param game a pointer to the game
  * @param cmd the cmd 
  * @return allways Ok
  */
STATUS game_update(Game *game, T_Command cmd,  char*arg);

/**
  * @brief Removes all the info of the game
  * @author Profesores PPROG
  *
  * Sets all spaces to NULL
  * @param game a pointer to the game
  * @return allways Ok
  */
STATUS game_destroy(Game *game);

/**
  * @brief Finish the game
  * @author Profesores PPROG
  *
  * @param game a pointer to the game
  * @return allways FALSE
  */
BOOL game_is_over(Game *game);

/**
  * @brief Prints useful info about
  * the game
  * @author Profesores PPROG
  *
  * @param game a pointer to the game
  */
void game_print_data(Game *game);

/**
  * @brief returns the space by its id
  * @author Profesores PPROG
  *
  * @param game a pointer to the game
  * @param id the id of the space
  * @returns ERROR if no id
  */
Space *game_get_space(Game *game, Id id);

/**
  * @brief returns player-location id
  * @author Profesores PPROG
  *
  * @param game a pointer to the game
  */
Id game_get_player_location(Game *game);

/**
  * @brief returns the space where an object is located
  * @author Profesores PPROG
  *
  * @param game a pointer to the game
  * @return NO_ID if theres no object located
  */
Id game_get_object_location(Game *game, Id id_obj);

/**
  * @brief returns last cd_command
  * @author Profesores PPROG
  *
  * @param game a pointer to the game
  */
T_Command game_get_last_command(Game *game);

/**
  * @brief adds a space to the game from game_load_space
  * @author Nicolas Victorino
  *
  * @param game a pointer to the game, @param space a pointer to the space
  * @return OK if it doesnt detect any error, in case it does it returns ERROR
  */
STATUS game_add_space(Game *game, Space *space);

/**
  * @brief adds a player to the game from game_load_player
  * @author Nicolas Victorino
  *
  * @param game a pointer to the game, @param player a pointer to the space
  * @return OK if it doesnt detect any error, in case it does it returns ERROR
  */
STATUS game_add_player(Game *game, Player *player);

/**
  * @brief adds a object to the game from game_load_object
  * @author Nicolas Victorino
  *
  * @param game a pointer to the game, @param object a pointer to the space
  * @return OK if it doesnt detect any error, in case it does it returns ERROR
  */
STATUS game_add_object(Game *game, Object *object);

/**
  * @brief Gets the id of a space, searching by its position
  * @author Profesores PPROG
  *
  * @param game a pointer to the game, @param position position of the space
  * @return NO_ID if the position value is not valid
  */
Id game_get_space_id_at(Game *game, int position);

/**
  * @brief sets the position of the player to a given space
  * @author Ignacio Nuñez
  *
  * @param game a pointer to the game, @param id identifier of the object where you want to set the player
  * @return OK if it doesnt detect any error, in case it does it returns ERROR
  */
STATUS game_set_player_location(Game *game, Id id);

/**
  * @brief sets the position of the object to a given space
  * @author Ignacio Nuñez
  *
  * @param game a pointer to the game, @param id_obj identifier of the object
  * @param id_loc identifier of the location to place de object
  * @return OK if it doesnt detect any error, in case it does it returns ERROR
  */
STATUS game_set_object_location(Game *game, Id id_obj, Id id_loc);

int game_get_n_objects(Game *game);
#endif
