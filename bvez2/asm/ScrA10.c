//-----------------------------------------------
// Mennyiség bevitel képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void	ScrA10_kiLe(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

Mnu.Num= MENU_A10;
Lcd_Clear();
SzovKi(&ScrA10_Mennyi);
SzovKi(&TxtVISSZA);
Dword_8itp_xy(Mnu.Mennyiseg, 0, 20, 15, 3);
}
//-----------------------------------------------Alap
void	ScrA10_kirak(uint8_t par)//par=0 - Mennyiség töröl
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(par == 0) Mnu.Mennyiseg= 0;
Mnu.AlFaz= 0;
ScrA10_kiLe();
}
//-----------------------------------------------Alap
void	ScrA10_G09(uint8_t g)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Mnu.AlFaz < 8){
	Mnu.AlFaz++;
	Mnu.Mennyiseg= Mnu.Mennyiseg*10+g;
	Dword_8itp_xy(Mnu.Mennyiseg, 0, 20, 15, 3);
	if(Mnu.AlFaz >= 1) SzovKi(&TxtRENDBEN);
	}
}
//-----------------------------------------------Alap
void	ScrA10_Torol(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Mnu.Mennyiseg > 0) ScrA10_kirak(0);	//töröl
else ScrA1_kirak();						//visszalép
}
//-----------------------------------------------Alap
void	ScrA10_Bevitel(void)
{
uint8_t		*ki;
uint8_t		i;
uint16_t	sum;
uint32_t	dlit;
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Mnu.AlFaz >= 1){						//tankolás mentés
	Tank[kut].ZarEv=		Ora.Ev;						//zárási idõ
	Tank[kut].ZarHo=		Ora.Ho;
	Tank[kut].ZarNap=		Ora.Nap;
	Tank[kut].ZarOra=		Ora.Ora;
	Tank[kut].ZarPerc=		Ora.Perc;
	Tank[kut].ZarMp=		Ora.Mp;

	dlit= Mnu.Mennyiseg*100;					//0,01l
	Tank[kut].LitKomp=		dlit;
	Tank[kut].Liter=		dlit;
	Tank[kut].Hibakod=		STA_VIRTUAL;

	Tank[kut].NyomtatDb= 0;								//0. példány
	if		(EE.PrnDb == 1)	Tank[kut].NyomtatDb= 1;		//1. példány
	else if	(EE.PrnDb == 2)	Tank[kut].NyomtatDb= 2;		//2. példány
	else if (EE.PrnDb == 9)	{
		switch(Tank[kut].Print){						//autó kártyáról
			case 1:	Tank[kut].NyomtatDb= 1; break;
			case 2:	Tank[kut].NyomtatDb= 2; break;
			}
		}

	ki= (uint8_t*)(&Tank[kut].KezdVerz);
	for(i=0,sum=0; i<126; i++) sum+= ki[i];
	Tank[kut].Sum= sum;									//checksumma
	Tank[kut].Mentes= MENT_STR2;						//második mentés start

	if(Tank[kut].NyomtatDb > 0){
		Tank[kut].Nyomtat= Tank[kut].NyomtatDb;			//start nyomtatás
		}
	ScrA1_kirak();
	}
}
//===============================================Alap
void	ScrA10_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;							//töröl
if		(g < 10)		ScrA10_G09(g);
else if	(g == GOMB_TOR)	ScrA10_Torol();
else if	(g == GOMB_BE)	ScrA10_Bevitel();
}
//===============================================END
