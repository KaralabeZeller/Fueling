//-----------------------------------------------
// 240*64 grafikus LCD kezelõ rutinok
//-----------------------------------------------
#include <p33FJ128GP708a.h>
#include <stdint.h>
#include "Lcd.h"
//-----------------------------------------------belsõ változó
#define		LCD_RES				_LATD3			//PORTD3:	Lcd reset kimenet
#define		LCD_RD				_LATD4			//PORTD4:	Lcd RD' kimenet
#define		LCD_WR				_LATD5			//PORTD5:	Lcd WR' kimenet
#define		LCD_RS				_LATD6			//PORTD6:	Lcd RS kimenet
#define		LCD_CE				_LATD7			//PORTD7:	Lcd CE kimenet

#define		LCD_ADAT_BE_W		PORTD			//PORTD8..15:Lcd D0..7 bemenet
#define		LCD_ADAT_KI_W		LATD			//PORTD8..15:Lcd D0..7 kimenet
#define		TRIS_LCD_ADAT_W		TRISD
#define		OCD_LCD_ADAT_W		ODCD

#define		LCD_KI				0x0000			//minden bit KI
#define		LCD_BE				0xff00			//adatok be
//#define		LCD_OC				0xfff8			//open collector

uint8_t		LcdMem[32][64];						//32*64=2048 byte (32*8=256 * 64)
//-----------------------------------------------
void Lcd_PortBe(void)
{
LCD_RES=			0;		//reset
LCD_RD=				1;
LCD_WR=				1;
LCD_RS=				1;
LCD_CE=				1;
TRIS_LCD_ADAT_W=	LCD_BE;
//*** OCD_LCD_ADAT_W=		LCD_OC;
}
//-----------------------------------------------
void _LcdWrComm(uint16_t com)
{
LCD_ADAT_KI_W= (LCD_ADAT_KI_W & 0x00ff) | ((com<<8)&0xff00);
TRIS_LCD_ADAT_W= LCD_KI;				//adat kimenet
LCD_RS= 1;
LCD_RD= 1;
LCD_CE= 0;
LCD_WR= 0;
com++; com++; com++; com++;				//100ns
com++; com++; com++; com++;				//100ns
LCD_WR= 1;
LCD_CE= 1;
TRIS_LCD_ADAT_W= LCD_BE;				//adat bemenet
}
//-----------------------------------------------
void _LcdWrData(uint16_t dat)			//#31
{
LCD_ADAT_KI_W= (LCD_ADAT_KI_W & 0x00ff) | ((dat<<8)&0xff00);
TRIS_LCD_ADAT_W= LCD_KI;				//adat kimenet
LCD_RS= 0;
LCD_RD= 1;
LCD_CE= 0;
LCD_WR= 0;
dat++; dat++; dat++; dat++;				//100ns
dat++; dat++; dat++; dat++;				//100ns
LCD_WR= 1;
LCD_CE= 1;
TRIS_LCD_ADAT_W= LCD_BE;				//adat bemenet
}
//-----------------------------------------------
uint8_t _LcdRdStatusz(void)				//#32
{
uint16_t	be;

TRIS_LCD_ADAT_W= LCD_BE;				//adat bemenet
LCD_RS= 1;
LCD_WR= 1;
LCD_CE= 0;
LCD_RD= 0;
be=0; be++; be++; be++; be++; be++; be++;//150ns
be=0; be++; be++; be++; be++; be++;		//150ns
be= LCD_ADAT_BE_W;
LCD_RD= 1;
LCD_CE= 1;
return(be>>8);							//high
}
//-----------------------------------------------
void _Lcd_Stat01(void)
{
uint16_t	 i;
for(i=0; i<400; i++) if((_LcdRdStatusz()&0x03) == 0x03) break;//STA1=1 és STA0=1
}
//-----------------------------------------------
void _Lcd_Stat3(void)					//#14
{
uint16_t	i;
for(i=0; i<400; i++) if((_LcdRdStatusz()&0x08) == 0x08) break;//STA3=1
}
//-----------------------------------------------
void _Lcd_Utasitas(uint16_t ut)
{
_Lcd_Stat01();	_LcdWrComm(ut);
}
//-----------------------------------------------
void _Lcd_Utasitas2(uint16_t ut, uint16_t hi, uint16_t lo)
{
_Lcd_Stat01();	_LcdWrData(lo);
_Lcd_Stat01();	_LcdWrData(hi);
_Lcd_Stat01();	_LcdWrComm(ut);
}
//-----------------------------------------------;=27	utasitas=a use:y,b,T
void _Lcd_AdatKi(uint16_t dat)
{
_Lcd_Stat3();	_LcdWrData(dat);	//#67-1,7us
}
//-----------------------------------------------
void Lcd_Init(void)
{
uint16_t	i;

LCD_RES= 0; for(i=0; i<2000; i++);	//2000*4/40=200us
LCD_RES= 1; for(i=0; i<2000; i++);	//2000*4/40=200us
_Lcd_Utasitas(0x90);				//Lcd off
_Lcd_Utasitas2(0x42, 0x00, 0x00);	//Graphics home address set 0,0
_Lcd_Utasitas2(0x43, 0x00, 0x20);	//32 oszlop	Graphics area set
_Lcd_Utasitas(0x89);				//XOR mode, external CG RAM set
_Lcd_Utasitas(0x98);				//Lcd mode set graphic
}
//-----------------------------------------------
void Lcd_Kimasol(void)
{
uint16_t		x, y;

_Lcd_Utasitas(0xb2);				//auto mode reset
_Lcd_Utasitas2(0x24,0x00,0x00);		//Address pointer set 0,0
_Lcd_Utasitas(0xb0);				//auto write enable
_Lcd_Stat01();
for(y=0; y<64; y++)
	for(x=0; x<32; x++)
		_Lcd_AdatKi(LcdMem[x][y]);	//x-y csere
_Lcd_Stat3();
_Lcd_Utasitas(0xb2);				//auto mode reset
}
//-----------------------------------------------
void Lcd_Clear(void)
{
uint16_t		x, y;
for(x=0; x<32; x++)
	for(y=0; y<64; y++)
		LcdMem[x][y]= 0;
}
//-----------------------------------------------
void PutPixel(uint16_t x, uint16_t y, char color)
{
if((x < 240)&&(y < 64)){
//	Byte		minta= 0x80>>(x&0x07),	px=x>>3,		py=y;		//egyenes
	uint8_t		minta= 0x01<<(x&0x07);
	uint16_t	px= (239-x)>>3,	py= (63-y);	//fordított
	if(color != 0)	LcdMem[px][py]|= minta;
	else			LcdMem[px][py]&= 0xff-minta;
	}
}
//===============================================END
