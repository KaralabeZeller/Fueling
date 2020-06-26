//-----------------------------------------------
// Szerviz fõmenü képernyõ
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

M.Gomb= GOMB_NO;								//töröl
switch(g){
	case 1:			ScrS3_kirak(); break;		//Szerviz kútfõ képernyõ
	case 2:			ScrS4_kirak(); break;		//Szerviz kártyák képernyõ
	case 3:			ScrS5_kirak(); break;		//Szerviz beállítások menü képernyõ
	case 4:			Mnu.Back= MENU_S2; ScrS9_kirak(); break;//Szerviz változók képernyõ
	case 5:			ScrS10_kirak(); break;		//Szerviz rendszer képernyõ
	case GOMB_TOR:	ScrA1_kirak(); break;		//Fõmenü
	}	
}
//===============================================END
