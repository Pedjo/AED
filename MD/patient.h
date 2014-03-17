/* 
 * File:   patient.h
 * Author: Carlos
 *
 * Created on 3 de Fevereiro de 2014, 15:30
 */

#ifndef PATIENT_H
#define	PATIENT_H

// TAD pointer definition
typedef struct _patient * patient;

// Constructor and Finalizer

/*      
 * Name Function:       createPatient
 * Description: Allocates memory and creates instance
 * Parameters:  name(char *) - the patient's name
 * Pre-Requisites:      NONE
 * Returns:     (patient) - Created Instance
 */
patient createPatient(char * name);

/*      
 * Name Function:       destroyPatient
 * Description: Destroys instance, by freeing its memory
 * Parameters:  p(patient) - the patient
 * Pre-Requisites:      p!=NULL
 * Returns:     VOID
 */
void destroyPatient(patient p);

// Passing Parameters

/*      
 * Name Function:       giveNamePatient
 * Description: Changes the name of a certain patient
 * Parameters:  p(patient) - the patient
 *              name(char*) - the new name
 * Pre-Requisites:      p!=NULL
 * Returns:     VOID
 */
void giveNamePatient(patient p,char * name);

// Returning Parameters

/*      
 * Name Function:       returnNamePatient
 * Description: Function returns the name of a certain patient
 * Parameters:  p(patient) - the patient
 * Pre-Requisites:      p!=NULL
 * Returns:     (char*) - the name
 */
char * returnNamePatient(patient p);

#endif	/* PATIENT_H */

