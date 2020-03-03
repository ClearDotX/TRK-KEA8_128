/*
 * typedefs.h
 *
 *  Created on: 01/08/2012
 *      Author: B34981
 */

#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

  typedef unsigned char   UINT8;      /* unsigned 8 bit definition */
  typedef unsigned short  UINT16;     /* unsigned 16 bit definition */
  typedef unsigned long   UINT32;     /* unsigned 32 bit definition */
  typedef signed char     INT8;       /* signed 8 bit definition */
  typedef short           INT16;      /* signed 16 bit definition */
  typedef long int        INT32;      /* signed 32 bit definition */  
  typedef void(*pt2Func)(void);		  /* Pointer to Functions, void argument */
  typedef void(*pt2FuncU8)(UINT8);	  /* Pointer to Functions, UINT8 argument */
  
#endif /* TYPEDEFS_H_ */
