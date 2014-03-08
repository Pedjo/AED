/* 
 * File:   ticket.h
 * Author: Carlos
 * Created on 22 January 2014, 11:19
 */

#ifndef TICKET_H
#define	TICKET_H

// TAD pointer definition
typedef struct _ticket * ticket;

// Constructor and finalizer

/*      
 * Name Function:       createTicket
 * Description: Allocates memory and creates instance
 * Parameters:  hi(int) - hour
 *              mi(int) - minute
 *              lp(char *) - license plate
 * Pre-Requisites:      NONE
 * Returns:     (ticket) - Created Instance
 */
ticket createTicket(int hi,int mi, char * lp);

/*      
 * Name Function:       destroyTicket       
 * Description: Destroys a certain instance
 * Parameters:  t(ticket) - ticket to be destroyed
 * Pre-Requisites:      t != NULL
 * Returns:     VOID
 */
void destroyTicket(ticket t);

// Passing Parameters

/*      
 * Name Function:       giveEntryTicket       
 * Description: Changes the entry time parameter of a certain ticket
 * Parameters:  t(ticket) - ticket to be changed
 *              hi(int) - hour of entry
 *              mi(int) - minute of entry
 * Pre-Requisites:      t != NULL
 * Returns:     VOID
 */
void giveEntryTicket(ticket t,int hi, int mi);

/*      
 * Name Function:       giveExitTicket       
 * Description: Changes the exit time parameter of a certain ticket
 * Parameters:  t(ticket) - ticket to be changed
 *              he(int) - hour of exit
 *              me(int) - minute of exit
 * Pre-Requisites:      t != NULL
 * Returns:     VOID
 */
void giveExitTicket(ticket t,int he,int me);

/*      
 * Name Function:       givePlateTicket       
 * Description: Changes the license plate of a certain ticket
 * Parameters:  t(ticket) - ticket to be changed
 *              plate(char *) - license plate
 * Pre-Requisites:      t != NULL
 * Returns:     VOID
 */
void givePlateTicket(ticket t,char * plate);

// Returning Parameters

/*      
 * Name Function:       returnEntryTicket       
 * Description: Return entry time of a certain ticket
 * Parameters:  t(ticket) - ticket in question
 * Pre-Requisites:      t != NULL
 * Returns:     (time) - the entry time
 */
time returnEntryTicket(ticket t);

/*      
 * Name Function:       returnExitTicket       
 * Description: Return exit time of a certain ticket
 * Parameters:  t(ticket) - ticket in question
 * Pre-Requisites:      t != NULL
 * Returns:     (time) - the exit time
 */
time returnExitTicket(ticket t);

/*      
 * Name Function:       returnPlateTicket       
 * Description: Return the license plate of a certain ticket
 * Parameters:  t(ticket) - ticket in question
 * Pre-Requisites:      t != NULL
 * Returns:     (char *) - the license plate
 */
char * returnPlateTicket(ticket t);

// TAD Functions

/*      
 * Name Function:       returnDurTicket       
 * Description: Return duration time of a certain ticket
 * Parameters:  t(ticket) - ticket in question
 * Pre-Requisites:      t != NULL
 * Returns:     (time) - the duration time
 */
time returnDurTicket(ticket t);

/*      
 * Name Function:       returnDurHITicket       
 * Description: Return duration(in hours(integer)) of a certain ticket
 * Parameters:  t(ticket) - ticket in question
 * Pre-Requisites:      t != NULL
 * Returns:     (int) - the duration time in hours
 */
int returnDurHITicket(ticket t);

#endif	/* TICKET_H */

