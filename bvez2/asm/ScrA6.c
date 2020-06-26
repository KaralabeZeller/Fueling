//-----------------------------------------------
// Tankolhat k�perny�
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
#include "Sflash16M.h"
//===============================================Alap
void ScrA6_kirak(void)
{
uint16_t	db1, db2;

Mnu.Num= MENU_A6;
Lcd_Clear();
SzovKi(&ScrA6_MaiNap);
SzovKi(&ScrA6_Litert);
SzovKi(&ScrA6_Szer);

db1= Mnu.TankDbA; db2= Mnu.TankDbE; if(db1 < db2) db1= db2;//nagyobbat �rja ki
Word_to_05i(Str, db1+1); OutStr1(5, 110, 6);
Word_to_05i(Str, Mnu.MaxLiter); OutStr1(5, 110, 20);
if(Mnu.MaxDbAuto > Mnu.TankDbA)	db1= Mnu.MaxDbAuto-Mnu.TankDbA; else db1= 0;
if(Mnu.MaxDbEmber > Mnu.TankDbE)db2= Mnu.MaxDbEmber-Mnu.TankDbE; else db2= 0;
if(db1 > db2) db1= db2;									//kisebbiket �rja ki
Word_to_05i(Str, db1); OutStr1(5, 110, 34);
SzovKi(&TxtVISSZA);
SzovKi(&TxtRENDBEN);
}
//-----------------------------------------------Alap
void	ScrA6_Torol(void)
{
if		(EE.Vez&B_VEZ_UZEMORA)	ScrA7_kirak(1);		//�zem�ra bek�r�s
else if	(EE.Vez&B_VEZ_MENLEV)	ScrA5_kirak(1);		//Menetlev�l bek�r�s
else if	(EE.Vez&B_VEZ_KMBE)		ScrA4_kirak(1);		//Km bek�r�s
else if	(EE.Vez2&B_VEZ2_MAXSTOP)ScrAstop_kirak(1);	//maxLitStop
else							ScrA1_kirak();		//F�men�
}
//-----------------------------------------------Alap
void	ScrA6_Bevitel(void)
{
uint8_t		kut= Mnu.Kut;	//0-14
uint16_t	egysar, kozpar, mask;

if(kut >= KUTFO_DB) return;								//rossz k�tsz�m
if((M.TankDb >= FLS_TANKSTOP)||(Mnu.MaxDbAuto <= Mnu.TankDbA)||(Mnu.MaxDbEmber <= Mnu.TankDbE)){//kimer�tve
	ScrH2_kirak(); return;
	}

if(Tank[kut].Mentes != MENT_ALAP) return;			//ment�sre v�r
if(Tank[kut].Nyomtat != 0) return;					//nyomtat�sra v�r
//-----------------------------------------------Tankol�s ment�s1
Tank[kut].KezdVerz=			TANK_VERZ;				//kezd� rekord
Tank[kut].KezdEv=			Ora.Ev;					//kezd�si id�
Tank[kut].KezdHo=			Ora.Ho;
Tank[kut].KezdNap=			Ora.Nap;
Tank[kut].KezdOra=			Ora.Ora;
Tank[kut].KezdPerc=			Ora.Perc;
Tank[kut].KezdMp=			Ora.Mp;

Tank[kut].VezNum=			EE.VezNum;				//Vez�rl� sz�ma+mester
Tank[kut].KutNum=			kut+1;					//(1-15)

MemCpy(Tank[kut].Gorg,		Kut[kut].Gorg,6);		//(9.999.999.999,99l)
MemCpy(Tank[kut].GorgKomp,	Kut[kut].GorgKomp,6);	//(9.999.999.999,99l)

if((EE.KutStat[kut]&0x02) == 0){					//�rak
	egysar= Tank[kut].Ar0Netto;						//g�zolaj
	kozpar= Arak0.Ar0Netto;
	}
else{
	egysar= Tank[kut].Ar1Netto;						//benzin
	kozpar= Arak0.Ar1Netto;
	}
if		(egysar == 0)	Tank[kut].EgysArNto= 0;		//nincs �raz�s
else if	(egysar == 1)	Tank[kut].EgysArNto= kozpar;	//k�zponti �raz�s
else					Tank[kut].EgysArNto= egysar;	//egyedi �raz�s
//-----------------------------------------------szintek
mask= 0x0001<<kut;
if		(EE.Szint1Kut & mask){
	if		(EE.Szint1 == 0)	Tank[kut].Szint= 0;
	else if	(EE.Szint1 == 1)	Tank[kut].Szint= M.Ma1;
	else if	(EE.Szint1 == 2)	Tank[kut].Szint= M.Ma2;
	else						Tank[kut].Szint= Szint[0].Jo;
	}
else if	(EE.Szint2Kut & mask){
	if		(EE.Szint2 == 0)	Tank[kut].Szint= 0;
	else if	(EE.Szint2 == 1)	Tank[kut].Szint= M.Ma1;
	else if	(EE.Szint2 == 2)	Tank[kut].Szint= M.Ma2;
	else						Tank[kut].Szint= Szint[1].Jo;
	}
else if	(EE.Szint3Kut & mask){	Tank[kut].Szint= M.Ma3; }
else if	(EE.Szint4Kut & mask){	Tank[kut].Szint= M.Ma4; }
else{							Tank[kut].Szint= 0; }

Tank[kut].ZarEv=	0;				//x64
Tank[kut].ZarHo=	0;
Tank[kut].ZarNap=	0;
Tank[kut].ZarOra=	0;
Tank[kut].ZarPerc=	0;
Tank[kut].ZarMp=	0;
Tank[kut].LitKomp=	0;
Tank[kut].Liter=	0;
Tank[kut].KutHom=	0;
Tank[kut].Hibakod=	0;
Tank[kut].NyomtatDb= 0;
Tank[kut].ArNetto=	0;
Tank[kut].ArBrutto=	0;
Tank[kut].Sum=		0;
//-----------------------------------------------Els� f�lrekord k�sz
Tank[kut].Print=		Mnu.Print;					//aut� k�rty�r�l(0,1,2,9)

Kut[kut].TimeOut= KUT_TIMEOUT;						//a m�sodik f�zis stop

Tank[kut].Mentes= MENT_STR1;						//Ment�s1 start
while(Tank[kut].Mentes < MENT_OK_1);				//Ment�s1 megv�r

Mnu.CardVan= 0;

if((EE.KutStat[kut]&0x04) == 0){					//normal k�tf�
	if(Kut[kut].Pisztoly == 1)	Kut[kut].Parancs= STA_TANK_KI;//pisztoly megv�r
	else						Kut[kut].Parancs= STA_TANK_BE;//tankol�s mehet
	Kut[kut].Limit= Mnu.MaxLiter;
	
	ScrA2_init();									//St�tusz k�perny�
	}
else{												//virtu�lis k�tf�
	ScrA10_kirak(0);								//Mennyis�g bevitel k�perny�
	}
}
//===============================================Alap
void	ScrA6_esemeny(void)
{
uint8_t	g= M.Gomb;

M.Gomb= GOMB_NO;							//t�r�l
if		(g == GOMB_TOR)	ScrA6_Torol();
else if	(g == GOMB_BE)	ScrA6_Bevitel();
}
//===============================================END
