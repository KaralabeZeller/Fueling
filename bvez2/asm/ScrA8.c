//-----------------------------------------------
// Mester kártya bevitel
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
/*
Mester_to_StrA:	lds	a,MnuKm
		rcall	BCD_toX
		stsX	StrA
		lds	a,MnuKm+1
		rcall	BCD_toX
		stsX	StrA+2
		lds	a,MnuKm+2
		rcall	BCD_toX
		stsX	StrA+4
		lds	a,MnuKm+3
		rcall	BCD_toX
		stsX	StrA+6
		lds	a,MnuKm+4
		rcall	BCD_toX
		stsX	StrA+8
		clr	a
		sts	StrA+10,a
		ret
*/
//===============================================Alap
void ScrA8_kiLe(void)
{
Mnu.Num= MENU_A8;
Lcd_Clear();
SzovKi(&ScrA8[0]);
SzovKi(&ScrA8[1]);		//Kell

//Mester_to_Str();		//10szám ki
//OutTxt2(Str,40,20);
}
//-----------------------------------------------Alap
void ScrA8_kirak(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

Tank[kut].Km= 0;
Mnu.AlFaz= 0;
ScrA8_kiLe();
}
//-----------------------------------------------Alap
void ScrA8_Torol(void)
{
if(Mnu.AlFaz == 0)	ScrA1_kirak();	//Fõmenü
else				ScrA8_kirak();	//if(!üres)töröl
}
//-----------------------------------------------Alap
void ScrA8_G09(uint8_t g)
{
Mnu.AlFaz++;
//	_LCD	ScrA8txtTorol
/*
		ldiZ	str		;StrA shift
		ldd	a,z+1
		st	z,a
		ldd	a,z+2
		std	z+1,a
		ldd	a,z+3
		std	z+2,a
		ldd	a,z+4
		std	z+3,a
		ldd	a,z+5
		std	z+4,a
		ldd	a,z+6
		std	z+5,a
		ldd	a,z+7
		std	z+6,a
		ldd	a,z+8
		std	z+7,a
		ldd	a,z+9
		std	z+8,a
		lds	b,GombElo
		subi	b,-'0'
		std	z+9,b

OutTxt2(Str,40,20);

if(Mnu.AlFaz >= MESTER_AUTONUMDB) _LCD	ScrA8txtRendben
*/
}
//-----------------------------------------------Alap
void ScrA8_Bevitel(void)
{
/*	lds	a,Mnu.AlFaz
	;*	tst		a
	;*	brne	ScrA8_Be01
	;*	rjmp	SrcA3_Tovabb	;0-> nem kell
ScrA8_Be01:
		cpi 	a,MESTER_AUTONUMDB
		brcc	ScrA8_BeStart	;10-> begépelte
		ret
ScrA8_BeStart:
		ldiZ	StrA
		CrdZtoCardID();	//MnuKm to CardID
		Fls_CardIn();	//Card töltés

		lds		a,CardTip
		cpi		a,CRD_JARMU
		breq	ScrA8_JoCard
		rjmp	ScrA8_kiFel	;if(nemjó)
ScrA8_JoCard:

		Card_IDtoZ(MnuAuto);
		MnuAutoNum=CardNum;
		if(MnuMaxLit > CardMaxLit) MnuMaxLit=CardMaxLit;
		
		rjmp	SrcA3_Tovabb
*/
}
//===============================================Alap
void	ScrA8_esemeny(void)
{
uint8_t	g= M.Gomb;

M.Gomb= GOMB_NO;							//töröl
if		(g < 10)		ScrA8_G09(g);
else if	(g == GOMB_TOR)	ScrA8_Torol();
else if	(g == GOMB_BE)	ScrA8_Bevitel();
//;*		sbrs	Sys,SYS_SOFOR
//;*		rjmp	Card_Wait
}
//===============================================END
