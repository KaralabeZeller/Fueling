//-----------------------------------------------
// Hiba: hibás kártya képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrH1_kirak(void)
{
Mnu.Num= MENU_H1;
Lcd_Clear();
SzovKi(&ScrH1_Kartya);
SzovKi(&TxtVISSZA);
CardId_to_Str14(); OutStr1(14, 55, 28);
}
//===============================================Alap
void	ScrH1_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;							//töröl
if(g == GOMB_TOR){
	if(Mnu.Back == MENU_A3)	ScrA3_kirak();	//Kártyabe
	else					ScrA1_kirak();	//Fõmenü
	}
}
//===============================================END
