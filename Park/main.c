/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 22 de Janeiro de 2014, 18:34
 */
// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// TAD Libraries
#include "time.h"
#include "ticket.h"
#include "park.h"

// CONSTANTS
#define SIZE_PARK 150

// Interfaces of the Program
void entryInter(park p,char * reader);

void exitInter(park p,char * reader);

void listInter(park p);

void bankInter(park p);

void presenceInter(park p,char * reader);


/*
 * 
 */

int main(int argc, char** argv) {
    char reader[90];
    park p = createPark(SIZE_PARK);
    
    do{
        printf(">Insert command(e,s,l,c,m,x):\n>");
        fgets(reader,90,stdin);
        switch(toupper(reader[0])){
            case 'E':   entryInter(p,reader);break;
            case 'S':   exitInter(p,reader);break;
            case 'L':   listInter(p);break;
            case 'C':   bankInter(p);break;
            case 'M':   presenceInter(p,reader);
            case 'X':break;
            default:printf(">Invalid input\n");
        }
    }while(reader[0]!= 'x');
    printf(">%.2lf Euros in bank\n",returnBankPark(p));
    printf("%d cars in the Park\n",returnOccupancyPark(p));
    printf(">END OF PROGRAM\n");
    return (EXIT_SUCCESS);
}

void entryInter(park p,char * reader){
    int h,m;
    char plate[9];
    ticket t;
    
    if(sscanf(reader,"%*c %d:%d %s",&h,&m,plate)!= 3){
        printf(">Invalid input\n");
        return;
    }
    t = createTicket(h,m,plate);
    if(t == NULL){
        printf(">System failure\n");
        return;
    }
    if(insertTicketPark(p,t)==0)
        printf(">Park is full\n");
    else
        printf(">Authorised Entry\n");
}

void exitInter(park p,char * reader){
    int h,m;
    char plate[9];
    ticket t;
    
    if(sscanf(reader,"%*c %d:%d %s",&h,&m,plate)!= 3){
        printf(">Invalid input\n");
        return;
    }
    t = exitPark(p,plate,h,m);
    if(t == NULL){
        printf(">Car not in Park\n");
        return;
    }
    printf(">Duration %d hours\n",returnDurHITicket(t));
    printf(">Payment: %.2lf Euros\n",costTicketPark(p,t));
    destroyTicket(t);
}

void listInter(park p){
    int i;
    int n = returnOccupancyPark(p);
    
    for(i=0;i<n;i++)
        printf(">%s\n",returnPlateTicket(returnTicketParkN(p,i)));
}

void bankInter(park p){
    printf(">%.2lf Euros in bank\n",returnBankPark(p));
}

void presenceInter(park p,char * reader){
    char plate[9],ch;
    
    if(sscanf(reader,"%*c %s",plate)!= 1){
        printf(">Invalid input\n");
        return;
    }
    
    if(inPark(p,plate))
        printf(">Car is in Park\n");
    else
        printf(">Car not in Park\n");
    
}