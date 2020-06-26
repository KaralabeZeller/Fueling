//-----------------------------------------------
// Üzemóra bevitel képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void	ScrA7_kiLe(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

Mnu.Num= MENU_A7;
Lcd_Clear();
SzovKi(&ScrA7_Uzemo);
SzovKi(&TxtVISSZA);
Dword_8itp_xy(Tank[kut].Uzemora, 0, 20, 15, 3);
}
//-----------------------------------------------Alap
void	ScrA7_kirak(uint8_t par)//par=0 - Uzemora töröl
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(par == 0) Tank[kut].Uzemora= 0;
Mnu.AlFaz= 0;
ScrA7_kiLe();
}
//-----------------------------------------------Alap
void	ScrA7_G09(uint8_t g)
{
uint8_t		kut=Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Mnu.AlFaz < 8){
	Mnu.AlFaz++;
	Tank[kut].Uzemora= Tank[kut].Uzemora*10+g;
	Dword_8itp_xy(Tank[kut].Uzemora, 0, 20, 15, 3);
	if(Mnu.AlFaz >= 4) SzovKi(&TxtRENDBEN);
	}
}
//-----------------------------------------------Alap
void	ScrA7_Torol(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Tank[kut].Uzemora > 0)	ScrA7_kirak(0);		//Töröl
else{
	if		(EE.Vez&B_VEZ_MENLEV)	ScrA5_kirak(1);	//Menetlevél-vissza
	else if	(EE.Vez&B_VEZ_KMBE)		ScrA4_kirak(1);	//Km-vissza
	else				 			ScrA1_kirak();	//Fõmenü-vissza
	}
}
//-----------------------------------------------Alap
void	ScrA7_Bevitel(void)
{
if(Mnu.AlFaz >= 4){
	if	(EE.Vez2&B_VEZ2_MAXSTOP)	ScrAstop_kirak(0);	//maxLitStop
	else							ScrA6_kirak();		//Tankolhat
	}
}
//===============================================Alap
void	ScrA7_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;							//töröl
if		(g < 10)		ScrA7_G09(g);
else if	(g == GOMB_TOR)	ScrA7_Torol();
else if	(g == GOMB_BE)	ScrA7_Bevitel();
}
//===============================================END
