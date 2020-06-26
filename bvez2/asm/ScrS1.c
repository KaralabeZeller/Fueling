//-----------------------------------------------
// Szervizkártya bekérés képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrS1_kirak(void)
{
M.Gomb= GOMB_NO;
Mnu.Num= MENU_S1;
Lcd_Clear();
SzovKi(&ScrS1_Szerviz);
SzovKi(&TxtVISSZA);
}
//===============================================Alap
void	ScrS1_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;								//töröl
if		(g == GOMB_TOR)	ScrA1_kirak();		//Fõmenü
//else if	(g == GOMB_BE)	ScrS2_kirak();	//*** csak teszt
else if	(Card_Vesz() == 0){
	if(Card_SearchId() == 0){				//->1=nincs,2=chk error,0=OK->Card-ba betöltve
		if(Card.Tip == CRD_SZERVIZ)
			ScrS2_kirak();					//Szerviz fõmenü
		else{
			CardId_to_Str14(); OutStr1(14, 0, 14);
			MemCpy(Str, Card.Nev, 20); OutStr1(20, 0, 26);
			Byte_to_02x(&Str[0],Card.Tip); Str[2]= ':';
			Word_to_05i(&Str[3],Card.MaxLit); Str[8]= '/';
			Word_to_05i(&Str[9],Card.MaxDb);
			OutStr1(14, 0, 38);
			}
		}
	else{ CardId_to_Str14(); OutStr1(14, 0, 14); }
	}
}
//===============================================END
