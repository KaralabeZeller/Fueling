#include <vcl.h>
#pragma hdrstop
#include "cVezerlo.h"
#include "cModBusSoros.h"
#include "cTankTst.h"
#include "cTxtBenzin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TTankTst *TankTst;
//---------------------------------------------------------------------------
__fastcall TTankTst::TTankTst(TComponent* Owner):TForm(Owner)
{
Kut=0;
}
//---------------------------------------------------------------------------
void __fastcall TTankTst::FormActivate(TObject *Sender)
{
int	i;

Caption=				TxtTankTst[ 0][Nyelv];
GroupKezdes->Caption=	TxtTankTst[ 2][Nyelv];
LabVerzio->Caption=		TxtTankTst[ 3][Nyelv];
LabIdo1->Caption=		TxtTankTst[ 4][Nyelv];
LabVezNum->Caption=		TxtTankTst[ 5][Nyelv];
LabKutNum->Caption=		TxtTankTst[ 6][Nyelv];

LabEmberNum->Caption=	TxtTankTst[ 7][Nyelv];
LabEmberId->Caption=	TxtTankTst[ 8][Nyelv];
LabEmber->Caption=		TxtTankTst[ 9][Nyelv];

LabAutoNum->Caption=	TxtTankTst[10][Nyelv];
LabAutoId->Caption=		TxtTankTst[11][Nyelv];
LabAuto->Caption=		TxtTankTst[12][Nyelv];

LabCsoport->Caption=    	TxtTankTst[13][Nyelv];
LabKm->Caption=		TxtTankTst[14][Nyelv];
LabMenlev->Caption=		TxtTankTst[15][Nyelv];
LabUzemora->Caption=    	TxtTankTst[16][Nyelv];

LabGorgKomp->Caption=   	TxtTankTst[17][Nyelv];
LabEgysAr->Caption=		TxtTankTst[18][Nyelv];
LabSorsz->Caption=		TxtTankTst[19][Nyelv];

LabGorgetett->Caption=  	TxtTankTst[20][Nyelv];
LabSzint->Caption=		TxtTankTst[21][Nyelv];

GroupZaras->Caption=	TxtTankTst[22][Nyelv];
LabIdo2->Caption=		TxtTankTst[ 4][Nyelv];
LabNetto->Caption=		TxtTankTst[23][Nyelv];
LabNyomtat->Caption=	TxtTankTst[24][Nyelv];

LabKitKomp->Caption=	TxtTankTst[25][Nyelv];
LabHomers->Caption=		TxtTankTst[26][Nyelv];
LabBrutto->Caption=		TxtTankTst[27][Nyelv];

LabLiter->Caption=		TxtTankTst[28][Nyelv];
LabVegeKod->Caption=	TxtTankTst[29][Nyelv];
LabSum->Caption=		TxtTankTst[30][Nyelv];

Kutfo->Items->Clear();
for(i=0; i<15; i++) Kutfo->Items->Add(s.sprintf("%i.%s",i+1,TxtTankTst[ 1][Nyelv]));
Kutfo->ItemIndex=Kut;
}
//---------------------------------------------------------------------------
void __fastcall TTankTst::Timer50ms(void)
{
int		res=MemRead(be,RD_TANK+Kut*2,128),i;
Byte 	jel;
Word		sum1,sum2;
double	d;

if(res == 0){
	Ki1Verz->Caption=		s.sprintf("%04x",(int)be[1]*256+be[0]);	//Word KezdVerz;x00 =0x3001	kezdõ rekord
	Ki1Ido->Caption=		s.sprintf("%02i/%02i/%02i %02i:%02i:%02i",be[2],be[3],be[4],be[5],be[6],be[7]);//Byte KezdEv;x02 kezdési idõ
								//Byte KezdHo;x03 //Byte KezdNap;x04 //Byte KezdOra;x05 //Byte KezdPerc;x06 //Byte KezdMp;x07
	Ki1VezNum->Caption=		be[0x08];		//Byte VezNum;//x08		Vezérlõ száma+mester
	Ki1Kutnum->Caption=		be[0x09];		//Byte KutNum;//x09		(1-16)
	Ki1EmberNum->Caption=	(int)be[0x0b]*256+be[0x0a];	//Word EmberNum;x0a
	Ki1AutoNum->Caption=	(int)be[0x0d]*256+be[0x0c];	//Word AutoNum;x0c
	Ki1Csoport->Caption=	(int)be[0x0f]*256+be[0x0e];	//Word Csoport;x0e		csoport száma

//	Ki1EmberId->Caption=	s.sprintf("%010li",((((((long int)be[0x16]*256+be[0x15])*256+be[0x14])*256+be[0x13])*256+be[0x12])*256+be[0x11])*256+be[0x10]);//Byte EmberId[7];x10  6+1byte bin ->15+2számjegy
	Ki1EmberId->Caption=	s.sprintf("%02X%02X%02X%02X%02X%02X%02X",be[0x10],be[0x11],be[0x12],be[0x13],be[0x14],be[0x15],be[0x16]);
//	Ki1AutoId->Caption=		s.sprintf("%010li",((((((long int)be[0x1d]*256+be[0x1c])*256+be[0x1b])*256+be[0x1a])*256+be[0x19])*256+be[0x18])*256+be[0x17]);//Byte AutoId[7];x17
	Ki1AutoId->Caption=		s.sprintf("%02X%02X%02X%02X%02X%02X%02X",be[0x17],be[0x18],be[0x19],be[0x1a],be[0x1b],be[0x1c],be[0x1d]);

	Ki1Km->Caption=		(((int)be[0x21]*256+be[0x20])*256+be[0x1f])*256+be[0x1e];//Dword Km;x1e		(99.999.999km)
	Ki1Menlev->Caption=		(((int)be[0x25]*256+be[0x24])*256+be[0x23])*256+be[0x22];//Dword	Menlev;x22	(99.999.999)
	Ki1Uzemora->Caption=	(((int)be[0x29]*256+be[0x28])*256+be[0x27])*256+be[0x26];//Dword	Uzemora;x26

	Ki1EmberNev->Caption=	s.sprintf("%20.20s",&be[0x2a]);	//Byte EmberNev[20];x2a
	Ki1AutoNev->Caption=	s.sprintf("%20.20s",&be[0x3e]);	//Byte AutoNev[20];x3e

	Ki1Gorgetett->Caption=	s.sprintf("%02i%02i%02i%02i%02i.%02i",be[0x52],be[0x53],be[0x54],be[0x55],be[0x56],be[0x57]);//Byte Gorg[6];x52 (9.999.999.999,99l)
	Ki1GorgKomp->Caption= 	s.sprintf("%02i%02i%02i%02i%02i.%02i",be[0x58],be[0x59],be[0x5a],be[0x5b],be[0x5c],be[0x5d]);//Byte GorgKomp[6];x58 (9.999.999.999,99l)

	Ki2EgysAr->Caption=		s.sprintf("%6.2f",((float)be[0x5f]*256+be[0x5e])/100);	//Word EgysArNto;	//x5e *0.01Ft egységár netto (max 655.36,-Ft/l)
	Ki2Cim->Caption=		(int)be[0x61]*256+be[0x60];	//Word Page;x60 [0+65536] mentési pozíció=tankolás sorszáma
	KiSzint->Caption=		(int)be[0x63]*256+be[0x62];	//Word Szint;x62
//---------------------------------------
	Ki2Ido->Caption=	s.sprintf("%02i/%02i/%02i %02i:%02i:%02i",be[0x64],be[0x65],be[0x66],be[0x67],be[0x68],be[0x69]);//Byte ZarEv;x64-6b zárási idõ

	Ki2LitKomp->Caption=s.sprintf("%9.2f",((((float)be[0x6d])*2.56+(float)be[0x6c]*0.01)*256+(float)be[0x6b]*0.01)*256+be[0x6a]*0.01);//Dword LitKomp;x6a	(999.999,99l) [0-42.949.672,96]
	Ki2Liter->Caption=	s.sprintf("%9.2f",((((float)be[0x71])*2.56+(float)be[0x70]*0.01)*256+(float)be[0x6f]*0.01)*256+be[0x6e]*0.01);//Dword Liter;x6e (999.999,99l)

	Ki2Homer->Caption=	s.sprintf("%5.1f",(float)be[0x73]*25.6+be[0x72]*0.1-40);//Word	KutHom;x72

	switch(be[0x74]){							//Byte Hibakod;x74	EndStatusz
		case 0:	s=" 0-STA_KIKAPCS"; break;	//		-_UTOTIM	reset/disable
		case 1:	s=" 1-STA_ALAP_FENT"; break;	//		-		vár
		case 2:	s=" 2-STA_SUM1"; break;		//		-		szumma1 kijelzése
		case 3:	s=" 3-STA_SUM2"; break;		//		-		szumma2 kijelzése
		case 4:	s=" 4-STA_ALAP_LENT"; break;	//		-TIM_FEJ	tank kezd + limit vár(fej lent)
		case 5:	s=" 5-STA_TANK_KI"; break;	//		-_IDOHATAR	tankolás szivattyú ki
		case 6:	s=" 6-STA_TANK_BE"; break;	//		-_IDOHATAR	tankolás szivattyú be
		case 7:	s=" 7-STA_VEGE_LIM"; break;	//		-TIM_FEJ	vége limit járt le
		case 8:	s=" 8-STA_VEGE_FEJ"; break;	//		-TIM_FEJ	vége fej lett visszarakva
		case 9:	s=" 9-STA_VEGE_IDO"; break;	//		-TIM_FEJ	vége idõhatár lejárt
		case 10:	s="10-STA_VEGE_LOP"; break;	//		-TIM_FEJ	vége lopás
		case 11:	s="11-STA_VEGE_FESZ"; break;	//		-TIM_FEJ	vége kisfesz
		case 12:	s="12-STA_STOP_LIM "; break;	//		-_IDOSTOP	mentés (limit járt le)
		case 13:	s="13-STA_STOP_FEJ"; break;	//		-_IDOSTOP	mentés (fej lett visszarakva)
		case 14:	s="14-STA_STOP_IDO"; break;	//		-_IDOSTOP	mentés (idõhatár lejárt)
		case 15:	s="15-STA_STOP_LOP"; break;	//		-_IDOSTOP	vár limit=0-ra (idõhatár lejárt)
		case 16:	s="16-STA_STOP_FESZ"; break;	//		-_IDOSTOP	vár limit=0-ra (idõhatár lejárt)
		case 17:	s="17-STA_UJRAVAR"; break;	//		-4mp		miden után kötelezõ nyugi
		case 18:	s="18-STA_HIBA"; break;		//		-		valami nem stimmelt
		case 19:	s="19-STA_TIMEOUT"; break;   	//		-		BVEZ2 timeout
		case 20:	s="20-STA_KAPCSOLAT"; break; 	//		-		BVEZ2 nem látja a kútfõt
		case 21:	s="21-STA_VIRTUAL"; break; 	//		-		virtuális kútfõ
		default:	s.sprintf("%i-ROSSZ KÓD",be[0x74]); break;
		}
	Ki2Hibakod->Caption=	s;
	Ki2Nyomtat->Caption=	be[0x75];				//Byte Nyomtat;x75	0=ready,=1,2 ennyi példányt kell még nyomtatni

	d=(((double)be[0x79]*256+be[0x78])*256+be[0x77])*256+be[0x76];	//Dword ArNetto; //x76 *0.01Ft netto végösszeg
	Ki2Arnto->Caption=	s.sprintf("%6.2f",d/100);
	d=(((double)be[0x7d]*256+be[0x7c])*256+be[0x7b])*256+be[0x7a];	//Dword ArBrutto; //x7a *0.01Ft brutto végösszeg
	Ki2Arbto->Caption=	s.sprintf("%6.2f",d/100);

	sum1=((Word)be[0x7f])*256+be[0x7e]; s.sprintf("%04x",sum1);//Word ZarSum;x7e
	for(i=0,sum2=0; i<0x7e; i++) sum2+=be[i];
	if(sum1 == sum2) s+="-OK"; else s+="-HIBA";
	Ki2Sum->Caption=s;
	}
GroupKutfo->Caption=s.sprintf(" %i.%s ",Kut+1,TxtTankTst[1][Nyelv]);//Kútfõ
PacketKi->Caption=s.sprintf("%i",PacketOK);
ErrorKi->Caption=s.sprintf("%i",PacketERR);
}
//---------------------------------------------------------------------------
void __fastcall TTankTst::KutfoChange(TObject *Sender)
{
int	kut=Kutfo->ItemIndex;
if(kut < 0) kut=0;
if(kut > 14) kut=14;
Kut=kut;
}
//---------------------------------------------------------------------------
void __fastcall TTankTst::BuStatClrClick(TObject *Sender)
{
PacketOK=0;
PacketERR=0;
}
//---------------------------------------------------------------------------
void __fastcall TTankTst::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

