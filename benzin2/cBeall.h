#ifndef cBeallH
#define cBeallH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TBeallit : public TForm
{
__published:	// IDE-managed Components
	TEdit *CimBe;
	TLabel *LabCim;
	TButton *BuOk;
	TComboBox *Valaszt;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	void __fastcall BuOkClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
	void __fastcall	BeallitVege(void);
public:		// User declarations
	__fastcall TBeallit(TComponent* Owner);
	Byte	Mut;	//1,2	melyik fele
};
//---------------------------------------------------------------------------
extern PACKAGE TBeallit *Beallit;
//---------------------------------------------------------------------------
#endif
