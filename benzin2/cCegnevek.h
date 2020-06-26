#ifndef cCegnevekH
#define cCegnevekH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TCegnevek : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *Txt;
	TLabel *BuOlvas;
	TLabel *BuBeir;
	TLabel *Uzen;
	TEdit *BeCsoport;
	TLabel *LabCsoport;
	TGroupBox *GroupMeglevo;
	TLabel *CegDb;
	TLabel *LabCegDb;
	TLabel *LabCardDb;
	TLabel *CardDb;
	TLabel *LabTankDb;
	TLabel *TankDb;
	TLabel *BuVissza;
	TSaveDialog *SaveDialog1;
	TLabel *BuMentes;
	TLabel *FileNev;
	TLabel *BuMegszak;
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall BuOlvasClick(TObject *Sender);
	void __fastcall BuBeirClick(TObject *Sender);
	void __fastcall BuVisszaClick(TObject *Sender);
	void __fastcall BuMentesClick(TObject *Sender);
	void __fastcall BuMegszakClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
	int			Csop;
	Byte			be[130];
	char			ki[200];
	AnsiString	ns;
	bool			Mehet;
	int			Cim;
	int			Resu,Fil1,Error;

	void __fastcall    	TCegnevek::NevOlvas(void);
	void __fastcall	TCegnevek::NevKitolt(Byte* str);
	void __fastcall    	TCegnevek::NevBeir(void);
	void __fastcall	TCegnevek::ToltesLeallit(void);
public:		// User declarations
	__fastcall TCegnevek(TComponent* Owner);
	void __fastcall	TCegnevek::Timer50ms(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TCegnevek *Cegnevek;
//---------------------------------------------------------------------------
#endif
