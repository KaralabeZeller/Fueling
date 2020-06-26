#include "Bvez2.h"
#include "SorosMod232.h"
#include "SorosModNet.h"
#include "Sflash16M.h"
//===============================================Configure PLL prescaler, PLL postscaler, PLL divisor
void TimerPllStart(void)
{
RCONbits.SWDTEN=0;		 	   	        // Disable Watch Dog Timer
										// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2 - Fosc= 8M*40/(2*2)=80Mhz for 8M input clock
PLLFBD=38;								// M = 40 ((8MHz/2)*40)/2=80MHz
CLKDIVbits.PLLPOST=0;					// N2 = 2
CLKDIVbits.PLLPRE=0;					// N1 = 2
__builtin_write_OSCCONH(0x03);			// Initiate Clock Switch to Primary Oscillator with PLL (NOSC = 0b011)
__builtin_write_OSCCONL(0x01);			// Start clock switching
while(OSCCONbits.COSC != 0b011);		// Wait for Clock switch to occur
while(OSCCONbits.LOCK != 1);			// Wait for PLL to lock
}
//===============================================
void Timer2InterruptInit(void)	//7->6,945usec
{
T2CON = 0;						// Timer reset
//T2CONbits.TON=0;				// Disable Timer
//T2CONbits.TCS=0;				// Select internal instruction cycle clock
//T2CONbits.TGATE=0;			// Disable Gated Timer mode
T2CONbits.TCKPS=1;				// Select 1:8 Prescaler (0,2usec)
TMR2=0x0000;					// Clear timer register
PR2=34;//35-1					// Load the period value (7usec=(34+1)*0,2)
IFS0bits.T2IF=0;				// Clear Timer2 Interrupt Flag
IPC1bits.T2IP=INT_PRIORITY_TIM2;// Set Timer2 Interrupt Priority Level (1-6)
IEC0bits.T2IE=1;				// Enable Timer2 interrupt
T2CONbits.TON=1;				// Start Timer
}
//===============================================
void Timer3InterruptInit(void)	//1,6msec
{
T3CON = 0;						// Timer reset
//T3CONbits.TON=0;				// Disable Timer
//T3CONbits.TCS=0;				// Select internal instruction cycle clock
//T3CONbits.TGATE=0;			// Disable Gated Timer mode
T3CONbits.TCKPS=3;				// Select 1:256 Prescaler (256*0,025usec=6,4us)
TMR3=0x0000;					// Clear timer register
PR3=249;//250-1					// Load the period value (1,6ms=625Hz)
IFS0bits.T3IF=0;				// Clear Timer Interrupt Flag
IPC2bits.T3IP=INT_PRIORITY_TIM3;// Set Timer Interrupt Priority Level (1-6)
IEC0bits.T3IE=1;				// Enable Timer interrupt
T3CONbits.TON=1;				// Start Timer
}
//===============================================
void Timer4InterruptInit(void)	//100usec
{
T4CON = 0;						// Timer reset
//T1CONbits.TON=0;				// Disable Timer
//T1CONbits.TCS=0;				// Select internal instruction cycle clock
//T1CONbits.TGATE=0;			// Disable Gated Timer mode
T4CONbits.TCKPS=1;				// Select 1:8 Prescaler (0,2usec)
TMR4=0x0000;					// Clear timer register
PR4=499;//500-1					// Load the period value (100usec)
IFS1bits.T4IF=0;				// Clear Timer Interrupt Flag
IPC6bits.T4IP=INT_PRIORITY_TIM4;// Set Timer Interrupt Priority Level (1-6)
IEC1bits.T4IE=1;				// Enable Timer interrupt
T4CONbits.TON=1;				// Start Timer
}
//===============================================
void Timer6InterruptInit(void)	//1ms
{
T6CON = 0;						// Timer reset
//T6CONbits.TON=0;				// Disable Timer
//T6CONbits.TCS=0;				// Select internal instruction cycle clock
//T6CONbits.TGATE=0;			// Disable Gated Timer mode
T6CONbits.TCKPS=1;				// Select 1:8 Prescaler (0,2usec)
TMR6=0x0000;					// Clear timer register
PR6=4999;//5000-1				// Load the period value (1000usec)
IFS2bits.T6IF=0;				// Clear Timer6 Interrupt Flag
IPC11bits.T6IP=INT_PRIORITY_TIM6;// Set Timer6 Interrupt Priority Level (1-6)
IEC2bits.T6IE=1;				// Enable Timer6 interrupt
T6CONbits.TON=1;				// Start Timer
}
//===============================================
//void TimerInterruptStop(void)
//{
//}
//===============================================
uint16_t	Int35u= 0;
uint16_t	FlsIntDisable= 0;		//*1ms flash int stop
void __attribute__((__interrupt__, auto_psv)) _T2Interrupt(void)	//7usec	#kb.30+45 - PRIOR=4
{
if(FlsIntDisable == 0) Fls_Int_7u_L();			//#35-1us

switch(Int35u){
	case 0:		Rxf_Busz_35u(); break;			//#66-1,6us
	case 1:		Txe_Busz_35u(); break;			//#56-1,5us
	case 2:		Rxd_Busz_35u(); break;			//#72-1,8us
	case 3:		Rxc_Busz_35u(); break;			//#kb.45
	case 4:		Rxb_Busz_35u(); break;
	}
Int35u++; if(Int35u > 4) Int35u=0;

IFS0bits.T2IF=0;								//Clear Timer interrupt flag
}
//===============================================
void __attribute__((__interrupt__, auto_psv)) _T3Interrupt(void)//#21	//1,6ms-625Hz - PRIOR=2
{
if(M.SpkTim > 0) OC1RS= 125; else OC1RS= 0;		//Write Duty Cycle value for next PWM cycle
OC3RS= EE.KontReg;								//Write Duty Cycle value for next PWM cycle

IFS0bits.T3IF= 0;								//Clear Timer interrupt flag
}
//===============================================
void __attribute__((__interrupt__, auto_psv)) _T4Interrupt(void)	//100usec - PRIOR=3
{
Fls_Ciklus_100u();
Soros_NET_100us();								//Kútfõk
Pisztoly_100us();								//RS232-Pisztoly
Soros_232_100u();
Meres_100u();

IFS1bits.T4IF= 0;								//Clear Timer interrupt flag
}
//===============================================
uint16_t 	DelayMs= 0;								//*1msec delay time (Interrupt increment)
void __attribute__((__interrupt__, auto_psv)) _T6Interrupt(void)	//1ms - PRIOR=1
{
DelayMs++;
if(FlsIntDisable > 0) FlsIntDisable--;

RealTime1ms();

IFS2bits.T6IF= 0;								//Clear Timer interrupt flag
}
//===============================================Alap
void  Delay_Ms_Alap(uint16_t time)					//time=delay in ms
{
DelayMs= 0;
while(DelayMs >= time);
}
//===============================================END
