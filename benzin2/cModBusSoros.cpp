#include <stdio.h>
#include <dos.h>
#pragma hdrstop
#include "cVezerlo.h"
#include "cUdpalap.h"
#include "cModBusSoros.h"
//-----------------------------------------------
unsigned long	PacketOK=0, PacketERR=0;
int			TcpUdp=0;			//0=soros, 1=UDP
Byte			DinIp=0;			//0=fixIP, 1=DinIP
Byte			SorosNum=1;		//0=r�gi NET prg, 1=RS485/232, 2=RS232
Word			KutSzam=1;

Byte			Sbe[SOROS_LEN+1],Ski[SOROS_LEN+1];
//-----------------------------------------------R�gi
//Byte			be[SER_SIZE],ki[SER_SIZE];
//-----------------------------------------------
/* Table of CRC values for high�order byte */
Byte CRC_H[]={
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81,
0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
0x40};
/* Table of CRC values for low�order byte */
Byte CRC_L[]={
0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7, 0x05, 0xC5, 0xC4,
0x04, 0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F, 0xDD,
0x1D, 0x1C, 0xDC, 0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32, 0x36, 0xF6, 0xF7,
0x37, 0xF5, 0x35, 0x34, 0xF4, 0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA, 0xEE,
0x2E, 0x2F, 0xEF, 0x2D, 0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 0x61, 0xA1, 0x63, 0xA3, 0xA2,
0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 0x78, 0xB8, 0xB9, 0x79, 0xBB,
0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0, 0x50, 0x90, 0x91,
0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98, 0x88,
0x48, 0x49, 0x89, 0x4B, 0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83, 0x41, 0x81, 0x80,
0x40};
//-----------------------------------------------
Word	ModBusCrcCalc(Byte* msg,Byte db)
{
Byte	len=db-2;		//quantity of bytes in message
Byte	crchi=0xff;	//high byte of CRC initialized
Byte	crclo=0xff;	//low byte of CRC initialized
Word	index;		//will index into CRC lookup table

while((len)>0){
	len--;
	index=crchi ^ *msg;
	msg++;
	crchi=crclo^CRC_H[index];
	crclo=CRC_L[index];
	}
return(crchi<<8 | crclo);
}
//-----------------------------------------------
bool	ModBusCrcBe(Byte db)
{
Word	crc,crcok;

crc=((Word)Sbe[db-2])<<8;
crc+=Sbe[db-1];
crcok=ModBusCrcCalc(Sbe,db);
return(crc == crcok);
}
//-----------------------------------------------
bool	_OpenUdp(void)
{
int	ipbe[4],port;
char	ip[20],prt[6];

ipbe[0]=Vezerlo->IpCim1->Text.ToIntDef(0);
ipbe[1]=Vezerlo->IpCim2->Text.ToIntDef(0);
ipbe[2]=Vezerlo->IpCim3->Text.ToIntDef(0);
ipbe[3]=Vezerlo->IpCim4->Text.ToIntDef(0);
port=Vezerlo->UdpPort->Text.ToIntDef(0);
sprintf(ip,"%i.%i.%i.%i",ipbe[0],ipbe[1],ipbe[2],ipbe[3]);
sprintf(prt,"%i",port);
return(OpenUdp(ip,prt));
}
//-----------------------------------------------
/*int	_SorosWrite(int db)
{
if(Vezerlo->Soros->Connected==true){
  Vezerlo->Soros->ClearBuffer(true,true);
  if(db <= SER_SIZE) return(Vezerlo->Soros->Write(Ski,db));
  }
return(0);
}*/
//-----------------------------------------------
/*int	_SorosRead(int db)
{
if(Vezerlo->Soros->Connected == true){
  setmem(Sbe,SER_SIZE,0);
  if(db <= SER_SIZE) return(Vezerlo->Soros->Read(Sbe,db));
  }
return(0);
}*/
//-----------------------------------------------
extern void	ModBusRxChar(int db)
{
if(db > SOROS_LEN) db=SOROS_LEN;			//t�lcsordul�s v�delem
Vezerlo->Soros->Read(Sbe,db);
}
//-----------------------------------------------
Byte	ModBusReadSoros(Byte db,int ms)
{
struct time t;
int	start,stop,bedb;

//if(db > SOROS_LEN) db=SOROS_LEN;
gettime(&t);
start=((t.ti_hour*60+t.ti_min)*60+t.ti_sec)*100+t.ti_hund;
do	{
	gettime(&t);
	stop=((t.ti_hour*60+t.ti_min)*60+t.ti_sec)*100+t.ti_hund;
	bedb=Vezerlo->Soros->InputCount();
	}
while((bedb < db)&&((stop-start) < (ms/10)));
if(bedb > 0) ModBusRxChar(bedb);
return(bedb);
}
//-----------------------------------------------
int	_WriteSoros(Byte db)
{
if(db < SOROS_LEN){
	if(Vezerlo->Soros->Connected == true){
		Vezerlo->Soros->ClearBuffer(true,true);
		return(Vezerlo->Soros->Write(Ski,db));
		}
	}
return(0);
}
//-----------------------------------------------
void	ModBusRxClear(void)
{
memset(Sbe,0,sizeof(Sbe)); //SbeDb=0;
}
//-----------------------------------------------
int	_Kommunikacio(Byte dbki,Byte dbbe)
{
int	cnt,resu=1,i,sum,sumbe;
Word	crc;

if((dbki >= SOROS_LEN)||(dbbe >= SOROS_LEN)) return(80);

Ski[0]=0xa5;
Ski[1]=dbki-1;
crc=ModBusCrcCalc(Ski,dbki);
Ski[dbki-2]=High(crc); Ski[dbki-1]=Low(crc);
Ski[dbki]=0xe1;
if(TcpUdp==0){
	if(_WriteSoros(dbki+0) == dbki+0) resu=0;
	ModBusRxClear();
	cnt=ModBusReadSoros(dbbe,100);		//50ms timeout
	}
else{
	for(i=dbki; i>=0; i--) Ski[i+1]=Ski[i];		//eltol�s az el�tagnak
	switch(SorosNum){
		case 0:	Ski[0]=0xa1; break;
		case 1:	Ski[0]=0xa2; break;
		default:	Ski[0]=0xa5; break;
		}
	dbki++;

	if(DinIp == 1){
		for(i=dbki; i>=0; i--) Ski[i+5]=Ski[i];
		Ski[0]='T';
		Ski[1]='R';		//transfer
		Ski[2]=High(KutSzam);
		Ski[3]=Low(KutSzam);
		Ski[4]='\n';
		dbki+=5;
		}

	_OpenUdp();
	if(SendDataUdp(Ski,dbki)) resu=0;
	ModBusRxClear();
	cnt=ReceiveDataUdp(Sbe);
	CloseUdp();
	}
if(cnt != dbbe) resu+=2;
else	{
	if(!ModBusCrcBe(dbbe)) resu+=10;
	else if((Sbe[0] != 0xa5)||(Sbe[1] != (dbbe-1))) resu+=20;
	}
if(resu == 0)
	return(resu);
return(resu);
}
//-----------------------------------------------
int		MemRead(Byte *Olv, Byte mut, Byte db)
{
int		resu, i;

Ski[2]= 4;	     	//parancs
Ski[3]= mut;    	//c�m mutat�
Ski[4]= db;
Ski[5]= 0;
resu= _Kommunikacio(8, db+6);
if(resu == 0){ if(Sbe[2] != 4) resu+= 40; }
if(resu == 0){ PacketOK++; for(i=0; i<db; i++) Olv[i]= Sbe[i+4]; }
else PacketERR++;
return(resu);
}
//-----------------------------------------------
int		FlashRead(Byte *Olv, Word cim, Byte alcim, Byte len)
{
int		resu, i;

Ski[2]= 3;	    	//parancs
Ski[3]= High(cim);	//c�m
Ski[4]= Low(cim);
Ski[5]= alcim;
Ski[6]= len;
resu= _Kommunikacio(9, len+6);
if(resu == 0){ if(Sbe[2] != 3) resu+= 40; }
if(resu == 0){ PacketOK++; for(i=0; i<len; i++) Olv[i]= Sbe[i+4]; }
else PacketERR++;
return(resu);
}
//-----------------------------------------------
int		FlashWrite(Byte *ir, Word cim, Byte alcim, Byte db)
{
int		resu,i;

Ski[2]= 16;		//parancs
Ski[3]= WR_FLS;	//mut
Ski[4]= High(cim);	//c�m
Ski[5]= Low(cim);
Ski[6]= alcim;
Ski[7]= db;
for(i=0; i<db; i++) Ski[8+i]=ir[i];//Adat
resu= _Kommunikacio(10+db,6);
if(resu == 0){ if((Sbe[2] != 16)||(Sbe[3] != WR_FLS)) resu+= 40; }
if(resu == 0) PacketOK++;
else PacketERR++;
return(resu);
}
//-----------------------------------------------
int	MemWrite(Byte *ir, Byte mut, Byte db)
{
int	resu, i;

if(db > (SOROS_LEN-9)) return(80);

Ski[2]= 16;
Ski[3]= mut;
for(i=0; i<db; i++) Ski[4+i]= ir[i];//Adat
resu=_Kommunikacio(6+db, 6);
if(resu == 0){ if((Sbe[2] != 16)||(Sbe[3] != mut)) resu+= 40; }
if(resu == 0) PacketOK++;
else PacketERR++;
return(resu);
}
//-----------------------------------------------
int	FlashSectorClr(Word sector)
{
int	resu= 0;
Byte	b[12];

b[0]='C';
b[1]='L';
b[2]='R';
b[3]='F';
b[4]='L';
b[5]='S';
b[6]=High(sector);
b[7]=Low(sector);
resu=MemWrite(b,CLR_SECT,8);
return(resu);
}
//-----------------------------------------------
int	OraBeall(Word Ev,Word Ho,Word Nap,Word Ora,Word Perc,Word Mp,Byte Wnap)
{
int	resu=0;
Byte	b[12];

while(Ev>99)Ev-=(Word)100;
b[0]=Ev;
b[1]=Ho;
b[2]=Nap;
b[3]=Ora;
b[4]=Perc;
b[5]=Mp;
b[6]=Wnap;
b[7]=0;
resu=MemWrite(b,RW_ORA,8);
return(resu);
}
//-----------------------------------------------
int	OraKorrBeall(Byte korr)
{
int	resu=0;
Byte	b[2];

b[0]=korr;
b[1]=0;
resu=MemWrite(b,RW_ORA,1);
return(resu);
}
//-----------------------------------------------END
