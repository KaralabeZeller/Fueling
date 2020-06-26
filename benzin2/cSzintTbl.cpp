#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include "cVezerlo.h"
#include "cModbusSoros.h"
#include "cSzintTbl.h"
#include "cTxtBenzin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TSzintTbl *SzintTbl;
//---------------------------------------------------------------------------
__fastcall 		TSzintTbl::TSzintTbl(TComponent* Owner):TForm(Owner)
{
DatTorol();
Fil1= -1;
}
//---------------------------------------------------------------------------
void __fastcall 	TSzintTbl::DatTorol(void)
{
int	i, j;

for(i=0; i<8; i++)
	for(j=0; j<120; j++){
            dat[i][j][0]= 0xffff; dat[i][j][1]= 0xffff;
            }
}
//---------------------------------------------------------------------------
void __fastcall 	TSzintTbl::TablaKiir(void)
{
int	i, j;

for(i=0; i<4; i++)
	for(j=0; j<120; j++){
		Txt->Cells[0][j+1]= s.sprintf("%i", j+1);
		if(dat[i][j][0] == 0xffff)	Txt->Cells[i*2+1][j+1]= "-";
        else         				Txt->Cells[i*2+1][j+1]= s.sprintf("%i", dat[i][j][0]);
		if(dat[i][j][1] == 0xffff)  Txt->Cells[i*2+2][j+1]= "-";
        else         				Txt->Cells[i*2+2][j+1]= s.sprintf("%i", dat[i][j][1]);
        }
}
//---------------------------------------------------------------------------
void __fastcall 	TSzintTbl::FormActivate(TObject *Sender)
{
int	i;

Caption=				TxtSzintTbl[0][Nyelv];
BuMentes->Caption=		TxtSzintTbl[1][Nyelv];
BuOlvas->Caption=	   	TxtSzintTbl[4][Nyelv];
BuBeir->Caption=	   	TxtSzintTbl[5][Nyelv];
BuVissza->Caption=		TxtSzintTbl[6][Nyelv];

Txt->Cells[0][0]= "No";
Txt->Cells[1][0]= TxtSzintTbl[3][Nyelv]+"1-uA";
Txt->Cells[2][0]= TxtSzintTbl[3][Nyelv]+"1-liter";
Txt->Cells[3][0]= TxtSzintTbl[3][Nyelv]+"2-uA";
Txt->Cells[4][0]= TxtSzintTbl[3][Nyelv]+"2-liter";
Txt->Cells[5][0]= TxtSzintTbl[3][Nyelv]+"3-uA";
Txt->Cells[6][0]= TxtSzintTbl[3][Nyelv]+"3-liter";
Txt->Cells[7][0]= TxtSzintTbl[3][Nyelv]+"4-uA";
Txt->Cells[8][0]= TxtSzintTbl[3][Nyelv]+"4-liter";
TablaKiir();
}
//---------------------------------------------------------------------------
void __fastcall 	TSzintTbl::BuMentesClick(TObject *Sender)
{
int		i, len, ua1, ua2, ua3, ua4, liter1, liter2, liter3, liter4;
char	ki[260];

if(Fil1 > 0) FileClose(Fil1); Fil1= -1;
if(SaveDialog1->Execute()){
	FileNev->Caption= SaveDialog1->FileName;
	Fil1= FileCreate(SaveDialog1->FileName);
	if(Fil1 > 0){
		sprintf(ki, "No;Sz1-uA;Sz1-Liter;Sz2-uA;Sz2-Liter;Sz3-uA;Sz3-Liter;Sz4-uA;Sz4-Liter;\n");
		len= strlen(ki);
		FileWrite(Fil1, ki, len);
		for(i=0; i<120; i++){
			ua1=	Txt->Cells[1][i+1].ToIntDef(0);
			liter1=	Txt->Cells[2][i+1].ToIntDef(0);
			ua2=	Txt->Cells[3][i+1].ToIntDef(0);
			liter2=	Txt->Cells[4][i+1].ToIntDef(0);
			ua3=	Txt->Cells[5][i+1].ToIntDef(0);
			liter3=	Txt->Cells[6][i+1].ToIntDef(0);
			ua4=	Txt->Cells[7][i+1].ToIntDef(0);
			liter4=	Txt->Cells[8][i+1].ToIntDef(0);
			sprintf(ki, "%03i;%5i;%5i;%5i;%5i;%5i;%5i;%5i;%5i;\n", i+1, ua1, liter1, ua2, liter2, ua3, liter3, ua4, liter4);
			len= strlen(ki);
			FileWrite(Fil1, ki, len);
       		}
		}
	else	Uzen->Caption= TxtSzintTbl[9][Nyelv];//"File létrehozás nem sikerült!";
	}

if(Fil1 > 0) FileClose(Fil1); Fil1= -1;
BuMentes->Font->Color= clNavy;
}
//---------------------------------------------------------------------------
void __fastcall 	TSzintTbl::SzintTblOlvas(void)
{
int		i, res, proba, cim, mut;
Byte		ok1= 0, hiba, be[130];
Word		verz;

Uzen->Caption= s.sprintf("%s: ", /*Olvasás*/TxtSzintTbl[10][Nyelv]); Uzen->Repaint();

DatTorol();
for(cim=0; cim<16; cim++){//4tbl*4(*30)pont
	for(hiba=0,proba=0; proba<50; proba++){
		res= FlashRead(be, FLS_SZINTMIN+cim/2,(cim&1)*128, 122);
		if(res == 0){
			verz= 256*(Word)be[0x01]+be[0x00]; if(verz == 0x7001) ok1= 1;//1.rekord
			break;
			}
		else{ hiba++; if(hiba > 20) break; }
      	}

	for(i=0; i<30; i++){
      	mut= (cim%4)*30+i;
		if(ok1 == 1){
			dat[cim/4][mut][0]= (int)be[i*4+3]*256+be[i*4+2];//uA
			dat[cim/4][mut][1]= (int)be[i*4+5]*256+be[i*4+4];//liter
            }
		}
	Uzen->Caption= s.sprintf("%s: %i/8 OK", /*Olvasás*/TxtSzintTbl[10][Nyelv], cim+1); Uzen->Repaint();
    }
TablaKiir();
}
//---------------------------------------------------------------------------
int __fastcall 	TSzintTbl::KiirFlsTolt(int mero, int blk)
{
int		i, res;
Word		ua, liter;
Byte		be[130];

mero&= 7; blk&= 3;						//0..7, 0..3	para
be[0]= 0x00;		//H
be[1]= mero*4+blk;	//L
be[2]= blk+0x01;	//L
be[3]= 0x70;		//H

for(i=4; i<124; i++) be[i]= 0xff;

for(i=0; i<30; i++){
   	ua= dat[mero][i+blk*30][0]; liter= dat[mero][i+blk*30][1];
	be[i*4+4]= Low(ua);		be[i*4+5]= High(ua);
	be[i*4+6]= Low(liter);	be[i*4+7]= High(liter);
	}
res= MemWrite(be, RW_SZINT, 124);
return(res);
}
//---------------------------------------------------------------------------
void __fastcall 	TSzintTbl::SzintTblBeir(void)
{
int		i, res= 0, m;
Byte	be[130];

FlashSectorClr(FLS_SZINTMIN);

for(i=0; i<120; i++){
	dat[0][i][0]=  	Txt->Cells[1][i+1].ToIntDef(0);
	dat[0][i][1]=	Txt->Cells[2][i+1].ToIntDef(0);
	dat[1][i][0]=  	Txt->Cells[3][i+1].ToIntDef(0);
	dat[1][i][1]=	Txt->Cells[4][i+1].ToIntDef(0);
	dat[2][i][0]=  	Txt->Cells[5][i+1].ToIntDef(0);
	dat[2][i][1]=	Txt->Cells[6][i+1].ToIntDef(0);
	dat[3][i][0]=  	Txt->Cells[7][i+1].ToIntDef(0);
	dat[3][i][1]=	Txt->Cells[8][i+1].ToIntDef(0);
	}

for(i=0; i<60; i++){//wait
	res= FlashRead(be, FLS_SZINTMIN, 0, 122);
	if(res == 0) break;
    }

for(m=0; m<4; m++){
	if(res == 0) res+= KiirFlsTolt(m, 0);
	if(res == 0) res+= KiirFlsTolt(m, 1);
	if(res == 0) res+= KiirFlsTolt(m, 2);
	if(res == 0) res+= KiirFlsTolt(m, 3);
    }

if(res == 0){ Uzen->Caption= TxtSzintTbl[11][Nyelv]/*"Írás OK"*/; }
else{ Uzen->Caption= s.sprintf("%s: %i",/*Írás HIBA*/TxtSzintTbl[12][Nyelv], res); }
}
//---------------------------------------------------------------------------
void __fastcall 	TSzintTbl::BuOlvasClick(TObject *Sender)	{ SzintTblOlvas(); }
//---------------------------------------------------------------------------
void __fastcall 	TSzintTbl::BuBeirClick(TObject *Sender)   	{ SzintTblBeir(); }
//---------------------------------------------------------------------------
void __fastcall 	TSzintTbl::BuVisszaClick(TObject *Sender)	{ Close(); }
//---------------------------------------------------------------------------
void __fastcall 	TSzintTbl::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------

