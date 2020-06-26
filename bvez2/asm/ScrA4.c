//-----------------------------------------------
// Km óra bevitel képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void	ScrA4_kirak(uint8_t par)//par=0 - Km töröl
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(par == 0){ Tank[kut].Km= 0; Mnu.KmElso= 0; }
Mnu.AlFaz= 0;

Mnu.Num= MENU_A4;
Lcd_Clear();
SzovKi(&ScrA4_KmOra);
SzovKi(&TxtVISSZA);

if(EE.Vez&B_VEZ_KMNOV){
	Fls_KmMax(kut);			//Mnu.KmElozo tölt
	Dword_08itp_xy(Mnu.KmElozo, 0, 150, 0, 1);
	}
Dword_8itp_xy(Tank[kut].Km, 0, 20, 15, 3);
}
//-----------------------------------------------Alap
void	ScrA4_G09(uint8_t g)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Mnu.AlFaz < 8){
	Mnu.AlFaz++;
	Tank[kut].Km= Tank[kut].Km*10+g;
	Dword_8itp_xy(Tank[kut].Km, 0, 20, 15, 3);
	if(Mnu.AlFaz >= 4) SzovKi(&TxtRENDBEN);
	}
}
//-----------------------------------------------Alap
void	ScrA4_Tovabb(void)
{
if		(EE.Vez&B_VEZ_MENLEV)	ScrA5_kirak(0);		//Menetlevél bevitel
else if	(EE.Vez&B_VEZ_UZEMORA)	ScrA7_kirak(0);		//Üzemóra bevitel
else if	(EE.Vez2&B_VEZ2_MAXSTOP)ScrAstop_kirak(0);	//maxLitStop
else							ScrA6_kirak();		//Tankolhat
}
//-----------------------------------------------Alap
void	ScrA4_Torol(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Tank[kut].Km > 0)ScrA4_kirak(0);		//Töröl
else				ScrA1_kirak();		//Fõmenü
}
//-----------------------------------------------Alap
void	ScrA4_Bevitel(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Mnu.AlFaz == 10) ScrA4_Torol();
if(Mnu.AlFaz >= 4){
	if(EE.Vez&B_VEZ_KMNOV){
		if(Tank[kut].Km < Mnu.KmElozo){
			SzovKi(&ScrA4_KmKis);			//HIBA
			Mnu.AlFaz=10;					//hibu
			}
		}
	if(Mnu.AlFaz < 10){
		if(EE.Vez2&B_VEZ2_KMKET){			//kétszeres bekérés
			if(Mnu.KmElso == 0){
				Mnu.KmElso=Tank[kut].Km;
				Tank[kut].Km=0;
				ScrA4_kirak(1);				//Nem töröl
				SzovKi(&ScrA4_KmKetto);
				}
			else if(Mnu.KmElso == Tank[kut].Km) { ScrA4_Tovabb(); }
			else{
				SzovKi(&ScrA4_KmKulonb);	//HIBA
				Mnu.AlFaz=10;				//hibu
				}
			}
		else{ ScrA4_Tovabb(); }
		}
	}
}
//===============================================Alap
void	ScrA4_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;							//töröl
if		(g < 10)		ScrA4_G09(g);
else if	(g == GOMB_TOR)	ScrA4_Torol();
else if	(g == GOMB_BE)	ScrA4_Bevitel();
}
//===============================================END
