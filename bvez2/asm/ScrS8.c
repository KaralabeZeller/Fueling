//-----------------------------------------------
// Szerviz testre szabás képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrS8_kirak(void)
{
Mnu.Num= MENU_S8;
Lcd_Clear();
SzovKi(&ScrS8[0]);								//CIM
SzovKi(&TxtVISSZA);

if(EE.Vez&B_VEZ_KMBE){
	if(EE.Vez&B_VEZ_KMNOV)	SzovKi(&ScrS8[1]);	//KMBENOV
	else					SzovKi(&ScrS8[2]);	//KMBE
	}
else						SzovKi(&ScrS8[3]);	//KMKI

if(EE.Vez&B_VEZ_MENLEV)		SzovKi(&ScrS8[4]);	//MENLBE
else						SzovKi(&ScrS8[5]);	//MENLKI

if(EE.Vez&B_VEZ_UZEMORA)	SzovKi(&ScrS8[6]);	//UZEMBE
else						SzovKi(&ScrS8[7]);	//UZEMKI
}
//-----------------------------------------------Alap
void ScrS8_Ment(void)
{
if(EEwrDb > 0) return;					//vár
EEwrCim= EECIM_VEZ; EEwrDb= 1;
ScrS8_kirak();
}
//===============================================Alap
void	ScrS8_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;						//töröl
switch(g){
	case 1:	if((EE.Vez&B_VEZ_KMBE)==0)		EE.Vez|= B_VEZ_KMBE;
			else{
				if((EE.Vez&B_VEZ_KMNOV)==0)	EE.Vez|= B_VEZ_KMNOV;
				else						EE.Vez^= B_VEZ_KMBE+B_VEZ_KMNOV;
				}
			ScrS8_Ment();
			break;
	case 2:	EE.Vez^= B_VEZ_MENLEV;	ScrS8_Ment(); break;
	case 3:	EE.Vez^= B_VEZ_UZEMORA;	ScrS8_Ment(); break;
	case GOMB_TOR:	ScrS5_kirak(); break;	//Szerviz beállítások
	}
}
//===============================================END
