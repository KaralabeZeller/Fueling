#include <vcl.h>
#pragma hdrstop

#include "cModemInit.h"
#include "cSoros.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TModemInit *ModemInit;
//---------------------------------------------------------------------------
__fastcall TModemInit::TModemInit(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TModemInit::BuBeirClick(TObject *Sender)
{
Byte	epr[70];
int	i,resu;
AnsiString sk;

memcpy(epr,Init1->Text.c_str(),32);
memcpy(&epr[32],Init2->Text.c_str(),32);

resu=Mem_write('E',epr,0x0020,64);
if(resu==0)	sk.sprintf("Írás: Rendben");
else		sk.sprintf("Írás: Hiba (Resu=%i)",resu);
Uzen->Caption=sk;
}
//---------------------------------------------------------------------------
void __fastcall TModemInit::BuKilepClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TModemInit::BuOlvasClick(TObject *Sender)
{
Byte	epr[70];
Byte	ski[30];
int	i,resu;
AnsiString sk;

for(i=0;i<10;i++){
 resu=Mem_read('E',epr,0x0020,64);
 if(resu==0)break;
 }

sk.sprintf("Olvasás: Resu=%i Próba=%i",resu,i);
Uzen->Caption=sk;

sk.sprintf("%.32s",epr);
Init1->Text=sk;
sk.sprintf("%.32s",&epr[32]);
Init2->Text=sk;
}
//---------------------------------------------------------------------------
