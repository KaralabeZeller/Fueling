//-----------------------------------------------
// Hiba: keret elfogyott képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrH2_kirak(void)
{
Mnu.Num= MENU_H2;
Lcd_Clear();
SzovKi(&ScrH2_Napi);
SzovKi(&ScrH2_Tankol);
SzovKi(&ScrH2_Kimerit);
SzovKi(&TxtVISSZA);
}
//===============================================Alap
void	ScrH2_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;						//töröl
if(g == GOMB_TOR)	ScrA1_kirak();	//Fõmenü
}
//===============================================END
