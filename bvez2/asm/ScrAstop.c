//-----------------------------------------------
// Max tankolható liter bevitel képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void	ScrAstop_kiLe(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

Mnu.Num= MENU_Astop;
Lcd_Clear();
SzovKi(&ScrAstop_Mennyi);
SzovKi(&TxtVISSZA);
Dword_8itp_xy(Mnu.LitStop, 0, 20, 15, 3);
}
//-----------------------------------------------Alap
void	ScrAstop_kirak(uint8_t par)//par=0 - Mennyiség töröl
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(par == 0) Mnu.LitStop= 0;
Mnu.AlFaz= 0;
ScrAstop_kiLe();
}
//-----------------------------------------------Alap
void	ScrAstop_G09(uint8_t g)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Mnu.AlFaz < 8){
	Mnu.AlFaz++;
	Mnu.LitStop= Mnu.LitStop*10+g;
	Dword_8itp_xy(Mnu.LitStop, 0, 20, 15, 3);
	if(Mnu.AlFaz >= 1) SzovKi(&TxtRENDBEN);
	}
}
//-----------------------------------------------Alap
void	ScrAstop_Torol(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Mnu.LitStop > 0) ScrAstop_kirak(0);		//töröl
else{										//visszalép
	if		(EE.Vez&B_VEZ_UZEMORA)	ScrA7_kirak(1);		//Üzemóra bekérés
	else if	(EE.Vez&B_VEZ_MENLEV)	ScrA5_kirak(1);		//Menetlevél bekérés
	else if	(EE.Vez&B_VEZ_KMBE)		ScrA4_kirak(1);		//Km bekérés
	else							ScrA1_kirak();		//Fõmenü
	}
}
//-----------------------------------------------Alap
void	ScrAstop_Bevitel(void)
{
if(Mnu.LitStop > 0){
	if(Mnu.MaxLiter > Mnu.LitStop) Mnu.MaxLiter= Mnu.LitStop;
	}
if(Mnu.AlFaz >= 1) ScrA6_kirak();		//Tankolhat
}
//===============================================Alap
void	ScrAstop_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;							//töröl
if		(g < 10)		ScrAstop_G09(g);
else if	(g == GOMB_TOR)	ScrAstop_Torol();
else if	(g == GOMB_BE)	ScrAstop_Bevitel();
}
//===============================================END
