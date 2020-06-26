#ifndef _SFLASH_H
#define _SFLASH_H
//-------------------------------------1.flash[8Mb=2048(128*32=4kb)sector]->65536db
//#define	FLS_TANKMIN		0x0000		//Tankolási adatok (64000db)
#define		FLS_TANKMAX		0x7cff
#define		FLS_TANKSTOP	0xf9fc		//nem enged többet tankolni
#define		FLS_UPGRMIN		0x7d00		//upgrade verzió 0x030000=192kbyte
#define		FLS_UPGRMAX		0x7fff
//-------------------------------------2.flash[8Mb=2048(256*16=4kb)sector]->32768db
#define		FLS_CARDMIN		0x8000		//Kártya adatok [128b](65536/8*6=49152db) - 32db/blk
#define		FLS_CARDMAX		0xdfff
#define		FLS_ARAKMIN		0xe000		//Ár adatok [32b](8192*8=65536db) - 128db/blk
#define		FLS_ARAKMAX		0xefff
#define		FLS_CEGMIN		0xf000		//Fél-Cég adatok [128b](8192db fél) - 32db/blk
#define		FLS_CEGMAX		0xffef
#define		FLS_SZINTMIN	0xfff0		//Negyed-Szint adatok [128b](32db negyed) - 16db/blk
#define		FLS_SZINTMAX	0xffff		//4kbyte erase (16*256)
//---------------------------------------------------------
#define	FLS_TAR_LEN	5+128+1+2				//5parancs+128adat
struct Fls_struct{
	uint16_t			Cim256;				//Cím(*256b)[faaa,aaaa;aaaa,aaaa]	256byte/page [2*8M]
	uint8_t				Cim1;				//Cím(0-255)[bbbb,bbbb]		page-en belüli cím
	uint8_t				Db;					//írandó/olvasandó byte db
	uint8_t				*Be;				//olvasott pointer
	uint8_t				Tar[FLS_TAR_LEN];	//írás/olvasás puffer
	};
struct FlsStru{
	struct Fls_struct	Sys, Pc;
	};
extern struct FlsStru	Fls;
//---------------------------------------------------------
extern void			SPI2_Init(void);						//Reset
extern void			Fls_Int_7u_L(void);
extern int			Fls_ReadUpg256_L(uint16_t cim256);		//0=siker, 1=hiba
extern int			Fls_UpgradeStart_L(void);				//0=siker, 1=hiba
extern int			Fls_UpgradeStart_H(void);				//0=siker, 1=hiba

extern void			Fls_Ciklus_100u(void);					//Interrupt
extern void			VarFlsRdID_Alap(uint16_t pag);			//Reset
extern void			VarFlsRead_Alap(uint16_t cim, uint8_t alcim, uint8_t db);//db*10.5us

extern uint8_t		FlsPcRd(uint16_t cim, uint8_t alcim, uint8_t len);//0=foglalt, 1=ok
extern uint8_t		FlsPcWrCard(uint8_t *tar);				//0=foglalt, 1=ok
extern uint8_t		FlsPcWrCeg(uint8_t *tar);				//0=foglalt, 1=ok
extern uint8_t		FlsPcWrArak(uint8_t *tar);				//0=foglalt, 1=ok
extern uint8_t		FlsPcWrUpgrade(uint8_t *tar, uint16_t cim, uint8_t alcim);//0=foglalt, 1=ok
extern uint8_t		FlsPcWrSzint(uint8_t *tar, uint16_t cim);//0=foglalt, 1=ok
extern uint8_t		FlsPcBlkErase(uint16_t cim);			//0=foglalt, 1=ok
//---------------------------------------------------------
#endif
