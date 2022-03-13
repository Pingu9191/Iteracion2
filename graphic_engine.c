/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * Modified by Nicolas Victorino
 * @version 2.2
 * @date 11-03-2022
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include "graphic_engine.h"
#include "libscreen.h"
#include "command.h"
#include "space.h"
#include "types.h"
#include "enemy.h"

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
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_right = NO_ID, id_left =NO_ID; //Modificado(obj_loc) Añadir id_right e id_letf
  Space *space_act = NULL;
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  char **gdesc_n = NULL, **gdesc_a = NULL, **gdesc_b = NULL, **gdesc_r = NULL, **gdesc_l = NULL;
  int i = 0;

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);
    id_right = space_get_east(space_act);
    id_left = space_get_west(space_act);
  }

  gdesc_b = (char**)space_get_gdesc(game_get_space(game, id_back));

    if (id_back != NO_ID) 
    {
      sprintf(str, "   _________");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |      %.3d|", (int)id_back);
      screen_area_puts(ge->map, str);
      for (i = 0; i < space_get_gdescY(); i++) {
      sprintf(str, "  |%s|", gdesc_b[i]);
      screen_area_puts(ge->map, str);
      }
    }

  gdesc_a = (char**)space_get_gdesc(game_get_space(game, id_act));

    if (id_act != NO_ID && id_left == NO_ID && id_right == NO_ID) 
    {
      sprintf(str, "   _________");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |m0^   %.3d|", (int)id_act);
      screen_area_puts(ge->map, str);
      for (i = 0; i < space_get_gdescY(); i++) {
      sprintf(str, "  |%s|", gdesc_a[i]);
      screen_area_puts(ge->map, str);
      }
    }

  gdesc_n = (char**)space_get_gdesc(game_get_space(game, id_next));

    if (id_next != NO_ID) 
    {
      sprintf(str, "   _________");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |      %.3d|", (int)id_next);
      screen_area_puts(ge->map, str);
      for (i = 0; i < space_get_gdescY(); i++) {
      sprintf(str, "  |%s|", gdesc_n[i]);
      screen_area_puts(ge->map, str);
      }
    }

  gdesc_r = (char**)space_get_gdesc(game_get_space(game, id_right));

    if (id_right != NO_ID && id_left == NO_ID) 
    {
      sprintf(str, "   _________   _________");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |m0^   %d| |      %.3d|", (int)id_act, (int)id_right);
      screen_area_puts(ge->map, str);
      for (i = 0; i < space_get_gdescY(); i++) {
      sprintf(str, "  |%s| |%s|", gdesc_a[i], gdesc_r[i]);
      screen_area_puts(ge->map, str);
      }
    }

  gdesc_l = (char**)space_get_gdesc(game_get_space(game, id_left));

    if (id_left != NO_ID && id_right == NO_ID) 
    {
      for (i=0; i < space_get_gdescY() + 2; i++) {
        sprintf(str, " ");
        screen_area_puts(ge->map, str);
      }
      sprintf(str, "   _________   _________");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |      %.3d| |m0^   %.3d|", (int)id_left, (int)id_act);
      screen_area_puts(ge->map, str);
      for (i = 0; i < space_get_gdescY(); i++) {
      sprintf(str, "  |%s| |%s|", gdesc_l[i], gdesc_a[i]);
      screen_area_puts(ge->map, str);
      }
    }

    if (id_left != NO_ID && id_right != NO_ID) 
    {
      for (i=0; i < space_get_gdescY() + 2; i++) {
        sprintf(str, " ");
        screen_area_puts(ge->map, str);
      }
      sprintf(str, "   _________   _________   _________");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |      %.3d| |m0^   %.3d| |      %.3d|", (int)id_left, (int)id_act, (int)id_right);
      screen_area_puts(ge->map, str);
      for (i = 0; i < space_get_gdescY(); i++) {
      sprintf(str, "  |%s| |%s| |%s|", gdesc_l[i], gdesc_a[i], gdesc_r[i]);
      screen_area_puts(ge->map, str);
      }
    }
 

  /* Paint in the description area */ //Modificado, añadido bucle
  screen_area_clear(ge->descript);

    sprintf(str, "  Objects location:"); 
    screen_area_puts(ge->descript, str);
    for (i=0; i < game_get_n_objects(game)-1; i++) {
      sprintf(str, "%s(%d): %d ", object_get_name(game->object[i]), (int)object_get_id(game->object[i]), (int)game_get_object_location(game, object_get_id(game->object[i])));
      screen_area_puts(ge->descript, str);
    }
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "Player location: %d", (int)game_get_player_location(game));
    screen_area_puts(ge->descript, str);
    sprintf(str, "Player object: %d", (int)player_get_object(game->player));
    screen_area_puts(ge->descript, str);
    sprintf(str, "Player HP: %d", player_get_health(game->player));
    screen_area_puts(ge->descript, str);
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "Enemy location: %d", (int)enemy_get_location(game->enemy));
    screen_area_puts(ge->descript, str);
    sprintf(str, "Enemy HP: %d", enemy_get_health(game->enemy));
    screen_area_puts(ge->descript, str);
  


  /* Paint in the banner area */
  screen_area_puts(ge->banner, "    The anthill game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n , back or b , left or l , right or r , take or t , drop or d , attack or a , exit or e (put a space after each  command)");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = game_get_last_command(game);
  if (game_get_cmd_st(game) == OK) {
  sprintf(str, " %s (%s): OK", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);
  } else {
  sprintf(str, " %s (%s): ERROR", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);
  }

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
