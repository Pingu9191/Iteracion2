
/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#define GDESC_X 9
#define GDESC_Y 5

#include "types.h"
#include "set.h"

typedef struct _Space Space;

 /**
 * Constant used in space.c. 
 * MAX_SPACES defines the maximum spaces available and FIRST_SPACE defines the Id of the first space 
 */
#define MAX_SPACES 100
#define FIRST_SPACE 1

/**
  * @brief It creates a new space
  * @author Profesores PPROG
  *
  * space_create allocates memory for a new space
  *  and initializes its members
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
Space* space_create(Id id);

/**
  * @brief It destroys a space
  * @author Profesores PPROG
  *
  * space_destroy frees the previous memory allocation 
  *  for a space
  * @param space a pointer to the space that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_destroy(Space* space);

/**
  * @brief It sets the gdesc of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param gdesc a matrix with the gdesc structure to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_gdesc(Space* space, char **gdesc);

/**
  * @brief It gets the gdesc of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @return  a matrix with the gdesc structure of the space
  */
const char** space_get_gdesc(Space* space);

/**
  * @brief It gets the id of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space  
  * @return the id of space
  */
Id space_get_id(Space* space);

/**
  * @brief It sets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_name(Space* space, char* name);

/**
  * @brief It gets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @return  a string with the name of the space
  */
const char* space_get_name(Space* space);

/**
  * @brief It sets the id of the space located at the north
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param id the id number of the space located at the north
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_north(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the north
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the north 
  */
Id space_get_north(Space* space);

/**
  * @brief It sets the id of the space located at the south
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the space located at the south
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_south(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the south
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the south 
  */
Id space_get_south(Space* space);

/**
  * @brief It sets the id of the space located at the east
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the space located at the east
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_east(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the east
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the east
  */
Id space_get_east(Space* space);

/**
  * @brief It sets the id of the space located at the west
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the space located at the west
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_west(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the west
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the west
  */
Id space_get_west(Space* space);

/**
  * @brief It adds the id of an object in a given space
  * @author Nicolas Victorino
  *
  * This function sets the id of an object in a given space
  * @param space a pointer to the space, @param id id of the object we want to save in the space
  * @return OK, if everything goes well or ERROR if something went wrong during the execution
  */
STATUS space_add_object (Space *space, Id id);

/**
  * @brief It gets the id of an object in a given space
  * @author Nicolas Victorino
  *
  * @param space a pointer to the space
  * @return In case the space given or the id of the object in the space is NULL, it returns NO_ID. If not it returns the id of the object in the space
  */
Set *space_get_object (Space *space); // Deberia devolver set???


/**
  * @brief It deletes the id of an object to a given space
  * @author Ignacio Nunnez
  *
  * This function sets the id of an object in a given space
  * @param space a pointer to the space, @param id id of the object we want to delete from the space
  * @return OK, if everything goes well or ERROR if something went wrong during the execution
  */
STATUS space_delete_object (Space *space, Id id);

/**
  * @brief It sets a new set of objects to the given space
  * @author Nicolas Victorino
  *
  * @param space a pointer to the space @param set a pointer to the new set
  * @return In case the space given or the id of the object in the space is NULL, it returns ERROR. If not it returns OK
  */
STATUS space_set_object(Space* space, Set*set);
/**
  * @brief It prints the space information
  * @author Profesores PPROG
  *
  * This fucntion shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
  * @param space a pointer to the space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_print(Space* space);

int space_get_gdescX();

int space_get_gdescY();

/**
  * @brief It allocates memory for a new gdesc
  * @author Nicolas Victorino
  *
  * 
  * @param space a pointer to the space
  * @return char**, if it creates the gdesc succesfully, NULL if something went wrong
  */
char ** space_create_gdesc ();

/**
  * @brief It frees the memory allocated for the gdesc
  * @author Nicolas Victorino
  *
  * 
  * @param space a pointer to the space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
 STATUS space_remove_gdesc(Space *space);

/**
  * @brief It returns the number of objects of an space
  * @author Nicolas Victorino
  *
  * 
  * @param space a pointer to the space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
int space_get_n_objects(Space *space);
#endif
