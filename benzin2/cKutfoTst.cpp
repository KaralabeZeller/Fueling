#include <vcl.h>
#pragma hdrstop
#include "cVezerlo.h"
#include "cModBusSoros.h"
#include "cKutfoTst.h"
#include "cTxtBenzin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TKutfoTst *KutfoTst;
//---------------------------------------------------------------------------
__fastcall TKutfoTst::TKutfoTst(TComponent* Owner):TForm(Owner)
{
Kut=0;
}
//---------------------------------------------------------------------------
void __fastcall TKutfoTst::FormActivate(TObject *Sender)
{
int	i;

Caption=				TxtKutfoTst[0][Nyelv];

Kutfo->Items->Clear();
for(i=0; i<15; i++) Kutfo->Items->Add(s.sprintf("%i.%s",i+1,TxtKutfoTst[1][Nyelv]));
Kutfo->ItemIndex=Kut;

LabHiba->Caption=		TxtKutfoTst[2][Nyelv];
LabParancs->Caption=    	TxtKutfoTst[3][Nyelv];
LabKimit->Caption=		TxtKutfoTst[4][Nyelv];
LabStatusz->Caption=    	TxtKutfoTst[5][Nyelv];

LabFej->Caption=    	TxtKutfoTst[6][Nyelv];
LabKezi->Caption=    	TxtKutfoTst[7][Nyelv];
LabSum1->Caption=    	TxtKutfoTst[8][Nyelv];
LabSum2->Caption=    	TxtKutfoTst[9][Nyelv];
LabLopCl->Caption=    	TxtKutfoTst[10][Nyelv];
LabRele->Caption=    	TxtKutfoTst[11][Nyelv];
LabVez->Caption=    	TxtKutfoTst[12][Nyelv];
LabKomp->Caption=    	TxtKutfoTst[13][Nyelv];

LabGyurus->Caption=    	TxtKutfoTst[14][Nyelv];
LabHomerseklet->Caption= TxtKutfoTst[15][Nyelv];

LabLiterKomp->Caption=   TxtKutfoTst[16][Nyelv];
LabGorgetettKomp->Caption=TxtKutfoTst[17][Nyelv];
LabLiter->Caption=    	TxtKutfoTst[18][Nyelv];
LabGorgetett->Caption=   TxtKutfoTst[19][Nyelv];

LabLiterOld->Caption=    TxtKutfoTst[20][Nyelv];
LabTimeOut->Caption=	TxtKutfoTst[21][Nyelv];
LabUtovilagitas->Caption=TxtKutfoTst[22][Nyelv];
}
//---------------------------------------------------------------------------
void __fastcall TKutfoTst::Timer50ms(void)
{
int	res=MemRead(be,RD_KUT+Kut,40);
Byte jel;

if(res == 0){
	KiHiba->Caption=	be[0];				//x00	n*150ms hibaszámláló
	KiParancs->Caption=	s.sprintf("%2i",be[1]);	//x01	kút vezérlés kiírása(kútfõben nem használt)
	KiLimit->Caption=	(int)be[3]*256+be[2];	//x02	tankolható liter
	switch(be[4]){							//x04	Státusz - Kut logika állapota beolvasva
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
		case 19:	s="19-TIMEOUT"; break;		//		-		BVEZ2 timeout
		default:	s.sprintf("%i-ROSSZ KÓD",be[4]); break;
		}
	KiStat->Caption=s;

	jel=be[5];							//x05	Jelek
	if(jel & 0x01) s="1"; else s="0"; KiFej->Caption=s;	//JEL_FEJ		0-fej fent
	if(jel & 0x02) s="1"; else s="0"; KiKezi->Caption=s;	//JEL_KEZI	1
	if(jel & 0x04) s="1"; else s="0"; KiSum1->Caption=s;	//JEL_SUM1	2
	if(jel & 0x08) s="1"; else s="0"; KiSum2->Caption=s;	//JEL_SUM2	3
	if(jel & 0x10) s="1"; else s="0"; KiLopCl->Caption=s;	//JEL_LOPCL	4
	if(jel & 0x20) s="1"; else s="0"; KiRele->Caption=s;	//JEL_RELE	5
	if(jel & 0x40) s="1"; else s="0"; KiVez->Caption=s;	//JEL_VEZ		6
	if(jel & 0x80) s="1"; else s="0"; KiKomp->Caption=s;	//JEL_KOMP	7	//		-	1=kompenzált,0=nem kompenzált kijelzés

	KiLiterKomp->Caption=s.sprintf("%9.2f",(((float)be[0x09]*2.56+be[0x08])*2.56+be[0x07])*2.56+be[0x06]*0.01);//Dword LitKomp;x06	Kompenzált liter
	KiLiter->Caption=	s.sprintf("%9.2f",(((float)be[0x0d]*2.56+be[0x0c])*2.56+be[0x0b])*2.56+be[0x0a]*0.01);//Dword Liter;x0a	Alap liter
	KiHom->Caption=	s.sprintf("%5.1f",(float)be[0x0f]*25.6+be[0x0e]*0.1-40);//Word Hom;x0e Hõmérséklet
	KiGorg->Caption=	s.sprintf("%02i%02i%02i%02i%02i.%02i",be[0x10],be[0x11],be[0x12],be[0x13],be[0x14],be[0x15]);//Byte Gorg[6];x10 6b Görgetett
	KiGorgKomp->Caption=s.sprintf("%02i%02i%02i%02i%02i.%02i",be[0x16],be[0x17],be[0x18],be[0x19],be[0x1a],be[0x1b]);//Byte GorgKomp[6];x16 6b Kompenzált görgetett
//	Word		Sum;			//x1c	szumma
	KiLiterOld->Caption=s.sprintf("%9.2f",(((float)be[0x23]*2.56+be[0x22])*2.56+be[0x21])*2.56+be[0x20]*0.01);//Dword LiterOld;x20	Timeouthoz elõzõ
	KiTimeOut->Caption=	s.sprintf("%5i",(int)be[0x25]*256+be[0x24]);	//Word TimeOut;x24	*1ms Timeout
	KiUtoVil->Caption=	s.sprintf("%3i",be[0x26]);				//Byte UtoTime;x26	*1s ScrA2 utánvilágítás
	KiPisztoly->Caption=s.sprintf("%i",be[0x27]);				//Byte Pisztoly;x27	0=kártya, 1=pisztoly tankolás vezérlés
	}
GroupKutfo->Caption=s.sprintf(" %i.%s ",Kut+1,/*Kútfõ*/TxtKutfoTst[1][Nyelv]);
PacketKi->Caption=s.sprintf("%i",PacketOK);
ErrorKi->Caption=s.sprintf("%i",PacketERR);
}
//---------------------------------------------------------------------------
void __fastcall TKutfoTst::KutfoChange(TObject *Sender)
{
int	kut=Kutfo->ItemIndex;
if(kut < 0)	kut=0;
if(kut > 14)	kut=14;
Kut=kut;	//0-14
}
//---------------------------------------------------------------------------
void __fastcall TKutfoTst::BuStatClrClick(TObject *Sender)
{
PacketOK=0;
PacketERR=0;
}
//---------------------------------------------------------------------------
void __fastcall TKutfoTst::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

