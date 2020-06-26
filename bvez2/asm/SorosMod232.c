//=========================================================
// BVEZ2 - benzin vezérl? soros csomag (RS232)
//=========================================================
#include <stdint.h>

#include "SorosMod232.h"
#include "Bvez2.h"
#include "asmFlash.h"
#include "Sflash16M.h"
#include "SorosModNet.h"
//---------------------------------------------------------
uint16_t		Rs232Apos= 0;			//adó ptr
uint16_t		Rs232Anum= 0;			//adandó db
uint16_t		Rs232Vpos= 0;			//vett ptr
uint16_t		Rs232Vtimout= 0;			//*1ms timeout
uint16_t		Rs232Tilt= 0;			//*1ms vétel és adás között

uint8_t			Rs232Vesz[256];
uint8_t			Rs232Ad[256];
uint8_t			FLS_CLR_STR[7]= {"CLRFLS"};
//---------------------------------------------------------
void	Rs232_Sajat(void);
void	Rs232_Par3jott(void);
void	Rs232_Par4jott(void);
void	Rs232_Par16jott(void);
void	Rs232_NemJo(void);
void	Rs232_ReadRam(void);
void	Rs232_ReadFlash(void);
void	Rs232_WriteRam(void);
//void	Rs232_WriteEEprom(void);
//---------------------------------------------------------
/* Table of CRC values for high?order byte */
const unsigned char	CRC_H[]={
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81,
0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,

0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
0x40};
/* Table of CRC values for low?order byte */
const unsigned char	CRC_L[]={
0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7, 0x05, 0xC5, 0xC4,
0x04, 0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F, 0xDD,
0x1D, 0x1C, 0xDC, 0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32, 0x36, 0xF6, 0xF7,
0x37, 0xF5, 0x35, 0x34, 0xF4, 0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA, 0xEE,
0x2E, 0x2F, 0xEF, 0x2D, 0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,

0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 0x61, 0xA1, 0x63, 0xA3, 0xA2,
0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 0x78, 0xB8, 0xB9, 0x79, 0xBB,
0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0, 0x50, 0x90, 0x91,
0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98, 0x88,
0x48, 0x49, 0x89, 0x4B, 0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83, 0x41, 0x81, 0x80,
0x40};
//=========================================================
void	UART1_Init()
{
//U1MODEbits.UARTEN=0;			//Bit15		TX, RX DISABLED
//U1MODEbits.USIDL=0;			//Bit13		Continue in Idle
//U1MODEbits.IREN=0;			//Bit12		No IR translation
//U1MODEbits.RTSMD=0;			//Bit11		Simplex Mode
//U1MODEbits.UEN=0;				//Bits8,9	TX,RX enabled, CTS,RTS not
//U1MODEbits.WAKE=0;			//Bit7		No Wake up
//U1MODEbits.LPBACK=0;			//Bit6		No Loop Back
//U1MODEbits.ABAUD=0;			//Bit5		No Autobaud
//U1MODEbits.URXINV=0;			//Bit4		RX IdleState=1
//U1MODEbits.BRGH=0;			//Bit3		16 clocks per bit period
//U1MODEbits.PDSEL=0;			//Bits1,2	8bit, No Parity
//U1MODEbits.STSEL=0;			//Bit0		One Stop Bit
U1MODE=0x0000;

//U1BRG=129;					//40Mhz-19,2kbaud U1BRG=(Fcy/(16*BaudRate))-1 =(40M/(16*19200))-1=129
U1BRG=64;						//40Mhz-38,4kbaud U1BRG=(Fcy/(16*BaudRate))-1 =(40M/(16*38400))-1=64

//U1STAbits.UTXISEL1=0;			//Bit15		Int when Char is transferred (1/2 config!)
//U1STAbits.UTXINV=0;			//Bit14		N/A, IRDA config
//U1STAbits.UTXISEL0=0;			//Bit13		Other half of Bit15
//U1STAbits.UTXBRK=0;			//Bit11		Disabled
//U1STAbits.UTXEN=0;			//Bit10		TX pins controlled(TEN után bekapcs)
//U1STAbits.URXISEL=0;			//Bits6,7	Int. on character recieved
//U1STAbits.ADDEN=0;			//Bit5 		Address Detect Disabled
U1STA=0x0000;

//IPC7=0x4400;					// Mid Range Interrupt Priority level, no urgent reason
//IFS1bits.U1TXIF=0;			// Clear the Transmit Interrupt Flag
//IEC1bits.U1TXIE=1;			// Enable Transmit Interrupts
//IFS1bits.U1RXIF=0;			// Clear the Recieve Interrupt Flag
//IEC1bits.U1RXIE=1;			// Enable Recieve Interrupts

U1MODEbits.UARTEN=1;			//turn on
U1STAbits.UTXEN=1;
}
//---------------------------------------------------------
uint16_t	ModBus_BeCrcCalc(uint8_t *msg, uint8_t db)
{
uint8_t			len= db-2;	//quantity of bytes in message
uint8_t			crchi= 0xff;//high byte of CRC initialized
uint8_t			crclo= 0xff;//low byte of CRC initialized
unsigned int	index;		//will index into CRC lookup table

while((len)>0){
	len--;
	index= crchi ^ *msg;
	msg++;
	crchi= crclo^CRC_H[index];
	crclo= CRC_L[index];
	}
return(crchi<<8 | crclo);
}
//---------------------------------------------------------
void	ModBus_KiCrcCalc(uint8_t *msg, uint8_t db)
{
uint16_t	crc;

msg[db-2]= 0;
msg[db-1]= 0;
crc= ModBus_BeCrcCalc(msg, db);
msg[db-2]= crc>>8;
msg[db-1]= crc&0xff;
}
//=========================================================Int-100us
void	Soros_232_100u(void)
{
if(Rs232Anum > 0){								//Adás
	if(U1STAbits.UTXBF == 0){					//1=transmit buffer full
		if(Rs232Apos < Rs232Anum)				//if(pos<db)Ad
			U1TXREG= Rs232Ad[Rs232Apos++];
		else{
			if(U1STAbits.TRMT != 0){			//1=transmit complete
				Rs232Anum= 0; Rs232Vpos= 0;		//Vétel start
				U1STAbits.OERR= 0;				//overrun clear+eldob
				}
			}
		}
	}
else{//------------------------------------------Vétel
	if(U1STAbits.URXDA != 0){					//if van adat
		Rs232Vesz[Rs232Vpos]= U1RXREG;
		if((Rs232Vpos == 0)&&(Rs232Vesz[0] == 0xa5)){//várakozás szinkronra
			Rs232Vtimout= 0; Rs232Vpos++;
			}
		else if(Rs232Vpos < 254) Rs232Vpos++;	//if(tele)eldob
		Rs232Tilt= RS232_TILT;					//válasz késik
		}
	else if(U1STAbits.OERR != 0) U1STAbits.OERR= 0;//overrun clear+eldob
	}
}
//=========================================================Int-1ms
void	Soros_232_1ms(void)
{
uint8_t		db;
uint16_t	crc, crcbe;

if(Rs232Tilt != 0) Rs232Tilt--;
else{
	Rs232Vtimout++;
	if(Rs232Vtimout >= RS232_TIMEOUT){ Rs232Vtimout= 0; Rs232Vpos= 0; }	

	if(Rs232Vpos >= 6){										//vár min.6 karakterre
		db= Rs232Vesz[1]+1;
		if(db >= Rs232Vpos){								//megvárja a teljes csomagot
			Rs232Anum= 0; Rs232Apos= 0; Rs232Vtimout= 0;	//stop send
			crc= ModBus_BeCrcCalc(Rs232Vesz,db);
			crcbe= (((uint16_t)Rs232Vesz[db-2])<<8)+Rs232Vesz[db-1];
			if(crc != crcbe) Rs232_NemJo();					//CRC rossz
 			else{
				switch(Rs232Vesz[2]){
					case 3:		Rs232_ReadFlash(); break;	//PAR=3 	;READ HOLDING REGISTERS
					case 4:		Rs232_ReadRam(); break;		//PAR=4		;READ INPUT REGISTERS
					case 16:	Rs232_WriteRam(); break;	//PAR=16	;WRITE HOLDING REGISTERS
					}
				}
			}
		}
	}
}
//---------------------------------------------------------Jó blokk vége
void	Rs232_Init(uint8_t db)
{
Rs232Apos= 0;
Rs232Anum= db;
LedProcTime= LED_JOKERES;				//proc led ég
LedProcTilt= LED_TILT;
Rs232Vpos= 0;
}
//---------------------------------------------------------Rossz blokk vége
void	Rs232_NemJo(void)
{
LedHibaTime= LED_JOKERES;				//hiba led ég
Rs232Vpos= 0;
}
//---------------------------------------------------------hiba visszajelzés
void	Rs232_Hiba(uint8_t hiba)
{
Rs232Ad[0]= 0xa5;
Rs232Ad[1]= 5;							//db-1
Rs232Ad[2]= Rs232Vesz[2]|0x80;			//hiba jelzés -> parancs(3,4)
Rs232Ad[3]= hiba;						//hibakód
ModBus_KiCrcCalc(Rs232Ad, 6);
Rs232_Init(6);
}
//=========================================================
#define	RD_MEM		0x00
#define	RD_MNU		0x02
#define	RW_CARD		0x04
#define	RD_SZINT	0x05
#define	RW_ORA		0x06
#define	RW_ARAK		0x07
#define	RW_EEPROM	0x08
#define	RD_NET		0x0a
#define	RD_FLS		0x0c
#define	RW_CEG		0x0e
#define	RW_SZINT	0x10
#define	RD_KUT		0x20	//x20-x2e 15db
#define	RD_TANK		0x40	//x40,41 - x5e,5f 15db
#define	CLR_SECT	0x60
#define	WR_PFLSPAR	0x70	//program flash parancs(r/w/e+page+cím)
#define	RD_PFLSROW	0x72	//read program flash row
#define	WR_FLS		0x74	//data flash write
//#define	RD_RAM		0x80	//cím szerint
//---------------------------------------------------------Int-1ms
void	Rs232_ReadRam_AdTolt(uint8_t *mem, uint16_t db, uint8_t mut)
{
Rs232Ad[0]= 0xa5;
Rs232Ad[1]= db+5;			//db-1
Rs232Ad[2]= 4;				//parancs
Rs232Ad[3]= mut;
MemCpy(&Rs232Ad[4], mem, db);
ModBus_KiCrcCalc(Rs232Ad, db+6);
Rs232_Init(db+6);
}
//---------------------------------------------------------Int-1ms
void	Rs232_ReadRam(void)
{
uint8_t		db, mut, mut1, mut2;

mut= Rs232Vesz[3];
mut2= mut&0xfe;
mut1= mut&1;
db= Rs232Vesz[4];

if		(mut2 == RD_MEM)		Rs232_ReadRam_AdTolt((uint8_t*)&M+mut1*128		,db,mut2);
else if	(mut2 == RD_MNU)		Rs232_ReadRam_AdTolt((uint8_t*)&Mnu+mut1*128	,db,mut2);
else if	(mut  == RW_CARD)		Rs232_ReadRam_AdTolt((uint8_t*)&Card			,db,0);
else if	(mut  == RD_SZINT)		Rs232_ReadRam_AdTolt((uint8_t*)&Szint			,db,0);
else if	(mut  == RW_ORA)		Rs232_ReadRam_AdTolt((uint8_t*)&Ora				,db,0);
else if	(mut  == RW_ARAK)		Rs232_ReadRam_AdTolt((uint8_t*)&Arak0			,db,0);
else if	(mut2 == RW_SZINT)		Rs232_ReadRam_AdTolt((uint8_t*)&M.SzintTbl+mut1*128,db,mut2);
// *** csak teszthez
else if	(mut2 == RW_EEPROM)		Rs232_ReadRam_AdTolt((uint8_t*)&EE+mut1*128		,db,mut2);
else if	(mut2 == RD_NET)		Rs232_ReadRam_AdTolt((uint8_t*)&Net+mut1*128	,db,mut2);
else if	(mut2 == RD_FLS)		Rs232_ReadRam_AdTolt((uint8_t*)&Fls+mut1*128	,db,mut2);
else if	(mut2 == RW_CEG)		Rs232_ReadRam_AdTolt((uint8_t*)&Ceg0+mut1*128	,db,mut2);
else if	((mut >= RD_KUT)&&(mut < (RD_KUT+15)))
								Rs232_ReadRam_AdTolt((uint8_t*)&Kut[mut-RD_KUT],db,mut);
else if	((mut >= RD_TANK)&&(mut < (RD_TANK+32)))
								Rs232_ReadRam_AdTolt((uint8_t*)&Tank[(mut2-RD_TANK)/2]+mut1*128,db,mut2);
else if	(mut2 == RD_PFLSROW)	Rs232_ReadRam_AdTolt((uint8_t*)&FlsRow+mut1*128,db,mut2);

else	Rs232_Hiba(HIBA_ADDR);						//rossz regiszter
}
//---------------------------------------------------------Int-1ms
void	Rs232_ReadFlash(void)
{
uint16_t	cim;
uint8_t		alcim, len;

cim= (((uint16_t)Rs232Vesz[3])<<8)+Rs232Vesz[4];
alcim= Rs232Vesz[5];
len= Rs232Vesz[6];
if(FlsPcRd(cim, alcim, len) == 0) Rs232_Hiba(HIBA_BUSY);
}
//---------------------------------------------------------Int-100u
void	Rs232_RdFls_Valasz(uint8_t len)//call from: Fls_Ciklus_Pc()//100us
{
Rs232Ad[0]= 0xa5;
Rs232Ad[1]= 5+len;				//byte-1
Rs232Ad[2]= 3;					//parancs
Rs232Ad[3]= 0;					//dummy
MemCpy(&Rs232Ad[4], Fls.Pc.Be, 128);
ModBus_KiCrcCalc(Rs232Ad, len+6);
Rs232_Init(len+6);
}
//---------------------------------------------------------Int-1ms
void	Rs232_WriteRam(void)
{
uint8_t		db, mut, i, alcim;
uint16_t	sum, par, pag, cim;

//Rs232Vesz[0]=0xa5;
db= Rs232Vesz[1]-5;//db-1
//Rs232Vesz[2]=16;//parancs
mut= Rs232Vesz[3];
switch(mut){
	case RW_ORA:												//Óra beállítás
			if(db == 8){
				Ora.BeEv=	Rs232Vesz[4];
				Ora.BeHo=	Rs232Vesz[5];
				Ora.BeNap=	Rs232Vesz[6];
				Ora.BeOra=	Rs232Vesz[7];
				Ora.BePerc=	Rs232Vesz[8];
				Ora.BeMp=	Rs232Vesz[9];
				Ora.BeWnap=	Rs232Vesz[10];
				Ora.Beall=1;
				}
			else if(db == 1){
				Ora.NewKorr= Rs232Vesz[4];
				Ora.KorrBeall= 1;
				}
			break;
	case RW_CARD:												//Write Card
			if((db != 64)||(M.CardDb >= (FLS_CARDMAX-FLS_CARDMIN)*2)){ Rs232_Hiba(HIBA_ADDR); return; }//rossz hossz
			else{
				Rs232Vesz[4+0x12]= hi(M.CardDb);
				Rs232Vesz[4+0x13]= lo(M.CardDb);
				Rs232Vesz[4+0x17]= Ora.Ev;
				Rs232Vesz[4+0x18]= Ora.Ho;
				Rs232Vesz[4+0x19]= Ora.Nap;
				Rs232Vesz[4+0x1a]= Ora.Ora;
				Rs232Vesz[4+0x1b]= Ora.Perc;
				Rs232Vesz[4+0x1c]= Ora.Mp;
				for(i=4,sum=0; i<4+62; i++) sum+= Rs232Vesz[i];
				Rs232Vesz[4+0x3e]= lo(sum); Rs232Vesz[4+0x3f]= hi(sum);
				if(FlsPcWrCard(&Rs232Vesz[4]) == 0){ Rs232_Hiba(HIBA_BUSY); return; }//foglalt
				}
			break;
	case RW_CEG:												//Write Cég
			if((db != 128)||(M.CegDb >= (FLS_CEGMAX-FLS_CEGMIN)*2)){ Rs232_Hiba(HIBA_ADDR); return; }//rossz hossz
			else{
				Rs232Vesz[4+0x76]= hi(M.CegDb);
				Rs232Vesz[4+0x77]= lo(M.CegDb);
				Rs232Vesz[4+0x78]= Ora.Ev;
				Rs232Vesz[4+0x79]= Ora.Ho;
				Rs232Vesz[4+0x7a]= Ora.Nap;
				Rs232Vesz[4+0x7b]= Ora.Ora;
				Rs232Vesz[4+0x7c]= Ora.Perc;
				Rs232Vesz[4+0x7d]= Ora.Mp;
				for(i=4,sum=0; i<4+126; i++) sum+= Rs232Vesz[i];
				Rs232Vesz[4+0x7e]= lo(sum); Rs232Vesz[4+0x7f]= hi(sum);
				if(FlsPcWrCeg(&Rs232Vesz[4]) == 0){ Rs232_Hiba(HIBA_BUSY); return; }//foglalt
				}
			break;
	case RW_ARAK:												//Write Arak
			if((db != 32)||(M.ArakDb >= (FLS_ARAKMAX-FLS_ARAKMIN)*8)){ Rs232_Hiba(HIBA_ADDR); return; }//rossz hossz
			else{
				Rs232Vesz[4+0x16]= hi(M.ArakDb);
				Rs232Vesz[4+0x17]= lo(M.ArakDb);
				Rs232Vesz[4+0x18]= Ora.Ev;
				Rs232Vesz[4+0x19]= Ora.Ho;
				Rs232Vesz[4+0x1a]= Ora.Nap;
				Rs232Vesz[4+0x1b]= Ora.Ora;
				Rs232Vesz[4+0x1c]= Ora.Perc;
				Rs232Vesz[4+0x1d]= Ora.Mp;
				for(i=4,sum=0; i<4+30; i++) sum+= Rs232Vesz[i];
				Rs232Vesz[4+0x1e]= lo(sum); Rs232Vesz[4+0x1f]= hi(sum);
				if(FlsPcWrArak(&Rs232Vesz[4]) == 0){ Rs232_Hiba(HIBA_BUSY); return; }//foglalt
				}
			break;
	case RW_SZINT:												//Write szint tbl
			if(db != 124){ Rs232_Hiba(HIBA_ADDR); return; }		//rossz hossz
			else{
				cim= (uint16_t)Rs232Vesz[4]*256+Rs232Vesz[5];
				if(FlsPcWrSzint(&Rs232Vesz[6], cim) == 0){ Rs232_Hiba(HIBA_BUSY); return; }//foglalt
				}
			break;
	case RW_EEPROM:												//Write EEprom
			if(EEwrDb > 0){ Rs232_Hiba(HIBA_BUSY); return; }	//foglalt
			else{
				if(db == 0x6a){
					MemCpy(&EE.VezNum, &Rs232Vesz[4+2], 0x68);	//(x6a-2)bemásol VERZ nélkül
					EEwrCim= 0x02; EEwrDb= 0x68;
					}
				else if(db == 0x01){
					EE.SzorU11= Rs232Vesz[4];
					EEwrCim= 0x6a; EEwrDb= 1;
					}
				else if(db == 0x04){
					EE.SzorMa1= (uint16_t)Rs232Vesz[4]+(uint16_t)Rs232Vesz[5]*256;
					EE.NullMa1= (uint16_t)Rs232Vesz[6]+(uint16_t)Rs232Vesz[7]*256;
					EEwrCim= 0x6c; EEwrDb= 4;
					}
				else if(db == 0x05){
					EE.SzorMa2= (uint16_t)Rs232Vesz[4]+(uint16_t)Rs232Vesz[5]*256;
					EE.NullMa2= (uint16_t)Rs232Vesz[6]+(uint16_t)Rs232Vesz[7]*256;
					EEwrCim= 0x70; EEwrDb= 4;
					}
				else if(db == 0x06){
					EE.SzorMa3= (uint16_t)Rs232Vesz[4]+(uint16_t)Rs232Vesz[5]*256;
					EE.NullMa3= (uint16_t)Rs232Vesz[6]+(uint16_t)Rs232Vesz[7]*256;
					EEwrCim= 0x74; EEwrDb= 4;
					}
				else if(db == 0x07){
					EE.SzorMa4= (uint16_t)Rs232Vesz[4]+(uint16_t)Rs232Vesz[5]*256;
					EE.NullMa4= (uint16_t)Rs232Vesz[6]+(uint16_t)Rs232Vesz[7]*256;
					EEwrCim= 0x78; EEwrDb= 4;
					}
				else{ Rs232_Hiba(HIBA_ADDR); return; }			//rossz hossz (!csak páros lehet!)
				}
			break;
	case CLR_SECT:												//Clear flash sector
			if(db != 6+2){ Rs232_Hiba(HIBA_ADDR); return; }		//("CLRFLS"+cim.w)	rossz hossz
			else{
				if(MemCmp(&Rs232Vesz[4], FLS_CLR_STR, 6) != 0){ Rs232_Hiba(HIBA_ADDR); return; }//rossz tartalom
				else if(FlsPcBlkErase((uint16_t)Rs232Vesz[4+6]*256+Rs232Vesz[4+7]) == 0){ Rs232_Hiba(HIBA_BUSY); return; }//foglalt
				}
			break;
	case WR_PFLSPAR:											//Write Program Flash parancs
			if(db < 6){ Rs232_Hiba(HIBA_ADDR); return; }		//(par.w+page.w+cim.w)	rossz hossz
			else{
				par= (uint16_t)Rs232Vesz[4]*256+Rs232Vesz[5];
				pag= (uint16_t)Rs232Vesz[6]*256+Rs232Vesz[7];
				cim= (uint16_t)Rs232Vesz[8]*256+Rs232Vesz[9];
				switch(par){
					case 0x0101:	ReadLatch64_L(pag, cim); break;
					case 0x0201:	ReadLatch64_H(pag, cim);	break;

					case 0x0102:
					case 0x0202:	MemCpy((uint8_t*)FlsRow, &Rs232Vesz[10], 128); break;

					case 0x0103:	MemCpy((uint8_t*)&FlsRow[32], &Rs232Vesz[10], 128); WriteLatch64_L(pag, cim);	break;
					case 0x0203:	MemCpy((uint8_t*)&FlsRow[32], &Rs232Vesz[10], 128); WriteLatch64_H(pag, cim);	break;

					case 0x0104:	EraseFls_L(pag, cim); break;
					case 0x0204:	EraseFls_H(pag, cim); break;

					case 0x0105:	cim/= 256; cim+= (pag&0x0ff)<<8;
									if(Fls_ReadUpg256_L(cim) != 0){ Rs232_Hiba(HIBA_BUSY); return; }//cim256
									break;

					case 0x0109:	if((pag == 0x1234)&&(cim == 0x9876)){
										if(Fls_UpgradeStart_L() != 0){ Rs232_Hiba(HIBA_BUSY); return; }
										}
									else{ Rs232_Hiba(HIBA_ADDR); return; }
									break;

					case 0x0209:	if((pag == 0x4321)&&(cim == 0x6789)){
										if(Fls_UpgradeStart_H() != 0){ Rs232_Hiba(HIBA_BUSY); return; }
										}
									else{ Rs232_Hiba(HIBA_ADDR); return; }
									break;

					default:		Rs232_Hiba(HIBA_ADDR); return;		//rossz parancs
					}
				}
			break;
	case WR_FLS:												//Write Data Flash
			if(db < 5){ Rs232_Hiba(HIBA_ADDR); return; }		//(par.w+page.w+cim.w)	rossz hossz
			else{
				cim= (uint16_t)Rs232Vesz[4]*256+Rs232Vesz[5];
				alcim= Rs232Vesz[6];
		//		db=Rs232Vesz[7];
//ggg-v70		if((cim < FLS_UPGRMIN)||(cim > FLS_UPGRMAX)){ Rs232_Hiba(HIBA_ADDR); return; }
				if(cim > FLS_UPGRMAX){ Rs232_Hiba(HIBA_ADDR); return; }
				if(FlsPcWrUpgrade(&Rs232Vesz[8], cim, alcim) == 0){ Rs232_Hiba(HIBA_BUSY); return; }//foglalt
				}
			break;
	default:{ Rs232_Hiba(HIBA_ADDR); return; }					//rossz regiszter
	}
Rs232Ad[0]= 0xa5;
Rs232Ad[1]= 5;							//len-1
Rs232Ad[2]= 16;							//parancs
Rs232Ad[3]= mut;
ModBus_KiCrcCalc(Rs232Ad, 6);
Rs232_Init(6);
}
//=========================================================END
