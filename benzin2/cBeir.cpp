//-------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "cBeir.h"
#include "cSoros.h"
//-------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBeir *Beir;
//-------------------------------------
__fastcall TBeir::TBeir(TComponent* Owner)
	: TForm(Owner)
{
}
//-------------------------------------
void BeirVege(void)
{
Word 	addr,dat;
Byte	ki[2]={0,0};

addr=StrToInt("0x"+Beir->CimBe->Text);
dat=StrToInt("0x"+Beir->Data->Text);
switch(Beir->Valaszt->Text[1]){
 case 'R':	if((addr>=0x0060)&&(addr<0x1000)&&(dat<0x0100)){
		 ki[0]=dat;
		 Mem_write('M',ki,addr,1);
		 }
		break;
 case 'E':
		break;
 }
Beir->Close();
}
//-------------------------------------
void __fastcall TBeir::BuOkClick(TObject *Sender)
{
BeirVege();
}
//-------------------------------------END


