/* 
 * File:   time.h
 * Author: Carlos
 *
 * Created on 22 January 2014, 11:28
 */

#ifndef TIME_H
#define	TIME_H

// Definition of pointer for our TAD
typedef struct _time * time;

// TAD constructor and finalizer

/*      
 * Name Function:       createTime
 * Description: Allocates memory and creates instance
 * Parameters:  h(int) - hour
 *              m(int) - minute
 *              s(int) - second
 * Pre-Requisites:      NONE
 * Returns:     (time) - Created Instance
 */
time createTime(int h,int m, int s);

/*      
 * Name Function:       destroyTime       
 * Description: Destroys a certain instance
 * Parameters:  t(time) - time to be destroyed
 * Pre-Requisites:      t != NULL
 * Returns:     VOID
 */
void destroyTime(time t);

// Passing parameters

/*      
 * Name Function:       giveHourTime       
 * Description: Changes the hour of a certain time
 * Parameters:  t(time) - Instance that is going to suffer changes
 *              h(int) - New Hour
 * Pre-Requisites:      t != NULL
 * Returns:     VOID
 */
void giveHourTime(time t, int h);

/*      
 * Name Function:       giveMinTime       
 * Description: Changes the minute of a certain time
 * Parameters:  t(time) - Instance that is going to suffer changes
 *              m(int) - New minute
 * Pre-Requisites:      t != NULL
 * Returns:     VOID
 */
void giveMinTime(time t, int m);

/*      
 * Name Function:       giveSecTime       
 * Description: Changes the second of a certain time
 * Parameters:  t(time) - Instance that is going to suffer changes
 *              s(int) - New second
 * Pre-Requisites:      t != NULL
 * Returns:     VOID
 */
void giveSecTime(time t, int s);

// Returning parameters

/*      
 * Name Function:  returnHourTime     
 * Description: Returns the parameter hour of a certain time
 * Parameters:  t(time) - The time in question
 * Pre-Requisites:      t != NULL
 * Returns:     (int) - The hour of a certain time
 */
int returnHourTime(time t);

/*      
 * Name Function:  returnMinTime     
 * Description: Returns the parameter minute of a certain time
 * Parameters:  t(time) - The time in question
 * Pre-Requisites:      t != NULL
 * Returns:     (int) - The minute of a certain time
 */
int returnMinTime(time t);

/*      
 * Name Function:  returnSecTime     
 * Description: Returns the parameter second of a certain time
 * Parameters:  t(time) - The time in question
 * Pre-Requisites:      t != NULL
 * Returns:     (int) - The second of a certain time
 */
int returnSecTime(time t);

// TAD functions

/*      
 * Name Function:  difHourTime     
 * Description: Returns the difference between two times in hours(double)
 * Parameters:  t(time) - The reference time
 *              u(time) - The other time
 * Pre-Requisites:      t != NULL && u != NULL
 * Returns:     (double) - The time(t - u) in hours
 */
double difHourTime(time t, time u);

/*      
 * Name Function:  difTime     
 * Description: Returns an instance that is the difference between two times
 * Parameters:  t(time) - The reference time
 *              u(time) - The other time
 * Pre-Requisites:      t != NULL && u != NULL
 * Returns:     (time) - The time(t - u)
 */
time difTime(time t, time u);

/*      
 * Name Function:  beforeTime     
 * Description: Checks if time t is prior to time u
 * Parameters:  t(time) - The reference time
 *              u(time) - The other time
 * Pre-Requisites:      t != NULL && u != NULL
 * Returns:     (int) - t < u ? 1 : 0
 */
int beforeTime(time t, time u);

/*      
 * Name Function:  afterTime     
 * Description: Checks if time t is posterior to time u
 * Parameters:  t(time) - The reference time
 *              u(time) - The other time
 * Pre-Requisites:      t != NULL && u != NULL
 * Returns:     (int) - t > u ? 1 : 0
 */
int afterTime(time t, time u);

/*      
 * Name Function:  equalTime     
 * Description: Checks if time t is equal to time u
 * Parameters:  t(time) - The reference time
 *              u(time) - The other time
 * Pre-Requisites:      t != NULL && u != NULL
 * Returns:     (int) - t == u ? 1 : 0
 */
int equalTime(time t, time u);

/*      
 * Name Function:  copyTime     
 * Description: Copies time u into time t
 * Parameters:  t(time) - The reciever
 *              u(time) - The other time
 * Pre-Requisites:      t != NULL && u != NULL
 * Returns:     VOID
 */
void copyTime(time t, time u);


#endif	/* TIME_H */

