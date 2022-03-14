/** 
 * @brief It implements all necessary functions to load the ant_game from a given file
 * @file game_reader.c
 * @author Ignacio Nunnez && Nicolas Victorino
 * @version 4.0 
 * @date 10-03-2022 
 * @copyright GNU Public License
 */

#include "game_reader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
* Loads the spaces and the information of each from a given file
* In case debug is being used it prints the information of each space that is loaded
* If anything has gonne wrong while using the file, it will change the exit status from OK to ERROR
*/
STATUS game_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  char **gdesc = space_create_gdesc();
  char **gdesc_n = NULL;
  int i;
  /*Error control*/
  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");

  /*Error control*/
  if (file == NULL)
  {
    return ERROR;
  }


  /*
  * While the loop reads information in the current line from the file: "hormiguero.dat", it divides that line in smaller tokens.
  * Each token has a piece of information, in the following order:
  * ID of the space, name, space at north, at east, at south, and at west.
  */
  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {



      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      for (i = 0; i < space_get_gdescY(); i++) {
        toks = strtok(NULL, "|");
        strcpy(*(gdesc + i), toks);
      }

    /*If debug is being used, it will print all the information from the current space that is being loaded*/
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif

  /*Defines a private variable called "space" and saves a pointer to space with the given id in it*/
      space = space_create(id);
      gdesc_n= space_copy_gdesc(gdesc);

  /*Error control, and in case everything is fine, it saves the information gotten in the prior loop in the newly created space*/
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        space_set_gdesc(space, gdesc_n);
        game_add_space(game, space);
      }
    }
  }

  /*Error control, if it has given an error at any moment while using the file, ferror while make the if condition true.
   This will change the private status variable declared at the beggining of the function from OK to ERROR. */
  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  space_remove_gdesc_game(gdesc);

  return status;
}

/*
* Loads the player and its information
* In case debug is being used it prints the information of the loaded player
* If anything has gonne wrong while using the file, it will change the exit status from OK to ERROR
*/
STATUS game_load_players(Game *game, char *filename) 
{
 FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, object = NO_ID, location = NO_ID;;
  Player *player = NULL;
  STATUS status = OK;

  /*Error control*/
  if (!filename)
  {
    return ERROR;
  }

  /*Error control*/
  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  
  /*
  * While the loop reads information in the current line from the file: "hormiguero.dat", it divides that line in smaller tokens.
  * Each token has a piece of information, in the following order:
  * ID of the player, name, Id of the object that the player has (NO_ID if it has no object), and location.
  */
  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#p:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      object = atol(toks);
      toks = strtok(NULL, "|");
      location = atol(toks);

  /*If debug is being used, it will print all the information from the current player that is being loaded*/
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld\n", id, name, objet, location);
#endif

  /*Defines a private variable called "player" and saves a pointer to player with the given id in it*/
      player = player_create(id);

  /*Error control, and in case everything is fine, it saves the information gotten in the prior loop in the newly created player*/
      if (player != NULL)
      {
        player_set_name(player, name);
        player_set_object(player, object);
        player_set_location(player, location);
        player_set_health(player, MAX_HEALTH_PLAYER);
        game_add_player(game, player); 
      }
    }
  }

  /*Error control, if it has given an error at any moment while using the file, ferror while make the if condition be true.
   This will change the private status variable declared at the beggining of the function from OK to ERROR. */
  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/*
* Loads the object and its information
* In case debug is being used it prints the information of the loaded object
* If anything has gonne wrong while using the file, it will change the exit status from OK to ERROR
*/
STATUS game_load_objects(Game *game, char *filename) 
{
 FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, loc = NO_ID;
  Object *object = NULL;
  STATUS status = OK;

  /*Error control*/
  if (!filename)
  {
    return ERROR;
  }

  /*Error control*/
  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  /*
  * While the loop reads information in the current line from the file: "hormiguero.dat", it divides that line in smaller tokens.
  * Each token has a piece of information, in the following order:
  * ID of the object, name.
  */
  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      loc = atol(toks);

  /*If debug is being used, it will print all the information from the current object that is being loaded*/
#ifdef DEBUG
      printf("Leido: %ld|%s\n", id, name);
#endif

  /*Defines a private variable called "object" and saves a pointer to object with the given id in it*/
      object = object_create(id);

  /*Error control, and in case everything is fine, it saves the information gotten in the prior loop in the newly created object*/
      if (object != NULL)
      {
        object_set_name(object, name);
        game_add_object(game, object); 
        game_set_object_location(game, id, loc);
      }
    }
  }

  /*Error control, if it has given an error at any moment while using the file, ferror while make the if condition be true.
   This will change the private status variable declared at the beggining of the function from OK to ERROR. */
  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/*
* Loads the enemy and its information
* In case debug is being used it prints the information of the loaded enemy
* If anything has gonne wrong while using the file, it will change the exit status from OK to ERROR
*/
STATUS game_load_enemy(Game *game, char *filename) 
{
 FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;;
  Enemy *enemy = NULL;
  STATUS status = OK;

  /*Error control*/
  if (!filename)
  {
    return ERROR;
  }

  /*Error control*/
  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  
  /*
  * While the loop reads information in the current line from the file: "hormiguero.dat", it divides that line in smaller tokens.
  * Each token has a piece of information, in the following order:
  * ID of the player, name, Id of the object that the player has (NO_ID if it has no object), and location.
  */
  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#e:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);

  /*If debug is being used, it will print all the information from the current player that is being loaded*/
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld\n", id, name, location);
#endif

  /*Defines a private variable called "player" and saves a pointer to player with the given id in it*/
      enemy = enemy_create(id);

  /*Error control, and in case everything is fine, it saves the information gotten in the prior loop in the newly created player*/
      if (enemy != NULL)
      {
        enemy_set_name(enemy, name);
        enemy_set_location(enemy, location);
        enemy_set_health(enemy, MAX_HEALTH_ENEMY);
        game_add_enemy(game, enemy); 
      }
    }
  }

  /*Error control, if it has given an error at any moment while using the file, ferror while make the if condition be true.
   This will change the private status variable declared at the beggining of the function from OK to ERROR. */
  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}


 /**
 * Creates a new game and loads the spaces from a file
 * Returns status expressions ERROR in case something goes wrong or OK if succesful
 */
STATUS game_create_from_file(Game *game, char *filename)
{
  /*Error control and creates the game*/
  if (game_create(game) == ERROR)
    return ERROR;

/*Error control and load the spaces into the game from a file*/
  if (game_load_spaces(game, filename) == ERROR)
    return ERROR;

/*Error control and load the player into the game from a file*/
  if (game_load_players(game, filename) == ERROR)
    return ERROR;

/*Error control and load the object into the game from a file*/
  if (game_load_objects(game, filename) == ERROR)
    return ERROR;

  /*Error control and load the enemy into the game from a file*/
  if (game_load_enemy(game, filename) == ERROR)
    return ERROR;

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));

  return OK;
}
