//---------------------------------------------------------------------------
#ifndef cCardKonvH
#define cCardKonvH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TCardKonv : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	TStringGrid *CrdList;
	TLabel *BuVezIr;
	TLabel *BuOlvas;
	TLabel *NevForras;
	TGroupBox *GroupFile;
	TGroupBox *GroupSor;
	TLabel *Kijel;
	TTrackBar *TrackBar;
	TLabel *BuMegszak;
	TLabel *BuVezOlv;
	TLabel *BuSorTorol;
	TLabel *BuSorHozzaad;
	TLabel *BuSorBeszur;
	TGroupBox *GroupTabl;
	TLabel *BuEllenorzes;
	TLabel *BuTablaTorol;
	TLabel *BuIr;
	TLabel *BuUjkartya;
	TLabel *BuDump;
	TSaveDialog *SaveDialogDump;
	TLabel *BuVissza;
	void __fastcall BuOlvasClick(TObject *Sender);
	void __fastcall BuMegszakClick(TObject *Sender);
	void __fastcall BuIrClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall BuTablaTorolClick(TObject *Sender);
	void __fastcall BuVezIrClick(TObject *Sender);
	void __fastcall BuSorTorolClick(TObject *Sender);
	void __fastcall BuSorHozzaadClick(TObject *Sender);
	void __fastcall BuVezOlvClick(TObject *Sender);
	void __fastcall BuSorBeszurClick(TObject *Sender);
	void __fastcall BuEllenorzesClick(TObject *Sender);
	void __fastcall BuUjkartyaClick(TObject *Sender);
	void __fastcall BuDumpClick(TObject *Sender);
	void __fastcall BuVisszaClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
//RTip;Card Id7  ;T;Liter;Db   ;Pin ;Kut ;Sorsz ;Csop ;P;Név20               ;
//2001;1659963323;5;01000;00100;0000;FFFF;000001;00001;1;NEGA-Szerviz        ;
//2001;1659963584;3;01000;00100;0000;FFFF;000002;00001;2;NEGA-Mester         ;
//2001;0268843437;2;01000;00010;0000;FFFF;000003;00001;0;NEGA-Autó           ;
//2001;0224885974;1;01000;00100;0000;FFFF;000004;00001;9;NEGA-Sofõr          ;
	struct CARD_Stru{
		Word		RecTip;		 	//x00	0x2001 - kártya-v1
		Byte		Id[7];		 	//x02	card in result BCD(6+1byte bin ->15+2számjegy)
		Byte		Tip;				//x09	tipus
		#define CRD_SOFOR		1
		#define CRD_JARMU		2
		#define CRD_MESTER		3
		#define CRD_SZERVIZ		5
		Word		MaxLit;			//x0a	[0-65000]
		Word		MaxDb;			//x0c	[0-65000]
		Word		Pin;				//x0e	[0000-9999]
		Word		Kutak;			//x10	[00-ffff]	max.16db kútfõ engedély
		Word		Num;				//x12	[0-65000]	kártya sorszáma
		Word		Csoport;			//x14
		Byte		Print;			//x16	[0-255]
		Byte		Ev;				//x17	beírási idõ
		Byte		Ho;				//x18
		Byte		Nap;				//x19
		Byte		Ora;				//x1a
		Byte		Perc;			//x1b
		Byte		Mp;				//x1c
		Byte		Nev[20];			//x1d
								//x31
		Word		Cim;
		Byte		Hiba;
		}Card;
 #define CARD_SORLEN	(76+2)+10
 #define CARD_MEZODB	(14)+1
	int			fK1, fKlen, fKdb;
	Byte			SorMezoDb;
	AnsiString     cs,SorMezo[CARD_MEZODB];	//mezõkre bontott 1 sor

	Byte			Tar[128+2];	//read128 miatt
	enum			EnuFazis{FAZ_STOP,FAZ_OLVCSV,FAZ_OLVCRD,FAZ_OLVVEZ,FAZ_IRCSV,FAZ_IRCRD,FAZ_IRVEZ,FAZ_DUMP} Fazis;
	int			Hiba,Whiba;
	int			Sor,Ures,Db;
	bool			Freeze;
	Byte			CrdMem[80];

	void __fastcall	ListaInit(void);
	int __fastcall		SorBeolv(void);	//0=nincs több, 1=van valami
	int __fastcall		SorSzetvag(void);
	Byte __fastcall	HexToBin(Byte be);
	Byte __fastcall  	SorKonvertal(int sor);
	int __fastcall		TarToCard(void);
	void __fastcall	CardToStr(AnsiString *s);
	void __fastcall	CardToTable(void);
	void __fastcall	CardToTar(int kapcs);
	int __fastcall		Ellenorzes(void);
	void __fastcall	KonvLeallit(void);
public:		// User declarations
	void __fastcall Timer50ms(void);
	__fastcall TCardKonv(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCardKonv *CardKonv;
//---------------------------------------------------------------------------
#endif
