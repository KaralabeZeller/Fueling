//---------------------------------------------------------
// BENZIN vezérlõ Kártya olvasó
//---------------------------------------------------------
#include "Bvez2.h"
//=========================================================Int-35u
void		Rxf_Busz_35u(void)	//kártya1	//#66-1,5us		//104,17us=9k6 (34,72us*3)
{
uint16_t	fki;
uint8_t		be;

if(Rxf.Tim > 0) Rxf.Tim--;				//#10
else{
	if(Card.TxDb > 0){									//van adandó
		Rxf.Tim= 2; Rxf.Faz++;			//# 8			//normál idõ=3
		fki= Card.TxBuf[Card.TxPos];	//#12			//következõ byte bekészít
		switch(Rxf.Faz){				//#28
			case 1:		RS_TXF= 0; break;				//start bit
			case 2:		if(fki&0x01) RS_TXF= 1; else RS_TXF= 0; break;
			case 3:		if(fki&0x02) RS_TXF= 1; else RS_TXF= 0; break;
			case 4:		if(fki&0x04) RS_TXF= 1; else RS_TXF= 0; break;
			case 5:		if(fki&0x08) RS_TXF= 1; else RS_TXF= 0; break;
			case 6:		if(fki&0x10) RS_TXF= 1; else RS_TXF= 0; break;
			case 7:		if(fki&0x20) RS_TXF= 1; else RS_TXF= 0; break;
			case 8:		if(fki&0x40) RS_TXF= 1; else RS_TXF= 0; break;
			case 9:		if(fki&0x80) RS_TXF= 1; else RS_TXF= 0; break;
			case 10:	RS_TXF= 1; break;				//stop1 bit
			default:	Rxf.Faz= 0; Card.TxPos++;		//stop2 bit
						if(Card.TxPos >= Card.TxDb){
							Card.TxDb= 0; Card.TxPos= 0;
							}		//#20
			}
		}	//#56
	else{
		be= RS_RXF; Rxf.Tim= 2; Rxf.Faz++;//#10			//normál idõ=3
		switch(Rxf.Faz){			//#29
			case  1:	Rxf.Tim= 0;							//1/3bit	START
						if(be) Rxf.Faz= 0;					//nincs start bit = vár
						break;
			case  2:	if(be){ Rxf.Tim= 0; Rxf.Faz= 0; }	//false start
						else Rxf.Byte= 0;					//START OK
						break;			//#10
			case  3:	if(be) Rxf.Byte|= 0x01; break;
			case  4:	if(be) Rxf.Byte|= 0x02; break;
			case  5:	if(be) Rxf.Byte|= 0x04; break;
			case  6:	if(be) Rxf.Byte|= 0x08; break;
			case  7:	if(be) Rxf.Byte|= 0x10; break;
			case  8:	if(be) Rxf.Byte|= 0x20; break;
			case  9:	if(be) Rxf.Byte|= 0x40; break;
			case 10:	if(be) Rxf.Byte|= 0x80; break;
			case 11:	Rxf.Vett= Rxf.Byte; Rxf.VanVett= 1;//StopBit
			default:	Rxf.Tim= 0; Rxf.Faz= 0;			//Error+vége		
			}
		}	//#49
	}
}
//=========================================================Int-35u
void		Rxd_Busz_35u(void)	//pisztoly		//#72		//104,17us=9k6 (34,72us*3)
{
uint8_t		be;

if(Rxd.Tim > 0) Rxd.Tim--;
else{
	be= RS_RXD; Rxd.Tim= 2; Rxd.Faz++;			//normál idõ=3
	switch(Rxd.Faz){
		case 1:	Rxd.Tim= 0;						//1/3bit	START
				if(be) Rxd.Faz= 0;				//nincs start bit = vár
				break;
		case 2:	if(be){	Rxd.Tim= 0; Rxd.Faz= 0; }	//false start
				else{ Rxd.Byte= 0; Rxd.Tim= 1; }	//START OK, 1/3bit
				break;
		case 3:	if(be) Rxd.Byte|= 0x01; break;	//1/3-nál mintavétel
		case 4:	if(be) Rxd.Byte|= 0x02; break;
		case 5:	if(be) Rxd.Byte|= 0x04; break;
		case 6:	if(be) Rxd.Byte|= 0x08; break;
		case 7:	if(be) Rxd.Byte|= 0x10; break;
		case 8:	if(be) Rxd.Byte|= 0x20; break;
		case 9:	if(be) Rxd.Byte|= 0x40; break;
		case 10:if(be) Rxd.Byte|= 0x80; break;
		case 11:if(be){
					Rxd.Vett= Rxd.Byte;			//StopBit
					Rxd.VanVett= 1;
					}
		default: Rxd.Tim= 0; Rxd.Faz= 0;		//Error+vége		
		}
	}
}
//=========================================================Alap
uint8_t		_ChrHex_to_bin(uint8_t be)
{
uint8_t	ki;
if		((be >= '0')&&(be <= '9')) ki= be-'0';
else if	((be >= 'A')&&(be <= 'F')) ki= be-'A'+10;
else	ki= 0;
return(ki&0x0f);
}
//---------------------------------------------------------Int-100us
//00182CD31C79002B 307E5DD12300 000000000000 00039561 0000 CE15
// 1 2 3 4 5 6 7 8_ 1 2 3 4 5 6_ 1 2 3 4 5 6_ 1 2 3 4_ 1 2_cccc +0x0d+0x0a = 63byte
void		Pisztoly_100us(void)
{
uint8_t		i, num, jo;
uint32_t 	dw;

if(Rxd.VanVett){  Rxd.VanVett= 0;
	for(i=0; i<63; i++) Card.PiBuf[i]= Card.PiBuf[i+1];		//shift
	Card.PiBuf[63]= Rxd.Vett;

	if(Card.PiDb < 255) Card.PiDb++;						//para
	if((Card.PiDb > 2)&&(Card.PiBuf[62] == 0x0d)&&(Card.PiBuf[63] == 0x0a)){	//1 sor megjött
		if(Card.PiDb > 62){									//megjött a 63 byte
			for(i=0,jo=0; i<12; i++){
				Card.PiBlk[i]= Card.PiBuf[i+18];
				num= Card.PiBlk[i];
				if(((num >= '0')&&(num <= '9'))||((num >= 'A')&&(num <= 'F'))) jo++;//jó számjegy
				}
			if(jo == 12){
				Card.PiKod[0]= _ChrHex_to_bin(Card.PiBlk[0])*16+_ChrHex_to_bin(Card.PiBlk[1]);
				Card.PiKod[1]= _ChrHex_to_bin(Card.PiBlk[2])*16+_ChrHex_to_bin(Card.PiBlk[3]);
				Card.PiKod[2]= _ChrHex_to_bin(Card.PiBlk[4])*16+_ChrHex_to_bin(Card.PiBlk[5]);
				Card.PiKod[3]= _ChrHex_to_bin(Card.PiBlk[6])*16+_ChrHex_to_bin(Card.PiBlk[7]);
				Card.PiKod[4]= _ChrHex_to_bin(Card.PiBlk[8])*16+_ChrHex_to_bin(Card.PiBlk[9]);
				Card.PiKod[5]= _ChrHex_to_bin(Card.PiBlk[10])*16+_ChrHex_to_bin(Card.PiBlk[11]);
				dw= Card.PiKod[1];
				dw= dw*256+Card.PiKod[2];
				dw= dw*256+Card.PiKod[3];
				dw= dw*256+Card.PiKod[4];
				Card.PiDec[4]=	dw%10;		dw/=10;
				Card.PiDec[4]+= dw%10*16;	dw/=10;
				Card.PiDec[3]=	dw%10;		dw/=10;
				Card.PiDec[3]+= dw%10*16;	dw/=10;
				Card.PiDec[2]=	dw%10;		dw/=10;
				Card.PiDec[2]+= dw%10*16;	dw/=10;
				Card.PiDec[1]=	dw%10;		dw/=10;
				Card.PiDec[1]+= dw%10*16;	dw/=10;
				Card.PiDec[0]=	dw%10;		dw/=10;
				Card.PiDec[0]+= dw%10*16;

				num= Card.PiKod[0]|Card.PiKod[1]|Card.PiKod[2]|Card.PiKod[3]|Card.PiKod[4]|Card.PiKod[5];
				if(num != 0){	Card.PiVan=1;	Card.PiTim100m=0; }	//megjött egy szám
				else		{	Card.PiVan=0; }						//csupa nulla
				}
			}
		Card.PiDb=0;											//sor eldob
		}
	}

if(Card.PiTim100m  >= PISZT_TIMEOUT) Card.PiVan=0;				//pisztollyal baj van, vagy elvették -> STOP
}
//=========================================================Alap
void		Card_Adas_mehet(void)
{
Card.Rx1Buf[0]=	0xff;			//régi kártya törölve
Card.Rx1Buf[1]=	0xff;
Card.Rx2Buf[0]=	0xff;			//régi kártya törölve
Card.Rx2Buf[1]=	0xff;
switch(EE.CardReaderTipe&0x0f){
	default:
//	case CARD_REGI:			break;						//1-régi(BCD-[#+10+1+3]) kártyaolvasó
//	case CARD_UJ:			break;						//2-új(BCD-[#+10+'9']) kártyaolvasó
//	case CARD_BCD10:		break;						//7-BCD-[#+10]) kártyaolvasó
//	case CARD_HEX:										//3-HEX[x2;08x;x3]
//		Card.RxBuf[0]= 0;								//régi kártya törölve
//		break;
//	case CARD_1x10cx2:		break;						//4-[x1+10c+x2]
//-----------------------------------------------
	case CARD_MIFARE:									//5-mifare
		Card.TxBuf[0]= 0xba;			//start	(0xBA,0x02,0x01)
		Card.TxBuf[1]= 0x02;			//len
		Card.TxBuf[2]= 0x01;			//command
		Card.TxBuf[3]= 0xb9;			//chksum=(xba^x02)^x01=xb9
		Card.TxPos= 0; Rxf.Faz= 0; Card.TxDb= 4;		//mehet az adás
		break;
//-----------------------------------------------
	case CARD_CROSSPOINT:								//6-CROSSPOINT
		Card.Id[0]= 0;					//régi ID törölve
		Card.Id[1]= 0;
		Card.Id[2]= 0;
		Card.Id[3]= 0;
		Card.Id[4]= 0;
		Card.Id[5]= 0;
		Card.Id[7]= 0;

//#if		CROSS_POINT_CIM == 6
//		Card.TxBuf[0]=0x06;				//    x06,x0b,x03,x9a,x01,x00,x6a
//		Card.TxBuf[6]=0x6a;				//xff^x06^x0b^x03^x9a^x01^x00=x6a
//#elif	CROSS_POINT_CIM == 12
//		Card.TxBuf[0]= 0x0c;			//    x0c,x0b,x03,x9a,x01,x00,x60
//		Card.TxBuf[6]= 0x60;			//xff^x0c^x0b^x03^x9a^x01^x00=x60
//#else
//		Card.TxBuf[0]= 0x18;			//    x18,x0b,x03,x9a,x01,x00,x74
//		Card.TxBuf[6]= 0x74;			//xff^x18^x0b^x03^x9a^x01^x00=x74
//#endif
		Card.TxBuf[0]= EE.CrossPointCim;
		Card.TxBuf[1]= 0x0b;
		Card.TxBuf[2]= 0x03;
		Card.TxBuf[3]= 0x9a;
		Card.TxBuf[4]= 0x01;
		Card.TxBuf[5]= 0x00;
		Card.TxBuf[6]= (0xff^0x0b^0x03^0x9a^0x01)^Card.TxBuf[0];

		Card.TxPos= 0; Rxf.Faz= 0; Card.TxDb= 7;	//mehet az adás
		break;
	}
}
//---------------------------------------------------------Alap
uint8_t		Card_Vesz_2(void)		//->0=ok,1..4=error
{
switch(EE.CardReaderTipe&0xf0){
	case CARD2_REGI:
		if(Card.Rx2Pos >= 15) return(0);
		if(Rxc.VanVett){ Rxc.VanVett= 0;
			Card.Rx2Buf[Card.Rx2Pos]= Rxc.Vett;
			if((Card.Rx2Pos > 0)||(Card.Rx2Buf[0] == '#')) Card.Rx2Pos++;//kezdõ karakter megjött
			}
		return(1);							//vár még
		break;
//-----------------------------------------------
	case CARD2_WIEGAND:
		if(Card.Rx2Pos >= 4) return(0);		//megjött
		return(1);							//vár még
		break;
	}
return(10);
}
//---------------------------------------------------------Alap
uint8_t		Card_Vesz_1(void)		//->0=ok,1..4=error
{
switch(EE.CardReaderTipe&0x0f){
	default:
	case CARD_REGI:										//1-régi(BCD-[#+10+1+3]) kártyaolvasó
		if(Card.Rx1Pos >= 15) return(0);
		if(Rxf.VanVett){ Rxf.VanVett= 0;
			Card.Rx1Buf[Card.Rx1Pos]= Rxf.Vett;
			if((Card.Rx1Pos > 0)||(Card.Rx1Buf[0] == '#')) Card.Rx1Pos++;//kezdõ karakter megjött
			}
		return(1);				//vár még
//-----------------------------------------------
	case CARD_UJ:										//2-új(BCD-[#+10+'9']) kártyaolvasó
		if(Card.Rx1Pos >= 12) return(0);
		if(Rxf.VanVett){ Rxf.VanVett= 0;
			Card.Rx1Buf[Card.Rx1Pos]= Rxf.Vett;
			if((Card.Rx1Pos > 0)||(Card.Rx1Buf[0] == '#')) Card.Rx1Pos++;//kezdõ karakter megjött
			}
		return(1);				//vár még
//-----------------------------------------------
	case CARD_BCD10:										//7-BCD-[#+10]) kártyaolvasó
		if(Card.Rx1Pos >= 11) return(0);
		if(Rxf.VanVett){ Rxf.VanVett= 0;
			Card.Rx1Buf[Card.Rx1Pos]= Rxf.Vett;
			if((Card.Rx1Pos > 0)||(Card.Rx1Buf[0] == '#')) Card.Rx1Pos++;//kezdõ karakter megjött
			}
		return(1);				//vár még
//-----------------------------------------------
	case CARD_HEX:										//3-HEX[x2;08x;x3]
		if(Card.Rx1Pos >=10) return(0);
		if(Rxf.VanVett){ Rxf.VanVett= 0;
			Card.Rx1Buf[Card.Rx1Pos]= Rxf.Vett;
			if((Card.Rx1Pos > 0)||(Card.Rx1Buf[0] == 0x02)) Card.Rx1Pos++;//kezdõ karakter megjött
			}
		return(1);				//vár még
//-----------------------------------------------
	case  CARD_1x10cx2:									//4-[x1+10c+x2]
		if(Card.Rx1Pos >= 12) return(0);
		if(Rxf.VanVett){ Rxf.VanVett= 0;
			Card.Rx1Buf[Card.Rx1Pos]= Rxf.Vett;
			if((Card.Rx1Pos > 0)||(Card.Rx1Buf[0] == 0x01)) Card.Rx1Pos++;//kezdõ karakter megjött
			}
		return(1);				//vár még
//-----------------------------------------------
	case CARD_MIFARE:									//5-mifare
		if(Card.Rx1Pos >= 10) return(0);//[0xBD,0x08,0x01,0x00,d1,d2,d3,d4,0x01=type,cc]
		if(Rxf.VanVett){ Rxf.VanVett= 0;
			Card.Rx1Buf[Card.Rx1Pos]= Rxf.Vett;
			if((Card.Rx1Pos > 0)||(Card.Rx1Buf[0] == 0xbd)) Card.Rx1Pos++;//kezdõ karakter megjött
			}
		return(1);				//vár még
//-----------------------------------------------
	case CARD_CROSSPOINT:								//6-CROSSPOINT
		if(Card.Rx1Pos >= 12) return(0);//[x00,xFB,x08,0x1A,x00,d5,d4,d3,d2,d1,|0x80=type,cc]
		if(Rxf.VanVett){ Rxf.VanVett= 0;
			if		(Card.Rx1Pos == 0){ Card.Rx1Buf[1]= Rxf.Vett; Card.Rx1Pos= 1; }
			else if	(Card.Rx1Pos == 1){
				Card.Rx1Buf[0]= Card.Rx1Buf[1]; Card.Rx1Buf[1]= Rxf.Vett;//shift
				if((Card.Rx1Buf[0] == 0x00)&&(Card.Rx1Buf[1] == 0xfb)) Card.Rx1Pos++;//kezdõ 2 karakter megjött
				}
			else{	Card.Rx1Buf[Card.Rx1Pos]= Rxf.Vett;	Card.Rx1Pos++; }	//kezdõ karakter megjött
			
			}
		return(1);							//vár még
	}
return(0);									//para
}
//---------------------------------------------------------Alap
uint8_t		Card_Ertekel1_REGI(void)				//->0=ok,1..4=error
{
uint8_t		i, num, szum;

if(Card.Rx1Pos < 15)				return(1);
szum= 0;
for(i=1; i<11; i++){
	num= Card.Rx1Buf[i];
	if((num < '0')||(num > '9'))	return(2);	//nem számjegy -> hiba
	szum+= num-'0';
	}
if(szum == 0)						return(3);	//Csupa '0'

num= Card.Rx1Buf[11];
if((num < '0')||(num > '9'))		return(4);	//nem számjegy -> hiba
if((szum%10) != (num-'0'))			return(5);	//CheckSum rossz

Card.Id[0]= (Card.Rx1Buf[1]&0x0f)*16+(Card.Rx1Buf[2]&0x0f);
Card.Id[1]= (Card.Rx1Buf[3]&0x0f)*16+(Card.Rx1Buf[4]&0x0f);
Card.Id[2]= (Card.Rx1Buf[5]&0x0f)*16+(Card.Rx1Buf[6]&0x0f);
Card.Id[3]= (Card.Rx1Buf[7]&0x0f)*16+(Card.Rx1Buf[8]&0x0f);
Card.Id[4]= (Card.Rx1Buf[9]&0x0f)*16+(Card.Rx1Buf[10]&0x0f);
Card.Id[5]= 0;
Card.Id[6]= 0;
return(0);
}
//---------------------------------------------------------Alap
uint8_t		Card_Ertekel2_REGI(void)			//->0=ok,1..4=error
{
uint8_t		i, num, szum;

if(Card.Rx2Pos < 15)				return(1);
szum= 0;
for(i=1; i<11; i++){
	num= Card.Rx2Buf[i];
	if((num < '0')||(num > '9'))	return(2);	//nem számjegy -> hiba
	szum+= num-'0';
	}
if(szum == 0)						return(3);	//Csupa '0'

num= Card.Rx2Buf[11];
if((num < '0')||(num > '9'))		return(4);	//nem számjegy -> hiba
if((szum%10) != (num-'0'))			return(5);	//CheckSum rossz

Card.Id[0]= (Card.Rx2Buf[1]&0x0f)*16+(Card.Rx2Buf[2]&0x0f);
Card.Id[1]= (Card.Rx2Buf[3]&0x0f)*16+(Card.Rx2Buf[4]&0x0f);
Card.Id[2]= (Card.Rx2Buf[5]&0x0f)*16+(Card.Rx2Buf[6]&0x0f);
Card.Id[3]= (Card.Rx2Buf[7]&0x0f)*16+(Card.Rx2Buf[8]&0x0f);
Card.Id[4]= (Card.Rx2Buf[9]&0x0f)*16+(Card.Rx2Buf[10]&0x0f);
Card.Id[5]= 0;
Card.Id[6]= 0;
return(0);
}
//---------------------------------------------------------Alap
uint8_t		Card_Ertekel2_WIEGAND(void)			//->0=ok,1..4=error
{
uint8_t		par1= 0, par2= 0, faci= 0, ki[8];
uint16_t	card= 0;

if(Card.Rx2Pos < 3)					return(1);	//26bit
//3d161900	régi	0011.1101.0001.0110.0001.1001:0000.0000
//			bit		1011.1100.0110.1000.1001.1000:0000.0000
//		páros	1:	0111.1000.1101:0001.0011.0000:0 páratlan
//120.53552= 78d130	0111.1000.1101.0001.0011.0000
//				
//22f19d01	régi	0010.0010.1111.0001.1001.1101:0000.0001
//			bit		0100.0100.1000.1111.1011.1001:1000.0000
//		páros	0:	1000.1001.0001:1111.0111.0011:0 páratlan
//137.08051= 891f73	1000.1001.0001.1111.0111.0011
if(Card.Rx2Buf[0]&0x01) par1= 1;
if(Card.Rx2Buf[0]&0x02) faci|= 0x80;
if(Card.Rx2Buf[0]&0x04) faci|= 0x40;
if(Card.Rx2Buf[0]&0x08) faci|= 0x20;
if(Card.Rx2Buf[0]&0x10) faci|= 0x10;
if(Card.Rx2Buf[0]&0x20) faci|= 0x08;
if(Card.Rx2Buf[0]&0x40) faci|= 0x04;
if(Card.Rx2Buf[0]&0x80) faci|= 0x02;
if(Card.Rx2Buf[1]&0x01) faci|= 0x01;
if(Card.Rx2Buf[1]&0x02) card|= 0x8000;
if(Card.Rx2Buf[1]&0x04) card|= 0x4000;
if(Card.Rx2Buf[1]&0x08) card|= 0x2000;
if(Card.Rx2Buf[1]&0x10) card|= 0x1000;
if(Card.Rx2Buf[1]&0x20) card|= 0x0800;
if(Card.Rx2Buf[1]&0x40) card|= 0x0400;
if(Card.Rx2Buf[1]&0x80) card|= 0x0200;
if(Card.Rx2Buf[2]&0x01) card|= 0x0100;
if(Card.Rx2Buf[2]&0x02) card|= 0x0080;
if(Card.Rx2Buf[2]&0x04) card|= 0x0040;
if(Card.Rx2Buf[2]&0x08) card|= 0x0020;
if(Card.Rx2Buf[2]&0x10) card|= 0x0010;
if(Card.Rx2Buf[2]&0x20) card|= 0x0008;
if(Card.Rx2Buf[2]&0x40) card|= 0x0004;
if(Card.Rx2Buf[2]&0x80) card|= 0x0002;
if(Card.Rx2Buf[3]&0x01) card|= 0x0001;
if(Card.Rx2Buf[3]&0x02) par2= 1;

ki[2]= faci%10;		faci/= 10;
ki[1]= faci%10;
ki[0]= faci/10;
ki[7]= card%10;		card/= 10;
ki[6]= card%10;		card/= 10;
ki[5]= card%10;		card/= 10;
ki[4]= card%10;
ki[3]= card/10;

Card.Id[0]= (ki[0]<<4)+(ki[1]);
Card.Id[1]= (ki[2]<<4)+(ki[3]);
Card.Id[2]= (ki[4]<<4)+(ki[5]);
Card.Id[3]= (ki[6]<<4)+(ki[7]);
Card.Id[4]= 0;
Card.Id[5]= 0;
Card.Id[6]= 0;
return(0);
}
//---------------------------------------------------------Alap
uint8_t		Card_Ertekel_UJ(void)				//->0=ok,1..4=error
{
uint8_t		i, num, szum;

if(Card.Rx1Pos < 12)				return(1);
szum= 0;
for(i=1; i<11; i++){
	num= Card.Rx1Buf[i];
	if((num < '0')||(num > '9'))	return(2);	//nem számjegy -> hiba
	szum+= num-'0';
	}
if(szum == 0)						return(3);	//Csupa '0'
num= Card.Rx1Buf[11];
if((num < '0')||(num > '9'))		return(4);	//nem számjegy -> hiba

Card.Id[0]= (Card.Rx1Buf[1]&0x0f)*16+(Card.Rx1Buf[2]&0x0f);
Card.Id[1]= (Card.Rx1Buf[3]&0x0f)*16+(Card.Rx1Buf[4]&0x0f);
Card.Id[2]= (Card.Rx1Buf[5]&0x0f)*16+(Card.Rx1Buf[6]&0x0f);
Card.Id[3]= (Card.Rx1Buf[7]&0x0f)*16+(Card.Rx1Buf[8]&0x0f);
Card.Id[4]= (Card.Rx1Buf[9]&0x0f)*16+(Card.Rx1Buf[10]&0x0f);
Card.Id[5]= 0;
Card.Id[6]= 0;
return(0);
}
//---------------------------------------------------------Alap
uint8_t		Card_Ertekel_BCD10(void)			//->0=ok,1..4=error
{
uint8_t		i, num;

if(Card.Rx1Pos < 11)				return(1);
for(i=1; i<11; i++){
	num= Card.Rx1Buf[i];
	if((num < '0')||(num > '9'))	return(2);	//nem számjegy -> hiba
	}

Card.Id[0]= (Card.Rx1Buf[1]&0x0f)*16+(Card.Rx1Buf[2]&0x0f);
Card.Id[1]= (Card.Rx1Buf[3]&0x0f)*16+(Card.Rx1Buf[4]&0x0f);
Card.Id[2]= (Card.Rx1Buf[5]&0x0f)*16+(Card.Rx1Buf[6]&0x0f);
Card.Id[3]= (Card.Rx1Buf[7]&0x0f)*16+(Card.Rx1Buf[8]&0x0f);
Card.Id[4]= (Card.Rx1Buf[9]&0x0f)*16+(Card.Rx1Buf[10]&0x0f);
Card.Id[5]= 0;
Card.Id[6]= 0;
return(0);
}
//---------------------------------------------------------Alap
uint8_t		Card_Ertekel_HEX(void)				//->0=ok,1..4=error
{
uint8_t		i, num;
uint8_t		konv[3];

if(Card.Rx1Pos < 10)				return(1);
for(i=1; i<9; i++){
	num= Card.Rx1Buf[i];
	if((num < '0')||(num > 'F')||((num > '9')&&(num < 'A'))) return(2);	//nem számjegy -> hiba
	}

konv[0]= _ChrHex_to_bin(Card.Rx1Buf[1])*16+_ChrHex_to_bin(Card.Rx1Buf[2]);
konv[1]= _ChrHex_to_bin(Card.Rx1Buf[3])*16+_ChrHex_to_bin(Card.Rx1Buf[4]);
konv[2]= _ChrHex_to_bin(Card.Rx1Buf[5])*16+_ChrHex_to_bin(Card.Rx1Buf[6]);
//***
return(0);
}
//---------------------------------------------------------Alap
uint8_t		Card_Ertekel_1x10cx2(void)			//->0=ok,1..4=error
{
uint8_t		i, num, szum;

if(Card.Rx1Pos < 12)				return(1);
szum= 0;
for(i=1; i<11; i++){
	num= Card.Rx1Buf[i];
	if((num < '0')||(num > '9'))	return(2);	//nem számjegy -> hiba
	szum+= num-'0';
	}
if(szum == 0)						return(3);	//Csupa '0'
num= Card.Rx1Buf[11];
if(num != 0x02)						return(4);	//záró karakter

Card.Id[0]= (Card.Rx1Buf[1]&0x0f)*16+(Card.Rx1Buf[2]&0x0f);
Card.Id[1]= (Card.Rx1Buf[3]&0x0f)*16+(Card.Rx1Buf[4]&0x0f);
Card.Id[2]= (Card.Rx1Buf[5]&0x0f)*16+(Card.Rx1Buf[6]&0x0f);
Card.Id[3]= (Card.Rx1Buf[7]&0x0f)*16+(Card.Rx1Buf[8]&0x0f);
Card.Id[4]= (Card.Rx1Buf[9]&0x0f)*16+(Card.Rx1Buf[10]&0x0f);
Card.Id[5]= 0;
Card.Id[6]= 0;
return(0);
}
//---------------------------------------------------------Alap
uint8_t		Card_Ertekel_MIFARE(void)			//->0=ok,1..4=error
{
uint8_t		i, num, szum;
uint8_t		konv[10];
uint32_t	dwi;

if(Card.Rx1Pos < 10)				return(1);

if(Card.Rx1Buf[0] != 0xbd)			return(2);	//a block megjött
if(Card.Rx1Buf[1] != 0x08)			return(2);
if(Card.Rx1Buf[2] != 0x01)			return(2);
if(Card.Rx1Buf[3] != 0x00)			return(2);
if(Card.Rx1Buf[8] != 0x01)			return(2);

szum= Card.Rx1Buf[0];
for(i=1; i<9; i++) szum^= Card.Rx1Buf[i];
num= Card.Rx1Buf[9];
if(szum != num)						return(5);	//CheckSum rossz

dwi= Card.Rx1Buf[7];
dwi= dwi*256+Card.Rx1Buf[6];
dwi= dwi*256+Card.Rx1Buf[5];
dwi= dwi*256+Card.Rx1Buf[4];					//0xffffffff=4.294.967.295

konv[9]= dwi%10; dwi/= 10;
konv[8]= dwi%10; dwi/= 10;
konv[7]= dwi%10; dwi/= 10;
konv[6]= dwi%10; dwi/= 10;
konv[5]= dwi%10; dwi/= 10;
konv[4]= dwi%10; dwi/= 10;
konv[3]= dwi%10; dwi/= 10;
konv[2]= dwi%10; dwi/= 10;
konv[1]= dwi%10; dwi/= 10;
konv[0]= dwi%10;

Card.Id[0]= (konv[0]&0x0f)*16+(konv[1]&0x0f);
Card.Id[1]= (konv[2]&0x0f)*16+(konv[3]&0x0f);
Card.Id[2]= (konv[4]&0x0f)*16+(konv[5]&0x0f);
Card.Id[3]= (konv[6]&0x0f)*16+(konv[7]&0x0f);
Card.Id[4]= (konv[8]&0x0f)*16+(konv[9]&0x0f);
Card.Id[5]= 0;
Card.Id[6]= 0;

//13 19 49 42 17 - dec kártya kód (Card[2])
//be a5 e2 49 = 3198542409
//49 e2 a5 be = 1239590334
return(0);
}
//---------------------------------------------------------Alap
uint8_t		Card_Ertekel_CROSSPOINT(void)		//->0=ok,1..4=error
{
uint8_t		i, num, szum;
uint8_t		konv[14];
uint64_t	ddwi;

if(Card.Rx1Pos < 12)				return(1);

if(Card.Rx1Buf[0] != 0x00)			return(2);	//a block megjött
if(Card.Rx1Buf[1] != 0xfb)			return(2);
if(Card.Rx1Buf[2] != 0x08)			return(2);
if(Card.Rx1Buf[3] != 0x1a)			return(2);
if((Card.Rx1Buf[10]&0x80) == 0)		return(3);	//nincs odatartva

szum= 0xff;
for(i=0; i<11; i++) szum^=Card.Rx1Buf[i];
num= Card.Rx1Buf[11];
if(szum != num)						return(5);	//CheckSum rossz

ddwi= Card.Rx1Buf[9];
ddwi= ddwi*256+Card.Rx1Buf[8];
ddwi= ddwi*256+Card.Rx1Buf[7];
ddwi= ddwi*256+Card.Rx1Buf[6];
ddwi= ddwi*256+Card.Rx1Buf[5];				//0xffff ffff ff=1.099.511.627.775

konv[12]= ddwi%10; ddwi/= 10;
konv[11]= ddwi%10; ddwi/= 10;
konv[10]= ddwi%10; ddwi/= 10;
konv[ 9]= ddwi%10; ddwi/= 10;
konv[ 8]= ddwi%10; ddwi/= 10;
konv[ 7]= ddwi%10; ddwi/= 10;
konv[ 6]= ddwi%10; ddwi/= 10;
konv[ 5]= ddwi%10; ddwi/= 10;
konv[ 4]= ddwi%10; ddwi/= 10;
konv[ 3]= ddwi%10; ddwi/= 10;
konv[ 2]= ddwi%10; ddwi/= 10;
konv[ 1]= ddwi%10; ddwi/= 10;
konv[ 0]= ddwi%10;

Card.Id[0]= (konv[0]&0x0f);
Card.Id[1]= (konv[1]&0x0f)*16+(konv[2]&0x0f);
Card.Id[2]= (konv[3]&0x0f)*16+(konv[4]&0x0f);
Card.Id[3]= (konv[5]&0x0f)*16+(konv[6]&0x0f);
Card.Id[4]= (konv[7]&0x0f)*16+(konv[8]&0x0f);
Card.Id[5]= (konv[9]&0x0f)*16+(konv[10]&0x0f);
Card.Id[6]= (konv[11]&0x0f)*16+(konv[12]&0x0f);
return(0);
}
//---------------------------------------------------------Alap
uint8_t		Card_Ertekel2(void)					//->0=ok,1..4=error
{
switch(EE.CardReaderTipe&0xf0){
	case CARD2_REGI:		return(Card_Ertekel2_REGI());//1-régi(BCD-[#+10+1+3]) kártyaolvasó
	case CARD2_WIEGAND:		return(Card_Ertekel2_WIEGAND());//2-
	}
return(1);
}
//---------------------------------------------------------Alap
uint8_t		Card_Ertekel1(void)					//->0=ok,1..4=error
{
switch(EE.CardReaderTipe&0x0f){
	default:
	case CARD_REGI:			return(Card_Ertekel1_REGI());	//1-régi(BCD-[#+10+1+3]) kártyaolvasó
	case CARD_UJ:			return(Card_Ertekel_UJ());		//2-új(BCD-[#+10+'9']) kártyaolvasó
	case CARD_BCD10:		return(Card_Ertekel_BCD10());	//7-BCD-[#+10]) kártyaolvasó
	case CARD_HEX:			return(Card_Ertekel_HEX());		//3-HEX[x2;08x;x3]
	case CARD_1x10cx2:		return(Card_Ertekel_1x10cx2());	//4-[x1+10c+x2]
	case CARD_MIFARE:		return(Card_Ertekel_MIFARE());	//5-mifare
	case CARD_CROSSPOINT:	return(Card_Ertekel_CROSSPOINT());//6-CROSSPOINT
	}
}
//---------------------------------------------------------Alap
uint8_t		Card_Vesz(void)			//->0=ok,1..4=error	<-(ScrS1,ScrA3)
{
uint8_t		resu1= 10, resu2= 10;

Card_Adas_mehet();					//ha kell, ad

Card.RxTim100m= 0; Card.Rx1Pos= 0;  Card.Rx2Pos= 0;
if((EE.CardReaderTipe&0xf0) == CARD2_WIEGAND){
	Rxb.VanVett= 0; Rxc.VanVett= 0; Rxb.Byte= 0; Rxb.Vett= 0; Rxc.Vett= 0;//init
	}
//-----------------------------------------------loop
while(Card.RxTim100m < CARD_TIMEOUT){//olvasó megvár
	resu1= Card_Vesz_1();	if(resu1 == 0) break;	//0= megjött
	resu2= Card_Vesz_2();	if(resu2 == 0) break;	//10= kikapcs
	}
//-----------------------------------------------
if		(resu1 == 0) resu1= Card_Ertekel1();
else if	(resu2 == 0) resu1= Card_Ertekel2();
if(resu1 == 0) M.SpkTim= CARD_BEEP_TIME;			//pitty
return(resu1);
}
//=========================================================END
