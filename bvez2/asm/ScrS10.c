//-----------------------------------------------
// Szerviz rendszer képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrS10_kirak(void)
{
Mnu.Num= MENU_S10;
Lcd_Clear();
SzovKi(&ScrS10_Rendszer);
SzovKi(&ScrS10_Fejleszt);
SzovKi(&TxtVISSZA);
}
//===============================================Alap
void	ScrS10_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;						//töröl
if(g == GOMB_TOR)	ScrS2_kirak();		//Szerviz fõmenü képernyõ
}
//===============================================END
