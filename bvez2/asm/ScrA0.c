//---------------------------------------------------------
// Szint kijelzés képernyõ
//---------------------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//---------------------------------------------------------
uint16_t	SzintSzamol(uint16_t tartnum)//1,2,
{
uint16_t	i, mero, szint, mut;
uint16_t	ma, ma1, ma2, lit1, lit2;
uint32_t	dx;

switch(tartnum){
	case 4:		ma= M.Ma4; mero= 3; break;
	case 3:		ma= M.Ma3; mero= 2; break;
	case 2:		ma= M.Ma2; mero= 1; break;
	default:	ma= M.Ma1; mero= 0; break;
	}
for(i=0; i<120; i++){
	mut= i;
	ma2= M.SzintTbl[mero][i][0]; if(ma2 == 0xffff) ma2= 0;
	if(ma < ma2) break;							//áram megvan
	if((i > 0)&&(ma2 == 0)){ mut= i-1; break; }	//tábla vége
	}
if(mut < 1){							//rossz tábla
	ma1= 0;								lit1= 0; 
	ma2= M.SzintTbl[mero][0][0];		lit2= M.SzintTbl[mero][0][1];
	}
else{
	ma1= M.SzintTbl[mero][mut-1][0];	lit1= M.SzintTbl[mero][mut-1][1];
	ma2= M.SzintTbl[mero][mut][0];		lit2= M.SzintTbl[mero][mut][1];
	}
if(ma1 == 0xffff)	ma1= 0;
if(ma2 == 0xffff)	ma2= 0;
if(lit1 == 0xffff)	lit1= 0;
if(lit2 == 0xffff)	lit2= 0;

dx=		0;
if(ma2 > ma1){
	lit2-=	lit1;
	ma2-=	ma1;
	ma-=	ma1;
	dx=		WmulWtoDW(lit2,	ma);
	dx/=	ma2;		//lineáris interpol
	if(dx > 65000) dx= 65000;
	}
szint= lit1+(uint16_t)dx;
return(szint);
}
//---------------------------------------------------------
void		ScrA0_kirak(void)
{
uint16_t	liter;

Mnu.Num=	MENU_A0;
Mnu.Villog= 0;
Lcd_Clear();
SzovKi(&TxtTARTALY);
SzovKi(&TxtVISSZA);	SzovKi(&TxtSETUP);
M.Gomb2= GOMB_NO; M.Gomb= GOMB_NO;				//gombok elõélet töröl

switch(Mnu.Kut){
	case 3:		liter= SzintSzamol(4); Str[0]='4';	break;
	case 2:		liter= SzintSzamol(3); Str[0]='3';	break;
	case 1:		liter= SzintSzamol(2); Str[0]='2';	break;
	default:	liter= SzintSzamol(1); Str[0]='1';	break;
	}
Str[1]=':'; OutStr2(2, 0, 14);//egy szám
Word_to_5i(liter); OutStr3(5, 85, 14);//(db,x,y)
G_Kar2_Ki(225, 26, 16, 'l');
}
//---------------------------------------------------------
void		ScrA0_G1_G8(void)
{
switch(M.Gomb){
	case 4:		Mnu.Kut= 3; break;				//0-14
	case 3:		Mnu.Kut= 2; break;				//0-14
	case 2:		Mnu.Kut= 1; break;				//0-14
	default:	Mnu.Kut= 0;	break;				//0-14
	}
ScrA0_kirak();
}
//---------------------------------------------------------
void		ScrA0_init(void)
{
Mnu.Kut= 0;										//0-14
ScrA0_kirak();
}
//=========================================================Alap
void		ScrA0_esemeny(void)
{
uint8_t		g= M.Gomb;

if		(g == GOMB_NO)		ScrA0_kirak();		//frissítés
else if	(g == GOMB_BE)		ScrS1_kirak();		//Szerviz belépés
else if	(g == GOMB_TOR)		ScrA1_kirak();		//töröl
else						ScrA0_G1_G8();
}
//=========================================================END
