//-------------------------------------
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include "cTankMnt.h"
#include "cSoros.h"
#include "cTeszt.h"
#include "cVezerlo.h"
//-------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBenzMent *BenzMent;
int	Tcim,fT=-1,TError;
//-------------------------------------
__fastcall TBenzMent::TBenzMent(TComponent* Owner):TForm(Owner)
{
}
//-------------------------------------
void ToltesLeallit(void)
{
FileClose(fT);
BenzMent->Time->Enabled=false;
BenzMent->BuMegszak->Font->Color=clYellow;
}
//-------------------------------------
void __fastcall TBenzMent::TimeTimer(TObject *Sender)
{
Byte	kival[80];
char	mu[50];
int	i,resu;

  if(Tcim>0xfff0) ToltesLeallit();
  else{
    resu =Fls_read16( kival    ,Tcim,0);
    resu+=Fls_read16(&kival[16],Tcim,1);
    resu+=Fls_read16(&kival[32],Tcim,2);
    resu+=Fls_read16(&kival[48],Tcim,3);
    if(resu==0){
      for(i=0;i<6;i++) if(kival[i]!=0xff)resu=1;
      if(resu==0) ToltesLeallit();
      else{
	FileWrite(fT,kival,64);
	Tcim++;
	}
      }
    else
      TError++;
    sprintf(mu,"Tank:%5i  Javítva:%5i",Tcim,TError);
    BenzMent->Hiba->Caption=mu;
    }
}
//-------------------------------------
void __fastcall TBenzMent::BuLetoltClick(TObject *Sender)
{
FileClose(fT);
if(SaveDialog1->Execute()){
  fT=FileCreate(SaveDialog1->FileName);
  if(fT>0){
    TError=0;
    Tcim=0;
    BenzMent->Time->Enabled=true;
    BenzMent->BuMegszak->Font->Color=clNavy;
  } }
}
//-------------------------------------
void __fastcall TBenzMent::BuMegszakClick(TObject *Sender)
{
  ToltesLeallit();
}
//-------------------------------------
void __fastcall TBenzMent::FormCreate(TObject *Sender)
{
 SorosStop();
}
//-------------------------------------
void __fastcall TBenzMent::FormClose(TObject *Sender, TCloseAction &Action)
{
  ToltesLeallit();
  Vezerlo->GoTankLe->Font->Color=clNavy;
}
//-------------------------------------
