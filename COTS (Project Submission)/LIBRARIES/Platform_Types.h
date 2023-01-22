/*
 * platform_Types.h
 *
 *  Created on: October 26, 2022
 *      Author: Ahmed M. Rizk
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include <stdbool.h>

#ifndef _Bool
#define _Bool unsigned char
#endif

#ifndef NULL
#define NULL 0
#endif

// #define CPU_TYPE 						CPU_TYPE_32
// #define CPU_BIT_ORDER 					MSB_FIRST
// #define CPU_BYTE_ORDER					HIGH_BYTE_FIRST

#ifndef FALSE
#define FALSE 							(boolean)false
#endif

#ifndef TRUE
#define TRUE 							(boolean)true
#endif

typedef _Bool 							boolean;

typedef unsigned char 					uint8;     
typedef unsigned short 					uint16;
typedef unsigned int					uint32;
typedef unsigned long long				uint64;

typedef signed char 					sint8;
typedef signed short 					sint16;
typedef signed int						sint32;
typedef long long						sint64;

typedef float							float32;
typedef double							float64;
typedef long double						float128;


typedef volatile signed char			vint8;
typedef volatile signed short 			vint16;
typedef volatile signed int 			vint32;
typedef volatile signed long long		vint64;

typedef volatile unsigned char			vuint8;
typedef volatile unsigned short			vuint16;
typedef volatile unsigned int			vuint32;
typedef volatile unsigned long long		vuint64;

#endif /* PLATFORM_TYPES_H_ */

