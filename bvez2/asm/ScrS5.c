//-----------------------------------------------
// Szerviz be�ll�t�sok k�perny�
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrS5_kirak(void)
{
Mnu.Num= MENU_S5;
Lcd_Clear();
SzovKi(&ScrS5[0]);
SzovKi(&ScrS5[1]);
SzovKi(&ScrS5[2]);
SzovKi(&ScrS5[3]);
SzovKi(&TxtVISSZA);
}
//===============================================Alap
void	ScrS5_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;								//t�r�l
switch(g){
	case 1:			ScrS6_kirak(); break;		//Liter kijelz�s
	case 2:			ScrS7_kirak(); break;		//Kontraszt
	case 3:			ScrS11_kirak(); break;		//OraSet
	case 4:			ScrS8_kirak(); break;		//Testre szab�s
	case GOMB_TOR:	ScrS2_kirak();				//Szerviz menu
	}
}
//===============================================END
