/* 
 * File:   cypher.h
 * Author: Carlos
 *
 * Created on 22 de Janeiro de 2014, 16:45
 */

#ifndef CYPHER_H
#define	CYPHER_H

// Pointer definition of TAD
typedef struct _cypher * cypher;

// TAD Constructor and finalizer

/*      
 * Name Function:       createCypher
 * Description: Allocates memory and creates instance
 * Parameters:  n(int) - Deviation associated to the Cypher
 * Pre-Requisites:      NONE
 * Returns:     Instance created(cypher)
 */
cypher createCypher(int n);

/*      
 * Name Function:       destroyCypher
 * Description: Destroys Instance passed as parameter 
 * Parameters:  c(cypher) - Instance to be destroyed
 * Pre-Requisites:      c != NULL
 * Returns:     VOID
 */
void destroyCypher(cypher c);

// Passing Parameters

/*      
 * Name Function:       giveCodeCypher 
 * Description: Changes the code of a certain cypher
 * Parameters:  c(cypher) - Instance to be changed
 *              n(int) - New Deviation code
 * Pre-Requisites:      c != NULL
 * Returns:     VOID
 */
void giveCodeCypher(cypher c, int n);

// Returning Parameters

/*      
 * Name Function:       returnCodeCypher
 * Description: Returns the code associated to a certain cypher
 * Parameters:  c(cypher) - Instance in cause
 * Pre-Requisites:      c != NULL
 * Returns:     (int) - The code in question
 */
int returnCodeCypher(cypher c);

//TAD functions

/*      
 * Name Function:       encodeCypher
 * Description: Function that recieves a character and returns it encoded
 * Parameters:  c(cypher) - Cypher in use to encode
 *              ch(char) - Character to be encoded
 * Pre-Requisites:      c != NULL
 * Returns:     (char) the encoded character
*/
char encodeCypher(cypher c,char ch);

/*      
 * Name Function:       decodeCypher 
 * Description: Function that decodes a certain character
 * Parameters:  c(cypher) - Cypher in question
 *              ch(char)  - Character to be decoded
 * Pre-Requisites:      c!= NULL
 * Returns:     (char) - The character decoded
 */
char decodeCypher(cypher c,char ch);

#endif	/* CYPHER_H */

