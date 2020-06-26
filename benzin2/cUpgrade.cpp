//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "cUpgrade.h"
#include "cModBusSoros.h"
#include "cMemo.h"
#include "cHexFile.h"
#include "cVezerlo.h"
#include "cTxtBenzin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TUpgrade *Upgrade;
//---------------------------------------------------------------------------
__fastcall TUpgrade::TUpgrade(TComponent* Owner):TForm(Owner)
{
UpgrTimFaz=UPGR_OFF;
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::FormActivate(TObject *Sender)
{
Caption=					TxtUpgrade[0][Nyelv];

GroupProgram->Caption=		TxtUpgrade[1][Nyelv];
RadioAuto->Caption=			TxtUpgrade[2][Nyelv];
RadioLepesenkent->Caption=	TxtUpgrade[3][Nyelv];
BuHexFile->Caption=			TxtUpgrade[4][Nyelv];

BuHexOlvas->Caption=		TxtUpgrade[5][Nyelv];
BuUpgradeClr->Caption=		TxtUpgrade[6][Nyelv];
BuUpgradeIr->Caption=		TxtUpgrade[7][Nyelv];
BuUpgradeOlv->Caption=		TxtUpgrade[8][Nyelv];

GroupVerzio->Caption=		TxtUpgrade[9][Nyelv];
BuVerziOlv->Caption=		TxtUpgrade[10][Nyelv];
LabAllapot->Caption=		TxtUpgrade[11][Nyelv];
BuVerzCsere->Caption=		TxtUpgrade[12][Nyelv];
BuProgramOlv->Caption=		TxtUpgrade[13][Nyelv];
BuToltoCsere->Caption=		TxtUpgrade[14][Nyelv];

GroupMemoria->Caption=		TxtUpgrade[15][Nyelv];
RadioHex->Caption=			TxtUpgrade[16][Nyelv];
RadioOlv->Caption=			TxtUpgrade[17][Nyelv];
BuMemory->Caption=			TxtUpgrade[18][Nyelv];
BuDump->Caption=			TxtUpgrade[19][Nyelv];
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::ListKiir(void)
{
int			i;
AnsiString	s;
DWord		*m;

if(RadioHex->Checked) m=DwHex; else m=DwOlv;
for(i=0; i<MEM_W_DB; i++)
	PrgMem->MemKi->Cells[i%16+1][i/16+1]=s.sprintf("%06X",(m[i]));
}
//---------------------------------------------------------------------------
Byte __fastcall TUpgrade::HexToByte(char be)
{
switch(be){
	case '0': return(0);
	case '1': return(1);
	case '2': return(2);
	case '3': return(3);
	case '4': return(4);
	case '5': return(5);
	case '6': return(6);
	case '7': return(7);
	case '8': return(8);
	case '9': return(9);
	case 'A':
	case 'a': return(10);
	case 'B':
	case 'b': return(11);
	case 'C':
	case 'c': return(12);
	case 'D':
	case 'd': return(13);
	case 'E':
	case 'e': return(14);
	case 'F':
	case 'f': return(15);
	}
return(15);
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::Memoba(AnsiString s)//egy sor értelmezése
{
char			*be=s.c_str();
int			len=s.Length();
int			sor,i;
Byte			beb[21];			//(1+2+1+16+1) bejövõ string byte-okban
Byte			bytedb,tip,maxb,sum;
Word			cimL,dat[8];
int			cim;
AnsiString	sk;

sor=HexFile->HexKi->RowCount-1;
HexFile->HexKi->Cells[0][sor]=s;
HexFile->HexKi->RowCount++;
if(be[0] != ':'){ HexHiba++; return; } 				//sorkezdés hiba

maxb=(len-1)/2;
if(maxb > 21) maxb=21;			//para
for(i=0; i<maxb; i++) beb[i]=HexToByte(be[2*i+1])*16+HexToByte(be[2*i+2]);
for(sum=0,i=0; i<maxb-1; i++)	sum+=beb[i];
sum=0x00-sum;

bytedb=	beb[0];
cimL=	(Word)beb[1]*256+beb[2];
tip=		beb[3];
for(i=0; i<8; i++){
	if(bytedb > i*2){
		if(tip == 0)	dat[i]=(Word)beb[2*i+5]*256 + beb[2*i+4];
		else			dat[i]=(Word)beb[2*i+4]*256 + beb[2*i+5];
		HexFile->HexKi->Cells[i+4][sor]=sk.sprintf("%04X",dat[i]);
		}
	else	{
		dat[i]=0;
		HexFile->HexKi->Cells[i+4][sor]="-";
		}
	}
HexFile->HexKi->Cells[1][sor]=bytedb;
HexFile->HexKi->Cells[2][sor]=sk.sprintf("%06X",((int)cimH*0x10000+cimL)/2);
HexFile->HexKi->Cells[3][sor]=tip;

if(bytedb > 16){ HexHiba++; return; }              		//hossz hiba
if(sum != beb[maxb-1]){ HexHiba++; return; }          		//chksum hiba

if		(tip == 0) cim=((int)cimH*0x010000+cimL)/4;		//data record
else if	(tip == 1) return;							//end of file record
//else if	(tip == 2) return;							//segment address record
else if	(tip == 4){								//linear address record
		cimH=dat[0];
		cim=((int)cimH*0x010000+cimL)/4;
		return;
		}
else		{ HexHiba++; return; }		         			//tipus hiba

if(tip == 0){
	if(cim < MEM_W_DB){
		if(bytedb >= 4){ 	DwHex[cim  ]=dat[1]*0x10000+dat[0]; }
		if(bytedb >= 8){ 	DwHex[cim+1]=dat[3]*0x10000+dat[2]; }
		if(bytedb >= 12){ 	DwHex[cim+2]=dat[5]*0x10000+dat[4]; }
		if(bytedb >= 16){ 	DwHex[cim+3]=dat[7]*0x10000+dat[6]; }
		}
	else if((cim >= 0x0f80000/2)&&(cim <= 0x0f80017/2)) ;	//Device Configuration Registers -> DO NOTHING !
	else	{ HexHiba++; return; }		                   	//cím hiba
	}
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::BuDumpClick(TObject *Sender)
{
int			len,db;
int			fD1;
DWord		*m;

if(RadioHex->Checked) m=DwHex; else m=DwOlv;

BuDump->Font->Color=clRed;

if(OpenDialogIr->Execute()){
	NevDump->Caption=OpenDialogIr->FileName;
	fD1=FileCreate(NevDump->Caption);
	if(fD1 < 1){
		KiDumpResu->Caption=TxtUpgrade[21][Nyelv];//"DUMP file megnyitási hiba!";
		}
	else	{
		len=sizeof(DwOlv);
		db=FileWrite(fD1,m,len);
		if(db != len)	KiDumpResu->Caption=TxtUpgrade[22][Nyelv];//"kiírás nem teljes!";
		else			KiDumpResu->Caption=TxtUpgrade[23][Nyelv];//"kiírás sikerült!";
		FileClose(fD1);
		}
	}
BuDump->Font->Color=clNavy;
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::Timer50ms(void) //100ms
{
Word			par,pag,cim;
DWord		min;
Byte			ki[8];
int			resu,szaz;
AnsiString	s;

if(Var50ms > 0){
	if(Var50ms > 1) Var50ms--;
	else	{ VerzioOlv(); return; }
	}

if(UpgrTimFaz != UPGR_OFF){
	switch(UpgrTimFaz){
		case UPGR_FLSCLR:
			min=(DWord)FLS_UPGRMIN*256;
			Wait++;
			if((Wait&0x03) == 0){
				Wait=0;
				if((xcim-min) < MEM_W_DB*4){
					if(FlashSectorClr((Word)(xcim/256)) == 0) xcim+=0x00800; else FlsClrHiba++;
					szaz=(100*(xcim-min))/MEM_W_DB/4;
					KiFlsClrResu->Caption=s.sprintf("%3i%% Error=%i",szaz,FlsClrHiba);
					KiFlsClrCim->Caption=s.sprintf("Cím: %06X",xcim);
					TrackFlsClr->SelEnd=szaz;
					}
				else	{
					if(RadioAuto->Checked){ StartUpgradeIr(); UpgrTimFaz=UPGR_FLSWR; }
					else	{ UpgrTimFaz=UPGR_OFF; }
					}
				}
			break;

		case UPGR_FLSWR:
			min=(DWord)FLS_UPGRMIN*256;
			if((xcim-min) < MEM_W_DB*4){
				if(FlashWrite(((Byte*)&DwHex)+(xcim-min),(Word)(xcim/256),(Byte)(xcim&0x80),128) == 0) xcim+=128; else FlsIrHiba++;
				szaz=(100*(xcim-min))/MEM_W_DB/4;
				KiFlsIrResu->Caption=s.sprintf("%3i%% Error=%i",szaz,FlsIrHiba);
				KiFlsIrCim->Caption=s.sprintf("Cím: %06X",xcim);
				TrackFlsIr->SelEnd=szaz;
				}
			else	{
				if(RadioAuto->Checked){ StartUpgradeOlv(); UpgrTimFaz=UPGR_FLSRD; }
				else	{ UpgrTimFaz=UPGR_OFF; }
				}
			break;

		case UPGR_FLSRD:
			min=(DWord)FLS_UPGRMIN*256;
			if((xcim-min) < MEM_W_DB*4){
				if(FlashRead(((Byte*)&DwOlv)+(xcim-min),(Word)(xcim/256),(Byte)(xcim&0x80),128) == 0) xcim+=128; else FlsOlvHiba++;
				szaz=(100*(xcim-min))/MEM_W_DB/4;
				KiFlsOlvResu->Caption=s.sprintf("%3i%% Error=%i",szaz,FlsOlvHiba);
				KiFlsOlvCim->Caption=s.sprintf("Cím: %06X",xcim);
				TrackFlsOlv->SelEnd=szaz;
				}
			else	{
				UpgrTimFaz=UPGR_OFF;
				ListKiir();
				szaz=0;
				for(cim=0; cim<MEM_W_DB; cim++) if(DwHex[cim] != DwOlv[cim]) szaz++;
				if(szaz == 0){
					KiLetoltesResu->Font->Color=clBlue;
					KiLetoltesResu->Caption=TxtUpgrade[24][Nyelv];//"SIKERES letöltés !";
					}
				else	{
					KiLetoltesResu->Font->Color=clRed;
					KiLetoltesResu->Caption=s.sprintf("%s: %i !!!",/*Hibák száma*/TxtUpgrade[25][Nyelv],szaz);
					}
				}
			break;
		case UPGR_PRGRD:
			if(xcim < 0x015800-64){
				par=0x0101;	//ReadLatch64_L
				pag=(Word)(xcim>>16);
				cim=(Word)(xcim&0xffff);
				ki[0]=High(par); ki[1]=Low(par);
				ki[2]=High(pag); ki[3]=Low(pag);
				ki[4]=High(cim); ki[5]=Low(cim);
				resu=MemWrite(ki,WR_PFLSPAR,6);	//ReadFlsRow(pag,cim);
				if(resu == 0){
					resu=MemRead((Byte*)&DwOlv[xcim/2],RD_PFLSROW  ,128);
					resu=MemRead((Byte*)&DwOlv[xcim/2+32],RD_PFLSROW+1,128);
					xcim+=64;
					}
				else	PrgReadHiba++;

				szaz=(100*xcim)/(MEM_W_DB*2-64);
				KiPrgReadResu->Caption=s.sprintf("%3i%% Error=%i",szaz,PrgReadHiba);
				KiPrgReadCim->Caption=s.sprintf("Cím: %06X",xcim);
				TrackPrgRead->SelEnd=szaz;
				}
			else	{
				UpgrTimFaz=UPGR_OFF;
				ListKiir();
				}
			break;
		}
	}
}
//---------------------------------------------------------------------------
int __fastcall TUpgrade::StartHexOlvas(void)
{
int			fH1,resu=1;
int			i,len,db;
char			b;
AnsiString	s;

BuHexOlvas->Font->Color=clRed;
HexFile->HexKi->RowCount=2;
for(i=0; i<MEM_W_DB; i++) DwHex[i]=0x00ffffff;
ListKiir();

if(OpenDialog->Execute()){
	NevHexForras->Caption=OpenDialog->FileName;
	fH1=FileOpen(NevHexForras->Caption,fmOpenRead);
	if(fH1 < 1) KiHexResu->Caption="HEX file megnyitási hiba!";
	else	{
		len=FileSeek(fH1,0,2);					//hossz
		if(len > HEXFILE_LEN) KiHexResu->Caption=TxtUpgrade[26][Nyelv];//"HEX file túl nagy!";
		else	{
			FileSeek(fH1,0,0);					//elejére
			db=FileRead(fH1,&Hex,len);			//db=beolvasott byte
			if(db != len)	KiHexResu->Caption=TxtUpgrade[27][Nyelv];//"beolvasás nem teljes!";
			else{ resu=0;	KiHexResu->Caption=TxtUpgrade[28][Nyelv];/*"beolvasás sikerült!"*/ }	//van beolvasott teljes rekord
			}
		FileClose(fH1);
		}

	HexHiba=0; cimH=0;
	if(resu == 0){
		for(i=0; i<len; i++){
			b=Hex[i];
			if(b != 0x0a) s+=b;
			else	{
				Memoba(s); s="";
				}
			}
		}

	if(HexHiba > 0){ KiHexHiba->Font->Color=clRed; resu=1; }
	else			  KiHexHiba->Font->Color=clGreen;
	KiHexHiba->Caption=s.sprintf("Error=%i",HexHiba);
	}
BuHexOlvas->Font->Color=clNavy;
ListKiir();
return(resu);
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::BuHexOlvasClick(TObject *Sender)
{
if(StartHexOlvas() == 0){
	if(RadioAuto->Checked){
		KiFlsClrResu->Caption="0%";
		KiFlsClrCim->Caption="0";
		TrackFlsClr->SelEnd=0;

		KiFlsIrResu->Caption="0%";
		KiFlsIrCim->Caption="0";
		TrackFlsIr->SelEnd=0;

		KiFlsOlvResu->Caption="0%";
		KiFlsOlvCim->Caption="0";
		TrackFlsOlv->SelEnd=0;

		KiLetoltesResu->Font->Color=clBlue;
		KiLetoltesResu->Caption="-";
		StartUpgradeClr();
		UpgrTimFaz=UPGR_FLSCLR;
		}
	}
}
//---------------------------------------------------------------------------
#define	WR_PFLSPAR	0x70	//program flash parancs(r/w/e+page+cím)
#define	RD_PFLSROW	0x72	//read program flash row
//	0x000000 - 0x0157fe = 128kbyte Flash
// 1 row = 64 instuction = 192 byte
// 1 page = 8 row = 512 insturction = 1536 byte (ERASE)
//---------------------------------------------------------------------------
void __fastcall TUpgrade::StartUpgradeClr(void)
{
xcim=(DWord)FLS_UPGRMIN*256;
FlsClrHiba=0; Wait=0;
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::BuUpgradeClrClick(TObject *Sender)
{
if(!RadioAuto->Checked){
	StartUpgradeClr();
	UpgrTimFaz=UPGR_FLSCLR;
	}
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::StartUpgradeIr(void)
{
xcim=(DWord)FLS_UPGRMIN*256;
FlsIrHiba=0;
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::BuUpgradeIrClick(TObject *Sender)
{
if(!RadioAuto->Checked){
	StartUpgradeIr();
	UpgrTimFaz=UPGR_FLSWR;
	}
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::StartUpgradeOlv(void)
{
int	i;
for(i=0; i<MEM_W_DB; i++) DwOlv[i]=0x00ffffff;
ListKiir();

xcim=(DWord)FLS_UPGRMIN*256;
FlsOlvHiba=0;
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::BuUpgradeOlvClick(TObject *Sender)
{
if(!RadioAuto->Checked){
	StartUpgradeOlv();
	UpgrTimFaz=UPGR_FLSRD;
	}
}
//---------------------------------------------------------------------------
/*void __fastcall TUpgrade::Iras1Row(Word pag,Word cim)
{
int	i,resu,par;
long	pki[64];
Byte	ki[256];

for(i=0; i<64; i++) pki[i]=cim+i;
par=0x0102;
ki[0]=High(par); ki[1]=Low(par);
ki[2]=High(pag); ki[3]=Low(pag);
ki[4]=High(cim); ki[5]=Low(cim);
for(i=0; i<32; i++) memcpy(&ki[4*i+6],&pki[i],4);
resu=MemWrite(ki,WR_PFLSPAR,6+128);
par=0x0103;
ki[0]=High(par); ki[1]=Low(par);
ki[2]=High(pag); ki[3]=Low(pag);
ki[4]=High(cim); ki[5]=Low(cim);
for(i=0; i<32; i++) memcpy(&ki[4*i+6],&pki[i+32],4);
resu=MemWrite(ki,WR_PFLSPAR,6+128);
}*/
//---------------------------------------------------------------------------
void __fastcall TUpgrade::BuVerzCsereClick(TObject *Sender)
{
int	i,par,pag,cim;
Byte	ki[8];

//(Application->MessageBox(TxtUpgrade[28][Nyelv]"Biztosan ki akarod cserélni a futó verziót ?","*** VERZIÓ CSERE ***", MB_OKCANCEL) == IDOK){
if(Application->MessageBox(TxtUpgrade[30][Nyelv].c_str(),TxtUpgrade[30][Nyelv].c_str(), MB_OKCANCEL) == IDOK){
	pag=(Word)(0x4321);
	cim=(Word)(0x6789);
	par=0x0209;	//upgrade_H
	ki[0]=High(par); ki[1]=Low(par);
	ki[2]=High(pag); ki[3]=Low(pag);
	ki[4]=High(cim); ki[5]=Low(cim);
	MemWrite(ki,WR_PFLSPAR,6);
	Var50ms=100;
	}
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::BuToltoCsereClick(TObject *Sender)
{
int	i,par,pag,cim;
Byte	ki[8];

//(Application->MessageBox("Biztosan ki akarod cserélni a program töltõt ?","*** PROGRAM TÖLTÕ CSERE ***", MB_OKCANCEL) == IDOK){
if(Application->MessageBox(TxtUpgrade[32][Nyelv].c_str(),TxtUpgrade[31][Nyelv].c_str(), MB_OKCANCEL) == IDOK){
	pag=(Word)(0x1234);
	cim=(Word)(0x9876);
	par=0x0109;	//upgrade_L
	ki[0]=High(par); ki[1]=Low(par);
	ki[2]=High(pag); ki[3]=Low(pag);
	ki[4]=High(cim); ki[5]=Low(cim);
	MemWrite(ki,WR_PFLSPAR,6);
	Var50ms=20;
	}
}
//---------------------------------------------------------------------------
Word __fastcall TUpgrade::VerzioOlv_L(Word pag,Word cim)
{
int		i,res,par;
Byte		ki[8],be[8];

par=0x0101;	//ReadLatch64_L
ki[0]=High(par); ki[1]=Low(par);
ki[2]=High(pag); ki[3]=Low(pag);
ki[4]=High(cim); ki[5]=Low(cim);
res=MemWrite(ki,WR_PFLSPAR,6);	//ReadFlsRow(pag,cim);
if(res == 0){
	res=MemRead(be,RD_PFLSROW,4);
	if(res == 0) return((Word)be[1]*256+be[0]);
	}
return(0);
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::VerzioOlv(void)
{
int		i,res1,res2,par,pag,cim;
Byte		ki[8],be[128];
Word		verz1,verz2;
TColor	col[15];

verz1=VerzioOlv_L(0x00,0x0200);
verz2=VerzioOlv_L(0x01,0x5000);
if((verz1 > 0)&&(verz2 > 0))	KiVerzio->Font->Color=clGreen;
else						KiVerzio->Font->Color=clRed;
KiVerzio->Caption=s.sprintf("%s= %i  -  %s= %i",/*Program Verzió*/TxtUpgrade[33][Nyelv],verz1,/*Töltõ verzió*/TxtUpgrade[34][Nyelv],verz2);

for(i=0; i<15; i++){
	res1=MemRead(be,0x20+i,6);
	if(res1 == 0){
		switch(be[4]){
			case	0:
			case 20:	col[i]=clSilver; break;
			case 1:	col[i]=clGreen; break;
			default:	col[i]=clRed; break;
			}
		}
	else	Kut1->Color=clRed;
	}

Kut1->Color=col[0];
Kut2->Color=col[1];
Kut3->Color=col[2];
Kut4->Color=col[3];
Kut5->Color=col[4];
Kut6->Color=col[5];
Kut7->Color=col[6];
Kut8->Color=col[7];
Kut9->Color=col[8];
Kut10->Color=col[9];
Kut11->Color=col[10];
Kut12->Color=col[11];
Kut13->Color=col[12];
Kut14->Color=col[13];
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::BuVerziOlvClick(TObject *Sender)
{
VerzioOlv();
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::BuProgramOlvClick(TObject *Sender)
{
int	i;

for(i=0; i<MEM_W_DB; i++) DwOlv[i]=0x00ffffff;
ListKiir();

xcim=0; PrgReadHiba=0;
UpgrTimFaz=UPGR_PRGRD;
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::BuHexFileClick(TObject *Sender)
{
HexFile->Show();
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::RadioAutoClick(TObject *Sender)
{
BuUpgradeClr->Font->Color=clBlack;
BuUpgradeIr->Font->Color=clBlack;
BuUpgradeOlv->Font->Color=clBlack;
BuUpgradeClr->Font->Style= TFontStyles();
BuUpgradeIr->Font->Style= TFontStyles();
BuUpgradeOlv->Font->Style= TFontStyles();
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::RadioLepesenkentClick(TObject *Sender)
{
BuUpgradeClr->Font->Color=clNavy;
BuUpgradeIr->Font->Color=clNavy;
BuUpgradeOlv->Font->Color=clNavy;
BuUpgradeClr->Font->Style= TFontStyles()<< fsUnderline;
BuUpgradeIr->Font->Style= TFontStyles()<< fsUnderline;
BuUpgradeOlv->Font->Style= TFontStyles()<< fsUnderline;
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::RadioOlvClick(TObject *Sender)
{
ListKiir();
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::RadioHexClick(TObject *Sender)
{
ListKiir();
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::BuMemoryClick(TObject *Sender)
{
ListKiir();
PrgMem->Show();
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::FormClose(TObject *Sender, TCloseAction &Action)
{
UpgrTimFaz=UPGR_OFF;
}
//---------------------------------------------------------------------------
void __fastcall TUpgrade::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

