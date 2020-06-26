#include <vcl.h>
#pragma hdrstop
#include "cEEpromInit.h"
#include "cModbusSoros.h"
#include "cTxtBenzin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TEEpromInit *EEpromInit;
//---------------------------------------------------------------------------
__fastcall TEEpromInit::TEEpromInit(TComponent* Owner):TForm(Owner)
{
Kiolv= 0; Beir= 0;
}
//---------------------------------------------------------------------------
void __fastcall 	TEEpromInit::FormActivate(TObject *Sender)
{
int	i;

Caption=					TxtEEprom[0][Nyelv];

GroupKutfok->Caption=		TxtEEprom[1][Nyelv];
Kut1->Caption=				TxtEEprom[2][Nyelv]+"1";
Kut2->Caption=				TxtEEprom[2][Nyelv]+"2";
Kut3->Caption=				TxtEEprom[2][Nyelv]+"3";
Kut4->Caption=				TxtEEprom[2][Nyelv]+"4";
Kut5->Caption=				TxtEEprom[2][Nyelv]+"5";
Kut6->Caption=				TxtEEprom[2][Nyelv]+"6";
Kut7->Caption=				TxtEEprom[2][Nyelv]+"7";
Kut8->Caption=				TxtEEprom[2][Nyelv]+"8";
Kut9->Caption=				TxtEEprom[2][Nyelv]+"9";
Kut10->Caption=		   	TxtEEprom[2][Nyelv]+"10";
Kut11->Caption=		   	TxtEEprom[2][Nyelv]+"11";
Kut12->Caption=		   	TxtEEprom[2][Nyelv]+"12";
Kut13->Caption=		   	TxtEEprom[2][Nyelv]+"13";
Kut14->Caption=		   	TxtEEprom[2][Nyelv]+"14";
Kut15->Caption=		   	TxtEEprom[2][Nyelv]+"15";
LabOlaj->Caption=			TxtEEprom[3][Nyelv];
LabBenzin->Caption=			TxtEEprom[4][Nyelv];
LabVirtualis->Caption=		TxtEEprom[5][Nyelv];

GroupSzint1->Caption=	   	TxtEEprom[6][Nyelv];
S1_1->Caption=				TxtEEprom[2][Nyelv]+"1";
S1_2->Caption=				TxtEEprom[2][Nyelv]+"2";
S1_3->Caption=				TxtEEprom[2][Nyelv]+"3";
S1_4->Caption=				TxtEEprom[2][Nyelv]+"4";
S1_5->Caption=				TxtEEprom[2][Nyelv]+"5";
S1_6->Caption=				TxtEEprom[2][Nyelv]+"6";
S1_7->Caption=				TxtEEprom[2][Nyelv]+"7";
S1_8->Caption=				TxtEEprom[2][Nyelv]+"8";
S1_9->Caption=				TxtEEprom[2][Nyelv]+"9";
S1_10->Caption=			TxtEEprom[2][Nyelv]+"10";
S1_11->Caption=			TxtEEprom[2][Nyelv]+"11";
S1_12->Caption=			TxtEEprom[2][Nyelv]+"12";
S1_13->Caption=			TxtEEprom[2][Nyelv]+"13";
S1_14->Caption=			TxtEEprom[2][Nyelv]+"14";
S1_15->Caption=			TxtEEprom[2][Nyelv]+"15";

GroupSzint2->Caption=	   	TxtEEprom[7][Nyelv];
S2_1->Caption=				TxtEEprom[2][Nyelv]+"1";
S2_2->Caption=				TxtEEprom[2][Nyelv]+"2";
S2_3->Caption=				TxtEEprom[2][Nyelv]+"3";
S2_4->Caption=				TxtEEprom[2][Nyelv]+"4";
S2_5->Caption=				TxtEEprom[2][Nyelv]+"5";
S2_6->Caption=				TxtEEprom[2][Nyelv]+"6";
S2_7->Caption=				TxtEEprom[2][Nyelv]+"7";
S2_8->Caption=				TxtEEprom[2][Nyelv]+"8";
S2_9->Caption=				TxtEEprom[2][Nyelv]+"9";
S2_10->Caption=			TxtEEprom[2][Nyelv]+"10";
S2_11->Caption=			TxtEEprom[2][Nyelv]+"11";
S2_12->Caption=			TxtEEprom[2][Nyelv]+"12";
S2_13->Caption=			TxtEEprom[2][Nyelv]+"13";
S2_14->Caption=			TxtEEprom[2][Nyelv]+"14";
S2_15->Caption=			TxtEEprom[2][Nyelv]+"15";

GroupStatusz->Caption=	   	TxtEEprom[8][Nyelv];
StaLiter->Caption=	   		TxtEEprom[9][Nyelv];
StaCard->Caption=	   		TxtEEprom[10][Nyelv];
StaAutoStr->Caption=	   	TxtEEprom[11][Nyelv];
StaKm->Caption=	   		TxtEEprom[12][Nyelv];
StaKmNov->Caption=	   		TxtEEprom[13][Nyelv];
StaKmKetszer->Caption=	   	TxtEEprom[14][Nyelv];
LabVezerloSzam->Caption=	   	TxtEEprom[15][Nyelv];
StaMenlev->Caption=	   		TxtEEprom[16][Nyelv];
StaUzem->Caption=	   		TxtEEprom[17][Nyelv];
StaEkod->Caption=	   		TxtEEprom[18][Nyelv];
LabNyelv->Caption=	   		TxtEEprom[19][Nyelv];

GroupKontraszt->Caption=		TxtEEprom[20][Nyelv];
LabKontraszt->Caption=		TxtEEprom[21][Nyelv];
LabKontKomopenz->Caption=    	TxtEEprom[22][Nyelv];
LabHoSzorzo->Caption=		TxtEEprom[23][Nyelv];
LabHoOffset->Caption=		TxtEEprom[24][Nyelv];

GroupGyurus->Caption=	   	TxtEEprom[25][Nyelv];
LabPisztoly1->Caption=	   	TxtEEprom[26][Nyelv];
LabPisztoly2->Caption=	   	TxtEEprom[27][Nyelv];
LabPisztoly3->Caption=	   	TxtEEprom[28][Nyelv];
LabPistNincs->Caption=	   	TxtEEprom[29][Nyelv];
LabOistNum->Caption=	   	TxtEEprom[30][Nyelv];

GroupKartyaolvaso1->Caption= 	TxtEEprom[31][Nyelv];
CardRead1->Caption= 		TxtEEprom[32][Nyelv];
CardRead2->Caption= 		TxtEEprom[33][Nyelv];
CardRead3->Caption= 		TxtEEprom[34][Nyelv];
CardRead4->Caption= 		TxtEEprom[35][Nyelv];
CardRead5->Caption= 		TxtEEprom[36][Nyelv];
CardRead6->Caption= 		TxtEEprom[37][Nyelv];
CardRead7->Caption= 		TxtEEprom[38][Nyelv];

GroupKartyaolvaso2->Caption= 	TxtEEprom[51][Nyelv];
CardRead20->Caption= 		TxtEEprom[52][Nyelv];
CardRead21->Caption= 		TxtEEprom[53][Nyelv];

GroupNyomtatas->Caption=		TxtEEprom[39][Nyelv];
LabPeldanyszam->Caption=		TxtEEprom[40][Nyelv];

GroupIdozitesek->Caption=   	TxtEEprom[41][Nyelv];
LabMnuVissza->Caption=   	TxtEEprom[42][Nyelv];
LabMnuUtanvil->Caption=   	TxtEEprom[43][Nyelv];
LabMnuVissza2->Caption=   	TxtEEprom[44][Nyelv];
LabMnuUtanvil2->Caption=   	TxtEEprom[45][Nyelv];

BuOlvas->Caption=		   	TxtEEprom[46][Nyelv];
BuBeir->Caption=		   	TxtEEprom[47][Nyelv];
BuKilep->Caption=		   	TxtEEprom[48][Nyelv];

StaMaxStop->Caption=		TxtEEprom[54][Nyelv];
}
//---------------------------------------------------------------------------
void __fastcall 	TEEpromInit::Kiolv50ms(void)
{
int			res= 0;
AnsiString	sk;

res= MemRead(epr, RW_EEPROM, 128);
if(res == 0){
	Kut1->Checked=		((epr[0x10]&0x01) != 0) ? true : false;
	Kut2->Checked=		((epr[0x11]&0x01) != 0) ? true : false;
	Kut3->Checked=		((epr[0x12]&0x01) != 0) ? true : false;
	Kut4->Checked=		((epr[0x13]&0x01) != 0) ? true : false;
	Kut5->Checked=		((epr[0x14]&0x01) != 0) ? true : false;
	Kut6->Checked=		((epr[0x15]&0x01) != 0) ? true : false;
	Kut7->Checked=		((epr[0x16]&0x01) != 0) ? true : false;
	Kut8->Checked=		((epr[0x17]&0x01) != 0) ? true : false;
	Kut9->Checked=		((epr[0x18]&0x01) != 0) ? true : false;
	Kut10->Checked=    	((epr[0x19]&0x01) != 0) ? true : false;
	Kut11->Checked=    	((epr[0x1a]&0x01) != 0) ? true : false;
	Kut12->Checked=    	((epr[0x1b]&0x01) != 0) ? true : false;
	Kut13->Checked=    	((epr[0x1c]&0x01) != 0) ? true : false;
	Kut14->Checked=    	((epr[0x1d]&0x01) != 0) ? true : false;
	Kut15->Checked=    	((epr[0x1e]&0x01) != 0) ? true : false;

	BeBenzin1->Text=	(epr[0x10]/2);
	BeBenzin2->Text=	(epr[0x11]/2);
	BeBenzin3->Text=	(epr[0x12]/2);
	BeBenzin4->Text=	(epr[0x13]/2);
	BeBenzin5->Text=	(epr[0x14]/2);
	BeBenzin6->Text=	(epr[0x15]/2);
	BeBenzin7->Text=	(epr[0x16]/2);
	BeBenzin8->Text=	(epr[0x17]/2);
	BeBenzin9->Text=	(epr[0x18]/2);
	BeBenzin10->Text=	(epr[0x19]/2);
	BeBenzin11->Text=	(epr[0x1a]/2);
	BeBenzin12->Text=	(epr[0x1b]/2);
	BeBenzin13->Text=	(epr[0x1c]/2);
	BeBenzin14->Text=	(epr[0x1d]/2);
	BeBenzin15->Text=	(epr[0x1e]/2);

	VezNum->Text=		sk.sprintf("%i", epr[0x02]);

	StaLiter->Checked=		((epr[0x03]&0x01) != 0) ? true : false;
	StaCard->Checked=		((epr[0x03]&0x02) != 0) ? true : false;
	StaKm->Checked=		((epr[0x03]&0x04) != 0) ? true : false;
	StaMenlev->Checked=		((epr[0x03]&0x08) != 0) ? true : false;
	StaUzem->Checked=		((epr[0x03]&0x10) != 0) ? true : false;
	StaKmNov->Checked=		((epr[0x03]&0x20) != 0) ? true : false;
	StaEkod->Checked=		((epr[0x03]&0x40) != 0) ? true : false;
	StaAutoStr->Checked= 	((epr[0x03]&0x80) != 0) ? true : false;

	StaKmKetszer->Checked= 	((epr[0x0e]&0x01) != 0) ? true : false;
	StaMaxStop->Checked= 	((epr[0x0e]&0x02) != 0) ? true : false;

	Kontraszt->Text=	sk.sprintf("%i", epr[0x04]);
	KontKomp->Text=	sk.sprintf("%i", epr[0x05]);
	Ho1Szor->Text=		sk.sprintf("%i", (int)epr[0x07]*256+epr[0x06]);//LH
	Ho1Offs->Text=		sk.sprintf("%i", (int)epr[0x09]*256+epr[0x08]);//LH
	CrossPointCim->Text= sk.sprintf("%i", epr[0x0f]);

//  	Init1->Text=		sk.sprintf("%.32s", &epr[0x20]);
//  	Init2->Text=		sk.sprintf("%.32s", &epr[0x40]);
	BeMnuTimeout->Text=	sk.sprintf("%i", epr[0x20]);
	BeMnuUtoTime->Text=	sk.sprintf("%i", epr[0x21]);
	switch(epr[0x22]&0x0f){
		case 2:		CardRead2->Checked= true; break;
		case 3:		CardRead3->Checked= true; break;
		case 4:		CardRead4->Checked= true; break;
		case 5:		CardRead5->Checked= true; break;
		case 6:		CardRead6->Checked= true; break;
		case 7:		CardRead7->Checked= true; break;
		default:	     CardRead1->Checked= true; break;
		}
	switch(epr[0x22]&0xf0){
		case 0x10:	CardRead21->Checked= true; break;
		case 0x20:	CardRead22->Checked= true; break;
		default:	     CardRead20->Checked= true; break;
		}

	Gyurus1->Text=	sk.sprintf("%i",epr[0x23]);
	switch(epr[0x24]){
		case	1:	K4Nyelv->ItemIndex= 1 ; break;
		default:	K4Nyelv->ItemIndex= 0 ; break;
		}

	TankDb->Text=		sk.sprintf("%i", epr[0x60]);

	BeSzintNum1->Text=	sk.sprintf("%i", (int)epr[0x63]*256+epr[0x62]);//LH

	S1_1->Checked=		((epr[0x64]&0x01) != 0) ? true : false;
	S1_2->Checked=		((epr[0x64]&0x02) != 0) ? true : false;
	S1_3->Checked=		((epr[0x64]&0x04) != 0) ? true : false;
	S1_4->Checked=		((epr[0x64]&0x08) != 0) ? true : false;
	S1_5->Checked=		((epr[0x64]&0x10) != 0) ? true : false;
	S1_6->Checked=		((epr[0x64]&0x20) != 0) ? true : false;
	S1_7->Checked=		((epr[0x64]&0x40) != 0) ? true : false;
	S1_8->Checked=		((epr[0x64]&0x80) != 0) ? true : false;
	S1_9->Checked=		((epr[0x65]&0x01) != 0) ? true : false;
	S1_10->Checked=	((epr[0x65]&0x02) != 0) ? true : false;
	S1_11->Checked=     ((epr[0x65]&0x04) != 0) ? true : false;
	S1_12->Checked=     ((epr[0x65]&0x08) != 0) ? true : false;
	S1_13->Checked=	((epr[0x65]&0x10) != 0) ? true : false;
	S1_14->Checked=	((epr[0x65]&0x20) != 0) ? true : false;
	S1_15->Checked=	((epr[0x65]&0x40) != 0) ? true : false;

	BeSzintNum2->Text= 	sk.sprintf("%i",(int)epr[0x67]*256+epr[0x66]);//LH

	S2_1->Checked=	     ((epr[0x68]&0x01) != 0) ? true : false;
	S2_2->Checked=	     ((epr[0x68]&0x02) != 0) ? true : false;
	S2_3->Checked=	     ((epr[0x68]&0x04) != 0) ? true : false;
	S2_4->Checked=	     ((epr[0x68]&0x08) != 0) ? true : false;
	S2_5->Checked=	     ((epr[0x68]&0x10) != 0) ? true : false;
	S2_6->Checked=	     ((epr[0x68]&0x20) != 0) ? true : false;
	S2_7->Checked=	     ((epr[0x68]&0x40) != 0) ? true : false;
	S2_8->Checked=	     ((epr[0x68]&0x80) != 0) ? true : false;
	S2_9->Checked=	     ((epr[0x69]&0x01) != 0) ? true : false;
	S2_10->Checked=	((epr[0x69]&0x02) != 0) ? true : false;
	S2_11->Checked=	((epr[0x69]&0x04) != 0) ? true : false;
	S2_12->Checked=	((epr[0x69]&0x08) != 0) ? true : false;
	S2_13->Checked=	((epr[0x69]&0x10) != 0) ? true : false;
	S2_14->Checked=	((epr[0x69]&0x20) != 0) ? true : false;
	S2_15->Checked=	((epr[0x69]&0x40) != 0) ? true : false;

	S3_1->Checked=	     ((epr[0x5c]&0x01) != 0) ? true : false;
	S3_2->Checked=	     ((epr[0x5c]&0x02) != 0) ? true : false;
	S3_3->Checked=	     ((epr[0x5c]&0x04) != 0) ? true : false;
	S3_4->Checked=	     ((epr[0x5c]&0x08) != 0) ? true : false;
	S3_5->Checked=	     ((epr[0x5c]&0x10) != 0) ? true : false;
	S3_6->Checked=	     ((epr[0x5c]&0x20) != 0) ? true : false;
	S3_7->Checked=	     ((epr[0x5c]&0x40) != 0) ? true : false;
	S3_8->Checked=	     ((epr[0x5c]&0x80) != 0) ? true : false;
	S3_9->Checked=	     ((epr[0x5d]&0x01) != 0) ? true : false;
	S3_10->Checked=	((epr[0x5d]&0x02) != 0) ? true : false;
	S3_11->Checked=	((epr[0x5d]&0x04) != 0) ? true : false;
	S3_12->Checked=	((epr[0x5d]&0x08) != 0) ? true : false;
	S3_13->Checked=	((epr[0x5d]&0x10) != 0) ? true : false;
	S3_14->Checked=	((epr[0x5d]&0x20) != 0) ? true : false;
	S3_15->Checked=	((epr[0x5d]&0x40) != 0) ? true : false;

	S4_1->Checked=	     ((epr[0x5e]&0x01) != 0) ? true : false;
	S4_2->Checked=	     ((epr[0x5e]&0x02) != 0) ? true : false;
	S4_3->Checked=	     ((epr[0x5e]&0x04) != 0) ? true : false;
	S4_4->Checked=	     ((epr[0x5e]&0x08) != 0) ? true : false;
	S4_5->Checked=	     ((epr[0x5e]&0x10) != 0) ? true : false;
	S4_6->Checked=	     ((epr[0x5e]&0x20) != 0) ? true : false;
	S4_7->Checked=	     ((epr[0x5e]&0x40) != 0) ? true : false;
	S4_8->Checked=	     ((epr[0x5e]&0x80) != 0) ? true : false;
	S4_9->Checked=	     ((epr[0x5f]&0x01) != 0) ? true : false;
	S4_10->Checked=	((epr[0x5f]&0x02) != 0) ? true : false;
	S4_11->Checked=	((epr[0x5f]&0x04) != 0) ? true : false;
	S4_12->Checked=	((epr[0x5f]&0x08) != 0) ? true : false;
	S4_13->Checked=	((epr[0x5f]&0x10) != 0) ? true : false;
	S4_14->Checked=	((epr[0x5f]&0x20) != 0) ? true : false;
	S4_15->Checked=	((epr[0x5f]&0x40) != 0) ? true : false;

	Uzen->Caption= 	sk.sprintf("Olvasás OK: %i",res);
	}
else	{
	Uzen->Caption= 	sk.sprintf("Olvasás HIBA: %i",res);
	}
Kiolv= 0;
}
//-------------------------------------
void __fastcall 	TEEpromInit::Beir50ms(void)
{
int			i, res= 0;
AnsiString	sk;

memset(epr, 0xff, sizeof(epr));

epr[0x00]= 0x01; epr[0x01]= 0x00;					//x00		Word VERZ 0x0001=alap

i= VezNum->Text.ToIntDef(0); if(i < 1) i= 1; if(i > 255) i= 255;
epr[0x02]= i;						     		//x02		vezérlõ sorszáma

epr[0x03]= 0;	     							//x03		Vezérlõ beállítások
if(StaLiter->Checked == true)		epr[0x03]+= 0x01;	//B_VEZ_LITER	Tankolás literkijelzés
if(StaCard->Checked == true)		epr[0x03]+= 0x02;	//VEZ_CARD2	Card2(kétkártyás)
if(StaKm->Checked == true)		epr[0x03]+= 0x04;	//VEZ_KMBE	Km bekérés van
if(StaMenlev->Checked == true)	epr[0x03]+= 0x08;	//VEZ_MENLEV	Menetlevél bekérés van
if(StaUzem->Checked == true)		epr[0x03]+= 0x10;	//VEZ_UZEMORA	Üzemóra bekérés van
if(StaKmNov->Checked == true)		epr[0x03]+= 0x20;	//VEZ_KMBE	Km bekérés növekvõ
if(StaEkod->Checked == true)		epr[0x03]+= 0x40;	//VEZ_EMKOD	ember kód bekérés van
if(StaAutoStr->Checked == true)	epr[0x03]+= 0x80;	//VEZ_AUTOSTR	1 kútfo esetén autstart kártyabe

i=Kontraszt->Text.ToIntDef(0);    	if(i < 1) i= 1; if(i > 255) i= 255;
epr[0x04]= i;							     	//x04		Kijelzõ kontraszt			[0x50]
i=KontKomp->Text.ToIntDef(0);		if(i < 0) i= 0; if(i > 200) i= 200;
epr[0x05]= i;						     		//x05 Reg+1	Kijelzõ kontraszt kompenzáció

i= Ho1Szor->Text.ToIntDef(0);		if(i < 0) i= 0; if(i > 40000) i= 40000;
epr[0x06]= Low(i); epr[0x07]= High(i);		          //x06		hõmérés1 szorzó
i= Ho1Offs->Text.ToIntDef(0);		if(i < 0) i= 0; if(i > 30000) i= 30000;
epr[0x08]= Low(i); epr[0x09]= High(i);		          //x08		hõmérés1 nulla

i= Ho1Szor->Text.ToIntDef(0);		if(i < 0) i= 0; if(i > 40000) i= 40000;
epr[0x0a]= Low(i); epr[0x0b]= High(i);	          	//x0a		hõmérés2 szorzó
i= Ho1Offs->Text.ToIntDef(0);		if(i < 0) i= 0; if(i > 30000) i= 30000;
epr[0x0c]= Low(i); epr[0x0d]= High(i);	          	//x0c		hõmérés2 nulla

epr[0x0e]= 0;							     	//x0e		Vezérlõ beállítások
if(StaKmKetszer->Checked == true)	epr[0x0e]+= 0x01;	//B_VEZ2_KMKET	Km bekérés kétszer
if(StaMaxStop->Checked == true)	epr[0x0e]+= 0x02;	//B_VEZ2_STOP	max liter bekérés

i= CrossPointCim->Text.ToIntDef(0); if(i < 0) i= 0; if(i > 255) i= 255;
epr[0x0f]= Low(i);						     	//x0f		Crosspoint cím

//Word		TimeKomp;			//x0e	b15(H+,L-) &0x7fff percenként +-1mp (0=semmi)

epr[0x10]= (Kut1->Checked == true) ? 1 : 0;	     	//EE_KutStat=0x0010;8b	8 kútfõ státusza (b0=ki/be)[100000000]
epr[0x11]= (Kut2->Checked == true) ? 1 : 0;	     	//KUT_DISABLE	=0	;-	Kikapcsolva
epr[0x12]= (Kut3->Checked == true) ? 1 : 0;	     	//KUT_NORMAL	=1	;-	Alaphelyzet
epr[0x13]= (Kut4->Checked == true) ? 1 : 0;
epr[0x14]= (Kut5->Checked == true) ? 1 : 0;
epr[0x15]= (Kut6->Checked == true) ? 1 : 0;
epr[0x16]= (Kut7->Checked == true) ? 1 : 0;
epr[0x17]= (Kut8->Checked == true) ? 1 : 0;
epr[0x18]= (Kut9->Checked == true) ? 1 : 0;
epr[0x19]= (Kut10->Checked == true) ? 1 : 0;
epr[0x1a]= (Kut11->Checked == true) ? 1 : 0;
epr[0x1b]= (Kut12->Checked == true) ? 1 : 0;
epr[0x1c]= (Kut13->Checked == true) ? 1 : 0;
epr[0x1d]= (Kut14->Checked == true) ? 1 : 0;
epr[0x1e]= (Kut15->Checked == true) ? 1 : 0;
epr[0x1f]= 0;

i= BeBenzin1->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x10]+= i*2;//b0=0-Kikapcsolva, 1-Alaphelyzet
i= BeBenzin2->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x11]+= i*2;//b1=0-Gázolaj,1-Benzin;
i= BeBenzin3->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x12]+= i*2;//b2=0-normál, 1-virtuális
i= BeBenzin4->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x13]+= i*2;
i= BeBenzin5->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x14]+= i*2;
i= BeBenzin6->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x15]+= i*2;
i= BeBenzin7->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x16]+= i*2;
i= BeBenzin8->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x17]+= i*2;
i= BeBenzin9->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x18]+= i*2;
i= BeBenzin10->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x19]+= i*2;
i= BeBenzin11->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x1a]+= i*2;
i= BeBenzin12->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x1b]+= i*2;
i= BeBenzin13->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x1c]+= i*2;
i= BeBenzin14->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x1d]+= i*2;
i= BeBenzin15->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 2) i= 2; epr[0x1e]+= i*2;

i= BeMnuTimeout->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 255) i= 255; epr[0x20]= i;
i= BeMnuUtoTime->Text.ToIntDef(0);	if(i < 0) i= 0; if(i > 255) i= 255; epr[0x21]= i;

epr[0x22]= 1;
if(CardRead2->Checked)	epr[0x22]= 2;
if(CardRead3->Checked)	epr[0x22]= 3;
if(CardRead4->Checked)	epr[0x22]= 4;
if(CardRead5->Checked)	epr[0x22]= 5;
if(CardRead6->Checked)	epr[0x22]= 6;
if(CardRead7->Checked)	epr[0x22]= 7;

if(CardRead21->Checked)	epr[0x22]|= 0x10;
if(CardRead22->Checked)	epr[0x22]|= 0x20;

i= Gyurus1->Text.ToIntDef(0); if(i < 1) i= 0; if(i > 14) i= 0; epr[0x23]= i;
switch(K4Nyelv->ItemIndex){
		case	1:	epr[0x24]= 1 ; break;
		default:	epr[0x24]= 0 ; break;
		}

//	Byte		TankDb;			//x60		nyomtatáshoz példányszám (0-2)
i= TankDb->Text.ToIntDef(0); if(i > 10) i= 1;
epr[0x60]= i;
epr[0x61]= 0xff;

//	Word		Szint1;				//x62
i= BeSzintNum1->Text.ToIntDef(0); if(i > 0xffff) i= 0;
epr[0x63]= High(i);	epr[0x62]= Low(i);
//	Word		Szint1Kut;			//x64		;b0..14=kut1..15
i= 0;
if(S1_1->Checked)	i|= 0x0001;
if(S1_2->Checked)	i|= 0x0002;
if(S1_3->Checked)	i|= 0x0004;
if(S1_4->Checked)	i|= 0x0008;
if(S1_5->Checked)	i|= 0x0010;
if(S1_6->Checked)	i|= 0x0020;
if(S1_7->Checked)	i|= 0x0040;
if(S1_8->Checked)	i|= 0x0080;
if(S1_9->Checked)	i|= 0x0100;
if(S1_10->Checked)	i|= 0x0200;
if(S1_11->Checked)	i|= 0x0400;
if(S1_12->Checked)	i|= 0x0800;
if(S1_13->Checked)	i|= 0x1000;
if(S1_14->Checked)	i|= 0x2000;
if(S1_15->Checked)	i|= 0x4000;
epr[0x65]=High(i);	epr[0x64]=Low(i);
//	Word		Szint2;				//x66
i= BeSzintNum2->Text.ToIntDef(0); if(i > 0xffff) i= 0;
epr[0x67]= High(i);	epr[0x66]= Low(i);
//	Word		Szint2Kut;			//x68		;b0..14=kut1..15
i= 0;
if(S2_1->Checked)	i|= 0x0001;
if(S2_2->Checked)	i|= 0x0002;
if(S2_3->Checked)	i|= 0x0004;
if(S2_4->Checked)	i|= 0x0008;
if(S2_5->Checked)	i|= 0x0010;
if(S2_6->Checked)	i|= 0x0020;
if(S2_7->Checked)	i|= 0x0040;
if(S2_8->Checked)	i|= 0x0080;
if(S2_9->Checked)	i|= 0x0100;
if(S2_10->Checked)	i|= 0x0200;
if(S2_11->Checked)	i|= 0x0400;
if(S2_12->Checked)	i|= 0x0800;
if(S2_13->Checked)	i|= 0x1000;
if(S2_14->Checked)	i|= 0x2000;
if(S2_15->Checked)	i|= 0x4000;
epr[0x69]= High(i);	epr[0x68]= Low(i);

//	Word		Szint3Kut;			//x5c		;b0..14=kut1..15
i= 0;
if(S3_1->Checked)	i|= 0x0001;
if(S3_2->Checked)	i|= 0x0002;
if(S3_3->Checked)	i|= 0x0004;
if(S3_4->Checked)	i|= 0x0008;
if(S3_5->Checked)	i|= 0x0010;
if(S3_6->Checked)	i|= 0x0020;
if(S3_7->Checked)	i|= 0x0040;
if(S3_8->Checked)	i|= 0x0080;
if(S3_9->Checked)	i|= 0x0100;
if(S3_10->Checked)	i|= 0x0200;
if(S3_11->Checked)	i|= 0x0400;
if(S3_12->Checked)	i|= 0x0800;
if(S3_13->Checked)	i|= 0x1000;
if(S3_14->Checked)	i|= 0x2000;
if(S3_15->Checked)	i|= 0x4000;
epr[0x5c]= Low(i); epr[0x5d]= High(i);
//	Word		Szint4Kut;			//x5e		;b0..14=kut1..15
i= 0;
if(S4_1->Checked)	i|= 0x0001;
if(S4_2->Checked)	i|= 0x0002;
if(S4_3->Checked)	i|= 0x0004;
if(S4_4->Checked)	i|= 0x0008;
if(S4_5->Checked)	i|= 0x0010;
if(S4_6->Checked)	i|= 0x0020;
if(S4_7->Checked)	i|= 0x0040;
if(S4_8->Checked)	i|= 0x0080;
if(S4_9->Checked)	i|= 0x0100;
if(S4_10->Checked)	i|= 0x0200;
if(S4_11->Checked)	i|= 0x0400;
if(S4_12->Checked)	i|= 0x0800;
if(S4_13->Checked)	i|= 0x1000;
if(S4_14->Checked)	i|= 0x2000;
if(S4_15->Checked)	i|= 0x4000;
epr[0x5e]= Low(i); epr[0x5f]= High(i);

res= MemWrite(epr, RW_EEPROM, 0x6a);
if(res == 0)   { Uzen->Caption= sk.sprintf("%s: %i ",/*Írás OK*/TxtEEprom[49][Nyelv], res); }
else           { Uzen->Caption= sk.sprintf("%s: %i ",/*Írás HIBA*/TxtEEprom[50][Nyelv], res); }
Beir= 0;
}
//-------------------------------------
void __fastcall 	TEEpromInit::Timer50ms(void)
{
if		(Kiolv > 0)	Kiolv50ms();
else if	(Beir > 0)	Beir50ms();
}
//-------------------------------------
void __fastcall 	TEEpromInit::BuOlvasClick(TObject *Sender)
{
Kiolv= 1;
}
//-------------------------------------
void __fastcall 	TEEpromInit::BuBeirClick(TObject *Sender)
{
Beir= 1;
}
//-------------------------------------
void __fastcall 	TEEpromInit::StaKmClick(TObject *Sender)
{
if(!StaKm->Checked){
	StaKmNov->Enabled= false;
	StaKmNov->Checked= false;
	}
else	{
	StaKmNov->Enabled= true;
	}
}
//-------------------------------------
void __fastcall 	TEEpromInit::BuKilepClick(TObject *Sender)
{
Close();
}
//-------------------------------------
void __fastcall 	TEEpromInit::FormKeyPress(TObject *Sender, char &Key)
{
if(Key == VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------


