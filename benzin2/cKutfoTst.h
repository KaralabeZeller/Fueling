//---------------------------------------------------------------------------
#ifndef cKutfoTstH
#define cKutfoTstH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TKutfoTst : public TForm
{
__published:	// IDE-managed Components
	TComboBox *Kutfo;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *PacketKi;
	TLabel *Label2;
	TLabel *ErrorKi;
	TButton *BuStatClr;
	TGroupBox *GroupKutfo;
	TLabel *LabHiba;
	TLabel *KiHiba;
	TLabel *LabParancs;
	TLabel *KiParancs;
	TLabel *LabKimit;
	TLabel *KiLimit;
	TLabel *LabStatusz;
	TLabel *KiStat;
	TLabel *LabFej;
	TLabel *KiFej;
	TLabel *LabLiterKomp;
	TLabel *KiLiterKomp;
	TLabel *LabLiter;
	TLabel *KiLiter;
	TLabel *LabKezi;
	TLabel *KiKezi;
	TLabel *LabSum1;
	TLabel *KiSum1;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *LabSum2;
	TLabel *KiSum2;
	TLabel *LabLopCl;
	TLabel *KiLopCl;
	TLabel *LabRele;
	TLabel *KiRele;
	TLabel *LabVez;
	TLabel *KiVez;
	TLabel *LabKomp;
	TLabel *KiKomp;
	TLabel *LabGorgetettKomp;
	TLabel *KiGorgKomp;
	TLabel *LabGorgetett;
	TLabel *KiGorg;
	TLabel *LabHomerseklet;
	TLabel *KiHom;
	TLabel *LabLiterOld;
	TLabel *KiLiterOld;
	TLabel *LabTimeOut;
	TLabel *KiTimeOut;
	TLabel *LabUtovilagitas;
	TLabel *KiUtoVil;
	TLabel *LabGyurus;
	TLabel *KiPisztoly;
	void __fastcall KutfoChange(TObject *Sender);
	void __fastcall BuStatClrClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
	Byte		Kut;	//0-14
	Byte		be[42];
public:		// User declarations
	void __fastcall	Timer50ms(void);
	__fastcall TKutfoTst(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKutfoTst *KutfoTst;
//---------------------------------------------------------------------------
#endif
