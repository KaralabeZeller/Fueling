#ifndef cNyomtatoH
#define cNyomtatoH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TNyomtatoTeszt : public TForm
{
__published:	// IDE-managed Components
	TListBox *Lista;
	TLabel *BuClr;
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall BuClrClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	void __fastcall Minta50ms(void);
	__fastcall TNyomtatoTeszt(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNyomtatoTeszt *NyomtatoTeszt;
//---------------------------------------------------------------------------
#endif
