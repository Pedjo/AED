/*
 *      Author : Carlos Pinto Machado
 *      Date: 22/01/2014
 *      
 */
// Standard Libraries
#include <stdlib.h>
#include <string.h>

// TAD Libraries
#include "time.h"
#include "ticket.h"

// CONSTANT DEFINES
#define SIZE_PLATE 9 // 6 characters + 2 characters for '-' + 1 for NULL

struct _ticket{
    time entry;
    time exit;
    char plate[SIZE_PLATE];
};

// Constructor and finalizer
ticket createTicket(int hi,int mi,char * lp){
    ticket t = (ticket)malloc(sizeof(struct _ticket));
    
    if(t == NULL)
        return NULL;
    t->entry = createTime(hi,mi,0);
    if(t->entry == NULL){
        free(t);
        return NULL;
    }
    t->exit = createTime(hi,mi,0);
    if(t->exit == NULL){
        destroyTime(t->entry);
        free(t);
        return NULL;
    }
    strcpy(t->plate,lp);
    
    return t;
    
}

void destroyTicket(ticket t){
    destroyTime(t->entry);
    destroyTime(t->exit);
    free(t);
}

// Passing Parameters
void giveEntryTicket(ticket t, int hi, int mi){
    giveHourTime(t->entry,hi);
    giveMinTime(t->entry,mi);
}

void giveExitTicket(ticket t,int he,int me){
    giveHourTime(t->exit,he);
    giveMinTime(t->exit,me);
}

void givePlateTicket(ticket t,char * plate){
    strcpy(t->plate,plate);
}

// Returning Parameters
time returnEntryTicket(ticket t){
    return t->entry;
}

time returnExitTicket(ticket t){
    return t->exit;
}

char * returnPlateTicket(ticket t){
    return t->plate;
}

// TAD Functions
time returnDurTicket(ticket t){
    return difTime(t->exit,t->entry);
}

int returnDurHITicket(ticket t){
    double n = difHourTime(t->exit,t->entry);
    
    if(n - (int)n > 0)
        return (int)n +1;
    return (int)n;
}