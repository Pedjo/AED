/* 
 * File:   cypher.c
 * Author: Carlos
 *
 * Created on 22 de Janeiro de 2014, 16:44
 */

// Standard Libraries
#include <stdlib.h>

// TAD Libraries
#include "cypher.h"

// TAD Structure
struct _cypher{
    int d;      // Character Deviation
};

// TAD Constructor and finalizer
cypher createCypher(int n){
    cypher c = (cypher)malloc(sizeof(struct _cypher));
    
    if(c == NULL)
        return NULL;
    c->d = n;
    return c;
}

void destroyCypher(cypher c){
    free(c);
}

// Passing Parameters
void giveCodeCypher(cypher c, int n){
    c->d = n;
}

// Returning Parameters
int returnCodeCypher(cypher c){
    return c->d;
}

//TAD functions
char encodeCypher(cypher c,char ch){
    char a;
    
    if(ch < 'a' || ch > 'z')
        return ch;
    a = ch+c->d;
    if(a > 'z')
        return a - 'z' + 'a';
    else
        if(a < 'a')
            return a + 'z' - 'a';
    return a;
}

char decodeCypher(cypher c,char ch){
    char a;
    
    if(ch < 'a' || ch > 'z')
        return ch;
    a = ch - c->d;
    if(a < 'a')
        return a - 'a'+ 'z';
    else
        if(a > 'z')
            return a - 'z' + 'a';
    return a;
}

