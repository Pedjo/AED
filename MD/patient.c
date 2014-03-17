/* 
 * File:   patient.c
 * Author: Carlos
 *
 * Created on 3 de Fevereiro de 2014, 15:29
 */
// Standard Libraries
#include <stdlib.h>
#include <string.h>

// TAD Libraries
#include "patient.h"

// TAD CONSTANTS
#define TAM 50

struct _patient{
    char name[TAM];
};

// Constructor and Finalizer
patient createPatient(char * name){
    patient p = (patient)malloc(sizeof(struct _patient));
    
    if(p == NULL)
        return NULL;
    strcpy(p->name,name);
    return p;
}

void destroyPatient(patient p){
    free(p);
}

// Passing Parameters
void giveNamePatient(patient p, char * name){
    strcpy(p->name,name);
}

// Returning parameters
char * returnNamePatient(patient p){
    return p->name;
}
