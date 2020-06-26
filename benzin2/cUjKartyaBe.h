//---------------------------------------------------------------------------

#ifndef cUjKartyaBeH
#define cUjKartyaBeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TUjKartyaBe : public TForm
{
__published:	// IDE-managed Components
	TEdit *MaxLit;
	TEdit *MaxDb;
	TGroupBox *GroupTipus;
	TLabel *LabMaxLiter;
	TLabel *LabMaxDb;
	TRadioButton *Ember;
	TRadioButton *Auto;
	TRadioButton *Mester;
	TRadioButton *Szerviz;
	TLabel *LabPIN;
	TEdit *Pin;
	TLabel *LabKutak;
	TEdit *Kutak;
	TLabel *LabCsoport;
	TEdit *Csoport;
	TLabel *LabPrint;
	TEdit *Print;
	TLabel *LabNev;
	TEdit *Nev;
	TLabel *BuUjkartya;
	TLabel *BuMegse;
	TGroupBox *GroupKartyaID;
	TEdit *Id;
	TRadioButton *Olvaso;
	TRadioButton *Gyuru;
	TRadioButton *Kezi;
	void __fastcall BuUjkartyaClick(TObject *Sender);
	void __fastcall BuMegseClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TUjKartyaBe(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TUjKartyaBe *UjKartyaBe;
//---------------------------------------------------------------------------
#endif
