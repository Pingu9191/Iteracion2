/** 
 * @brief It defines all necessary 
 * to load the game
 * @file game_reader.c
 * @author Ignacio Nunnez && Nicolas Victorino
 * @version 1.0 
 * @date 03-02-2022 
 * @copyright GNU Public License
 */

#include "command.h"
#include "space.h"
#include "types.h"
#include "game.h"

/**
  * @brief Loads the spaces from a file, and saves them in the game struct
  * @author Nicolas Victorino
  * 
  * @param game a pointer to the struct Game, @param filename is the file from where the spaces are being loaded
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_load_spaces(Game *game, char *filename);

/**
  * @brief Loads the player from a file, and saves it in the game struct
  * @author Nicolas Victorino
  * 
  * @param game a pointer to the struct Game, @param filename is the file from where the spaces are being loaded
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_load_players(Game *game, char *filename);

/**
  * @brief Loads the object from a file, and saves it in the game struct
  * @author Nicolas Victorino
  * 
  * @param game a pointer to the struct Game, @param filename is the file from where the spaces are being loaded
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_load_objects(Game *game, char *filename);

/**
  * @brief It creates the game from a file and loads the objects, players and spaces to the game
  * @author Nicolas Victorino
  *
  * @param game where it is going to save the struct of the game,@param filename from where it loads all the spaces, objects and players
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_create_from_file(Game *game, char *filename);