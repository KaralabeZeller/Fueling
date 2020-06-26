#ifndef cFlsClearH
#define cFlsClearH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFlsClr : public TForm
{
__published:	// IDE-managed Components
	TLabel 		*LabVigyazz;
	TGroupBox 		*GroupKartyak;
	TControlBar 	*Kartyak;
	TLabel 		*KiKartya;
	TLabel 		*BuOlvasCrd;
	TLabel 		*BuTorolCrd;
	TGroupBox 		*GroupCegek;
	TLabel 		*KiCeg;
	TLabel 		*BuOlvasCeg;
	TLabel 		*BuTorolCeg;
	TControlBar 	*Cegek;
	TGroupBox 		*GroupTankolasok;
	TLabel 		*KiTank;
	TLabel 		*BuOlvasTank;
	TLabel 		*BuTorolTank;
	TControlBar 	*Tankok;
	TLabel 		*BuVissza;
	TLabel 		*BuStop;
	TGroupBox 		*GroupArak;
	TLabel 		*KiArak;
	TLabel 		*BuOlvasArak;
	TLabel 		*BuTorolArak;
	TControlBar 	*Arak;
	void __fastcall 	FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall 	KartyakPaint(TObject *Sender);
	void __fastcall 	BuTorolCrdClick(TObject *Sender);
	void __fastcall 	BuOlvasCrdClick(TObject *Sender);
	void __fastcall 	BuOlvasCegClick(TObject *Sender);
	void __fastcall 	BuOlvasTankClick(TObject *Sender);
	void __fastcall 	BuVisszaClick(TObject *Sender);
	void __fastcall 	BuTorolTankClick(TObject *Sender);
	void __fastcall 	BuTorolCegClick(TObject *Sender);
	void __fastcall 	BuStopClick(TObject *Sender);
	void __fastcall 	BuOlvasArakClick(TObject *Sender);
	void __fastcall 	BuTorolArakClick(TObject *Sender);
	void __fastcall 	FormKeyPress(TObject *Sender, char &Key);
	void __fastcall 	FormActivate(TObject *Sender);
private:	// User declarations
	Word			Blk;	//0-2047 blk mutató
	enum			{F_ALAP,F_OLVTANK,F_OLVCRD,F_OLVARAK,F_OLVCEG,F_CLRTANK,F_CLRCRD,F_CLRARAK,F_CLRCEG}Fazis;
	Byte			Fls[130];
 #define	TANK_MAXBLK	2048
 #define	CARD_MAXBLK	(2048-256)
 #define	ARAK_MAXBLK	256
 #define	CEG_MAXBLK	256
	Byte			BlkTank[TANK_MAXBLK];	//0=alap,1=üres,2=foglalt
	Byte			BlkCrd[CARD_MAXBLK];
	Byte			BlkArak[ARAK_MAXBLK];
	Byte			BlkCeg[CEG_MAXBLK];
	Word			Db;
	AnsiString		ks;
	int			Delay;

	void __fastcall 	KockaKi(TControlBar *bar, int x, int y, TColor color);

public:		// User declarations
	void __fastcall	TFlsClr::Timer50ms(void);
	__fastcall 		TFlsClr(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFlsClr 	*FlsClr;
//---------------------------------------------------------------------------
#endif
