//-----------------------------------------------
// BENZIN flash rutinok
//-----------------------------------------------
#include "Bvez2.h"
#include "Sflash16M.h"
//===============================================Alap
uint16_t	Fls_TankDb(uint8_t kut,char kapcs)//A=auto,E=ember
{
uint8_t				ev= Ora.Ev, ho= Ora.Ho, nap= Ora.Nap;//hogy változatlan maradjon
uint16_t			db= 0, blk= M.TankDb;
struct TANK_Stru	*be= (struct TANK_Stru *)Fls.Sys.Be;

if(kut >= KUTFO_DB) return(0);
while(blk > 0){
	blk--;
	VarFlsRead_Alap(blk/2, (blk&1)*128, 36);		//41*7=287us
	if((be->KezdEv == ev)&&(be->KezdHo == ho)&&(be->KezdNap == nap)){//aznapi
		if		((kapcs=='A')&&(MemCmp(be->AutoId, Tank[kut].AutoId, 7) == 0)) db++;
		else if	((kapcs=='E')&&(MemCmp(be->EmberId, Tank[kut].EmberId, 7) == 0)) db++;
		}
	else blk= 0;
	}
return(db);
}
//-----------------------------------------------Alap
void		Fls_KmMax(uint8_t kut)// Visszafelé keresve az utolsó kártya tankolasrekordjának km értéke
{
uint16_t			blk= M.TankDb;
struct TANK_Stru	*be= (struct TANK_Stru *)Fls.Sys.Be;

if(kut >= KUTFO_DB) return;
Mnu.KmElozo=0;
while(blk > 0){
	blk--;
	VarFlsRead_Alap(blk/2, (blk&1)*128, 36);		//41*7=287us
	if(MemCmp(be->AutoId, Tank[kut].AutoId, 7) == 0){
		MemCpy((uint8_t*)&Mnu.KmElozo, &Fls.Sys.Be[0x1e], 4);
//		Mnu.KmElozo=be->Km;
//		Mnu.KmElozo=*((Dword*)&Fls.Sys.Be[0x1e]);
		blk= 0;
		}
	}
}
//-----------------------------------------------Alap
void		Fls_CegTolt(struct CEG_Stru *c, uint16_t num)//utsó keres -> 0-nincs,1-alsó,2-felsõ,3mindkettõ van
{
uint8_t		i, van= 0;
uint16_t	blk, csop, tip;

for(i=0; i<6; i++) c->Nev[i][0]= '!';	//kikapcs
blk= M.CegDb;
while((blk > 0)&&(van < 3)){
	blk--;
	VarFlsRead_Alap(blk/2+FLS_CEGMIN, (blk&1)*128, 10);	//105us
	tip=	(uint16_t)Fls.Sys.Be[1]*256+Fls.Sys.Be[0];
	csop=	(uint16_t)Fls.Sys.Be[3]*256+Fls.Sys.Be[2];
	if(csop == num){
		if(tip == 0x4001){
			if((van&1) == 0){
				VarFlsRead_Alap(blk/2+FLS_CEGMIN, (blk&1)*128+0x10, 96);//700us
				MemCpy(c->Nev[0], Fls.Sys.Be, 96);		//1,2,3 sor
				van|= 1;
				}
			}
		else if(tip == 0x5001){
			if((van&2) == 0){
				VarFlsRead_Alap(blk/2+FLS_CEGMIN, (blk&1)*128+0x10, 96);
				MemCpy(c->Nev[3], Fls.Sys.Be, 96);		//4,5,6 sor
				van|= 2;
				}
			}
		}
	}
}
//-----------------------------------------------Alap
void		Fls_ArakTolt(struct ARAK_Stru *a, uint16_t num)//utsó keres -> 0-nincs,1-van
{
uint8_t		van= 0;
uint16_t	blk, csop, tip, cim;

a->Ar0Netto= 0; a->Ar1Netto= 0;			//kikapcs
blk= M.ArakDb;
while((blk > 0)&&(van < 1)){
	blk--;
	cim= blk/8;
	VarFlsRead_Alap(blk/8+FLS_ARAKMIN, (blk&7)*32, 10);	//105us//***32b
	tip=	(uint16_t)Fls.Sys.Be[1]*256+Fls.Sys.Be[0];
	csop=	(uint16_t)Fls.Sys.Be[3]*256+Fls.Sys.Be[2];
	if(csop == num){
		if(tip == 0x6001){
			if(van == 0){
				MemCpy((uint8_t*)&a->RecTip, Fls.Sys.Be, 8);//2*Word betölt
				van= 1;
				}
			}
		}
	}
}
//===============================================Alap
uint8_t		Card_SearchId(void)	//->1=nincs,2=chk error,0=OK->Card-ba betöltve
{
uint16_t	cim= M.CardDb, megvan= 0;
uint16_t	i, x= 0;
uint8_t		*tar= Fls.Sys.Be;

MemSet((uint8_t*)&Card.Tip, 0, CARD_LEN-9);
do	{
	VarFlsRead_Alap(cim/2+FLS_CARDMIN, (cim&1)*128, 10);//105us
	if(MemCmp(&Fls.Sys.Be[2],Card.Id, 7) == 0) megvan= 1;
	else if(cim == 0) return(1);				//nincs meg
	else cim--;
	}
while(megvan == 0);		//28672*105u=3010ms

VarFlsRead_Alap(cim/2+FLS_CARDMIN, (cim&1)*128, 64);
for(i=0; i<62; i++) x+= tar[i];	//chksum
if((tar[62] != lo(x))||(tar[63] != hi(x))) return(2);//ChkSum error

Card.RecTip=	(uint16_t)tar[0x00]*256+tar[0x01];
//MemCpy(Card.Id,&tar[0x02],7);
Card.Tip=		tar[0x09];
Card.MaxLit=	(uint16_t)tar[0x0a]*256+tar[0x0b];
Card.MaxDb=		(uint16_t)tar[0x0c]*256+tar[0x0d];
Card.Pin=		(uint16_t)tar[0x0e]*256+tar[0x0f];
Card.Kutak=		(uint16_t)tar[0x10]*256+tar[0x11];
Card.Num=		(uint16_t)tar[0x12]*256+tar[0x13];
Card.Csoport=	(uint16_t)tar[0x14]*256+tar[0x15];
Card.Print=		tar[0x16];
Card.Ev=		tar[0x17];
Card.Ho=		tar[0x18];
Card.Nap=		tar[0x19];
Card.Ora=		tar[0x1a];
Card.Perc=		tar[0x1b];
Card.Mp=		tar[0x1c];
MemCpy(Card.Nev, &tar[0x1d], 20);
return(0);		//ok
}
//-----------------------------------------------
uint8_t		ures[10]= {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
//-----------------------------------------------
void		Card_SrcUres(void)
{
uint16_t	blk, cim, al;

for(blk=FLS_CARDMIN+15; blk<FLS_CARDMAX; blk+=16){	//1792*105u=189ms
	VarFlsRead_Alap(blk, 128, 10); if(MemCmp(Fls.Sys.Be, ures, 10) == 0) break;//elsõ üres
	}
blk-= 15;
for(cim=0; cim<16; cim++){							//16*105u=2ms
	VarFlsRead_Alap(blk+cim, 128, 10); if(MemCmp(Fls.Sys.Be, ures, 10) == 0) break;//elsõ üres 256b felsõ
	}
VarFlsRead_Alap(blk+cim, 0, 10); if(MemCmp(Fls.Sys.Be, ures, 10) == 0) al= 0; else al= 1;//elsõ üres 128b
M.CardDb= (blk+cim-FLS_CARDMIN)*2+al;
}
//-----------------------------------------------
void		Tank_SrcUres(void)
{
uint16_t	blk, cim, al;

for(blk=15; blk<FLS_TANKMAX; blk+=16){				//2048*105u=215ms				//16*256b=4kbyte=1blokk(32db tankolás)
	VarFlsRead_Alap(blk, 128, 10); if(MemCmp(Fls.Sys.Be, ures, 10) == 0) break;		//elsõ üres blokk fels? fél
	}
blk-= 15;
for(cim=0; cim<16; cim++){							//16*105u=2ms
	VarFlsRead_Alap(blk+cim, 128, 10); if(MemCmp(Fls.Sys.Be, ures, 10) == 0) break;	//elsõ üres 256b felsõ fél
	}
VarFlsRead_Alap(blk+cim, 0, 10); if(MemCmp(Fls.Sys.Be, ures, 10) == 0) al= 0; else al= 1;//elsõ üres 128b
M.TankDb= (blk+cim)*2+al;
}
//-----------------------------------------------
void		Ceg_SrcUres(void)
{
uint16_t	blk, cim, al;

for(blk=FLS_CEGMIN+15; blk<FLS_CEGMAX; blk+=16){	//4095*105u=430ms
	VarFlsRead_Alap(blk, 0x80, 10); if(MemCmp(Fls.Sys.Be, ures, 10) == 0) break;		//elsõ üres
	}
blk-= 15;
for(cim=0; cim<16; cim++){							//16*105u=2ms
	VarFlsRead_Alap(blk+cim, 0x80, 10); if(MemCmp(Fls.Sys.Be, ures, 10) == 0) break;	//elsõ üres 256b felsõ
	}
VarFlsRead_Alap(blk+cim, 0, 10); if(MemCmp(Fls.Sys.Be, ures, 10) == 0) al= 0; else al= 1;//elsõ üres 128b
M.CegDb= (blk+cim-FLS_CEGMIN)*2+al;
}
//---------------------------------------------------------
void		Arak_SrcUres(void)
{
uint16_t	blk, cim, al;

for(blk=FLS_ARAKMIN+15; blk<FLS_ARAKMAX; blk+=16){	//4095*105u=430ms
	VarFlsRead_Alap(blk, 0xe0, 10); if(MemCmp(Fls.Sys.Be, ures, 10) == 0) break;		//elsõ üres
	}
blk-=15;
for(cim=0; cim<16; cim++){							//16*105u=2ms
	VarFlsRead_Alap(blk+cim, 0xe0, 10); if(MemCmp(Fls.Sys.Be, ures, 10) == 0) break;	//elsõ üres 256b felsõ
	}
for(al=0; al<8; al++){								//8*105u=1ms
	VarFlsRead_Alap(blk+cim, al*32, 10); if(MemCmp(Fls.Sys.Be, ures, 10) == 0) break;	//elsõ üres 32b
	}
M.ArakDb= (blk+cim-FLS_ARAKMIN)*8+al;
}
//---------------------------------------------------------
void		SzintTbl_Load(void)//8*120*4b= 4kb->1sector
{
uint16_t	i, tbl, blk, tip;

for(tbl=0; tbl<4; tbl++){						//4db szint tábla
	for(i=0; i<120; i++){
		M.SzintTbl[tbl][i][0]=	0;				//pontpárok
		M.SzintTbl[tbl][i][1]=	0;
		}

	blk= tbl*2+FLS_SZINTMIN;
//	VarFlsRead_Alap(uint16_t cim, uint8_t alcim, uint8_t db)	//(db+5)*7us
	VarFlsRead_Alap(blk,   0, 122);//931us 2+30*4
	tip= (uint16_t)Fls.Sys.Be[1]*256+Fls.Sys.Be[0];
	if(tip == 0x7001){
		MemCpy((uint8_t*)&M.SzintTbl[tbl][0][0], &Fls.Sys.Be[2], 120);		//30db
		}
	VarFlsRead_Alap(blk, 128, 122);//931us 2+30*4
	tip= (uint16_t)Fls.Sys.Be[1]*256+Fls.Sys.Be[0];
	if(tip == 0x7002){
		MemCpy((uint8_t*)&M.SzintTbl[tbl][30][0], &Fls.Sys.Be[2], 120);		//30db
		}
	blk++;
	VarFlsRead_Alap(blk,   0, 122);//931us 2+30*4
	tip= (uint16_t)Fls.Sys.Be[1]*256+Fls.Sys.Be[0];
	if(tip == 0x7003){
		MemCpy((uint8_t*)&M.SzintTbl[tbl][60][0], &Fls.Sys.Be[2], 120);		//30db
		}
	VarFlsRead_Alap(blk, 128, 122);//931us 2+30*4
	tip= (uint16_t)Fls.Sys.Be[1]*256+Fls.Sys.Be[0];
	if(tip == 0x7004){
		MemCpy((uint8_t*)&M.SzintTbl[tbl][90][0], &Fls.Sys.Be[2], 120);		//30db
		}
	}
}
//=========================================================END
