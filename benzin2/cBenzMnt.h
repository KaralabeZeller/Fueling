#ifndef cBenzMntH
#define cBenzMntH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TBenzMent : public TForm
{
__published:	// IDE-managed Components
	TSaveDialog *SaveDialog1;
	TLabel *Hiba;
	TLabel *LabKezdoCim;
	TMaskEdit *BeKezdoCim;
	TButton *BuLetolt;
	TButton *BuMegszak;
	TGroupBox *GroupBox1;
	TRadioButton *RadioK4;
	TRadioButton *RadioK2;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog2;
	TLabel *CimMax;
	TOpenDialog *OpenDialogCsv;
	void __fastcall BuLetoltClick(TObject *Sender);
	void __fastcall BuMegszakClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall FormActivate(TObject *Sender);
private:		// User declarations
	bool			Mehet;
	int			Cim;
	int			Resu, f0, f1, Error;
	Byte			be[130];
	AnsiString	bs;

	AnsiString	mezo[30];
	int			sor, mezodb;

	bool			Beir;

	void __fastcall 	TBenzMent::ToltesLeallit(void);
	void __fastcall 	TBenzMent::K2tankKonvertal(void);
	void __fastcall 	TBenzMent::K4tankKonvertal(void);

	int __fastcall 	TBenzMent::MezoGet2i(int meznum, int chnum);
	int __fastcall 	TBenzMent::MezoGet10i(AnsiString mez, int chnum, int max);
	int __fastcall 	TBenzMent::MezoBcd02(AnsiString mez, int chnum);
	int __fastcall 	TBenzMent::MezoI100(AnsiString mez, int chnum);
	int __fastcall 	TBenzMent::MezoGorg(AnsiString mez, Byte *ki);
	int __fastcall 	TBenzMent::MezoLiter(AnsiString mez, Byte *ki);
	int __fastcall 	TBenzMent::MezoHom(AnsiString mez, Byte *ki);
	int __fastcall 	TBenzMent::SorRead(void);
	int __fastcall 	TBenzMent::MezoWrite(void);
	void __fastcall 	TBenzMent::K4csvOlvas(void);
	void __fastcall 	TBenzMent::K4tnkBeir(void);
public:		// User declarations
	void __fastcall TBenzMent::Timer50ms(void);
	__fastcall TBenzMent(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBenzMent *BenzMent;
//---------------------------------------------------------------------------
#endif
