//=========================================================
// BVEZ2 vezérlõ (dsPIC33GP708-8Mhz)
//=========================================================
#include "asmFlash.h"
#include "Bvez2.h"
#include "Lcd.h"
#include "OraKorr.h"
#include "SorosMod232.h"
#include "SorosModNet.h"
#include "Sflash16M.h"
#include "GyorsGra.h"
//=========================================================Configuration bits
//-----FBS----------[b7.6=RBS; b3.2=BSS; b0=BWRP]
//-----FSS----------[b7.6=RSS; b3.2=SSS; b0=SWRP]
//-----FGS----------[b2.1=GSS; b0=GWRP]
//#pragma config	GSS=		OFF		//General Segment Code-Protect bit (General Segment Code protect is Disabled)
//				GCP=		ON		//1= General Segment Code protection Enabled  
//				GCP=		OFF		//0= General Segment Code protect is Disabled  
//#pragma config	GWRP=		OFF		//General Segment Write-Protect bit (General Segment may be written)
//				GWRP=		ON		//1= General Segment is write protected  
//				GWRP=		OFF		//0= General Segment may be written  
//-----FOSCSEL------[b7=IESO; b2.0=FNOSC]
#pragma config	IESO=		OFF		//Two-speed Oscillator Start-up Enable bit (Start up with user-selected oscillator source)
//				IESO=		OFF		//0= Start up with user-selected oscillator source
//				IESO=		ON		//1= Start up device with FRC, then switch to user-selected oscillator source
#pragma config	FNOSC=		FRC		//Oscillator Source Selection (Internal Fast RC (FRC))
//				FNOSC=		FRC		//000= Internal Fast RC (FRC)  
//				FNOSC=		FRCPLL	//001= Fast RC Oscillator with divide-by-N with PLL module (FRCPLL)  
//				FNOSC=		PRI		//010= Primary Oscillator (XT, HS, EC)  
//				FNOSC=		PRIPLL	//011= Primary Oscillator with PLL module (XT + PLL, HS + PLL, EC + PLL)  
//				FNOSC=		LPRC	//101= Low-Power RC Oscillator (LPRC)  
//				FNOSC=		FRCDIVN	//111= Internal Fast RC (FRC) Oscillator with postscaler  
//-----FOSC---------[b7.6=FCKSM; b2=OSCIOFNC; b1.b0=POSCMD]
#pragma config	FCKSM=		CSECMD	//Clock Switching Mode bits (Clock switching is enabled,Fail-safe Clock Monitor is disabled)
//				FCKSM=		CSECME	//00= Both Clock switching and Fail-safe Clock Monitor are enabled  
//				FCKSM=		CSECMD	//01= Clock switching is enabled,Fail-safe Clock Monitor is disabled  
//				FCKSM=		CSDCMD	//1x= Both Clock switching and Fail-safe Clock Monitor are disabled  
#pragma config	OSCIOFNC=	OFF		//OSC2 Pin Function bit (OSC2 is clock output)
//				OSCIOFNC=	ON		//0= OSC2 is general purpose digital I/O pin  
//				OSCIOFNC=	OFF		//1= OSC2 is clock output  
#pragma config	POSCMD=		XT		//Primary Oscillator Mode Select bits (Primary Oscillator disabled)
//				POSCMD=		EC		//00= EC (External Clock) Mode  
//				POSCMD=		XT		//01= XT Crystal Oscillator Mode  
//				POSCMD=		HS		//10= HS Crystal Oscillator Mode  
//				POSCMD=		NONE	//11= Primary Oscillator disabled  
//-----FWDT---------[b7=FWDTEN; b6=WINDIS; b5=PLLKEN; b4=WDTPRE; b3.0=WDTPOST]
#pragma config	FWDTEN=		ON//OFF		//Watchdog Timer Enable bit (Watchdog timer enabled/disabled by user software)
//				FWDTEN=		OFF		//0= Watchdog timer enabled/disabled by user software  
//				FWDTEN=		ON		//1= Watchdog timer always enabled  
#pragma config	WINDIS=		OFF		//Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode)
//				WINDIS=		ON		//0= Watchdog Timer in Window mode  
//				WINDIS=		OFF		//1= Watchdog Timer in Non-Window mode  
#pragma config	WDTPRE=		PR128	//Watchdog Timer Prescaler bit (1:128) 32000Hz/128=250
//				WDTPRE=		PR32	//0=  1 : 32  
//				WDTPRE=		PR128	//1=  1 : 128  
#pragma config	WDTPOST=	PS512	//52ms-Watchdog Timer Postscaler bits (1:32,768)
//				WDTPOST=	PS1		//0000= 1 : 1  
//				WDTPOST=	PS2		//0001= 1 : 2  
//				WDTPOST=	PS16384	//1110= 1 : 16,384  
//				WDTPOST=	PS32768	//1111= 1 : 32,768  
//-----FPOR---------[b1.0=FPWRT; ]
#pragma config	FPWRT=		PWR128	//128ms power on timer
//-----FICD---------[b7=1; b5=JTAGEN; b1.0=ICS]
#pragma config	JTAGEN=		OFF		//JTAG Enable bit (JTAG is disabled)
//				JTAGEN=		OFF		//0= JTAG is disabled  
//				JTAGEN=		ON		//1= JTAG is enabled  
#pragma config	ICS=		PGD2	//ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1)
//				ICS=		NONE	//00= Reserved, do not use  
//				ICS=		PGD3	//01= Communicate on PGEC3 and PGED3  
//				ICS=		PGD2	//10= Communicate on PGEC2 and PGED2  
//				ICS=		PGD1	//11= Communicate on PGEC1 and PGED1  
//=========================================================Upgrade
// FLASH:
//	0x000000 - 0x0157fe = 128kbyte Flash
//	0x000000 - GOTO reset
//	0x000002 - RESET address
//	0x000004 - Vector table
//	0x000104 - Alternate Vector table
//	0x000200 - user program 44k instruction
//	0x015800 - read as '0'
//	0xf80000 - device config. regs.
//	0xff0000 - device ID(2)
//
// 1 row = 64 instuction = 192 byte (0x0080.w)
// 1 page = 8 row = 512 insturction = 1536 byte (ERASE) (0x0400.w)
//-----------------------------------------------
// RAM:
//	0x000000 - 0x0007ff =  2kbyte SFR
//	0x000000 - 0x001fff =  8kbyte NEAR DATA SPACE
//	0x000800 - 0x0047ff = 16kbyte RAM
//	0x004000 - 0x0047ff =  2kbyte DMA RAM dual port
//	0x800000 - 0xffffff = 16kbyte FLASH MAPPED to RAM
//-----------------------------------------------PAGE0
const uint16_t		__attribute__ ((space(psv), address (0x0200))) Verzio_L= C_VERZ;
const uint32_t		__attribute__ ((space(psv), address (0x0202))) ChkSum_L= 0x123456;
//-----------------------------------------------
const uint16_t		__attribute__ ((space(psv), address (0x015000))) Verzio_H= C_VERZ;
const uint32_t		__attribute__ ((space(psv), address (0x015002))) ChkSum_H= 0x123456;
//-----------------------------------------------
uint32_t			__attribute__ ((address (0x0800))) FlsRow[64];		//64db utasítás = 256byte
//===============================================Munka változók
uint8_t				SYS_A100MS= 0;			//-	system timer - 100ms alap rutin mehet

uint16_t			LedProcTime= 1000;		//*1ms	kezdeti felvillanás
uint16_t			LedVezTime= 2000;
uint16_t			LedHibaTime= 3000;
uint16_t			LedProcTilt= 4;			//*1s Rendben led villogás tiltva

uint16_t			KijelVedo;				//(*0,1s) kijelzõ védõ vár
uint16_t			KijelReset;				//(*0,1s) kijelzõ védõ után ennyivel resetel

uint8_t				Str[STR_MAXLEN];		//String változó szövegeléshez
//===============================================OnChip RAM
struct struRx		Rxb, Rxc, Rxd, Rxf;

struct struMem		M;

struct StruOra		Ora;					//16b
struct StruPrn		Prn;					//69b

struct MENU_Stru	Mnu;					//87b

struct CARD_Stru	Card;					//35b
struct SZINT_Stru	Szint[2];
struct CEG_Stru		Ceg0;
struct ARAK_Stru	Arak0;

struct KUT_Stru		Kut[KUTFO_DB];
struct TANK_Stru	Tank[KUTFO_DB];
struct EEPROM_Stru	EE;
uint8_t				EEwrCim, EEwrDb;			//ciklikus íráshoz mutatók

struct StruNet		Net;					//46b
//-----------------------------------------------
void 	Menu_100ms(void);
void 	Alap_1perc(void);
//===============================================
void PortKezdoertekek(void)
{
AD1PCFGH=			0xffff;
AD1PCFGL=			0xffff;
AD2PCFGL=			0xffff;

LED_HIBA=			1;		TRIS_LED_HIBA=		TRIS_KI;
LED_PROC=			1;		TRIS_LED_PROC=		TRIS_KI;
LED_VEZ=			1;		TRIS_LED_VEZ= 		TRIS_KI;

TRIS_GOMB_BE1= 		TRIS_BE;
TRIS_GOMB_BE2= 		TRIS_BE;
TRIS_GOMB_BE3= 		TRIS_BE;
TRIS_GOMB_BE4= 		TRIS_BE;
GOMB_KI1=			1;		TRIS_GOMB_KI1= 		TRIS_KI;
GOMB_KI2=			1;		TRIS_GOMB_KI2= 		TRIS_KI;
GOMB_KI3=			1;		TRIS_GOMB_KI3= 		TRIS_KI;

//SPK=				0;
LCD_HATTER=			0;		TRIS_LCD_HATTER=	TRIS_KI;
//LCD_KONTR=		1;

RS_TXB=				1;		TRIS_RS_TXB= 		TRIS_KI;
RS_TXC=				1;		TRIS_RS_TXC= 		TRIS_KI;
RS_TXD=				1;		TRIS_RS_TXD= 		TRIS_KI;
RS_TXE=				1;		TRIS_RS_TXE= 		TRIS_KI;
RS_TXF=				1;		TRIS_RS_TXF= 		TRIS_KI;

Lcd_PortBe();
ORA_PinInit();
}
//-----------------------------------------------Alap
void Beeper_Init(void)			//Initialize Output Compare Module
{
OC1CONbits.OCM= 0b000;			//Disable Output Compare Module
OC1R=0;							//Write the duty cycle for the first PWM pulse
OC1RS=0;						//Write the duty cycle for the second PWM pulse
OC1CONbits.OCTSEL= 1;			//Select Timer 3 as output compare time base
OC1CONbits.OCM= 6;				//110=PWM mode without fault protection. PWM mode on OCx, Fault pin is disabled
}
//-----------------------------------------------Alap
void Kontraszt_Init(void)		//Initialize Output Compare Module
{
OC3CONbits.OCM= 0b000;			//Disable Output Compare Module
OC3R=251;						//Write the duty cycle for the first PWM pulse
OC3RS=251;						//Write the duty cycle for the second PWM pulse
OC3CONbits.OCTSEL= 1;			//Select Timer 3 as output compare time base
OC3CONbits.OCM= 6;				//110=PWM mode without fault protection. PWM mode on OCx, Fault pin is disabled
}
//-----------------------------------------------Alap
void ADC_Init(void)
{
AD1CON1bits.ADON= 0;			//turn ADC Off

AD1CON1bits.AD12B= 1;			// 12bit
AD1CON1bits.FORM= 0;			// unsigned int
AD1CON1bits.SSRC= 7;			// Interan Counter (SAMC) ends sampling and starts convertion
AD1CON1bits.ASAM= 0;			// ADC Sample Control: Sampling manually

//AD1CON2bits.VCFG= 0;			// Voltage reference = AVDD-AVSS
//AD1CON2bits.CSCNA= 0;			// Scan Input: not scan
//AD1CON2bits.CHPS= 0;			// Converts only CH0
//AD1CON2bits.SMPI= 0;			// DMA increment rate
AD1CON2= 0;

AD1CON3bits.ADRC= 0;			// ADC Clock is derived from Systems Clock
AD1CON3bits.SAMC= 31; 			// (0-31) Auto Sample Time = 31*Tad (7,8u)
AD1CON3bits.ADCS= (10-1);	    // (0-255) ADC Conversion Clock Tad=Tcy*(ADCS+1)= (1/40M)*10 = 250ns (min.118ns)
								// ADC Conversion Time for 12-bit Tc=14*Tad = 3,5us (min.2us)
AD1CON4= 0;						// 1 word/channel DMA

//AD1CHS0bits.CH0NA= 0;			// MUXA - input selection (Vref-) for CH0
//AD1CHS0bits.CH0SA= ANAH_XP;	// MUXA + input selection (AIN0) for CH0
//***AD1CHS0= ANA_XM;
 
AD1CSSH= 0;
AD1CSSL= 0;
AD1PCFGH= ANA_INITH;
AD1PCFGL= ANA_INITL;
IFS0bits.AD1IF= 0;				// Clear the A/D interrupt flag bit
IEC0bits.AD1IE= 0;				// Do Not Enable A/D interrupt 
AD1CON1bits.ADON= 1;			// Turn on the A/D converter	
}
//-----------------------------------------------EEPROM betöltés
void	EepromBetoltes()
{
uint8_t		b, i;
uint16_t	w;

//w= (Word)EEprom_olv(0x00)*256+EEprom_olv(0x01);		//x00		0x0001=alap
//EE.VERZ= w;

b= EEprom_olv(0x02);									//x02		vezérlõ sorszáma
if(b == 0xff) b= 0x01;			//elsõ
EE.VezNum= b;

b= EEprom_olv(0x03);									//x03		Vez=Vezérlõ státusza
EE.Vez= b;

b= EEprom_olv(0x04);									//x04		Kijelzõ kontraszt			[0x50]
if(b == 0xff) b= LCD_KONTRASZT;	//elsõ
EE.KontReg= b;

b= EEprom_olv(0x05);									//x05	 	Kijelzõ kontraszt kompenzáció
if(b == 0xff) b= 0;				//elsõ
EE.KontKomp= b;
	
w= (uint16_t)EEprom_olv(0x07)*256+EEprom_olv(0x06);			//x06		1.hõmérés szorzó
if(w > 40000) w= MUL_HOM1;		//elsõ
EE.Ho1Szor= w;

w= (uint16_t)EEprom_olv(0x09)*256+EEprom_olv(0x08);			//x08		1.hõmérés nulla
if(w > 30000) w= 1;				//elsõ
EE.Ho1Offs= w;

w= (uint16_t)EEprom_olv(0x0b)*256+EEprom_olv(0x0a);			//x0a		2.hõmérés szorzó
if(w > 40000) w= MUL_HOM2;		//elsõ
EE.Ho2Szor= w;

w= (uint16_t)EEprom_olv(0x0d)*256+EEprom_olv(0x0c);			//x0c		2.hõmérés nulla
if(w > 30000) w= 1;				//elsõ
EE.Ho2Offs= w;

//w= (Word)EEprom_olv(0x0f)*256+EEprom_olv(0x0e);		//x0e	b15(H+,L-) &0x7fff percenként +-1mp (0=semmi)
//EE.TimeKomp= w;
b= EEprom_olv(0x0e);									//x0e		Vez2=Vezérlõ státusza
EE.Vez2= b;
b= EEprom_olv(0x0f);									//x0f		Crosspoint olvasó címe
EE.CrossPointCim= b;

for(i=0; i<KUTFO_DB; i++){								//x10		15 kútfõ státusza (b0=ki/be)
	b= EEprom_olv(0x10+i);	if(b == 0xff) b= 0;			//b0[0-Kikapcsolva,1-Alaphelyzet] b1[0-Gázolaj,1-Benzin] b2[0-normál,1-virtuális]
	EE.KutStat[i]= b;
	}

b= EEprom_olv(0x20);									//x20		Menü timeot (1-254,0v.255=no)
EE.MnuTimeout= b;

b= EEprom_olv(0x21);									//x21		*1s menü utánvilágítás tankolás végén (0-254s, 255=állandó)
EE.MnuUtoTime= b;

b= EEprom_olv(0x22);									//x22	(x87)1-régi,2-új,3 új(HEX),4-x1,10c,x2,5-mifare,6-CARD_CROSSPOINT,7-BCD[#+10]
EE.CardReaderTipe= b;

b= EEprom_olv(0x23);	if((b < 1)||(b >= KUTFO_DB)) b= 0;//x23(0-14)	[1-14] melyik kútfohöz tartozik a pisztoly 1
EE.Pisztoly1= b;

b=EEprom_olv(0x24);		if(b > 1) b=0;					//x24		0-magyar,1-angol
EE.Nyelv= b;

b=EEprom_olv(0x60);		if(b > 9) b=1;					//x60		nyomtatáshoz példányszám (0-2,9)
EE.PrnDb= b;

w= (uint16_t)EEprom_olv(0x63)*256+EEprom_olv(0x62);			//x62		Szint1 gyáriszám
EE.Szint1= w;
w= (uint16_t)EEprom_olv(0x65)*256+EEprom_olv(0x64);			//x64		Szint1Kut
EE.Szint1Kut= w;

w= (uint16_t)EEprom_olv(0x67)*256+EEprom_olv(0x66);			//x66		Szint2 gyáriszám
EE.Szint2= w;
w= (uint16_t)EEprom_olv(0x69)*256+EEprom_olv(0x68);			//x68		Szint2Kut
EE.Szint2Kut= w;

w= (uint16_t)EEprom_olv(0x5d)*256+EEprom_olv(0x5c);			//x5c		Szint3Kut
EE.Szint3Kut= w;
w= (uint16_t)EEprom_olv(0x5f)*256+EEprom_olv(0x5e);			//x5e		Szint4Kut
EE.Szint4Kut= w;

b= EEprom_olv(0x6a);									//x6a
EE.SzorU11= b;

w= (uint16_t)EEprom_olv(0x6d)*256+EEprom_olv(0x6c);			//x6c		SzorMa1
EE.SzorMa1= w;
w= (uint16_t)EEprom_olv(0x6f)*256+EEprom_olv(0x6e);			//x6e		NullMa1
EE.NullMa1= w;
w= (uint16_t)EEprom_olv(0x71)*256+EEprom_olv(0x70);			//x70		SzorMa2
EE.SzorMa2= w;
w= (uint16_t)EEprom_olv(0x73)*256+EEprom_olv(0x72);			//x72		NullMa2
EE.NullMa2= w;
w= (uint16_t)EEprom_olv(0x75)*256+EEprom_olv(0x74);			//x70		SzorMa3
EE.SzorMa3= w;
w= (uint16_t)EEprom_olv(0x77)*256+EEprom_olv(0x76);			//x72		NullMa3
EE.NullMa3= w;
w= (uint16_t)EEprom_olv(0x79)*256+EEprom_olv(0x78);			//x70		SzorMa4
EE.SzorMa4= w;
w= (uint16_t)EEprom_olv(0x7b)*256+EEprom_olv(0x7a);			//x72		NullMa4
EE.NullMa4= w;
}
//===============================================Reset
int			main(void)
{
int			i;

KijelVedo= C_KIJEL_VEDO; KijelReset= C_KIJEL_RESET;

M.Gyari= C_GYARI; M.Szoftver= C_VERZ;
M.TankDb= 0; M.CardDb= 0; M.CegDb= 0; M.ArakDb= 0;
M.InputBe= 0; M.GombBe= 0; M.Gomb= GOMB_NO;
M.SpkTim= 0; Mnu.Villog= 0;
M.LcdInitTime= LCD_INIT_TIME-1;		//1s múlva LCD init
M.AdHibaNemkesz= 0;
//IntHo3= 0x1800						//kontraszt felhúzás

Rxb.Tim= 0; Rxb.Faz= 0; Rxb.VanVett= 0; Rxb.Byte= 0; Rxb.Vett= 0;
Rxc.Tim= 0; Rxc.Faz= 0; Rxc.VanVett= 0; Rxc.Byte= 0; Rxc.Vett= 0;
Rxd.Tim= 0; Rxd.Faz= 0; Rxd.VanVett= 0; Rxd.Byte= 0; Rxd.Vett= 0;
Rxf.Tim= 0; Rxf.Faz= 0; Rxf.VanVett= 0; Rxf.Byte= 0; Rxf.Vett= 0;

Card.Rx1Pos= 0; Card.Rx2Pos= 0; Card.RxTim100m= 0;
Card.PiDb= 0; Card.PiTim100m= 0;
M.NetMehet= 0;

PortKezdoertekek();
Timer2InterruptInit();
Timer3InterruptInit();
Timer4InterruptInit();
Timer6InterruptInit();
asm("clrwdt");
TimerPllStart();

Beeper_Init();
Kontraszt_Init();
Ora_Init();
UART1_Init();						//PC soros
UART2_Init();						//Kútfõ soros
ADC_Init();							//hõmérõk,mA és tápfeszek
SPI2_Init();						//Flash

Delay_Ms_Alap(10);					//10ms pihi
Ora_Cikl_100m();					//óra elsõ kiolvasás
EepromBetoltes();
Lcd_Init();
Lcd_Clear();
Lcd_Kimasol();

VarFlsRdID_Alap(0x0000); MemCpy(M.FlsId1, Fls.Sys.Be, 3);
VarFlsRdID_Alap(0x8000); MemCpy(M.FlsId2, Fls.Sys.Be, 3);
Tank_SrcUres();
Card_SrcUres();
Ceg_SrcUres();
Arak_SrcUres();
SzintTbl_Load();
Mnu.Back= MENU_A1; ScrS9_kirak();
for(i=0; i<KUTFO_DB; i++) Kut[i].Hiba= 10;
M.NetMehet= 1;
//===============================================Alap
while(1) {
	if(SYS_A100MS > 0){//------------------------100ms-nem pontos
		SYS_A100MS= 0;
		Ora_Cikl_100m();

		if(Ora.Sys_MP > 0){//---------------------1s-nem pontos
			Ora.Sys_MP= 0;

//			Homer_1s();
			if(M.LcdInitTime < LCD_INIT_TIME) M.LcdInitTime++;
			else{
				M.LcdInitTime= 0;
				Lcd_Init();
				}

			if(Ora.Sys_PERC > 0){//---------------1p-nem pontos
				Ora.Sys_PERC= 0;
				}
			if(LedProcTilt > 0)	LedProcTilt--;
			else				LedProcTime= LED_1MP;
			}		
		Menu_100ms();
		}	
	//-------------------------------------------Alap ráérõs (megakasztja a többi Alapot)
	if(Prn.Foglalt == 0){				//ready
		for(i=0; i<KUTFO_DB; i++){
			if(Tank[i].Nyomtat > 0){	//van mit
				Tank[i].Nyomtat--;		//egy példány ki
				Tank_nyomtat(i);
				i= 30;					//majd a következõ körben
				}
			}
		}
	}
}
//-----------------------------------------------Alap-100ms
void	Menu_100ms(void)
{
switch(Mnu.Num){
	case MENU_RESET:ScrA1_kirak(); break;		//bekapcsolásnál 100ms késleltetés
	case MENU_A0:	ScrA0_esemeny(); break;		//Szintek
	case MENU_A1:	ScrA1_esemeny(); break;		//Kútszámok + cégnév
	case MENU_A2:	ScrA2_esemeny(); break;		//Státusz kijelzés
	case MENU_A3:	ScrA3_esemeny(); break;		//Kártya bevitel
	case MENU_A4:	ScrA4_esemeny(); break;		//Km óra bevitel
	case MENU_A5:	ScrA5_esemeny(); break;		//Menetlevél bevitel
	case MENU_A6:	ScrA6_esemeny(); break;		//Tankolhat
	case MENU_A7:	ScrA7_esemeny(); break;		//Üzemóra bevitel
	case MENU_A8:	ScrA8_esemeny(); break;		//Mester kártya bevitel
	case MENU_A9:	ScrA9_esemeny(); break;		//Sofor kód bevitel
	case MENU_A10:	ScrA10_esemeny(); break;	//Mennyiség bevitel
	case MENU_Astop: ScrAstop_esemeny(); break;	//MaxStop bevitel

	case MENU_H1:	ScrH1_esemeny(); break;		//Kártya hiba
	case MENU_H2:	ScrH2_esemeny(); break;		//Tankolásszám kimerítve
	case MENU_H3:	ScrH3_esemeny(); break;		//Kártya-kútfõ hiba

	case MENU_S1:	ScrS1_esemeny(); break;		//Szervizkártya bekérés
	case MENU_S2:	ScrS2_esemeny(); break;		//Szerviz fõmenü
	case MENU_S3:	ScrS3_esemeny(); break;		//Szerviz kútfõ
	case MENU_S4:	ScrS4_esemeny(); break;		//Szerviz kártyák
	case MENU_S5:	ScrS5_esemeny(); break;		//Szerviz beállítások
	case MENU_S6:	ScrS6_esemeny(); break;		//Szerviz beállítás-literkijelzés
	case MENU_S7:	ScrS7_esemeny(); break;		//Szerviz beállítás-kontraszt
	case MENU_S8:	ScrS8_esemeny(); break;		//Szerviz testre szabás
	case MENU_S9:	ScrS9_esemeny(); break;		//Szerviz változók
	case MENU_S10:	ScrS10_esemeny(); break;	//Szerviz rendszer
	case MENU_S11:	ScrS11_esemeny(); break;	//Szerviz-Beállítások-Idõk

	default:		ScrA1_kirak(); break;		//para
	}	
/*
if(KijelVedo > 0){
	KijelVedo--;
	SetHatter(100);
	}
else{
	SetHatter(20);
	if(KijelReset > 0) KijelReset--;
	else{
		LCD_ResetDevice();
		KijelReset=C_KIJEL_RESET;
		}
	}
*/
Lcd_Kimasol();
LCD_HATTER= 1;
}
//-----------------------------------------------
void	CardId_to_Str14(void)
{
Byte_to_02x(&Str[ 0], Card.Id[0]);
Byte_to_02x(&Str[ 2], Card.Id[1]);
Byte_to_02x(&Str[ 4], Card.Id[2]);
Byte_to_02x(&Str[ 6], Card.Id[3]);
Byte_to_02x(&Str[ 8], Card.Id[4]);
Byte_to_02x(&Str[10], Card.Id[5]);
Byte_to_02x(&Str[12], Card.Id[6]);
}
//-----------------------------------------------
void	CardNev_to_LCD(uint8_t *strbe, uint8_t x, uint8_t y)
{
uint8_t	i;
for(i=0; i<20; i++) Str[i]= strbe[i];
OutStr1(20, x, y);
}
//------------------------------------------------
/*void NullaOlt(char *str, Byte db)
{
int	i;
for(i=0; i<db; i++){
	if(str[i]=='0') str[i]=' ';
	else break;
	}	
}*/
//------------------------------------------------
/*void Hom_to_3p1Fok(Word hom)
{
//sprintf(Str,"%04i",hom); NullaOlt(Str,2);
Str[4]=Str[3];
Str[3]='.';
Str[5]='°';//chr_fok;
Str[6]=0;
}*/
//-----------------------------------------------
void	Byte_to_2i(uint8_t *ki, uint8_t be)
{
uint8_t		bh= (be/10);
be%= 10;
bh+= '0'; be+= '0';
if(bh == '0') ki[0]= ' '; else ki[0]= bh;
ki[1]= be;
}
//-----------------------------------------------
void	Byte_to_02i(uint8_t *ki, uint8_t be)
{
uint8_t		bh= (be/10);
be%= 10;
bh+= '0'; be+= '0';
ki[0]= bh; ki[1]= be;
}
//-----------------------------------------------
void	Byte_to_02x(uint8_t *ki, uint8_t be)
{
uint8_t		beh= be/16, bel= be&0x0f;
if(beh > 9) beh+= 7; //'0'=x30 'A'=x41
if(bel > 9) bel+= 7;
ki[0]= beh+'0';
ki[1]= bel+'0';
}
//-----------------------------------------------
void	Byte_to_03i(uint8_t *ki, uint8_t be)
{
uint8_t		b[3];
b[0]= be/100;	be%= 100;
b[1]= be/10;	b[2]= be%10;
ki[0]= b[0]+'0'; ki[1]= b[1]+'0'; ki[2]= b[2]+'0';
}
//-----------------------------------------------
void	Byte_to_3i(uint8_t *ki, uint8_t be)
{
Byte_to_03i(ki, be);
if(ki[0] == '0'){
	ki[0]= ' ';
	if(ki[1] == '0') ki[1]= ' ';
	}
}
//------------------------------------------------
void	Word_to_05i(uint8_t *ki, uint16_t be)
{
uint8_t	b[5];
b[0]= be/10000;	be%= 10000;
b[1]= be/1000;	be%= 1000;
b[2]= be/100;	be%= 100;
b[3]= be/10;	b[4]= be%10;
ki[0]= b[0]+'0'; ki[1]= b[1]+'0'; ki[2]= b[2]+'0';
ki[3]= b[3]+'0'; ki[4]= b[4]+'0';
}
//------------------------------------------------
void	Word_to_5i(uint16_t be)
{
Word_to_05i(Str, be);
if(Str[0] == '0'){ Str[0]= ' ';
	if(Str[1] == '0'){ Str[1]= ' ';
		if(Str[2] == '0'){ Str[2]= ' ';
			if(Str[3] == '0') Str[3]= ' ';
			}
		}
	}
}
//------------------------------------------------
void	Word_5i_xy(uint16_t be, uint8_t x, uint8_t y)
{
Word_to_5i(be); OutStr1(5, x, y);
}
//------------------------------------------------
void	Dword_to_10i2(uint8_t *ki, uint32_t be)//AR_MAX=660000000*0,01=660Ft*10000l=6,6mFt
{
uint16_t	wl, wh, wh2;
uint32_t	dwh;

dwh=	be/10000;
wh2=	dwh/10000;
wh=		dwh%10000;
wl=		be%10000;

if(wh2 < 10){
	ki[0]= wh2+'0';

	ki[4]= (wh%10)+'0';	wh/= 10;
	ki[3]= (wh%10)+'0'; wh/= 10;
	ki[2]= (wh%10)+'0';			
	ki[1]= (wh/10)+'0';			

	ki[8]= (wl%10)+'0'; wl/= 10;
	ki[7]= (wl%10)+'0';	wl/= 10;
	ki[6]= (wl%10)+'0';
	ki[5]= (wl/10)+'0';			
	}
else{
	ki[0]= '9';
	ki[1]= '9';	ki[2]= '9';	ki[3]= '9';	ki[4]= '9';
	ki[5]= '9';	ki[6]= '9';	ki[7]= '9';	ki[8]= '9';
	}
ki[10]= 0; ki[9]= ki[8]; ki[8]= ki[7]; ki[7]= '.';
}
//------------------------------------------------
void	Dword_to_08itp(uint8_t *ki, uint32_t be, uint8_t tp)
{
uint16_t	wl, wh;

if(be < 100000000l){
	wl= be%10000;
	wh= be/10000;
				ki[7]= (wl%10)+'0';
	wl/= 10;	ki[6]= (wl%10)+'0';			
	wl/= 10;	ki[5]= (wl%10)+'0';			
	wl/= 10;	ki[4]= wl+'0';			
				ki[3]= (wh%10)+'0';
	wh/= 10;	ki[2]= (wh%10)+'0';			
	wh/= 10;	ki[1]= (wh%10)+'0';			
	wh/= 10;	ki[0]= wh+'0';
	}
else{
	ki[0]= '9'; ki[1]= '9'; ki[2]= '9'; ki[3]= '9';
	ki[4]= '9'; ki[5]= '9'; ki[6]= '9'; ki[7]= '9';
	}
ki[8]= 0; ki[9]= 0;
if		(tp == 1){ ki[8]= ki[7]; ki[7]= '.'; }
else if	(tp == 2){ ki[8]= ki[7]; ki[7]= ki[6]; ki[6]= '.'; }
}
//------------------------------------------------
void	Dword_08itp_xy(uint32_t be, uint8_t tp, uint8_t x, uint8_t y, uint8_t size)
{
Dword_to_08itp(Str, be, tp);
if		(size == 3)	OutStr3(9, x, y);
else if	(size == 2)	OutStr2(9, x, y);
else				OutStr1(9, x, y);
}
//------------------------------------------------
void	Dword_8itp_xy(uint32_t be, uint8_t tp, uint8_t x, uint8_t y, uint8_t size)
{
Dword_to_08itp(Str, be, tp);
if(Str[0] == '0'){ Str[0]= ' ';				//nulla olt
	if(Str[1] == '0'){ Str[1]= ' ';
		if(Str[2] == '0'){ Str[2]= ' ';
			if(Str[3] == '0'){ Str[3]= ' ';
				if(Str[4] == '0'){ Str[4]= ' ';
					if(Str[5] == '0'){ Str[5]= ' ';
						if(Str[6] == '0'){ Str[6]= ' ';
	}	}	}	}	}	}	}
if		(tp == 2){
	if(Str[5] == ' ') Str[5]= '0';
	if(Str[6] == ' ') Str[6]= '0';
	}
else if	(tp == 1){
	if(Str[6] == ' ') Str[6]= '0';
	}

if		(size == 3)	OutStr3(9, x, y);
else if	(size == 2)	OutStr2(9, x, y);
else				OutStr1(9, x, y);
}
//------------------------------------------------
/*
void Word_to_3p1Sec(Word num)
{
//sprintf(Str,"%04i",num); NullaOlt(Str,2);
//Str[4]=Str[3];
Str[3]='.';
Str[5]='s';
Str[6]=0;
}*/
//-----------------------------------------------Alap
/*void BCD4_to_Str(char *str,Byte *bcd)
{
str[0]=bcd[0]/16;
str[1]=bcd[0]&0x0f;
str[2]=bcd[1]/16;
str[3]=bcd[1]&0x0f;
str[4]=bcd[2]/16;
str[5]=bcd[2]&0x0f;
str[6]=bcd[3]/16;
str[7]=bcd[3]&0x0f;
str[8]=0;
}*/
//-----------------------------------------------
void	MemCpy(uint8_t *cel, uint8_t *forr, uint8_t db)
{
uint8_t		i;
for(i=0; i<db; i++) cel[i]= forr[i];
}
//-----------------------------------------------
int		MemCmp(uint8_t *cel, uint8_t *forr, uint8_t db)//-1=kisebb,0egyenlõ,+1=nagyobb
{
uint8_t		i;
for(i=0; i<db; i++){
	if		(cel[i] < forr[i]) return(-1);	//kisebb
	else if	(cel[i] > forr[i]) return(1);	//nagyobb
	}
return(0);									//egyenlõ
}
//-----------------------------------------------
void	MemSet(uint8_t *cel, uint8_t minta, uint8_t db)
{
uint8_t		i;
for(i=0; i<db; i++) cel[i]= minta;
}
//===============================================END
/*;--------------------------------------Alap-1s
.macro	_Integral
		movY_X
		lsrY			;/8
		lsrY
		lsrY
		subX_Y			;z=Fesz12-Fesz12/8
		addX_Z
.endm*/
//-----------------------------------------------Alap-1s
/*
void	Homer_1s(void)
{
uint32_t	ho;
uint16_t	komp;

IntHo3=IntHo3-IntHo3/8+FeszUHO3		//FeszHo3 [0000-1fff]

ho=IntHo3*Ho3Szor-Ho3Offs
if(ho < 0) ho=0;					//if(hõ<-40)hõ=-40
if(ho > 1399) ho=1399;				//if(hõ>99,9)hõ=99,9

Hom3=ho;
ho/=10;

lds		a,KontReg
cpiX	120				;max.80°C
if(ho > 120)brcc	Homer_ir
		cpi		xl,20			;min.-20°C
		brcs	Homer_ir

komp=KontKomp;
if(komp >		cpi		yl,1
		brcs	Homer_ir		;min.1
		cpi		yl,140
		brcc	Homer_ir		;max.140
		call	div16u			;(x,y)->(x=x/y,rema=y)	Used:-

		sub		a,xl
		brcc	Homer_Komp1
		clr		a
Homer_Komp1:
		cpi		a,200
		brcs	Homer_ir
		ldi		a,200
Homer_ir:
		sts		KontKi,a
}*/
//===============================================END
