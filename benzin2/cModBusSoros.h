#ifndef SOROS_MODB_H
#define SOROS_MODB_H
//-------------------------------------
#define High(x)		(*(((Byte*)&x)+1))
#define Low(x)			(*((Byte*)&x))
extern unsigned long	PacketOK,PacketERR;
extern int			TcpUdp; 		//0=soros, 1=UDP
#define UDP_TIMEOUT		899			//Vétel mennyi ideig tartson max (millisecond)
//-------------------------------------DinIP
extern Byte			DinIp;			//0=fixIP, 1=DinIP
extern Byte			SorosNum;			//0=régi NET prg, 1=RS485/232, 2=RS232
extern Word			KutSzam;
//-------------------------------------MODEM
//#define				SER_SIZE	200
//extern Byte			be[SER_SIZE],ki[SER_SIZE];
//-------------------------------------
#define				SOROS_LEN	255  	//max.255
extern Byte			Sbe[SOROS_LEN+1],Ski[SOROS_LEN+1];

#define	RD_MEM		0x00
//#define	RD_MNU		0x02
#define	RW_CARD		0x04
#define	RD_SZINT		0x05
#define	RW_ORA		0x06
#define	RW_ARAK		0x07
#define	RW_EEPROM		0x08
//#define	RD_NET		0x0a
//#define	RD_FLS		0x0c
#define	RW_CEG		0x0e
#define	RW_SZINT		0x10
#define	RD_KUT		0x20	//x20-x2e 15db
#define	RD_TANK		0x40	//x40,41 - x5e,5f 16db
#define	CLR_SECT		0x60
#define	WR_PFLSPAR	0x70	//program flash parancs(r/w/e+page+cím)
#define	RD_PFLSROW	0x72	//read program flash row
#define	WR_FLS		0x74	//data flash write

extern int	MemRead		(Byte *Olv,Byte mut,Byte db);
extern int	MemWrite		(Byte *ki,Byte mut,Byte db);
extern int	FlashRead		(Byte *Olv,Word cim,Byte alcim,Byte len);
extern int	FlashWrite	(Byte *ir,Word cim,Byte alcim,Byte db);
extern int	FlashSectorClr	(Word sector);
extern int	OraBeall 		(Word Ev,Word Ho,Word Nap,Word Ora,Word Perc,Word Mp,Byte Wnap);
extern int	OraKorrBeall	(Byte korr);
#endif
//-------------------------------------END

