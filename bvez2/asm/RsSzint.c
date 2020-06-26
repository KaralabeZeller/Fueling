//-----------------------------------------------
// BENZIN SOROS Szinmérô csomag (RECEIVE 63byte block) - (AtMEGA103-6Mhz)
//-----------------------------------------------
#include "Bvez2.h"
//-----------------------------------------------
//1) the Smart Box sends the data periodic 1x per minute.
//2) you only have to read it.
//3) the connection normally is with a special COM port adapter to the PC (included in the PC Set).
//2400 Baud, No Parity, 8 Datenbits, 1 Stopbit
//Handshake-wire: RTS and DTR are fix on plus supply
//-----------------------------------------------
//Block leírás:
//0		- Preamble byte FF for synchronization UART (do not process)
//1		- Startbyte STX (02)
//2		- Number of value-bytes (17), incl. number and check sum, without preamble, start, end
//3		- Identification 	02 = display device LX-1
//							03 = Display and supervision device TO-1 (with 2 relays )
//							04 = Display and supervision device LC-1 or LC-2 (with 1 relay)
//							05 = Display device LX-2
//4,5	- Serial number (0000 = no serial number available)
//6		- Reserved for temperature data. (00 = no data)
//7		- Bit field interferences and relay status (insofar contained in display device)
//			Bit 0: error input alarm : 1 = alarm ( depending on programming close/open )
//			Bit 1: error input contact status : 1 = contact closed
//			Bit 2: status relay 1 : 1 = relay pulled in
//			Bit 3: status relay 2 : 1 = relay pulled in
//			Bit 4: acknowledgement beeper
//			Bit 5 - 7: Reserve
//8,9	- Current level (= content indicator on the display device) in BCD (for example 0550 = 550 Liters)
//10,11	- Tank parameters set in the display device:
//			Bit 0-7: Tank type
//			Bit 8-9: Decimal point
//			Bit 10: Always 1 (Send data = active)
//			Bit 12-15: Rounding
//12,13	- Tank value
//14,15	- Tank height
//16,17	- Threshold values for relay (insofar contained in the display device)
//			Hi-Byte = Threshold value relay 1 in percentage (01-99)
//			Lo-Byte = Threshold value relay 2 in percentage (01-99)
//18	- Check sum: 8 Bit Sum all bytes (bytes 2-17)
//19	- Endbyte ETX (03)
//=========================================================Int-35u
void		Rxb_Busz_35u(void)			//416,66us=2k4 (34,72us*12)
{
uint8_t		be;

if((EE.CardReaderTipe&0xf0) == CARD2_WIEGAND){
	be= RS_RXB;
	if(be){ if(Rxb.Tim < 10) Rxb.Tim++; } else{ if(Rxb.Tim > 0) Rxb.Tim--; }
	if		((Rxb.Tim == 0)&&(Rxb.Faz != 0)){ Rxb.Faz= 0; }//új H->L jött
	else if	((Rxb.Tim > 9)&&(Rxb.Faz != 1)){ Rxb.Faz= 1; Rxb.VanVett= 1; }//új L->H jött
	}
else{
	if(Rxb.Tim > 0) Rxb.Tim--;
	else{
		be= RS_RXB; Rxb.Tim= 12; Rxb.Faz++;			//normál idô=12
		switch(Rxb.Faz){
			case 1:	Rxb.Tim= 0;						//1/3bit	START
				if(be) Rxb.Faz= 0;					//nincs start bit = vár
				break;
			case 2:	if(be){ Rxb.Tim= 0; Rxb.Faz= 0; }	//false start
				else Rxb.Byte= 0;					//START OK
				break;
			case 3:	if(be) Rxb.Byte|= 0x01; break;
			case 4:	if(be) Rxb.Byte|= 0x02; break;
			case 5:	if(be) Rxb.Byte|= 0x04; break;
			case 6:	if(be) Rxb.Byte|= 0x08; break;
			case 7:	if(be) Rxb.Byte|= 0x10; break;
			case 8:	if(be) Rxb.Byte|= 0x20; break;
			case 9:	if(be) Rxb.Byte|= 0x40; break;
			case 10:if(be) Rxb.Byte|= 0x80; Rxb.Tim--; break;//2/3bit
			case 11:if(be){
					Rxb.Vett= Rxb.Byte;				//StopBit
					Rxb.VanVett= 1;
					}
			default:Rxb.Tim= 0; Rxb.Faz= 0;			//Error+vége
			}
		}
	}
}
//=========================================================Int-35u
void		Rxc_Busz_35u(void)			//416,66us=2k4 (34,72us*12)
{
uint8_t		be;

if((EE.CardReaderTipe&0xf0) == CARD2_WIEGAND){
	be= RS_RXC;
	if(be){ if(Rxc.Tim < 10) Rxc.Tim++; } else{ if(Rxc.Tim > 0)	Rxc.Tim--; }
	if		((Rxc.Tim == 0)&&(Rxc.Faz != 0)){ Rxc.Faz= 0; }//új H->L jött
	else if	((Rxc.Tim > 9)&&(Rxc.Faz != 1)){ Rxc.Faz= 1; Rxc.VanVett= 1; }//új L->H jött
	}
else{
	if(Rxc.Tim > 0) Rxc.Tim--;
	else{
		be= RS_RXC;
		if((EE.CardReaderTipe&0xf0) == CARD2_REGI)	Rxc.Tim= 2;	//3-9k6
		else										Rxc.Tim= 12;//13-2k4 normál idô=12
		Rxc.Faz++;
		switch(Rxc.Faz){
			case 1:	Rxc.Tim= 0;							//1/3bit	START
					if(be) Rxc.Faz= 0;					//nincs start bit = vár
					break;
			case 2:	if(be){ Rxc.Tim= 0; Rxc.Faz= 0; }	//false start
					else Rxc.Byte= 0;					//START OK
					break;
			case 3:	if(be) Rxc.Byte|= 0x01; break;
			case 4:	if(be) Rxc.Byte|= 0x02; break;
			case 5:	if(be) Rxc.Byte|= 0x04; break;
			case 6:	if(be) Rxc.Byte|= 0x08; break;
			case 7:	if(be) Rxc.Byte|= 0x10; break;
			case 8:	if(be) Rxc.Byte|= 0x20; break;
			case 9:	if(be) Rxc.Byte|= 0x40; break;
			case 10:if(be) Rxc.Byte|= 0x80; Rxc.Tim--; break;//2/3bit
			case 11:if(be){
						Rxc.Vett= Rxc.Byte;			//StopBit
						Rxc.VanVett= 1;
						}
			default:Rxc.Tim= 0; Rxc.Faz= 0;			//Error+vége
			}
		}
	}
}
//===============================================Int-1msec
uint16_t	Konv_BCDtoBIN(uint8_t *tar)
{
uint16_t	n1, n2, n3, n4;
uint32_t	szint;

n1= tar[7]/16; n2= tar[7]%16; n3= tar[8]/16; n4= tar[8]%16;
n1= n1*10+n2;
n2= n3*10+n4;
szint= WmulWtoDW(n1, 100)+n2;

if((tar[9]&0x03) == 0x02) szint*= 10;			//0x00=*1, 0x02=*10,
if(szint > 0x0ffff) szint= 0x0ffff;
return((uint16_t)szint);
}
//-----------------------------------------------Int-1ms
void		Szint_Ciklus_1ms(void)				//->0=ok,1..4=error
{
uint8_t		i, sum;
uint16_t	num;

if((EE.CardReaderTipe&0xf0)== CARD2_WIEGAND){
	if((Rxb.Faz == 0)&&(Rxc.Faz == 0)){			//visszaállt alapba
		if		((Rxb.VanVett == 1)&&(Rxc.VanVett == 0)){	//0 jött
			Rxb.Byte++; Rxb.VanVett= 0;						//0..7
			Rxc.Vett= 0;	//timeout
			}
		else if	((Rxb.VanVett == 0)&&(Rxc.VanVett == 1)){	//1 jött
			Rxb.Vett= Rxb.Vett+(0x01<<Rxb.Byte);			//lsb...msb
			Rxb.Byte++;	Rxc.VanVett= 0;						//0..7
			Rxc.Vett= 0;	//timeout
			}
		Rxc.Vett++;			//timeout
		if(Rxc.Vett > 10){	//10ms nem jött semmi
			Rxc.Vett= 0;	//timeout
			if(Card.Rx2Pos >= 3){	//0..1..2.. vége az adásnak
				Card.Rx2Buf[Card.Rx2Pos]= Rxb.Vett; Rxb.Vett= 0;
				Card.Rx2Pos++;
				}
			}
		if(Rxb.Byte > 7){
			Rxb.Byte= 0;
			if(Card.Rx2Pos < 5){
				Card.Rx2Buf[Card.Rx2Pos]= Rxb.Vett; Rxb.Vett= 0;
				Card.Rx2Pos++;
				}
			}
		}
	}
else{										//csak ha nincs 2.wiegand
	if(Rxb.VanVett){
		Szint[0].Buf[Szint[0].Pos]= Rxb.Vett; Rxb.VanVett= 0;
		if((Szint[0].Pos > 0)||(Szint[0].Buf[0] == 0x02)) Szint[0].Pos++;//kezdô karakter megjött
		Szint[0].TimeOut= 0;
		}
	else{
		Szint[0].TimeOut++;
		if(Szint[0].TimeOut > 50){ Szint[0].TimeOut= 0; Szint[0].Pos= 0; }//50ms=10 byte
		}
	
	if((EE.CardReaderTipe&0xf0)== 0){		//csak ha nincs 2. kártyaolvasó
		if(Rxc.VanVett){
			Szint[1].Buf[Szint[1].Pos]= Rxc.Vett; Rxc.VanVett= 0;
			if((Szint[1].Pos > 0)||(Szint[1].Buf[0] == 0x02)) Szint[1].Pos++;//kezdô karakter megjött
			Szint[1].TimeOut= 0;
			}
		else{
			Szint[1].TimeOut++;
			if(Szint[1].TimeOut > 50){ Szint[1].TimeOut= 0; Szint[1].Pos= 0; }//50ms=10 byte
			}
		}
	}

if(EE.Szint1 == 0){ Szint[0].Jo= 0; }		//1.szinmérô NINCS
else{										//1.szinmérô van
	if(Szint[0].Pos >= 19){
		if(Szint[0].Buf[1] == 0x11){						//len=17
			for(sum=0,i=1; i<17; i++) sum+= Szint[0].Buf[i];
//			if(sum == Szint[0].Buf[17]){					//Szumma jó
				num= (uint16_t)Szint[0].Buf[3]*256+Szint[0].Buf[4];
				if(num == EE.Szint1){						//gyári szám
					MemCpy(Szint[0].Buf1, Szint[0].Buf, 20);
					Szint[0].Jo= Konv_BCDtoBIN(Szint[0].Buf1);
					}
//				}
			}
		}
	}

if(EE.Szint2 == 0){ Szint[1].Jo= 0; }		//2.szinmérô NINCS
else{										//2.szinmérô van
	if(Szint[1].Pos >= 19){
		if(Szint[1].Buf[1] == 0x11){						//len=17
			for(sum=0,i=1; i<17; i++) sum+= Szint[1].Buf[i];
//			if(sum == Szint[1].Buf[17]){					//Szumma jó
				num= (uint16_t)Szint[1].Buf[3]*256+Szint[1].Buf[4];
				if(num == EE.Szint2){						//gyári szám
					MemCpy(Szint[1].Buf1, Szint[1].Buf, 20);
					Szint[1].Jo= Konv_BCDtoBIN(Szint[1].Buf1);
					}
//				}
			}
		}
	}
}
//===============================================END
