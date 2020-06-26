#include <stdio.h>
#include <vcl.h>
#pragma hdrstop
#include "cUjKartyaBe.h"
#include "cCardKonv.h"
#include "cTxtBenzin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TUjKartyaBe *UjKartyaBe;
//---------------------------------------------------------------------------
__fastcall TUjKartyaBe::TUjKartyaBe(TComponent* Owner):TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TUjKartyaBe::FormActivate(TObject *Sender)
{
int			sor=CardKonv->CrdList->Row;

Caption=				TxtUjKartyaBe[0][Nyelv];

GroupKartyaID->Caption=	TxtUjKartyaBe[1][Nyelv];
Olvaso->Caption=		TxtUjKartyaBe[2][Nyelv];
Gyuru->Caption=		TxtUjKartyaBe[3][Nyelv];
Kezi->Caption=			TxtUjKartyaBe[4][Nyelv];

GroupTipus->Caption=	TxtUjKartyaBe[5][Nyelv];
Ember->Caption=		TxtUjKartyaBe[6][Nyelv];
Auto->Caption=			TxtUjKartyaBe[7][Nyelv];
Mester->Caption=		TxtUjKartyaBe[8][Nyelv];
Kezi->Caption=			TxtUjKartyaBe[9][Nyelv];

LabMaxLiter->Caption=	TxtUjKartyaBe[10][Nyelv];
LabMaxDb->Caption=		TxtUjKartyaBe[11][Nyelv];
LabPIN->Caption=		TxtUjKartyaBe[12][Nyelv];
LabKutak->Caption=		TxtUjKartyaBe[13][Nyelv];
LabCsoport->Caption=	TxtUjKartyaBe[14][Nyelv];
LabPrint->Caption=		TxtUjKartyaBe[15][Nyelv];
LabNev->Caption=		TxtUjKartyaBe[16][Nyelv];

BuMegse->Caption=		TxtUjKartyaBe[17][Nyelv];
BuUjkartya->Caption=	TxtUjKartyaBe[18][Nyelv];

if(CardKonv->CrdList->Cells[1][sor] != ""){
	if(Kezi->Checked) Id->Text=CardKonv->CrdList->Cells[1][sor];//CrdID[7]

	if		(CardKonv->CrdList->Cells[2][sor] == '1') Ember->Checked=true;//Tipus
	else if	(CardKonv->CrdList->Cells[2][sor] == '3') Mester->Checked=true;
	else if	(CardKonv->CrdList->Cells[2][sor] == '5') Szerviz->Checked=true;
	else 	Auto->Checked=true;

	MaxLit->Text=	CardKonv->CrdList->Cells[3][sor];
	MaxDb->Text=	CardKonv->CrdList->Cells[4][sor];
	Pin->Text=	CardKonv->CrdList->Cells[5][sor];
	Kutak->Text=	CardKonv->CrdList->Cells[6][sor];

	Csoport->Text=	CardKonv->CrdList->Cells[8][sor];
	Print->Text=	CardKonv->CrdList->Cells[9][sor];
	Nev->Text=	CardKonv->CrdList->Cells[10][sor];
	}
}
//---------------------------------------------------------------------------
void __fastcall TUjKartyaBe::BuUjkartyaClick(TObject *Sender)
{
//11;dátum    idõ  ;card kód  ;T;Lit  ;Db   ;12;szöveg       ;Pin ;13;sorsz;Ku;Cso;Prn
//11;22/02/03 08:31;2432479453;5;01000;00100;12;NEGA-Szerviz ;0000;13;01907;ff;255;0
//11;22/02/03 08:31;2432439133;3;01000;00100;12;NEGA-Mester  ;0000;13;01908;ff;255;0
//11;22/02/03 08:31;2432166301;2;01000;00010;12;NEGA-Autó    ;0000;13;01909;1f;002;0
//11;22/02/03 08:31;2432432733;1;01000;00100;12;NEGA-Sofõr   ;0000;13;01910;1f;001;0
char			tipus;
Word			lit,db,pin,kutak,csoport,prn;
Byte			ki[84];
AnsiString	s;
int			sor=CardKonv->CrdList->Row;

CardKonv->CrdList->Cells[0][sor]="2001/[____]";

CardKonv->CrdList->Cells[1][sor]=Id->Text;//CrdID[7]

if		(Ember->Checked)	tipus='1';//Tipus
else if	(Mester->Checked)	tipus='3';
else if	(Szerviz->Checked)	tipus='5';
else 					tipus='2';
CardKonv->CrdList->Cells[2][sor]=tipus;

lit=MaxLit->Text.ToIntDef(0);			//MaxLit.W
if(lit > 59999) lit= 59999;
CardKonv->CrdList->Cells[3][sor]=lit;

db=MaxDb->Text.ToIntDef(0);			//MaxDb.W
if(db > 9999) db=9999;
CardKonv->CrdList->Cells[4][sor]=db;

pin=Pin->Text.ToIntDef(0);			//PIN.W
if(pin > 9999) pin=9999;
CardKonv->CrdList->Cells[5][sor]=s.sprintf("%04i",pin);

s="0x"+Kutak->Text; kutak=s.ToIntDef(0);//Kutfõk.w
if(kutak >= 0xffff) kutak=0xffff;
CardKonv->CrdList->Cells[6][sor]=s.sprintf("%04X",kutak);

CardKonv->CrdList->Cells[7][sor]="0";

csoport=Csoport->Text.ToIntDef(0);		//Csoport.w
if(csoport > 4095) csoport=4095;
CardKonv->CrdList->Cells[8][sor]=csoport;

prn=Print->Text.ToIntDef(0);			//Prn.b
if(prn > 9) prn=9;
CardKonv->CrdList->Cells[9][sor]=prn;

s=Nev->Text+"                    ";	//Név[20]
CardKonv->CrdList->Cells[10][sor]=s;

Close();
}
//---------------------------------------------------------------------------
void __fastcall TUjKartyaBe::BuMegseClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TUjKartyaBe::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

