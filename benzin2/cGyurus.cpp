#include <vcl.h>
#pragma hdrstop
#include "cVezerlo.h"
#include "cModBusSoros.h"
#include "cGyurus.h"
#include "cTxtBenzin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGyurus *Gyurus;
//---------------------------------------------------------------------------
__fastcall TGyurus::TGyurus(TComponent* Owner):TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGyurus::FormActivate(TObject *Sender)
{
Caption=				TxtGyurus[0][Nyelv];

GroupKapcsolat->Caption=	TxtGyurus[1][Nyelv];
LabVan->Caption=		TxtGyurus[2][Nyelv];
LabIdo->Caption=		TxtGyurus[3][Nyelv];
LabKod->Caption=		TxtGyurus[4][Nyelv];
}
//---------------------------------------------------------------------------
void __fastcall TGyurus::Timer50ms(void)
{
int		res=MemRead(be,RW_CARD,90);

if(res == 0){
	KiVan->Font->Color=clNavy;
	KiKodHex->Font->Color=clNavy;
	KiKodDec->Font->Color=clNavy;
	}
else	{
	KiVan->Font->Color=clRed;
	KiKodHex->Font->Color=clRed;
	KiKodDec->Font->Color=clRed;
	}
KiVan->Caption=	be[0x47];
KiTime->Caption=	be[0x46];
KiKodHex->Caption=	s.sprintf("%02x - %02x %02x %02x %02x - %02x",be[0x4e],be[0x4f],be[0x50],be[0x51],be[0x52],be[0x53]);
KiKodDec->Caption=	s.sprintf("%02x%02x%02x%02x%02x",be[0x48],be[0x49],be[0x4a],be[0x4b],be[0x4c],be[0x4d]);
}
//---------------------------------------------------------------------------
void __fastcall TGyurus::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

