#include <stdio.h>
#include <vcl.h>
#pragma hdrstop
#include "cCardKonv.h"
#include "cUjKartyaBe.h"
#include "cModbusSoros.h"
#include "cVezerlo.h"
#include "cTxtBenzin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TCardKonv *CardKonv;
//-----------------------------------------------
__fastcall TCardKonv::TCardKonv(TComponent* Owner):TForm(Owner)
{
Freeze=false;
fK1=-1; fKlen=0; fKdb=0;
ListaInit();
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::FormActivate(TObject *Sender)
{
Caption=				TxtCardKonv[0][Nyelv];

BuVezOlv->Caption=		TxtCardKonv[1][Nyelv];
BuDump->Caption=		TxtCardKonv[2][Nyelv];
BuVezIr->Caption=		TxtCardKonv[3][Nyelv];
BuUjkartya->Caption=	TxtCardKonv[4][Nyelv];
BuVissza->Caption=		TxtCardKonv[5][Nyelv];

GroupFile->Caption=		TxtCardKonv[6][Nyelv];
BuOlvas->Caption=		TxtCardKonv[7][Nyelv];
BuIr->Caption=			TxtCardKonv[8][Nyelv];

GroupSor->Caption=		TxtCardKonv[9][Nyelv];
BuSorHozzaad->Caption=	TxtCardKonv[10][Nyelv];
BuSorBeszur->Caption=	TxtCardKonv[11][Nyelv];
BuSorTorol->Caption=	TxtCardKonv[12][Nyelv];

GroupTabl->Caption=		TxtCardKonv[13][Nyelv];
BuEllenorzes->Caption=	TxtCardKonv[14][Nyelv];
BuTablaTorol->Caption=	TxtCardKonv[15][Nyelv];

BuMegszak->Caption=		TxtCardKonv[16][Nyelv];

KonvLeallit();
}
//-----------------------------------------------
void __fastcall TCardKonv::ListaInit(void)
{
int	i;

CrdList->Cells[0][0]=TxtCardKonv[17][Nyelv];//"RTip/Cím";
CrdList->Cells[1][0]=TxtCardKonv[18][Nyelv];//"Card Id";
CrdList->Cells[2][0]=TxtCardKonv[19][Nyelv];//"Tipus";
CrdList->Cells[3][0]=TxtCardKonv[20][Nyelv];//"Liter";
CrdList->Cells[4][0]=TxtCardKonv[21][Nyelv];//"Db";
CrdList->Cells[5][0]=TxtCardKonv[22][Nyelv];//"Pin";
CrdList->Cells[6][0]=TxtCardKonv[23][Nyelv];//"Kut [hex]";
CrdList->Cells[7][0]=TxtCardKonv[24][Nyelv];//"Sorsz";
CrdList->Cells[8][0]=TxtCardKonv[25][Nyelv];//"Csop";
CrdList->Cells[9][0]=TxtCardKonv[26][Nyelv];//"Prn";
CrdList->Cells[10][0]=TxtCardKonv[27][Nyelv];//"Név";
for(i=0; i<11; i++) CrdList->Cells[i][1]="";
CrdList->RowCount=2;
NevForras->Caption='-';
Kijel->Caption='-';
}
//-----------------------------------------------
Byte __fastcall TCardKonv::HexToBin(Byte be)
{
Byte	b=0;

switch(be){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	b=be-'0'; break;
	case 'A':
	case 'a':	b=10; break;
	case 'B':
	case 'b':	b=11; break;
	case 'C':
	case 'c':	b=12; break;
	case 'D':
	case 'd':	b=13; break;
	case 'E':
	case 'e':	b=14; break;
	case 'F':
	case 'f':	b=15; break;
	default:	b=0xff;
	}
return(b);
}
//-----------------------------------------------
int __fastcall TCardKonv::SorBeolv(void)	//0=nincs több, i=hány byte jött be
{
int	i;
char	be;

SorMezoDb=0;
for(i=0; i<CARD_MEZODB; i++) SorMezo[i]="";
for(i=0; i<CARD_SORLEN; i++){
	if(FileRead(fK1,&be,1) == 1){
		switch(be){
			case 0x0d:	; break;
			case 0x0a:	return(i+1);//eldob és sor vége
			case ';':		if(SorMezoDb < CARD_MEZODB) SorMezoDb++; break;
			default:		SorMezo[SorMezoDb]+=be; break;
			}
		}
	else return(i);//utsó sor \n nélkül
	}
return(i);//utsó sor \n nélkül
}
//-----------------------------------------------
int __fastcall TCardKonv::SorSzetvag(void)	//0=elsõ két betû rossz, 1=OK
{
int			i,sor=CrdList->RowCount-1,len;
char			c;

for(i=0; i<CARD_MEZODB; i++){
	cs=SorMezo[i];
	if(cs > ""){
		if(cs[1] == '"') cs.Delete(1,1);
		len=cs.Length();
		if(cs[len] == '"') cs.Delete(len,1);
		SorMezo[i]=cs;
		}
	}

if(SorMezo[0] == "11"){					//régi tipus
	if(CrdList->Cells[0][sor] != "") { CrdList->RowCount++; sor++; }

//11;11/11/24 19:26;0347997781;5;01000;00100;12;Service mol  ;7781;13;00000;18;032;32
	CrdList->Cells[0][sor]="2001/[____]";	//RTip/Cím";
	CrdList->Cells[1][sor]=SorMezo[2];		//"Card Id";
	CrdList->Cells[2][sor]=SorMezo[3];		//"Tipus";
	CrdList->Cells[3][sor]=SorMezo[4];		//"Liter";
	CrdList->Cells[4][sor]=SorMezo[5];		//"Db";
	if(SorMezo[8] == "????") SorMezo[8]="0000";
	CrdList->Cells[5][sor]=SorMezo[8];		//"Pin";
	CrdList->Cells[6][sor]="FF"+SorMezo[11];//"Kut [hex]";
	CrdList->Cells[7][sor]=SorMezo[10];	//"Sorsz";
	CrdList->Cells[8][sor]=SorMezo[12];	//"Csop";
	i=SorMezo[13].ToIntDef(0);			//"Prn";
	if(i > 9) i=0;
	CrdList->Cells[9][sor]=i;
	CrdList->Cells[10][sor]=SorMezo[7];	//"Név";

	return(1);
	}
else if(SorMezo[0] == "2001"){			//új tipus
	if(CrdList->Cells[0][sor] != "") { CrdList->RowCount++; sor++; }

	for(i=0; i<CARD_MEZODB; i++){
		if(i == 0)CrdList->Cells[i][sor]=SorMezo[i]+"[____]";
		else 	CrdList->Cells[i][sor]=SorMezo[i];
		}
	return(1);
	}
else return(0);						//a tipus nem stimmel
}
//-----------------------------------------------
Byte __fastcall TCardKonv::SorKonvertal(int sor)//0-50=hibás oszlop,255=sikerült
{
Word			x;
int			i;
AnsiString	s;
Byte			*be,ki[20];

s=CrdList->Cells[0][sor].Trim();		//RTip/Cim
if(s.Length() < 9) return(0);
be=s.c_str();
for(i=0; i<4; i++){ ki[i]=HexToBin(be[i]); if(ki[i] > 15) return(0); }
Card.RecTip=((Word)ki[0]*16+ki[1])*256+ki[2]*16+ki[3];
if(Card.RecTip != 0x2001) return(0);

s=CrdList->Cells[1][sor].Trim();		//Card Id
if(s.Length() < 10) return(1);
be=s.c_str();
for(i=0; i<14; i++){ ki[i]=HexToBin(be[i]); if(ki[i] > 15) return(1); }
Card.Id[0]=16*ki[0]+ki[1];
Card.Id[1]=16*ki[2]+ki[3];
Card.Id[2]=16*ki[4]+ki[5];
Card.Id[3]=16*ki[6]+ki[7];
Card.Id[4]=16*ki[8]+ki[9];
Card.Id[5]=16*ki[10]+ki[11];
Card.Id[6]=16*ki[12]+ki[13];

s=CrdList->Cells[2][sor].Trim();		//Type
if(s.Length() < 1) return(2);
i=s.ToIntDef(-1); if(i < 0) return(2);
switch(i){
	case 1:
	case 2:
	case 3:
	case 5:	Card.Tip=i;
			break;
	default:	return(2);
	}

s= CrdList->Cells[3][sor].Trim();		//Liter
if(s.Length() < 1) return(3);
i= s.ToIntDef(-1); if(i > 59999) return(3);
Card.MaxLit= i;

s=CrdList->Cells[4][sor].Trim();		//Db
if(s.Length() < 1) return(4);
i=s.ToIntDef(-1); if(i > 999) return(4);
Card.MaxDb=i;

s=CrdList->Cells[5][sor].Trim();		//Pin
if(s.Length() < 4) return(5);
be=s.c_str();
for(i=0; i<4; i++){ ki[i]=HexToBin(be[i]); if(ki[i] > 9) return(5); }
Card.Pin=((Word)ki[0]*16+ki[1])*256+ki[2]*16+ki[3];

s=CrdList->Cells[6][sor].Trim();		//Kut
if(s.Length() < 4) return(6);
be=s.c_str();
for(i=0; i<4; i++){ ki[i]=HexToBin(be[i]); if(ki[i] > 15) return(6); }
Card.Kutak=((Word)ki[0]*16+ki[1])*256+ki[2]*16+ki[3];

s=CrdList->Cells[7][sor].Trim();		//Sorsz
if(s.Length() < 1) return(7);
i=s.ToIntDef(-1); if(i < 0) return(7);
Card.Num=i;

s=CrdList->Cells[8][sor].Trim();		//Csop
if(s.Length() < 1) return(8);
i=s.ToIntDef(-1); if((i < 0)||(i > 9999)) return(8);
Card.Csoport=i;

s=CrdList->Cells[9][sor].Trim();		//Print
if(s.Length() < 1) return(9);
i=s.ToIntDef(-1); if((i < 0)||(i > 9)) return(9);
Card.Print=i;

s=CrdList->Cells[10][sor].Trim();		//Név
if(s.Length() < 1) return(10);
s=s+"                    "; be=s.c_str();
for(i=0; i<20; i++) if(be[i] < ' ') return(10);
for(i=0; i<20; i++) Card.Nev[i]=be[i];

return(255);
}
//-----------------------------------------------
void __fastcall TCardKonv::CardToStr(AnsiString *s)
{
AnsiString    ki,p;

ki =p.sprintf("%04X;%02X%02X%02X%02X%02X%02X%02X;",Card.RecTip,Card.Id[0],Card.Id[1],Card.Id[2],Card.Id[3],Card.Id[4],Card.Id[5],Card.Id[6]);
ki+=p.sprintf("%1i;%05i;%05i;%04X;%04X;%05i;",Card.Tip,Card.MaxLit,Card.MaxDb,Card.Pin,Card.Kutak,Card.Num);
ki+=p.sprintf("%05i;%01i;%20.20s;\r\n",Card.Csoport,Card.Print,Card.Nev);
*s=ki;
}
//-----------------------------------------------
void __fastcall TCardKonv::CardToTable(void)
{
AnsiString	s;
int			i,sor=CrdList->RowCount-1;

if(CrdList->Cells[0][sor] != "") { CrdList->RowCount++; sor++; }	//ha nincs üres, új sor

if(Card.Hiba == 0)	CrdList->Cells[0][sor]=s.sprintf("%04X/%04x",Card.RecTip,Card.Cim);
else				CrdList->Cells[0][sor]=s.sprintf("%04X/%04x***H",Card.RecTip,Card.Cim);
CrdList->Cells[1][sor]=s.sprintf("%02X%02X%02X%02X%02X%02X%02X",Card.Id[0],Card.Id[1],Card.Id[2],Card.Id[3],Card.Id[4],Card.Id[5],Card.Id[6]);
CrdList->Cells[2][sor]=s.sprintf("%1i",Card.Tip);
CrdList->Cells[3][sor]=s.sprintf("%05i",Card.MaxLit);
CrdList->Cells[4][sor]=s.sprintf("%05i",Card.MaxDb);
CrdList->Cells[5][sor]=s.sprintf("%04X",Card.Pin);
CrdList->Cells[6][sor]=s.sprintf("%04X",Card.Kutak);
CrdList->Cells[7][sor]=s.sprintf("%05i",Card.Num);
CrdList->Cells[8][sor]=s.sprintf("%05i",Card.Csoport);
CrdList->Cells[9][sor]=s.sprintf("%01i",Card.Print);
CrdList->Cells[10][sor]=s.sprintf("%20.20s",Card.Nev);
}
//-----------------------------------------------
int __fastcall TCardKonv::TarToCard(void) //-1=chk rossz,0=ok,1=üres
{
int	i;
Word	x;

for(i=0; i<64; i++) if(Tar[i] != 0xff) break;
if(i >= 64) return(1);
for(i=0,x=0; i<62; i++) x+=Tar[i];	//chksum
if((Tar[62] != Low(x))||(Tar[63] != High(x))) Card.Hiba=1;	//ChkSum error
else  Card.Hiba=0;

Card.RecTip=	(Word)Tar[0x00]*256+Tar[0x01];
memcpy(Card.Id,&Tar[0x02],7);
Card.Tip=		Tar[0x09];
Card.MaxLit=	(Word)Tar[0x0a]*256+Tar[0x0b];
Card.MaxDb=	(Word)Tar[0x0c]*256+Tar[0x0d];
Card.Pin=		(Word)Tar[0x0e]*256+Tar[0x0f];
Card.Kutak=	(Word)Tar[0x10]*256+Tar[0x11];
Card.Num=		(Word)Tar[0x12]*256+Tar[0x13];
Card.Csoport=	(Word)Tar[0x14]*256+Tar[0x15];
Card.Print=	Tar[0x16];
Card.Ev=       Tar[0x17];
Card.Ho=       Tar[0x18];
Card.Nap=      Tar[0x19];
Card.Ora=      Tar[0x1a];
Card.Perc=     Tar[0x1b];
Card.Mp=       Tar[0x1c];
memcpy(Card.Nev,&Tar[0x1d],20);

return(0);	//ok
}
//-----------------------------------------------
void __fastcall TCardKonv::CardToTar(int kapcs)
{
int	i;

Tar[0x00]=High(Card.RecTip);			//00-w.hex
Tar[0x01]= Low(Card.RecTip);
memcpy(&Tar[0x02],Card.Id,7);			//02-7b
Tar[0x09]= Card.Tip;				//09-1b
Tar[0x0a]=High(Card.MaxLit);			//0a-w
Tar[0x0b]= Low(Card.MaxLit);
Tar[0x0c]=High(Card.MaxDb);			//0c-w
Tar[0x0d]= Low(Card.MaxDb);
Tar[0x0e]=High(Card.Pin);			//0e-w
Tar[0x0f]= Low(Card.Pin);
Tar[0x10]=High(Card.Kutak);			//10-w
Tar[0x11]= Low(Card.Kutak);
Tar[0x12]=High(Card.Num);			//12-w
Tar[0x13]= Low(Card.Num);
Tar[0x14]=High(Card.Csoport);			//14-w
Tar[0x15]= Low(Card.Csoport);
Tar[0x16]= Card.Print;  				//16-b
if(kapcs == 0){
	Tar[0x17]=0; Tar[0x18]=0; Tar[0x19]=0;	//date
	Tar[0x1a]=0; Tar[0x1b]=0; Tar[0x1c]=0;	//time
	}
else	{
	Tar[0x17]=Card.Ev; Tar[0x18]=Card.Ho; Tar[0x19]=Card.Nap;	//date
	Tar[0x1a]=Card.Ora; Tar[0x1b]=Card.Perc; Tar[0x1c]=Card.Mp;	//time
	}
memcpy(&Tar[0x1d],Card.Nev,20);		//1d-20b

for(i=0x31; i<0x40; i++)	Tar[i]=0xff;	//31-üres
}
//-----------------------------------------------
int __fastcall TCardKonv::Ellenorzes(void)
{
int		sor;
Byte		oszl;

for(sor=1; sor<CrdList->RowCount; sor++){
	oszl=SorKonvertal(sor);
	if(oszl != 255){			//hiba
		CrdList->Row=sor;
		CrdList->Col=oszl;
		return(-1);
		}
	}
return(0);
}
//-----------------------------------------------
void __fastcall TCardKonv::KonvLeallit(void)
{
Fazis=FAZ_STOP;
if(fK1 > -1) { FileClose(fK1); fK1=-1; }

BuOlvas->Font->Color=clNavy;
BuIr->Font->Color=clNavy;
BuMegszak->Font->Color=clGray;
BuVezOlv->Font->Color=clNavy;
BuDump->Font->Color=clNavy;
BuVezIr->Font->Color=clNavy;
}
//-----------------------------------------------
void __fastcall TCardKonv::Timer50ms(void)
{
AnsiString	s;
int			db,resu;
int			szaz;

if(Freeze) return;
Freeze=true;

if(UjKartyaBe->Visible){
	MemRead(CrdMem,RW_CARD,78);
	if(UjKartyaBe->Olvaso->Checked)
		UjKartyaBe->Id->Text=s.sprintf("%02X%02X%02X%02X%02X%02X%02X",CrdMem[0x02],CrdMem[0x03],CrdMem[0x04],CrdMem[0x05],CrdMem[0x06],CrdMem[0x07],CrdMem[0x08]);
	else if(UjKartyaBe->Gyuru->Checked)
		UjKartyaBe->Id->Text=s.sprintf("0000%02X%02X%02X%02X%02X",CrdMem[0x48],CrdMem[0x49],CrdMem[0x4a],CrdMem[0x4b],CrdMem[0x4c]);
	}
else{
  switch(Fazis){
	case FAZ_STOP: break;
	case FAZ_OLVCSV:
		db=SorBeolv();						//db=beolvasott byte
		fKdb+=db;
		if(db > 0){						//van beolvasott valami
			if(SorSzetvag() == 1) Db++;
			else	if(Sor > 0) Hiba++;
			}
		else	KonvLeallit();
		szaz=fKdb*100/fKlen;
		Kijel->Caption=s.sprintf("%3.0f%% (%idb / %i %s)",(float)szaz,Db,Hiba,/*hiba*/TxtCardKonv[28][Nyelv]);
		TrackBar->Position=szaz; TrackBar->SelEnd=szaz;
		break;
	case FAZ_OLVCRD:
		db=FileRead(fK1,&Tar,64);			//db=beolvasott byte
		if(db == 64){						//van beolvasott teljes rekord
			fKdb+=db;
			if(TarToCard() != 0) Hiba++;
			else	CardToTable();
			}
		else	KonvLeallit();
		Sor++;
		szaz=fKdb*100/fKlen;
		Kijel->Caption=s.sprintf("%3.0f%% (%idb / %i %s)",(float)szaz,Sor,Hiba,/*hiba*/TxtCardKonv[28][Nyelv]);
		TrackBar->Position=szaz; TrackBar->SelEnd=szaz;
		break;
	case FAZ_OLVVEZ:					 		//Olvasás BVEZ2-bõl
		if(FlashRead(Tar,Card.Cim/2+0x8000,(Card.Cim&1)*128,128) == 0){//db=beolvasott byte
			resu=TarToCard();
			switch(resu){
				case 0:	CardToTable(); break;	//CRC renben
				case 1:	Ures++; break;			//üres rekord
				default:	Hiba++; break;
				}
			Card.Cim++;
			}
		else Whiba++;
		szaz=Card.Cim*100/fKlen;
		Kijel->Caption=s.sprintf("%3.0f%% %idb(C=%04x/H=%i/W=%i)",(float)szaz,Card.Cim-Ures,Card.Cim,Hiba,Whiba);
		TrackBar->Position=szaz; TrackBar->SelEnd=szaz;
		if((Card.Cim >= fKlen)||(Ures > 35)) KonvLeallit();
		break;
	case FAZ_DUMP:						 		//Olvasás BVEZ2-bõl
		if(FlashRead(Tar,Card.Cim/2+0x8000,(Card.Cim&1)*128,128) == 0){//db=beolvasott byte
			if(FileWrite(fK1,Tar,128) != 128){
				Kijel->Caption=TxtCardKonv[29][Nyelv];//"Kiírási HIBA!";
				KonvLeallit();
				}
			Card.Cim++;
			}
		else Whiba++;
		szaz=Card.Cim*100/fKlen;
		Kijel->Caption=s.sprintf("%3.0f%% (%05i/H=%i)",(float)szaz,Card.Cim,Whiba);
		TrackBar->Position=szaz; TrackBar->SelEnd=szaz;
		if(Card.Cim >= fKlen) KonvLeallit();
		break;
	case FAZ_IRCSV:					 	//Írás *.csv file-ba
		if(Sor <  CrdList->RowCount){
			if(SorKonvertal(Sor) == 255){		//Card jól feltöltve
				CardToStr(&s); db=s.Length();
				if(FileWrite(fK1,s.c_str(),db) != db){
					Kijel->Caption=TxtCardKonv[29][Nyelv];//"Kiírási HIBA!";
					KonvLeallit();
					}
				}
			else  Hiba++;
			Sor++;
			}
		else KonvLeallit();
		szaz=Sor*100/CrdList->RowCount;
		Kijel->Caption=s.sprintf("%3.0f%% (%idb / %i%s)",(float)szaz,Sor-1,Hiba,/*hiba*/TxtCardKonv[28][Nyelv]);
		TrackBar->Position=szaz; TrackBar->SelEnd=szaz;
		break;
	case FAZ_IRCRD:					 	//Írás *.crd file-ba
		if(Sor <  CrdList->RowCount){
			if(SorKonvertal(Sor) == 255){		//Card jól feltöltve
				CardToTar(1);
				if(FileWrite(fK1,Tar,64) != 64){
					Kijel->Caption=TxtCardKonv[29][Nyelv];//"Kiírási HIBA!";
					KonvLeallit();
					}
				}
			else  Hiba++;
			Sor++;
			}
		else KonvLeallit();
		szaz=Sor*100/CrdList->RowCount;
		Kijel->Caption=s.sprintf("%3.0f%% (%idb / %i%s)",(float)szaz,Sor-1,Hiba,/*hiba*/TxtCardKonv[28][Nyelv]);
		TrackBar->Position=szaz; TrackBar->SelEnd=szaz;
		break;
	case FAZ_IRVEZ:					 	//Írás BVEZ2-be
		if(Sor <  CrdList->RowCount){
			if(SorKonvertal(Sor) == 255){		//Card jól feltöltve
				CardToTar(0);
				if(MemWrite(Tar,RW_CARD,64) == 0) Sor++;
				else	{ Whiba++; if(Whiba > 20) KonvLeallit(); }
				}
			else  Hiba++;
			}
		else KonvLeallit();
		szaz=Sor*100/CrdList->RowCount;
		Kijel->Caption=s.sprintf("%3.0f%% (%idb / bad:%is %iw) ",(float)szaz,Sor-1,Hiba,Whiba);
		TrackBar->Position=szaz; TrackBar->SelEnd=szaz;
		break;
	default:	KonvLeallit();
	}
  }
Freeze=false;
}
//-----------------------------------------------
void __fastcall TCardKonv::BuOlvasClick(TObject *Sender)
{
AnsiString	n,s;

KonvLeallit();
BuOlvas->Font->Color=clGray;
BuMegszak->Font->Color=clNavy;
if(OpenDialog->Execute()){
	NevForras->Caption=OpenDialog->FileName;
	BuMegszak->Font->Color=clGreen;
	FileClose(fK1); fK1= FileOpen(NevForras->Caption,fmOpenRead);
	if(fK1 < 1){
		Kijel->Caption=TxtCardKonv[30][Nyelv];//"File megnyitási hiba!";
		KonvLeallit();
		return;
		}
	fKlen=FileSeek(fK1,0,2);				//hossz
	FileSeek(fK1,0,0);					//elejére
	fKdb=0;
	Hiba=0; Sor=0; Db=0;
	n=NevForras->Caption.LowerCase();
	s=OpenDialog->FileName.SubString(LastDelimiter(".",n),4);
	if((s == ".txt")||(s == ".csv")){	Fazis=FAZ_OLVCSV; }
	else if(s == ".crd"){			Fazis=FAZ_OLVCRD; }
	}
}
//-----------------------------------------------
void __fastcall TCardKonv::BuIrClick(TObject *Sender)
{
AnsiString	n,s;
int			db;

KonvLeallit();
BuIr->Font->Color=clGray;
BuMegszak->Font->Color=clNavy;
if(Ellenorzes() != 0) Application->MessageBox(/*"Ellenõrzés HIBA!"*/TxtCardKonv[32][Nyelv].c_str(), /*"Ellenõrzés"*/TxtCardKonv[31][Nyelv].c_str(), MB_OK);
if(SaveDialog->Execute()){
	NevForras->Caption=SaveDialog->FileName;
	FileClose(fK1); fK1= FileCreate(NevForras->Caption);
	if(fK1 < 1){
		Kijel->Caption=TxtCardKonv[30][Nyelv];//"File megnyitási hiba!";
		KonvLeallit();
		return;
		}
	Sor=1;			//fejléc nem kell
	Hiba=0;
	FileSeek(fK1,0,0);
	n=NevForras->Caption.LowerCase();
	s=SaveDialog->FileName.SubString(LastDelimiter(".",n),4);
	if(s == ".csv"){
		s="RTip;Card Id   ;T;Liter;Db   ;Pin ;Kut ;Sorsz;Csop ;P;Név                 ;\r\n";
		db=s.Length();
		if(FileWrite(fK1,s.c_str(),db) != db){
			Kijel->Caption=TxtCardKonv[29][Nyelv];//"Kiírási HIBA!";
			KonvLeallit();
			}
		else{ Fazis=FAZ_IRCSV; }
		}
	else if	(s == ".crd"){	Fazis=FAZ_IRCRD; }
	}
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::BuDumpClick(TObject *Sender)
{
AnsiString	n,s;
int			db;

KonvLeallit();
BuDump->Font->Color=clRed;
BuMegszak->Font->Color=clNavy;
if(SaveDialogDump->Execute()){
	FileClose(fK1); fK1= FileCreate(SaveDialogDump->FileName);
	if(fK1 < 1){
		Kijel->Caption=TxtCardKonv[30][Nyelv];//"File megnyitási hiba!";
		KonvLeallit();
		return;
		}
	FileSeek(fK1,0,0);

	Card.Cim=0; fKlen=49152;  	//[0x8000-0xdfff]	Kártya adatok [128b](65536/8*6=49152db) - 32db/blk
	Ures=0; Hiba=0; Whiba=0;
	Fazis=FAZ_DUMP;
	}
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::BuVezOlvClick(TObject *Sender)
{
KonvLeallit();
BuVezOlv->Font->Color=clRed;
BuMegszak->Font->Color=clNavy;
Sor=1;			//fejléc nem kell
Card.Cim=0; fKlen=28672;
Ures=0; Hiba=0; Whiba=0;
Fazis=FAZ_OLVVEZ;
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::BuVezIrClick(TObject *Sender)
{
AnsiString	n,s;
int			db;

if(Ellenorzes() != 0) return;
KonvLeallit();
BuVezIr->Font->Color=clRed;
BuMegszak->Font->Color=clNavy;
Sor=1;			//fejléc nem kell
Hiba=0; Whiba=0;
Fazis=FAZ_IRVEZ;
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::BuMegszakClick(TObject *Sender)
{
KonvLeallit();
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::BuTablaTorolClick(TObject *Sender)
{
ListaInit();
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::BuSorTorolClick(TObject *Sender)
{
int	kezd=CrdList->Row, veg=CrdList->RowCount,i,j;

if(kezd < 1) ;						//fejléc marad
else if(CrdList->RowCount < 3){		//1.sor marad
	for(j=0; j<CrdList->ColCount; j++)
	 	CrdList->Cells[j][1]="";		//1.sor töröl
	}
else	{
	for(i=kezd; i<veg-1; i++)
		for(j=0; j<CrdList->ColCount; j++) CrdList->Cells[j][i]=CrdList->Cells[j][i+1];//shift le
	CrdList->RowCount--;
	}
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::BuSorHozzaadClick(TObject *Sender)
{
int	i;

CrdList->RowCount++;
for(i=0; i<CrdList->ColCount; i++)	CrdList->Cells[i][CrdList->RowCount-1]="";//új.sor töröl
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::BuEllenorzesClick(TObject *Sender)
{
if(Ellenorzes() == 0) Application->MessageBox(/*"Ellenõrzés sikeres!"*/TxtCardKonv[33][Nyelv].c_str(), /*"Ellenõrzés"*/TxtCardKonv[31][Nyelv].c_str(), MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::BuSorBeszurClick(TObject *Sender)
{
int	kezd=CrdList->Row, veg=CrdList->RowCount,i,j;

if(kezd < 1) ;						//fejléc marad
else	{
	CrdList->RowCount++;
	for(i=veg; i>kezd; i--)
		for(j=0; j<CrdList->ColCount; j++)
			CrdList->Cells[j][i]=CrdList->Cells[j][i-1];//shift le
	for(j=0; j<CrdList->ColCount; j++)	CrdList->Cells[j][kezd]="";//új.sor töröl
	}
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::BuUjkartyaClick(TObject *Sender)
{
UjKartyaBe->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::FormClose(TObject *Sender, TCloseAction &Action)
{
KonvLeallit();
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::BuVisszaClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TCardKonv::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

