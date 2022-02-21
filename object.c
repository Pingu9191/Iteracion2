/**
* @brief An implementation to manage objects the
* objects in the ant_game
* @file object.c
* @author Nicolas Victorino && Ignacio Nunnez
* @version 1.0
* @date 07/02/2022
* @copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

/**
 * @brief Object
 *
 * This struct stores all the information of a object.
 */
struct _Object {
  Id id;                    /*!< Id number of the object, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the object */
};

/** object_create allocates memory for a new object
  *  and initializes its members
  */
Object* object_create(Id id) { 
  Object *newObject = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newObject = (Object *) malloc(sizeof (Object));
  if (newObject == NULL) {
    return NULL;
  }

  /* Initialization of an empty object*/
  newObject->id = id;
  newObject->name[0] = '\0';

  return newObject;
}

/** object_destroy frees the previous memory allocation 
  *  for a object
  */
STATUS object_destroy(Object* object) {
  
  /* Error control */
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;
  return OK;
}

/** It gets the id of a object
  */
Id object_get_id(Object* object) {
  
  /* Error control */
  if (!object) {
    return NO_ID;
  }
  return object->id;
}

/** It sets the name of a object
  */
STATUS object_set_name(Object* object, char* name) {
  
  /* Error control */
  if (!object || !name) {
    return ERROR;
  }

  /* Error control */
  if (!strcpy(object->name, name)) {
    return ERROR;
  }
  return OK;
}

const char * object_get_name(Object* object) {
  
  /* Error control */
  if (!object) {
    return NULL;
  }
  return object->name;
}

/** It prints the object information
  */
STATUS object_print(Object* object) {
  
  /* Error Control */
  if (!object) {
    return ERROR;
  }

  /*Print the id and the name of the object */
  
  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

  return OK;
}
