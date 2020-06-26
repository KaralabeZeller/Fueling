//---------------------------------------------------------------------------

#ifndef cTankMntH
#define cTankMntH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TBenzMent : public TForm
{
__published:	// IDE-managed Components
	TSaveDialog *SaveDialog1;
	TTimer *Time;
	TLabel *BuMegszak;
	TLabel *BuLetolt;
	TLabel *Hiba;
	void __fastcall TimeTimer(TObject *Sender);
	void __fastcall BuLetoltClick(TObject *Sender);
	void __fastcall BuMegszakClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TBenzMent(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBenzMent *BenzMent;
//---------------------------------------------------------------------------
#endif
