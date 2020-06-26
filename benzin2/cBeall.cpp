#include <vcl.h>
#pragma hdrstop
#include "cBeall.h"
#include "cTeszt.h"
#include "cTxtBenzin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBeallit *Beallit;
//---------------------------------------------------------------------------
__fastcall TBeallit::TBeallit(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBeallit::FormActivate(TObject *Sender)
{
Caption=				TxtBeall[0][Nyelv];
LabCim->Caption=		TxtBeall[1][Nyelv];
}
//---------------------------------------------------------------------------
void __fastcall TBeallit::BeallitVege(void)
{
switch(Beallit->Mut){
 case 1: Teszt->RdAddr1=StrToInt("0x"+Beallit->CimBe->Text);
	 switch(Beallit->Valaszt->Text[1]){
	  case 'R':	Teszt->BuCim1->Caption="RAM";		Teszt->Kapcs1='M'; break;
	  case 'F':	Teszt->BuCim1->Caption="FLASH";	Teszt->Kapcs1='F'; break;
	  }
	 break;
 case 2:
	 Teszt->RdAddr2=StrToInt("0x"+Beallit->CimBe->Text);
	 switch(Beallit->Valaszt->Text[1]){
	  case 'R':	Teszt->BuCim2->Caption="RAM";		Teszt->Kapcs2='M'; break;
	  case 'F':	Teszt->BuCim2->Caption="FLASH";	Teszt->Kapcs2='F'; break;
	  }
	 break;
 }
Close();
}
//---------------------------------------------------------------------------
void __fastcall TBeallit::BuOkClick(TObject *Sender)
{
BeallitVege();
}
//---------------------------------------------------------------------------
void __fastcall TBeallit::FormKeyPress(TObject *Sender, char &Key)
{
switch(Key){
  case VK_ESCAPE:	Close(); break;
  case VK_RETURN:	BeallitVege(); break;
  }
}
//---------------------------------------------------------------------------

