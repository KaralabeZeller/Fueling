//===============================================
// BVEZ2 Flash csomag SPI-vel
//===============================================
#include <stdint.h>

#include "asmFlash.h"
#include "Sflash16M.h"
#include "Bvez2.h"
#include "SorosMod232.h"
//-----------------------------------------------Belsõ változók
enum	F_ParType{
		F_READY,
		FS_RD,
		FS_WR,
		FS_WR_2,
		FS_RD_ID,
		FP_RD,
		FP_RD_OK,
		FP_WR,
		FP_WR_2,
		FP_ERASE,
		FP_ERASE2
		};
uint16_t		F_Mut=0;					//Fls olv/ír aktuális mutató
uint16_t		F_Db=0;						//Fls olvas/ír db (0=ready -> ezt figyeli minden)
uint16_t		F_Tilt100u=0;				//*100us Fls tiltás írás után
uint8_t			*F_Tar;						//Fls olvas/ír adatterület
uint8_t			F_WrTar[6];					//írás enable puffer
enum F_ParType	F_Par=F_READY;				//aktív parancs
//-----------------------------------------------Külsö változók
struct FlsStru	Fls;
//===============================================RESET
void	SPI2_Init(void)
{
FLS_nCS1= 1;	TRIS_FLS_nCS1= TRIS_KI;	//Flash nCS1		KI=1
FLS_nCS2= 1;	TRIS_FLS_nCS2= TRIS_KI;	//Flash nCS2		KI=1
FLS_CK= 0;		TRIS_FLS_CK= TRIS_KI;	//Flash Clock		KI=0
FLS_DI= 0;		TRIS_FLS_DI= TRIS_BE;	//Flash Data Out	BE
FLS_DO= 0;		TRIS_FLS_DO= TRIS_KI;	//Flash Data In		KI=0

SPI2STAT= 0;				//disable the SPI module
SPI2CON1= 0x012e;			//000,DISSCK=0;DISSDO=0,MODE16=0,SMP=0,CKE=1; SSEN=0,CKP=0,MSTEN=1,SPRE=011,PPRE=10;(5*4/40=0,5us=2MHz/max.33Mhz)
SPI2CON2= 0;				//FRAMEN=0,SPIFSD=0,FRMPOL=0,0;0000; 0000;00,FRMDLY=0,0
SPI2STAT= 0x8000;			//enable the SPI module

//IFS2bits.SPI2IF= 0;		// Clear Spi2 Interrupt Flag
//IPC8bits.SPI2IP=INT_PRIORITY_FLASH;// Set Spi2 Interrupt Priority Level (1-6)
//IEC2bits.SPI2IE= 0;//1	// Enable Spi2 interrupt
}
//===============================================Int7u
#define	SPI_ROV	0x0040	//overrun error
//		SPI_TBF	0x0002	//transmit full (0-ok,1-tele)
#define	SPI_RBF	0x0001	//receive full (0-nincs,1-van adat)
void __attribute__ ((section("SflashRd_L"))) Fls_Int_7u_L(void)//#35
{
uint8_t		be;

if(SPI2STAT & SPI_ROV) SPI2STATbits.SPIROV= 0;	//clear overrun
be= SPI2BUF;
if(F_Db > 0){
	if(F_Mut < F_Db){							//van adandó
		SPI2BUF= F_Tar[F_Mut]; F_Tar[F_Mut]= be;
		F_Mut++;
		}
	else{ FLS_nCS1= 1; FLS_nCS2= 1; F_Db= 0; }	//adás vége
	}
}
//===============================================Upgrade
void __attribute__ ((section("SflashRd_H"),address (0x015006+0x88))) _F_Int_7u_H(void)//#32
{
uint8_t		be;

if(SPI2STAT & SPI_ROV) SPI2STATbits.SPIROV= 0;	//clear overrun
be= SPI2BUF;
if(F_Db > 0){
	if(F_Mut < F_Db){							//van adandó
		SPI2BUF= F_Tar[F_Mut]; F_Tar[F_Mut]= be;
		F_Mut++;
		}
	else{ FLS_nCS1= 1; FLS_nCS2= 1; F_Db= 0; }	//adás vége
	}
}
//-----------------------------------------------
int __attribute__ ((section("SflashRd_L")))	_F_ReadUpg128_L(uint16_t cim, uint8_t alcim)//128=[931us]
{
uint16_t	wait= 0;

F_Tar=Fls.Sys.Tar;
F_Tar[0]=0x03;
F_Tar[1]= ((uint8_t)(cim >> 8))&0x7f;				//Cím(*256b)[faaa,aaaa;aaaa,aaaa]	256byte/page [2*8M]
F_Tar[2]= (uint8_t)(cim & 0x00ff);					//Cim.l
F_Tar[3]= alcim;									//Cím(0-255)[bbbb,bbbb]
FLS_nCS1= 0;										//CS start
F_Mut= 0;
F_Db= 4+128+1;										//Start
Fls_Int_7u_L();
while((wait < 0xffff)&&(F_Db != 0)){
	wait++;											//para
	if(SPI2STAT & SPI_RBF) Fls_Int_7u_L();			//ha van vett
	}
if(wait == 0xffff) return(1);
return(0);
}
//-----------------------------------------------
int __attribute__ ((section("SflashRd_H")))	_F_ReadUpg128_H(uint16_t cim, uint8_t alcim)//128=[931us]
{
uint16_t	wait=0;

F_Tar= Fls.Sys.Tar;
F_Tar[0]= 0x03;
F_Tar[1]= ((uint8_t)(cim >> 8))&0x7f;				//Cím(*256b)[faaa,aaaa;aaaa,aaaa]	256byte/page [2*8M]
F_Tar[2]= (uint8_t)(cim & 0x00ff);					//Cim.l
F_Tar[3]= alcim;									//Cím(0-255)[bbbb,bbbb]
FLS_nCS1= 0;										//CS start
F_Mut= 0;
F_Db= 4+128+1;									//Start
_F_Int_7u_H();
while((wait < 0xffff)&&(F_Db != 0)){
	wait++;										//para
	if(SPI2STAT & SPI_RBF) _F_Int_7u_H();		//ha van vett
	}
if(wait == 0xffff) return(1);
return(0);
}
//-----------------------------------------------
int __attribute__ ((section("SflashRd_L")))	Fls_ReadUpg256_L(uint16_t cim256)//soros hívja
{
int			i;
char		*mut= (char*)FlsRow;
uint16_t	cim= FLS_UPGRMIN+cim256;
uint16_t	wait= 0;

while((wait < 0xffff)&&((F_Db != 0)||(F_Tilt100u != 0))) wait++;//foglalt-megvár
if(wait == 0xffff) return(1);					//para

FlsIntDisable= 10000;							//10mp stop
if(_F_ReadUpg128_L(cim, 0) != 0) return(1);
for(i=0; i<128; i++) mut[i]=	Fls.Sys.Tar[i+5];//4+1
if(_F_ReadUpg128_L(cim, 0x80) != 0) return(1);
for(i=0; i<128; i++) mut[i+128]= Fls.Sys.Tar[i+5];//4+1
FlsIntDisable= 10;								//10m stop még
return(0);
}
//-----------------------------------------------
int __attribute__ ((section("SflashRd_H")))	_F_ReadUpg256_H(uint16_t cim256)
{
int			i;
char		*mut= (char*)FlsRow;
uint16_t	cim= FLS_UPGRMIN+cim256;

FlsIntDisable= 10000;							//10mp stop
if(_F_ReadUpg128_H(cim, 0) != 0) return(1);
for(i=0; i<128; i++) mut[i]=	Fls.Sys.Tar[i+5];//4+1
if(_F_ReadUpg128_H(cim, 0x80) != 0) return(1);
for(i=0; i<128; i++) mut[i+128]= Fls.Sys.Tar[i+5];//4+1
FlsIntDisable= 10;								//10m stop még
return(0);
}
//-----------------------------------------------
int __attribute__ ((section("SflashRd_L")))	Fls_UpgradeStart_L(void)//soros hívja
{
uint16_t	cim256, page, addr;
//*** verzió ellen?riz
//*** chksum ellen?riz

for(cim256=0x02a0; cim256<0x02b0; cim256++){
	if(Fls_ReadUpg256_L(cim256) != 0) return(1);
	page= cim256/512;
	addr= cim256*128;
	if((addr&0x03ff) == 0) EraseFls_L(page, addr);//use:-
	WriteLatch64_L(page, addr);//use:-
	}
return(0);
}
//-----------------------------------------------
int __attribute__ ((section("SflashRd_H")))	Fls_UpgradeStart_H(void)//soros hívja
{
uint16_t	cim256, page, addr;
uint16_t	wait= 0;
//*** verzió ellen?riz
//*** chksum ellen?riz
//*** tank stop

while((wait < 0xffff)&&((F_Db != 0)||(F_Tilt100u != 0))) wait++;//foglalt-megvár
if(wait == 0xffff) return(1);					//para

T3CON = 0;						// Timer reset
T6CON = 0;						// Timer reset
T4CON = 0;						// Timer reset
T2CON = 0;						// Timer reset
IEC0bits.T3IE=0;				//1,6ms	- Disable Timer3 interrupt
IEC2bits.T6IE=0;				//1ms	- Disable Timer6 interrupt
IEC1bits.T4IE=0;				//100us	- Disable Timer4 interrupt
IEC0bits.T2IE=0;				//7us	- Disable Timer2 interrupt

for(cim256=0; cim256<0x02a0; cim256++){
//	if(Fls_ReadUpg256_H(cim256) != 0) return(1);	NINCS visszaút !!!
	_F_ReadUpg256_H(cim256);
	page= cim256/512;
	addr= cim256*128;
	if((addr&0x03ff)==0) EraseFls_H(page, addr);//use:-
	WriteLatch64_H(page, addr);//use:-
	}
ResetK4_H();
return(0);	//csak syntax
}
//-----------------------------------------------END section
#define	VERZ_LEN		6
#define	ASM_PGM_LEN		0x88
#define	C_PGM_LEN		0x1d6
#define	FLSRD_LEN		(VERZ_LEN+ASM_PGM_LEN+C_PGM_LEN)
const char	__attribute__ ((space(psv),noload,address (0x015000+FLSRD_LEN))) Fls_Ures_H[0x07fc - FLSRD_LEN];
const int	__attribute__ ((space(psv),noload,address (0x0157fe))) Fls_END;
//===============================================Interrupt-100u
void	F_Start(uint16_t cim256, uint16_t db)
{
if((db > 0)&&(db <= FLS_TAR_LEN)){
	if(cim256 < 0x8000) FLS_nCS1= 0; else FLS_nCS2= 0;//CS start
	F_Mut= 0;
	F_Db= db;										//Start
	}
}
//-----------------------------------------------Int-100u
void	F_ToltTar4(uint8_t par, uint16_t cim256, uint8_t cim1)
{
F_Tar[0]= par;
F_Tar[1]= ((uint8_t)(cim256 >> 8))&0x7f;			//Cím(*256b)[faaa,aaaa;aaaa,aaaa]	256byte/page [2*8M]
F_Tar[2]= (uint8_t)(cim256 & 0x00ff);				//Cim.l
F_Tar[3]= cim1;									//Pc Cím(0-255)[bbbb,bbbb]
}
//-----------------------------------------------Int-100u
void	F_RdIdSys(void)							//[35us]
{
Fls.Sys.Be= &Fls.Sys.Tar[1+1];
F_Tar= Fls.Sys.Tar;
F_ToltTar4(0x9f, Fls.Sys.Cim256, Fls.Sys.Cim1);	//Parancs=Read data bytes
F_Start(Fls.Sys.Cim256, 5);//1+3+1				//5db (35us)
}
//-----------------------------------------------Int-100u
void	F_ReadSys(void)							//10=[105us],64=[483us],128=[931us]
{
Fls.Sys.Be= &Fls.Sys.Tar[4+1];
F_Tar= Fls.Sys.Tar;
F_ToltTar4(0x03, Fls.Sys.Cim256, Fls.Sys.Cim1);	//Parancs=Read data bytes
F_Start(Fls.Sys.Cim256, 5+Fls.Sys.Db);//4+1		//15db (105us)
}
//-----------------------------------------------Int-100u
void	F_ReadPc(void)							//10=[105us],64=[483us],128=[931us]
{
Fls.Pc.Be= &Fls.Pc.Tar[4+1];
F_Tar= Fls.Pc.Tar;
F_ToltTar4(0x03, Fls.Pc.Cim256, Fls.Pc.Cim1);	//Parancs=Read data bytes
F_Start(Fls.Pc.Cim256, 5+Fls.Pc.Db);//4+1		//15db (105us)
}
//-----------------------------------------------Int-100u
void	F_WriteSys(void)
{
F_Tilt100u= 40;									//(5+128)*7u=818us+(max.3ms)-utána
F_Tar= Fls.Sys.Tar;
F_ToltTar4(0x02, Fls.Sys.Cim256, Fls.Sys.Cim1);	//Page Program
F_Start(Fls.Sys.Cim256, 4+Fls.Sys.Db);
}
//-----------------------------------------------Int-100u
void	F_WritePc(void)
{
F_Tilt100u= 40;									//(5+128)*7u=818us+(max.3ms)-utána
F_Tar= Fls.Pc.Tar;
F_ToltTar4(0x02, Fls.Pc.Cim256, Fls.Pc.Cim1);	//Page Program
F_Start(Fls.Pc.Cim256, 4+Fls.Pc.Db);
}
//-----------------------------------------------Int-100u
void	F_WrEnCim(uint16_t cim256)
{
F_Tar= F_WrTar;
F_Tar[0]= 0x06;									//Write enable
F_Start(cim256, 1);
}
//-----------------------------------------------Int-100u
void	F_SectClrCim(uint16_t cim256)			//401ms
{
F_Tilt100u= 4010;								//(max.400ms)+1ms
F_Tar= F_WrTar;
F_ToltTar4(0x20, cim256, 0);					//Sector erase(4kb)
F_Start(cim256, 4);
}
//-----------------------------------------------Int-100u
void	F_TankWrite1(uint8_t kut)
{
uint8_t		*ki;
uint16_t	cim= M.TankDb;
uint16_t	i;

if(cim >= FLS_TANKSTOP) return;
Tank[kut].TankCim= cim;
M.TankDb++;

Fls.Sys.Cim256= cim/2;
if((cim&0x0001) != 0) Fls.Sys.Cim1= 128; else Fls.Sys.Cim1= 0;
ki= (uint8_t*)(&Tank[kut].KezdVerz);
for(i=0; i<100; i++) Fls.Sys.Tar[4+i]= ki[i];	//bemásol
Fls.Sys.Db= 100; F_Par= FS_WR;
Tank[kut].Mentes= MENT_OK_1;						//elsõ mentés megvolt
}
//-----------------------------------------------Int-100u
void	F_TankWrite2(uint8_t kut)
{
uint8_t		*ki;
uint16_t	cim;
int			i;

cim= Tank[kut].TankCim;
if(cim >= FLS_TANKSTOP) return;

Fls.Sys.Cim256= cim/2;
if((cim&0x0001) != 0) Fls.Sys.Cim1= 128+100; else Fls.Sys.Cim1= 0+100;
ki= (uint8_t*)(&Tank[kut].ZarEv);
for(i=0; i<28; i++) Fls.Sys.Tar[4+i]=ki[i];//bemásol
Fls.Sys.Db= 28; F_Par= FS_WR;
Tank[kut].Mentes= MENT_OK_2;					//második mentés megvolt
}
//-----------------------------------------------Int-100u
void	Fls_Ciklus_Tank100u(void)
{
if		(Tank[0].Mentes == MENT_STR1)	F_TankWrite1(0);
else if	(Tank[1].Mentes == MENT_STR1)	F_TankWrite1(1);
else if	(Tank[2].Mentes == MENT_STR1)	F_TankWrite1(2);
else if	(Tank[3].Mentes == MENT_STR1)	F_TankWrite1(3);
else if	(Tank[4].Mentes == MENT_STR1)	F_TankWrite1(4);
else if	(Tank[5].Mentes == MENT_STR1)	F_TankWrite1(5);
else if	(Tank[6].Mentes == MENT_STR1)	F_TankWrite1(6);
else if	(Tank[7].Mentes == MENT_STR1)	F_TankWrite1(7);
else if	(Tank[8].Mentes == MENT_STR1)	F_TankWrite1(8);
else if	(Tank[9].Mentes == MENT_STR1)	F_TankWrite1(9);
else if	(Tank[10].Mentes == MENT_STR1)	F_TankWrite1(10);
else if	(Tank[11].Mentes == MENT_STR1)	F_TankWrite1(11);
else if	(Tank[12].Mentes == MENT_STR1)	F_TankWrite1(12);
else if	(Tank[13].Mentes == MENT_STR1)	F_TankWrite1(13);
else if	(Tank[14].Mentes == MENT_STR1)	F_TankWrite1(14);

else if	(Tank[0].Mentes == MENT_STR2)	F_TankWrite2(0);
else if	(Tank[1].Mentes == MENT_STR2)	F_TankWrite2(1);
else if	(Tank[2].Mentes == MENT_STR2)	F_TankWrite2(2);
else if	(Tank[3].Mentes == MENT_STR2)	F_TankWrite2(3);
else if	(Tank[4].Mentes == MENT_STR2)	F_TankWrite2(4);
else if	(Tank[5].Mentes == MENT_STR2)	F_TankWrite2(5);
else if	(Tank[6].Mentes == MENT_STR2)	F_TankWrite2(6);
else if	(Tank[7].Mentes == MENT_STR2)	F_TankWrite2(7);
else if	(Tank[8].Mentes == MENT_STR2)	F_TankWrite2(8);
else if	(Tank[9].Mentes == MENT_STR2)	F_TankWrite2(9);
else if	(Tank[10].Mentes == MENT_STR2)	F_TankWrite2(10);
else if	(Tank[11].Mentes == MENT_STR2)	F_TankWrite2(11);
else if	(Tank[12].Mentes == MENT_STR2)	F_TankWrite2(12);
else if	(Tank[13].Mentes == MENT_STR2)	F_TankWrite2(13);
else if	(Tank[14].Mentes == MENT_STR2)	F_TankWrite2(14);
}
//-----------------------------------------------Int-100u
void	Fls_Ciklus_100u(void)
{
if(F_Db != 0) return;							//foglalt
if(F_Tilt100u != 0){ F_Tilt100u--; return; }	//tiltva van

switch(F_Par){			//system
	case F_READY:	Fls_Ciklus_Tank100u();			break;	//ráér

	case FS_RD:		F_ReadSys();					F_Par= F_READY; break;
	case FS_WR:		F_WrEnCim(Fls.Sys.Cim256);		F_Par= FS_WR_2; break;
	case FS_WR_2:	F_WriteSys();					F_Par= F_READY; break;
	case FS_RD_ID:	F_RdIdSys();					F_Par= F_READY; break;	//RESET-hez
							//pc
	case FP_RD:		F_ReadPc();						F_Par= FP_RD_OK; break;
	case FP_RD_OK:	Rs232_RdFls_Valasz(Fls.Pc.Db);	F_Par= F_READY; break;

	case FP_WR:		F_WrEnCim(Fls.Pc.Cim256);		F_Par= FP_WR_2; break;
	case FP_WR_2:	F_WritePc();					F_Par= F_READY; break;
	case FP_ERASE:	F_WrEnCim(Fls.Pc.Cim256);		F_Par= FP_ERASE2; break;
	case FP_ERASE2:	F_SectClrCim(Fls.Pc.Cim256);	F_Par= F_READY; break;

	default:		F_Par= F_READY;			//para
	}
}
//=========================================================Int-1ms
//---------------------------------------------------------Int-1ms + Alap
uint8_t		FlsSzabad(void)							//0=foglalt, 1=szabad
{
if((F_Par == F_READY)&&(F_Db == 0)&&(F_Tilt100u == 0)) return(1);
return(0);
}
//---------------------------------------------------------Int-1ms
uint8_t		FlsPcRd(uint16_t cim, uint8_t alcim, uint8_t len)		//0=foglalt, 1=ok
{
if(len > 128) return(0);
if(FlsSzabad() == 0) return(0);
Fls.Pc.Cim256= cim;
Fls.Pc.Cim1= alcim;
Fls.Pc.Db= len; F_Par= FP_RD;
return(1);
}
//---------------------------------------------------------Int-1ms
uint8_t		FlsPcWrCard(uint8_t *tar)	//0=foglalt, 1=ok
{
uint8_t		i;
uint16_t	cim= M.CardDb;

if(FlsSzabad() == 0) return(0);
Fls.Pc.Cim256= cim/2+FLS_CARDMIN;
Fls.Pc.Cim1= (cim&1)*128;
for(i=0; i<64; i++) Fls.Pc.Tar[4+i]= tar[i];		//bemásol
Fls.Sys.Db= 64; F_Par= FP_WR;
M.CardDb++;
return(1);
}
//---------------------------------------------------------Int-1ms
uint8_t		FlsPcWrCeg(uint8_t *tar)	//0=foglalt, 1=ok
{
uint8_t		i;
uint16_t	cim= M.CegDb;

if(FlsSzabad() == 0) return(0);
Fls.Pc.Cim256= cim/2+FLS_CEGMIN;
Fls.Pc.Cim1= (cim&1)*128;
for(i=0; i<128; i++) Fls.Pc.Tar[4+i]= tar[i];	//bemásol
Fls.Pc.Db= 128; F_Par= FP_WR;
M.CegDb++;
return(1);
}
//---------------------------------------------------------Int-1ms
uint8_t		FlsPcWrUpgrade(uint8_t *tar, uint16_t cim, uint8_t alcim)//0=foglalt, 1=ok
{
uint8_t		i;

//ggg-v70	if((cim < FLS_UPGRMIN)||(cim > FLS_UPGRMAX)) return(0);
if(cim > FLS_UPGRMAX) return(0);
if(FlsSzabad() == 0) return(0);
Fls.Pc.Cim256= cim;
Fls.Pc.Cim1= alcim;
for(i=0; i<128; i++) Fls.Pc.Tar[4+i]= tar[i];	//bemásol
Fls.Pc.Db= 128; F_Par= FP_WR;
return(1);
}
//---------------------------------------------------------Int-1ms
uint8_t		FlsPcWrArak(uint8_t *tar)	//0=foglalt, 1=ok
{
uint8_t		i;
uint16_t	cim= M.ArakDb;

if(FlsSzabad() == 0) return(0);
Fls.Pc.Cim256= cim/8+FLS_ARAKMIN;
Fls.Pc.Cim1= (cim&7)*32;
for(i=0; i<32; i++) Fls.Pc.Tar[4+i]= tar[i];		//bemásol
Fls.Pc.Db= 32; F_Par= FP_WR;
M.ArakDb++;
return(1);
}
//---------------------------------------------------------Int-1ms
uint8_t		FlsPcWrSzint(uint8_t *tar, uint16_t cim)	//0=foglalt, 1=ok
{
uint8_t		i;

if(FlsSzabad() == 0) return(0);
Fls.Pc.Cim256= cim/2+FLS_SZINTMIN;
Fls.Pc.Cim1= (cim&1)*128;
for(i=0; i<122; i++) Fls.Pc.Tar[4+i]= tar[i];	//bemásol
Fls.Pc.Db= 122; F_Par= FP_WR;
return(1);
}
//---------------------------------------------------------Int-1ms
uint8_t		FlsPcBlkErase(uint16_t cim)					//0=foglalt, 1=ok
{
if(FlsSzabad() == 0) return(0);
Fls.Pc.Cim256= cim;
F_Par= FP_ERASE;
return(1);
}
//=========================================================Alap
void	_VarFls(void)							//megvárja a flasht
{
while((F_Par != F_READY)||(F_Db != 0)||(F_Tilt100u != 0)) ;
}
//---------------------------------------------------------Reset
void	VarFlsRdID_Alap(uint16_t pag)			//100us
{
_VarFls();
Fls.Sys.Cim256= pag;
F_Par= FS_RD_ID;
_VarFls();
}
//---------------------------------------------------------Alap
void	VarFlsRead_Alap(uint16_t cim, uint8_t alcim, uint8_t db)	//(db+5)*7us
{
_VarFls();
Fls.Sys.Cim256= cim;
Fls.Sys.Cim1= alcim;
Fls.Sys.Db= db; F_Par= FS_RD;
_VarFls();
}
//=========================================================END
