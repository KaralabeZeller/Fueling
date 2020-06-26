//---------------------------------------------------------------------------

#ifndef cAnalogH
#define cAnalogH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TAnalog : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupTapfesz;
	TLabel *KiU11;
	TLabel *LabU11;
	TLabel *LabU10;
	TLabel *KiU10;
	TEdit *BeU11;
	TButton *BuBeirU11;
	TLabel *UzenTap;
	TGroupBox *GroupMa1;
	TLabel *KiMa1;
	TLabel *UzenMa1;
	TEdit *BeSzorMa1;
	TButton *BuBeirMa1;
	TButton *BuKiolv;
	TEdit *BeNullMa1;
	TLabel *LabSzorzo1;
	TLabel *LabNulla1;
	TLabel *UzenKiolv;
	TGroupBox *GroupMa2;
	TLabel *KiMa2;
	TLabel *UzenMa2;
	TLabel *LabSzorzo2;
	TLabel *LabNulla2;
	TEdit *BeSzorMa2;
	TButton *BuBeirMa2;
	TEdit *BeNullMa2;
	TGroupBox *GroupMa3;
	TLabel *KiMa3;
	TLabel *UzenMa3;
	TLabel *LabSzorzo3;
	TLabel *LabNulla3;
	TEdit *BeSzorMa3;
	TButton *BuBeirMa3;
	TEdit *BeNullMa3;
	TGroupBox *GroupMa4;
	TLabel *KiMa4;
	TLabel *UzenMa4;
	TLabel *LabSzorzo4;
	TLabel *LabNulla4;
	TEdit *BeSzorMa4;
	TButton *BuBeirMa4;
	TEdit *BeNullMa4;
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall BuBeirU11Click(TObject *Sender);
	void __fastcall BuKiolvClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall BuBeirMa1Click(TObject *Sender);
	void __fastcall BuBeirMa2Click(TObject *Sender);
	void __fastcall BuBeirMa3Click(TObject *Sender);
	void __fastcall BuBeirMa4Click(TObject *Sender);
private:	// User declarations
	int			Beir,Kiolv;
	Byte			be[128];
	Byte			Kiepr[6];
	AnsiString	sk;
public:		// User declarations
	void __fastcall Timer50ms(void);
	__fastcall TAnalog(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAnalog *Analog;
//---------------------------------------------------------------------------
#endif
