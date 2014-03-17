/* 
 * File:   md.h
 * Author: Carlos
 *
 * Created on 3 de Fevereiro de 2014, 15:30
 */

#ifndef MD_H
#define	MD_H

// TAD pointer definition
typedef struct _MD * MD;

// Constructor and Finalizer

/*      
 * Name Function:       createMD
 * Description: Allocates memory and creates instance
 * Parameters:  cap(int) - Capacity of Medical Department
 * Pre-Requisites:      cap >=0
 * Returns:     (MD) - Created Instance
 */
MD createMD(int cap);

/*      
 * Name Function:       destroyMD
 * Description: Destroys instance
 * Parameters:  m(MD) - Medical Department
 * Pre-Requisites:      m!= NULL
 * Returns:     VOID
 */
void destroyMD(MD m);

/*      
 * Name Function:       atomicDestroyMD
 * Description: Destroys instance and elements of collection
 * Parameters:  m(MD) - Medical Department
 * Pre-Requisites:      m!= NULL
 * Returns:     VOID
 */
void atomicDestroyMD(MD m);

// Passing Parameters

/*      
 * Name Function:       insertPatientMD
 * Description: Inserts Patient in queue
 * Parameters:  m(MD) - Medical Department
 *              p(patient) - patient in question
 * Pre-Requisites:      m!= NULL && p!= NULL
 * Returns:     VOID
 */
void insertPatientMD(MD m,patient p);

/*      
 * Name Function:       resetBankMD
 * Description: Inserts 0 in MD's account
 * Parameters:  m(MD) - Medical Department
 * Pre-Requisites:      m!= NULL && p!= NULL
 * Returns:     (double) - Bank before reset
 */
double resetBankMD(MD m);

// Returning Parameters
/*      
 * Name Function:       nextPatientMD
 * Description: Returns patient being attended 
 *                      and puts the first in queue 
 *                      to be attended
 * Parameters:  m(MD) - Medical Department
 * Pre-Requisites:    m != NULL
 * Returns:     (patient) - patient that was being attended
 */
patient nextPatientMD(MD m);

/*      
 * Name Function:       returnNumberPatientsMD
 * Description: Returns number of patients in queue
 * Parameters:  m(MD) - Medical Department
 * Pre-Requisites:    m!= NULL
 * Returns:     (int) - patients in queue
 */
int returnNumberPatientsMD(MD m);

/*      
 * Name Function:       returnBankMD
 * Description: Returns the bank of a MD
 * Parameters:  m(MD) - Medical Department
 * Pre-Requisites:    m!=NULL
 * Returns:     (double) - Bank
 */
double returnBankMD(MD m);

/*      
 * Name Function:       returnBillMD
 * Description: Returns the BILL value of a certain implementation of MD
 * Parameters:  NONE
 * Pre-Requisites:    NONE
 * Returns:     (double) - BILL
 */
double returnBillMD();

//TAD Functions
/*      
 * Name Function:       inOfficeMD
 * Description: Returns patient being attended 
 * Parameters:  m(MD) - Medical Department
 * Pre-Requisites:    m != NULL
 * Returns:     (patient) - patient being attended
 */
patient inOfficeMD(MD m);

#endif	/* MD_H */

