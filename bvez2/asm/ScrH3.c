//-----------------------------------------------
// Hiba: Ezzel a kártyával ezen a kútfõn NEM TANKOLHAT !
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrH3_kirak(void)
{
Mnu.Num= MENU_H3;
Lcd_Clear();
SzovKi(&ScrH3_Kartya);
SzovKi(&ScrH3_Kutfo);
SzovKi(&ScrH3_Nemtank);
SzovKi(&TxtVISSZA);
}
//===============================================Alap
void	ScrH3_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;						//töröl
if(g == GOMB_TOR)	ScrA1_kirak();		//Fõmenü
}
//===============================================END
