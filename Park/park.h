/* 
 * File:   park.h
 * Author: Carlos
 *
 * Created on 22 de Janeiro de 2014, 18:35
 */

#ifndef PARK_H
#define	PARK_H

// TAD pointer definition
typedef struct _park * park;

// Constructors and finalizer

/*      
 * Name Function:       createPark
 * Description: Allocates memory and creates instance
 * Parameters:  n(int) - size of park
 * Pre-Requisites:      NONE
 * Returns:     (park) - Created Instance
 */
park createPark(int n);

/*      
 * Name Function:       destroyPark       
 * Description: Destroys a certain instance
 * Parameters:  p(park) - park to be destroyed
 * Pre-Requisites:      p != NULL
 * Returns:     VOID
 */
void destroyPark(park p);

/*      
 * Name Function:       destroyAtomicPark       
 * Description: Destroys a certain instance and all elements associated to it
 * Parameters:  p(park) - park to be destroyed
 * Pre-Requisites:      p != NULL
 * Returns:     VOID
 */
void atomicDestroyPark(park p);

// Passing Parameters

/*      
 * Name Function:       insertTicketPark       
 * Description: Inserts a ticket in a park
 * Parameters:  p(park) - the park
 *              t(ticket) - the ticket
 * Pre-Requisites:      p != NULL && t != NULL
 * Returns:     (int) - Success of operation : 1 :0
 */
int insertTicketPark(park p, ticket t);

/*      
 * Name Function:       resetBankPark      
 * Description: Empties the parks bank(puts it to 0)
 * Parameters:  p(park) - the park
 * Pre-Requisites:      p != NULL
 * Returns:     (double) - The value that was in bank
 */
double resetBankPark(park p);

// Returning Parameters

/*      
 * Name Function:       returnOccupancyPark      
 * Description: Function returns the number of cars in park
 * Parameters:  p(park) - the park
 * Pre-Requisites:      p != NULL
 * Returns:     (int) - number of cars in park
 */
int returnOccupancyPark(park p);

/*      
 * Name Function:       resetSizePark      
 * Description: Function returns the size of the park
 * Parameters:  p(park) - the park
 * Pre-Requisites:      p != NULL
 * Returns:     (int) - number of cars that are able to be in park
 */
int returnSizePark(park p);

/*      
 * Name Function:       returnBankPark      
 * Description: Function returns the value in bank
 * Parameters:  p(park) - the park
 * Pre-Requisites:      p != NULL
 * Returns:     (double) - The value that is in bank
 */
double returnBankPark(park p);

// TAD functions

/*      
 * Name Function:       returnTicketParkN
 * Description: Returns Car in place i
 * Parameters:  p(park) - the park
 *              i(int) - the index
 * Pre-Requisites:      p != NULL
 * Returns:     (ticket) - The car's ticket or NULL
 */
ticket returnTicketParkN(park p, int i);

/*      
 * Name Function:       returnTicketPark
 * Description: Returns Car with a certain license plate
 * Parameters:  p(park) - the park
 *              plate(char *) - the license plate
 * Pre-Requisites:      p != NULL && plate != NULL
 * Returns:     (ticket) - The car's ticket or NULL
 */
ticket returnTicketPark(park p, char * plate);

/*      
 * Name Function:       costTicketPark
 * Description: Returns the cost that a car would pay, give certain schedule
 * Parameters:  p(park) - the park
 *              t(ticket) - the ticket
 * Pre-Requisites:      p != NULL && t != NULL
 * Returns:     (double) - the cost
 */
double costTicketPark(park p, ticket t);

/*      
 * Name Function:       exitPark
 * Description: Makes a car exit, if this one is in the park
 * Parameters:  p(park) - the park
 *              plate(char *) - The car's license plate
 *              he(int) - Hour of exit
 *              me(int) - Minute of exit
 * Pre-Requisites:      p != NULL && plate != NULL
 * Returns:     (ticket) - The car's ticket or NULL
 */
ticket exitPark(park p,char * plate, int he, int me);

/*      
 * Name Function:       inPark
 * Description: Inquires if a certain car is in the park
 * Parameters:  p(park) - the park
 *              plate(char *) - the license plate
 * Pre-Requisites:      p != NULL && plate != NULL
 * Returns:     (int) - is in Park? 1:0
 */
int inPark(park p, char * plate);

#endif	/* PARK_H */

