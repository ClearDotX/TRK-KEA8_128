#include "lin_demo.h"
#include "lin.h"

l_u8 count = 0;
void init_demo(void) {
  
  /* For LED */
  /* Configures PB[3..0] as output and PB[7..4] as input */
  PORTB = 0x00;                                   
  DDRB = 0x0F; 

  /* Enables pull-ups on PB port */
  PUCR |= 0x02;
    
  PORTB_PB0=0;
  PORTB_PB1=0;
  PORTB_PB2=0;
  PORTB_PB3=0;
  
  /* Initialize ADC to grab potentiometer value */
  // 8 bit data resolution
  ATD0CTL1 = 0x10; 
  // Left justified data, 2 conversion sequence and non-FIFO mode
  ATD0CTL3 = 0x13;                        
  // fBUS=8MHz, fATDCLK = 1 MHz (PRESCLAER = 0) Select 24 Sample Time
  ATD0CTL4 = 0xE3;  
}

void free_counter_init()
{
  /* Common initialization of the CPU registers */
  /* ECT_TSCR1: TEN=0,TSWAI=0,TSFRZ=0,TFFCA=0,PRNT=0,??=0,??=0,??=0 */
  ECT_TSCR1 = 0;
  /* ECT_MCCTL: MODMC=1 */
  ECT_MCCTL = 64;           
  /* ECT_OCPD: OCPD0=1 */
  ECT_OCPD = 1;             
  /* ECT_PACTL: CLK1=0,CLK0=0 */
  ECT_PACTL &=  ~12;           
  /* ECT_OC7M: OC7M0=0 */
  ECT_OC7M &= ~1;
  /* ECT_TIOS: IOS0=1 */
  ECT_TIOS = 1;             
  /* ECT_TCTL2: OM0=0,OL0=0 */
  ECT_TCTL2 &= ~3;
  /* ECT_TTOV: TOV0=0 */
  ECT_TTOV &= ~1;             
  /* ECT_TSCR2: TOI=0,TCRE=0,PR2=1,PR1=1,PR0=1 */
  ECT_TSCR2_TOI = 0;
  ECT_TSCR2_TCRE = 0;
  ECT_TSCR2_PR2 = 1;
  ECT_TSCR2_PR1 = 1;
  ECT_TSCR2_PR0 = 1;
  /* ECT_TFLG1: C7F=1,C6F=1,C5F=1,C4F=1,C3F=1,C2F=1,C1F=1,C0F=1 */
  ECT_TFLG1 = 255;
  /* ECT_TIE: C0I=1 */
  ECT_TIE = 1;
  /* ### MC9S12XEP100_208 "Cpu" init code ... */
  /* ### Free running 16-bit counter "FC1" init code ... */
  /* ECT_TC0: BIT15=1,BIT14=1,BIT13=1,BIT12=1,BIT11=0,BIT10=1,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=1,BIT4=0,BIT3=0,BIT2=1,BIT1=0,BIT0=0 */
  ECT_TC0 = 62500;            /* Store given value to the compare register */ 
 /* Common peripheral initialization - ENABLE */
  /* ECT_TSCR1: TEN=1 */
  ECT_TSCR1_TEN = 0;          
}

void freecntr_enable(){
  ECT_TSCR1_TEN = 1;
}

void freecntr_disable(){
  ECT_TSCR1_TEN = 0;
}


void tim_init(){
  TIM_TSCR1_TEN = 0;
  TIM_TIE = 0;
  TIM_PACTL &= ~(65);
  PTRRR = 0;
  TIM_TIOS = 128;
  TIM_TC7 = 1250; /* The output compare counter for 5ms
                     To setup 10ms, the value is 2500
                    */
  TIM_OCPD = 128;
  TIM_OC7M = 128;
  TIM_OC7D = 0;
  TIM_TTOV = 128;
  TIM_TCTL1 = 192;
  TIM_TCTL2 = 0;
  TIM_TCTL3 = 0;
  TIM_TCTL4 = 0;
  TIM_TFLG1 = 255;
  TIM_TFLG2 = 128;
  TIM_TIE = 128;
  TIM_TSCR2 = 141;
  TIM_PACNT = 0;
  TIM_PTPSR = 0;
  TIM_TSCR1 = 0;
  TIM_PAFLG = 3;
  TIM_PACTL = 12;
  TIM_TSCR1_TEN = 1;
}

void init_sci6(void)
{		

	SCI6BD = 52;						/* 9.6 kbps baudrate */
	SCI6CR1 &= ~SCICR1_M_MASK & ~SCICR1_PE_MASK; /* 8,N,1 byte format */
	SCI6CR2 |= SCICR2_TE_MASK | SCICR2_RE_MASK;	/* SCI Tx/Rx enabled */


}

#pragma CODE_SEG __NEAR_SEG NON_BANKED
interrupt VectorNumber_Vectch0 void freecntr_isr() 
{
  count++;
  ECT_TFLG1 = 1;                       /* Reset interrupt request flag */
}

interrupt VectorNumber_Vtimch7 void main_application_5ms(void)
{
    /* Periodically call the schedule tick function */
    (void)l_sch_tick(LI1);
    (void)l_sch_tick(LI2);
    /* Clear timer interrupt flag */
    TIM_TFLG1 = TIM_TFLG1_C7F_MASK;
}
#pragma CODE_SEG DEFAULT