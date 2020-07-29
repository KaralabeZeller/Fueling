//===============================================
// BVEZ2 vezérlõ TIMER INTERRUPT
//===============================================
#include "Bvez2.h"
#include "SorosMod232.h"
#include "SorosModNet.h"
#include "OraKorr.h"
#include "Sflash16M.h"
//-----------------------------------------------
uint16_t	InputBeFazis= 0;						//0-4 gombolvasásá fázisok 1ms-onként
uint16_t	GombI[12]= {0,0,0,0,0,0,0,0,0,0,0,0};	//Gombok integrátorai
uint16_t	GombOld= 0;								//Gombok elõzõ állapot
//-----------------------------------------------Int-1ms
void		GombSzur(int num, uint8_t level, uint16_t minta)
{
if(level == 0){									//LO
	if(GombI[num] > 0) GombI[num]--;			//csökken, nincs változás
	else M.GombBe&= (~minta);					//nullán van
	}
else{											//HI
	if(GombI[num] < GOMB_PRELL)	GombI[num]++;	//növkszik, nincs változás
	else M.GombBe|= minta;						//maxon van
	}
}
//-----------------------------------------------Int-5ms
void		Gomb_Ert_5ms(void)
{
uint16_t gmb, gombLH;

gombLH= M.GombBe^GombOld;						//változott
gombLH&= M.GombBe;								//H-ra változott
GombOld= M.GombBe;
if(gombLH > 0){									//csak az utolsó gombnyomást tárolja
	if(M.SpkTim == 0) M.SpkTim= GOMB_BEEP_TIME;	//pitty
	gmb= GOMB_NO;								//12 ha nincs nyomva
	if(gombLH & G_0) gmb= 0;
	if(gombLH & G_1) gmb= 1;
	if(gombLH & G_2) gmb= 2;
	if(gombLH & G_3) gmb= 3;
	if(gombLH & G_4) gmb= 4;
	if(gombLH & G_5) gmb= 5;
	if(gombLH & G_6) gmb= 6;
	if(gombLH & G_7) gmb= 7;
	if(gombLH & G_8) gmb= 8;
	if(gombLH & G_9) gmb= 9;
	if(gombLH & G_BAL) gmb= GOMB_TOR;
	if(gombLH & G_JOBB) gmb= GOMB_BE;
	M.Gomb2= M.Gomb; M.Gomb= gmb;					//shift
	M.Gomb2Time= GOMB2_TIMEOUT;
	}
}
//-----------------------------------------------Int-1ms
void		Input_Be_1ms(void)
{
uint8_t		be;

switch(InputBeFazis){
	case 0:
		GOMB_KI1= 0;
		GOMB_KI2= 1;
		GOMB_KI3= 1;					//1.sor beállít
		break;
	case 1:
		be= GOMB_BEPORT;				//1. sor olvas
		be= be^0x1e;					//H->L
		M.InputBe= (M.InputBe&0x0ff0)|((be>>1)&0x0f);
		GombSzur(0, be&0x02, G_BAL);
		GombSzur(1, be&0x04, G_7);
		GombSzur(2, be&0x08, G_4);
		GombSzur(3, be&0x10, G_1);
		GOMB_KI1= 1;
		GOMB_KI2= 0;
		GOMB_KI3= 1;					//2.sor beállít
		break;
	case 2:
		be= GOMB_BEPORT;				//2.sor olvas
		be= be^0x1e;					//H->L
		M.InputBe= (M.InputBe&0x0f0f)|(((be>>1)&0x0f)<<4);
		GombSzur(4, be&0x02, G_0);
		GombSzur(5, be&0x04, G_8);
		GombSzur(6, be&0x08, G_5);
		GombSzur(7, be&0x10, G_2);
		GOMB_KI1= 1;
		GOMB_KI2= 1;
		GOMB_KI3= 0;					//3.sor beállít
		break;
	case 3:
		be= GOMB_BEPORT;				//3.sor olvas
		be= be^0x1e;					//H->L
		M.InputBe= (M.InputBe&0x00ff)|(((be>>1)&0x0f)<<8);
		GombSzur(8, be&0x02, G_JOBB);
		GombSzur(9, be&0x04, G_9);
		GombSzur(10, be&0x08, G_6);
		GombSzur(11, be&0x10, G_3);
		GOMB_KI1= 1;
		GOMB_KI2= 1;
		GOMB_KI3= 1;					//kikapcs.sor
		break;
	case 4:
		Gomb_Ert_5ms();
		break;
	}	
InputBeFazis++; if(InputBeFazis > 4) InputBeFazis= 0;//0-4
}
//===============================================Int-150ms
void		Kut_Check_150ms(void)			//NetKerdez_150() után
{
uint8_t		i, be= 0;

for(i=0; i<KUTFO_DB; i++){							//0-14 összes kút
	if(Kut[i].Stat <= STA_TANK_BE){					//csak amíg vége nincs
		if(Kut[i].Liter != Kut[i].LiterOld){
			Kut[i].LiterOld= Kut[i].Liter;			//követ
			Kut[i].TimeOut= KUT_TIMEOUT;			//folyik a lé
			}
		else{										//nincs változás
			if(Kut[i].TimeOut > 0) Kut[i].TimeOut--;//nem folyik
			}
		}

	if(Kut[i].Pisztoly == 1){						//ezen a kúton van a fej1
		if(Card.PiTim100m  < PISZT_TIMEOUT){		//baj van vagy elvették de még vár
			be= 1;
			if(Card.PiVan == 1){					//nem nulla
				if(MemCmp(Card.PiDec,Tank[i].AutoId,5) != 0) be= 0; //nem azonos kártya kód
				}
			}
		if(be == 1)	{ if(Kut[i].Parancs == STA_TANK_KI) Kut[i].Parancs= STA_TANK_BE; }
		else		{ if(Kut[i].Parancs == STA_TANK_BE) Kut[i].Parancs= STA_TANK_KI; }
		}
	}
}
//===============================================Int-150ms
// a litert elmenti a megfelelõ tankolásrekordba és beírja a Flash-be
void		Kut_Mentes_1m(uint16_t kut, uint16_t vesz)
{								
uint8_t		*ki;
uint8_t		i, stat;
uint16_t	sum;
uint32_t	dw;

if(kut >= KUTFO_DB) return;							//0..14
if((EE.KutStat[kut]&0x04) != 0) return;				//virtuális kútfo - nincs mentés

stat= Kut[kut].Stat;
if((vesz == 0)&&(Kut[kut].TimeOut > 0)&&(stat < STA_STOP_LIM)) return;//nem vész + nem timeout + még tankol

Kut[kut].Limit= 0; Kut[kut].Parancs= STA_ALAP_FENT;	//kikapcs

if(Tank[kut].Mentes != MENT_OK_1) return;			//megvár az elsõ mentés, és csak egyszer megy

Tank[kut].ZarEv=		Ora.Ev;						//zárási idõ
Tank[kut].ZarHo=		Ora.Ho;
Tank[kut].ZarNap=		Ora.Nap;
Tank[kut].ZarOra=		Ora.Ora;
Tank[kut].ZarPerc=		Ora.Perc;
Tank[kut].ZarMp=		Ora.Mp;

Tank[kut].LitKomp=		Kut[kut].LitKomp;			//(999.999,99l) [0-42.949.672,96]
Tank[kut].Liter=		Kut[kut].Liter;				//(999.999,99l)
Tank[kut].KutHom=		Kut[kut].Hom;

if(Kut[kut].TimeOut == 0){							//timeout van
	if(stat < STA_TANK_KI){							//nem volt tankolás megkezdés
		Tank[kut].LitKomp= 0;
		Tank[kut].Liter= 0;
		}
	}

if(Tank[kut].EgysArNto == 0){
	Tank[kut].ArNetto= 0;
	Tank[kut].ArBrutto= 0;
	}
else{
	dw= WmulWtoDW(Tank[kut].EgysArNto, Tank[kut].LitKomp);//16b*10000
	if((dw%100) > 49) dw+= 50;						//kerekítés
	dw/= 100;
	if(dw > AR_MAX) dw= AR_MAX;						//kijelzési túlcsordulás
	Tank[kut].ArNetto= dw;

	dw*= 127;
	if((dw%100) > 49) dw+= 50;						//kerekítés
	dw/= 100;
	if(dw > AR_MAX) dw= AR_MAX;						//kijelzési túlcsordulás
	Tank[kut].ArBrutto= dw;
	}
//-----
Tank[kut].Hibakod= stat;

Tank[kut].NyomtatDb= 0;								//0. példány
if		(EE.PrnDb == 1)	Tank[kut].NyomtatDb= 1;		//1. példány
else if	(EE.PrnDb == 2)	Tank[kut].NyomtatDb= 2;		//2. példány
else if (EE.PrnDb == 9)	{
	switch(Tank[kut].Print){						//autó kártyáról
		case 1:	Tank[kut].NyomtatDb= 1; break;
		case 2:	Tank[kut].NyomtatDb= 2; break;
		}
	}

ki= (uint8_t*)(&Tank[kut].KezdVerz);
for(i=0,sum=0; i<126; i++) sum+= ki[i];
Tank[kut].Sum= sum;								//checksumma
Tank[kut].Mentes= MENT_STR2;						//második mentés start

Kut[kut].UtoTime= EE.MnuUtoTime;

if(Tank[kut].NyomtatDb > 0){
	Tank[kut].Nyomtat= Tank[kut].NyomtatDb;		//start nyomtatás
	}
}
//-----------------------------------------------Alap
//Vészmentés - elvégzi a tankolásrekord teljes kitöltését és elmentését
void	Kut_VeszMent(void)
{
uint8_t		k;

for(k=0; k<15; k++){
	Kut[k].Limit= 0; Kut[k].Parancs= STA_ALAP_FENT;	//vész-stop
	}
for(k=0; k<15; k++)	Kut_Mentes_1m(k, 1);
}
//===============================================Int-1ms
uint8_t		Sys1ms= 0;							//1ms system timer
uint8_t		Sys100ms= 0;
uint8_t		Sys150ms= 0;
//-----------------
void	RealTime1ms(void)
{
uint8_t		k;

asm("clrwdt");
Soros_232_1ms();							//RS232-PC

if(LedHibaTime > 0)	{ LedHibaTime--; LED_HIBA= 1; }	else{ LED_HIBA= 0; }	
if(LedProcTime > 0)	{ LedProcTime--; LED_PROC= 1; }	else{ LED_PROC= 0; }	
if(LedVezTime > 0)	{ LedVezTime--;	LED_VEZ= 1; }	else{ LED_VEZ= 0; }	
if(M.SpkTim > 0)	M.SpkTim--;

Input_Be_1ms();
MeresSzamol_1ms();
Szint_Ciklus_1ms();

Sys150ms++;
if(Sys150ms > 149){		//150ms
	Sys150ms= 0;
	NetKerdez_150ms();
	Kut_Check_150ms();
	}

for(k=0; k<15; k++)	Kut_Mentes_1m(k, 0);	//mindenképp megy, mert ha vár gyorsan kell ismételni
//-----------------------------------------------100ms
Sys1ms++; if(Sys1ms > 99){ Sys1ms= 0;
	SYS_A100MS= 1; 							//Alapnak jelzés

	if(M.Gomb2Time > 0) M.Gomb2Time--;
	if(Card.RxTim100m < CARD_TIMEOUT)	Card.RxTim100m++;
	if(Card.PiTim100m < PISZT_TIMEOUT)	Card.PiTim100m++;
	//-------------------------------------------1s
	Sys100ms++; if(Sys100ms > 9){ Sys100ms= 0;
		if(Mnu.Timeout > 0) Mnu.Timeout--;
		for(k=0; k<15; k++){
			if((Kut[k].Parancs == STA_ALAP_FENT)&&(Kut[k].UtoTime > 0)) Kut[k].UtoTime--;
	
			Kut[k].sebes[6]= Kut[k].sebes[5];
			Kut[k].sebes[5]= Kut[k].sebes[4];
			Kut[k].sebes[4]= Kut[k].sebes[3];
			Kut[k].sebes[3]= Kut[k].sebes[2];
			Kut[k].sebes[2]= Kut[k].sebes[1];
			Kut[k].sebes[1]= Kut[k].sebes[0];
			Kut[k].sebes[0]= Kut[k].Liter;
			}
		}
	}
}
//=========================================================AD1-mérések belsõ változói
uint16_t	MerFaz=	0;				//Mérés fázis (0-20)=2ms
uint16_t	MerMs=	0;				//mérési idõzítõ
uint16_t	MerMa1=	0;
uint16_t	MerMa2=	0;
uint16_t	MerPt1=	0;
uint16_t	MerPt2=	0;
uint16_t	MerHom1= 0;
uint16_t	MerHom2= 0;
uint16_t	MerU11=	0;
uint16_t	MerU10=	0;
uint16_t	MerU8=	0;
uint16_t	MerU5=	0;
uint16_t	MerU3=	0;
uint16_t	MerUhat= 0;
uint16_t	MerUm15= 0;
uint16_t	MerUee=	0;
uint16_t	U10[4]= {0, 0, 0, 0};
//---------------------------------------------------------Int-100us
void		Meres_100u(void)
{
uint16_t	w;
uint32_t	dw;

if(AD1CON1bits.DONE == 0) M.AdHibaNemkesz++;
else{
	w= ADC1BUF0&0x0fff;
	switch(MerFaz){
		case 0:						AD1CHS0= ANA_MA1; break;
		case 1:		MerMa1+=	w;	AD1CHS0= ANA_MA2; break;
		case 2:		MerMa2+=	w;	AD1CHS0= ANA_PT100_1; break;
		case 3:		MerPt1+=	w;	AD1CHS0= ANA_PT100_2; break;
		case 4:		MerPt2+=	w;	AD1CHS0= ANA_HOM1; break;
		case 5:		MerHom1+=	w;	AD1CHS0= ANA_HOM2; break;
		case 6:		MerHom2+=	w;	AD1CHS0= ANA_U11; break;
		case 7:		MerU11+=	w;	AD1CHS0= ANA_U10; break;
		case 8:		MerU10+=	w;	AD1CHS0= ANA_U8; break;
		case 9:		MerU8+=		w;	AD1CHS0= ANA_U5; break;
		case 10:	MerU5+=		w;	AD1CHS0= ANA_U3; break;
		case 11:	MerU3+=		w;	AD1CHS0= ANA_UHAT; break;
		case 12:	MerUhat+=	w;	AD1CHS0= ANA_UM15; break;
		case 13:	MerUm15+=	w;	AD1CHS0= ANA_UEE; break;
		case 14:	MerUee+=	w; break;
		case 15:	MerMs++;							//2ms
					if(MerMs > 10){ MerMs= 0;			//20ms-onként
						U10[3]= U10[2]; U10[2]= U10[1]; U10[1]= U10[0]; U10[0]= MerU10/4;//80ms
						M.Mer10U10=		MerU10;		MerU10=		0;
						M.Mer10Ma1=		MerMa1;		MerMa1=		0;
						M.Mer10Ma2=		MerMa2;		MerMa2=		0;
						M.Mer10Ma3=		MerPt1;		MerPt1=		0;
						M.Mer10Ma4=		MerPt2;		MerPt2=		0;
						M.Mer10Hom1=	MerHom1;	MerHom1=	0;
						M.Mer10Hom2=	MerHom2;	MerHom2=	0;
						M.Mer10U11=		MerU11;		MerU11=		0;
						M.Mer10U8=		MerU8;		MerU8=		0;
						M.Mer10U5=		MerU5;		MerU5=		0;
						M.Mer10U3=		MerU3;		MerU3=		0;
						M.Mer10Uhat=	MerUhat;	MerUhat=	0;
						M.Mer10Um15=	MerUm15;	MerUm15=	0;
						M.Mer10Uee=		MerUee;		MerUee=		0;

						w= U10[0]+U10[1]+U10[2]+U10[3];	//4096*10/4=10240
						dw= WmulWtoDW(w, EE.SzorU11*32);//32*255=8160
						w= hw(dw);
						if(w > 3000) w= 3000;			//30V
						M.U10= w;

						if(M.U10 > 800)	{ LCD_HATTER= 1; }//if(UM1 > 8V)HáttérBe
						else			{ LCD_HATTER= 0; Kut_VeszMent(); }//megáll
						}	
					break;
		}
	MerFaz++; if(MerFaz > 19) MerFaz= 0;				//2ms
	}	
AD1CON1bits.SAMP= 1;									//start
}
//---------------------------------------------------------Int-1ms
void		MeresSzamol_1ms(void)
{
uint16_t	w;
uint32_t	dw;

M.IntMa1= M.IntMa1-M.IntMa1/8+M.Mer10Ma1/8;	//4096*10/8=5120*8=40960
dw= WmulWtoDW(M.IntMa1, EE.SzorMa1); w= hw(dw);	//40960*SZOR/65536
if(w > 65000) w= 65000;
if(w > EE.NullMa1) w-= EE.NullMa1; else w= 0;
M.UMa1= w; M.Ma1= M.UMa1;

M.IntMa2= M.IntMa2-M.IntMa2/8+M.Mer10Ma2/8;
dw= WmulWtoDW(M.IntMa2, EE.SzorMa2); w= hw(dw);
if(w > 65000) w= 65000;
if(w > EE.NullMa2) w-= EE.NullMa2; else w= 0;
M.UMa2= w; M.Ma2= M.UMa2;

M.IntMa3= M.IntMa3-M.IntMa3/8+M.Mer10Ma3/8;
dw= WmulWtoDW(M.IntMa3, EE.SzorMa3); w= hw(dw);
if(w > 65000) w= 65000;
if(w > EE.NullMa3) w-= EE.NullMa3; else w= 0;
M.UMa3= w; M.Ma3= M.UMa3;

M.IntMa4= M.IntMa4-M.IntMa4/8+M.Mer10Ma4/8;
dw= WmulWtoDW(M.IntMa4, EE.SzorMa4); w= hw(dw);
if(w > 65000) w= 65000;
if(w > EE.NullMa4) w-= EE.NullMa4; else w= 0;
M.UMa4= w; M.Ma4= M.UMa4;

//M.IntHom1= M.IntHom1-M.IntHom1/8+M.Mer10Hom1/8;
//li= M.IntHom1; li= (li*MUL_HOM1)/32000; if(li > 65000) li= 65000;
//M.UHom1= (uint16_t)li;

//M.IntHom2= M.IntHom2-M.IntHom2/8+M.Mer10Hom2/8;
//li=M.IntHom2; li= (li*MUL_HOM2)/32000; if(li > 65000) li= 65000;
//M.UHom2= (uint16_t)li;

M.IntU11= M.IntU11-M.IntU11/4+M.Mer10U11/4;	//12+2bit
dw= WmulWtoDW(M.IntU11, EE.SzorU11*32);		//32*255=8160
w= hw(dw); if(w > 3000) w= 3000;			//30V
M.U11= w;
}
//=========================================================END
