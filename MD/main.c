/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 3 de Fevereiro de 2014, 0:20
 */

// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// TAD Libraries
#include "patient.h"
#include "md.h"

// PROGRAM CONSTANTS
#define CAP 30
#define BILL 60.

/*
 * 
 */

void exit_MD(MD m);

void number_MD(MD m);

void in_MD(MD m);

int entry_MD(MD m, char * reader);

int main(int argc, char** argv) {
    MD m = createMD(CAP);
    char reader[90];
    char ch;
    
    do{
        printf(">");
        fgets(reader,90,stdin);
        ch = toupper(reader[0]);
        switch(ch){
            case 'S':   exit_MD(m); break;
            case 'N':   number_MD(m); break;
            case 'A':   in_MD(m);
            case 'X':   break;
            case 'C':   if(entry_MD(m,reader) == 1)
                                break;
            default:    printf(">Invalid Command\n");
        }
    }while(ch !='X');
    atomicDestroyMD(m);
    return (EXIT_SUCCESS);
}

void exit_MD(MD m){
    patient p = nextPatientMD(m);
    
    if(p == NULL)
        puts(">No patients");
    else{
        printf("%s should pay %.0lf\n",returnNamePatient(p),returnBillMD());
        destroyPatient(p);
        p = inOfficeMD(m);
        if(p == NULL)
            puts("No more patients waiting");
        else
                printf("Calling %s\n",returnNamePatient(p));
    }
}

void number_MD(MD m){
    printf(">There are %d patients waiting\n",returnNumberPatientsMD(m));
}

void in_MD(MD m){
    patient p = inOfficeMD(m);
    
    if(p == NULL)
        puts(">No patient being taken care of");
    else
        printf(">%s being attended\n",returnNamePatient(p));
}

int entry_MD(MD m, char * reader){
    char name[50];
    patient p;
    
    if(sscanf(reader,"%*s %[^\n]",name) != 1)
        return 0;
    p = createPatient(name);
    if(p == NULL)
        return 0;
    insertPatientMD(m,p);
    return 1;
}