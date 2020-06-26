//-----------------------------------------------
// Státusz kijelzés tankolás közben képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//-----------------------------------------------
void	ScrA2_kirak(void)
{
uint8_t		hom;
uint32_t	liter;
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

Mnu.Num= MENU_A2;
Mnu.Villog= 0;
Lcd_Clear();
SzovKi(&TxtVISSZA);

switch(Kut[kut].Stat){	//0..14
	case STA_KIKAPCS:	SzovKi(&ScrA2[0]); break;	//Kikapcs
	case STA_ALAP_FENT:	SzovKi(&ScrA2[1]); break;	//FejFent
	case STA_SUM1:		SzovKi(&ScrA2[2]); break;	//Sum1
	case STA_SUM2:		SzovKi(&ScrA2[3]); break;	//Sum2
	case STA_ALAP_LENT:	SzovKi(&ScrA2[4]); break;	//tank kezd + limit vár(fej lent)
	case STA_TANK_KI:	SzovKi(&ScrA2[5]); break;	//tankolás szivattyú ki
	case STA_TANK_BE:	SzovKi(&ScrA2[6]); break;	//tankolás szivattyú be
	case STA_VEGE_LIM:	SzovKi(&ScrA2[7]); break;	//vége limit járt le
	case STA_VEGE_FEJ:	SzovKi(&ScrA2[8]); break;	//vége fej lett visszarakva
	case STA_VEGE_IDO:	SzovKi(&ScrA2[9]); break;	//vége idõhatár lejárt
	case STA_VEGE_LOP:	SzovKi(&ScrA2[10]); break;	//vége lopás
	case STA_VEGE_FESZ:	SzovKi(&ScrA2[11]); break;	//vége kisfesz
	case STA_STOP_LIM:	SzovKi(&ScrA2[12]); break;	//mentés (limit járt le)
	case STA_STOP_FEJ:	SzovKi(&ScrA2[13]); break;	//mentés (fej lett visszarakva)
	case STA_STOP_IDO:	SzovKi(&ScrA2[14]); break;	//mentés (idõhatár lejárt)
	case STA_STOP_LOP:	SzovKi(&ScrA2[15]); break;	//Slopas	vár limit=0-ra (idõhatár lejárt)
	case STA_STOP_FESZ:	SzovKi(&ScrA2[16]); break;	//Sfesz		vár limit=0-ra (idõhatár lejárt)
	case STA_UJRAVAR:	SzovKi(&ScrA2[17]); break;	//Var		miden után kötelezõ nyugi
	case STA_HIBA:									//H-Hiba
	case STA_TIMEOUT:								//I-Idõ
	case STA_KAPCSOLAT:								//N-Net
	default:			SzovKi(&ScrA2[18]); break;	//Error		valami nem stimmelt
	}
if(Kut[kut].Jel&JEL_KOMP){ liter=Kut[kut].LitKomp; hom= CHR_HOM; }//hõmérõ jel	
else					 { liter=Kut[kut].Liter; hom= CHR_NOHOM; }//áthúzott hõmérõ jel

if(kut > 8){ Str[0]='1'; Str[1]='0'+kut-9; Str[2]=':'; OutStr2(3,0,14); }	//két szám
else{		 Str[0]='1'+kut; Str[1]=':'; OutStr2(2,0,14); }					//egy szám

if(EE.Vez&B_VEZ_LITER){
	Dword_8itp_xy(liter,2,25,14,3);
	G_Kar2_Ki(225,26,16,'l');
	}
G_Kar2_Ki(225, 0,16,hom);

if(Kut[kut].UtoTime > 0) SzovKi(&ScrA2[19]);	//Tankolás gomb

#if		C_SEBESSEG==1
	uint16	seb;
	liter= Kut[kut].sebes[0]-Kut[kut].sebes[6];	//6mp 0,01 liter fogyasztása
	if(liter > 65000) seb= 65000; else seb= (uint16)liter;//max.650 l/6mp = 6500 l/p
	liter= WmulWtoDW(seb, 6554);//*10/100*65536	//*10(6mp->1p) /100(0.01->1 liter)
	seb= *(((uint16*)&liter)+1);//liter/0x10000;
	Word_5i_xy(seb, 80, 52);//y:80-177=97(12betu)
	SzovKi(&ScrA2[20]);
#endif
}
//-----------------------------------------------
void	ScrA2_init(void)
{
Mnu.Timeout= EE.MnuTimeout;
ScrA2_kirak();
}
//===============================================Alap
void	ScrA2_esemeny(void)
{
uint8_t		g= M.Gomb;
uint8_t		kut= Mnu.Kut;
uint8_t		vege= 0;

M.Gomb= GOMB_NO;									//töröl
if(g == GOMB_TOR)			vege= 1;				//kézi vissza

if(EE.MnuTimeout < 255)								//nincs kikapcsolva
	if(Mnu.Timeout == 0)	vege= 1;				//lejárt a Timeout

if(kut < 15){
	if(g == GOMB_BE)		Kut[kut].UtoTime= 0;
	if(Kut[kut].Parancs == STA_ALAP_FENT){			//vége a tankolásnak
		if		(EE.MnuUtoTime == 0)	vege= 1;	//utótime=0, azonnal vége
		else if	(EE.MnuUtoTime < 255){				//be van állítva valami
			if(Kut[kut].UtoTime == 0)	vege= 1;	//lejárt az utóidõ
			}
		else							vege= 1;	//=255, sosincs vége, csak kézzel
		}
	}

if(vege)	ScrA1_kirak();	//vissza Fõmenübe
else		ScrA2_kirak();	//Státusz frissítés
}
//===============================================END
