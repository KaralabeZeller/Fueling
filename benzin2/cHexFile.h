//---------------------------------------------------------------------------
#ifndef cHexFileH
#define cHexFileH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class THexFile : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *HexKi;
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall THexFile(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THexFile *HexFile;
//---------------------------------------------------------------------------
#endif
