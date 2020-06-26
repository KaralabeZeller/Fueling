//-----------------------------------------------
//BENZIN SOROS Printer csomag (SEND 256byte block)
//-----------------------------------------------
#include "Bvez2.h"
#include "TextStr.h"
//===============================================Int-35u
uint16_t	PrnTim= 0;				//bitid�
uint16_t	PrnFaz= 0;				//ad�si f�zis
uint16_t	PrnPos= 0;
uint16_t	PrnDb= 0;
void		Txe_Busz_35u(void)			//#56		//104,17us=9k6 (34,72us*3)
{
uint8_t		eki;

if(PrnDb > 0){
	if(PrnTim > 0) PrnTim--;
	else{
		PrnTim= 2; PrnFaz++;						//norm�l id�=3
		eki= Prn.Buf[PrnPos];						//byte bek�sz�t
		switch(PrnFaz){
			case 1:		RS_TXE= 0; break;			//start bit
			case 2:		if(eki&0x01) RS_TXE= 1; else RS_TXE= 0; break;
			case 3:		if(eki&0x02) RS_TXE= 1; else RS_TXE= 0; break;
			case 4:		if(eki&0x04) RS_TXE= 1; else RS_TXE= 0; break;
			case 5:		if(eki&0x08) RS_TXE= 1; else RS_TXE= 0; break;
			case 6:		if(eki&0x10) RS_TXE= 1; else RS_TXE= 0; break;
			case 7:		if(eki&0x20) RS_TXE= 1; else RS_TXE= 0; break;
			case 8:		if(eki&0x40) RS_TXE= 1; else RS_TXE= 0; break;
			case 9:		if(eki&0x80) RS_TXE= 1; else RS_TXE= 0; break;
			case 10:	RS_TXE= 1; break;			//stop1 bit
			default:	PrnFaz= 0; PrnPos++;		//stop2 bit			
						if(PrnPos >= PrnDb){
							PrnDb= 0; PrnPos= 0;
							}
			}
		}
	}
}
//===============================================Alap
uint8_t		Prn_convert(char be)
{
switch(be){
	case '�':	return(0xa0);//;�=0x85
	case '�':	return(0x82);
	case '�':	return(0xa1);
	case '�':	return(0xa2);//;�=0x95
	case '�':	return(0x7c);//;�=0x94
	case '�':	return(0x93);
	case '�':	return(0xa3);//;�=0x97
	case '�':	return(0x7d);//;�=0x81
	case '�':	return(0x96);
	case '�':	return(0x8e);//8f
	case '�':	return(0x90);
	case '�':	return(0xa1);//�
	case '�':	return(0xa2);//�
	case '�':	return(0x5c);
	case '�':	return(0x93);//�
	case '�':	return(0xa3);//�
	case '�':	return(0x5d);
	case '�':	return(0x96);//�
	case '�':	return(0xf8);//�	//;�=0xf8;fc;�
	}
return(be);
}
//-----------------------------------------------Alap
void		Prn_sorkiC(const char *txt, uint8_t konv, uint8_t db)
{
uint8_t		i;

while(PrnDb > 0) ;					//if(m�g ad) v�r
if(db > 34) db= 34;					//max.hossz
for(i=0; i<db; i++){
	if(konv) Prn.Buf[i]= Prn_convert(txt[i]);
 	else	 Prn.Buf[i]= txt[i];
	if(txt[i] == 0) break;
	}
Prn.Buf[i]= 0x0a; Prn.Buf[i+1]= 0;
PrnDb= i+2;
}
//-----------------------------------------------Alap
void		Prn_sorki(uint8_t *txt, uint8_t konv, uint8_t db)
{
uint8_t		i;

while(PrnDb > 0) ;					//if(m�g ad) v�r
if(db > 34) db= 34;					//max.hossz
for(i=0; i<db; i++){
	if(konv) Prn.Buf[i]= Prn_convert(txt[i]);
 	else	 Prn.Buf[i]= txt[i];
	if(txt[i] == 0) break;
	}
Prn.Buf[i]= 0x0a; Prn.Buf[i+1]= 0;
PrnDb= i+2;
}
//-----------------------------------------------Alap
void		_TxtCtoStr(const char *txt)//flashc�m
{
uint8_t		i;
for(i=0; i<34; i++){
	Str[i]= txt[i];
	if(Str[i] == 0) break;
	}
Str[i]= 0;
}
//-----------------------------------------------Alap
void		_Prn_NullaKi(uint8_t *ki, uint8_t db)
{
if((db > 0)&&(ki[0] == '0')){
	ki[0]= ' ';
	if((db > 1)&&(ki[1] == '0')){
		ki[1]= ' ';
		if((db > 2)&&(ki[2] == '0')){
			ki[2]= ' ';
			if((db > 3)&&(ki[3] == '0')){
				ki[3]= ' ';
				if((db > 4)&&(ki[4] == '0')){
					ki[4]= ' ';
					if((db > 5)&&(ki[5] == '0')){
						ki[5]= ' ';
						if((db > 6)&&(ki[6] == '0')){
							ki[6]= ' ';
							if((db > 7)&&(ki[7] == '0')){
								ki[7]= ' ';
								}
							}
						}
					}
				}
			}
		}
	}
}
//===============================================Alap-Nyomtat�s
void		Tank_nyomtat(uint8_t kut)
{
uint16_t	hom;

if(kut >= KUTFO_DB) return;

Prn.Foglalt= 1;
Prn_sorkiC(PrnByteInit, 0, 34);				//printer init
Prn_sorkiC(Prn_Vonal, 0, 34);				//------------------------

if(Ceg0.Nev[0][0] != '!'){
	Prn_sorkiC(Prn_Elado[EE.Nyelv], 1, 34);						//Fejl�c Elad�
	Prn_sorki(Ceg0.Nev[0], 1, 32);								//elad� 1.sor
	if(Ceg0.Nev[1][0] != '!') Prn_sorki(Ceg0.Nev[1], 1, 32);	//elad� 2.sor
	if(Ceg0.Nev[2][0] != '!') Prn_sorki(Ceg0.Nev[2], 1, 32);	//elad� 3.sor
	if(Ceg0.Nev[3][0] != '!') Prn_sorki(Ceg0.Nev[3], 1, 32);	//elad� 4.sor
	if(Ceg0.Nev[4][0] != '!') Prn_sorki(Ceg0.Nev[4], 1, 32);	//elad� 5.sor
	if(Ceg0.Nev[5][0] != '!') Prn_sorki(Ceg0.Nev[5], 1, 32);	//elad� 6.sor
	Prn_sorkiC(Prn_Vonal, 0, 34);			//------------------------
	}

if((Tank[kut].Csoport > 0)&&(Tank[kut].Ceg.Nev[0][0] != '!')){
	Prn_sorkiC(Prn_Vevo[EE.Nyelv], 1, 34);										//Fejl�c Vev�
	Prn_sorki(Tank[kut].Ceg.Nev[0], 1, 32);										//Vev� 1.sor
	if(Tank[kut].Ceg.Nev[1][0] != '!') Prn_sorki(Tank[kut].Ceg.Nev[1], 1, 32);	//Vev� 2.sor
	if(Tank[kut].Ceg.Nev[2][0] != '!') Prn_sorki(Tank[kut].Ceg.Nev[2], 1, 32);	//Vev� 3.sor
	if(Tank[kut].Ceg.Nev[3][0] != '!') Prn_sorki(Tank[kut].Ceg.Nev[3], 1, 32);	//Vev� 4.sor
	if(Tank[kut].Ceg.Nev[4][0] != '!') Prn_sorki(Tank[kut].Ceg.Nev[4], 1, 32);	//Vev� 5.sor
	if(Tank[kut].Ceg.Nev[5][0] != '!') Prn_sorki(Tank[kut].Ceg.Nev[5], 1, 32);	//Vev� 6.sor
	Prn_sorkiC(Prn_Vonal, 0, 34);			//------------------------
	}
//-----------------------------------------------"M�r�s kezdete: 20__.__.__ __:__:__"
_TxtCtoStr(Prn_Kezd[EE.Nyelv]);
if(EE.Nyelv == NYELV_HU){					//---"M�r�s kezdete: 20__.__.__ __:__:__"
	Byte_to_02i(&Str[17], Tank[kut].KezdEv);
	Byte_to_02i(&Str[20], Tank[kut].KezdHo);
	Byte_to_02i(&Str[23], Tank[kut].KezdNap);
	Byte_to_02i(&Str[26], Tank[kut].KezdOra);
	Byte_to_02i(&Str[29], Tank[kut].KezdPerc);
	Byte_to_02i(&Str[32], Tank[kut].KezdMp);
	}
else{										//---"Start meter  : __:__:__ __.__.20__"
	Byte_to_02i(&Str[15], Tank[kut].KezdOra);
	Byte_to_02i(&Str[18], Tank[kut].KezdPerc);
	Byte_to_02i(&Str[21], Tank[kut].KezdMp);
	Byte_to_02i(&Str[24], Tank[kut].KezdNap);
	Byte_to_02i(&Str[27], Tank[kut].KezdHo);
	Byte_to_02i(&Str[32], Tank[kut].KezdEv);
	}
Prn_sorki(Str, 1, 34);
//-----------------------------------------------"M�r�s v�ge   : 20__.__.__ __:__:__"
_TxtCtoStr(Prn_Vege[EE.Nyelv]);
if(EE.Nyelv == NYELV_HU){					//---"M�r�s v�ge   : 20__.__.__ __:__:__"
	Byte_to_02i(&Str[17], Tank[kut].ZarEv);
	Byte_to_02i(&Str[20], Tank[kut].ZarHo);
	Byte_to_02i(&Str[23], Tank[kut].ZarNap);
	Byte_to_02i(&Str[26], Tank[kut].ZarOra);
	Byte_to_02i(&Str[29], Tank[kut].ZarPerc);
	Byte_to_02i(&Str[32], Tank[kut].ZarMp);
	}
else{										//---"End meter    : __:__:__ __.__.20__"
	Byte_to_02i(&Str[15], Tank[kut].ZarOra);
	Byte_to_02i(&Str[18], Tank[kut].ZarPerc);
	Byte_to_02i(&Str[21], Tank[kut].ZarMp);
	Byte_to_02i(&Str[24], Tank[kut].ZarNap);
	Byte_to_02i(&Str[27], Tank[kut].ZarHo);
	Byte_to_02i(&Str[32], Tank[kut].ZarEv);
	}
Prn_sorki(Str, 1, 34);
//-----------------------------------------------"Szem�ly    : ____________________ "
_TxtCtoStr(Prn_Ember[EE.Nyelv]);
MemCpy(&Str[13], Tank[kut].EmberNev, 20);
Prn_sorki(Str, 1, 34);
//-----------------------------------------------"Rendsz�m   : ____________________ "
_TxtCtoStr(Prn_Rendsz[EE.Nyelv]);
MemCpy(&Str[13], Tank[kut].AutoNev, 20);
Prn_sorki(Str, 1, 34);
//-----------------------------------------------"Kilom�ter          :   ________ km"
_TxtCtoStr(Prn_Km[EE.Nyelv]);
Dword_to_08itp(&Str[23], Tank[kut].Km, 0);		//T_KM		4b	(99999999km)
_Prn_NullaKi(&Str[23], 7);
Prn_sorki(Str, 1, 34);
//-----------------------------------------------"�zem�ra            :   ________ � "
_TxtCtoStr(Prn_Uzemora[EE.Nyelv]);
Dword_to_08itp(&Str[23], Tank[kut].Uzemora, 0);	//T_UZEMORA	4b	(99999999)
_Prn_NullaKi(&Str[23], 7);
Prn_sorki(Str, 1, 34);
//-----------------------------------------------"Menetlev�l         :   ________   "
_TxtCtoStr(Prn_Menlev[EE.Nyelv]);
Dword_to_08itp(&Str[23], Tank[kut].Menlev, 0);	//T_MENLEV	4b	(99999999)
_Prn_NullaKi(&Str[23], 7);
Prn_sorki(Str, 1, 34);
//-----------------------------------------------"Kim�r�s sorsz�ma Nr:     _____/_  "
_TxtCtoStr(Prn_Sorszam[EE.Nyelv]);
Word_to_05i(&Str[25], Tank[kut].TankCim);		//sorsz�m
_Prn_NullaKi(&Str[25], 4);
if(kut < 9) Str[31]= '1'+kut;					//(1-9)	T_KUTSZAM	1b	(1-16)
else{		Str[31]= '1'; Str[32]= '0'+kut-9; }	//(10-15)
Prn_sorki(Str, 1, 34);
//-----------------------------------------------"Sz�ml�l� �ll�sa   V:__________,__l"		
_TxtCtoStr(Prn_OszLit[EE.Nyelv]);
Byte_to_02i(&Str[20], Tank[kut].Gorg[0]);		//T_GORG		6b	BCD(9999.999999,99l)
Byte_to_02i(&Str[22], Tank[kut].Gorg[1]);
Byte_to_02i(&Str[24], Tank[kut].Gorg[2]);
Byte_to_02i(&Str[26], Tank[kut].Gorg[3]);
Byte_to_02i(&Str[28], Tank[kut].Gorg[4]);
Byte_to_02i(&Str[31], Tank[kut].Gorg[5]);
_Prn_NullaKi(&Str[20], 9);
Prn_sorki(Str, 1, 34);
//-----------------------------------------------"�sszegezett m�r�sVo:__________,__l"
_TxtCtoStr(Prn_OszKomp[EE.Nyelv]);
Byte_to_02i(&Str[20], Tank[kut].GorgKomp[0]);	//T_GORGKOMP	6b	BCD(9999.999999,99l)
Byte_to_02i(&Str[22], Tank[kut].GorgKomp[1]);
Byte_to_02i(&Str[24], Tank[kut].GorgKomp[2]);
Byte_to_02i(&Str[26], Tank[kut].GorgKomp[3]);
Byte_to_02i(&Str[28], Tank[kut].GorgKomp[4]);
Byte_to_02i(&Str[31], Tank[kut].GorgKomp[5]);
_Prn_NullaKi(&Str[20], 9);
Prn_sorki(Str, 1, 34);
Prn_sorkiC(Prn_Vonal, 0, 34);					//------------------------
//-----------------------------------------------"Kim�rt mennyis�g   Vt: ______,__ l"
_TxtCtoStr(Prn_Liter[EE.Nyelv]);
Dword_to_08itp(&Str[23], Tank[kut].Liter, 2);	//T_LITER	4bBCD	(999999,99l)
_Prn_NullaKi(&Str[23], 5);
Prn_sorki(Str, 1, 34);
//-----------------------------------------------"Term�kh�m�rs�klet   t:    ___,_ �C"
_TxtCtoStr(Prn_Hom[EE.Nyelv]);
if(Tank[kut].KutHom < 400){						//T_HOMER	2b	w256(0x0000-0x07ff)(-40.0-+164.8)
	hom= 400-Tank[kut].KutHom;
	Word_to_05i(&Str[25], hom);
	Str[25]= '-';
	}
else{
	hom= Tank[kut].KutHom-400;
	Word_to_05i(&Str[25], hom);
	Str[25]= ' ';
	}
Str[30]= Str[29]; Str[29]= ',';
_Prn_NullaKi(&Str[26], 2);
Prn_sorki(Str, 1, 34);
//-----------------------------------------------
Prn_sorkiC(Prn_Megnev[EE.Nyelv], 1, 34);
if((EE.KutStat[kut]&0x02) == 0)	Prn_sorkiC(Prn_MegnevG[EE.Nyelv], 1, 34);
else							Prn_sorkiC(Prn_MegnevB[EE.Nyelv], 1, 34);
//-----------------------------------------------
Prn_sorkiC(Prn_BazisHo[EE.Nyelv], 1, 34);
//-----------------------------------------------"Mennyis�g to-�n    Vo: ______,__ l"
_TxtCtoStr(Prn_LitKomp[EE.Nyelv]);
Dword_to_08itp(&Str[23], Tank[kut].LitKomp, 2);	//T_LITKOMP	4bBCD	(999999,99l)
_Prn_NullaKi(&Str[23], 5);
Prn_sorki(Str, 1, 34);

if(Tank[kut].EgysArNto > 0){
	Prn_sorkiC(Prn_Vonal, 0, 34);					//------------------------
//-----------------------------------------------"Egys�g�r (netto):    0000,00 Ft/l"
	_TxtCtoStr(Prn_ArAlap[EE.Nyelv]);
	Dword_to_10i2(&Str[17], (uint32_t)Tank[kut].EgysArNto);	_Prn_NullaKi(&Str[17], 7);
	Prn_sorki(Str, 1, 34);
//-----------------------------------------------"�r (netto)      :  000000,00 Ft"
	_TxtCtoStr(Prn_ArNetto[EE.Nyelv]);
	Dword_to_10i2(&Str[17], Tank[kut].ArNetto);	_Prn_NullaKi(&Str[17], 7);
	Prn_sorki(Str, 1, 34);
//-----------------------------------------------"�r (brutto)     :  000000,00 Ft"
	_TxtCtoStr(Prn_ArBrutto[EE.Nyelv]);
	Dword_to_10i2(&Str[17], Tank[kut].ArBrutto);	_Prn_NullaKi(&Str[17], 7);
	Prn_sorki(Str, 1, 34);
	}
//-----------------------------------------------Hib�s befejez�s
if((Tank[kut].Hibakod < STA_STOP_LIM)||(Tank[kut].Hibakod > STA_STOP_IDO)){
	Prn_sorkiC(Prn_Vonal, 0, 34);					//------------------------
	Prn_sorkiC(Prn_RosszBiz[EE.Nyelv], 1, 34);
	Prn_sorkiC(Prn_Jelezze[EE.Nyelv], 1, 34);
	}
//-----------------------------------------------
Prn_sorkiC(Prn_Vonal, 0, 34);						//------------------------
Prn_sorkiC(PrnByteClose, 0, 34);					//lez�r�s+v�g�s
Prn.Foglalt= 0;
}
//===============================================END
