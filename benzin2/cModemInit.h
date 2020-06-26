//---------------------------------------------------------------------------

#ifndef cModemInitH
#define cModemInitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TModemInit : public TForm
{
__published:	// IDE-managed Components
	TEdit *Init1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *BuBeir;
	TLabel *BuKilep;
	TLabel *Label4;
	TEdit *Init2;
	TLabel *BuOlvas;
	TLabel *Uzen;
	void __fastcall BuBeirClick(TObject *Sender);
	void __fastcall BuKilepClick(TObject *Sender);
	void __fastcall BuOlvasClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TModemInit(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TModemInit *ModemInit;
//---------------------------------------------------------------------------
#endif
