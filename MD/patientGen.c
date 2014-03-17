/* 
 * File:   patientGen.c
 * Author: Carlos
 *
 * Created on 3 de Fevereiro de 2014, 16:23
 */

// Standard Libraries
#include <stdlib.h>

// TAD Libraries
#include "patient.h"
#include "patientGen.h"

/*
 * 
 */
void destroyPatientGen(void * p){
    destroyPatient((patient)p);
}

