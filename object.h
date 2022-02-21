/**
* @brief An implementation to manage objects the
* objects in the ant_game
* @file object.c
* @author Nicolas Victorino && Ignacio Nunnez
* @version 1.0
* @date 07/02/2022
* @copyright GNU Public License
*/

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

#define MAX_OBJECTS 100
#define FIRST_OBJECT 1

/**
  * @brief It creates a new object
  * @author Nicolas Victorino
  *
  * object_create allocates memory for a new object
  *  and initializes its members
  * @param id the identification number for the new object
  * @return a new object, initialized
  */
Object* object_create(Id id);

/**
  * @brief It destroys a object
  * @author Nicolas Victorino
  *
  * object_destroy frees the previous memory allocation 
  *  for a object
  * @param object a pointer to the object that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_destroy(Object* object);

/**
  * @brief It gets the id of a object
  * @author Nicolas Victorino
  * 
  * @param object a pointer to the object  
  * @return the id of object
  */
Id object_get_id(Object* object);

/**
  * @brief It sets the name of a object
  * @author Nicolas Victorino
  * 
  * @param space a pointer to the object
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_name(Object* space, char* name);

/**
  * @brief It prints the object information
  * @author Nicolas Victorino
  *
  * This fucntion shows the id and name of the object.
  * @param object a pointer to the object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_print(Object* object);

#endif
