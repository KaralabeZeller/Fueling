//===============================================
// MCP79410 óra csomag
//===============================================
#include "Bvez2.h"
#include "OraKorr.h"
//-----------------------------------------------
void ORA_PinInit(void)
{
I2C1BRG = 0x0188;				//BaudRate = 40Mhz/100kHz = 0x0188
I2C1CON = 0x1200;				//Master Mode, No Slew Rate Control, and leave the peripheral switched off.
I2C1RCV = 0x0000;
I2C1TRN = 0x0000;
I2C1CON = 0x9200;				//on
}
//-----------------------------------------------
uint16_t	_StartI2C(void)
{
I2C1CONbits.SEN=1;				//Generate Start COndition
while(I2C1CONbits.SEN);			//Wait for Start COndition
return(I2C1STATbits.S);			//Optionally return status
}
//-----------------------------------------------
uint16_t	_RestartI2C(void)
{
I2C1CONbits.RSEN = 1;			//Generate Restart		
while(I2C1CONbits.RSEN);		//Wait for restart	
return(I2C1STATbits.S);			//Optional - return status
}
//-----------------------------------------------
uint16_t	_StopI2C(void)
{
I2C1CONbits.PEN = 1;			//Generate Stop Condition
while(I2C1CONbits.PEN);			//Wait for Stop
return(I2C1STATbits.P);			//Optional - return status of the Stop
}
//-----------------------------------------------
void		_WriteI2C(uint8_t byte)
{
while(I2C1STATbits.TRSTAT);		//Wait for bus to be idle
I2C1TRN=byte;					//Load byte to I2C1 Transmit buffer
while(I2C1STATbits.TBF);		//wait for data transmission
}
//-----------------------------------------------
void		_IdleI2C(void)
{
while(I2C1STATbits.TRSTAT);		//Wait for bus Idle
}
//-----------------------------------------------
void		_NotAckI2C(void)
{
I2C1CONbits.ACKDT=1;			//Set for NotACk
I2C1CONbits.ACKEN=1;
while(I2C1CONbits.ACKEN);		//wait for ACK to complete
I2C1CONbits.ACKDT=0;			//Set for NotACk
}
//-----------------------------------------------
void		_ORA_ir(uint8_t cim, uint8_t dat)
{
_IdleI2C();						//Ensure Module is Idle
_StartI2C();					//Generate Start COndition
_WriteI2C(0xde);				//Write Control byte
_IdleI2C();
//ErrorCode=ACKStatus();		//Return ACK Status
_WriteI2C(cim);					//Write Low Address
_IdleI2C();
//ErrorCode=ACKStatus();		//Return ACK Status
_WriteI2C(dat);					//Write Data
_IdleI2C();
_StopI2C();						//Initiate Stop Condition
//EEAckPolling(ControlByte);	//Perform ACK polling
//return(ErrorCode);
}
//-----------------------------------------------Alap
void		_EEprom_ir(uint8_t cim, uint8_t dat)
{
_IdleI2C();						//Ensure Module is Idle
_StartI2C();					//Generate Start COndition
_WriteI2C(0xae);				//Write Control byte
_IdleI2C();
//ErrorCode=ACKStatus();		//Return ACK Status
_WriteI2C(cim);					//Write Low Address
_IdleI2C();
//ErrorCode=ACKStatus();		//Return ACK Status
_WriteI2C(dat);					//Write Data
_IdleI2C();
_StopI2C();						//Initiate Stop Condition
//EEAckPolling(ControlByte);	//Perform ACK polling
//return(ErrorCode);
}
//-----------------------------------------------
uint8_t		_ORA_olv(uint8_t cim)
{
uint8_t dat;

_IdleI2C();						//wait for bus Idle
_StartI2C();					//Generate Start Condition
_WriteI2C(0xde);				//Write Control Byte
_IdleI2C();						//wait for bus Idle
_WriteI2C(cim);					//Write start address
_IdleI2C();						//wait for bus Idle

_RestartI2C();					//Generate restart condition
_WriteI2C(0xde | 0x01);			//Write control byte for read
_IdleI2C();						//wait for bus Idle

I2C1CONbits.RCEN=1;				//Enable Master receive
asm("nop");
while(!I2C1STATbits.RBF);		//Wait for receive bufer to be full
dat=I2C1RCV;					//Return data in buffer

_NotAckI2C();					//Send Not Ack
_StopI2C();						//Generate Stop

return(dat);
}
//-----------------------------------------------Alap
uint8_t		EEprom_olv(uint8_t cim)
{
uint8_t		dat;

Ora.Freeze=1;
_IdleI2C();						//wait for bus Idle
_StartI2C();					//Generate Start Condition
_WriteI2C(0xae);				//Write Control Byte
_IdleI2C();						//wait for bus Idle
_WriteI2C(cim);					//Write start address
_IdleI2C();						//wait for bus Idle

_RestartI2C();					//Generate restart condition
_WriteI2C(0xae | 0x01);			//Write control byte for read
_IdleI2C();						//wait for bus Idle

I2C1CONbits.RCEN=1;				//Enable Master receive
asm("nop");
while(!I2C1STATbits.RBF);		//Wait for receive bufer to be full
dat=I2C1RCV;					//Return data in buffer

_NotAckI2C();					//Send Not Ack
_StopI2C();						//Generate Stop

Ora.Freeze=0;
return(dat);
}
//-----------------------------------------------Alap-Reset
void		Ora_Init(void)
{
uint8_t		day= _ORA_olv(3);

Ora.Sys_MP=0;	Ora.Sys_PERC= 0;
Ora.PercOld=0;	Ora.MpOld= 0;
Ora.MpError=0;	Ora.PercError= 0;
Ora.Freeze=0;	Ora.Beall= 0;
Ora.NewKorr=0;	Ora.KorrBeall= 0;

if(day & 0x20)	return;			//óra megy
else{
	_ORA_ir(3, 0x08|day);		//read day + VBATEN bit
	_ORA_ir(0, 0x84);			//start osszcillátor
	}	
}
//-----------------------------------------------
void		ORA_Beall(void)
{
uint8_t		mp, perc, ora, wnap, nap, ho, ev;

mp=		Ora.BeMp/10*16		+Ora.BeMp%10;
perc=	Ora.BePerc/10*16	+Ora.BePerc%10;
ora=	Ora.BeOra/10*16		+Ora.BeOra%10;
wnap=	Ora.BeWnap&0x07;
nap=	Ora.BeNap/10*16		+Ora.BeNap%10;
ho=		Ora.BeHo/10*16		+Ora.BeHo%10;
ev=		Ora.BeEv/10*16		+Ora.BeEv%10;

Ora.Beall= 0;
_ORA_ir(6,		ev);
_ORA_ir(5,		ho);
_ORA_ir(4,		nap);	// x,x,nap(2)		;nap(4)
_ORA_ir(3,0x08 | wnap);	// x,x,OSCON,VBAT	;VBATEN,wday(3)
_ORA_ir(2,0x00 | ora);	// x,12/24n,10ó(2)	;1ó(4)
_ORA_ir(1,		perc);	// x,10p(3)			;1p(4)
_ORA_ir(0,0x80 | mp);	//ST,10mp(3)		;1mp(4)
}
//-----------------------------------------------
void		ORA_KorrBeall(void)
{
Ora.KorrBeall= 0;
_ORA_ir(8, Ora.NewKorr);
}
//-----------------------------------------------
void		EE_WrCiklus(void)
{
if(EEwrCim > 127){ EEwrDb= 0; }			//hibás paraméter
else{
	_EEprom_ir(EEwrCim,*(((uint8_t*)(&EE.xxVERZ))+EEwrCim));
	EEwrCim++; EEwrDb--;
	}
}
//-----------------------------------------------Int-100ms
void		Ora_Cikl_100m(void)
{
uint8_t		mp, perc, ora, wnap, nap, ho, ev, mp2;

Ora.MpError++;
if(Ora.Freeze != 0) return;						//eeprom olv

if		(Ora.Beall > 0)		ORA_Beall();
else if	(Ora.KorrBeall > 0)	ORA_KorrBeall();
else{
	mp=		_ORA_olv(0);
	perc=	_ORA_olv(1);
	ora=	_ORA_olv(2);
	wnap=	_ORA_olv(3);
	nap=	_ORA_olv(4);
	ho=		_ORA_olv(5);
	ev=		_ORA_olv(6);
	mp2=	_ORA_olv(0);
	if(mp == mp2){								//if(változott)nem_olvas
		Ora.Ev=		(ev/16*10)+ev%16;
		Ora.Ho=		(((ho/16)&0x01)*10)+ho%16;
		Ora.Nap=	(nap/16*10)+nap%16;
		Ora.Wnap=	wnap&0x07;
		Ora.Ora=	(((ora/16)&0x03)*10)+ora%16;
		Ora.Perc=	(perc/16*10)+perc%16;
		Ora.Mp=		(((mp/16)&0x07)*10)+mp%16;
		Ora.TimKomp=	_ORA_olv(0x08);

		Ora.MpError= 0;  Ora.PercError= 0;
		if(Ora.Mp != Ora.MpOld){
			Ora.MpOld= Ora.Mp; Ora.Sys_MP= 1;
			if(Ora.Perc != Ora.PercOld){
				Ora.PercOld= Ora.Perc; Ora.Sys_PERC= 1;
				}	
			}
		}
	}
if(Ora.MpError >= 10){							//óra ic nem megy
	Ora.Sys_MP= 1; Ora.MpError= 0;
	Ora.PercError++;
	if(Ora.PercError >= 60){
		Ora.Sys_PERC= 1; Ora.PercError= 0;
		}	
	}	

if(EEwrDb > 0) EE_WrCiklus();
}
//===============================================END
