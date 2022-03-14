
/** 
 * @brief It implements the game interface and all the associated calls
 * for each command
 * 
 * @file game.c
 * @author Profesores PPROG
 * Modified by Nicolas Victorino && Ignacio Nunnez
 * @version 5.0 
 * @date 13-03-2022 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "object.h"
#include "player.h"
#include "space.h"
#include "set.h"
#include "enemy.h"

STATUS game_add_space(Game *game, Space *space);
STATUS game_add_player(Game *game, Player *player);
STATUS game_add_object(Game *game, Object *object);
Id game_get_space_id_at(Game *game, int position);
STATUS game_set_player_location(Game *game, Id id);
STATUS game_set_object_location(Game *game, Id id_obj, Id id_loc);

void game_command_unknown(Game *game);
void game_command_exit(Game *game);
STATUS game_command_next(Game *game);
STATUS game_command_back(Game *game);
STATUS game_command_right(Game *game);
STATUS game_command_left(Game *game);
STATUS game_command_take(Game *game, char* obj);
STATUS game_command_drop(Game *game);
STATUS game_command_attack(Game *game);

/**
   Game interface implementation
*/
STATUS game_create(Game *game)
{
  int i;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    game->object[i] = NULL;
  }

  game->player = NULL;
  game->last_cmd = NO_CMD;

  return OK;
}

/*
* Destroys the game and all its spaces, returning OK when done
*/
STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; i < MAX_OBJECTS && game->object[i] != NULL; i++)
  {
    object_destroy(game->object[i]);
  }

  player_destroy(game->player);

  enemy_destroy(game->enemy);

  return OK;
}

/*
*Adds a space to the game in the first available space position, and if there is none it returns ERROR
*/
STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;

  /*Error control*/
  if (space == NULL)
  {
    return ERROR;
  }

  /*Searches the first space position available*/
  while (i < MAX_SPACES && game->spaces[i] != NULL)
  {
    i++;
  }

  /*Error control (if there is no space position left)*/
  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

/*
* Adds a given object to the game
*/
STATUS game_add_object(Game *game, Object *object) 
{
  /*Error control*/
  if (object == NULL)
  return ERROR;

  int i = 0;

  /*Searches the first object position available*/
  while (i < MAX_OBJECTS && game->object[i] != NULL)
  {
    i++;
  }

  /*Error control (if there is no space position left)*/
  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->object[i] = object;

  return OK;    
}

/*
* Adds a given player to the game
*/
STATUS game_add_player(Game *game, Player *player) 
{
  /*Error control*/
  if (player == NULL)
    {
      return ERROR;
    }

  game->player = player;

  return OK;
}

STATUS game_add_enemy(Game *game, Enemy *enemy) 
{
  /*Error control*/
  if (enemy == NULL)
    {
      return ERROR;
    }

  game->enemy = enemy;

  return OK;
}

  /*
  * Gets the id of a space, searching by its position
  */
Id game_get_space_id_at(Game *game, int position)
{

  /*Error control*/
  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

/*
* Returns the space that coincides with the given id
*/
Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  /*Error control*/
  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

/*
*Moves the player to the space of the given id 
*/
STATUS game_set_player_location(Game *game, Id id)
{

  /*Error control*/
  if (id == NO_ID)
  {
    return ERROR;
  }
  
  player_set_location(game->player, id);

  return OK;
}

/*
* Places an object in the space of the given id
*/
STATUS game_set_object_location(Game *game, Id id_obj, Id id_loc)
{

  if ( game_get_object_location(game, id_obj) == NO_ID){}
  else{
    space_delete_object(game_get_space(game, game_get_object_location(game, id_obj)), id_obj);
  }

  space_add_object(game_get_space(game, id_loc), id_obj);

  return OK;

}

/*
* Gets the location of the player
*/
Id game_get_player_location(Game *game)
{
  return player_get_location(game->player);
}

/*
* Gets the location of an object
*/
Id game_get_object_location(Game *game, Id id_obj)
{
  int i;

  /*Goes space from space if there's space with object*/
  for (i=0 ; i < MAX_SPACES ; i++) {
    if (set_idInSet(space_get_object(game->spaces[i]), id_obj) == TRUE) {
      return space_get_id(game->spaces[i]);
    }
  }
  return NO_ID;
}

/*
* Gets a command and depending of which one it is, it executes one of the following functions
*/
STATUS game_update(Game *game, T_Command cmd, char *arg)
{
  game->last_cmd = cmd;
  
  switch (cmd)
  {
    case UNKNOWN:
      game_command_unknown(game);
      break;

    case EXIT:
      game_command_exit(game);
      break;

    case NEXT:
      return game_command_next(game);
      break;

    case BACK:
      return game_command_back(game);
      break;

    case RIGHT:
      return game_command_right(game);
      break;

    case LEFT:
      return game_command_left(game);
      break;
    case TAKE:
      return game_command_take(game, arg);
      break;
    case DROP:
      return game_command_drop(game);
      break;  
    
    case ATTACK:
      return game_command_attack(game);
      break;

    default:
      break;
  }

  return OK;
}

/*
* Gets the last command that has been used
*/
T_Command game_get_last_command(Game *game)
{
  return game->last_cmd;
}

/*
* Prints all the information in the struct game (Spaces, oject location, player location)
*/
void game_print_data(Game *game)
{
  int i = 0;

  printf("\n\n-------------\n\n");

  /*1. Prints the spaces and the information of each one*/
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  /*2. Printf the object loaction*/
  printf("=> Objects: \n");
  for(i = 0 ; i < MAX_OBJECTS && game->object[i] != NULL ; i++)
  {
    object_print(game->object[i]);
  }

  /*3. Printf the player loaction*/
  printf("=> Player location: %d\n", (int)game_get_player_location(game));
}

/*
* Finishes the game
*/
BOOL game_is_over(Game *game)
{
  if (player_get_health(game->player) == 0) {
    return TRUE;
  } else {
  return FALSE;
  }
}

/**
   Calls implementation for each action 
*/
void game_command_unknown(Game *game)
{

}

void game_command_exit(Game *game)
{
  
}

/*
* Command that moves the player one space position to thes south, in case there is one.
* If not it doesnt move the player
*/
STATUS game_command_next(Game *game)
{
  /*Initializes the private variables current_id and space_id*/
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  /*Saves the current location of the player in space_id*/
  space_id = game_get_player_location(game);

  /*Error control. Checks if the id of the space of the player is correctly saved*/
  if (space_id == NO_ID)
  {
    return ERROR;
  }

  /*Searches if there is a space south of the space of the player, and in case there is one, it moves the player to that space*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      } else {
        return ERROR;
      }
    } 
  }
  return OK;
}

/*
* Command that moves the player one space position to the north, in case there is one.
* If not it doesnt move the player
*/
STATUS game_command_back(Game *game)
{

    /*Initializes the private variables current_id and space_id*/
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  /*Saves the current location of the player in space_id*/
  space_id = game_get_player_location(game);

  /*Error control. Checks if the id of the space of the player is correctly saved*/
  if (NO_ID == space_id)
  {
    return ERROR;
  }

/*Searches if there is a space north of the space of the player, and in case there is one, it moves the player to that space*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
        
      } else {
      return ERROR;
      }
    } 
  }
  return OK;
}

/*
* Command that moves the player one space position to the east, in case there is one.
* If not it doesnt move the player
*/
STATUS game_command_right(Game *game)
{

    /*Initializes the private variables current_id and space_id*/
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  /*Saves the current location of the player in space_id*/
  space_id = game_get_player_location(game);

  /*Error control. Checks if the id of the space of the player is correctly saved*/
  if (NO_ID == space_id)
  {
    return ERROR;
  }

/*Searches if there is a space east of the space of the player, and in case there is one, it moves the player to that space*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_east(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);

      } else {
      return ERROR;
      }
    } 
  }        
  return OK;
}

/*
* Command that moves the player one space position to the west, in case there is one.
* If not it doesnt move the player
*/
STATUS game_command_left(Game *game)
{

    /*Initializes the private variables current_id and space_id*/
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  /*Saves the current location of the player in space_id*/
  space_id = game_get_player_location(game);

  /*Error control. Checks if the id of the space of the player is correctly saved*/
  if (NO_ID == space_id)
  {
    return ERROR;
  }

/*Searches if there is a space west of the space of the player, and in case there is one, it moves the player to that space*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_west(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      } else {
      return ERROR;
      } 
    } 
  }
  return OK;
}

/*
* Command that make the player take the object.
* If the player and object aren't in the same room returns ERROR.
*/
STATUS game_command_take(Game *game, char *obj) 
{
  if(obj[0] != 'o' && obj[0] != 'O')
  return ERROR;

  obj[0] = obj[1];
  obj[1] = obj[2];
  obj[2] = '\0';

  Id id_obj = atoi(obj);
  if(id_obj == 0){
    return ERROR;
  }

  /*Check if Player and object are in the same place*/
  if (game_get_object_location(game, id_obj) != game_get_player_location(game)) {
    return ERROR;
  }

  if (player_get_object(game->player) != -1) {
    return ERROR;
  }

  Id loc = game_get_object_location(game, id_obj);

  /*Gives the object to the player*/
  if (player_set_object(game->player, id_obj) == ERROR) {
    return ERROR;
  }

  /*Removes the object from the space*/
  if (space_delete_object(game_get_space(game, loc), id_obj) == ERROR) {
    return ERROR;
  }

  return OK;
}

/*
* Command that make the player drop the object on the space.
* If player aint object, returns ERROR
*/
STATUS game_command_drop(Game *game)
{
  /*Checks the player has an object*/
  if(player_get_object(game->player) == NO_ID)
  return ERROR;

  /*Leaves the object on the space*/
  game_set_object_location(game, player_get_object(game->player), game_get_player_location(game));

  /*Removes the object from the player*/
  player_set_object(game->player, NO_ID);

  return OK;
}

/*
* Command that 50%-50% drops the HP of the player or the enemy
* If player and enemy arent in the same room, returns ERROR
*/
STATUS game_command_attack(Game *game)
{

  /*Checks if player and enemy are in the same room*/
  if(player_get_location(game->player) != enemy_get_location(game->enemy))
  return ERROR;

  /*Cheks if enemy is alive*/ 
  if (enemy_get_health(game->enemy) == 0)
  return ERROR; 
   
  /*Generates random number*/
  srand(time(NULL));
  int i = rand() % 10;

  /*Depending on the value of i, player or enemy lose HP*/
  if(i<5){
    player_set_health(game->player, player_get_health(game->player) - 1);
  }
  else{
    enemy_set_health(game->enemy, enemy_get_health(game->enemy) - 1);
  }

  return OK;
}

int game_get_n_objects(Game *game) {

  int i = 0;

  if (!game)
  return NO_ID;

  while (i < MAX_OBJECTS && game->object[i] != NULL) {
    i++;
  }

  if (i > MAX_OBJECTS)
  return NO_ID;

  return i + 1;
}

void game_set_cmd_st(Game* game, STATUS cmd_st) {
  game->cmd_status = cmd_st;
}

STATUS game_get_cmd_st(Game *game) {
  return game->cmd_status;
}

