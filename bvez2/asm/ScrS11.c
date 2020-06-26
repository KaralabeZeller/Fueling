//-----------------------------------------------
// Szerviz beállít-Óra képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "OraKorr.h"
#include "GyorsGra.h"
//===============================================Alap
void Ora_to_Str(uint8_t *be, uint8_t vez)//vez=0 normal, egyébként csak addig
{
Str[0]= '2'; Str[1]= '0';
Byte_to_02i(&Str[2], be[0]); Str[4]= ':';		//év
Byte_to_02i(&Str[5], be[1]); Str[7]= ':';		//hó
Byte_to_02i(&Str[8], be[2]); Str[10]= ' ';		//nap
Byte_to_02i(&Str[11], be[3]); Str[13]= '.';		//óra
Byte_to_02i(&Str[14], be[4]); Str[16]= '.';		//perc
Byte_to_02i(&Str[17], be[5]);					//mp
if(vez > 0){									//üres kioltás
	switch(Mnu.AlFaz){
		case 0:		Str[2]= '.';
		case 1:		Str[3]= '.';
		case 2:		Str[5]= '.';
		case 3:		Str[6]= '.';
		case 4:		Str[8]= '.';
		case 5:		Str[9]= '.';
		case 6:		Str[11]= '.';
		case 7:		Str[12]= '.';
		case 8:		Str[14]= '.';
		case 9:		Str[15]= '.';
		case 10:	Str[17]= '.';
		case 11:	Str[18]= '.';
		}
	}
}
//-----------------------------------------------Alap
void Orakovet(void)
{
Ora_to_Str((uint8_t*)&Mnu.Obe, 1); OutStr1(19, 30, 30);
if(Mnu.AlFaz > 12) SzovKi(&TxtRENDBEN);
}
//-----------------------------------------------Alap
void ScrS11_kirak(void)
{
Mnu.Num= MENU_S11;
Lcd_Clear();
SzovKi(&TxtVISSZA);

Mnu.Obe.Ev= 0; Mnu.Obe.Ho= 0; Mnu.Obe.Nap= 0; Mnu.Obe.Ora= 0; Mnu.Obe.Perc= 0; Mnu.Obe.Mp= 0;
Mnu.AlFaz= 0;
Orakovet();
}
//-----------------------------------------------Alap
void ScrS11_G09(uint8_t g)
{
uint8_t		num= g;

if(Mnu.AlFaz < 13){
	switch(Mnu.AlFaz){
		case 0:		Mnu.Obe.Ev= 10*num; break;
		case 1:		Mnu.Obe.Ev+= num; break;
		case 2:		Mnu.Obe.Ho= 10*num; break;
		case 3:		Mnu.Obe.Ho+= num; break;
		case 4:		Mnu.Obe.Nap= 10*num; break;
		case 5:		Mnu.Obe.Nap+= num; break;
		case 6:		Mnu.Obe.Ora= 10*num; break;
		case 7:		Mnu.Obe.Ora+= num; break;
		case 8:		Mnu.Obe.Perc= 10*num; break;
		case 9:		Mnu.Obe.Perc+= num; break;
		case 10:	Mnu.Obe.Mp= 10*num; break;
		case 11:	Mnu.Obe.Mp+= num; break;
		}
	Mnu.AlFaz++;
	Orakovet();
	}
}
//-----------------------------------------------Alap
void ScrS11_Torol(void)
{
if(Mnu.AlFaz > 0)	ScrS11_kirak(); 
else				ScrS5_kirak();		//Szerviz beállítások
}
//-----------------------------------------------Alap
void Ora_Beallit(void)
{
Ora.BeEv= Mnu.Obe.Ev; Ora.BeHo= Mnu.Obe.Ho; Ora.BeNap= Mnu.Obe.Nap;
Ora.BeOra= Mnu.Obe.Ora; Ora.BePerc= Mnu.Obe.Perc; Ora.BeMp= Mnu.Obe.Mp;

if(	(Ora.BeEv > 11)&&
	(Ora.BeHo > 0)&&(Ora.BeHo < 13)&&
	(Ora.BeNap > 0)&&(Ora.BeNap < 32)&&
	(Ora.BeOra < 24)&&(Ora.BePerc < 60)&&(Ora.BeMp < 60)){
		Ora.Beall= 1;
		ScrS5_kirak();					//OK->Szerviz beállítások
		}
}
//===============================================Alap
void	ScrS11_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;							//töröl
switch(g){
	case 0:
	case 1:	
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:			ScrS11_G09(g); break;
	case GOMB_BE:	Ora_Beallit(); break;
	case GOMB_TOR:	ScrS11_Torol(); break;
	default:							//nincs nyomva semmi - követ
					Ora_to_Str(&Ora.Ev, 0); OutStr1(19, 30, 10);
					break;
	}
}
//===============================================END
