#ifndef BVEZ2H_MAR_VOLT
#define BVEZ2H_MAR_VOLT
//-----------------------------------------------
// BVEZ2 vez�rlo (dsPIC33FJ128GP708 - 8[40]MHz)
//-----------------------------------------------
#include <p33FJ128GP708a.h>
#include <stdint.h>
#include "OraKorr.h"
//-----------------------------------------------
//- LCD hom�ro a kontarszthoz (A vez�rlo panelen nem muk�dik a hokompenz�ci�)
//+ k�tfo bitek kikapcsol�sa r�gi szoftverhez
//+ napi limit 0-1
//+ oper�tor krt
//- a k�tszerver szoftverbe fej figyel�s �ll�t�si lehet?s�ge kellene.
//- a benzin szoftverben a nyomtat�s opcion�lis kellene legyen a v�g�s, illetve az, hogy +2 sort oda dob a v�g�re.
//+ V�ge ido: Lej�rati ido, ami ut�n nem megy,
//- Auto+mester km �t�ll�t(mester menu km n�vekvo kikapcs 1 tankol�sra)
//- a vez�rlon a rosszul be�t�tt km �ra �ll�st nem lehet jav�tani mester k�rty�val,
//	rossz km�ra �ll�s ut�n tankoltak egyet a mester k�rty�val, ahol jav�tott�k az 
//	�ll�st, �s a k�vetkez? tankol�sn�l m�r ezt vette alapul.
//- �j let�lto k�rtya+szoftver
//- oper�tork�rtya funkci�, ugyan�gy mint KII eset�ben
// 	1, �rabe�ll�t�s 
//	2, kontraszt�ll�t�s
//- setup t�rl�s ellenorz�se
//===============================================
#define		C_SEREG				1		//1=nyomtat�s m�s sz�vegek
#define		C_SEBESSEG			1		//1=kijelz�sn�l sebess�g is
//--------------
#define		C_VERZ				74		//2019/04/23 - 3->6mp �tlag
//			C_VERZ				73		//2019/04/04 - g�zolaj->gazolaj sereg felirat
//			C_VERZ				72		//2019/04/04 - g�zolaj->gazolaj sereg felirat
//			C_VERZ				71		//2019/04/03 - sereg sz�veg KEROZIN->G�ZOLAJ
//			C_VERZ				70		//2019/01/07 - WR_FLS enged�lyez a tnkol�s ter�letre is
//			C_VERZ				69		//2018/11/05 - Pisztoly timeot 15 mp
//			C_VERZ				68		//2018/06/04 - sebess�g kijelz�se(0-500l/p))
//			C_VERZ				67		//2018/03/24 - sereg nyomtat�s
//			C_VERZ				66		//2018/03/24 - g�rgetett komp<->alap v�laszt�s
//			C_VERZ				65		//2018/02/27 - TankN->KutN g�rgetett kirak
//			C_VERZ				64		//2018/02/27 - Scr3-ra g�rgetett kirak
//			C_VERZ				63		//2018/02/19 - tankol�s stop Scr01-r?l is
//  		C_VERZ				62		//2018/02/19 - tankol�s stop k�perny?
//  		C_VERZ				61		//2018/02/19 - C_MAX_LITER=59999
//  		C_VERZ				60		//2018/01/08 - 4. mA bemenet integr�tor jav�t�s
//  		C_VERZ				59		//2018/01/07 - 4szinm�r? be�ll�t�s
//  		C_VERZ				58		//2017/09/28 - CrossPoint c�m setup
//			C_VERZ				57		//2017/08/23 - m�r�s sz�mol�s csere, 4*mA start
//			C_VERZ				56		//2017/05/20 - CARD2 mifare->wiegand,
//										//			 - rossz v�ge nyomtat�s
//			C_VERZ				55		//2017/03/27 -	CARD2_VAN start
//			C_VERZ				54		//2016/09/04 -	Tart�ly szint kijelz�s
//- ha az �gyf�l megnyom egy gombot, l�thatja a tart�ly aktu�lis k�szlet�t 1 literben. (0-�s gomb pl)
//-	T�bb szintm�rot kezeljen a K4 a jelenlegin�l (jelenleg 2-ot tud kezelni, optim�lis, ha 8-at tud egyszerre)
//- 4..20mA-es jelad�val m�rik a szintet, az elso tart�lyfelt�lt�skor kapunk egy liter<->mA t�bl�zatot 0 literrol kezdodoen.
//- h�ny elemu lesz ez a t�bl�zat? 1000, vagy 500 literenk�nt t�rt�nik a kalibr�l�s.
//- legkisebb tart�ly : 3e liter, legnagyobb: 60e liter
//			C_VERZ				53		//2016/01/03 - Txf ki �s Txe ki init jav�t�s,
//										//			 - ScrA1 csak az akt�v sz�mok l�tszanak, ha k�ben kikapcsolt�k nem enged k�rty�zni
//										//			 - Tankol�s k�ben letilt�sn�l limit=1, tankol�s befejez�s rendesen
//			C_VERZ				52		//2015/09/21 - Dummy null string Net k�r�nk�nt
//			C_VERZ				51		//2015/04/29 - Rs232 word, Analog 1ms
//      	C_VERZ				50		//2015/01/28 - CrossPoin c�m 6->12
//			C_VERZ				49		//2014/12/01 - 20-as hiba:0xa5 shift10*, NET rutin 1ms->100us, KAPCS_HIBA csomagonk�nt sz�mol
//			C_VERZ				48		//2014/10/24 - upgrade start,FLS_TANKMAX=0x7cff,soros hibajelz�s,flash dupla jav�t,nyelv kapcsol�
//			C_VERZ				47		//2014/08/27 - Virtu�lis k�tfo start
//			C_VERZ				46		//2014/05/09 - Olvas� 7 eeprom olv jav�t
//			C_VERZ				45		//2014/04/08 - Net k�rbe
//			C_VERZ				44		//2014/04/06 - FLS_TANKMAX	0x7fff->0xffff
//			C_VERZ				43		//2014/01/06 - CARD_BCD10 start
//			C_VERZ				42		//2013/12/14 - km dupla bevitel
//			C_VERZ				41		//2013/12/12 - B_VEZ_AUTOSTR
//			C_VERZ				40		//2013/11/13 - Gyurus motor vez�rl�s is v�r 10mp-et
//			C_VERZ				39		//2013/11/13 - Gyurus 0-k�d is 10mp k�slelte�ssel �ll le
//			C_VERZ				38		//2013/11/12 - CrossPoint olvas� r�gi ID t�t�lve, Id?z�t?k (N-1)
//			C_VERZ				37		//2013/10/07 - CrossPoint olvas� start
//			C_VERZ				36		//2013/10/02 - Mifare sorrend jav�t�s
//			C_VERZ				35		//2013/09/30 - 1-es ut�n nem v�r, emberk�d visszal�p jav�t�s, CrossPoint olvas� start
//			C_VERZ				34		//2013/09/24 - Ember k�d
//			C_VERZ				33		//2013/09/21 - Mifare k�rtyaolvas�
//			C_VERZ				32		//2013/09/19 - Kut[x].Pisztoly start, ScrA2-ben tankol�s gomb
//			C_VERZ				31		//2013/07/16 - KAPCSOLAT_TIME=200, Kut1 kommunik�ci� teszt
//			C_VERZ				30		//2013/06/18 - Gyurus olvas� start
//			C_VERZ				29		//2012/10/17 - KUT_TIMEOUT 1p->3p, timeout �s stat<TANK_KI liter 0,�ra korrekci� start
//			C_VERZ				28		//2012/10/03 - EE.CardReaderTipe,EE.MnuTimeout,EE.MnuUtoTime start
//			C_VERZ				27		//2012/09/26 - Ma1,2 eeprom bet�lt�s
//			C_VERZ				26		//2012/09/24 - Kutfok mindk�t k�ry�ra,stat=VEGE->STOP,M.UMa->M.Ma
//			C_VERZ				25		//2012/09/04 - 19-es ment�sn�l nem nulla, STA_KAPCSOLAT start
//			C_VERZ				24		//2012/08/06 - 4-20mA bemenetek start
//			C_VERZ				23		//2012/06/26 - Mesterhez aut�,Feszm�r�s
//			C_VERZ				22		//2012/06/07 - MnuTimeOut=255 kikapcsolva
//			C_VERZ				21		//2012/05/29 - ScrA1 timout kijelz�s jav�t, szint szumma kikapcs
//			C_VERZ				20		//2012/05/28 - Net lehal�s ment�s miatt
//			C_VERZ				19		//2012/05/23 - 2*Szint-> Rsb,Rsc
//			C_VERZ				18		//2012/05/20 - Kut[16->15], 60mp Kut.TimeOut
//			C_VERZ				17		//2012/05/10 - Kut 0-14, h?mkomp v�lt�s tank v�g�n, EE.KutSta&0x01
//			C_VERZ				16		//2012/04/25 - TRIS_LCD_HATTER
//			C_VERZ				15		//2012/04/16 - PrintEEc�m jav�t, szint start
//			C_VERZ				14		//2012/04/11 - Pinbevitel DEC->HEX, 15 k�tf? start, print �r 10.2
//			C_VERZ				13		//2012/04/05 - Pinbevitel ut�n megakad�s jav�t�s, A1/S3 Gomb2Time
//			C_VERZ				12		//2012/04/03 - Pink�d ut�n k�rtyabe,A3-r?l szerviz bel�p�s,A2 nincs timeout
//			C_VERZ				11		//2012/03/29 - AR_MAX 1m -> 6,6m
//			C_VERZ				10		//2012/03/08 - �rak brutt� jav�t
//			C_VERZ				9		//2012/03/07 - KiJE3 start, �r t�lcsor, ment�s f�zisok
//			C_VERZ				8		//2012/02/21 - Print=9 ind�t, f�ltankol�s v�ge megv�r
//			C_VERZ				7		//2012/01/31 - Liter �s LitKomp (4b)->Dword konverzi� jav�t�sa
//			C_VERZ				6		//2012/01/30 - Arak_SrcUres *2 -> *8
//			C_VERZ				5		//2012/01/24 - �j k�rtya be�r�sn�l dupla increment
//			C_VERZ				4		//2012/01/04 - �rak Tank-ba,c�gn�v 6.sor,�rak mez? start,n�v nyomtat�s !szerint
//			C_VERZ				3		//2012/01/02 - S11 �ra bevitel jav�t�s,�FA 25%->27%,k�tfajta Megnev,
										//			   EE.KutStat-b1 start, Chr3 start
//			C_VERZ				2		//2011/11/24 - Csoportok start, TankDb k�l�n-k�l�n, �rak start, KmMax start
//			C_VERZ				1		//2011/11/21 - Alap
//-----------------------------------------------
#define		C_GYARI				11001
//===============================================
#define		CROSS_POINT_CIM		24			//6,12,24

#define		MESTER_AUTONUMDB	4			//4 vagy 10
#define		C_MAX_LITER			59999
#define		C_MAX_DB			100
#define		AR_MAX				660000000	//*0,01Ft =660Ft*10000l=6,6mFt

#define		KAPCSOLAT_TIME		200			//ennyi rossz csomag -> elment hib�val
#define		NET_REGI			0			//1=r�gi, m�s=�j
//-----------------------------------------------DEFINE
#define		RS232_TILT			3		//*1ms	v�lasz k�sik
#define		RS232_TIMEOUT		100		//*1ms	timeout hiba (v�tel v�g�t?l)
//.equ	NET_TIMEOUT	=12	;*5m= 60 msec (4k8)
//.equ	MOD_TIMEOUT	=6	;*5m= 30 msec (9k6)

#define		LED_1MP				100		//*1ms	LED �g id?
#define		LED_JOKERES			50		//*1ms	LED �g id?
#define		LED_TILT			5		//*1s	LED tilt�s, ha volt soros
#define		GOMB2_TIMEOUT		15		//*100ms

#define		GOMB_PRELL			6		//*5ms prell sz?r�s
#define		GOMB_BEEP_TIME		50		//*1ms beep a gombnyom�sra
#define		CARD_BEEP_TIME		200		//*1ms beep a k�rty�ra
#define		CARD_TIMEOUT		10		//*100ms=1.0 sec
#define		PISZT_TIMEOUT		150//100		//b		*100ms=10.0 sec
#define		KUT_TIMEOUT			1200	//*150ms=3p	k�t nem mozdul->kil�v�s

#define		LCD_KONTRASZT		210		//0-250 kit�lt�si t�nyez?
#define		LCD_INIT_TIME		60		//*1s
#define		C_KIJEL_VEDO		1800	//*0,1s	3p	k�perny?v�d? indul
#define		C_KIJEL_RESET		6000	//*0,1s	10p	k�perny?v�d?ben ennyink�nt reset
//-----------------------------------------------
#if		C_GYARI==11001					//2011.04.21-v1	- teszt - no h?m�r?
//  #warning "### Gy�ri sz�m=11001 ###"
  #define	MUL_HOM1			2000
  #define	MUL_HOM2			2000
//-----------------------------------------------
#else
  rossz gyariszam
#endif
//===============================================
#define		TRIS_KI				0				//kimeneti pin
#define		TRIS_BE				1				//bemeneti pin

typedef		uint8_t		uint8;
typedef		uint16_t	uint16;
typedef		uint32_t	uint32;

#define		hw(x)		(*(((uint16_t*)(&x))+1))
#define		lw(x)		(*(((uint16_t*)(&x))))

#define		hh(x)		(*((uint8_t*)(&x)+3))
#define		hl(x)		(*((uint8_t*)(&x)+2))
#define		lh(x)		(*((uint8_t*)(&x)+1))
#define		ll(x)		(*((uint8_t*)(&x)))

#define		hi(x)		(*((uint8_t*)(&x)+1))
#define		lo(x)		(*((uint8_t*)(&x)))

#define		WmulWtoDW(mit, mivel)	__builtin_muluu(mit, mivel)
//===============================================IO pins
#define		LED_HIBA			_LATG0			//PORTG0	Led HIBA
#define		TRIS_LED_HIBA		_TRISG0
#define		LED_PROC			_LATG1			//PORTG1	Led PROC
#define		TRIS_LED_PROC		_TRISG1
#define		LED_VEZ				_LATF1			//PORTF1	Led VEZ
#define		TRIS_LED_VEZ		_TRISF1

#define		GOMB_KI1			_LATG12			//PORTG12:	KG1 gomb kimenet
#define		TRIS_GOMB_KI1		_TRISG12
#define		GOMB_KI2			_LATG13			//PORTG13:	KG2 gomb kimenet
#define		TRIS_GOMB_KI2		_TRISG13
#define		GOMB_KI3			_LATG14			//PORTG14:	KG3 gomb kimenet
#define		TRIS_GOMB_KI3		_TRISG14
#define		GOMB_BEPORT			PORTC			//PORTC(xxxx;3.2.1.0)
#define		TRIS_GOMB_BE1		_TRISC1			//PORTC1:	BG1 gomb bemenet
#define		TRIS_GOMB_BE2		_TRISC2			//PORTC2:	BG1 gomb bemenet
#define		TRIS_GOMB_BE3		_TRISC3			//PORTC3:	BG1 gomb bemenet
#define		TRIS_GOMB_BE4		_TRISC4			//PORTC4:	BG1 gomb bemenet

//			SPK					_LATD0			//PORTD0:	Speaker kimenet
#define		LCD_HATTER			_LATD1			//PORTD1:	Lcd h�tt�r kimenet
#define		TRIS_LCD_HATTER		_TRISD1
//			LCD_KONTR			_LATD2			//PORTD2:	Lcd kontraszt kimenet

#define		FLS_CK				_LATG6			//Flash Clock		KI=0
#define		TRIS_FLS_CK			_TRISG6
#define		FLS_DI				_LATG7			//Flash Data Out	BE
#define		TRIS_FLS_DI			_TRISG7
#define		FLS_DO				_LATG8			//Flash Data In		KI=0
#define		TRIS_FLS_DO			_TRISG8
#define		FLS_nCS1			_LATG9			//Flash nCS1		KI=1
#define		TRIS_FLS_nCS1		_TRISG9
#define		FLS_nCS2			_LATG15			//Flash nCS2		KI=1
#define		TRIS_FLS_nCS2		_TRISG15

#define		RS_RXB				_RF6			//RS232-RXB bemenet
#define		TRIS_RS_RXB			_TRISF6
#define		RS_TXB				_LATF7			//RS232-TXB kimenet
#define		TRIS_RS_TXB			_TRISF7

#define		RS_RXC				_RA2			//RS232-RXC bemenet
#define		TRIS_RS_RXC			_TRISA2
#define		RS_TXC				_LATA3			//RS232-TXC kimenet
#define		TRIS_RS_TXC			_TRISA3

#define		RS_RXD				_RA6			//RS232-RXD bemenet
#define		TRIS_RS_RXD			_TRISA6
#define		RS_TXD				_LATA7			//RS232-TXD kimenet
#define		TRIS_RS_TXD			_TRISA7

#define		RS_RXE				_RB6			//RS232-RXE bemenet
#define		TRIS_RS_RXE			_TRISB6
#define		RS_TXE				_LATB7			//RS232-TXE kimenet
#define		TRIS_RS_TXE			_TRISB7

#define		RS_RXF				_RA9			//RS232-RXF bemenet
#define		TRIS_RS_RXF			_TRISA9
#define		RS_TXF				_LATA10			//RS232-TXF kimenet
#define		TRIS_RS_TXF			_TRISA10
//-----------------------------------------------
#define		ANA_MA1			4				//AN4	- mA bemenet 1
#define		ANA_MA2			5				//AN5	- mA bemenet 2
#define		ANA_PT100_1		2				//AN2	- Pt100 H?m�r? 1
#define		ANA_PT100_2		3				//AN3	- Pt100 H?m�r? 2
#define		ANA_HOM1		0				//AN0	- H?m�r?1 lapon
#define		ANA_HOM2		1				//AN1	- H?m�r?2 csatin

#define		ANA_U11			8				//AN8	- fesz 11V - di�da ut�n
#define		ANA_U10			9				//AN9	- fesz 10V - 11V+2R
#define		ANA_U8			10				//AN10	- fesz 8V
#define		ANA_U5			11				//AN11	- fesz 5V
#define		ANA_U3			12				//AN12	- fesz 3V
#define		ANA_UHAT		13				//AN13	- fesz Uhat - LCD h�tt�r led kimenet
#define		ANA_UM15		14				//AN14	- fesz Uminusz15
#define		ANA_UEE			15				//AN15	- fesz Uee - LCD kontraszt kimenet

#define		ANA_INITH		0xffff			// AN-31-16 digital
#define		ANA_INITL		0x00c0			// AN-15,14,13,12;11,10,9,8;_,_,5,4;3,2,1,0 analog, tobbi digital
/*
.equ LCHAT	=6	;PD6	H�tt�r 	0-KI, 1-BE		(OUT)
.macro _Hatter_Ki
		cbi	PORTD,LCHAT        	;2 csak egy utasitas!!!
.endmacro
.macro _Hatter_Be
		sbi	PORTD,LCHAT        	;2 csak egy utasitas!!!
.endmacro
*/
//===============================================V�ltoz�k
extern uint32_t		FlsRow[64];				//64db utas�t�s
extern uint16_t		FlsIntDisable;			//*1ms flash int stop
extern uint8_t		SYS_A100MS;				//-	system timer - 100ms alap rutin mehet

extern uint16_t	 	LedProcTime;			//*1ms Rendben led �g
extern uint16_t	 	LedVezTime;
extern uint16_t		LedHibaTime;			//*1ms Hiba led �g
extern uint16_t		LedProcTilt;			//*1s Rendben led villog�s tiltva

#define			STR_MAXLEN		32+1	//***
extern uint8_t		Str[STR_MAXLEN];		//String v�ltoz� sz�vegel�shez
//===============================================RD_MEM
struct struRx{
	uint16_t	Tim;			//bitid�
	uint16_t	Faz;			//v�teli f�zis
	uint16_t	VanVett;		//van vett byte jelz�s
	uint8_t		Byte;			//aktu�lis byte �ssze�ll�t�sa
	uint8_t		Vett;			//k�sz byte
	};
extern struct struRx	Rxb;	//szintm�r�1 | k�rtya2
extern struct struRx	Rxc;	//szintm�r�2 | k�rtya2
extern struct struRx	Rxd;	//pisztoly
extern struct struRx	Rxf;	//k�rtya1 
//===============================================RD_MEM
struct struMem{
	uint16_t		Gyari;				//x00	kijelz? Gy�risz�m (yynnn)
	uint16_t		Szoftver;			//x02	kijelz? Szoftver verzi�

	uint8_t			FlsId1[3];			//x04
	uint8_t			FlsId2[3];			//x07

	uint16_t		TankDb;				//x0a	elfoglalt tankol�srekordok sz�ma
	uint16_t		CardDb;				//x0c	elfoglalt k�rtyarekordok sz�ma
	uint16_t		CegDb;				//x0e	elfoglalt c�grekordok sz�ma
	uint16_t		ArakDb;				//x10	elfoglalt c�grekordok sz�ma
	
	uint16_t		InputBe;			//x12	inputs gombok
	uint16_t		GombBe;				//x14	Button(1-12) inputs (control gombok)
	#define 	G_0		0x0001
	#define 	G_1		0x0002
	#define 	G_2		0x0004
	#define 	G_3		0x0008
	#define 	G_4		0x0010
	#define 	G_5		0x0020
	#define 	G_6		0x0040
	#define 	G_7		0x0080
	#define 	G_8		0x0100
	#define 	G_9		0x0200
	#define 	G_BAL	0x0400
	#define 	G_JOBB	0x0800
	uint8_t			Gomb;				//x16	a gomb sorsz�ma 0..11, ha nincs nyomva 12
	uint8_t			Gomb2;				//x17	a gomb sorsz�ma 0..11, ha nincs nyomva 12
	#define		GOMB_TOR	10		//		T�rl�s gomb
	#define		GOMB_BE		11		//		Bevitel gomb
	#define		GOMB_NO		12		//		Nincs megnyomva
	uint16_t		KontKi;				//x18	kompenz�lt kontraszt
	uint16_t		LcdInitTime;		//x1a	LcdInit id?z�t�s

	uint16_t		Ma1;				//x1c	*1uA [0-20000] mA-1 (Tank-ba mentve szint)
	uint16_t		Ma2;				//x1e	*1uA [0-20000] mA-2
	uint16_t		Ma3;				//x20	*1uA [0-20000] mA-2
	uint16_t		Ma4;				//x22	*1uA [0-20000] mA-2
	uint16_t		Hom1;				//x24	*0,1�C H?m1-alaplap
	uint16_t		Hom2;				//x26	*0,1�C H?m2

	uint16_t		UMa1;				//x28	*1uA [0-20000] mA-1 (t�voli leolvas�s)
	uint16_t		UMa2;				//x2a	*1uA [0-20000] mA-2
	uint16_t		UMa3;				//x2c	*1uA [0-20000] mA-2
	uint16_t		UMa4;				//x2e	*1uA [0-20000] mA-2
	uint16_t		UHom1;				//x30	*0,1�C H?m1-alaplap
	uint16_t		UHom2;				//x32	*0,1�C H?m2
	uint16_t		U11;				//x34	*0,01V
	uint16_t		U10;				//x36	*0,01V
	uint16_t		U8;					//x38	*0,01V
	uint16_t		U5;					//x3a	*0,01V
	uint16_t		U3;					//x3c	*0,01V
	uint16_t		Uhat;				//x3e	*0,01V
	uint16_t		Um15;				//x40	*0,01V
	uint16_t		Uee;				//x42	*0,01V

	uint16_t		IntMa1;				//x44	10db 12bit m�rt
	uint16_t		IntMa2;				//		*1uA [0-20000] mA-2
	uint16_t		IntMa3;				//		*1uA [0-20000] mA-2
	uint16_t		IntMa4;				//		*1uA [0-20000] mA-2
	uint16_t		IntHom1;			//		*0,1�C Hom1-alaplap
	uint16_t		IntHom2;			//		*0,1�C Hom2
	uint16_t		IntU11;				//		*0,01V
	uint16_t		IntU10;				//		*0,01V
	uint16_t		IntU8;				//		*0,01V
	uint16_t		IntU5;				//		*0,01V
	uint16_t		IntU3;				//		*0,01V
	uint16_t		IntUhat;			//		*0,01V
	uint16_t		IntUm15;			//		*0,01V
	uint16_t		IntUee;				//		*0,01V
	
	uint16_t		AdHibaNemkesz;

	uint16_t		Mer10Ma1;			//10db 12bit m�rt
	uint16_t		Mer10Ma2;			//10db 12bit m�rt
	uint16_t		Mer10Ma3;			//10db 12bit m�rt
	uint16_t		Mer10Ma4;			//10db 12bit m�rt
	uint16_t		Mer10Hom1;			//10db 12bit m�rt
	uint16_t		Mer10Hom2;			//10db 12bit m�rt
	uint16_t		Mer10U11;			//10db 12bit m�rt
	uint16_t		Mer10U10;			//10db 12bit m�rt
	uint16_t		Mer10U8;			//10db 12bit m�rt
	uint16_t		Mer10U5;			//10db 12bit m�rt
	uint16_t		Mer10U3;			//10db 12bit m�rt
	uint16_t		Mer10Uhat;			//10db 12bit m�rt
	uint16_t		Mer10Um15;			//10db 12bit m�rt
	uint16_t		Mer10Uee;			//10db 12bit m�rt

	uint16_t		Gomb2Time;			//*0,1s kettos sz�m max ido

	uint16_t		SpkTim;				//x..	*1ms gombra pitty
	uint8_t			NetMehet;			//=1 mehet a net bekapcsol�sn�l
	uint8_t		xxu;
	
	uint16_t		SzintTbl[4][120][2];//mero,pont,ua/liter
	};
extern struct struMem	M;
//-----------------------------------------------
//.equ	SzintRx		=0x08f4	;2b
//;		SzintTxPos	=0x08f6	;b
//;		SzintTxDb	=0x08f7	;b

//.equ	FeszUM1		=0x0120	;b	10V NET fesz�lts�g
//.equ	VeszMent	=0x0121	;b	fesz kicsi k�sleltet�s
//.equ	FeszUHO3	=0x0122	;w	h?3 fesz�lts�g
//.equ	IntHo3		=0x0124	;w	H?m3 integral
//.equ	Ho3Szor		=0x0139	;w	h?m�r�s szorz�
//.equ	Ho3Offs		=0x013b	;w	h?m�r�s nulla
//.equ	MnuSorszam	=0x013e	;w	a mentend? tankol�s sorsz�ma

//.equ	SzintRxBuf	=0x0d00	;32b	Szintm�r?
//.equ	SzintRxJo1	=0x0d20	;20b	uts� j� blokk m�solata
//.equ	SzintRxJo2	=0x0d34	;20b	uts� j� blokk m�solata
//.equ	SzintJo1	=0x0d48	;w-bcd	uts� j� szint1
//.equ	SzintJo2	=0x0d4a	;w-bcd	uts� j� szint2
//.equ	SzintJoSum	=0x0d4c	;w-bcd	uts� j� szint1+szint2
//===============================================RW_ORA
extern struct StruOra	Ora;			//7b+7b+w	 kijelz? Ora.Olv,Ora.Ir,Ora.Korr
struct StruPrn{
	uint8_t			xxPos;
	uint8_t			xxDb;
	uint8_t			xxByte;				//aktu�lis byte �ssze�ll�t�sa
	uint8_t			xxTim;				//bitido
	uint8_t			xxFaz;				//ad�si f�zis
	uint8_t			Buf[38];			//34+2

	uint8_t			Foglalt;			//nyomtat�s folyamatban valamelyik k�tfon
	};
extern struct StruPrn	Prn;	
//===============================================RD_MNU
enum MenuType{
			MENU_RESET,		/* bekapcsol�si 100ms k�sleltet�s */
			MENU_A0,		/* szintek */
			MENU_A1,		/* k�tsz�mok + c�gn�v */
			MENU_A2,		/* st�tusz kijelz�s */
			MENU_A3,		/* k�rtya bevitel */
			MENU_A4,		/* km �ra �ll�sa */
			MENU_A5,		/* menetlev�l bevitel */
			MENU_A6,		/* tankolhat */
			MENU_A7,		/* �zem�ra bevitel */
			MENU_A8,		/* mester k�rtya bek�r�s */
			MENU_A9,		/* ember k�d bek�r�s */
			MENU_A10,		/* mennyis�g k�d bek�r�s */
			MENU_Astop,		/* max tankolhat� liter bek�r�s */
			MENU_H1,		/* k�rtya hib�s */
			MENU_H2,		/* keret elfogyott */
			MENU_H3,		/* k�rtya rossz a k�tf?h�z */
			MENU_S1,		/* Service k�rtya bek�r�s */	
			MENU_S2,		/* Service f?men� */
			MENU_S3,		/* Service k�tf?k */
			MENU_S4,		/* Service k�rty�k */
			MENU_S5,		/* Service be�ll�t�s */
			MENU_S6,		/* Service be�ll�t�s-liter kijelz�s */
			MENU_S7,		/* Service be�ll�t�s-kontraszt */
			MENU_S8,		/* Service testre szab�s */
			MENU_S9,		/* Service v�ltoz�k */
			MENU_S10,		/* Service rendszer */
			MENU_S11		/* Service be�ll�t�s-�ra */
			};			
struct MENU_Stru{
	enum MenuType		Num;			//x00	akt�v men� sz�ma
	uint8_t				Villog;			//x02	Men� villog�s id?
	uint8_t				Kut;			//x03	(0-15)Az aktu�lis k�t mutat�ja

	uint16_t			MaxLiter;		//x04	k�rty�r�l a kisebbik
	uint16_t			MaxDbAuto;		//x06	k�rty�r�l
	uint16_t			TankDbA;		//x08	tankol�s van az adott aut�val aznap
	uint16_t			MaxDbEmber;		//x0a	k�rty�r�l
	uint16_t			TankDbE;		//x0c	tankol�s van az adott aut�val aznap
	uint16_t			Kutak;			//x0e	k�tf? bitmap (0=tiltva, 1=engeve)
	uint32_t			KmElozo;		//x10	el?z?leg tankolt km
	
	uint16_t			Pin;			//x14	HEX-Pin beolvas�s
	uint8_t				AlFaz;			//x16	Men� k�perny?n bel�li be�ll�t�s f�zis mutat�
	uint8_t				Back;			//x17	Hiba men� visszat�r�s

	uint8_t				CardVan;		//x18	1=J�rm?,2=Sof?r,4=Oper�tor,8=Szerviz megj�tt
	#define			VAN_AUTO	0x01
	#define			VAN_SOFOR	0x02
//	#define			VAN_OPER	0x04
//	#define			VAN_MESTER	0x08

	uint8_t				Print;			//x19	auto k�rty�r�l print
	uint8_t				Timeout;		//x1a	*1s timout ut�n st�tusz->alap
	uint8_t				ScrA1Vill;		//x1b
	struct StruIdo		Obe;			//x1c	7b �ra be�ll�t�s

	uint32_t			EmberKod;		//x24	(00999999)
	uint8_t				Kod[8];			//x28
	uint32_t			KmElso;			//x30	(00999999)-elso km bevitel
	uint32_t			Mennyiseg;		//x34	(00999999)-mennyis�g bevitel
	uint16_t			LitStop;		//x38	(0059999)-liter stop
	};
extern struct MENU_Stru	Mnu;
//===============================================RW_CARD
//<KARTYA>
//<T_DATUM>2008.12.10 11:00</T_DATUM>
//<CardID>1234567890</CardID>
//<CardTip>1</CardTip>
//<CardMaxLit>01000</CardMaxLit>
//<CardMaxDb>00100</CardMaxDb>
//<CardNev>N�meth G�bor      20</CardNev>
//<CardPin>3456</CardPin>
//<CardNum>0176</CardNum>
//<CardKutfok>00</CardKutfok>
//<CardCsoport>000</CardCsoport>
//<CardPrint>0</CardPrint>
//</KARTYA>
struct CARD_Stru{
	uint16_t		RecTip;			//x00	0x2001 - k�rtya-v1
	uint8_t			Id[7];			//x02	card in result BCD 		6+1byte bin ->15+2sz�mjegy
	uint8_t			Tip;			//x09	tipus
	#define 	CRD_SOFOR		1
	#define 	CRD_JARMU		2
	#define 	CRD_MESTER		3
	#define 	CRD_SZERVIZ		5
	uint16_t		MaxLit;			//x0a	[0-60000]
	uint16_t		MaxDb;			//x0c	[0-65000]
	uint16_t		Pin;			//x0e	HEX[0000-9999]
	uint16_t		Kutak;			//x10	[00-ffff]	max.16db k�tf� enged�ly
	uint16_t		Num;			//x12	[0-65000]	k�rtya sorsz�ma
	uint16_t		Csoport;		//x14	[0-4095]
	uint8_t			Print;			//x16	[0-255]
	uint8_t			Ev;				//x17	be�r�si id�
	uint8_t			Ho;				//x18
	uint8_t			Nap;			//x19
	uint8_t			Ora;			//x1a
	uint8_t			Perc;			//x1b
	uint8_t			Mp;				//x1c
	uint8_t			Nev[20];		//x1d
									//x31
	uint8_t			Rx1Pos;			//x31	v�teli poz�ci�
	uint8_t			RxTim100m;		//x32	id�hat�r
	uint8_t			Rx1Buf[18];		//x33	K�rtya olvas�

	uint8_t			PiDb;			//x45	vett byte
	uint8_t			PiTim100m;		//x46	(100ms) id�hat�r null�z�shoz
	uint8_t			PiVan;			//x47	1=van,0=nincs �rv�nyes k�d
	uint8_t			PiDec[6];		//x48	Pisztoly �rv�nyes k�d
	uint8_t			PiKod[6];		//x4e	Pisztoly �rv�nyes k�d
	uint8_t			PiBlk[12];		//x54	Pisztoly blokk
	uint8_t			PiBuf[64];		//x60	Pisztoly olvas�

	uint8_t			TxPos;			//xa0	ad�si poz�ci�
	uint8_t			TxDb;			//xa1	ad�si poz�ci�
	uint8_t			TxBuf[8];		//xa2	K�rtya olvas� ad�s

	uint8_t			Rx2Pos;			//xaa	v�teli poz�ci�
	uint8_t			Rx2Buf[18];		//xab	K�rtya olvas�
	};								//xbd
extern struct CARD_Stru		Card;
#define	CARD_LEN	0x31
//===============================================Szintm�r?k
struct SZINT_Stru{
	uint8_t			TimeOut;		//x00	id�hat�r
	uint8_t			Pos;			//x01	v�teli poz�ci�
	uint8_t			Buf[22];		//x02	Szinm�ro blokk
	uint8_t			Buf1[22];		//x18	1.Szinm�ro blokk
	uint16_t		Jo;				//x2e
	};								//x30
extern struct SZINT_Stru	Szint[2];
//===============================================C�gek
/*struct CEG_Stru{
	Word		RecTip1;		//x00	0x4001 - v1
	Word		Csoport;		//x02	[0-4095]
	Byte		Ures[12];		//x04

	Byte		Nev1[32];		//x10
	Byte		Nev2[32];		//x30
	Byte		Nev3[32];		//x50

	Byte		Ures[6];		//x70
	Word		Cim;			//x76
	Byte		Ev1;			//x78	be�r�si ido
	Byte		Ho1;			//x79
	Byte		Nap1;			//x7a
	Byte		Ora1;			//x7b
	Byte		Perc1;			//x7c
	Byte		Mp1;			//x7d
	Word		Sum1;			//x7e
	//--------------------------//x80=128byte
	Word		RecTip2;		//x00	0x5001 - v1
	Word		Csoport;		//x02	[0-4095]
	Byte		Ures[12];		//x04

	Byte		Nev4[32];		//x10
	Byte		Nev5[32];		//x30
	Byte		Nev6[32];		//x50

	Byte		Ures[6];		//x70
	Word		Cim;			//x76
	Byte		Ev2;			//x78	be�r�si ido
	Byte		Ho2;			//x79
	Byte		Nap2;			//x7a
	Byte		Ora2;			//x7b
	Byte		Perc2;			//x7c
	Byte		Mp2;			//x7d
	Word		Sum2;			//x7e
	};*/
struct CEG_Stru{
	uint8_t			Nev[6][32];		//		192b
	};
extern struct CEG_Stru	Ceg0;
//===============================================�rak
struct ARAK_Stru{
	uint16_t		RecTip;			//x00	0x6001 - v1
	uint16_t		Csoport;		//x02	[0-4095]
	uint16_t		Ar0Netto;		//x04	*0.01Ft	(max 655.35,-Ft/l)
	uint16_t		Ar1Netto;		//x06	*0.01Ft
//	Word		Ures[];			//x08
//	Word		Cim;			//x16
//	Byte		Ev;				//x18		be�r�si id?
//	Byte		Ho;				//x19
//	Byte		Nap;			//x1a
//	Byte		Ora;			//x1b
//	Byte		Perc;			//x1c
//	Byte		Mp;				//x1d
//	Word		Sum;			//x1e
	};
extern struct ARAK_Stru	Arak0;
//===============================================RD_KUT[15]
//KI->xA5,xCn,Par,Max(2),Sum(2)=7b
//BE->xA5,xEn,Sta,Be,LitKomp(4),Liter(4),Hom(2),Gorg(6),GorgKomp(6),Sum(2)=28b
#define		KUTFO_DB	15		//ennyi k�tf? lehet max.
struct KUT_Stru{
	uint8_t			Hiba;			//x00	n*150ms hibasz�ml�l�
	uint8_t			Parancs;		//x01	k�t vez�rl�s ki�r�sa(k�tf�ben nem haszn�lt)
	uint16_t		Limit;			//x02	tankolhat� liter

	uint8_t			Stat;			//x04	St�tusz - Kut logika �llapota beolvasva
	#define STA_KIKAPCS		0	//		-_UTOTIM	reset/disable
	#define STA_ALAP_FENT	1	//		-		v�r
	#define STA_SUM1		2	//		-		szumma1 kijelz�se
	#define STA_SUM2		3	//		-		szumma2 kijelz�se
	#define STA_ALAP_LENT	4	//		-TIM_FEJ	tank kezd + limit v�r(fej lent)
	#define STA_TANK_KI		5	//		-_IDOHATAR	tankol�s szivatty� ki
	#define STA_TANK_BE		6	//		-_IDOHATAR	tankol�s szivatty� be
	#define STA_VEGE_LIM	7	//		-TIM_FEJ	v�ge limit j�rt le
	#define STA_VEGE_FEJ	8	//		-TIM_FEJ	v�ge fej lett visszarakva
	#define STA_VEGE_IDO	9	//		-TIM_FEJ	v�ge id�hat�r lej�rt
	#define STA_VEGE_LOP	10	//		-TIM_FEJ	v�ge lop�s
	#define STA_VEGE_FESZ	11	//		-TIM_FEJ	v�ge kisfesz
	#define STA_STOP_LIM	12	//		-_IDOSTOP	ment�s (limit j�rt le)
	#define STA_STOP_FEJ	13	//		-_IDOSTOP	ment�s (fej lett visszarakva)
	#define STA_STOP_IDO	14	//		-_IDOSTOP	ment�s (id�hat�r lej�rt)
	#define STA_STOP_LOP	15	//		-_IDOSTOP	v�r limit=0-ra (id�hat�r lej�rt)
	#define STA_STOP_FESZ	16	//		-_IDOSTOP	v�r limit=0-ra (id�hat�r lej�rt)
	#define STA_UJRAVAR		17	//		-4mp		miden ut�n k�telez� nyugi
	#define STA_HIBA		18	//		-		valami nem stimmelt
	#define STA_TIMEOUT		19	//		-		BVEZ2 timeout lej�rt, �s nem volt pisztoly fel
	#define STA_KAPCSOLAT	20	//		-		BVEZ2 nem l�tja a k�tfot
	#define STA_VIRTUAL		21	//		-		virtu�lis k�tfo

	uint8_t			Jel;			//x05	Jelek
//	#define		JEL_FEJ		0	//		-	fej fent
//	#define		JEL_KEZI	1
//	#define		JEL_SUM1	2
//	#define		JEL_SUM2	3
//	#define		JEL_LOPCL	4
//	#define		JEL_RELE	5
//	#define		JEL_VEZ		6
  	#define		JEL_KOMP	0x80	//-	(Par+_KOMP == 2)
	//-	1=kompenz�lt,0=nem kompenz�lt kijelz�s
	uint32_t		LitKomp;		//x06	Kompenz�lt liter
	uint32_t		Liter;			//x0a	Alap liter
	uint16_t		Hom;			//x0e	Hom�rs�klet
	uint8_t			Gorg[6];		//x10	6b	G�rgetett
	uint8_t			GorgKomp[6];	//x16	6b	Kompenz�lt g�rgetett
	uint16_t		Sum;			//x1c	szumma
	uint8_t			Ures[2];		//x1e
	uint32_t		LiterOld;		//x20	Timeouthoz el?z?
	uint16_t		TimeOut;		//x24	*1ms Timeout
	uint8_t			UtoTime;		//x26	*1s ScrA2 ut�nvil�g�t�s
	uint8_t			Pisztoly;		//x27	0=k�rtya, 1=pisztoly tankol�s vez�rl�s

	uint32_t		sebes[7];		//x28	uts� 6mp liter adata
	};								//x44=68byte
extern struct KUT_Stru	Kut[KUTFO_DB];//0..14
//===============================================RD_TANK[16]
#define	TANK_VERZ	0x3003		//20120524	Szint start
//		TANK_VERZ	0x3002		//20120306	96->100byte els? f�lbe EgysArNto �s TankCim
//		TANK_VERZ	0x3001		//			alap
struct TANK_Stru{
	uint16_t	KezdVerz;			//x00		=0x3001	kezd� rekord
	uint8_t		KezdEv;				//x02		kezd�si id?
	uint8_t		KezdHo;				//x03
	uint8_t		KezdNap;			//x04
	uint8_t		KezdOra;			//x05
	uint8_t		KezdPerc;			//x06
	uint8_t		KezdMp;				//x07

	uint8_t		VezNum;				//x08		Vez�rl� sz�ma+mester
	uint8_t		KutNum;				//x09		(1-16)
	uint16_t	EmberNum;			//x0a
	uint16_t	AutoNum;			//x0c
	uint16_t	Csoport;			//x0e		csoport sz�ma

	uint8_t		EmberId[7];			//x10		6+1byte bin ->15+2sz�mjegy
	uint8_t		AutoId[7];			//x17
	
	uint32_t	Km;					//x1e		(99.999.999km)
	uint32_t	Menlev;				//x22		(99.999.999)
	uint32_t	Uzemora;			//x26		(99.999.999)

	uint8_t		EmberNev[20];		//x2a
	uint8_t		AutoNev[20];		//x3e

	uint8_t		Gorg[6];			//x52		(9.999.999.999,99l)
	uint8_t		GorgKomp[6];		//x58		(9.999.999.999,99l)

	uint16_t	EgysArNto;			//x5e		*0.01Ft egys�g�r nto(max 655.35Ft/l)
	uint16_t	TankCim;			//x60		[0-65536]ment�si poz�ci�=tankol�s sorsz�ma

	uint16_t	Szint;				//x62		(99999)szintm�ro a kezd�sn�l
	//--------------------------//x64=100byte
	uint8_t		ZarEv;				//x64		z�r�si id?
	uint8_t		ZarHo;				//x65
	uint8_t		ZarNap;				//x66
	uint8_t		ZarOra;				//x67
	uint8_t		ZarPerc;			//x68
	uint8_t		ZarMp;				//x69

	uint32_t	LitKomp;			//x6a		(999.999,99l) [0-42.949.672,96]
	uint32_t	Liter;				//x6e		(999.999,99l)

	uint16_t	KutHom;				//x72		0=-40.0 - 400=0.0
	uint8_t		Hibakod;			//x74		EndStatusz
	uint8_t		NyomtatDb;			//x75		0=ready,=1,2 ennyi p�ld�nyt kell m�g nyomtatni
	uint32_t	ArNetto;			//x76		*0.01Ft netto v�g�sszeg
	uint32_t	ArBrutto;			//x7a		*0.01Ft brutto v�g�sszeg
	uint16_t	Sum;				//x7e
								//x80=128byte
	uint8_t		Mentes;				//x80		menteni kell a rekordot
#define		MENT_ALAP	0
#define		MENT_STR1	1
#define		MENT_OK_1	2
#define		MENT_STR2	3
#define		MENT_OK_2	4
	uint8_t		Print;				//x81		auto k�rty�r�l (0,1,2,9)
	uint8_t		Nyomtat;			//x82		0=ready,=1,2 ennyi p�ld�nyt kell m�g nyomtatni

	uint16_t	Ar0Netto;			//x84		*0.01Ft
	uint16_t	Ar1Netto;			//x86		*0.01Ft
	struct CEG_Stru		Ceg;
	};
//-----------------------------------------------Tankol�s rekordok k�tf?nk�nt
extern struct TANK_Stru	Tank[KUTFO_DB];
//===============================================RW_EEPROM - �RA EEPROM(00-7f)
#define	EECIM_VEZ		0x03
#define	EECIM_KONTREG	0x04
//#define	EECIM_KONTKOMP	0x05
#define	EECIM_KUTSTAT	0x10
struct	EEPROM_Stru{
	uint16_t		xxVERZ;				//x00		0x0001=alap
	uint8_t			VezNum;				//x02		vez�rlo sorsz�ma
	uint8_t			Vez;				//x03		Vez�rlo be�ll�t�sok
	#define 	B_VEZ_LITER		0x01	//-			Tankol�s literkijelz�s
	#define 	B_VEZ_CARD2		0x02	//-			Card2(k�tk�rty�s)
	#define 	B_VEZ_KMBE		0x04	//-			Km bek�r�s van
	#define 	B_VEZ_MENLEV	0x08	//-			Menetlev�l bek�r�s van
	#define 	B_VEZ_UZEMORA	0x10	//-			�zem�ra bek�r�s van
	#define 	B_VEZ_KMNOV		0x20	//-			Km bek�r�sn�l el?z?n�l kisebb rossz
	#define 	B_VEZ_EMKOD		0x40	//-			ember k�d bek�r�s van
	#define 	B_VEZ_AUTOSTR	0x80	//-			1 k�tfo eset�n autstart k�rtyabe
	uint8_t			KontReg;			//x04		Kijelzo kontraszt			[0x50]
	uint8_t			KontKomp;			//x05 Reg+1	Kijelzo kontraszt kompenz�ci�
	uint16_t		Ho1Szor;			//x06		hom�r�s szorz�
	uint16_t		Ho1Offs;			//x08		hom�r�s nulla
	uint16_t		Ho2Szor;			//x0a		hom�r�s szorz�
	uint16_t		Ho2Offs;			//x0c		hom�r�s nulla
	uint8_t			Vez2;				//x0e		Vez�rlo be�ll�t�sok
	#define 	B_VEZ2_KMKET	0x01	//-			Km bek�r�s k�tszer
	#define 	B_VEZ2_MAXSTOP 	0x02	//-			TankMaxStop be�ll�t�s kell
	uint8_t			CrossPointCim;		//x0fe		Crosspoint olvas� c�me
//	uint8_t		__ures_b0;	//xxTimeKomp;//x0f	b15(H+,L-) &0x7fff percenk�nt +-1mp (0=semmi)

	uint8_t			KutStat[15];		//x10		15 k�tfo st�tusza
                                        //          b0=0-Kikapcsolva, 1-Alaphelyzet
										//			b1=0-G�zolaj,1-Benzin
										//			b2=0-norm�l, 1-virtu�lis
	uint8_t		__ures_b1;				//x1f
//	hely hogy k�s?bb 32 k�tf� lehessen

//	Byte		ModInit1[28];		//x20		Modem inicializ�l�s 1.
//	Byte		ModValasz1[4];		//x3c		Modem v�lasz 1.
//	Byte		ModInit2[28];		//x40		Modem inicializ�l�s 2.
//	Byte		ModValasz2[4];		//x5c		Modem v�lasz 2.
//#define		MENU_TIMEOUT		255			//*1s st�tusz k�perny? -> f?men�
	uint8_t			MnuTimeout;			//x20		*1s Men� timeot (1-254,0v.255=no)
	uint8_t			MnuUtoTime;			//x21		*1s men� ut�nvil�g�t�s tankol�s v�g�n (0-254s, 255=�lland�)
	uint8_t			CardReaderTipe;		//x22		k�rtyaolvas�
	#define			CARD_REGI		1	//-r�gi(BCD-[#+10+1+3])
	#define			CARD_UJ			2	//-�j(BCD-[#+10+'9'])
	#define			CARD_HEX		3	//-HEX[x2;08x;x3]
	#define			CARD_1x10cx2	4	//-[x1+10c+x2]
	#define			CARD_MIFARE		5	//-[ba,02,01,b9]->
	#define			CARD_CROSSPOINT	6	//-[ba,02,01,b9]->
	#define			CARD_BCD10		7	//-BCD[#+10]
	#define			CARD2_REGI		0x10
	#define			CARD2_WIEGAND	0x20
	uint8_t			Pisztoly1;			//x23		[1-14] melyik k�tf?h�z tartozik a pisztoly 1 (0=nincs)
	uint8_t			Nyelv;				//x24		0-magyar,1-angol
	uint8_t		__ures_b2[55];			//x25+x37

	uint16_t		Szint3Kut;			//x5c		;b0..14=kut1..15
	uint16_t		Szint4Kut;			//x5e		;b0..14=kut1..15

	uint8_t			PrnDb;				//x60		nyomtat�shoz p�ld�nysz�m (0,1,2,9)
	uint8_t		__ures_b3;				//x61
	uint16_t		Szint1;				//x62
	uint16_t		Szint1Kut;			//x64		;b0..14=kut1..15
	uint16_t		Szint2;				//x66
	uint16_t		Szint2Kut;			//x68		;b0..14=kut1..15

	uint8_t			SzorU11;			//x6a
	uint8_t		__ures_b4;				//x6b
	uint16_t		SzorMa1;			//x6c
	uint16_t		NullMa1;			//x6e
	uint16_t		SzorMa2;			//x70
	uint16_t		NullMa2;			//x72
	uint16_t		SzorMa3;			//x74
	uint16_t		NullMa3;			//x76
	uint16_t		SzorMa4;			//x78
	uint16_t		NullMa4;			//x7a
	uint16_t	__ures_w2[2];			//x7c
	};									//x7f		max.
extern struct EEPROM_Stru	EE;
extern uint8_t				EEwrCim, EEwrDb;//ciklikus �r�shoz mutat�k
//===============================================Rutinok
#define	INT_PRIORITY_TIM2	4		//7us
#define	INT_PRIORITY_TIM4	3		//100us
#define	INT_PRIORITY_TIM3	2		//1,6ms
#define	INT_PRIORITY_TIM6	1		//1ms

extern void		TimerPllStart(void);				//Timer_Int.c
extern void		Timer2InterruptInit(void);			//Timer_Int.c
extern void		Timer3InterruptInit(void);			//Timer_Int.c
extern void		Timer4InterruptInit(void);			//Timer_Int.c
extern void		Timer6InterruptInit(void);			//Timer_Int.c

//extern void		FlsReadRow(int page,int cim);		//Rs232
//extern void		FlsWriteRow(int page,int cim);		//Rs232

extern void		RealTime1ms(void);
extern void		Delay_Ms_Alap(uint16_t time);			//time=delay in ms
extern void		Meres_100u(void);
extern void		MeresSzamol_1ms(void);

extern void		CardNev_to_LCD(uint8_t *str, uint8_t x, uint8_t y);
extern void		CardId_to_Str14(void);
//-----------------------------------------------STDIO
extern void		MemCpy(uint8_t *cel, uint8_t *forr, uint8_t db);
extern int		MemCmp(uint8_t *cel, uint8_t *forr, uint8_t db);//-1=kisebb,0egyenl?,+1=nagyobb
extern void		MemSet(uint8_t *cel, uint8_t minta, uint8_t db);
extern void		Byte_to_2i(uint8_t *ki, uint8_t be);
extern void		Byte_to_02i(uint8_t *ki, uint8_t be);
extern void		Byte_to_02x(uint8_t *ki, uint8_t be);
extern void		Byte_to_3i(uint8_t *ki, uint8_t be);
extern void		Byte_to_03i(uint8_t *ki, uint8_t be);
extern void		Word_to_05i(uint8_t *ki, uint16_t be);
extern void		Word_to_5i(uint16_t be);
extern void		Word_5i_xy(uint16_t be, uint8_t x, uint8_t y);
extern void		Dword_to_08itp(uint8_t *ki, uint32_t be, uint8_t tp);
extern void		Dword_to_10i2(uint8_t *ki, uint32_t be);//tp=2
extern void		Dword_08itp_xy(uint32_t be, uint8_t tp, uint8_t x, uint8_t y, uint8_t size);
extern void		Dword_8itp_xy(uint32_t be, uint8_t tp, uint8_t x, uint8_t y, uint8_t size);
//-----------------------------------------------Bfls.c
extern uint16_t	Fls_TankDb(uint8_t kut, char kapcs);//A=auto,E=ember
extern void		Fls_KmMax(uint8_t kut);
extern void		Fls_CegTolt(struct CEG_Stru *c, uint16_t num);
extern void		Fls_ArakTolt(struct ARAK_Stru *c, uint16_t num);
extern uint8_t	Card_SearchId(void);	//->0=nincs,1=OK->Card-ba bet�ltve
extern void		Tank_SrcUres(void);
extern void		Card_SrcUres(void);
extern void		Ceg_SrcUres(void);
extern void		Arak_SrcUres(void);
extern void		SzintTbl_Load(void);
//-----------------------------------------------CardRead.c
extern void		Rxb_Busz_35u(void);		//416,66us=2k4 (34,72us*12)
extern void		Rxc_Busz_35u(void);		//416,66us=2k4 (34,72us*12)
extern void		Rxd_Busz_35u(void);		//104,17us=9k6 (34,72us*3)
extern void		Txe_Busz_35u(void);		//104,17us=9k6 (34,72us*3)
extern void		Rxf_Busz_35u(void);		//104,17us=9k6 (34,72us*3)
extern void		Pisztoly_100us(void);
extern uint8_t	Card_Vesz(void);		//->0=ok,1..4=error
extern void		Szint_Ciklus_1ms(void);
//-----------------------------------------------Printer.c
extern void		Tank_nyomtat(uint8_t kut);
//-----------------------------------------------K�perny?k
extern void		ScrA0_init(void);
extern void		ScrA0_esemeny(void);
extern void		ScrA1_kirak(void);
extern void		ScrA1_esemeny(void);
extern void		ScrA2_init(void);
extern void		ScrA2_esemeny(void);
extern void		ScrA3_kirak(void);
extern void		ScrA3_esemeny(void);
extern void		Card_Valaszt(void);
extern void		ScrA4_kirak(uint8_t par);	//par=0 - Km t�r�l
extern void		ScrA4_esemeny(void);
extern void		ScrA5_kirak(uint8_t par);	//par=0 - Menlev t�r�l
extern void		ScrA5_esemeny(void);
extern void		ScrA6_kirak(void);
extern void		ScrA6_esemeny(void);
extern void		ScrA7_kirak(uint8_t par);	//par=0 - Uzemora t�r�l
extern void		ScrA7_esemeny(void);
extern void		ScrA8_kirak(void);
extern void		ScrA8_kiLe(void);
extern void		ScrA8_esemeny(void);
extern void		ScrA9_kirak(uint8_t par);	//par=0 - emberk�d t�r�l	- Emberk�d bevitel
extern void		ScrA9_esemeny(void);
extern void		ScrA10_kirak(uint8_t par);	//par=0 - Mennyiseg t�r�l
extern void		ScrA10_esemeny(void);
extern void		ScrAstop_kirak(uint8_t par);//par=0 - Stop=0
extern void		ScrAstop_esemeny(void);

extern void		ScrH1_kirak(void);
extern void		ScrH1_esemeny(void);
extern void		ScrH2_kirak(void);
extern void		ScrH2_esemeny(void);
extern void		ScrH3_kirak(void);
extern void		ScrH3_esemeny(void);

extern void		ScrS1_kirak(void);
extern void		ScrS1_esemeny(void);
extern void		ScrS2_kirak(void);
extern void		ScrS2_esemeny(void);
extern void		ScrS3_kirak(void);
extern void		ScrS3_esemeny(void);
extern void		ScrS4_kirak(void);
extern void		ScrS4_esemeny(void);
extern void		ScrS5_kirak(void);
extern void		ScrS5_esemeny(void);
extern void		ScrS6_kirak(void);
extern void		ScrS6_esemeny(void);
extern void		ScrS7_kirak(void);
extern void		ScrS7_esemeny(void);
extern void		ScrS8_kirak(void);
extern void		ScrS8_esemeny(void);
extern void		ScrS9_kirak(void);
extern void		ScrS9_esemeny(void);
extern void		ScrS10_kirak(void);
extern void		ScrS10_esemeny(void);
extern void		ScrS11_kirak(void);
extern void		ScrS11_esemeny(void);
//===============================================END
#endif
