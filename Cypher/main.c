/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 22 de Janeiro de 2014, 16:35
 */

// Standard Libraries
#include <stdio.h>
#include <stdlib.h>

//TAD Libraries
#include "cypher.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int n;
    char name[20],a;
    FILE * f;
    cypher c;
    
    printf("Caesar's code: ");
    scanf(" %d",&n);
    c = createCypher(n);
    printf("Name of the file: ");
    scanf(" %s",name);
    f = fopen(name,"r");
    if(f == NULL)
        printf("File not found.");
    else{
        printf(">The Cyphertext\n");
        while((a=fgetc(f))!= EOF){
            a = encodeCypher(c,a);
            putchar(a);
        }
        fclose(f);
    }
    destroyCypher(c);
    return (EXIT_SUCCESS);
}

