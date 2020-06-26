#ifndef _GYORSGRA_H
#define _GYORSGRA_H
//-----------------------------------------------
#include "TextStr.h"

#define		CHR_HOM		1		//hõmérõ
#define		CHR_NOHOM	2		//áthúzott hõmérõ
//#define	CHR_1pP		3		//1/p
//#define	chr_fok		2		//°C

#define		C1_COL		12		//hány sor
#define		C1_SZEL		8		//pixel szélesség
#define		C2_COL		24		//hány sor
#define		C2_SZEL		16		//pixel szélesség
//#define	C3_COL		36		//hány sor
//#define	C3_SZEL		24		//pixel szélesség
//-----------------------------------------------
extern void G_Kar1_Ki(uint16 x, uint16 ybe, uint8 ch);
extern void G_Kar2_Ki(uint16 xbe, uint16 y, uint16 wide, uint8 ch);
extern void G_Kar3_Ki(uint16 xbe, uint16 y, uint16 wide, uint8 ch);
extern void OutStr1(uint16 db, uint16 x, uint16 y);
extern void OutStr2(uint16 db, uint16 x, uint16 y);
extern void OutStr3(uint16 db, uint16 x, uint16 y);
extern void SzovKi(const struct StruTxt *str);
//-----------------------------------------------
#endif
