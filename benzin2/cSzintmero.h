//---------------------------------------------------------------------------

#ifndef cSzintmeroH
#define cSzintmeroH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TSzintmero : public TForm
{
__published:	// IDE-managed Components
	TLabel *BuKilep;
	TTimer *SzintmeroTime;
	TRadioGroup *GroupMintavetel;
	TRadioButton *BuStart;
	TRadioButton *BuStop;
	TListBox *Lista;
	TLabel *LabCsomagok;
	TLabel *BuClr;
	void __fastcall BuKilepClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall SzintmeroTimeTimer(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall BuStartClick(TObject *Sender);
	void __fastcall BuStopClick(TObject *Sender);
	void __fastcall BuClrClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSzintmero(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSzintmero *Szintmero;
//---------------------------------------------------------------------------
#endif
