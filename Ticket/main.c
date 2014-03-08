/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 1 de Fevereiro de 2014, 19:14
 */

// Standard Libraries
#include <stdio.h>
#include <stdlib.h>

// TAD Libraries
#include "time.h"
#include "ticket.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char lp[9];
    int h, m;
    ticket t;
    
    printf(">License Plate: ");
    scanf(" %s",lp);
    printf(">Entry(format hh:mm): ");
    scanf(" %d:%d",&h,&m);
    t = createTicket(h,m,lp);
    if(t == NULL){
        printf(">Insufficient memory");
        exit(1);
    }
    printf(">Exit(format hh:mm): ");
    scanf(" %d:%d",&h,&m);
    giveExitTicket(t,h,m);
    printf(">Duration(hours): %d\n",returnDurHITicket(t));
    printf(">End of stay of car %s\n",returnPlateTicket(t));
    destroyTicket(t);
    return (EXIT_SUCCESS);
}

