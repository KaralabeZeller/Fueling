//---------------------------------------------------------------------------

#ifndef cBeirH
#define cBeirH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TBeir : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TComboBox *Valaszt;
	TEdit *CimBe;
	TButton *BuOk;
	TEdit *Data;
	TLabel *Label2;
	void __fastcall BuOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TBeir(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBeir *Beir;
//---------------------------------------------------------------------------
#endif
