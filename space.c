/** 
 * @brief It implements the space module
 * 
 * @file space.c
 * @author Profesores PPROG
 * Modified by Nicolas Victorino & Ignacio Nunnez
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

struct _Space {
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Id north;                 /*!< Id of the space at the north */
  Id south;                 /*!< Id of the space at the south */
  Id east;                  /*!< Id of the space at the east */
  Id west;                  /*!< Id of the space at the west */
  Set *object;              /*!< Id of the object located in the space */
  char **gdesc;             /*!< Matrix with the gdesc graphics*/
};

/** space_create allocates memory for a new space
  *  and initializes its members
  */
Space* space_create(Id id) {
  Space *newSpace = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *) malloc(sizeof (Space));
  if (newSpace == NULL) {
    return NULL;
  }

  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;
  newSpace->object = set_create();
  newSpace->gdesc = NULL;

  return newSpace;
}

/** space_destroy frees the previous memory allocation 
  *  for a space
  */
STATUS space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }

  if(space->gdesc != NULL)
  space_remove_gdesc(space);

  free(space);
  space = NULL;
  return OK;
}

/*Set a given gdesc in a space*/
STATUS space_set_gdesc(Space* space, char** gdesc) {

  /*CONTROL ERROR*/
  if (!space || !gdesc) {
    return ERROR;
  }

  space->gdesc = gdesc;
  return OK;

}

/*Returns the pointer to the gdesc_matrix*/
const char** space_get_gdesc(Space* space) {

  /*CONTROL ERROR*/
  if(!space)
  return NULL;

  return (const char**)space->gdesc;
}

/** It gets the id of a space
  */
Id space_get_id(Space* space) {
  /*CONTROL ERROR*/
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

/** It sets the name of a space
  */
STATUS space_set_name(Space* space, char* name) {
  /*CONTROL ERROR*/
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }
  return OK;
}

/** It gets the name of a space
  */
const char * space_get_name(Space* space) {
  /*CONTROL ERROR*/
  if (!space) {
    return NULL;
  }
  return space->name;
}

/** It sets the id of the space located at the north
  */
STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}
/** It gets the id of the space located at the north
  */
Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

/** It sets the id of the space located at the south
  */
STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}
/** It gets the id of the space located at the south
  */
Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

/** It sets the id of the space located at the east
  */
STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}
/** It gets the id of the space located at the east
  */
Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

/** It sets the id of the space located at the west
  */
STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}
/** It gets the id of the space located at the west
  */
Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}

/** It sets the id of an object in the given space
  */
STATUS space_add_object(Space* space, Id id) {
  if (!space) {
    return ERROR;
  }
  
  if(set_add_id(space->object, id)==ERROR)
  return ERROR;
  
  return OK;
}
/** It gets the id of the object in the given space
  */
Set *space_get_object (Space *space) // Deberia devolver set??
{
  if (!space) {
    return NULL;
  }
  return space->object;
}

/** It deletes one id of an object-set in the given space
  */
STATUS space_delete_object(Space* space, Id id) {
  if (!space) {
    return ERROR;
  }

  if(set_del_id(space->object, id)==ERROR)
  return ERROR;

  return OK;
}

/** It sets set of objects  the given space
  */
STATUS space_set_object(Space* space, Set *set) {
  if(!space)
  return ERROR;

  set_destroy(space->object);
  space->object = set;
  return OK;
}

/** It prints the space information
  */
STATUS space_print(Space* space) {
  Id idaux = NO_ID;

  /* Error Control */
  if (!space) {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
 
  /* 2. For each direction, print its link */ 
  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }
  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }
  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }
  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  /* 3. Print all objects in the space*/
  printf("Set of objects:\n");
  set_print(space->object);

  /* 4. Print the gdesc*/
  int i, j;

  for(i=0;i<GDESC_X;i++){
    for(j=0;j<GDESC_Y;j++){
      printf("%c", space->gdesc[i][j]);
    }
    printf("\n");
  }

  return OK;
}

/*ACCES TO MACRO*/
int space_get_gdescX() {
  return GDESC_X;
}

/*ACCES TO MACRO*/
int space_get_gdescY() {
  return GDESC_Y;
}

/*Creates empty gdesc*/
char ** space_create_gdesc () {

  char **gdesc_new;
  int i;

  /*Reserves memory for string of pointers*/
  if ((gdesc_new = (char **)malloc(sizeof(char *)*GDESC_Y)) == NULL)
  return NULL;

  /*Reserves memory for every pointer*/
  for (i = 0; i < GDESC_Y; i++) {
    if ( (gdesc_new[i] = (char *)malloc(sizeof(char) * (GDESC_X + 1))) == NULL ){
    free(gdesc_new);
    return NULL;
    }
  }

  return gdesc_new;
}

/*Frees gdesc of a space*/
STATUS space_remove_gdesc(Space *space) {

  int i = 0;

  /*CONTROL ERROR*/
  if (!space || !space->gdesc)
  return ERROR;


  for (i = 0; i < GDESC_Y; i++) {
    if (space->gdesc[i] != NULL) {
      free(space->gdesc[i]);
      space->gdesc[i] = NULL;
    }
  }
  
  if (space->gdesc != NULL) {
    free(space->gdesc);
    space->gdesc = NULL;
  }

  return OK;
}

/*Returns number of objects a space has*/
int space_get_n_objects(Space *space) {
  /*CONTROL ERROR*/
  if (!space)
  return NO_ID;

  return set_get_n_ids(space->object);
}
