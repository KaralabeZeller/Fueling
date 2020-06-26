#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include "cFlsClear.h"
#include "cModbusSoros.h"
#include "cTeszt.h"
#include "cVezerlo.h"
#include "cTxtBenzin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TFlsClr *FlsClr;
//---------------------------------------------------------------------------
__fastcall 		TFlsClr::TFlsClr(TComponent* Owner):TForm(Owner)
{
setmem(BlkTank, sizeof(BlkTank), 0);
setmem(BlkCrd, sizeof(BlkCrd), 0);
setmem(BlkArak, sizeof(BlkArak), 0);
setmem(BlkCeg, sizeof(BlkCeg), 0);
Tankok->Width=	TANK_MAXBLK/4+4;//border miatt
Kartyak->Width=	CARD_MAXBLK/4+4;
Arak->Width=	ARAK_MAXBLK/4+4;
Cegek->Width=	CEG_MAXBLK/4+4;
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::FormActivate(TObject *Sender)
{
Caption=				TxtFlsClear[0][Nyelv];
LabVigyazz->Caption=		TxtFlsClear[1][Nyelv];
GroupTankolasok->Caption=	TxtFlsClear[2][Nyelv];
GroupKartyak->Caption=		TxtFlsClear[3][Nyelv];
GroupArak->Caption=		TxtFlsClear[4][Nyelv];
GroupCegek->Caption=		TxtFlsClear[5][Nyelv];

BuOlvasTank->Caption=		TxtFlsClear[6][Nyelv];
BuOlvasCrd->Caption=		TxtFlsClear[6][Nyelv];
BuOlvasArak->Caption=		TxtFlsClear[6][Nyelv];
BuOlvasCeg->Caption=		TxtFlsClear[6][Nyelv];

BuTorolTank->Caption=		TxtFlsClear[7][Nyelv];
BuTorolCrd->Caption=		TxtFlsClear[7][Nyelv];
BuTorolArak->Caption=		TxtFlsClear[7][Nyelv];
BuTorolCeg->Caption=		TxtFlsClear[7][Nyelv];

BuStop->Caption=			TxtFlsClear[8][Nyelv];
BuVissza->Caption=		TxtFlsClear[9][Nyelv];
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::KockaKi(TControlBar *bar, int x, int y, TColor color)
{
bar->Canvas->Pixels[x  ][y  ]= color;
bar->Canvas->Pixels[x+1][y  ]= color;
bar->Canvas->Pixels[x  ][y+1]= color;
bar->Canvas->Pixels[x+1][y+1]= color;
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::KartyakPaint(TObject *Sender)
{
int		x, y;
TColor	color;

for(x=0; x<Tankok->Width; x+=2){
	for(y=0; y<16; y+=2){
		switch(BlkTank[x*4+y/2]){
			case 0: color= clWhite; break;
			case 1: color= clGreen; break;
			case 2: color= clRed; break;
			}
		KockaKi(Tankok, x, y, color);
		}
	}
for(x=0; x<Kartyak->Width; x+=2){
	for(y=0; y<16; y+=2){
		switch(BlkCrd[x*4+y/2]){
			case 0: color= clWhite; break;
			case 1: color= clGreen; break;
			case 2: color= clRed; break;
			}
		KockaKi(Kartyak, x, y, color);
		}
	}
for(x=0; x<Arak->Width; x+=2){
	for(y=0; y<16; y+=2){
		switch(BlkArak[x*4+y/2]){
			case 0: color= clWhite; break;
			case 1: color= clGreen; break;
			case 2: color= clRed; break;
			}
		KockaKi(Arak, x, y, color);
		}
	}
for(x=0; x<Cegek->Width; x+=2){
	for(y=0; y<16; y+=2){
		switch(BlkCeg[x*4+y/2]){
			case 0: color= clWhite; break;
			case 1: color= clGreen; break;
			case 2: color= clRed; break;
			}
		KockaKi(Cegek, x, y, color);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::Timer50ms(void)
{
int		x, y;
TColor	color;

switch(Fazis){
	case F_OLVTANK:
			if(FlashRead(Fls, Blk*16, 0, 32) == 0){
				if((Fls[0] != 0xff)||(Fls[1] != 0xff)||(Fls[2] != 0xff))
					{ color= clRed; Db++; BlkTank[Blk]= 2; }
				else	{ color= clGreen; BlkTank[Blk]= 1; }
				x= 2*(Blk/8); y= 2*(Blk%8);
				Tankok->Canvas->Pixels[x  ][y  ]= color;
				Tankok->Canvas->Pixels[x+1][y  ]= color;
				Tankok->Canvas->Pixels[x  ][y+1]= color;
				Tankok->Canvas->Pixels[x+1][y+1]= color;
				KiTank->Caption=ks.sprintf("%5i%s [Blk=%04i]", Db, TxtFlsClear[10][Nyelv], Blk);//db rekord foglalt
				Blk++;
				if(Blk >= TANK_MAXBLK) Fazis= F_ALAP;	//stop
				}
			break;
	case F_OLVCRD:
			if(FlashRead(Fls, Blk*16+0x8000, 0, 32) == 0){
				if((Fls[0] != 0xff)||(Fls[1] != 0xff)||(Fls[2] != 0xff))
					{ color= clRed; Db++; BlkCrd[Blk]= 2; }
				else	{ color= clGreen; BlkCrd[Blk]= 1; }
				x= 2*(Blk/8); y= 2*(Blk%8);
				Kartyak->Canvas->Pixels[x  ][y  ]= color;
				Kartyak->Canvas->Pixels[x+1][y  ]= color;
				Kartyak->Canvas->Pixels[x  ][y+1]= color;
				Kartyak->Canvas->Pixels[x+1][y+1]= color;
				KiKartya->Caption= ks.sprintf("%5i%s [Blk=%04i]", Db, TxtFlsClear[10][Nyelv], Blk);//db rekord foglalt
				Blk++;
				if(Blk >= CARD_MAXBLK) Fazis= F_ALAP;	//stop
				}
			break;
	case F_OLVARAK:
			if(FlashRead(Fls, Blk*16+0xe000, 0, 32) == 0){
				if((Fls[0] != 0xff)||(Fls[1] != 0xff)||(Fls[2] != 0xff))
					{ color= clRed; Db++; BlkCeg[Blk]= 2; }
				else	{ color= clGreen; BlkCeg[Blk]= 1; }
				x= 2*(Blk/8); y= 2*(Blk%8);
				Arak->Canvas->Pixels[x  ][y  ]= color;
				Arak->Canvas->Pixels[x+1][y  ]= color;
				Arak->Canvas->Pixels[x  ][y+1]= color;
				Arak->Canvas->Pixels[x+1][y+1]= color;
				KiArak->Caption= ks.sprintf("%5i%s [Blk=%04i]", Db, TxtFlsClear[10][Nyelv], Blk);//db rekord foglalt
				Blk++;
				if(Blk >= ARAK_MAXBLK) Fazis= F_ALAP;	//stop
				}
			break;
	case F_OLVCEG:
			if(FlashRead(Fls, Blk*16+0xf000, 0, 32) == 0){
				if((Fls[0] != 0xff)||(Fls[1] != 0xff)||(Fls[2] != 0xff))
					{ color= clRed; Db++; BlkCeg[Blk]= 2; }
				else	{ color= clGreen; BlkCeg[Blk]= 1; }
				x= 2*(Blk/8); y= 2*(Blk%8);
				Cegek->Canvas->Pixels[x  ][y  ]= color;
				Cegek->Canvas->Pixels[x+1][y  ]= color;
				Cegek->Canvas->Pixels[x  ][y+1]= color;
				Cegek->Canvas->Pixels[x+1][y+1]= color;
				KiCeg->Caption= ks.sprintf("%5i%s [Blk=%04i]", Db, TxtFlsClear[10][Nyelv], Blk);//db rekord foglalt
				Blk++;
				if(Blk >= CEG_MAXBLK) Fazis= F_ALAP;	//stop
				}
			break;
	case F_CLRTANK:
			if(Delay > 0) Delay--;
			else{
				Delay= 10;//500ms pihi
				if(FlashSectorClr(Blk*16) == 0){
					color= clBlack; Db++; BlkTank[Blk]= 0;
					x= 2*(Blk/8); y= 2*(Blk%8);
					Tankok->Canvas->Pixels[x  ][y  ]= color;
					Tankok->Canvas->Pixels[x+1][y  ]= color;
					Tankok->Canvas->Pixels[x  ][y+1]= color;
					Tankok->Canvas->Pixels[x+1][y+1]= color;
					KiTank->Caption= ks.sprintf("%5i%s [Blk=%04i]", Db, TxtFlsClear[11][Nyelv],Blk);//db rekord törölve
					Blk++;
					if(Blk >= TANK_MAXBLK) Fazis= F_ALAP;	//stop
					}
				}
			break;
	case F_CLRCRD:
//FlashSectorClr(cim/2);	//cim(16page=1sector)
			if(Delay > 0) Delay--;
			else{
				Delay= 10;//500ms pihi
				if(FlashSectorClr(Blk*16+0x8000) == 0){
					color= clBlack; Db++; BlkCrd[Blk]= 0;
					x= 2*(Blk/8); y= 2*(Blk%8);
					Kartyak->Canvas->Pixels[x  ][y  ]= color;
					Kartyak->Canvas->Pixels[x+1][y  ]= color;
					Kartyak->Canvas->Pixels[x  ][y+1]= color;
					Kartyak->Canvas->Pixels[x+1][y+1]= color;
					KiKartya->Caption= ks.sprintf("%5i%s [Blk=%04i]", Db, TxtFlsClear[11][Nyelv], Blk);//db rekord törölve
					Blk++;
					if(Blk >= CARD_MAXBLK) Fazis=F_ALAP;	//stop
					}
				}
			break;
	case F_CLRARAK:
			if(Delay > 0) Delay--;
			else{
				Delay= 10;//500ms pihi
				if(FlashSectorClr(Blk*16+0xe000) == 0){
					color= clBlack; Db++; BlkArak[Blk]= 0;
					x= 2*(Blk/8); y= 2*(Blk%8);
					Arak->Canvas->Pixels[x  ][y  ]= color;
					Arak->Canvas->Pixels[x+1][y  ]= color;
					Arak->Canvas->Pixels[x  ][y+1]= color;
					Arak->Canvas->Pixels[x+1][y+1]= color;
					KiArak->Caption=ks.sprintf("%5i%s [Blk=%04i]", Db, TxtFlsClear[11][Nyelv], Blk);//db rekord törölve
					Blk++;
					if(Blk >= ARAK_MAXBLK) Fazis= F_ALAP;	//stop
					}
				}
			break;
	case F_CLRCEG:
			if(Delay > 0) Delay--;
			else{
				Delay= 10;//500ms pihi
				if(FlashSectorClr(Blk*16+0xf000) == 0){
					color= clBlack; Db++; BlkCeg[Blk]= 0;
					x= 2*(Blk/8); y= 2*(Blk%8);
					Cegek->Canvas->Pixels[x  ][y  ]= color;
					Cegek->Canvas->Pixels[x+1][y  ]= color;
					Cegek->Canvas->Pixels[x  ][y+1]= color;
					Cegek->Canvas->Pixels[x+1][y+1]= color;
					KiCeg->Caption= ks.sprintf("%5i%s [Blk=%04i]", Db, TxtFlsClear[11][Nyelv] ,Blk);//db rekord törölve
					Blk++;
					if(Blk >= CEG_MAXBLK) Fazis= F_ALAP;	//stop
					}
				}
			break;
	}
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::BuOlvasTankClick(TObject *Sender)
{
setmem(BlkTank, sizeof(BlkTank), 0);  	Blk= 0; Db= 0; Fazis= F_OLVTANK;
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::BuOlvasCrdClick(TObject *Sender)
{
setmem(BlkCrd, sizeof(BlkCrd), 0);		Blk= 0; Db= 0; Fazis= F_OLVCRD;
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::BuOlvasArakClick(TObject *Sender)
{
setmem(BlkArak, sizeof(BlkArak), 0);	Blk= 0; Db= 0; Fazis= F_OLVARAK;
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::BuOlvasCegClick(TObject *Sender)
{
setmem(BlkCeg, sizeof(BlkCeg), 0);        Blk= 0; Db= 0; Fazis= F_OLVCEG;
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::BuTorolTankClick(TObject *Sender)
{
//if(Application->MessageBox("Törölni akarod a tankolásokat ?","Tankolások törlése",MB_YESNO)==IDYES){
if(Application->MessageBox(TxtFlsClear[13][Nyelv].c_str(),TxtFlsClear[12][Nyelv].c_str(),MB_YESNO) == IDYES){
	Blk= 0; Db= 0; Delay= 0; Fazis= F_CLRTANK;
	}
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::BuTorolCrdClick(TObject *Sender)
{
//if(Application->MessageBox("Törölni akarod a kártyákat ?","Kártyák törlése",MB_YESNO)==IDYES){
if(Application->MessageBox(TxtFlsClear[15][Nyelv].c_str(),TxtFlsClear[14][Nyelv].c_str(),MB_YESNO) == IDYES){
	Blk= 0; Db= 0; Delay= 0; Fazis= F_CLRCRD;
	}
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::BuTorolArakClick(TObject *Sender)
{
//if(Application->MessageBox("Törölni akarod az árakat ?","Árak törlése",MB_YESNO)==IDYES){
if(Application->MessageBox(TxtFlsClear[17][Nyelv].c_str(),TxtFlsClear[16][Nyelv].c_str(),MB_YESNO) == IDYES){
	Blk= 0; Db= 0; Delay= 0; Fazis= F_CLRARAK;
	}
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::BuTorolCegClick(TObject *Sender)
{
//if(Application->MessageBox("Törölni akarod a cégeket ?","Cégek törlése",MB_YESNO)==IDYES){
if(Application->MessageBox(TxtFlsClear[19][Nyelv].c_str(),TxtFlsClear[18][Nyelv].c_str(),MB_YESNO) == IDYES){
	Blk= 0; Db= 0; Delay= 0; Fazis= F_CLRCEG;
	}
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::BuStopClick(TObject *Sender)
{
Blk= 0; Db= 0; Fazis= F_ALAP;
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::FormClose(TObject *Sender, TCloseAction &Action)
{
Blk= 0; Db= 0; Fazis= F_ALAP;
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::BuVisszaClick(TObject *Sender)
{
FlsClr->Close();
}
//---------------------------------------------------------------------------
void __fastcall 	TFlsClr::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

