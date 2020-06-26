#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include "cVezerlo.h"
#include "cModbusSoros.h"
#include "cCegnevek.h"
#include "cTxtBenzin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TCegnevek *Cegnevek;
//---------------------------------------------------------------------------
__fastcall TCegnevek::TCegnevek(TComponent* Owner):TForm(Owner)
{
Csop=0;
Mehet=false;
Fil1=-1;
}
//---------------------------------------------------------------------------
void __fastcall TCegnevek::FormActivate(TObject *Sender)
{
int	res=MemRead(be,0,16);

Caption=				TxtCegnevek[0][Nyelv];
GroupMeglevo->Caption=	TxtCegnevek[1][Nyelv];
LabCegDb->Caption=		TxtCegnevek[2][Nyelv];
LabCardDb->Caption=		TxtCegnevek[3][Nyelv];
LabTankDb->Caption=		TxtCegnevek[4][Nyelv];

BuMentes->Caption=		TxtCegnevek[5][Nyelv];
LabCsoport->Caption=	TxtCegnevek[6][Nyelv];
BuMegszak->Caption=		TxtCegnevek[7][Nyelv];

BuOlvas->Caption=		TxtCegnevek[8][Nyelv];
BuBeir->Caption=		TxtCegnevek[9][Nyelv];
BuVissza->Caption=		TxtCegnevek[10][Nyelv];

Txt->Cells[0][0]="";
Txt->Cells[1][0]=TxtCegnevek[6][Nyelv];//"Csoport";
Txt->Cells[0][1]=TxtCegnevek[11][Nyelv];//"Név 1.sor";
Txt->Cells[0][2]=TxtCegnevek[12][Nyelv];//"Név 2.sor";
Txt->Cells[0][3]=TxtCegnevek[13][Nyelv];//"Név 3.sor";
Txt->Cells[0][4]=TxtCegnevek[14][Nyelv];//"Név 4.sor";
Txt->Cells[0][5]=TxtCegnevek[15][Nyelv];//"Név 5.sor";
Txt->Cells[0][6]=TxtCegnevek[16][Nyelv];//"Név 6.sor";

if(res == 0){
	TankDb->Caption=256*(int)be[0x0b]+be[0x0a];
	CardDb->Caption=256*(int)be[0x0d]+be[0x0c];
	CegDb->Caption=256*(int)be[0x0f]+be[0x0e];
	}
}
//---------------------------------------------------------------------------
void __fastcall TCegnevek::ToltesLeallit(void)
{
Mehet=false;
if(Fil1 > 0) FileClose(Fil1); Fil1=-1;
BuMentes->Font->Color=clNavy;
BuMegszak->Font->Color=clGray;
}
//---------------------------------------------------------------------------
void __fastcall TCegnevek::Timer50ms(void)
{
int	i,len,hibu=0;

if(!Mehet) return;
//if(Cim > 0x0ff0) ToltesLeallit();
if(Cim > (FLS_CEGMAX-FLS_CEGMIN)*2) ToltesLeallit();
else	{
	Resu=FlashRead(be,FLS_CEGMIN+Cim/2,(Cim&1)*128,128);
	if(Resu > 0){ Error++; if(Error > 60) ToltesLeallit(); }
	if(Resu == 0){
		Error=0;
		for(i=0; i<6; i++) if(be[i] != 0xff) Resu=1;
		if(Resu == 0) ToltesLeallit();
		else	{
			sprintf(ki,"%04x;%05i;%032.32s;%032.32s;%032.32s;%04x;%02i/%02i/%02i %02i:%02i:%02i;\n",
				(int)be[0x01]*256+be[0x00],(int)be[0x03]*256+be[0x02],		/*Verzio, Csoport*/
				&be[0x10],&be[0x30],&be[0x50],
				(int)be[0x76]*256+be[0x77],be[0x78],be[0x79],be[0x7a],be[0x7b],be[0x7c],be[0x7d]);
			len=strlen(ki);
			FileWrite(Fil1,ki,len);
			Cim++;
			}
		}
	Uzen->Caption=ns.sprintf("%s:%5i  %s:%5i - %i",/*Cég*/TxtCegnevek[17][Nyelv],Cim/2,/*Javítva*/TxtCegnevek[18][Nyelv],Error,hibu);
	}
}
//---------------------------------------------------------------------------
void __fastcall TCegnevek::BuMentesClick(TObject *Sender)
{
if(Fil1 > 0) FileClose(Fil1); Fil1=-1;
if(SaveDialog1->Execute()){
	FileNev->Caption=SaveDialog1->FileName;
	Fil1=FileCreate(SaveDialog1->FileName);
	if(Fil1 > 0){
		Error=0; Cim=0;
		Mehet=true;
		BuMentes->Font->Color=clGray;
		BuMegszak->Font->Color=clNavy;
		}
	else	Uzen->Caption=TxtCegnevek[19][Nyelv];//"File létrehozás nem sikerült!";
	}
}
//---------------------------------------------------------------------------
void __fastcall TCegnevek::BuMegszakClick(TObject *Sender)
{
ToltesLeallit();
}
//---------------------------------------------------------------------------
void __fastcall TCegnevek::NevOlvas(void)
{
int		i,res,db;
Byte		ok1=0,ok2=0,hiba=0;
Word		csop,verz;
float	ar;
AnsiString	s;

Csop=BeCsoport->Text.ToIntDef(0);
Txt->Cells[1][0]=ns.sprintf("%s %i.",/*Csoport*/TxtCegnevek[6][Nyelv],Csop);
if((Csop < 0)||(Csop > 500)){
	Uzen->Caption=ns.sprintf("%s: %i",/*Rossz CSOPORT*/TxtCegnevek[20][Nyelv],Csop);
	return;
	}

res=MemRead(be,0,16);
if(res == 0){
	TankDb->Caption=256*(int)be[0x0b]+be[0x0a];
	CardDb->Caption=256*(int)be[0x0d]+be[0x0c];
	db=256*(int)be[0x0f]+be[0x0e]; CegDb->Caption=db;
	for(i=db; i>=0; i--){
		res=FlashRead(be,0xf000+i/2,(i&1)*128,128);			//fenrõl le
		if(res == 0){
			hiba=0;
			verz=256*(Word)be[0x01]+be[0x00];
			csop=256*(Word)be[0x03]+be[0x02];
			if(csop == Csop){							//megvan az utolsó
				if(verz == 0x4001){						//elsõ rekord
					Txt->Cells[1][1]=ns.sprintf("%32.32s",&be[0x10]);
					Txt->Cells[1][2]=ns.sprintf("%32.32s",&be[0x30]);
					Txt->Cells[1][3]=ns.sprintf("%32.32s",&be[0x50]);
	//				ar=(((float)be[0x07]*2.56+be[0x06])*2.56+be[0x05])*2.56+be[0x04]*0.01;
	  //				Txt->Cells[1][6]=ns.sprintf("%4.2f",ar);
					ok1=1;
					}
				else if(verz == 0x5001){					//második rekord
					Txt->Cells[1][4]=ns.sprintf("%32.32s",&be[0x10]);
					Txt->Cells[1][5]=ns.sprintf("%32.32s",&be[0x30]);
					Txt->Cells[1][6]=ns.sprintf("%32.32s",&be[0x50]);
					ok2=1;
					}
				}
			}
		else	{
			hiba++; if(hiba > 20) break;
			}
		if((ok1 > 0)&&(ok2 >0)) break;					//minkét fél megvan
		}
	}
Uzen->Caption=s.sprintf("%s: %i+%i OK",/*Olvasás*/TxtCegnevek[21][Nyelv],ok1,ok2);
if(ok1 == 0){
	Txt->Cells[1][1]="!";
	Txt->Cells[1][2]="!";
	Txt->Cells[1][3]="!";
	}
if(ok2 == 0){
	Txt->Cells[1][4]="!";
	Txt->Cells[1][5]="!";
	Txt->Cells[1][6]="!";
	}
}
//---------------------------------------------------------------------------
void __fastcall TCegnevek::NevKitolt(Byte* str)
{
int	i,volt=0;

for(i=0; i<32; i++){
	if(str[i]==0) volt=1;
	if((str[i] < ' ')||(volt > 0)) str[i]=' ';
	}
}
//---------------------------------------------------------------------------
void __fastcall TCegnevek::NevBeir(void)
{
int		i,res1=10,res2=10;
double    ar;
long		filler;
Byte		*aki;

Csop=BeCsoport->Text.ToIntDef(0);
Txt->Cells[1][0]=ns.sprintf("%s %i.",/*Csoport*/TxtCegnevek[6][Nyelv],Csop);
if((Csop < 0)||(Csop > 500)){
	Uzen->Caption=ns.sprintf("%s: %i",/*Rossz CSOPORT*/TxtCegnevek[20][Nyelv],Csop);
	return;
	}

for(i=0; i<128; i++) be[i]=0xff;
be[0]=0x01; be[1]=0x40;	//RecTip1;	0x4001 - v1
be[2]=Low(Csop); be[3]=High(Csop);	//Word Csoport;//x02	[0-4095]
//if(ArBeolv(&filler)==0){
//	aki=(Byte*)&filler;
//	be[4]=aki[0]; be[5]=aki[1]; be[6]=aki[2]; be[7]=aki[3];
memcpy(&be[0x10],Txt->Cells[1][1].c_str(),32); NevKitolt(&be[0x10]);
memcpy(&be[0x30],Txt->Cells[1][2].c_str(),32); NevKitolt(&be[0x30]);
memcpy(&be[0x50],Txt->Cells[1][3].c_str(),32); NevKitolt(&be[0x50]);
res1=MemWrite(be,RW_CEG,128);

for(i=0; i<128; i++) be[i]=0xff;
be[0]=0x01; be[1]=0x50;	//RecTip2;	0x5001 - v1
be[2]=Low(Csop); be[3]=High(Csop);	//Word Csoport;//x02	[0-4095]
memcpy(&be[0x10],Txt->Cells[1][4].c_str(),32); NevKitolt(&be[0x10]);
memcpy(&be[0x30],Txt->Cells[1][5].c_str(),32); NevKitolt(&be[0x30]);
memcpy(&be[0x50],Txt->Cells[1][6].c_str(),32); NevKitolt(&be[0x50]);
if((be[0x10] != '!')||(be[0x30] != '!')||(be[0x50] != '!')) res2=MemWrite(be,RW_CEG,128);
else res2=0;

if((res1+res2) == 0){ Uzen->Caption=TxtCegnevek[22][Nyelv]/*"Írás OK"*/; }
else{ Uzen->Caption=ns.sprintf("%s: %i/%i",/*Írás HIBA*/TxtCegnevek[23][Nyelv],res1,res2); }
}
//---------------------------------------------------------------------------
void __fastcall TCegnevek::BuOlvasClick(TObject *Sender)
{
NevOlvas();
}
//---------------------------------------------------------------------------
void __fastcall TCegnevek::BuBeirClick(TObject *Sender)
{
NevBeir();
}
//---------------------------------------------------------------------------
void __fastcall TCegnevek::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------
void __fastcall TCegnevek::BuVisszaClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

