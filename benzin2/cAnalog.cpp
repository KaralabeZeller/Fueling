#include <vcl.h>
#pragma hdrstop
#include "cModbusSoros.h"
#include "cAnalog.h"
#include "cTxtBenzin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TAnalog *Analog;
//-------------------------------------
__fastcall 		TAnalog::TAnalog(TComponent* Owner) : TForm(Owner)
{
Beir= 0; Kiolv= 0;
}
//---------------------------------------------------------------------------
void __fastcall 	TAnalog::FormActivate(TObject *Sender)
{
Caption=				TxtAnalog[0][Nyelv];
BuKiolv->Caption=		TxtAnalog[1][Nyelv];

GroupTapfesz->Caption=	TxtAnalog[2][Nyelv];
BuBeirU11->Caption=		TxtAnalog[3][Nyelv];

GroupMa1->Caption=		TxtAnalog[4][Nyelv];
LabSzorzo1->Caption=	TxtAnalog[5][Nyelv];
LabNulla1->Caption=		TxtAnalog[6][Nyelv];
BuBeirMa1->Caption=		TxtAnalog[7][Nyelv];

GroupMa2->Caption=		TxtAnalog[8][Nyelv];
LabSzorzo2->Caption=	TxtAnalog[5][Nyelv];
LabNulla2->Caption=		TxtAnalog[6][Nyelv];
BuBeirMa2->Caption=		TxtAnalog[9][Nyelv];

GroupMa3->Caption=		TxtAnalog[14][Nyelv];
LabSzorzo3->Caption=	TxtAnalog[5][Nyelv];
LabNulla3->Caption=		TxtAnalog[6][Nyelv];
BuBeirMa3->Caption=		TxtAnalog[15][Nyelv];

GroupMa4->Caption=		TxtAnalog[16][Nyelv];
LabSzorzo4->Caption=	TxtAnalog[5][Nyelv];
LabNulla4->Caption=		TxtAnalog[6][Nyelv];
BuBeirMa4->Caption=		TxtAnalog[17][Nyelv];

Kiolv= 1;
}
//-------------------------------------
void __fastcall 	TAnalog::Timer50ms(void) //50ms
{
AnsiString	s;
int			res= -1;

if		(Beir){
	if(Beir == 1){
		res= MemWrite(Kiepr, RW_EEPROM, 0x01);
		if(res == 0)	UzenTap->Caption= sk.sprintf("%s: %i ", TxtAnalog[10][Nyelv],res);//OK
		else			UzenTap->Caption= sk.sprintf("%s: %i ", TxtAnalog[11][Nyelv],res);//HIBA
		}
	else if(Beir == 2){
		res= MemWrite(Kiepr, RW_EEPROM, 0x04);
		if(res == 0)	UzenMa1->Caption= sk.sprintf("%s: %i ", TxtAnalog[10][Nyelv],res);//OK
		else			UzenMa1->Caption= sk.sprintf("%s: %i ", TxtAnalog[11][Nyelv],res);//HIBA
		}
	else if(Beir == 3){
		res= MemWrite(Kiepr, RW_EEPROM, 0x05);
		if(res == 0)	UzenMa2->Caption= sk.sprintf("%s: %i ", TxtAnalog[10][Nyelv],res);//OK
		else			UzenMa2->Caption= sk.sprintf("%s: %i ", TxtAnalog[11][Nyelv],res);//HIBA
		}
	else if(Beir == 4){
		res= MemWrite(Kiepr, RW_EEPROM, 0x06);
		if(res == 0)	UzenMa3->Caption= sk.sprintf("%s: %i ", TxtAnalog[10][Nyelv],res);//OK
		else			UzenMa3->Caption= sk.sprintf("%s: %i ", TxtAnalog[11][Nyelv],res);//HIBA
		}
	else if(Beir == 5){
		res= MemWrite(Kiepr, RW_EEPROM, 0x07);
		if(res == 0)	UzenMa4->Caption= sk.sprintf("%s: %i ", TxtAnalog[10][Nyelv],res);//OK
		else			UzenMa4->Caption= sk.sprintf("%s: %i ", TxtAnalog[11][Nyelv],res);//HIBA
		}
	Beir= 0;
	}
else if	(Kiolv){
	res= MemRead(be, RW_EEPROM, 128);
	if(res == 0){
		BeU11->Text= 		be[0x6a];
		BeSzorMa1->Text= 	(int)be[0x6c]+(int)be[0x6d]*256;
		BeNullMa1->Text= 	(int)be[0x6e]+(int)be[0x6f]*256;
		BeSzorMa2->Text= 	(int)be[0x70]+(int)be[0x71]*256;
		BeNullMa2->Text= 	(int)be[0x72]+(int)be[0x73]*256;
		BeSzorMa3->Text= 	(int)be[0x74]+(int)be[0x75]*256;
		BeNullMa3->Text= 	(int)be[0x76]+(int)be[0x77]*256;
		BeSzorMa4->Text= 	(int)be[0x78]+(int)be[0x79]*256;
		BeNullMa4->Text= 	(int)be[0x7a]+(int)be[0x7b]*256;
		UzenKiolv->Caption= sk.sprintf("%s: %i ", TxtAnalog[12][Nyelv], res);
		}
	else	UzenKiolv->Caption= sk.sprintf("%s: %i ", TxtAnalog[13][Nyelv], res);
	Kiolv= 0;
	UzenTap->Caption= "-";
	UzenMa1->Caption= "-";
	UzenMa2->Caption= "-";
	UzenMa3->Caption= "-";
	UzenMa4->Caption= "-";
	}
else	{
	if(MemRead(be, RD_MEM, 64) == 0){
		KiU11->Caption=s.sprintf("%4.2fV", ((float)be[0x35]*256+(float)be[0x34])/100);	//U11
		KiU10->Caption=s.sprintf("%4.2fV", ((float)be[0x37]*256+(float)be[0x36])/100);	//U10

		KiMa1->Caption=s.sprintf("%5iuA", (int)be[0x29]*256+(int)be[0x28]);			//UmA1
		KiMa2->Caption=s.sprintf("%5iuA", (int)be[0x2b]*256+(int)be[0x2a]);			//UmA2
		KiMa3->Caption=s.sprintf("%5iuA", (int)be[0x2d]*256+(int)be[0x2c]);			//UmA3
		KiMa4->Caption=s.sprintf("%5iuA", (int)be[0x2f]*256+(int)be[0x2e]);			//UmA4
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall 	TAnalog::BuKiolvClick(TObject *Sender)
{
Kiolv= 1;
}
//---------------------------------------------------------------------------
void __fastcall 	TAnalog::BuBeirU11Click(TObject *Sender)
{
int		i;
i= BeU11->Text.ToIntDef(0); if(i < 1) i= 1; if(i > 255) i= 255;
Kiepr[0x00]= i;
Beir= 1;
}
//---------------------------------------------------------------------------
void __fastcall 	TAnalog::BuBeirMa1Click(TObject *Sender)
{
int		i;
i= BeSzorMa1->Text.ToIntDef(0); if(i < 1) i= 1; if(i > 30000) i= 30000;
Kiepr[0x00]= Low(i); Kiepr[0x01]= High(i);
i= BeNullMa1->Text.ToIntDef(0); if(i < 1) i= 1; if(i > 30000) i= 30000;
Kiepr[0x02]= Low(i); Kiepr[0x03]= High(i);
Beir= 2;
}
//---------------------------------------------------------------------------
void __fastcall 	TAnalog::BuBeirMa2Click(TObject *Sender)
{
int		i;
i= BeSzorMa2->Text.ToIntDef(0); if(i < 1) i= 1; if(i > 30000) i= 30000;
Kiepr[0x00]= Low(i); Kiepr[0x01]= High(i);
i= BeNullMa2->Text.ToIntDef(0); if(i < 1) i= 1; if(i > 30000) i= 30000;
Kiepr[0x02]= Low(i); Kiepr[0x03]= High(i);
Beir= 3;
}
//---------------------------------------------------------------------------
void __fastcall TAnalog::BuBeirMa3Click(TObject *Sender)
{
int		i;
i= BeSzorMa3->Text.ToIntDef(0); if(i < 1) i= 1; if(i > 30000) i= 30000;
Kiepr[0x00]= Low(i); Kiepr[0x01]= High(i);
i= BeNullMa3->Text.ToIntDef(0); if(i < 1) i= 1; if(i > 30000) i= 30000;
Kiepr[0x02]= Low(i); Kiepr[0x03]= High(i);
Beir= 4;
}
//---------------------------------------------------------------------------
void __fastcall TAnalog::BuBeirMa4Click(TObject *Sender)
{
int		i;
i= BeSzorMa4->Text.ToIntDef(0); if(i < 1) i= 1; if(i > 30000) i= 30000;
Kiepr[0x00]= Low(i); Kiepr[0x01]= High(i);
i= BeNullMa4->Text.ToIntDef(0); if(i < 1) i= 1; if(i > 30000) i= 30000;
Kiepr[0x02]= Low(i); Kiepr[0x03]= High(i);
Beir= 5;
}
//---------------------------------------------------------------------------
void __fastcall 	TAnalog::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

