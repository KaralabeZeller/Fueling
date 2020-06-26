//-----------------------------------------------
// Szerviz f�men� k�perny�
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrS2_kirak(void)
{
Mnu.Num= MENU_S2;
Lcd_Clear();
SzovKi(&ScrS2_Menu);
SzovKi(&ScrS2_Sor1);
SzovKi(&ScrS2_Sor2);
SzovKi(&ScrS2_Sor3);
SzovKi(&TxtVISSZA);
}
//===============================================Alap
void	ScrS2_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;								//t�r�l
switch(g){
	case 1:			ScrS3_kirak(); break;		//Szerviz k�tf� k�perny�
	case 2:			ScrS4_kirak(); break;		//Szerviz k�rty�k k�perny�
	case 3:			ScrS5_kirak(); break;		//Szerviz be�ll�t�sok men� k�perny�
	case 4:			Mnu.Back= MENU_S2; ScrS9_kirak(); break;//Szerviz v�ltoz�k k�perny�
	case 5:			ScrS10_kirak(); break;		//Szerviz rendszer k�perny�
	case GOMB_TOR:	ScrA1_kirak(); break;		//F�men�
	}	
}
//===============================================END
