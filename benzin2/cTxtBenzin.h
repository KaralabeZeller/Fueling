#ifndef cTextStrH
#define cTextStrH
//---------------------------------------------------------------------------
#define	NYELV__MAGYAR	0
#define	NYELV__ANGOL	1
#define	NYELV_AKTU	NYELV__MAGYAR
extern int		Nyelv;
//---------------------------------------------------------------------------
extern AnsiString	TxtVez		[28][2];

extern AnsiString	TxtBenzMent	[ 6][2];
extern AnsiString	TxtCardKonv	[34][2];
extern AnsiString	TxtUjKartyaBe	[19][2];

extern AnsiString	TxtCegnevek	[25][2];
extern AnsiString	TxtSzintTbl	[13][2];
extern AnsiString	TxtArak		[23][2];
extern AnsiString	TxtEEprom		[55][2];
extern AnsiString	TxtOraBe		[12][2];

extern AnsiString	TxtNyomtato	[ 2][2];
extern AnsiString	TxtKutfoTst	[23][2];
extern AnsiString	TxtTankTst	[31][2];
extern AnsiString	TxtGyurus		[ 5][2];

extern AnsiString	TxtSzintTst	[ 7][2];
extern AnsiString	TxtAnalog		[18][2];
extern AnsiString	TxtTeszt		[ 1][2];
extern AnsiString	TxtBeall		[ 2][2];

extern AnsiString	TxtUpgrade	[35][2];
extern AnsiString	TxtHexFile	[13][2];
extern AnsiString	TxtMemo		[ 2][2];
extern AnsiString	TxtFlsClear	[20][2];
//---------------------------------------------------------------------------
#endif
