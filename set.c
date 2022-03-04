/** 
 * @brief It implements the set module
 * 
 * @file set.c
 * @author Nicolas Victorino 
 * @version 1.0
 * @date 21-02-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "set.h"

struct _Set {
    int n_ids;
    Id *ids;
};

/*
* Creates a new set to save ids
*/
Set *set_create() 
{

    /*Creates a pointer to a set and allocates memory for it, returning NULL in case of error*/
    Set *newSet = NULL;

    newSet = (Set *) malloc(sizeof (Set));
    if (newSet == NULL) {
        return NULL;
    }

    /* Initialization of an empty set*/
    newSet->n_ids = NO_ID + 1;
    newSet->ids = NULL;

  return newSet;
}

/*
* Destroys a given set
*/
STATUS set_destroy (Set *set) 
{
    /*Error control*/
    if (!set) {
        return ERROR;
    }

    free(set);
    set = NULL;

    return OK;
}

/*
* Adds an id to a given set, reallocating memory for it and locating the first empty space
*/
STATUS set_add_id (Set *set, Id id)
{

    /*Error control*/
    if ((!set) || (!id) || (id==NO_ID) ) {
        return ERROR;
    }

    set->n_ids++;

    /*Reserves memory for one more*/
    if (!(set->ids = (Id *)realloc(set->ids, set->n_ids * sizeof(Id)))) {
        return ERROR;
    }

    set->ids[set->n_ids - 1] = id;

    return OK;
}

/*
* Deletes a given id of a set
*/
STATUS set_del_id (Set *set, Id id)
{
    int i = 0;

    /*Error control*/
    if ((!set) || (!id)) {
        return ERROR;
    }

    /*Checks the position where the id coincides*/
    while (i < set->n_ids) {
        if(set->ids[i]==id){
            break;
        }
        i++;
    }

    /*If it has not located the position, it reaches n_ids and returns ERROR*/
    if ( i == set->n_ids) {
        return ERROR;
    }

    /*Re-sort all ids*/
    for(;i<set->n_ids-1;i++){
        set->ids[i] = set->ids[i+1];
    }

    set->n_ids--;

    return OK;
}

/*
* Prints all the ids saved in a set (for debbuging purpouses)
*/
STATUS set_print(Set *set)
{
    int i = 0;

    /*Error control*/
    if (!set) {
        return ERROR;
    }

    /*Prints the number of ids saved the set*/
    fprintf(stdout, "-Number of ids saved: %d\n", set->n_ids);

    /*Prints all the ids saved*/
    for (i= 0; i < set->n_ids; i++) {
        fprintf(stdout, "Id %d: %ld \n", i+1, set->ids[i]);
    }

    return OK;
}

//Funcion para ver si una id dada se encuentra en el set (añadida temporalmente, creo que puede ser útil)
BOOL set_idInSet (Set* set, Id id)
{
    int i = 0; 

    /*Error control*/
    if ((!set) || (!id)) {
        return FALSE;
    }


    /*Checks the position where the id coincides*/
    while (i < set->n_ids) {
        if(set->ids[i]==id){
            break;
        }
        i++;
    }

    /*If it has not located the position, it reaches MAX_IDS and returns ERROR*/
    if ( i == set->n_ids) {
        return FALSE;
    } else {
        return TRUE;
    }
}

/*Whether the set is empty or not*/
BOOL set_is_empty(Set *set)
{
    /*Error control (if the 
    set is NULL, is also empty*/
    if (!set) {
        return TRUE;
    }

    /*Comprueba que esta vacio*/
    if (set->n_ids == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*returns number of ids*/
int set_get_n_ids(Set* set) {

    /*CONTROL ERROR*/
    if (!set) {
        return NO_ID;
    }

    return set->n_ids;
}
