
/*
 *      Author: hana
 */

// prevent multiple inclusions of the same header file

#ifndef STD_MACROS
#define STD_MACROS

///////////////////////////////////////////////////////////////
				   //type declarations//
///////////////////////////////////////////////////////////////
typedef unsigned char  uint8;

typedef unsigned short int  uint16;
typedef unsigned long int  uint32;
typedef unsigned long long int  uint64;


typedef signed short int  sint16;
typedef signed char    sint8;
typedef signed long int  sint32;
typedef signed long long int  sint64;

typedef float   float32;
typedef double  float64;
typedef long double float128;

///////////////////////////////////////////////////////////////
				        //macros//
///////////////////////////////////////////////////////////////

#define SET_BIT(reg,bit)  reg|=(1<<bit)
#define CLR_BIT(reg,bit)  reg&=~(1<<bit)
#define TOG_BIT(reg,bit)  reg^=(1<<bit)
#define READ_BIT(reg,bit)  (reg &(1<<bit))>>bit
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define TOG_REG(reg)  reg=~reg // reg^=0xff



#define LOW 0
#define HIGH 1

#endif
