//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "cUpgrade.h"
#include "cMemo.h"
#include "cTxtBenzin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPrgMem *PrgMem;
//---------------------------------------------------------------------------
_fastcall TPrgMem::TPrgMem(TComponent* Owner):TForm(Owner)
{
int			i;
AnsiString	s;

MemKi->Cells[0][0]=TxtMemo[1][Nyelv];//"Cím";
for(i=0; i<16; i++)				MemKi->Cells[i+1][0]=s.sprintf("%02x",i*2);
for(i=0; i<(MEM_W_DB/16); i++)	MemKi->Cells[0][i+1]=s.sprintf("%06x",i*32);
}
//---------------------------------------------------------------------------
void __fastcall TPrgMem::FormActivate(TObject *Sender)
{
Caption=		TxtMemo[0][Nyelv];
}
//---------------------------------------------------------------------------
void __fastcall TPrgMem::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

