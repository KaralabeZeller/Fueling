//-----------------------------------------------
// Szerviz k�rty�k k�perny�
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrS4_kirak(void)
{
Mnu.Num= MENU_S4;
Lcd_Clear();
SzovKi(&ScrS4[0]);
SzovKi(&ScrS4[1]);
SzovKi(&TxtVISSZA);
if(EE.Vez&B_VEZ_CARD2)	SzovKi(&ScrS4[3]);	//Card2
else					SzovKi(&ScrS4[2]);	//Card1
}
//===============================================Alap
void	ScrS4_esemeny(void)
{
uint8_t	g= M.Gomb;

M.Gomb= GOMB_NO;								//t�r�l
if		(g == GOMB_TOR)	ScrS2_kirak();		//Szerviz f�men� k�perny�
else if	(g == 1){
	if(EEwrDb > 0) return;					//v�r
	EE.Vez^=B_VEZ_CARD2;
	EEwrCim=EECIM_VEZ; EEwrDb=1;
	ScrS4_kirak();
	}
}
//===============================================END
