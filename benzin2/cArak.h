#ifndef cArakH
#define cArakH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TArak : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupMeglevo;
	TLabel *ArakDb;
	TLabel *LabDb;
	TLabel *LabCsoport;
	TEdit *BeCsoport;
	TStringGrid *Txt;
	TLabel *BuOlvas;
	TLabel *Uzen;
	TLabel *BuBeir;
	TLabel *BuVissza;
	TLabel *BuMentes;
	TLabel *FileNev;
	TLabel *BuMegszak;
	TSaveDialog *SaveDialog1;
	void __fastcall BuOlvasClick(TObject *Sender);
	void __fastcall BuBeirClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall BuVisszaClick(TObject *Sender);
	void __fastcall BuMentesClick(TObject *Sender);
	void __fastcall BuMegszakClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
	int			Csop;
	Byte			be[130];
	char			ki[200];
	AnsiString	as;
	bool			Mehet;
	int			Cim,Ures;
	int			Resu,FilNum,Error;

	void __fastcall	TArak::ToltesLeallit(void);
	int __fastcall		TArak::ArBeolv(Word *filler,Byte mut);
	void __fastcall	TArak::ArakBeir(void);
	void __fastcall	TArak::ArakOlvas(void);
public:		// User declarations
	__fastcall TArak(TComponent* Owner);
	void __fastcall TArak::Timer50ms(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TArak *Arak;
//---------------------------------------------------------------------------
#endif
