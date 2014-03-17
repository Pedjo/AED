/* 
 * File:   md.c
 * Author: Carlos
 *
 * Created on 3 de Fevereiro de 2014, 15:30
 */

// Standard Libraries
#include <stdlib.h>

// TAD Libraries
#include "fila.h"
#include "patient.h"
#include "patientGen.h"
#include "md.h"

// CONSTANTS
#define BILL 60.

struct _MD{
    patient attendee;
    fila wait;
    double bank;
};

// Constructor and Finalizer
MD createMD(int cap){
    MD m = (MD)malloc(sizeof(struct _MD));
    
    if(m == NULL)
        return NULL;
    m->wait = criaFila(cap);
    if(m->wait == NULL){
        free(m);
        return NULL;
    }
    m->attendee = NULL;
    m->bank = 0;
    return m;
}

void destroyMD(MD m){
    destroiFila(m->wait);
    free(m);
}

void atomicDestroyMD(MD m){
    if(m->attendee != NULL)
        destroyPatient(m->attendee);
    destroiFilaEElems(m->wait,destroyPatientGen);
    free(m);
}

// Passing Parameters
void insertPatientMD(MD m,patient p){
    if(m->attendee == NULL)
        m->attendee = p;
    else
        adicionaElemFila(m->wait,p);
}

double resetBankMD(MD m){
    double aux = m->bank;
    m->bank = 0;
    return aux;
}



// Returning Parameters
patient nextPatientMD(MD m){
    patient p = m->attendee;
    if(m->attendee != NULL)
            m->bank+= BILL;
    if(tamanhoFila(m->wait))
        m->attendee = removeElemFila(m->wait);
    else
        m->attendee = NULL;
    return p;
}

int returnNumberPatientsMD(MD m){
    return tamanhoFila(m->wait);
}

double returnBankMD(MD m){
    return m->bank;
}

double returnBillMD(){
    return BILL;
}

// TAD FUNCTION
patient inOfficeMD(MD m){
    return m->attendee;
}