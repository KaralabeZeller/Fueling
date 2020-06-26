#ifndef _ORAKORR_H
#define _ORAKORR_H
//-----------------------------------------------
struct	StruIdo{
	uint8_t			Ev,Ho,Nap,Ora,Perc,Mp,Wnap;		//7b	id�
	};	
struct	StruOra{
	uint8_t			Ev,Ho,Nap,Ora,Perc,Mp,Wnap;		//x00		m�rt �rt�kek
	uint8_t			BeEv,BeHo,BeNap,BeOra,BePerc,BeMp,BeWnap;//x07	be�rand�
	uint8_t			TimKomp;						//x0e		b7(0=+,1=-)  Toutput=(32768+/-(2*CALREG))*Tinput
	uint8_t			xxxHiba;						//x0f		hiba sz�ml�l�

	uint8_t			Sys_MP;							//x10		system timer - 1s alap rutin mehet
	uint8_t			Sys_PERC;						//x11		system timer - 1p alap rutin mehet
	uint8_t			PercOld;						//x12		El�z� Perc
	uint8_t			MpOld;							//x13		El�z� Mp
	uint8_t			MpError;						//x14		*0,1s ha bed�glik az �ra, 1mp-enk�nt Sys_MP
	uint8_t			PercError;						//x15		*1s ha bed�glik az �ra, 60mp-enk�nt Sys_PERC
	uint8_t			Freeze;							//x16
	uint8_t			Beall;							//x17		�rabe�ll�t�s kell
	uint8_t			NewKorr;						//x18
	uint8_t			KorrBeall;						//x19
	};												//26byte
//extern struct StruOra	Ora;						//26b		M�rt �s be�ll�tand�
//-----------------------------------------------
//#define		PIN_CCL			_LATG2				//Clock clock		KI=0
//#define		TRIS_PIN_CCL	_TRISG2
//#define		PIN_CDA			_LATG3				//Clock data		BE
//#define		TRIS_PIN_CDA	_TRISG3
//#define		PIN_CDA_BE		_RG3				//Clock data		BE
//-----------------------------------------------
extern void		ORA_PinInit(void);
extern void		Ora_Init(void);
extern uint8_t	EEprom_olv(uint8_t cim);
extern void		Ora_Cikl_100m(void);
//-----------------------------------------------END
#endif
