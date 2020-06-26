//-----------------------------------------------
// F�men� alap k�perny�
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//-----------------------------------------------
void	ScrA1_kiir(void)
{
uint16_t		i, x, stat;
char			ch= 'E';		//E-Bels� szoftver hiba

Mnu.Num= MENU_A1;
Mnu.Villog= 0;
Lcd_Clear();
SzovKi(&ScrA1_Ratio);
SzovKi(&ScrA1_tel);

if(Mnu.ScrA1Vill == 0)	{ Mnu.ScrA1Vill= 1; }
else			  		{ Mnu.ScrA1Vill= 0; SzovKi(&ScrA1_valassz); }

for(i=0,x=0; i<KUTFO_DB; i++){
	if((EE.KutStat[i]&0x01) != 0){									//bekapcsolva
		stat= Kut[i].Stat;
		if((EE.KutStat[i]&0x04) != 0) stat= STA_ALAP_FENT;			//virtu�lis k�tfo
		if((Mnu.ScrA1Vill == 0)||(stat == STA_ALAP_FENT)){			//villogtat�s vagy 1-v�r
			if(i < 9){		//0..8
				ch= i+'1';		G_Kar2_Ki(x, 0, C2_SZEL+1, ch);		//(x, y, w, ch)
				}
			else{
				ch= '1';		G_Kar2_Ki(x, 0, C2_SZEL, ch);
				ch= i-9+'0';	G_Kar2_Ki(x+C2_SZEL-4, 0, C2_SZEL, ch);
				}
			}
		else{
			switch(stat){
				case STA_KIKAPCS:	ch= '-'; break;		//0-_UTOTIM	reset/disable
				case STA_SUM1:		ch= '1'; break;		//1-szumma1 kijelz�se
				case STA_SUM2:		ch= '2'; break;		//2-szumma2 kijelz�se
				case STA_ALAP_LENT:	ch= 'P'; break;		//P-Pisztoly lent alap
				case STA_TANK_KI:	ch= 'K'; break;		//K-Kikapcs tankol�s
				case STA_TANK_BE:	ch= 'T'; break;		//T-Tankol
		
				case STA_VEGE_LIM:
				case STA_VEGE_FEJ:
				case STA_VEGE_IDO:
				case STA_VEGE_LOP:
				case STA_VEGE_FESZ:	ch= 'M'; break;		//M-Ment-adatb�zisba v�gk�dok

				case STA_STOP_LIM:
				case STA_STOP_FEJ:
				case STA_STOP_IDO:	ch= 'S'; break;		//S-Stop
				case STA_STOP_LOP:	ch= 'L'; break;		//L-Lop�s
				case STA_STOP_FESZ:	ch= 'F'; break;		//F-Fesz

				case STA_UJRAVAR:	ch= 'U'; break;		//U-4mp		miden ut�n k�telez� nyugi
				case STA_HIBA:		ch= 'H'; break;		//H-Hiba
				case STA_TIMEOUT:	ch= 'I'; break;		//I-Id�
				case STA_KAPCSOLAT:	ch= 'N'; break;		//N-Net
				}
			G_Kar1_Ki(x, 0, ch);
			}
		if(i < 9)	x+= 5+C2_SZEL;
		else		x+= 5+C2_SZEL*2-4;
		}
	}
}
//-----------------------------------------------
void	ScrA1_kirak(void)
{
M.Gomb2= GOMB_NO; M.Gomb= GOMB_NO;				//gombok el��let t�r�l
ScrA1_kiir();
}
//-----------------------------------------------Alap
void	ScrA1_G1_G9(void)
{
uint16_t		kut, db, stat, melyik;

for(kut=9,db=0; kut<KUTFO_DB; kut++) if(EE.KutStat[kut]&0x01) db++;		//1x-re nem v�r, ha nincs
if(db > 0){
	if((M.Gomb2 == GOMB_NO)&&(M.Gomb == 1)&&(M.Gomb2Time != 0)) return;	//01=v�r m�g
	}

for(kut=0,db=0; kut<KUTFO_DB; kut++){
	if(EE.KutStat[kut]&0x01){ db++; melyik= kut; }
	}
kut= 300;	//nincs ilyen
if((db == 1)&&(EE.Vez&B_VEZ_AUTOSTR)){						//csak ha 1db k�tfo van
	kut= melyik;											//auto kiv�laszt az egyetlen
	}
else{
	if(M.Gomb < 10){
		kut= M.Gomb-1;
		if(M.Gomb2 == 1) kut+= 10;
		}
	}
M.Gomb2= GOMB_NO; M.Gomb= GOMB_NO;						//gombok el��let t�r�l
if(kut >= KUTFO_DB) return;	//0-14

stat= Kut[kut].Stat;
switch(Tank[kut].Mentes){									//startn�l v�rakoz�s
	case MENT_ALAP:	break;									//alapban semmi
	case MENT_STR1:
	case MENT_OK_1:
	case MENT_STR2:	stat= 200; break;						//ment�sre v�r,liter kijelz�s
//	case MENT_OK_2:
	default:		Tank[kut].Mentes= MENT_ALAP; break;		//v�gzett -> �jra el�r�l
	}
if(Tank[kut].Nyomtat != 0) stat= 200;						//m�g nyomtat, liter kijelz�s
if((EE.MnuUtoTime < 255)&&(Kut[kut].UtoTime > 0)) stat= 200;//ketyeg az ut�id�
if((EE.KutStat[kut]&0x01) == 0) return;						//ha k�zben kikapcsolt�k

Mnu.Kut= kut;					//0-14						//a v�lasztott k�t elt�rol�sa
if((EE.KutStat[kut]&0x04) != 0) stat= STA_ALAP_FENT;		//virtu�lis k�tfo
switch(stat){												//l�tez�,v�laszthat� k�t-e?
	case STA_KIKAPCS:
	case STA_SUM1:
	case STA_SUM2:
						break;
	case STA_ALAP_FENT:
	case STA_ALAP_LENT:
						Kut[kut].Parancs=	STA_ALAP_FENT;	//kikapcs
						Kut[kut].Limit=		0;

						Mnu.Kutak=			0xffff;			//mindegyik enged
						Mnu.TankDbA=		0;
						Mnu.TankDbE=		0;
						Mnu.MaxLiter=		C_MAX_LITER;	//enn�l csak kisebb
						Mnu.MaxDbAuto=		C_MAX_DB;		//enn�l csak kisebb
						Mnu.MaxDbEmber=		C_MAX_DB;		//enn�l csak kisebb
						Mnu.KmElozo=		0;
						Mnu.CardVan=		0;
						Mnu.Print=			0;
						Mnu.EmberKod=		0;
						Mnu.Mennyiseg=		0;

						Tank[kut].KezdVerz=	TANK_VERZ;
						Tank[kut].KezdEv=	0;
						Tank[kut].KezdHo=	0;
						Tank[kut].KezdNap=	0;
						Tank[kut].KezdOra=	0;
						Tank[kut].KezdPerc=	0;
						Tank[kut].KezdMp=	0;

						Tank[kut].VezNum=	0;
						Tank[kut].KutNum=	0;
						Tank[kut].EmberNum=	0;
						Tank[kut].AutoNum=	0;
						Tank[kut].Csoport=	0;				//card adatok t�rl�se
						MemSet(Tank[kut].EmberId,0,7);
						MemSet(Tank[kut].AutoId,0,7);
						Tank[kut].Km=		0;
						Tank[kut].Menlev=	0;
						Tank[kut].Uzemora=	0;
						MemSet(Tank[kut].EmberNev,'.',20);
						MemSet(Tank[kut].AutoNev,'.',20);
						MemSet(Tank[kut].Gorg,0,6);
						MemSet(Tank[kut].GorgKomp,0,6);
						Tank[kut].EgysArNto=0;
						Tank[kut].TankCim=	0;
						Tank[kut].Szint=	0;

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
						Tank[kut].NyomtatDb=0;
						Tank[kut].ArNetto=	0;
						Tank[kut].ArBrutto=	0;
						Tank[kut].Sum=		0;

						Tank[kut].Mentes=	MENT_ALAP;
						Tank[kut].Print=	0;
						Tank[kut].Nyomtat=	0;
						Kut[kut].Pisztoly=	0;
						Tank[kut].Ar0Netto=	0;
						Tank[kut].Ar1Netto=	0;

						ScrA3_kirak();						//k�rtya bek�r�s
						break;
	default:			if(EE.Vez & B_VEZ_LITER) ScrA2_init();//if(Literkijelz�s==ok) �llapotki
	}
}
//-----------------------------------------------Alap
void	ScrA1_esemeny(void)
{
uint8_t		g= M.Gomb;

if		(g == 0)			ScrA0_init();		//Szint bel�p�s
else if	(g == GOMB_TOR)		ScrA1_kirak();		//t�r�l
ScrA1_G1_G9();

if(Mnu.Villog > 9) ScrA1_kiir();
Mnu.Villog++;
}
//===============================================END
