/** 
 * @brief It defines the set interface
 * 
 * @file set.h
 * @author Nicolas Victorino && Ignacio Nunnez
 * @version 1.0
 * @date 21-02-2022
 * @copyright GNU Public License
 */

#ifndef SET_H
#define SET_H

#include "types.h"

/**
* Defines the maximum number of ids that can be saved in a set
*/
#define MAX_IDS 20 //Temporal, no se cuanto tiene que ser el tope

typedef struct _Set Set;

/**
  * @brief Creates a new set to save ids
  * @author Nicolas Victorino
  *
  * @return a pointer to the newly created set, and in case of an error NULL.
  */
Set* set_create ();

/**
  * @brief Destroys a given set of ids
  * @author Nicolas Victorino
  *
  * @param set a pointer to the set we want to destroy
  * @return OK if everything went right, ERROR in case something went wrong
  */
STATUS set_destroy (Set *set);

/**
  * @brief Adds an id to a given set
  * @author Nicolas Victorino
  *
  * @param set a pointer to the given set, @param id id that we want to add to the set
  * @return OK if everything went right, ERROR in case something went wrong
  */
STATUS set_add_id (Set *set, Id id);

/**
  * @brief Deletes a given id of a set
  * @author Nicolas Victorino
  *
  * @param set a pointer to the given set, @param id id that we want to delete from the set
  * @return OK if everything went right, ERROR in case something went wrong
  */
STATUS set_del_id (Set *set, Id id);

/**
  * @brief Prints all the ids saved in a set (for debbuging purpouses)
  * @author Nicolas Victorino
  *
  * @param set a pointer to the given set
  * @return OK if everything went right, ERROR in case something went wrong
  */
STATUS set_print (Set *set);

//Funcion para ver si una id dada se encuentra en el set (añadida temporalmente, creo que puede ser útil)
BOOL set_idInSet (Set* set, Id id);

#endif
