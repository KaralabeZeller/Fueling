#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include "cVezerlo.h"
#include "cModbusSoros.h"
#include "cArak.h"
#include "cTxtBenzin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TArak *Arak;
//---------------------------------------------------------------------------
__fastcall TArak::TArak(TComponent* Owner):TForm(Owner)
{
Csop=0;
Mehet=false;
FilNum=-1;
}
//---------------------------------------------------------------------------
void __fastcall TArak::FormActivate(TObject *Sender)
{
int	db,res=MemRead(be,0,18);

Caption=				TxtArak[0][Nyelv];
GroupMeglevo->Caption=	TxtArak[1][Nyelv];
LabDb->Caption=		TxtArak[2][Nyelv];

BuMentes->Caption=		TxtArak[3][Nyelv];
LabCsoport->Caption=    	TxtArak[4][Nyelv];
BuMegszak->Caption=		TxtArak[5][Nyelv];
BuOlvas->Caption=		TxtArak[6][Nyelv];
BuBeir->Caption=		TxtArak[7][Nyelv];
BuVissza->Caption=		TxtArak[8][Nyelv];

Txt->Cells[0][0]="";
Txt->Cells[1][0]=TxtArak[ 9][Nyelv];//"Csoport";
Txt->Cells[0][1]=TxtArak[10][Nyelv];//"0 - Gázolaj";
Txt->Cells[0][2]=TxtArak[11][Nyelv];//"1 - Benzin";

if(res == 0){ db=256*(int)be[0x11]+be[0x10]; ArakDb->Caption=db;	}
}
//---------------------------------------------------------------------------
void __fastcall TArak::ToltesLeallit(void)
{
Mehet=false;
if(FilNum > 0) FileClose(FilNum); FilNum=-1;
BuMentes->Font->Color=clNavy;
BuMegszak->Font->Color=clGray;
}
//---------------------------------------------------------------------------
void __fastcall TArak::Timer50ms(void)
{
int	i,hibu=0,len;
Byte	*tar;

if(!Mehet) return;
if(Cim > 0x0ff0) ToltesLeallit();
else	{
	Resu=FlashRead(be,FLS_ARAKMIN+Cim/2,(Cim&1)*128,128);
	if(Resu > 0){ Error++; if(Error > 60) ToltesLeallit(); }
	if(Resu == 0){
		Error=0;
		for(i=0; i<6; i++) if((be[0] == 0xff)||(be[0] == 0xff)) Ures++;
		if(Ures > 10) Resu=0; else Resu=1;
		if(Resu == 0) ToltesLeallit();
		else	{
			for(i=0; i<4; i++){
				tar=&be[0x20*i];
				sprintf(ki,"%04x;%05i;%05i;%05i;%04x;%02i/%02i/%02i %02i:%02i:%02i;\n",
					(int)tar[0x01]*256+tar[0x00],(int)tar[0x03]*256+tar[0x02],		/*Verzio, Csoport*/
					(int)tar[0x05]*256+tar[0x04],(int)tar[0x07]*256+tar[0x06],
					(int)tar[0x16]*256+tar[0x17],tar[0x18],tar[0x19],tar[0x1a],tar[0x1b],tar[0x1c],tar[0x1d]);
				len=strlen(ki);
				FileWrite(FilNum,ki,len);
				}
			Cim++;
			}
		}
	Uzen->Caption=as.sprintf("%s:%5i  %s:%5i - %i",TxtArak[12][Nyelv]/*Ár*/,Cim*4,TxtArak[13][Nyelv]/*Javítva*/,Error,hibu);
	}
}
//---------------------------------------------------------------------------
void __fastcall TArak::BuMegszakClick(TObject *Sender)
{
ToltesLeallit();
}
//---------------------------------------------------------------------------
void __fastcall TArak::BuMentesClick(TObject *Sender)
{
if(FilNum > 0) FileClose(FilNum); FilNum=-1;
if(SaveDialog1->Execute()){
	FileNev->Caption=SaveDialog1->FileName;
	FilNum=FileCreate(SaveDialog1->FileName);
	if(FilNum > 0){
		Error=0; Cim=0; Ures=0;
		Mehet=true;
		BuMentes->Font->Color=clGray;
		BuMegszak->Font->Color=clNavy;
		}
	else	Uzen->Caption=TxtArak[14][Nyelv];//"File létrehozás nem sikerült!";
	}
}
//---------------------------------------------------------------------------
void __fastcall TArak::ArakOlvas(void)
{
int			i,res,db;
Byte			ok=0,hiba=0;
Word			csop,verz;
float		ar;
AnsiString	s;

Csop=BeCsoport->Text.ToIntDef(0);
Txt->Cells[1][0]=as.sprintf("%s %i.",TxtArak[15][Nyelv],Csop);//Csoport
if((Csop < 0)||(Csop > 500)){
	Uzen->Caption=as.sprintf("%s: %i",TxtArak[16][Nyelv],Csop);//Rossz CSOPORT
	return;
	}

res=MemRead(be,0,18);
if(res == 0){
	db=256*(int)be[0x11]+be[0x10]; ArakDb->Caption=db;
	for(i=db; i>=0; i--){
		res=FlashRead(be,0xe000+i/8,(i&7)*32,32);	//fenrõl le
		if(res == 0){
			hiba=0;
			verz=256*(Word)be[0x01]+be[0x00];
			csop=256*(Word)be[0x03]+be[0x02];
			if(csop == Csop){					//megvan az utolsó
				if(verz == 0x6001){				//elsõ rekord
					ar=(float)((Word)be[0x05]*256+be[0x04])*0.01;
					Txt->Cells[1][1]=as.sprintf("%4.2f",ar);
					ar=(float)((Word)be[0x07]*256+be[0x06])*0.01;
					Txt->Cells[1][2]=as.sprintf("%4.2f",ar);
					ok=1;
					}
				}
			}
		else	{
			hiba++; if(hiba > 20) break;
			}
		if(ok > 0) break;						//minkét fél megvan
		}
	}
if(ok == 0){
	Uzen->Caption=TxtArak[17][Nyelv];//"Olvasás: HIBA ";
	Txt->Cells[1][1]="0";
	Txt->Cells[1][2]="0";
	}
else Uzen->Caption=TxtArak[18][Nyelv];//"Olvasás: OK ";
}
//---------------------------------------------------------------------------
int __fastcall TArak::ArBeolv(Word *filler,Byte mut)
{
int		i,tized=10;
char		*be,ch;

if(mut == 0)	as=Txt->Cells[1][1].Trim();
else			as=Txt->Cells[1][2].Trim();
be=as.c_str();
*filler=0;
for(i=0; i<32; i++){
	ch=be[i];
	if((ch >= '0')&&(ch <= '9')) *filler=*filler*10+(ch-'0');
	else if((ch == '.')||(ch== ',')) tized=3;
	else return(-1);					//hiba
	if(tized < 10) tized--;
	if(tized == 0) break;
	}
if(*filler >= 0xffff){ return(-1); }
Txt->Cells[1][1]=as.sprintf("%4.2f",(float)*filler/100);
return(0);
}
//---------------------------------------------------------------------------
void __fastcall TArak::ArakBeir(void)
{
int		i,res=10,ok1,ok2;
//double    ar;
Word		filler;

Csop=BeCsoport->Text.ToIntDef(0);
Txt->Cells[1][0]=as.sprintf("%s %i.",TxtArak[15][Nyelv],Csop);//Csoport
if((Csop < 0)||(Csop > 500)){
	Uzen->Caption=as.sprintf("%s: %i",TxtArak[16][Nyelv],Csop);//Rossz CSOPORT
	return;
	}

for(i=0; i<32; i++) be[i]=0xff;
be[0]=0x01; be[1]=0x60;			//RecTip;	0x6001 - v1
be[2]=Low(Csop); be[3]=High(Csop);	//Word Csoport;//x02	[0-4095]
if((ok1=ArBeolv(&filler,0))==0){ be[4]=Low(filler); be[5]=High(filler); }
if((ok2=ArBeolv(&filler,1))==0){ be[6]=Low(filler); be[7]=High(filler); }

if(ok1 != 0)		Uzen->Caption=TxtArak[19][Nyelv];//"*** 0. ÁR HIBA ***";
else if(ok2 != 0)	Uzen->Caption=TxtArak[20][Nyelv];//"*** 1. ÁR HIBA ***";
else				res=MemWrite(be,RW_ARAK,32);
if(res == 0)		Uzen->Caption=TxtArak[21][Nyelv];//"Írás OK";
else				Uzen->Caption=as.sprintf("%s: %i",TxtArak[22][Nyelv],res);//Írás HIBA
}
//---------------------------------------------------------------------------
void __fastcall TArak::BuOlvasClick(TObject *Sender)
{
ArakOlvas();
}
//---------------------------------------------------------------------------
void __fastcall TArak::BuBeirClick(TObject *Sender)
{
ArakBeir();
}
//---------------------------------------------------------------------------
void __fastcall TArak::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------
void __fastcall TArak::BuVisszaClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

