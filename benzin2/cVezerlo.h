#ifndef cVezerloH
#define cVezerloH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "CPort.hpp"
#include <Graphics.hpp>
//-------------------------------------
class TVezerlo : public TForm
{
__published:	// IDE-managed Components
	TComPort *Soros;
	TGroupBox *GroupKapcsolat;
	TComboBox *ComboPort;
	TEdit *IpCim1;
	TLabel *LabIPcim;
	TLabel *LabIPport;
	TEdit *UdpPort;
	TEdit *IpCim2;
	TEdit *IpCim3;
	TEdit *IpCim4;
	TGroupBox *GroupNET3soros;
	TRadioButton *Soros0;
	TRadioButton *Soros1;
	TRadioButton *Soros2;
	TLabel *LabKutnum;
	TEdit *BeKutNum;
	TTimer *Tim;
	TGroupBox *GroupAdatkezeles;
	TLabel *BuTankLe;
	TLabel *BuKartyak;
	TGroupBox *GroupBeallitas;
	TLabel *BuCegnev;
	TLabel *BuModInit;
	TLabel *BuOraBe;
	TGroupBox *GroupTesztek;
	TLabel *BuNyomtato;
	TLabel *BuSzint;
	TLabel *BuAnalog;
	TLabel *BuTeszt;
	TLabel *BuKutfoTeszt;
	TLabel *BuTankTeszt;
	TLabel *BuTorol;
	TLabel *BuArak;
	TLabel *BuGyurus;
	TLabel *BuUpgrade;
	TImage *NyelvAngol;
	TImage *NyelvMagyar;
	TLabel *BuSzintTbl;
	void __fastcall BuTankLeClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BuTesztClick(TObject *Sender);
	void __fastcall BuKartyakClick(TObject *Sender);
	void __fastcall BuModInitClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall BuOraBeClick(TObject *Sender);
	void __fastcall BuSzintClick(TObject *Sender);
	void __fastcall BuAnalogClick(TObject *Sender);
	void __fastcall ComboPortChange(TObject *Sender);
	void __fastcall Soros0Click(TObject *Sender);
	void __fastcall Soros1Click(TObject *Sender);
	void __fastcall Soros2Click(TObject *Sender);
	void __fastcall BeKutNumChange(TObject *Sender);
	void __fastcall BuCegnevClick(TObject *Sender);
	void __fastcall BuNyomtatoClick(TObject *Sender);
	void __fastcall TimTimer(TObject *Sender);
	void __fastcall BuKutfoTesztClick(TObject *Sender);
	void __fastcall BuTankTesztClick(TObject *Sender);
	void __fastcall BuTorolClick(TObject *Sender);
	void __fastcall BuArakClick(TObject *Sender);
	void __fastcall BuGyurusClick(TObject *Sender);
	void __fastcall BuUpgradeClick(TObject *Sender);
	void __fastcall NyelvAngolClick(TObject *Sender);
	void __fastcall NyelvMagyarClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall BuSzintTblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TVezerlo(TComponent* Owner);
};
//-------------------------------------
extern PACKAGE TVezerlo *Vezerlo;
extern char		mu[255];
extern AnsiString	s;
//-----------------------------------------------1.flash[8Mb=2048(128*32=4kb)sector]->65536db
//#define	FLS_TANKMIN		0x0000			//Tankol�si adatok (64000db)
#define		FLS_TANKMAX		0x7cff
#define		FLS_UPGRMIN		0x7d00			//upgrade verzi� 0x030000=192kbyte
#define		FLS_UPGRMAX		0x7fff
//-----------------------------------------------2.flash[8Mb=2048(256*16=4kb)sector]->32768db
#define		FLS_CARDMIN		0x8000			//K�rtya adatok [128b](65536/8*6=49152db) - 32db/blk
#define		FLS_CARDMAX		0xdfff
#define		FLS_ARAKMIN		0xe000			//�r adatok [32b](8192*8=65536db) - 128db/blk
#define		FLS_ARAKMAX		0xefff
#define		FLS_CEGMIN		0xf000			//F�l-C�g adatok [128b](8192db f�l) - 32db/blk
#define		FLS_CEGMAX		0xffef
#define		FLS_SZINTMIN	0xfff0
#define		FLS_SZINTMAX	0xffff
//-----------------------------------------------
#define	VERZIO	"v50"	//20190117 - K4 tank.csv beolvas
//		VERZIO	"v49"	//20190115 - K4 beolvas -> csv is
//		VERZIO	"v48"	//20181011 - K2.tnk beolvas -> csv
//		VERZIO	"v47"	//20180219 - MaxStop start
//		VERZIO	"v46"	//20180219 - Card maxlit=59999
//		VERZIO	"v45"	//20180107 - Ana3,4 be�ll�t�s
//   	VERZIO	"v44"	//20171129 - Ana3,4 kijelz�s jav�t�s
//		VERZIO	"v43"	//20170928 - Crosspoint cim start
//		VERZIO	"v42"	//20170823 - 4db 4..20mA
//		VERZIO	"v41"	//20170530 - tankol�s fel kezd� c�m
//		VERZIO	"v40"	//20170512 - +WIEGAND k�rtyaolvas�2
//		VERZIO	"v39"	//20170326 - 2 k�rtyaolvas�
//		VERZIO	"v38"	//20160904 - COM1-8, SzintTbl start
//		VERZIO	"v37"	//20150209 - angol jav�t�s
//		VERZIO	"v36"	//20150125 - t�bb nyelv
//		VERZIO	"v35"	//20141210 - upgrade
//		VERZIO	"v34"	//20141025 - upgrade, nyelv kapcsol�
//		VERZIO	"v33"	//20140828 - Virtu�lis k�tf� start
//		VERZIO	"v32"	//20140410 - *.cdr-be d�tum is
//		VERZIO	"v31"	//20140106 - olvas� 7 - DEC10 [#+10] start
//		VERZIO	"v30"	//20131214 - 2szeres km bek�r�s
//		VERZIO	"v29"	//20131212 - 1k�tf� autostart
//		VERZIO	"v28"	//20131008 - CardID 10->14 sz�mjegy
//		VERZIO	"v27"	//20130928 - CrossPoint olvas� start
//		VERZIO	"v26"	//20130924 - Ember k�d start, �rakalib jav�t�s
//		VERZIO	"v25"	//20130923 - �ra kalib start
//		VERZIO	"v24"	//20130920 - Mifare olvas� start
//		VERZIO	"v23"	//20130918 - Gy�r�s pisztoly time ki�r
//		VERZIO	"v22"	//20130618 - Gy�r�s pisztoly start
//		VERZIO	"v21"	//20121017 - �ra kalib start
//		VERZIO	"v20"	//20121003 - EE.CardReaderTipe,EE.MnuTimeout,EE.MnuUtoTime start
//		VERZIO	"v19"	//20120926 - TankTst-ben k�rtya ID jav�t�s
//		VERZIO	"v18"	//20120806 - UmA1,2 start
//		VERZIO	"v17"	//20120626 - U11,U10 start
//		VERZIO	"v16"	//20120528 - Kutf� teszt Timeout b�v�t
//		VERZIO	"v15"	//20120524 - Szintm�r�1,2 sz�tv�laszt, TankTst c�m jav�t
//		VERZIO	"v14"	//20120520 - Kut 1-15 -> 1-14
//		VERZIO	"v13"	//20120416 - Szintm�r� start
//		VERZIO	"v12"	//20120411 - PIN k�d DEC->HEX
//				"v11"	//20120329 - N�v �s �r felt�lt
//		VERZIO	"v1.0"	//20120313 - Tank felt�lt 60mp v�r
//		VERZIO	"v0.9"	//20120130 - Arak search jav�t
//		VERZIO	"v0.8"	//20120124 - T�rl�s k�rd�sek, c�g t�rl�s gomb �trak, k�rtya dump start
//		VERZIO	"v0.7"	//20120123 - K�rtya ellen�r liter0,db0 lehet, �r�s el�tt ellen�rz�s ki�r, nostop
//		VERZIO	"v0.6"	//20120104 - �rak be�ll�t�s k�perny�, tank kijelz�sen �rak
//		VERZIO	"v0.5"	//20120102 - Term�k be�ll�t�s (Benzin/Olaj)
//		VERZIO	"v0.4"	//20111126 - �j k�rtya id/c�m csere,
//						//		uts� sor nincs v�ge beolvas�s�n�l
//						//		"szoveg" lev�g�s xls beolvn�l
//		VERZIO	"v0.3"	//20111125 - FlashClr start
//		VERZIO	"v0.2"	//20111124 - BenzinTolt,c�gekbe
//		VERZIO	"v0.1"	//20111121 - Alap
//-------------------------------------
#endif
