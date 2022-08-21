/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 30 Auguest 2020                                                                    */
/* Version      : V01                                                                                */
/*****************************************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR, BIT) VAR |= (1 << BIT)
#define CLR_BIT(VAR, BIT) VAR &= ~(1 << BIT)
#define GET_BIT(VAR, BIT) ((VAR >> BIT) & 1)
#define TOG_BIT(VAR, BIT) VAR ^= (1 << BIT)

#define BIT_BANDING(BIT_ALIAS_BASE, OFFSET, BIT_NUM) (BIT_ALIAS_BASE + ((OFFSET x 32) + (BIT_NUM x 4)))

#endif
