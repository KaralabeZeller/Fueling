//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "cHexFile.h"
#include "cTxtBenzin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THexFile *HexFile;
//---------------------------------------------------------------------------
__fastcall THexFile::THexFile(TComponent* Owner):TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THexFile::FormActivate(TObject *Sender)
{
Caption=				TxtHexFile[0][Nyelv];

HexKi->Cells[0][0]=		TxtHexFile[1][Nyelv];//"Hex file";
HexKi->Cells[1][0]=		TxtHexFile[2][Nyelv];//"byte";
HexKi->Cells[2][0]=		TxtHexFile[3][Nyelv];//"cím";
HexKi->Cells[3][0]=		TxtHexFile[4][Nyelv];//"típus";
HexKi->Cells[4][0]=		TxtHexFile[5][Nyelv];//"word1";
HexKi->Cells[5][0]=		TxtHexFile[6][Nyelv];//"word2";
HexKi->Cells[6][0]=		TxtHexFile[7][Nyelv];//"word3";
HexKi->Cells[7][0]=		TxtHexFile[8][Nyelv];//"word4";
HexKi->Cells[8][0]=		TxtHexFile[9][Nyelv];//"word5";
HexKi->Cells[9][0]=		TxtHexFile[10][Nyelv];//"word6";
HexKi->Cells[10][0]=	TxtHexFile[11][Nyelv];//"word7";
HexKi->Cells[11][0]=	TxtHexFile[12][Nyelv];//"word8";
}
//---------------------------------------------------------------------------
void __fastcall THexFile::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

