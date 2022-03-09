/** 
 * @brief It implements the command interpreter
 * 
 * @file command.c
 * @author Profesores PPROG
 * @version 2.1
 * @date 19-02-2022 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <string.h>
#include "command.h"

#define CMD_LENGHT 30

/*
* Declaration of a matrix that includes all the commands that are going to be used during the execution of the game 
*/
char *cmd_to_str[N_CMD]
[N_CMDT] = {{"", "No command"},
      {"", "Unknown"},
			{"e", "Exit"},
			{"n", "Next"},
			{"b", "Back"},
      {"r", "Right"},
      {"l", "Left"},
      {"t", "Take"},
      {"d", "Drop"}};

/*
* Gets the last command that the user inputted and assigns them a numeric value depending of what they do
*/
T_Command command_get_user_input(char *arg)
{
  /*Assigns a value to the newly created variable "cmd", that corresponds to the command: UNKNOWN (state by default of a command)*/
  T_Command cmd = NO_CMD;
  char *input;
  char *second;
  char buffer[CMD_LENGHT] = "";
  int i = UNKNOWN - NO_CMD + 1;

  /*Compares the command inputted to all the commands available in the game, and when it finds a match, it outputs the numeric value of that command, assigning it to the variable "cmd"*/
  
  scanf("%s", buffer);
  input = strtok(buffer, " ");
  second = strtok(NULL, " ");
  if (second != NULL) {
    strcpy(arg, second);
  } else {
    arg[0] = 0;
  }

    cmd = UNKNOWN;
    while (cmd == UNKNOWN && i < N_CMD)
    {
      if (!strcasecmp(input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL]))
      {
        cmd = i + NO_CMD;
      }
      else
      {
        i++;
      }
    }
  
  
  return cmd;
}
