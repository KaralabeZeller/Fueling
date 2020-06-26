#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include "cVezerlo.h"
#include "cTeszt.h"
#include "cBeall.h"
#include "cModBusSoros.h"
#include "cTxtBenzin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TTeszt *Teszt;

Byte	kiir[270];
int	Fazis=0;	//Timer fázis
//---------------------------------------------------------------------------
void	Kiir1_16(int cim,Byte* ki,Byte resu,Byte Index)
{
int 	i;
char	mu[10],kistr[17];

sprintf(mu,"%05x.%02x>%2i",cim,Index*0x10,resu); Teszt->Ki1->Cells[0][Index]=mu;
if(resu==0){
  for(i=0; i<8; i++){
    sprintf(mu,"%02x %02x",ki[2*i],ki[2*i+1]);
    Teszt->Ki1->Cells[i+1][Index]=mu;
    if(ki[2*i]<' ')		kistr[2*i]='.'; else kistr[2*i]=ki[2*i];
    if(ki[2*i+1]<' ')	kistr[2*i+1]='.'; else kistr[2*i+1]=ki[2*i+1];
    }
  kistr[16]=0; Teszt->Ki1->Cells[9][Index]=kistr;
  }
}
//---------------------------------------------------------------------------
void	Kiir2_16(int cim,Byte* ki,Byte resu,Byte Index)
{
int 	i;
char	mu[10],kistr[17];

sprintf(mu,"%05x.%02x>%2i",cim,Index*0x10,resu); Teszt->Ki2->Cells[0][Index]=mu;
if(resu==0){
  for(i=0; i<8; i++){
    sprintf(mu,"%02x %02x",ki[2*i],ki[2*i+1]);
    Teszt->Ki2->Cells[i+1][Index]=mu;
    if(ki[2*i]<' ')		kistr[2*i]='.'; else kistr[2*i]=ki[2*i];
    if(ki[2*i+1]<' ')	kistr[2*i+1]='.'; else kistr[2*i+1]=ki[2*i+1];
    }
  kistr[16]=0; Teszt->Ki2->Cells[9][Index]=kistr;
  }
}
//---------------------------------------------------------------------------
__fastcall TTeszt::TTeszt(TComponent* Owner):TForm(Owner)
{
Kapcs1='M';		Kapcs2='M';
RdAddr1=0x00000;	RdAddr2=0x00000;
}
//---------------------------------------------------------------------------
void __fastcall TTeszt::FormActivate(TObject *Sender)
{
Caption=				TxtTeszt[0][Nyelv];
}
//---------------------------------------------------------------------------
void __fastcall TTeszt::BuCim1Click(TObject *Sender)
{
Beallit->Mut=1;
Beallit->Valaszt->Text=BuCim1->Caption;
Beallit->CimBe->Text=IntToHex(RdAddr1,5);
Beallit->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TTeszt::BuCim2Click(TObject *Sender)
{
Beallit->Mut=2;
Beallit->Valaszt->Text=BuCim2->Caption;
Beallit->CimBe->Text=IntToHex(RdAddr2,5);
Beallit->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TTeszt::Timer50ms(void)
{
int	res,cim;

if(Fazis == 0){
	Fazis=1;
	if(Kapcs1=='F'){
		res=FlashRead(kiir,RdAddr1/2,(RdAddr1&0x01)*128,128);
		Kiir1_16(RdAddr1, kiir    ,res,0);
		Kiir1_16(RdAddr1,&kiir[16],res,1);
		Kiir1_16(RdAddr1,&kiir[32],res,2);
		Kiir1_16(RdAddr1,&kiir[48],res,3);
		Kiir1_16(RdAddr1,&kiir[64],res,4);
		Kiir1_16(RdAddr1,&kiir[80],res,5);
		Kiir1_16(RdAddr1,&kiir[96],res,6);
		Kiir1_16(RdAddr1,&kiir[112],res,7);
		}
	else{
		res=MemRead(kiir,RdAddr1,128);
		Kiir1_16(RdAddr1, kiir    ,res,0);
		Kiir1_16(RdAddr1,&kiir[16],res,1);
		Kiir1_16(RdAddr1,&kiir[32],res,2);
		Kiir1_16(RdAddr1,&kiir[48],res,3);
		Kiir1_16(RdAddr1,&kiir[64],res,4);
		Kiir1_16(RdAddr1,&kiir[80],res,5);
		Kiir1_16(RdAddr1,&kiir[96],res,6);
		Kiir1_16(RdAddr1,&kiir[112],res,7);
		}
	}
else	{
	Fazis=0;
	if(Kapcs2=='F'){
		res=FlashRead(kiir+128,RdAddr2/2,(RdAddr2&0x01)*128,128);
		Kiir2_16(RdAddr2,&kiir[128],res,0);
		Kiir2_16(RdAddr2,&kiir[144],res,1);
		Kiir2_16(RdAddr2,&kiir[160],res,2);
		Kiir2_16(RdAddr2,&kiir[176],res,3);
		Kiir2_16(RdAddr2,&kiir[192],res,4);
		Kiir2_16(RdAddr2,&kiir[208],res,5);
		Kiir2_16(RdAddr2,&kiir[224],res,6);
		Kiir2_16(RdAddr2,&kiir[240],res,7);
		}
	else{
		res=MemRead(kiir+128,RdAddr2,128);
		Kiir2_16(RdAddr2,&kiir[128],res,0);
		Kiir2_16(RdAddr2,&kiir[144],res,1);
		Kiir2_16(RdAddr2,&kiir[160],res,2);
		Kiir2_16(RdAddr2,&kiir[176],res,3);
		Kiir2_16(RdAddr2,&kiir[192],res,4);
		Kiir2_16(RdAddr2,&kiir[208],res,5);
		Kiir2_16(RdAddr2,&kiir[224],res,6);
		Kiir2_16(RdAddr2,&kiir[240],res,7);
		}
	}
PacketKi->Caption=s.sprintf("%i",PacketOK);
ErrorKi->Caption=s.sprintf("%i",PacketERR);
}
//---------------------------------------------------------------------------
void __fastcall TTeszt::BuStatClrClick(TObject *Sender)
{
PacketOK=0; PacketERR=0;
}
//---------------------------------------------------------------------------
void __fastcall TTeszt::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

