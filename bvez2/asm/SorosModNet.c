//===============================================
// NET - benzin vezérlõ soros csomag
//===============================================
#include <stdint.h>

#include "SorosModNet.h"
#include "SorosMod232.h"
#include "Bvez2.h"
//===============================================
#if			NET_REGI==1
	#warning "NET baud = 3k7 "
#else
	#warning "NET baud = 5k "
#endif
void		UART2_Init(void)
{
//U2MODEbits.UARTEN=0;			// Bit15 TX, RX DISABLED, ENABLE at end of func
//U2MODEbits.USIDL=0;			// Bit13 Continue in Idle
//U2MODEbits.IREN=0;			// Bit12 No IR translation
//U2MODEbits.RTSMD=0;			// Bit11 Simplex Mode
//U2MODEbits.UEN=0;				// Bits8,9 TX,RX enabled, CTS,RTS not
//U2MODEbits.WAKE=0;			// Bit7 No Wake up (since we don't sleep here)
//U2MODEbits.LPBACK=0;			// Bit6 No Loop Back
//U2MODEbits.ABAUD=0;			// Bit5 No Autobaud (would require sending '55')
//U2MODEbits.URXINV=0;			// Bit4 IdleState = 1  (for dsPIC)
//U2MODEbits.BRGH=0;			// Bit3 16 clocks per bit period
//U2MODEbits.PDSEL=0;			// Bits1,2 8bit, No Parity
//U2MODEbits.STSEL=0;			// Bit0 0=One,1=2 Stop Bit
U2MODE=0x0000;

#if			NET_REGI==1
//	#warning "NET baud = 3k7 "
	U2BRG=667;					//40Mhz-5kbaud U2BRG=(Fcy/(16*BaudRate))-1 =(40M/(16*3745))-1=667
								//Kútfõben: 66,75us*4=267us->3,7453kbaud , 1STOPbit
#else
//	#warning "NET baud = 5k "
	U2BRG=505;					//40Mhz-5kbaud U2BRG=(Fcy/(16*BaudRate))-1 =(40M/(16*4938))-1=505 (202,4us)
								//Kútfõben: 66,75us*3=200,25us->4,938kbaud , 1STOPbit
#endif
//U2STAbits.UTXISEL1=0;			//Bit15 Int when Char is transferred (1/2 config!)
//U2STAbits.UTXINV=1;			//Bit14 N/A, IRDA config
//U2STAbits.UTXISEL0=0;			//Bit13 Other half of Bit15
//U2STAbits.UTXBRK=0;			//Bit11 Disabled
//U2STAbits.UTXEN=0;			//Bit10 TX pins controlled by periph
//U2STAbits.URXISEL=0;			//Bits6,7 Int. on character recieved
//U2STAbits.ADDEN=0;			//Bit5 Address Detect Disabled
U2STA=0x4000;

//IPC7=0x4400;					// Mid Range Interrupt Priority level, no urgent reason
//IFS1bits.U2TXIF = 0;			// Clear the Transmit Interrupt Flag
//IEC1bits.U2TXIE = 1;			// Enable Transmit Interrupts
//IFS1bits.U2RXIF = 0;			// Clear the Recieve Interrupt Flag
//IEC1bits.U2RXIE = 1;			// Enable Recieve Interrupts

U2MODEbits.UARTEN=1;			// And turn the peripheral on
U2STAbits.UTXEN = 1;
}
//===============================================Int-100us
void		Soros_NET_100us(void)
{
uint8_t		be, torol= 1;

if(Net.Anum > 0){								//Adás
	if(U2STAbits.UTXBF == 0){					//1=transmit buffer full
		if(Net.Apos < Net.Anum){				//if(pos < db)Ad
			U2TXREG= Net.Ad[Net.Apos++];
			}
		else{
			if(U2STAbits.TRMT != 0){			//1=transmit complete
				Net.Vpos= 0;						//Vétel start
				Net.Anum= 0;						//utolsó adás+1ms
				torol= 0;
				}
			}
		}
	if((torol == 1)&&(U2STAbits.URXDA != 0)) be= U2RXREG;//if(van adat)eldob
	if(U2STAbits.OERR != 0) U2STAbits.OERR= 0;	//overrun clear+eldob
	}

if(Net.Anum == 0){//-----------------------------Vétel
	if(U2STAbits.URXDA != 0){
		Net.Vesz[Net.Vpos]= U2RXREG;				//if van adat
		if((Net.Vpos == 0)&&(Net.Vesz[0] == 0xa5)) Net.Vpos++;//várakozás szinkronra	
		else if(Net.Vpos < (NET_VMAX-1)) Net.Vpos++;//if(tele)eldob
		}
	else if(U2STAbits.OERR != 0) U2STAbits.OERR= 0;	//overrun clear+eldob
	}
}
//===============================================Int-150ms
// kutf?:	vétel=(1+8+1)=10bit adás=(1+8+2)=11bit
//			10*9 + 11*34 = 90+374 = 464bit*202,4us = 93914us
uint8_t		NetBeblokkErt(uint16_t kutnum)					//0=ok,1..20=hiba
{
uint8_t		kn, i, pos;
uint16_t	db, sum, sumbe;
uint8_t		*be;

for(pos=0; pos<10; pos++){ if(Net.Vesz[pos] == 0xa5) break; }
be= &Net.Vesz[pos];
db= Net.Vpos-pos;

if(be[0] != 0xa5)					return(1);		//[0]=a5	szinkron rossz
if((be[1]&0xf0) != 0xe0)			return(2);
kn= (be[1]&0x0f)-1;									//[1]=0xE1..0xEF (1..15)
if((kutnum >= KUTFO_DB)||(kn != kutnum)) return(3);	//rossz kútfo válasza

#if		NET_REGI==1
//0xa5,pEn,Sta,Be,LitKomp(4),Liter(4),Hom(2),Gorg(6),GorgKomp(6),Sum(2)=28
	if(db < 28)						return(4);		//nem jött meg a jó teljes blokk
	for(i=0,sum=0; i<26; i++) sum+=be[i];
	sumbe=(Word)be[26]*256+be[27];
#else
//0xa5,pEn,Sta,Be,LitKomp(4),Liter(4),Hom(2),Gorg(6),GorgKomp(6),Kont(3),Hat(3),Sum(2)=34
	if(db < 34)						return(4);		//nem jött meg a jó teljes blokk
	for(i=0,sum=0; i<32; i++) sum+= be[i];
	sumbe= (uint16_t)be[32]*256+be[33];
#endif
if(sum != sumbe)					return(5);		//check sum rossz

Kut[kutnum].Stat=		be[2];						//[2]=Statusz
Kut[kutnum].Jel=		be[3];						//[3]=Jelek

Kut[kutnum].LitKomp=	((((uint32_t)be[4])*100+be[5])*100+be[6])*100+be[7];//[4]=LitKomp	w100
Kut[kutnum].Liter=		((((uint32_t)be[8])*100+be[9])*100+be[10])*100+be[11];//[8]=Liter	w100
Kut[kutnum].Hom=		(uint16_t)be[12]*256+be[13];	//[12]=Homer.w (0,1°C)[0=-40°,400=0°,2048=+164,8°]
MemCpy(Kut[kutnum].Gorg		,&be[14],6);			//[14]=Gorg
MemCpy(Kut[kutnum].GorgKomp	,&be[20],6);			//[20]=GorgKomp
Kut[kutnum].Sum= sum;								//[26]=szumma.w

return(0);											//minden ok
}
//-----------------------------------------------Int-150ms
uint16_t	NetKut= 0;		//0-14
//A5,pCn,Par,Max(2),Sum(2)=7b						//(7+28)*2ms=70ms
//A5,pCn,Par,Max(2),EgysAr(2),Sum(2)=9b				//(9+34)*2ms=86ms
void		NetKerdez_150ms(void)				
{
uint16_t	i, amax, sum= 0;

if(M.NetMehet == 0) return;							//megvárja a start befejezését

if(NetKut < KUTFO_DB){								//értékelés csak normál kérdezésnél
	if(NetBeblokkErt(NetKut) == 0){					//megjött a jó teljes blokk
		Kut[NetKut].Hiba= 0;
		LedVezTime= LED_JOKERES;					//Vez led ég
		}
	else{
		if(Kut[NetKut].Hiba <= KAPCSOLAT_TIME) Kut[NetKut].Hiba++;
		if(Kut[NetKut].Hiba == KAPCSOLAT_TIME) Kut[NetKut].Stat= STA_KAPCSOLAT;
		LedHibaTime= LED_JOKERES;					//hiba led ég
		}
	}

for(i=NetKut+1; i<KUTFO_DB; i++){					//0-14,+15=break
	if((EE.KutStat[i]&0x04) == 0){					//nem virtuális
		if((EE.KutStat[i]&0x01) != 0) break;		//bekapcsolva
		else{										//kikapcsolva
			if(Kut[i].Stat >= STA_ALAP_LENT) break;	//megvárja
			}
		}
	}
NetKut= i;

if(NetKut < KUTFO_DB){								//normál kérdezés
	Net.Ad[0]= 0xa5;
	Net.Ad[1]= 0xc0+NetKut+1;						//1-15
	Net.Ad[2]= Kut[NetKut].Parancs;
	if((EE.KutStat[NetKut]&0x01) == 0){				//menet közben kikapcsolták
		Net.Ad[3]= 0;	//hi
		Net.Ad[4]= 1;	//lo						//limit= 1
		}
	else{
		Net.Ad[3]= hi(Kut[NetKut].Limit);
		Net.Ad[4]= lo(Kut[NetKut].Limit);
		}

#if	NET_REGI == 1
	amax= 5;
#else
	Net.Ad[5]= hi(Tank[NetKut].EgysArNto);
	Net.Ad[6]= lo(Tank[NetKut].EgysArNto);
	amax= 7;
#endif
	for(i=0; i<amax; i++) sum+= Net.Ad[i];
	Net.Ad[amax]=	hi(sum);
	Net.Ad[amax+1]=	lo(sum);
	Net.Vpos= 0; Net.Apos= 0; Net.Anum= amax+2;
	}
else{												//dummy nullázó csomag
	for(i=0; i<NET_AMAX; i++) Net.Ad[i]=0;
	Net.Vpos= 0; Net.Apos= 0; Net.Anum= NET_AMAX;
	NetKut= 0xffff;//Next=0
	}
}
//===============================================END
