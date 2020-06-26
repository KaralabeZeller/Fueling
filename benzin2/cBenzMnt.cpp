#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include "cBenzMnt.h"
#include "cModbusSoros.h"
#include "cTeszt.h"
#include "cVezerlo.h"
#include "cTxtBenzin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBenzMent *BenzMent;
//---------------------------------------------------------------------------
__fastcall 		TBenzMent::TBenzMent(TComponent* Owner):TForm(Owner)
{
Mehet= false; Beir= false;
f0= -1; f1= -1;
}
//---------------------------------------------------------------------------
void __fastcall 	TBenzMent::FormActivate(TObject *Sender)
{
Caption=				TxtBenzMent[0][Nyelv];
BuLetolt->Caption=		TxtBenzMent[1][Nyelv];
BuMegszak->Caption=		TxtBenzMent[2][Nyelv];
LabKezdoCim->Caption=	TxtBenzMent[5][Nyelv];
CimMax->Caption=		bs.sprintf("(max. %05i)", FLS_TANKMAX);
}
//---------------------------------------------------------------------------
void __fastcall 	TBenzMent::ToltesLeallit(void)
{
Mehet= false; Beir= false;
if(f0 > 0){ FileClose(f0); f0= -1; }
if(f1 > 0){ FileClose(f1); f1= -1; }
Hiba->Caption= Hiba->Caption+"->Leálltva";
}
//---------------------------------------------------------------------------
void __fastcall 	TBenzMent::Timer50ms(void)
{
int		i, hibu= 0, db, stop= 0;

//-----------------------------------------------beírás
if(Beir){
	if(Cim > FLS_TANKMAX) ToltesLeallit();
	else	{
		db= FileSeek(f0, Cim*128, 0);
		if(db != Cim*128) stop= 1;
		if(stop == 0){
			db= FileRead(f0, be, 128);		//Konvert.tnk
			if(db != 128) stop= 2;
			}

		if(stop){ Hiba->Caption= Hiba->Caption+"->KÉSZ"; ToltesLeallit(); }
		else	{
			Resu= FlashWrite(be, Cim/2, (Cim&1)*128, 128);
			if(Resu > 0){ Error++; if(Error > 10) ToltesLeallit(); }
			if(Resu == 0){ Error= 0; Cim++; }
			BenzMent->Hiba->Caption= bs.sprintf("TnkWrt:%5i  %s:%5i - %i", Cim, /*Javítva*/TxtBenzMent[4][Nyelv], Error, hibu);
			}
		}
	return;
	}
//-----------------------------------------------alap
if(!Mehet) return;
if(Cim > FLS_TANKMAX) ToltesLeallit();
else{
	Resu= FlashRead(be, Cim/2, (Cim&1)*128, 128);
	if(Resu > 0){ Error++; if(Error > 60) stop= 1; }
	if(Resu == 0){									//jó csomag
		Error= 0;
		for(i=0; i<6; i++) if(be[i] != 0xff) Resu= 1;	//nem üres
		if(Resu == 0) stop= 2;						//ha üres -> stop
		else	{
			FileWrite(f0, be, 128);		//*.tnk
			K4tankKonvertal();			//*.csv
			Cim++;
			}
		}
	BenzMent->Hiba->Caption= bs.sprintf("%s:%5i  %s:%5i - %i", /*Tank*/TxtBenzMent[3][Nyelv], Cim, /*Javítva*/TxtBenzMent[4][Nyelv], Error, hibu);
	if(stop) ToltesLeallit();
	}
}
//---------------------------------------------------------------------------
void __fastcall 	TBenzMent::K2tankKonvertal(void)
{
int		len, i;
Byte		be[68];

len= FileSeek(f0, 0, 2);//végére
if(len < 1){ BenzMent->Hiba->Caption= "*** SIZE ERROR ***"; return; }
FileSeek(f0, 0, 0);//elejére
FileSeek(f1, 0, 0);//elejére

bs.sprintf(	"TYP1;DATE;TIME;CRDAUTO;CRDEMBER;" \
			"TYP2;LITKOMP;KM;MENLEV;CSOPORT;KUTSZAM;" \
			"TYP3;LITER;GORG;HOMER;EMBERNUM;HIBAKOD;" \
			"TYP4;GORGKOMP;SZINT;VEZERLO;UZEMORA;\r\n");
FileWrite(f1, bs.c_str(), bs.Length());

for(i=0; i<len; i+=64){//1blokk= 64byte
	if(FileRead(f0, be, 64) == 64){
/*
.equ	T_TIP1		=0x00	;1b	+0	=01
.equ	T_EV			=0x01	;1b	+1
.equ	T_HO			=0x02	;1b
.equ	T_NAP		=0x03	;1b
.equ	T_ORA		=0x04	;1b
.equ	T_PERC		=0x05	;1b
.equ	T_AUTO		=0x06	;5b	+6
.equ	T_EMBER		=0x0b	;5b	+11
*/		bs.sprintf("%i;%02i/%02i/%02i;%02i:%02i;%i%i%i%i%i%i%i%i%i%i;%i%i%i%i%i%i%i%i%i%i;", \
					be[0x00], \
					be[0x01],be[0x02],be[0x03], be[0x04],be[0x05], \
					be[0x06]/16,be[0x06]&0x0f, be[0x07]/16,be[0x07]&0x0f, be[0x08]/16,be[0x08]&0x0f, be[0x09]/16,be[0x09]&0x0f, be[0x0a]/16,be[0x0a]&0x0f, \
					be[0x0b]/16,be[0x0b]&0x0f, be[0x0c]/16,be[0x0c]&0x0f, be[0x0d]/16,be[0x0d]&0x0f, be[0x0e]/16,be[0x0e]&0x0f, be[0x0f]/16,be[0x0f]&0x0f );
		FileWrite(f1, bs.c_str(), bs.Length());
/*
.equ	T_TIP2		=0x10	;1b	+16	=02
.equ	T_LITKOMP		=0x11	;4b	+17	(999999,99l)
.equ	T_KM			=0x15	;4b	+21	(99999999km)
.equ	T_MENLEV		=0x19	;4b	+25	(99999999)
;.equ T_AUTONUM	=0x1d	;2b	+29
.equ	T_CSOPORT		=0x1d	;1b	+29	csoport száma
;1b hely
.equ	T_KUTSZAM		=0x1f	;1b	+31	(1-9)
*/		bs.sprintf("%i;%i%i%i%i%i%i,%i%i;%02i%02i%02i%02i;%02i%02i%02i%02i;%02i;%02i;", \
					be[0x10], \
					be[0x11]/16,be[0x11]&0x0f, be[0x12]/16,be[0x12]&0x0f, be[0x13]/16,be[0x13]&0x0f, be[0x14]/16,be[0x14]&0x0f, \
					be[0x15],be[0x16],be[0x17],be[0x18], \
					be[0x19],be[0x1a],be[0x1b],be[0x1c], \
					be[0x1d], be[0x1f]);
		FileWrite(f1, bs.c_str(), bs.Length());
/*
.equ	T_TIP3		=0x20	;1b	+32	=03
.equ	T_LITER		=0x21	;4b	+33	(999999,99l)
.equ	T_GORG		=0x25	;6b	+37	(9999.999999,99l)
.equ	T_HOMER		=0x2b	;2b	+43	w256
.equ	T_EMBERNUM	=0x2d	;2b	+45
.equ	T_HIBAKOD		=0x2f	;1b	+47	EndStatusz
*/		bs.sprintf("%i;%i%i%i%i%i%i,%i%i;%i%i%i%i%i%i%i%i%i%i,%i%i;%04i;%04i;%02i;", \
					be[0x20], \
					be[0x21]/16,be[0x21]&0x0f, be[0x22]/16,be[0x22]&0x0f, be[0x23]/16,be[0x23]&0x0f, be[0x24]/16,be[0x24]&0x0f, \
					be[0x25]/16,be[0x25]&0x0f, be[0x26]/16,be[0x26]&0x0f, be[0x27]/16,be[0x27]&0x0f, be[0x28]/16,be[0x28]&0x0f, \
					be[0x29]/16,be[0x29]&0x0f, be[0x2a]/16,be[0x2a]&0x0f, \
					be[0x2b]*256+be[0x2c], be[0x2d]*256+be[0x2e], be[0x2f]);
		FileWrite(f1, bs.c_str(), bs.Length());
/*
.equ	T_TIP4		=0x30	;1b	+48	=04
.equ	T_GORGKOMP	=0x31	;6b	+49	(9999.999999,99l)
.equ	T_SZINT		=0x37	;2b	+55	(0-0xffff liter)
.equ	T_VEZERLO		=0x39	;1b	+57	Vezérlõ száma+mester
.equ	T_UZEMORA		=0x3a	;4b	+58
.equ	T_CHK		=0x3e	;2b	+62
*/
		bs.sprintf("%i;%i%i%i%i%i%i%i%i%i%i,%i%i;%05i;%02i;%05i;\r\n", \
					be[0x30], \
					be[0x31]/16,be[0x31]&0x0f, be[0x32]/16,be[0x32]&0x0f, be[0x33]/16,be[0x33]&0x0f, be[0x34]/16,be[0x34]&0x0f, \
					be[0x35]/16,be[0x35]&0x0f, be[0x36]/16,be[0x36]&0x0f, \
					be[0x37]*256+be[0x38],
					be[0x39], be[0x3a]*256+be[0x3b]);
		FileWrite(f1, bs.c_str(), bs.Length());
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall 	TBenzMent::K4tankKonvertal(void)
{
//uint16_t	KezdVerz;			//x00		=0x3001	kezdô rekord
//uint8_t		KezdEv;			//x02		kezdési id?
//uint8_t		KezdHo;			//x03
//uint8_t		KezdNap;			//x04
//uint8_t		KezdOra;			//x05
//uint8_t		KezdPerc;			//x06
//uint8_t		KezdMp;			//x07
bs.sprintf("%05i;%02i/%02i/%02i;%02i:%02i:%02i;", \
	(int)be[0x00]+(int)be[0x01]*256, \
	be[0x02], be[0x03], be[0x04], \
	be[0x05], be[0x06], be[0x07]);
FileWrite(f1, bs.c_str(), bs.Length());

//uint8_t		VezNum;			//x08		Vezérlô száma+mester
//uint8_t		KutNum;			//x09		(1-16)
//uint16_t	EmberNum;			//x0a
//uint16_t	AutoNum;			//x0c
//uint16_t	Csoport;			//x0e		csoport száma
bs.sprintf("%i;%i;%05i;%05i;%05i;", \
	be[0x08], be[0x09], \
	(int)be[0x0a]+(int)be[0x0b]*256, \
	(int)be[0x0c]+(int)be[0x0d]*256, \
	(int)be[0x0e]+(int)be[0x0f]*256);
FileWrite(f1, bs.c_str(), bs.Length());

//uint8_t		EmberId[7];		//x10		6+1byte bin ->15+2számjegy
//uint8_t		AutoId[7];		//x17
bs.sprintf("%02x%02x%02x%02x%02x%02x%02x;%02x%02x%02x%02x%02x%02x%02x;", \
	be[0x10], be[0x11], be[0x12], be[0x13], be[0x14], be[0x15], be[0x16], \
	be[0x17], be[0x18], be[0x19], be[0x1a], be[0x1b], be[0x1c], be[0x1d]);
FileWrite(f1, bs.c_str(), bs.Length());

//uint32_t	Km;				//x1e		(99.999.999km)
//uint32_t	Menlev;			//x22		(99.999.999)
//uint32_t	Uzemora;			//x26		(99.999.999)
bs.sprintf("%010li;%010li;%010li;", \
	(((long)be[0x21]*256+be[0x20])*256+be[0x1f])*256+be[0x1e], \
	(((long)be[0x25]*256+be[0x24])*256+be[0x23])*256+be[0x22], \
	(((long)be[0x29]*256+be[0x28])*256+be[0x27])*256+be[0x26]);
FileWrite(f1, bs.c_str(), bs.Length());

//---------------------------------------------------------------------------
//uint8_t		EmberNev[20];		//x2a
//uint8_t		AutoNev[20];		//x3e
bs.sprintf("%20.20s;%20.20s;", \
	&be[0x2a], &be[0x3e]);
FileWrite(f1, bs.c_str(), bs.Length());

//uint8_t		Gorg[6];			//x52		(9.999.999.999,99l)
//uint8_t		GorgKomp[6];		//x58		(9.999.999.999,99l)
bs.sprintf("%02i%02i%02i%02i%02i.%02i;%02i%02i%02i%02i%02i.%02i;", \
	be[0x52],be[0x53],be[0x54],be[0x55],be[0x56],be[0x57], \
	be[0x58],be[0x59],be[0x5a],be[0x5b],be[0x5c],be[0x5d]);
FileWrite(f1, bs.c_str(), bs.Length());

//uint16_t	EgysArNto;		//x5e		*0.01Ft egységár nto(max 655.35Ft/l)
//uint16_t	TankCim;			//x60		[0-65536]mentési pozíció=tankolás sorszáma
//uint16_t	Szint;			//x62		(99999)szintméro a kezdésnél
 bs.sprintf("%05i;%05i;%05i;", \
	(int)be[0x5e]+(int)be[0x5f]*256, \
	(int)be[0x60]+(int)be[0x61]*256, \
	(int)be[0x62]+(int)be[0x63]*256);
FileWrite(f1, bs.c_str(), bs.Length());
//---------------------------------//x64=100byte-tankolás elején mentve
//uint8_t		ZarEv;			//x64		zárási idõ
//uint8_t		ZarHo;			//x65
//uint8_t		ZarNap;			//x66
//uint8_t		ZarOra;			//x67
//uint8_t		ZarPerc;			//x68
//uint8_t		ZarMp;			//x69
bs.sprintf("20%02i/%02i/%02i;%02i:%02i:%02i;", \
	be[0x64], be[0x65], be[0x66], \
	be[0x67], be[0x68], be[0x69]);
FileWrite(f1, bs.c_str(), bs.Length());

//uint32_t	LitKomp;			//x6a		(999.999,99l) [0-42.949.672,96]
//uint32_t	Liter;			//x6e		(999.999,99l)
bs.sprintf("%4.2f;%4.2f;",
	(float)((((long)be[0x6d]*256+be[0x6c])*256+be[0x6b])*256+be[0x6a])/100, \
	(float)((((long)be[0x71]*256+be[0x70])*256+be[0x6f])*256+be[0x6e])/100);
FileWrite(f1, bs.c_str(), bs.Length());

//uint16_t	KutHom;			//x72		0=-40.0 - 400=0.0
//uint8_t		Hibakod;			//x74		EndStatusz
//uint8_t		NyomtatDb;		//x75		0=ready,=1,2 ennyi példányt kell még nyomtatni
//uint32_t	ArNetto;			//x76		*0.01Ft netto végösszeg
//uint32_t	ArBrutto;			//x7a		*0.01Ft brutto végösszeg
//uint16_t	Sum;				//x7e
bs.sprintf("%5.1f;%i;%i;%5.2f;%5.2f;%05i;\r\n", \
	(float)((int)be[0x72]+(int)be[0x73]*256)/10, \
	be[0x74], be[0x75], \
	(float)((((long)be[0x79]*256+be[0x78])*256+be[0x77])*256+be[0x76])/100, \
	(float)((((long)be[0x7d]*256+be[0x7c])*256+be[0x7b])*256+be[0x7a])/100, \
	(int)be[0x7e]+(int)be[0x7f]*256);
FileWrite(f1, bs.c_str(), bs.Length());
}
//---------------------------------------------------------------------------
int __fastcall 	TBenzMent::SorRead(void)
{
int		m, i, db, voltR= 0;
char		ch[4];

for(m=0; m<30; m++) mezo[m]= "";
for(m=0; m<30; m++){						//mezok
	for(i=0; i<20; i++){					//mezon belül
		db= FileRead(f0, ch, 1);
		if(db == 1){
			if		(ch[0] == '\r') voltR= 1;	//sor vége 1
			else if	(ch[0] == '\n') break;		//sor vége 2
			else	{
				if(ch[0] == ';'){ i= 21;			//mezõ vége
					}
				else{ mezo[m]+= ch[0]; }
				}
			}
		else	{
			if((m == 0)&&(i == 0)&&(db == 0)) return(2);
			}
		}
	}
if		((db != 0)&&(voltR == 0)){ BenzMent->Hiba->Caption= bs.sprintf("*** SOR VÉGE HIBA (sor=%i)***", sor);	return(1); }
else if	(m != 30){ 	BenzMent->Hiba->Caption= bs.sprintf("*** MEZÕ SZÁM HIBA (sor=%i)***", sor);return(1); }
return(0);
}
//---------------------------------------------------------------------------
int __fastcall 	TBenzMent::MezoGet2i(int meznum, int chnum)
{
char		ch1, ch2;
int		ki, len;

len= mezo[meznum].Length();
if(len < 1) return(-1);
if(len == 1){ ch1= '0'; ch2= mezo[meznum][chnum]; }
else{ ch1= mezo[meznum][chnum]; ch2= mezo[meznum][chnum+1]; }
if((ch1 < '0')||(ch1 > '9')) return(-1);
if((ch2 < '0')||(ch2 > '9')) return(-1);
ki= ((int)ch1-'0')*10+ch2-'0';
return(ki);
}
//---------------------------------------------------------------------------
int __fastcall 	TBenzMent::MezoGet10i(AnsiString mez, int chnum, int max)
{
int		ch[10]= {0,0,0,0,0,0,0,0,0,0};
int		i, ki1, ki, len;

len= mez.Length();
if((len < 1)||(len > max)) return(-1);
for(i=0; i<len; i++){
	ch[10-len+i]= (int)mez[chnum+i]-'0';
	if((ch[i] < 0)||(ch[i] > 9)) return(-1);
	}
ki1= (((ch[0]*10+ch[1])*10+ch[2])*10+ch[3])*10+ch[4];
ki= 	(((ch[5]*10+ch[6])*10+ch[7])*10+ch[8])*10+ch[9];
return(ki1*100000+ki);
}
//---------------------------------------------------------------------------
int __fastcall 	TBenzMent::MezoBcd02(AnsiString mez, int chnum)
{
int		ch[2]= {0,0};
int		i, ki, len;

len= mez.Length();
if(len < 2) return(-1);
ch[0]= (int)mez[chnum]-'0';
ch[1]= (int)mez[chnum+1]-'0';
if((ch[0] < 0)||(ch[0] > 9)) return(-1);
if((ch[1] < 0)||(ch[1] > 9)) return(-1);
ki= ch[0]*16+ch[1];
return(ki);
}
//---------------------------------------------------------------------------
int __fastcall 	TBenzMent::MezoI100(AnsiString mez, int chnum)
{
int		ch[2]= {0,0};
int		i, ki, len;

len= mez.Length()-chnum+1;
if(len < 1) return(-1);
if(len < 2)	{ ch[1]= (int)mez[chnum]-'0'; }
else			{ ch[0]= (int)mez[chnum]-'0'; ch[1]= (int)mez[chnum+1]-'0'; }
if((ch[0] < 0)||(ch[0] > 9)) return(-1);
if((ch[1] < 0)||(ch[1] > 9)) return(-1);
ki= ch[0]*10+ch[1];
return(ki);
}
//---------------------------------------------------------------------------
int __fastcall 	TBenzMent::MezoGorg(AnsiString mez, Byte *ki)
{
int		ch[12];
int		i, pos, len;

bs= "000000000000"+mez;
pos= bs.Pos("."); len= bs.Length();
if		(pos == 0) 		bs= bs+".00";
else if	((len-pos) == 1) 	bs= bs+"0";
len= bs.Length();
if(len < 13) return(-1);
bs= bs.SubString(len-12, 13);

ch[0]= (int)bs[1]-'0'; ch[1]= (int)bs[2]-'0';
ch[2]= (int)bs[3]-'0'; ch[3]= (int)bs[4]-'0';
ch[4]= (int)bs[5]-'0'; ch[5]= (int)bs[6]-'0';
ch[6]= (int)bs[7]-'0'; ch[7]= (int)bs[8]-'0';
ch[8]= (int)bs[9]-'0'; ch[9]= (int)bs[10]-'0';
ch[10]= (int)bs[12]-'0'; ch[11]= (int)bs[13]-'0';
for(i=0; i<12; i++) if((ch[0] < 0)||(ch[0] > 9)) return(-1);

ki[0]= ch[0]*10+ch[1];
ki[1]= ch[2]*10+ch[3];
ki[2]= ch[4]*10+ch[5];
ki[3]= ch[6]*10+ch[7];
ki[4]= ch[8]*10+ch[9];
ki[5]= ch[10]*10+ch[11];
return(0);
}
//---------------------------------------------------------------------------
int __fastcall 	TBenzMent::MezoLiter(AnsiString mez, Byte *ki)
{
//uint32_t	LitKomp;			//x6a		(999.999,99l) [0-42.949.672,96]
//uint32_t	Liter;			//x6e		(999.999,99l)
int		ch[10];
int		i, pos, len, ki1, ki2;

bs= "0000000000"+mez;
pos= bs.Pos("."); len= bs.Length();
if		(pos == 0) 		bs= bs+".00";
else if	((len-pos) == 1) 	bs= bs+"0";
len= bs.Length();
if(len < 11) return(-1);
bs= bs.SubString(len-10, 11);

ch[0]= (int)bs[1]-'0'; ch[1]= (int)bs[2]-'0';
ch[2]= (int)bs[3]-'0'; ch[3]= (int)bs[4]-'0';
ch[4]= (int)bs[5]-'0'; ch[5]= (int)bs[6]-'0';
ch[6]= (int)bs[7]-'0'; ch[7]= (int)bs[8]-'0';
ch[8]= (int)bs[10]-'0'; ch[9]= (int)bs[11]-'0';
for(i=0; i<10; i++) if((ch[0] < 0)||(ch[0] > 9)) return(-1);

ki2= (((ch[0]*10+ch[1])*10+ch[2])*10+ch[3])*10+ch[4];
ki1= (((ch[5]*10+ch[6])*10+ch[7])*10+ch[8])*10+ch[9];
ki1+= ki2*100000;

ki[0]= ki1%256; ki1/=256;
ki[1]= ki1%256; ki1/=256;
ki[2]= ki1%256; ki[3]= ki1/256;
return(0);
}
//---------------------------------------------------------------------------
int __fastcall 	TBenzMent::MezoHom(AnsiString mez, Byte *ki)
{
int		ch[4];  //000.0
int		i, pos, len, ki1;

bs= "00000"+mez;
pos= bs.Pos("."); len= bs.Length();
if		(pos == 0)  	bs= bs+".0";
else if	(len == pos)	bs= bs+"0";
len= bs.Length();
if(len < 5) return(-1);
bs= bs.SubString(len-4, 5);

ch[0]= (int)bs[1]-'0'; ch[1]= (int)bs[2]-'0';
ch[2]= (int)bs[3]-'0'; ch[3]= (int)bs[5]-'0';
for(i=0; i<4; i++) if((ch[0] < 0)||(ch[0] > 9)) return(-1);

ki1= ((ch[0]*10+ch[1])*10+ch[2])*10+ch[3];
if(ki1 > 990) return(-1);

ki[0]= ki1%256; ki[1]= ki1/256;
return(0);
}
//---------------------------------------------------------------------------
int __fastcall 	TBenzMent::MezoWrite(void)
{
int		i;
Byte		ki[130];

for(i=0; i<128; i++) ki[i]= 0xff;

if(mezo[0] != "12291"){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-VERZ1 HIBA"; return(1); }
ki[0]= 0x03; ki[1]= 0x30;	//x3003=12291

i= MezoGet2i(1, 1);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-DATE HIBA"; return(1); }
if(mezo[1][3] != '/'){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-DATE HIBA"; return(1); }
ki[2]= i;
i= MezoGet2i(1, 4);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-DATE HIBA"; return(1); }
ki[3]= i;
if(mezo[1][6] != '/'){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-DATE HIBA"; return(1); }
i= MezoGet2i(1, 7);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-DATE HIBA"; return(1); }
ki[4]= i;

i= MezoGet2i(2, 1);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-TIME HIBA"; return(1); }
if(mezo[2][3] != ':'){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-TIME HIBA"; return(1); }
ki[5]= i;
i= MezoGet2i(2, 4);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-TIME HIBA"; return(1); }
ki[6]= i;
if(mezo[2][6] != ':'){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-TIME HIBA"; return(1); }
i= MezoGet2i(2, 7);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-TIME HIBA"; return(1); }
ki[7]= i;

i= MezoGet2i(3, 1);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-VEZNUM HIBA"; return(1); }
ki[8]= i;
i= MezoGet2i(4, 1);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-KUTNUM HIBA"; return(1); }
ki[9]= i;

i= MezoGet10i(mezo[5], 1, 5);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-AUTONUM HIBA"; return(1); }
ki[10]= i%256; ki[11]= i/256;
i= MezoGet10i(mezo[6], 1, 5);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-EMBERNUM HIBA"; return(1); }
ki[12]= i%256; ki[13]= i/256;
i= MezoGet10i(mezo[7], 1, 5);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-CSOPORT"; return(1); }
ki[14]= i%256; ki[15]= i/256;

i= MezoBcd02(mezo[8], 1);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-EMBERID"; return(1); }
ki[0x10]= i;
i= MezoBcd02(mezo[8], 3);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-EMBERID"; return(1); }
ki[0x11]= i;
i= MezoBcd02(mezo[8], 5);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-EMBERID"; return(1); }
ki[0x12]= i;
i= MezoBcd02(mezo[8], 7);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-EMBERID"; return(1); }
ki[0x13]= i;
i= MezoBcd02(mezo[8], 9);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-EMBERID"; return(1); }
ki[0x14]= i;
i= MezoBcd02(mezo[8], 11);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-EMBERID"; return(1); }
ki[0x15]= i;
i= MezoBcd02(mezo[8], 13);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-EMBERID"; return(1); }
ki[0x16]= i;

i= MezoBcd02(mezo[9], 1);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-AUTOID"; return(1); }
ki[0x17]= i;
i= MezoBcd02(mezo[9], 3);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-AUTOID"; return(1); }
ki[0x18]= i;
i= MezoBcd02(mezo[9], 5);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-AUTOID"; return(1); }
ki[0x19]= i;
i= MezoBcd02(mezo[9], 7);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-AUTOID"; return(1); }
ki[0x1a]= i;
i= MezoBcd02(mezo[9], 9);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-AUTOID"; return(1); }
ki[0x1b]= i;
i= MezoBcd02(mezo[9], 11);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-AUTOID"; return(1); }
ki[0x1c]= i;
i= MezoBcd02(mezo[9], 13);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-AUTOID"; return(1); }
ki[0x1d]= i;

i= MezoGet10i(mezo[10], 1, 10);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-KM"; return(1); }
ki[0x1e]= i%256; i/=256;
ki[0x1f]= i%256; i/=256;
ki[0x20]= i%256; ki[0x21]= i/256;

i= MezoGet10i(mezo[11], 1, 10);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-MENLEV"; return(1); }
ki[0x22]= i%256; i/=256;
ki[0x23]= i%256; i/=256;
ki[0x24]= i%256; ki[0x25]= i/256;

i= MezoGet10i(mezo[12], 1, 10);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-UZEMORA"; return(1); }
ki[0x26]= i%256; i/=256;
ki[0x27]= i%256; i/=256;
ki[0x28]= i%256; ki[0x29]= i/256;

bs= mezo[13]+"                    ";
bs.SetLength(20);
memcpy(&ki[0x2a], bs.c_str(), 20);

bs= mezo[14]+"                    ";
bs.SetLength(20);
memcpy(&ki[0x3e], bs.c_str(), 20);

i= MezoGorg(mezo[15], &ki[0x52]);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-GORG"; return(1); }

i= MezoGorg(mezo[16], &ki[0x58]);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-GORGKOMP"; return(1); }

i= MezoGet10i(mezo[17], 1, 5);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-EGYSARNTO HIBA"; return(1); }
ki[0x5e]= i%256; ki[0x5f]= i/256;
i= MezoGet10i(mezo[18], 1, 5);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-TANKCIM HIBA"; return(1); }
ki[0x60]= i%256; ki[0x61]= i/256;
i= MezoGet10i(mezo[19], 1, 5);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-SZINT HIBA"; return(1); }
ki[0x62]= i%256; ki[0x63]= i/256;
//-----------------------------------------------ENDDATE
i= MezoGet2i(20, 1);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ENDDATE HIBA"; return(1); }
if(mezo[20][3] != '/'){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ENDDATE HIBA"; return(1); }
ki[0x64]= i;
i= MezoGet2i(20, 4);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ENDDATE HIBA"; return(1); }
ki[0x65]= i;
if(mezo[20][6] != '/'){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ENDDATE HIBA"; return(1); }
i= MezoGet2i(20, 7);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ENDDATE HIBA"; return(1); }
ki[0x66]= i;
//-----------------------------------------------ENDTIME
i= MezoGet2i(21, 1);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ENDTIME HIBA"; return(1); }
if(mezo[21][3] != ':'){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ENDTIME HIBA"; return(1); }
ki[0x67]= i;
i= MezoGet2i(21, 4);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ENDTIME HIBA"; return(1); }
ki[0x68]= i;
if(mezo[21][6] != ':'){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ENDTIME HIBA"; return(1); }
i= MezoGet2i(21, 7);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ENDTIME HIBA"; return(1); }
ki[0x69]= i;
//-----------------------------------------------LITKOMP
i= MezoLiter(mezo[22], &ki[0x6a]);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-LITKOMP"; return(1); }
//-----------------------------------------------LITER
i= MezoLiter(mezo[23], &ki[0x6e]);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-LITER"; return(1); }
//-----------------------------------------------HOM
i= MezoHom(mezo[24], &ki[0x72]);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-HOM"; return(1); }
//-----------------------------------------------HIBAKOD
i= MezoGet2i(25, 1);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-HIBAKOD HIBA"; return(1); }
ki[0x74]= i;
//-----------------------------------------------NYOMTATDB
i= MezoGet2i(26, 1);	//0..99
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-NYOMTATDB HIBA"; return(1); }
ki[0x75]= i;
//-----------------------------------------------ARNETTO
i= MezoLiter(mezo[27], &ki[0x76]);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ARNETTO"; return(1); }
//-----------------------------------------------ARBTO
i= MezoLiter(mezo[28], &ki[0x7a]);
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ARBTO"; return(1); }
//-----------------------------------------------SZUM
i= MezoGet10i(mezo[29], 1, 5);//0..65535
if(i < 0){ BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-SZUM HIBA"; return(1); }
ki[0x7e]= i%256; ki[0x7f]= i/256;

if(FileWrite(f1, ki, 128) == 128) return(0);
BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+"-ÍRÁS HIBA";
return(1);
}
//---------------------------------------------------------------------------
void __fastcall 	TBenzMent::K4csvOlvas(void)
{
int			resu;
AnsiString     nev;

if(f0 > 0){ FileClose(f0); f0= -1; }
if(f1 > 0){ FileClose(f1); f1= -1; }
BenzMent->Hiba->Caption= "CSV beolvasás";

if(OpenDialogCsv->Execute()){
	f0= FileOpen(OpenDialogCsv->FileName, fmOpenRead);
	if(f0 < 1){ BenzMent->Hiba->Caption= "*** OPEN ERROR ***"; return; }
	}

nev= "Konvert.tnk";
if(FileExists(nev)) DeleteFile(nev);
f1= FileCreate(nev);
if(f1 < 1){ BenzMent->Hiba->Caption= "*** CREATE ERROR ***"; }
else	{
	if(SorRead() == 0){		//elsõ sor = fejléc
		if(	(mezo[0] != "VERZ1")||(mezo[1] != "DATE")||(mezo[2] != "TIME")||(mezo[3] != "VEZNUM")|| \
			(mezo[4] != "KUTNUM")||(mezo[5] != "AUTONUM")||(mezo[6] != "EMBERNUM")||(mezo[7] != "CSOPORT")|| \
			(mezo[8] != "EMBERID")||(mezo[9] != "AUTOID")||(mezo[10] != "KM")||(mezo[11] != "MENLEV")|| \
			(mezo[12] != "UZEMORA")||(mezo[13] != "EMBERNEV")||(mezo[14] != "AUTONEV")||(mezo[15] != "GORG")|| \
			(mezo[16] != "GORGKOMP")||(mezo[17] != "EGYSARNTO")||(mezo[18] != "TANKCIM")||(mezo[19] != "SZINT")|| \
			(mezo[20] != "ENDDATE")||(mezo[21] != "ENDTIME")||(mezo[22] != "LITKOMP")||(mezo[23] != "LITER")|| \
			(mezo[24] != "HOM")||(mezo[25] != "HIBAKOD")||(mezo[26] != "NYOMTATDB")||(mezo[27] != "ARNETTO")|| \
			(mezo[28] != "ARBTO")||(mezo[29] != "SZUM") \
			){ BenzMent->Hiba->Caption= "*** FEJLÉC HIBA ***"; }
		else	{
			do	{
				sor++;
				resu= SorRead();
				if(resu == 0){ resu= MezoWrite(); }
				}while(resu == 0);
			}
		}
	}

if(f0 > 0){ FileClose(f0); f0= -1; }
if(f1 > 0){ FileClose(f1); f1= -1; }
BenzMent->Hiba->Caption= BenzMent->Hiba->Caption+" -> VÉGE";
}
//---------------------------------------------------------------------------
void __fastcall 	TBenzMent::K4tnkBeir(void)
{
int			resu;
AnsiString     nev;

if(f0 > 0){ FileClose(f0); f0= -1; }
if(f1 > 0){ FileClose(f1); f1= -1; }
BenzMent->Hiba->Caption= "TANK BEÍRÁS";

nev= "Konvert.tnk";
f0= FileOpen(nev, fmOpenRead);
if(f0 < 1){ BenzMent->Hiba->Caption= "*** FILE OPEN ERROR ***"; return; }
else{ Error= 0; Cim= 0; Mehet= false; Beir= true; }
}
//---------------------------------------------------------------------------
void __fastcall 	TBenzMent::BuLetoltClick(TObject *Sender)
{
int			be;
AnsiString     nev;

if(RadioK4->Checked){			//K4
	nev= BenzMent->BeKezdoCim->Text;
	if		(nev == "98012") K4csvOlvas();
	else if	(nev == "98345") K4tnkBeir();
	else	{					//K4 letöltés
		if(f0 > 0){ FileClose(f0); f0= -1; }
		if(f1 > 0){ FileClose(f1); f1= -1; }
		be= BenzMent->BeKezdoCim->Text.ToIntDef(0);
		if(be > FLS_TANKMAX) return;

		if(SaveDialog1->Execute()){
			nev= SaveDialog1->FileName;
			nev.SetLength(nev.Pos(".tnk"));
			f0= FileCreate(nev+"tnk");
			f1= FileCreate(nev+"csv");
			if((f0 > 0)&&(f1 > 0)){
				bs.sprintf(	"VERZ1;DATE;TIME;VEZNUM;KUTNUM;AUTONUM;EMBERNUM;CSOPORT;" \
					"EMBERID;AUTOID;KM;MENLEV;UZEMORA;EMBERNEV;AUTONEV;" \
					"GORG;GORGKOMP;EGYSARNTO;TANKCIM;SZINT;" \
					"ENDDATE;ENDTIME;LITKOMP;LITER;HOM;HIBAKOD;NYOMTATDB;ARNETTO;ARBTO;SZUM;\r\n");
				FileWrite(f1, bs.c_str(), bs.Length());
				Error= 0; Cim= be; Mehet= true;
				}
			}
		}
	}
else	{						//K2 file konverzió
	if(f0 > 0){ FileClose(f0); f0= -1; }
	if(f1 > 0){ FileClose(f1); f1= -1; }
	if(OpenDialog1->Execute()){
		f0= FileOpen(OpenDialog1->FileName, fmOpenRead);
		if(f0 < 1){ BenzMent->Hiba->Caption= "*** OPEN ERROR ***"; return; }
		}
	if(SaveDialog2->Execute()){
		f1= FileCreate(SaveDialog2->FileName);
		if(f1 < 1){ BenzMent->Hiba->Caption= "*** CREATE ERROR ***"; FileClose(f0); f0=-1; return; }
		K2tankKonvertal();
		FileClose(f0); f0= -1;
		FileClose(f1); f1= -1;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall 	TBenzMent::BuMegszakClick(TObject *Sender)
{
ToltesLeallit();
}
//---------------------------------------------------------------------------
void __fastcall 	TBenzMent::FormClose(TObject *Sender, TCloseAction &Action)
{
ToltesLeallit(); Vezerlo->BuTankLe->Font->Color= clNavy;
}
//---------------------------------------------------------------------------
void __fastcall 	TBenzMent::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------


