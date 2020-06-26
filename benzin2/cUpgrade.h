//---------------------------------------------------------------------------
#ifndef cUpgradeH
#define cUpgradeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TUpgrade : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialogIr;
	TOpenDialog *OpenDialog;
	TGroupBox *GroupProgram;
	TLabel *BuHexOlvas;
	TLabel *NevHexForras;
	TLabel *KiHexResu;
	TLabel *KiHexHiba;
	TTrackBar *TrackFlsClr;
	TLabel *BuUpgradeClr;
	TLabel *KiFlsClrResu;
	TLabel *BuUpgradeIr;
	TLabel *KiFlsIrResu;
	TLabel *BuUpgradeOlv;
	TLabel *KiFlsOlvResu;
	TTrackBar *TrackFlsIr;
	TTrackBar *TrackFlsOlv;
	TLabel *KiLetoltesResu;
	TGroupBox *GroupMemoria;
	TLabel *BuDump;
	TLabel *NevDump;
	TLabel *KiDumpResu;
	TLabel *BuMemory;
	TRadioButton *RadioHex;
	TRadioButton *RadioOlv;
	TLabel *BuHexFile;
	TRadioButton *RadioAuto;
	TRadioButton *RadioLepesenkent;
	TLabel *KiFlsClrCim;
	TLabel *KiFlsIrCim;
	TLabel *KiFlsOlvCim;
	TGroupBox *GroupVerzio;
	TLabel *BuVerzCsere;
	TLabel *BuVerziOlv;
	TLabel *BuProgramOlv;
	TTrackBar *TrackPrgRead;
	TLabel *KiPrgReadResu;
	TLabel *KiPrgReadCim;
	TPanel *Kut1;
	TPanel *Kut2;
	TPanel *Kut3;
	TPanel *Kut4;
	TPanel *Kut5;
	TPanel *Kut6;
	TPanel *Kut7;
	TPanel *Kut8;
	TPanel *Kut9;
	TPanel *Kut10;
	TPanel *Kut11;
	TPanel *Kut12;
	TPanel *Kut13;
	TPanel *Kut14;
	TLabel *KiVerzio;
	TLabel *LabAllapot;
	TLabel *BuToltoCsere;
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall BuDumpClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BuMemoryClick(TObject *Sender);
	void __fastcall BuHexFileClick(TObject *Sender);
	void __fastcall BuVerzCsereClick(TObject *Sender);
	void __fastcall BuHexOlvasClick(TObject *Sender);
	void __fastcall BuUpgradeClrClick(TObject *Sender);
	void __fastcall BuUpgradeIrClick(TObject *Sender);
	void __fastcall BuUpgradeOlvClick(TObject *Sender);
	void __fastcall RadioOlvClick(TObject *Sender);
	void __fastcall RadioHexClick(TObject *Sender);
	void __fastcall BuVerziOlvClick(TObject *Sender);
	void __fastcall BuProgramOlvClick(TObject *Sender);
	void __fastcall RadioAutoClick(TObject *Sender);
	void __fastcall RadioLepesenkentClick(TObject *Sender);
	void __fastcall BuToltoCsereClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
#define		HEXFILE_LEN	400000
	Byte		Hex[HEXFILE_LEN];
//0x000200-0x015800=88064w
//0xf80000-0xf80017=device config reg
#define		MEM_W_DB		44032	//2752*16
	DWord	DwHex[MEM_W_DB];
	DWord	DwOlv[MEM_W_DB];
	int		HexHiba,FlsOlvHiba,FlsIrHiba,FlsClrHiba,PrgReadHiba;
	Word		cimH;
	DWord	xcim;		//olvasás-írás cím
     Byte		Wait;		//törlés 400ms wait

#define	UPGR_OFF		0
#define	UPGR_FLSCLR	1
#define	UPGR_FLSWR	2
#define	UPGR_FLSRD	3
#define	UPGR_PRGRD	4
	int		UpgrTimFaz;
     int		Var50ms;

	void __fastcall TUpgrade::ListKiir(void);
	Byte __fastcall TUpgrade::HexToByte(char be);
	void __fastcall TUpgrade::Memoba(AnsiString be);
 //	void __fastcall TUpgrade::Iras1Row(Word pag,Word cim);

	int __fastcall TUpgrade::StartHexOlvas(void);
	void __fastcall TUpgrade::StartUpgradeClr(void);
	void __fastcall TUpgrade::StartUpgradeIr(void);
	void __fastcall TUpgrade::StartUpgradeOlv(void);
	Word __fastcall TUpgrade::VerzioOlv_L(Word pag,Word cim);
	void __fastcall TUpgrade::VerzioOlv(void);
public:		// User declarations
	__fastcall TUpgrade(TComponent* Owner);
	void __fastcall TUpgrade::Timer50ms(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TUpgrade *Upgrade;
//---------------------------------------------------------------------------
#endif
