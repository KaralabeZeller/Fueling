//-----------------------------------------------
// Szerviz be�ll�t�s-literkijelz�s k�perny�
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrS6_kirak(void)
{
Mnu.Num= MENU_S6;
Lcd_Clear();
SzovKi(&ScrS6_Kijelz);	//CIM
SzovKi(&TxtVISSZA);

if(EE.Vez&B_VEZ_LITER)	SzovKi(&ScrS6_KijelBe);	//BE
else					SzovKi(&ScrS6_KijelKi);	//KI
}
//===============================================Alap
void	ScrS6_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;								//t�r�l
switch(g){
	case 1:									//Liter kijelz�s
			if(EEwrDb == 0){				//v�r
				EE.Vez^=B_VEZ_LITER;
				EEwrCim=EECIM_VEZ; EEwrDb=1;
				ScrS6_kirak();
				}
			break;
	case GOMB_TOR:
			ScrS5_kirak();					//Szerviz be�ll�t�sok
	}
}
//===============================================END
