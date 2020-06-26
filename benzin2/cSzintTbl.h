#ifndef cSzintTblH
#define cSzintTblH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TSzintTbl : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *Txt;
	TLabel *BuOlvas;
	TLabel *BuBeir;
	TLabel *Uzen;
	TLabel *BuVissza;
	TSaveDialog *SaveDialog1;
	TLabel *BuMentes;
	TLabel *FileNev;
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall BuOlvasClick(TObject *Sender);
	void __fastcall BuBeirClick(TObject *Sender);
	void __fastcall BuVisszaClick(TObject *Sender);
	void __fastcall BuMentesClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
	Word			dat[8][120][2];	
	AnsiString		s;
	int				Cim;
	int				Resu, Fil1, Error;

	void __fastcall 	DatTorol(void);
	void __fastcall 	TablaKiir(void);
	void __fastcall   	SzintTblOlvas(void);
	int __fastcall 		KiirFlsTolt(int mero, int blk);
	void __fastcall   	SzintTblBeir(void);

public:		// User declarations
	__fastcall 		TSzintTbl(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSzintTbl *SzintTbl;
//---------------------------------------------------------------------------
#endif
