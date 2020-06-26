#include <vcl.h>
#pragma hdrstop
#include "cSzintmero.h"
#include "cModbusSoros.h"
#include "cTxtBenzin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TSzintmero *Szintmero;
//-----------------------------------------------
__fastcall TSzintmero::TSzintmero(TComponent* Owner):TForm(Owner)
{
}
//-----------------------------------------------
void __fastcall TSzintmero::FormActivate(TObject *Sender)
{
Caption=				TxtSzintTst[0][Nyelv];
LabCsomagok->Caption=	TxtSzintTst[1][Nyelv];
GroupMintavetel->Caption=TxtSzintTst[2][Nyelv];
BuStart->Caption=		TxtSzintTst[3][Nyelv];
BuStop->Caption=		TxtSzintTst[4][Nyelv];
BuClr->Caption=		TxtSzintTst[5][Nyelv];
BuKilep->Caption=		TxtSzintTst[6][Nyelv];

BuStop->Checked=true;
}
//-----------------------------------------------
void __fastcall TSzintmero::SzintmeroTimeTimer(TObject *Sender)//1s
{
Byte			ept[100];
AnsiString	st,s1,s2,s3,s4;
TDateTime		tim=Now();
Word			ev,ho,nap,ora,perc,mp,smp;

DecodeDate(tim,ev,ho,nap);
DecodeTime(tim,ora,perc,mp,smp);
if(MemRead(ept,RD_SZINT,96) == 0){
	st.sprintf("%04i.%02i.%02i %02i:%02i:%02i.%03i <1> ",ev,ho,nap,ora,perc,mp,smp);
	s1.sprintf("[%02x-%02x %02x %02x%02x %02x %02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x-%02x]",
		ept[0x02],ept[0x03],ept[0x04],ept[0x05],ept[0x06],ept[0x07],ept[0x08],ept[0x09],ept[0x0a],ept[0x0b],ept[0x0c],
		ept[0x0d],ept[0x0e],ept[0x0f],ept[0x10],ept[0x11],ept[0x12],ept[0x13],ept[0x14]);
	s2.sprintf(" - [%02x-%02x %02x %02x%02x %02x %02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x-%02x]",
		ept[0x18],ept[0x19],ept[0x1a],ept[0x1b],ept[0x1c],ept[0x1d],ept[0x1e],ept[0x1f],ept[0x20],ept[0x21],ept[0x22],
		ept[0x23],ept[0x24],ept[0x25],ept[0x26],ept[0x27],ept[0x28],ept[0x29],ept[0x2a]);
	s4.sprintf(" - [%05i]",(int)ept[0x2f]*256+ept[0x2e]);
	Lista->Items->Add(st+s1+s2+s3+s4);

	st.sprintf("____ __ __ __ __ __ ___ <2> ");
	s1.sprintf("[%02x-%02x %02x %02x%02x %02x %02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x-%02x]",
		ept[0x32],ept[0x33],ept[0x34],ept[0x35],ept[0x36],ept[0x37],ept[0x38],ept[0x39],ept[0x3a],ept[0x3b],ept[0x3c],
		ept[0x3d],ept[0x3e],ept[0x3f],ept[0x40],ept[0x41],ept[0x42],ept[0x43],ept[0x44]);
	s2.sprintf(" - [%02x-%02x %02x %02x%02x %02x %02x %02x%02x %02x%02x %02x%02x %02x%02x %02x%02x %02x-%02x]",
		ept[0x48],ept[0x49],ept[0x4a],ept[0x4b],ept[0x4c],ept[0x4d],ept[0x4e],ept[0x4f],ept[0x50],ept[0x51],ept[0x52],
		ept[0x53],ept[0x54],ept[0x55],ept[0x56],ept[0x57],ept[0x58],ept[0x59],ept[0x5a]);
	s4.sprintf(" - [%05i]",(int)ept[0x5f]*256+ept[0x5e]);
	Lista->Items->Add(st+s1+s2+s3+s4);
	}
}
//-----------------------------------------------
void __fastcall TSzintmero::BuClrClick(TObject *Sender)
{
Lista->Items->Clear();
}
//-----------------------------------------------
void __fastcall TSzintmero::BuStartClick(TObject *Sender)
{
SzintmeroTime->Enabled=true;
}
//-----------------------------------------------
void __fastcall TSzintmero::BuStopClick(TObject *Sender)
{
SzintmeroTime->Enabled=false;
}
//-----------------------------------------------
void __fastcall TSzintmero::BuKilepClick(TObject *Sender)
{
SzintmeroTime->Enabled=false;
Close();
}
//-----------------------------------------------
void __fastcall TSzintmero::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) BuKilepClick(Sender);
}
//-----------------------------------------------

