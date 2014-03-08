/* 
 * File:   park.c
 * Author: Carlos
 *
 * Created on 22 de Janeiro de 2014, 18:35
 */

// Standard Libraries
#include <stdlib.h>
#include <string.h>

// TAD Libraries
#include "time.h"
#include "ticket.h"
#include "park.h"

// Park Constants
#define FIRST 1.5
#define SECOND 1
#define THIRD 0.75
#define FOURTH 0.6

// TAD Structure
struct _park{
    int occu, sizePark;
    double bank;
    ticket * place;
};

// Constructors and finalizer
park createPark(int n){
    park p = (park)malloc(sizeof(struct _park));
    
    if(p == NULL)
        free(p);
    p->place = (ticket *)malloc(sizeof(ticket *)*n);
    if(p->place == NULL){
        free(p);
        return NULL;
    }
    p->bank=0;
    p->occu=0;
    p->sizePark = n;
    return p;
}

void destroyPark(park p){
    free(p->place);
    free(p);
}

void atomicDestroyPark(park p){
    int i;
    
    for(i=0;i<p->occu;i++)
        destroyTicket(p->place[i]);
    destroyPark(p);
}

// Passing Parameters
int insertTicketPark(park p, ticket t){
    if(p->occu >= p->sizePark)
        return 0;
    p->place[p->occu] = t;
    p->occu++;
    return 1;
}

double resetBankPark(park p){
    double aux = p->bank;
    p->bank = 0;
    return aux;
}

// Returning Parameters
int returnOccupancyPark(park p){
    return p->occu;
}

int returnSizePark(park p){
    return p->sizePark;
}

double returnBankPark(park p){
    return p->bank;
}

// TAD functions
ticket returnTicketParkN(park p, int i){
    return p->place[i];
}

ticket returnTicketPark(park p, char * plate){
    int i;
    
    for(i=0;i<p->occu;i++)
        if(strcmp(plate,returnPlateTicket(p->place[i]))==0)
            return p->place[i];
    return NULL;
}

double costTicketPark(park p, ticket t){
    int h = returnDurHITicket(t);
    
    switch(h){
        case 1: return FIRST*h;break;
        case 2: 
        case 3: return FIRST+SECOND*(h-1);break;
        case 4: 
        case 5: return FIRST+SECOND*2+(h-3)*THIRD; break;
        case 6:
        default:return FIRST+2*(SECOND+THIRD)+(h-5)*FOURTH;
    }
}

ticket exitPark(park p,char * plate, int he, int me){
    ticket t = returnTicketPark(p,plate);
    int i;
    
    if(t == NULL)
        return NULL;
    giveExitTicket(t,he,me);
    for(i = 0;i<p->occu;i++)
        if(strcmp(plate,returnPlateTicket(p->place[i]))==0)
            break;
    p->occu--;
    p->place[i] = p->place[p->occu];
    p->bank+= costTicketPark(p,t);
    return t;
}

int inPark(park p, char * plate){
    return returnTicketPark(p,plate) != NULL;
}

