/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include "graphic_engine.h"
#include "libscreen.h"
#include "command.h"
#include "space.h"
#include "types.h"

#define ROWS 23
#define COLUMNS 80

struct _Graphic_engine
{
  Area *map, *descript, *banner, *help, *feedback;
};

Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init(ROWS, COLUMNS);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
    return NULL;

  ge->map = screen_area_init(1, 1, 48, 13);
  ge->descript = screen_area_init(50, 1, 29, 13);
  ge->banner = screen_area_init(28, 15, 23, 1);
  ge->help = screen_area_init(1, 16, 78, 2);
  ge->feedback = screen_area_init(1, 19, 78, 3);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge)
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc[MAX_OBJECTS]; //Modificado(obj_loc)
  Space *space_act = NULL;
  Object *obj[MAX_OBJECTS]; // Modificado
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  int i = 0;

  //Modificado, para poner la localizacion de los objetos a NO_ID y todos los punteros a objeto  a NULL
  for (i = 0; i < game_get_n_objects(game); i++) {
    obj_loc[i] = NO_ID;
    obj[i] = NULL;
  }

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);

    for (i = 0; i < game_get_n_objects(game); i++) { //Modificado, añadido bucle y object set graphic
      if (game_get_object_location(game, object_get_id(obj[i])) == id_back)
        object_set_graphic (obj[i], '*');
      else
        object_set_graphic (obj[i], ' ');
    }

    if (id_back != NO_ID) //Hay que ver como modificarlo para que añada varios objetoes (puede que con un bucle de todos los obj funciona?)
    {
      sprintf(str, "  |         %2d|", (int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", object_get_graphic(obj[i]));
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }

    for (i = 0; i < game_get_n_objects(game); i++) { //Modificado, añadido bucle y object set graphic
    if (game_get_object_location(game, object_get_id(obj[i])) == id_act)
      object_set_graphic (obj[i], '*');
    else
      object_set_graphic (obj[i], ' ');
    }

    if (id_act != NO_ID)
    {
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      /*\\(\")/ CODIFICACION HORMIGA */
      sprintf(str, "  | gpp0^   %2d|", (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", object_get_graphic(obj[i]));
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }

    for (i = 0; i < MAX_OBJECTS; i++) { //Modificado, añadido bucle y object set graphic
    if (game_get_object_location(game, object_get_id(obj[i])) == id_next)
      object_set_graphic (obj[i], '*');
    else
      object_set_graphic (obj[i], ' ');
    }

    if (id_next != NO_ID)
    {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |         %2d|", (int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", object_get_graphic(obj[i]));
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */ //Modificado, añadido bucle
  screen_area_clear(ge->descript);

    sprintf(str, "  Objects location:"); 
    screen_area_puts(ge->descript, str);
    sprintf(str, "%d: %d, %d: %d, %d:%d, %d: %d", (int)object_get_id(obj[0]), (int)obj_loc[0], (int)object_get_id(obj[1]), (int)obj_loc[1], (int)object_get_id(obj[2]), (int)obj_loc[2], (int)object_get_id(obj[3]), (int)obj_loc[3]);
    screen_area_puts(ge->descript, str);
    sprintf(str, "  Player location: %d", (int)game_get_player_location(game));
    screen_area_puts(ge->descript, str);
    sprintf(str, "Player object: %d", (int)player_get_object(game->player));
    screen_area_puts(ge->descript, str);
    sprintf(str, " Player HP: %d", player_get_health(game->player));
    screen_area_puts(ge->descript, str);
    sprintf(str, "Enemy location: %d", (int)enemy_get_location(game->enemy));
    screen_area_puts(ge->descript, str);
    sprintf(str, "Enemy HP: %d", enemy_get_health(game->enemy));
    screen_area_puts(ge->descript, str);
  


  /* Paint in the banner area */
  screen_area_puts(ge->banner, " The anthill game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n , back or b , left or l , right or r , take or t , drop or d , attack or a , exit or e ");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s (%s)", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
