//-----------------------------------------------
// Szerviz változók képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrS9_kirak(void)
{
Mnu.Num= MENU_S9;
Lcd_Clear();
SzovKi(&ScrS9_Valtozok);
SzovKi(&ScrS9_Tankdb);
SzovKi(&ScrS9_Kartyak);
SzovKi(&ScrS9_Cegek);
SzovKi(&TxtVISSZA);
}
//===============================================Alap
void	ScrS9_esemeny(void)
{
uint8_t		g= M.Gomb;

Word_5i_xy(M.TankDb, 145, 14);
Word_5i_xy(M.CardDb, 145, 26);
Word_5i_xy(M.CegDb, 145, 38);

M.Gomb= GOMB_NO;							//töröl
if(g == GOMB_TOR){
	if(Mnu.Back == MENU_S2)	ScrS2_kirak();	//Szerviz fõmenü képernyõ
	else					ScrA1_kirak();	//Fõmenü
	}
}
//===============================================END
