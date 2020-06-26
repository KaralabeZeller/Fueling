//-----------------------------------------------
// K�rtya bevitel k�perny�
//-----------------------------------------------
#include "Bvez2.h"
#include "Lcd.h"
#include "TextStr.h"
#include "GyorsGra.h"
//===============================================Alap
void	ScrA3_kirak(void)
{
uint8	kut= Mnu.Kut; if(kut >= KUTFO_DB) return;

Mnu.Num= MENU_A3;
Mnu.Villog= 0;
Lcd_Clear();
Mnu.AlFaz= 0;

if(EE.Vez&B_VEZ_CARD2)	SzovKi(&ScrA3_Card2);
else					SzovKi(&ScrA3_Card1);
SzovKi(&ScrA3_Nev);
SzovKi(&ScrA3_Jarmu);
SzovKi(&TxtVISSZA);
SzovKi(&ScrA3_Kutfo);

if(kut < 9) { G_Kar1_Ki(1, 1, ' '); G_Kar1_Ki(10, 1, kut+'1'); }	//egy sz�m
else		{ G_Kar1_Ki(1, 1, '1'); G_Kar1_Ki(10, 1, kut-9+'0'); }	//k�t sz�m

if(Kut[kut].Jel&JEL_KOMP){
	Byte_to_02i(&Str[ 0], Kut[kut].GorgKomp[0]);//T_GORGKOMP 6b BCD(9999.999999,99l)
	Byte_to_02i(&Str[ 2], Kut[kut].GorgKomp[1]);
	Byte_to_02i(&Str[ 4], Kut[kut].GorgKomp[2]);
	Byte_to_02i(&Str[ 6], Kut[kut].GorgKomp[3]);
	Byte_to_02i(&Str[ 8], Kut[kut].GorgKomp[4]);
	Byte_to_02i(&Str[11], Kut[kut].GorgKomp[5]);
	}
else{
	Byte_to_02i(&Str[ 0], Kut[kut].Gorg[0]);	//T_GORG 6b BCD(9999.999999,99l)
	Byte_to_02i(&Str[ 2], Kut[kut].Gorg[1]);
	Byte_to_02i(&Str[ 4], Kut[kut].Gorg[2]);
	Byte_to_02i(&Str[ 6], Kut[kut].Gorg[3]);
	Byte_to_02i(&Str[ 8], Kut[kut].Gorg[4]);
	Byte_to_02i(&Str[11], Kut[kut].Gorg[5]);
	}
Str[10]= '.'; Str[13]= 0; OutStr1(13, 120, 1);

if(Mnu.CardVan&VAN_SOFOR)	CardNev_to_LCD(Tank[kut].EmberNev, 63, 28);
if(Mnu.CardVan&VAN_AUTO)	CardNev_to_LCD(Tank[kut].AutoNev, 63, 40);
}
//-----------------------------------------------Alap
void	ScrA3_Bevitel(void)
{
uint16	x;
uint8	kut= Mnu.Kut;//0-14

if(kut >= KUTFO_DB) return;
Tank[kut].Km= 0;
Tank[kut].Menlev= 0;
Tank[kut].Uzemora= 0;

//if(Mnu.MESTER){
//	ScrA8_kiFel();//***				//if(MESTER)	Mester km bek�r�s
//SrcA3_Tovabb:					;Scr8-r�l vissza
//	}

switch(kut){					//melyik k�tf�(0-15)
	case 0:		x= 0x0001; break;
	case 1:		x= 0x0002; break;
	case 2:		x= 0x0004; break;
	case 3:		x= 0x0008; break;
	case 4:		x= 0x0010; break;
	case 5:		x= 0x0020; break;
	case 6:		x= 0x0040; break;
	case 7:		x= 0x0080; break;
	case 8:		x= 0x0100; break;
	case 9:		x= 0x0200; break;
	case 10:	x= 0x0400; break;
	case 11:	x= 0x0800; break;
	case 12:	x= 0x1000; break;
	case 13:	x= 0x2000; break;
	case 14:	x= 0x4000; break;
	default:	x= 0x8000; break;
	}	
if((Mnu.Kutak & x) == 0)			//k�tf� bitmap (0=tiltva, 1=engeve)
	ScrH3_kirak();					//adott k�tf�re nem j� a k�rtya
else{
	if		(EE.Vez&B_VEZ_KMBE)		ScrA4_kirak(0);		//Km bek�r�s
	else if	(EE.Vez&B_VEZ_MENLEV)	ScrA5_kirak(0);		//Menetlev�l bek�r�s
	else if	(EE.Vez&B_VEZ_UZEMORA)	ScrA7_kirak(0);		//�zem�ra bek�r�s
	else if	(EE.Vez2&B_VEZ2_MAXSTOP)ScrAstop_kirak(0);	//maxLitStop
	else							ScrA6_kirak();		//Tankol�s
	}
}
//-----------------------------------------------
void	Card_Max_kozos(void)
{
if(Card.MaxLit < Mnu.MaxLiter)	Mnu.MaxLiter= Card.MaxLit;
SzovKi(&ScrA3_Ures);
}
//-----------------------------------------------
void	Sofor_Card(void)
{
uint8	kut= Mnu.Kut;	//0-14
if(kut >= KUTFO_DB) return;

Mnu.CardVan|= VAN_SOFOR;						//SoforReady=1
if((EE.Vez&B_VEZ_CARD2)==0) Mnu.CardVan|= VAN_AUTO;//egyk�rty�s

MemCpy(Tank[kut].EmberId, Card.Id, 7);
Tank[kut].EmberNum= Card.Num;
MemCpy(Tank[kut].EmberNev, Card.Nev, 20);
CardNev_to_LCD(Tank[kut].EmberNev, 63, 28);
Mnu.MaxDbEmber= Card.MaxDb;
Mnu.TankDbE= Fls_TankDb(kut, 'E');			//mai tankol�sok sz�ma
Mnu.Kutak&= Card.Kutak;						//csak ha mindkett�n�l j�
Card_Max_kozos();
}
//-----------------------------------------------
void	Jarmu_Card(void)
{
uint8	kut= Mnu.Kut;	//0-14
if(kut >= KUTFO_DB) return;

Mnu.CardVan|= VAN_AUTO;						//JarmuReady=1
if((EE.Vez&B_VEZ_CARD2)==0) Mnu.CardVan|= VAN_SOFOR;//egyk�rty�s

MemCpy(Tank[kut].AutoId, Card.Id, 7);
Tank[kut].AutoNum= Card.Num;
MemCpy(Tank[kut].AutoNev, Card.Nev, 20);
CardNev_to_LCD(Tank[kut].AutoNev, 63, 40);
Tank[kut].Csoport= Card.Csoport;
Mnu.MaxDbAuto= Card.MaxDb;
Mnu.TankDbA= Fls_TankDb(kut, 'A');			//mai tankol�sok sz�ma
Mnu.Print= Card.Print;
Fls_CegTolt(&Ceg0, 0);						//saj�t keres
Fls_CegTolt(&Tank[kut].Ceg, Tank[kut].Csoport);
Fls_ArakTolt(&Arak0, Tank[kut].Csoport);
Tank[kut].Ar0Netto= Arak0.Ar0Netto;
Tank[kut].Ar1Netto= Arak0.Ar1Netto;
Mnu.Kutak&= Card.Kutak;						//csak ha mindkett�n�l j�
Fls_ArakTolt(&Arak0, 0);
}
//-----------------------------------------------
void	Mester_Card(void)
{
uint8	kut= Mnu.Kut;	//0-14
if(kut >= KUTFO_DB) return;

if((EE.Vez&B_VEZ_CARD2) == 0){				//egyk�rty�sn�l mindkett�
	Mnu.CardVan|= VAN_SOFOR+VAN_AUTO;

	MemCpy(Tank[kut].AutoId, Card.Id, 7);		//if(nem volt aut�)CardNum=Mester
	Tank[kut].AutoNum= Card.Num;				//alapba felt�lti a mesterrel
	MemCpy(Tank[kut].AutoNev, Card.Nev, 20);
	Tank[kut].Csoport= Card.Csoport;
	CardNev_to_LCD(Tank[kut].AutoNev, 63, 40);

	MemCpy(Tank[kut].EmberId, Card.Id,7);
	Tank[kut].EmberNum= Card.Num;
	MemCpy(Tank[kut].EmberNev, Card.Nev, 20);
	CardNev_to_LCD(Tank[kut].EmberNev, 63, 28);
	}
else{
	if((Mnu.CardVan&VAN_SOFOR) == 0){		//sof�r k�rtya nem volt
		Mnu.CardVan|= VAN_SOFOR;

		MemCpy(Tank[kut].EmberId, Card.Id, 7);
		Tank[kut].EmberNum= Card.Num;
		MemCpy(Tank[kut].EmberNev, Card.Nev, 20);
		CardNev_to_LCD(Tank[kut].EmberNev, 63, 28);
		}
	else{									//sof�r volt
		Mnu.CardVan|= VAN_AUTO;

		MemCpy(Tank[kut].AutoId,Card.Id, 7);	//if(nem volt aut�)CardNum=Mester
		Tank[kut].AutoNum= Card.Num;			//alapba felt�lti a mesterrel
		MemCpy(Tank[kut].AutoNev, Card.Nev, 20);
		Tank[kut].Csoport= Card.Csoport;
		CardNev_to_LCD(Tank[kut].AutoNev, 63, 40);
		}
	}

if(Card.MaxLit < Mnu.MaxLiter)	Mnu.MaxLiter= Card.MaxLit;
Mnu.MaxDbAuto= Card.MaxDb;
Mnu.MaxDbEmber= Card.MaxDb;
SzovKi(&ScrA3_Ures);
}
//-----------------------------------------------
void	Card_Hibas(void)
{
Mnu.Back= MENU_A3;
ScrH1_kirak();						//K�rtya hiba
//SzovKi(&ScrA3_Hiba);
}
//-----------------------------------------------
void	Card_Valaszt(void)
{
switch(Card.Tip){
	case CRD_SOFOR:		Sofor_Card(); break;//A k�rtya tipusa szerint
	case CRD_JARMU: 	Jarmu_Card(); break;
	case CRD_MESTER:	Mester_Card(); break;
	case CRD_SZERVIZ:	ScrS2_kirak(); break;//Szerviz f�men�
	default:			Card_Hibas(); break;
	}
}
//-----------------------------------------------Alap
void	ScrA3_PinBe(uint8 gmb)
{
if(gmb == GOMB_TOR){
	if(Mnu.AlFaz > 0)	Mnu.AlFaz--;	//eggyel vissza
	else				ScrA1_kirak();	//faz=0-> pin k�d nem j�
	}
else if(gmb < 10){
	switch(Mnu.AlFaz){
		case 1:		Mnu.Pin= (uint16_t)gmb; break;
		default:	Mnu.Pin= Mnu.Pin*16+(uint16_t)gmb; break;
		}
	Mnu.AlFaz++;
	}	
switch(Mnu.AlFaz){						//kijelz�s
	case 1:	SzovKi(&ScrA3_Pin0); break;	//PIN0
	case 2: SzovKi(&ScrA3_Pin1); break;	//PIN1
	case 3:	SzovKi(&ScrA3_Pin2); break;	//PIN2
	case 4:	SzovKi(&ScrA3_Pin3); break;	//PIN3
	default:if(Mnu.Pin != Card.Pin){	//PIN4
				Mnu.Pin= 0; ScrA1_kirak();//rossz pin
				}
			else{
				SzovKi(&ScrA3_Pin4);
				Card_Valaszt();
				}
			Mnu.AlFaz= 0;
			break;
	}
}
//-----------------------------------------------Alap
void		Card_Wait(void)	//<-ScrA3
{
uint8		kut= Mnu.Kut;	//0-14

if(Card_Vesz() == 0){									//k�rtyaolvas� olvas
	if(Card_SearchId() == 0){							//->1=nincs,2=chk error,0=OK->Card-ba bet�ltve
		if((Card.Pin == 0xffff)||(Card.Pin == 0x0000)){
			Card_Valaszt();
			}
		else{ Mnu.Pin= 0; Mnu.AlFaz= 1; }				//pinbek�r�s start
		}
	}
else{
	if(kut >= KUTFO_DB) return;
	if((EE.Pisztoly1 == (kut+1))&&(Card.PiVan == 1)){	//gyurus pisztoly k�d megj�tt
		MemCpy(Card.Id,Card.PiDec,5);
		if(Card_SearchId() == 0){						//->1=nincs,2=chk error,0=OK->Card-ba bet�ltve
			if((Card.Pin == 0xffff)||(Card.Pin == 0x0000)){
				if(Card.Tip == CRD_JARMU){				//csak aut�
					Kut[kut].Pisztoly=1;
					Card_Valaszt();
					}
				}
			else{ Mnu.Pin=0; Mnu.AlFaz=1; }				//pinbek�r�s start
			}
		}
	}
}
//===============================================Alap
void	ScrA3_esemeny(void)
{
uint8		g= M.Gomb;

M.Gomb= GOMB_NO;										//t�r�l
if(Mnu.AlFaz != 0)	ScrA3_PinBe(g);
else{
	if(g ==	GOMB_TOR){ ScrA1_kirak(); return; }		//F�men�
	if((EE.Vez&B_VEZ_EMKOD)&&((Mnu.CardVan&VAN_SOFOR) == 0)){//Ember k�d bevitel
		SzovKi(&ScrA3_Ember);
		if(g ==	GOMB_BE)	ScrA9_kirak(0);
		else				Card_Wait();
		}
	else if(Mnu.CardVan < (VAN_SOFOR+VAN_AUTO)) Card_Wait();
	else{
		SzovKi(&TxtRENDBEN);
		if(g ==	GOMB_BE) ScrA3_Bevitel();
		}
	}
}
//===============================================END
