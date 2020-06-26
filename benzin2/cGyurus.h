//---------------------------------------------------------------------------

#ifndef cGyurusH
#define cGyurusH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TGyurus : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupKapcsolat;
	TLabel *LabVan;
	TLabel *KiVan;
	TLabel *LabKod;
	TLabel *KiKodHex;
	TLabel *KiKodDec;
	TLabel *LabIdo;
	TLabel *KiTime;
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
	Byte		be[128];
public:		// User declarations
	__fastcall TGyurus(TComponent* Owner);
	void __fastcall TGyurus::Timer50ms(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TGyurus *Gyurus;
//---------------------------------------------------------------------------
#endif
