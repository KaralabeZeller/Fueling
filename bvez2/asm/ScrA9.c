//-----------------------------------------------
// Emberkód bevitel képernyõ
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrA9_kiLe(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

Mnu.Num= MENU_A9;
Lcd_Clear();
SzovKi(&ScrA9_Cim);
SzovKi(&TxtVISSZA);
Dword_8itp_xy(Mnu.EmberKod, 0, 20, 15, 3);
}
//-----------------------------------------------Alap
void ScrA9_kirak(uint8_t par)//par=0 - emberkód töröl
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(par == 0) Mnu.EmberKod= 0;
Mnu.AlFaz= 0;
ScrA9_kiLe();
}
//-----------------------------------------------Alap
void ScrA9_G09(uint8_t g)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Mnu.AlFaz < 8){
	Mnu.AlFaz++;
	Mnu.EmberKod= Mnu.EmberKod*10+g;
	Dword_8itp_xy(Mnu.EmberKod, 0, 20, 15, 3);
	if(Mnu.AlFaz >= 6) SzovKi(&TxtRENDBEN);
	}
}
//-----------------------------------------------Alap
void ScrA9_Torol(void)
{
uint8_t		kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

if(Mnu.EmberKod > 0)	ScrA9_kirak(0);	//Töröl
else					ScrA3_kirak();	//Kártyabe-vissza
}
//-----------------------------------------------Alap
void ScrA9_Bevitel(void)
{

if(Mnu.AlFaz >= 6){
	Mnu.Kod[7]= Mnu.EmberKod%10; Mnu.EmberKod/= 10;
	Mnu.Kod[6]= Mnu.EmberKod%10; Mnu.EmberKod/= 10;
	Mnu.Kod[5]= Mnu.EmberKod%10; Mnu.EmberKod/= 10;
	Mnu.Kod[4]= Mnu.EmberKod%10; Mnu.EmberKod/= 10;
	Mnu.Kod[3]= Mnu.EmberKod%10; Mnu.EmberKod/= 10;
	Mnu.Kod[2]= Mnu.EmberKod%10; Mnu.EmberKod/= 10;
	Mnu.Kod[1]= Mnu.EmberKod%10; Mnu.EmberKod/= 10;
	Mnu.Kod[0]= Mnu.EmberKod%10;

	Card.Id[0]= 0;
	Card.Id[1]= Mnu.Kod[0]*16+Mnu.Kod[1];
	Card.Id[2]= Mnu.Kod[2]*16+Mnu.Kod[3];
	Card.Id[3]= Mnu.Kod[4]*16+Mnu.Kod[5];
	Card.Id[4]= Mnu.Kod[6]*16+Mnu.Kod[7];
	Card.Id[5]= 0;
	Card.Id[6]= 0;

	if(Card_SearchId() == 0){							//->1=nincs,2=chk error,0=OK->Card-ba betöltve
		if((Card.Pin == 0xffff)||(Card.Pin == 0x0000)){
			Card_Valaszt();
			}
		else{ Mnu.Pin= 0; Mnu.AlFaz= 1; }				//pinbekérés start
		}
	ScrA3_kirak();//Autó kártya tovább
	}
}
//===============================================Alap
void	ScrA9_esemeny(void)
{
uint8_t		g= M.Gomb;

M.Gomb= GOMB_NO;							//töröl
if		(g < 10)		ScrA9_G09(g);
else if	(g == GOMB_TOR)	ScrA9_Torol();
else if	(g == GOMB_BE)	ScrA9_Bevitel();
}
//===============================================END
