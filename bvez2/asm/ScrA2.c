//-----------------------------------------------
// St�tusz kijelz�s tankol�s k�zben k�perny�
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
	case STA_ALAP_LENT:	SzovKi(&ScrA2[4]); break;	//tank kezd + limit v�r(fej lent)
	case STA_TANK_KI:	SzovKi(&ScrA2[5]); break;	//tankol�s szivatty� ki
	case STA_TANK_BE:	SzovKi(&ScrA2[6]); break;	//tankol�s szivatty� be
	case STA_VEGE_LIM:	SzovKi(&ScrA2[7]); break;	//v�ge limit j�rt le
	case STA_VEGE_FEJ:	SzovKi(&ScrA2[8]); break;	//v�ge fej lett visszarakva
	case STA_VEGE_IDO:	SzovKi(&ScrA2[9]); break;	//v�ge id�hat�r lej�rt
	case STA_VEGE_LOP:	SzovKi(&ScrA2[10]); break;	//v�ge lop�s
	case STA_VEGE_FESZ:	SzovKi(&ScrA2[11]); break;	//v�ge kisfesz
	case STA_STOP_LIM:	SzovKi(&ScrA2[12]); break;	//ment�s (limit j�rt le)
	case STA_STOP_FEJ:	SzovKi(&ScrA2[13]); break;	//ment�s (fej lett visszarakva)
	case STA_STOP_IDO:	SzovKi(&ScrA2[14]); break;	//ment�s (id�hat�r lej�rt)
	case STA_STOP_LOP:	SzovKi(&ScrA2[15]); break;	//Slopas	v�r limit=0-ra (id�hat�r lej�rt)
	case STA_STOP_FESZ:	SzovKi(&ScrA2[16]); break;	//Sfesz		v�r limit=0-ra (id�hat�r lej�rt)
	case STA_UJRAVAR:	SzovKi(&ScrA2[17]); break;	//Var		miden ut�n k�telez� nyugi
	case STA_HIBA:									//H-Hiba
	case STA_TIMEOUT:								//I-Id�
	case STA_KAPCSOLAT:								//N-Net
	default:			SzovKi(&ScrA2[18]); break;	//Error		valami nem stimmelt
	}
if(Kut[kut].Jel&JEL_KOMP){ liter=Kut[kut].LitKomp; hom= CHR_HOM; }//h�m�r� jel	
else					 { liter=Kut[kut].Liter; hom= CHR_NOHOM; }//�th�zott h�m�r� jel

if(kut > 8){ Str[0]='1'; Str[1]='0'+kut-9; Str[2]=':'; OutStr2(3,0,14); }	//k�t sz�m
else{		 Str[0]='1'+kut; Str[1]=':'; OutStr2(2,0,14); }					//egy sz�m

if(EE.Vez&B_VEZ_LITER){
	Dword_8itp_xy(liter,2,25,14,3);
	G_Kar2_Ki(225,26,16,'l');
	}
G_Kar2_Ki(225, 0,16,hom);

if(Kut[kut].UtoTime > 0) SzovKi(&ScrA2[19]);	//Tankol�s gomb

#if		C_SEBESSEG==1
	uint16	seb;
	liter= Kut[kut].sebes[0]-Kut[kut].sebes[6];	//6mp 0,01 liter fogyaszt�sa
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

M.Gomb= GOMB_NO;									//t�r�l
if(g == GOMB_TOR)			vege= 1;				//k�zi vissza

if(EE.MnuTimeout < 255)								//nincs kikapcsolva
	if(Mnu.Timeout == 0)	vege= 1;				//lej�rt a Timeout

if(kut < 15){
	if(g == GOMB_BE)		Kut[kut].UtoTime= 0;
	if(Kut[kut].Parancs == STA_ALAP_FENT){			//v�ge a tankol�snak
		if		(EE.MnuUtoTime == 0)	vege= 1;	//ut�time=0, azonnal v�ge
		else if	(EE.MnuUtoTime < 255){				//be van �ll�tva valami
			if(Kut[kut].UtoTime == 0)	vege= 1;	//lej�rt az ut�id�
			}
		else							vege= 1;	//=255, sosincs v�ge, csak k�zzel
		}
	}

if(vege)	ScrA1_kirak();	//vissza F�men�be
else		ScrA2_kirak();	//St�tusz friss�t�s
}
//===============================================END
