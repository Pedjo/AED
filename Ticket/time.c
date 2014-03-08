/* 
 * File:   time.c
 * Author: Carlos
 *
 * Created on 22 January 2014, 11:25
 */

//      Standard Libraries
#include <stdlib.h>

//      TAD Libraries
#include "time.h"

// TAD structure
struct _time{
    int h;
    int m;
    int s;
};

// TAD constructor and finalizer
time createTime(int h,int m, int s){
    time t = (time)malloc(sizeof(struct _time));
    
    if(t == NULL)
        return NULL;
    t->h = h;
    t->m = m;
    t->s = s;
    return t;
}

void destroyTime(time t){
    free(t);
}

// Passing parameters
void giveHourTime(time t, int h){
    t->h = h;
}

void giveMinTime(time t, int m){
    t->m = m;
}

void giveSecTime(time t, int s){
    t->s = s;
}

// Returning parameters
int returnHourTime(time t){
    return t->h;
}

int returnMinTime(time t){
    return t->m;
}

int returnSecTime(time t){
    return t->s;
}

// TAD functions
double difHourTime(time t, time u){
    double ht, hu;
    
    ht = t->h+(t->m+t->s/60.)/60.;
    hu = u->h+(u->m+u->s/60.)/60.;
    
    return ht - hu;
}

time difTime(time t, time u){
    time d = createTime(t->h-u->h,t->m-u->m,t->s-u->s);
    if(d == NULL)
        return NULL;
    return d;
}

int beforeTime(time t, time u){
    if(t->h == u->h){
        if(t->m == u->m){
            if(t->s < u->s)
                return 1;
        }
        else
            if(t->m < u->m)
                return 1;
    }
    else
        if(t->h < u->h)
                return 1;
    return 0;
}

int afterTime(time t, time u){
    if(t->h == u->h){
        if(t->m == u->m){
            if(t->s > u->s)
                return 1;
        }
        else
            if(t->m > u->m)
                return 1;
    }
    else
        if(t->h > u->h)
                return 1;
    return 0;
}

int equalTime(time t, time u){
    if(t->h == u->h)
        if(t->m == u->m)
            if(t->s == u->s)
                return 1;
    return 0;
}

void copyTime(time t, time u){
    t->h = u->h;
    t->m = u->m;
    t->s = u->s;
}
