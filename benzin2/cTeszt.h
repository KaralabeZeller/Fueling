#ifndef cTesztH
#define cTesztH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//#include "CPort.hpp"
//-------------------------------------
class TTeszt : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *Ki1;
	TButton *BuCim1;
	TButton *BuCim2;
	TStringGrid *Ki2;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *PacketKi;
	TLabel *Label2;
	TLabel *ErrorKi;
	TButton *BuStatClr;
	void __fastcall BuCim1Click(TObject *Sender);
	void __fastcall BuCim2Click(TObject *Sender);
	void __fastcall BuStatClrClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	char		Kapcs1,Kapcs2;
	int		RdAddr1,RdAddr2;

	void __fastcall	Timer50ms(void);
	__fastcall TTeszt(TComponent* Owner);
};
//-------------------------------------
extern PACKAGE TTeszt *Teszt;
//-------------------------------------
#endif
