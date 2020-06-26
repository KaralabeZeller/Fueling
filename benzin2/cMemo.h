//---------------------------------------------------------------------------
#ifndef cMemoH
#define cMemoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TPrgMem : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *MemKi;
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPrgMem(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrgMem *PrgMem;
//---------------------------------------------------------------------------
#endif
