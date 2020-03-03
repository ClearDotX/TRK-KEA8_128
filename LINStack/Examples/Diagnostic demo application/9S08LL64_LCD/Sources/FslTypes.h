#ifndef __Definitions__
  #define __Definitions__


  /* Typedefs */
  /* Standard Types */
  typedef unsigned char   UINT8;  		/*unsigned 8 bit definition */
  typedef unsigned int    UINT16; 		/*unsigned 16 bit definition*/
  typedef unsigned long   UINT32; 		/*unsigned 32 bit definition*/
  typedef signed char     INT8;   		/*signed 8 bit definition */
  typedef short      		  INT16;  		/*signed 16 bit definition*/
  typedef long int    	  INT32;  		/*signed 32 bit definition*/

  /* State Machine */
  typedef struct
  {
    UINT8 ActualState;
    UINT8 PrevState;
    UINT8 NextState;
    UINT8 ErrorState;
  }sSM;


  /* Definitions */
  #define   _OUT       1
  #define   _IN        0

  enum ISR
  {
      SCI_Flag,
      ADC_Flag
  };

  /* Macros */
  #define FLAG_SET(BitNumber, Register)        (Register |=(1<<BitNumber))
  #define FLAG_CLR(BitNumber, Register)        (Register &=~(1<<BitNumber))
  #define FLAG_CHK(BitNumber, Register)        (Register & (1<<BitNumber))


#endif /* __Definitions__ */