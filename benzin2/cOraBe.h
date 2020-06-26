#ifndef cOraBeH
#define cOraBeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TOraBe : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupKorrekcio;
	TLabel *LabComment;
	TEdit *BeKorr;
	TLabel *BuKorrBe;
	TLabel *BuVissza;
	TGroupBox *GroupIdo;
	TLabel *KiDatum;
	TLabel *LabUtolso;
	TLabel *KiBeall;
	TLabel *BuOrabe;
	TLabel *KiUzen;
	TLabel *KiUzen2;
	TLabel *KiKorr;
	TRadioButton *Elore;
	TRadioButton *Vissza;
	void __fastcall BuVisszaClick(TObject *Sender);
	void __fastcall BuOrabeClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall BuKorrBeClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
	Byte			ora[18];

	bool __fastcall TOraBe::OraBeolv(void);
public:		// User declarations
	void __fastcall Timer50ms(void);
	__fastcall TOraBe(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOraBe *OraBe;
//---------------------------------------------------------------------------
#endif
