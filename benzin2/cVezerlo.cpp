#include <vcl.h>
#pragma hdrstop
#include "cVezerlo.h"
#include "cFlsClear.h"
#include "cBenzMnt.h"
#include "cCardKonv.h"
#include "cEEpromInit.h"
#include "cOraBe.h"
#include "cSzintmero.h"
#include "cAnalog.h"
#include "cUdpalap.h"
#include "cModbusSoros.h"
#include "cCegnevek.h"
#include "cArak.h"
#include "cSzintTbl.h"
#include "cNyomtato.h"
#include "cKutfoTst.h"
#include "cTankTst.h"
#include "cTeszt.h"
#include "cGyurus.h"
#include "cUpgrade.h"
#include "cTxtBenzin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//#pragma link "CPort"
#pragma resource "*.dfm"
TVezerlo *Vezerlo;
char			mu[255];
AnsiString	s;
int			Nyelv=NYELV_AKTU; //***setup***
int			TimFaz=0;
//---------------------------------------------------------------------------
__fastcall 		TVezerlo::TVezerlo(TComponent* Owner):TForm(Owner)
{
BeKutNum->Text=			KutSzam;
InitUdp();
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::FormActivate(TObject *Sender)
{
Caption=				" "+TxtVez[0][Nyelv]+" ("VERZIO")";

GroupAdatkezeles->Caption=	TxtVez[ 1][Nyelv];
BuTankLe->Caption=		TxtVez[ 2][Nyelv];
BuKartyak->Caption=		TxtVez[ 3][Nyelv];

GroupBeallitas->Caption=	TxtVez[ 4][Nyelv];
BuCegnev->Caption=		TxtVez[ 5][Nyelv];
BuArak->Caption=			TxtVez[ 6][Nyelv];
BuModInit->Caption=		TxtVez[ 7][Nyelv];
BuOraBe->Caption=			TxtVez[ 8][Nyelv];

GroupTesztek->Caption=		TxtVez[ 9][Nyelv];
BuNyomtato->Caption=		TxtVez[10][Nyelv];
BuKutfoTeszt->Caption=		TxtVez[11][Nyelv];
BuTankTeszt->Caption=		TxtVez[12][Nyelv];
BuGyurus->Caption=		TxtVez[13][Nyelv];
BuSzint->Caption=			TxtVez[14][Nyelv];
BuAnalog->Caption=		TxtVez[15][Nyelv];
BuTeszt->Caption=			TxtVez[16][Nyelv];

GroupKapcsolat->Caption=	TxtVez[17][Nyelv];
LabIPcim->Caption=		TxtVez[18][Nyelv];
LabIPport->Caption=		TxtVez[19][Nyelv];
LabKutnum->Caption=		TxtVez[20][Nyelv];
GroupNET3soros->Caption=	TxtVez[21][Nyelv];
Soros0->Caption=			TxtVez[22][Nyelv];
Soros1->Caption=			TxtVez[23][Nyelv];
Soros2->Caption=			TxtVez[24][Nyelv];

BuUpgrade->Caption=		TxtVez[25][Nyelv];
BuTorol->Caption=			TxtVez[26][Nyelv];
BuSzintTbl->Caption=		TxtVez[27][Nyelv];
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::TimTimer(TObject *Sender)//100ms
{
if	 (Upgrade->Visible)		{ Upgrade->Timer50ms(); }
else if(NyomtatoTeszt->Visible)	{ NyomtatoTeszt->Minta50ms(); }
else if(FlsClr->Visible)		{ FlsClr->Timer50ms(); }
else if(EEpromInit->Visible)		{ EEpromInit->Timer50ms(); }
else if(BenzMent->Visible)		{ BenzMent->Timer50ms(); }
else if(CardKonv->Visible)		{ CardKonv->Timer50ms(); }
else if(Cegnevek->Visible)		{ Cegnevek->Timer50ms(); }
else if(Arak->Visible)			{ Arak->Timer50ms(); }
else if(Analog->Visible)		{ Analog->Timer50ms(); }
else{
	if(TimFaz==0){	TimFaz=1; 	if(Teszt->Visible)    	{ Teszt->Timer50ms(); return;}}
	if(TimFaz==1){	TimFaz=2;	if(OraBe->Visible)    	{ OraBe->Timer50ms(); return;}}
	if(TimFaz==2){	TimFaz=3;	if(KutfoTst->Visible)	{ KutfoTst->Timer50ms(); return;}}
	if(TimFaz==3){	TimFaz=4;	if(TankTst->Visible)	{ TankTst->Timer50ms(); return;}}
	if(TimFaz==4){	TimFaz=0;	if(Gyurus->Visible)   	{ Gyurus->Timer50ms(); return;}}
	}
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::ComboPortChange(TObject *Sender)
{
Soros->Close();
CloseUdp();
switch(ComboPort->ItemIndex){
  case 0:	Soros->Port= "COM1"; TcpUdp= 0; Soros->Open();	break;
  case 1:	Soros->Port= "COM2"; TcpUdp= 0; Soros->Open();	break;
  case 2:	Soros->Port= "COM3"; TcpUdp= 0; Soros->Open(); 	break;
  case 3:	Soros->Port= "COM4"; TcpUdp= 0; Soros->Open(); 	break;
  case 4:	Soros->Port= "COM5"; TcpUdp= 0; Soros->Open(); 	break;
  case 5:	Soros->Port= "COM6"; TcpUdp= 0; Soros->Open(); 	break;
  case 6:	Soros->Port= "COM7"; TcpUdp= 0; Soros->Open(); 	break;
  case 7:	Soros->Port= "COM8"; TcpUdp= 0; Soros->Open(); 	break;
  case 8:	InitUdp();		DinIp= 0; TcpUdp=	1;		break;
  case 9:	InitUdp();		DinIp= 1; TcpUdp= 1;		break;
  }
BuTankLe->Enabled=	true;
BuKartyak->Enabled=	true;
BuCegnev->Enabled=	true;
BuArak->Enabled=		true;
BuSzintTbl->Enabled=	true;
BuModInit->Enabled=	true;
BuOraBe->Enabled=		true;
BuNyomtato->Enabled=	true;
BuKutfoTeszt->Enabled=	true;
BuTankTeszt->Enabled=	true;
BuTeszt->Enabled=		true;
BuSzint->Enabled=		true;
BuTorol->Enabled=		true;
BuAnalog->Enabled=	true;
BuGyurus->Enabled=	true;
BuUpgrade->Enabled=	true;
}
//-------------------------------------
void __fastcall 	TVezerlo::Soros0Click(TObject *Sender)
{
SorosNum= 0;
}
//-------------------------------------
void __fastcall 	TVezerlo::Soros1Click(TObject *Sender)
{
SorosNum= 1;
}
//-------------------------------------
void __fastcall 	TVezerlo::Soros2Click(TObject *Sender)
{
SorosNum= 2;
}
//-------------------------------------
void __fastcall 	TVezerlo::BeKutNumChange(TObject *Sender)
{
int	i= BeKutNum->Text.ToIntDef(0);
if((i == 1)||(i == 2)) KutSzam= i; else KutSzam=0;
}
//-------------------------------------
void __fastcall 	TVezerlo::BuTankLeClick(TObject *Sender)
{
BenzMent->ShowModal();
}
//-------------------------------------
void __fastcall 	TVezerlo::BuKartyakClick(TObject *Sender)
{
CardKonv->ShowModal();
}
//-------------------------------------
void __fastcall 	TVezerlo::BuOraBeClick(TObject *Sender)
{
if(OraBe->Visible == true) OraBe->SetFocus(); else OraBe->Visible=true;
}
//-------------------------------------
void __fastcall 	TVezerlo::BuTesztClick(TObject *Sender)
{
if(Teszt->Visible == true) Teszt->SetFocus(); else Teszt->Visible=true;
}
//-------------------------------------
void __fastcall 	TVezerlo::BuAnalogClick(TObject *Sender)
{
Analog->ShowModal();
}
//-------------------------------------
void __fastcall 	TVezerlo::BuModInitClick(TObject *Sender)
{
EEpromInit->ShowModal();
}
//-----------------------------------------------
void __fastcall 	TVezerlo::BuCegnevClick(TObject *Sender)
{
Cegnevek->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::BuArakClick(TObject *Sender)
{
Arak->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::BuSzintTblClick(TObject *Sender)
{
SzintTbl->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::BuSzintClick(TObject *Sender)
{
Szintmero->ShowModal();
}
//-----------------------------------------------
void __fastcall 	TVezerlo::BuNyomtatoClick(TObject *Sender)
{
Soros->Close();
Soros->BaudRate= br9600;
Soros->Open();
NyomtatoTeszt->ShowModal();
Soros->Close();
Soros->BaudRate= br38400;
Soros->Open();
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::BuKutfoTesztClick(TObject *Sender)
{
if(KutfoTst->Visible == true) KutfoTst->SetFocus(); else KutfoTst->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::BuTankTesztClick(TObject *Sender)
{
if(TankTst->Visible == true) TankTst->SetFocus(); else TankTst->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::BuGyurusClick(TObject *Sender)
{
if(Gyurus->Visible == true) Gyurus->SetFocus(); else Gyurus->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::BuTorolClick(TObject *Sender)
{
FlsClr->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::BuUpgradeClick(TObject *Sender)
{
Upgrade->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::NyelvAngolClick(TObject *Sender)
{
Nyelv=NYELV__ANGOL;
FormActivate(Sender);
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::NyelvMagyarClick(TObject *Sender)
{
Nyelv=NYELV__MAGYAR;
FormActivate(Sender);
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::FormClose(TObject *Sender, TCloseAction &Action)
{
Soros->Close();
}
//---------------------------------------------------------------------------
void __fastcall 	TVezerlo::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

