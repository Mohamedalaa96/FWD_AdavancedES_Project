/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 30 Auguest 2020                                                                    */
/* Version      : V01                                                                                */
/*****************************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;

typedef volatile uint32 *IO_REG_PTR;

typedef uint8 Std_ReturnType;

#define NULL_PTR ((void *)0) 

#define E_OK ((Std_ReturnType)0)
#define E_NOT_OK ((Std_ReturnType)1)
#define E_WRONG_CONFIG ((Std_ReturnType)2)

#endif

/* TODO: change this file to std .h file structure */

