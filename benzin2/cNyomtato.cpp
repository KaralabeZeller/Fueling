#include <vcl.h>
#pragma hdrstop
#include "cNyomtato.h"
#include "cModBusSoros.h"
#include "cVezerlo.h"
#include "cTxtBenzin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TNyomtatoTeszt *NyomtatoTeszt;
AnsiString	Prn="";		//printer puffer
//-----------------------------------------------
__fastcall TNyomtatoTeszt::TNyomtatoTeszt(TComponent* Owner):TForm(Owner)
{
}
//-----------------------------------------------
void __fastcall TNyomtatoTeszt::FormActivate(TObject *Sender)
{
Caption=			TxtNyomtato[0][Nyelv];
BuClr->Caption=	TxtNyomtato[1][Nyelv];
}
//-----------------------------------------------
void __fastcall TNyomtatoTeszt::Minta50ms(void)
{
int		cnt,i;
Byte		be[32],c;
AnsiString	s;

if(Vezerlo->Soros->Connected != true) return;
cnt=Vezerlo->Soros->Read(be,32);
for(i=0; i<cnt; i++){
	c=be[i];
	if(c == 0){
		Lista->Items->Add("|"+Prn+"|");
		Prn="";
		}
	else	{
		switch(c){
			case 0xa0:	c='á'; break;
			case 0x82:	c='é'; break;
			case 0xa1:	c='í'; break;
			case 0xa2:	c='ó'; break;
			case 0x7c:	c='ö'; break;
			case 0x93:	c='õ'; break;
			case 0xa3:	c='ú'; break;
			case 0x7d:	c='ü'; break;
			case 0x96:	c='û'; break;

			case 0x8e:	c='Á'; break;
			case 0x90:	c='É'; break;
//			case 0xa1:	c='Í'; break;
//			case 0xa2:	c='Ó'; break;
			case 0x5c:	c='Ö'; break;
//			case 0x93:	c='Õ'; break;
//			case 0xa3:	c='Ú'; break;
			case 0x5d:	c='Ü'; break;
//			case 0x9a:	c='Û'; break;

			case 0xf8:	c='°'; break;
			}
//		if(c == 0x0a)	;//eldob
//		else
		if(c < 0x20)	Prn+=s.sprintf("[%02x]",c);
		else 		Prn+=(char)c;
		}
	}
}
//-----------------------------------------------
void __fastcall TNyomtatoTeszt::BuClrClick(TObject *Sender)
{
Lista->Items->Clear();
Prn="";
}
//-----------------------------------------------
void __fastcall TNyomtatoTeszt::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

