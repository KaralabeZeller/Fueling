//---------------------------------------------------------------------------
#ifndef cTankTstH
#define cTankTstH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTankTst : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupKutfo;
	TComboBox *Kutfo;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *PacketKi;
	TLabel *Label2;
	TLabel *ErrorKi;
	TButton *BuStatClr;
	TGroupBox *GroupKezdes;
	TLabel *LabVerzio;
	TLabel *Ki1Verz;
	TLabel *LabIdo1;
	TLabel *Ki1Ido;
	TLabel *LabVezNum;
	TLabel *Ki1VezNum;
	TLabel *LabKutNum;
	TLabel *Ki1Kutnum;
	TLabel *LabEmberNum;
	TLabel *Ki1EmberNum;
	TLabel *LabAutoNum;
	TLabel *Ki1AutoNum;
	TLabel *LabCsoport;
	TLabel *Ki1Csoport;
	TLabel *LabEmberId;
	TLabel *Ki1EmberId;
	TLabel *LabAutoId;
	TLabel *Ki1AutoId;
	TLabel *LabKm;
	TLabel *Ki1Km;
	TLabel *LabMenlev;
	TLabel *Ki1Menlev;
	TLabel *LabUzemora;
	TLabel *Ki1Uzemora;
	TLabel *LabEmber;
	TLabel *Ki1EmberNev;
	TLabel *LabAuto;
	TLabel *Ki1AutoNev;
	TLabel *LabSzint;
	TGroupBox *GroupZaras;
	TLabel *LabIdo2;
	TLabel *Ki2Ido;
	TLabel *LabKitKomp;
	TLabel *Ki2LitKomp;
	TLabel *LabLiter;
	TLabel *Ki2Liter;
	TLabel *LabHomers;
	TLabel *Ki2Homer;
	TLabel *LabSum;
	TLabel *Ki2Sum;
	TLabel *LabVegeKod;
	TLabel *Ki2Hibakod;
	TLabel *LabGorgKomp;
	TLabel *Ki1GorgKomp;
	TLabel *LabGorgetett;
	TLabel *Ki1Gorgetett;
	TLabel *LabNyomtat;
	TLabel *Ki2Nyomtat;
	TLabel *LabNetto;
	TLabel *Ki2Arnto;
	TLabel *LabBrutto;
	TLabel *Ki2Arbto;
	TLabel *LabEgysAr;
	TLabel *Ki2EgysAr;
	TLabel *LabSorsz;
	TLabel *Ki2Cim;
	TLabel *KiSzint;
	void __fastcall BuStatClrClick(TObject *Sender);
	void __fastcall KutfoChange(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
	Byte		Kut;	//0-14
	Byte		be[128+1];
public:		// User declarations
	void __fastcall	Timer50ms(void);
	__fastcall TTankTst(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTankTst *TankTst;
//---------------------------------------------------------------------------
#endif
