#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include "cOraBe.h"
#include "cModbusSoros.h"
#include "cVezerlo.h"
#include "cTxtBenzin.h"
//-------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOraBe *OraBe;
//-------------------------------------
__fastcall TOraBe::TOraBe(TComponent* Owner):TForm(Owner)
{
}
//-------------------------------------
void __fastcall TOraBe::BuOrabeClick(TObject *Sender)
{
int			res;
Word			ev,ho,nap,ora,perc,mp,msec;
TDateTime		most=Now();
AnsiString	s;

DecodeDate(most,ev,ho,nap);
DecodeTime(most,ora,perc,mp,msec);
res=OraBeall(ev,ho,nap,ora,perc,mp,most.DayOfWeek());
if(res == 0)	KiUzen->Caption="Óra OK";
else			KiUzen->Caption=s.sprintf("HIBA:%2i",res);
}
//-------------------------------------
bool __fastcall TOraBe::OraBeolv(void)
{
AnsiString	s;

if(MemRead(ora,RW_ORA,16) == 0){
	KiDatum->Caption=s.sprintf("%02i/%02i/%02i %02i:%02i:%02i n:%i",
		ora[0],ora[1],ora[2],ora[3],ora[4],ora[5],ora[6]);
	KiBeall->Caption=s.sprintf("%02i/%02i/%02i %02i:%02i:%02i n:%i",
		ora[7],ora[8],ora[9],ora[10],ora[11],ora[12],ora[13]);
	return(true);
	}
return(false);
}
//-------------------------------------
void __fastcall TOraBe::Timer50ms(void)
{
OraBeolv();
}
//-------------------------------------
void __fastcall TOraBe::FormActivate(TObject *Sender)
{
int			k;

Caption=				TxtOraBe[0][Nyelv];
GroupIdo->Caption=		TxtOraBe[1][Nyelv];
LabUtolso->Caption=		TxtOraBe[2][Nyelv];
BuOrabe->Caption=		TxtOraBe[3][Nyelv];
GroupKorrekcio->Caption=	TxtOraBe[4][Nyelv];
LabComment->Caption=	TxtOraBe[5][Nyelv];
Elore->Caption=		TxtOraBe[6][Nyelv];
Vissza->Caption=		TxtOraBe[7][Nyelv];
BuKorrBe->Caption=		TxtOraBe[8][Nyelv];
BuVissza->Caption=		TxtOraBe[9][Nyelv];

KiUzen->Caption="---";
KiUzen2->Caption="---";
OraBeolv();
k=ora[14];
KiKorr->Caption=s.sprintf("%i",k&0x7f);
if(k&0x80)	{ Elore->Checked=true; Vissza->Checked=false; }
else			{ Elore->Checked=false; Vissza->Checked=true; }
BeKorr->Text=KiKorr->Caption;
//*1órajel a 983040-bõl percenként
//16384percenként 0..127mp
}
//-------------------------------------
void __fastcall TOraBe::BuKorrBeClick(TObject *Sender)
{
int	i;
Byte	be;

i=BeKorr->Text.ToIntDef(0);
if(i < 0) i=0;
if(i > 127) i=127;
be=(Byte)i;
KiKorr->Caption=be;
if(Elore->Checked == true) be+=0x80;	//vissza
if(OraKorrBeall(be) == 0) KiUzen2->Caption=TxtOraBe[10][Nyelv];//"OK";
else					 KiUzen2->Caption=TxtOraBe[11][Nyelv];//"HIBA!";
}
//-------------------------------------
void __fastcall TOraBe::BuVisszaClick(TObject *Sender)
{
Close();
}
//-------------------------------------
void __fastcall TOraBe::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//-------------------------------------

