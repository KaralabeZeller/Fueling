//-----------------------------------------------
// Szerviz k�tf� k�perny�
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void ScrS3_kiir(void)
{
uint8_t		i;

Mnu.Num= MENU_S3;
Lcd_Clear();
for(i=0; i<15; i++){
	if((EE.KutStat[i]&0x01) == 0)	Str[2*i]= '-';
	else{
		if(i < 9)			Str[2*i]= '1'+i;		//1-9
		else				Str[2*i]= '1';		//10-15
		}
	Str[2*i+1]= ' ';
	}	
OutStr1(30, 0, 20); 			//Kiirja a sz�mokat

for(i=0; i<15; i++){
	if((EE.KutStat[i]&0x01) == 0)	Str[2*i]= ' ';
	else{
		if(i < 9)			Str[2*i]= ' ';		//1-9
		else				Str[2*i]= '0'+i-9;	//10-15
		}
	Str[2*i+1]= ' ';
	}
OutStr1(30, 0, 32); 			//Kiirja a sz�mokat

SzovKi(&ScrS3_Kutfok);
SzovKi(&TxtVISSZA);
}
//-----------------------------------------------Alap
void ScrS3_kirak(void)
{
M.Gomb2= GOMB_NO; M.Gomb= GOMB_NO;				//gombok el��let t�r�l
ScrS3_kiir();
}
//-----------------------------------------------Alap
void ScrS3_KiBe(void)
{
uint8_t		i, kut= 0, sta= 0;

if((M.Gomb2 == GOMB_NO)&&(M.Gomb == 1)&&(M.Gomb2Time != 0)) return;//01=v�r m�g
if(M.Gomb2 < 2)	kut= M.Gomb2*10;	//0..1
if(M.Gomb < 10)	kut+= M.Gomb;
kut--;
M.Gomb2= GOMB_NO; M.Gomb= GOMB_NO;				//gombok el��let t�r�l

if(kut >= KUTFO_DB) return;
for(i=0; i<KUTFO_DB; i++) if((EE.KutStat[i]&0x01) > 0) sta++;//legal�bb 1 k�tf� legyen bekapcsolva
if(EEwrDb == 0){								//v�r
	if((EE.KutStat[kut]&0x01) == 0)	EE.KutStat[kut]|= 0x01;
	else if(sta > 1) 		 		EE.KutStat[kut]&= 0xfe;	//1 marad
	EEwrCim= EECIM_KUTSTAT+kut; EEwrDb= 1;
	ScrS3_kirak();
	}
}
//===============================================Alap
void	ScrS3_esemeny(void)
{
if(M.Gomb == GOMB_TOR){ M.Gomb2= GOMB_NO; M.Gomb= GOMB_NO; ScrS2_kirak(); }//Szerviz f�men� k�perny�
ScrS3_KiBe();
}
//===============================================END
