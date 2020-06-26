//-----------------------------------------------
// Szerviz beállítás-kontraszt képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrS7_kirak(void)
{
Mnu.Num= MENU_S7;
Lcd_Clear();
SzovKi(&ScrS7_Kontr);
SzovKi(&ScrS7_Csokk);
SzovKi(&ScrS7_Homer);
SzovKi(&ScrS7_Kcsokk);
SzovKi(&TxtVISSZA);
}
//-----------------------------------------------Alap
void ScrS7_Ment(void)
{
if(EEwrDb > 0) return;					//vár
EEwrCim= EECIM_KONTREG; EEwrDb= 2;		//+EECIM_KONTKOMP

ScrS5_kirak();							//Szerviz beállítások
}
//===============================================Alap
void	ScrS7_esemeny(void)
{
uint8_t		g= M.Gomb;
//int		ho;

M.Gomb= GOMB_NO;						//töröl
switch(g){
	case 1:			if(EE.KontReg > 20)		EE.KontReg--; break;	//kontraszt csökkent
	case 3:			if(EE.KontReg < 255)	EE.KontReg++; break;	//kontraszt növel
	case 7:			if(EE.KontKomp > 0)		EE.KontKomp--; break;	//kompenz növel
	case 9:			if(EE.KontKomp < 140)	EE.KontKomp++; break;	//kompenz csökkent
	case GOMB_TOR:	ScrS7_Ment(); break;
	default:		Byte_to_3i(Str,EE.KontReg); OutStr1(3, 104, 0);	//Kontraszt ki
//					ho=M.Hom3-400;
//***				sprintf(Str,"%3i.%1i",ho/10,ho%10);	//Mõmérséklet ki
//					Str[5]=0; OutTxt1(Str,96,28);
					Str[0]= 'k'; Str[1]= ':';
					Byte_to_03i(&Str[2], EE.KontKomp);	//0-140	Hõmérséklet kompenzáció ki
					OutStr1(5, 150, 28);
					break;
	}
}
//===============================================END
