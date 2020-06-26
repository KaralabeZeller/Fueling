//-----------------------------------------------
// Menetlevél bevitel képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrA5_kiLe(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

Mnu.Num= MENU_A5;
Lcd_Clear();
SzovKi(&ScrA5_Menlev);
SzovKi(&TxtVISSZA);
Dword_8itp_xy(Tank[kut].Menlev, 0, 20, 15, 3);
}
//-----------------------------------------------Alap
void ScrA5_kirak(uint8_t par)//par=0 - Menlev töröl
{
uint8_t	kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(par == 0) Tank[kut].Menlev= 0;
Mnu.AlFaz= 0;
ScrA5_kiLe();
}
//-----------------------------------------------Alap
void ScrA5_G09(uint8_t g)
{
uint8_t		kut=Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Mnu.AlFaz < 8){
	Mnu.AlFaz++;
	Tank[kut].Menlev= Tank[kut].Menlev*10+g;
	Dword_8itp_xy(Tank[kut].Menlev, 0, 20, 15, 3);
	if(Mnu.AlFaz >= 4) SzovKi(&TxtRENDBEN);
	}
}
//-----------------------------------------------Alap
void	ScrA5_Torol(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Tank[kut].Menlev > 0)	ScrA5_kirak(0);	//Töröl
else{
	if(EE.Vez&B_VEZ_KMBE)	ScrA4_kirak(1);	//Km-vissza
	else				 	ScrA1_kirak();	//Fõmenü-vissza
	}
}
//-----------------------------------------------Alap
void	ScrA5_Bevitel(void)
{
if(Mnu.AlFaz >= 4){
	if		(EE.Vez&B_VEZ_UZEMORA)	ScrA7_kirak(0);		//Üzemóra bevitel
	else if	(EE.Vez2&B_VEZ2_MAXSTOP)ScrAstop_kirak(0);	//maxLitStop
	else							ScrA6_kirak();		//Tankolhat
	}
}
//===============================================Alap
void	ScrA5_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;							//töröl
if		(g < 10)		ScrA5_G09(g);
else if	(g == GOMB_TOR)	ScrA5_Torol();
else if	(g == GOMB_BE)	ScrA5_Bevitel();
}
//===============================================END
