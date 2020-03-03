#ifndef _analog_h
#define _analog_h

/* address definition of the Quest analog die registers */
typedef unsigned char byte;

	extern	volatile	byte	_ISRhi	@	0x0200;
	#define	ISRhi	_ISRhi			
	extern	volatile	byte	_ISRlo	@	0x0201 ;
	#define	ISRlo	_ISRlo			
	extern	volatile	byte	_IVR	@	0x0202  ;
	#define	IVR	_IVR			
	extern	volatile	byte	_VCR	@	0x0204  ;
	#define	VCR	_VCR			
	extern	volatile	byte	_VSR	@	0x0205  ;
	#define	VSR	_VSR			
	extern	volatile	byte	_LXR	@	0x0208  ;
	#define	LXR	_LXR			
	extern	volatile	byte	_LXCR	@	0x0209  ;
	#define	LXCR	_LXCR			
	extern	volatile	byte	_WDR	@	0x0210  ;
	#define	WDR	_WDR			
	extern	volatile	byte	_WDSR	@	0x0211  ;
	#define	WDSR	_WDSR			
	extern	volatile	byte	_WCR	@	0x0212  ;
	#define	WCR	_WCR			
	extern	volatile	byte	_TCR	@	0x0213  ;
	#define	TCR	_TCR			
	extern	volatile	byte	_WSR	@	0x0214  ;
	#define	WSR	_WSR			
	extern	volatile	byte	_RSR	@	0x0215  ;
	#define	RSR	_RSR			
	extern	volatile	byte	_MCR	@	0x0216  ;
	#define	MCR	_MCR			
	extern	volatile	byte	_LINR	@	0x0218  ;
	#define	LINR	_LINR			
	extern	volatile	byte	_PTBC1	@	0x0220;
	#define	PTBC1	_PTBC1			
	extern	volatile	byte	_PTBC2	@	0x0221;
	#define	PTBC2	_PTBC2			
	extern	volatile	byte	_PTB	@	0x0222   ;
	#define	PTB	_PTB			
	extern	volatile	byte	_HSCR	@	0x0228  ;
	#define	HSCR	_HSCR			
	extern	volatile	byte	_HSSR	@	0x0229  ;
	#define	HSSR	_HSSR			
	extern	volatile	byte	_LSCR	@	0x0230     ;
	#define	LSCR	_LSCR			
	extern	volatile	byte	_LSSR	@	0x0231     ;
	#define	LSSR	_LSSR			
	extern	volatile	byte	_HSR	@	0x0238     ;
	#define	HSR	_HSR			
	extern	volatile	byte	_CSR	@	0x023C     ;
	#define	CSR	_CSR			
	extern	volatile	byte	_SCIBDhi	@	0x0240 ;
	#define	SCIBDhi	_SCIBDhi			
	extern	volatile	byte	_SCIBDlo	@	0x0241 ;
	#define	SCIBDlo	_SCIBDlo			
	extern	volatile	byte	_SCIC1	@	0x0242   ;
	#define	SCIC1	_SCIC1			
	extern	volatile	byte	_SCIC2	@	0x0243   ;
	#define	SCIC2	_SCIC2			
	extern	volatile	byte	_SCIS1	@	0x0244   ;
	#define	SCIS1	_SCIS1			
	extern	volatile	byte	_SCIS2	@	0x0245   ;
	#define	SCIS2	_SCIS2			
	extern	volatile	byte	_SCIC3	@	0x0246   ;
	#define	SCIC3	_SCIC3			
	extern	volatile	byte	_SCID	@	0x0247     ;
	#define	SCID	_SCID			
	extern	volatile	byte	_PWMCTL	@	0x0260   ;
	#define	PWMCTL	_PWMCTL			
	extern	volatile	byte	_PWMPRCLK	@	0x0261 ;
	#define	PWMPRCLK	_PWMPRCLK			
	extern	volatile	byte	_PWMSCLA	@	0x0262 ;
	#define	PWMSCLA	_PWMSCLA			
	extern	volatile	byte	_PWMSCLB	@	0x0263 ;
	#define	PWMSCLB	_PWMSCLB			
	extern	volatile	byte	_PWMCNT0	@	0x0264 ;
	#define	PWMCNT0	_PWMCNT0			
	extern	volatile	byte	_PWMCNT1	@	0x0265 ;
	#define	PWMCNT1	_PWMCNT1			
	extern	volatile	byte	_PWMPER0	@	0x0266 ;
	#define	PWMPER0	_PWMPER0			
	extern	volatile	byte	_PWMPER1	@	0x0267 ;
	#define	PWMPER1	_PWMPER1			
	extern	volatile	byte	_PWMDTY0	@	0x0268 ;
	#define	PWMDTY0	_PWMDTY0			
	extern	volatile	byte	_PWMDTY1	@	0x0269 ;
	#define	PWMDTY1	_PWMDTY1			
	extern	volatile	byte	_ACR	@	0x0280     ;
	#define	ACR	_ACR			
	extern	volatile	byte	_ASR	@	0x0281     ;
	#define	ASR	_ASR			
	extern	volatile	byte	_ACCRhi	@	0x0282   ;
	#define	ACCRhi	_ACCRhi			
	extern	volatile	byte	_ACCRlo	@	0x0283   ;
	#define	ACCRlo	_ACCRlo			
	extern	volatile	byte	_ACCSRhi	@	0x0284 ;
	#define	ACCSRhi	_ACCSRhi			
	extern	volatile	byte	_ACCSRlo	@	0x0285 ;
	#define	ACCSRlo	_ACCSRlo			
	extern	volatile	byte	_ADR0hi	@	0x0286   ;
	#define	ADR0hi	_ADR0hi			
	extern	volatile	byte	_ADR0lo	@	0x0287   ;
	#define	ADR0lo	_ADR0lo			
	extern	volatile	byte	_ADR1hi	@	0x0288   ;
	#define	ADR1hi	_ADR1hi			
	extern	volatile	byte	_ADR1lo	@	0x0289   ;
	#define	ADR1lo	_ADR1lo			
	extern	volatile	byte	_ADR2hi	@	0x028A   ;
	#define	ADR2hi	_ADR2hi			
	extern	volatile	byte	_ADR2lo	@	0x028B     ;
	#define	ADR2lo	_ADR2lo			
	extern	volatile	byte	_ADR3hi	@	0x028C   ;
	#define	ADR3hi	_ADR3hi			
	extern	volatile	byte	_ADR3lo	@	0x028D   ;
	#define	ADR3lo	_ADR3lo			
	extern	volatile	byte	_ADR4hi	@	0x028E   ;
	#define	ADR4hi	_ADR4hi			
	extern	volatile	byte	_ADR4lo	@	0x028F   ;
	#define	ADR4lo	_ADR4lo			
	extern	volatile	byte	_ADR5hi	@	0x0290   ;
	#define	ADR5hi	_ADR5hi			
	extern	volatile	byte	_ADR5lo	@	0x0291   ;
	#define	ADR5lo	_ADR5lo			               
	extern	volatile	byte	_ADR6hi	@	0x0292   ;
	#define	ADR6hi	_ADR6hi			
	extern	volatile	byte	_ADR6lo	@	0x0293   ;
	#define	ADR6lo	_ADR6lo			
	extern	volatile	byte	_ADR7hi	@	0x0294  ;
	#define	ADR7hi	_ADR7hi			
	extern	volatile	byte	_ADR7lo	@	0x0295  ;
	#define	ADR7lo	_ADR7lo			
	extern	volatile	byte	_ADR8hi	@	0x0296  ;
	#define	ADR8hi	_ADR8hi			
	extern	volatile	byte	_ADR8lo	@	0x0297  ;
	#define	ADR8lo	_ADR8lo			
	extern	volatile	byte	_ADR9hi	@	0x0298  ;
	#define	ADR9hi	_ADR9hi			
	extern	volatile	byte	_ADR9lo	@	0x0299  ;
	#define	ADR9lo	_ADR9lo			
	extern	volatile	byte	_ADR10hi	@	0x029A;
	#define	ADR10hi	_ADR10hi			
	extern	volatile	byte	_ADR10lo	@	0x029B;
	#define	ADR10lo	_ADR10lo			
	extern	volatile	byte	_ADR11hi	@	0x029C;
	#define	ADR11hi	_ADR11hi			
	extern	volatile	byte	_ADR11lo	@	0x029D;
	#define	ADR11lo	_ADR11lo			
	extern	volatile	byte	_ADR15hi	@	0x02A4;
	#define	ADR15hi	_ADR15hi			
	extern	volatile	byte	_ADR15lo	@	0x02A5;
	#define	ADR15lo	_ADR15lo			
	extern	volatile	byte	_TIOS	@	0x02C0;
	#define	TIOS	_TIOS			
	extern	volatile	byte	_CFORC	@	0x02C1;
	#define	CFORC	_CFORC			
	extern	volatile	byte	_OC3M	@	0x02C2;
	#define	OC3M	_OC3M			
	extern	volatile	byte	_OC3D	@	0x02C3;
	#define	OC3D	_OC3D			
	extern	volatile	byte	_TCNThi	@	0x02C4;
	#define	TCNThi	_TCNThi			
	extern	volatile	byte	_TCNTlo	@	0x02C5;
	#define	TCNTlo	_TCNTlo			
	extern	volatile	byte	_TSCR1	@	0x02C6;
	#define	TSCR1	_TSCR1			
	extern	volatile	byte	_TTOV	@	0x02C7;
	#define	TTOV	_TTOV			
	extern	volatile	byte	_TCTL1	@	0x02C8;
	#define	TCTL1	_TCTL1			
	extern	volatile	byte	_TCTL2	@	0x02C9;
	#define	TCTL2	_TCTL2			
	extern	volatile	byte	_TIE	@	0x02CA;
	#define	TIE	_TIE			
	extern	volatile	byte	_TSCR2	@	0x02CB;
	#define	TSCR2	_TSCR2			
	extern	volatile	byte	_TFLG1	@	0x02CC;
	#define	TFLG1	_TFLG1			
	extern	volatile	byte	_TFLG2	@	0x02CD;
	#define	TFLG2	_TFLG2			
	extern	volatile	byte	_TC0hi	@	0x02CE;
	#define	TC0hi	_TC0hi			
	extern	volatile	byte	_TC0lo	@	0x02CF;
	#define	TC0lo	_TC0lo			
	extern	volatile	byte	_TC1hi	@	0x02D0;
	#define	TC1hi	_TC1hi			
	extern	volatile	byte	_TC1lo	@	0x02D1;
	#define	TC1lo	_TC1lo			
	extern	volatile	byte	_TC2hi	@	0x02D2;
	#define	TC2hi	_TC2hi			
	extern	volatile	byte	_TC2lo	@	0x02D3;
	#define	TC2lo	_TC2lo			                
	extern	volatile	byte	_TC3hi	@	0x02D4;
	#define	TC3hi	_TC3hi			
	extern	volatile	byte	_TC3lo	@	0x02D5;
	#define	TC3lo	_TC3lo			



#endif