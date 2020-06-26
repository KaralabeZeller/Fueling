#ifndef _TEXTSTR_H
#define _TEXTSTR_H
//-----------------------------------------------
#define	NYELV_HU	0	//magyar
#define	NYELV_GB	1	//angol
#define	NYELV_DB	2

struct StruTxt{
	int		x,y;			//koordináta
	char*	str[NYELV_DB];	//szövegek nevenként
	};
//-----------------------------------------------
extern const struct StruTxt	TxtVISSZA;
extern const struct StruTxt	TxtRENDBEN;
extern const struct StruTxt	TxtSETUP;
extern const struct StruTxt	TxtTARTALY;

extern struct StruTxt	ScrA1_valassz;
extern struct StruTxt	ScrA1_Ratio;
extern struct StruTxt	ScrA1_tel;

extern struct StruTxt	ScrA2[21];

extern struct StruTxt	ScrA3_Kutfo;
//extern struct StruTxt	ScrA3_Hiba;
extern struct StruTxt	ScrA3_Ures;
extern struct StruTxt	ScrA3_Card1;
extern struct StruTxt	ScrA3_Card2;
extern struct StruTxt	ScrA3_Nev;
extern struct StruTxt	ScrA3_Jarmu;
extern struct StruTxt	ScrA3_Pin0;
extern struct StruTxt	ScrA3_Pin1;
extern struct StruTxt	ScrA3_Pin2;
extern struct StruTxt	ScrA3_Pin3;
extern struct StruTxt	ScrA3_Pin4;
extern struct StruTxt	ScrA3_Ember;

extern struct StruTxt	ScrA4_KmOra;
extern struct StruTxt	ScrA4_KmKis;
extern struct StruTxt	ScrA4_KmKetto;
extern struct StruTxt	ScrA4_KmKulonb;

extern struct StruTxt	ScrA5_Menlev;

extern struct StruTxt	ScrA6_MaiNap;
extern struct StruTxt	ScrA6_Litert;
extern struct StruTxt	ScrA6_Szer;

extern struct StruTxt	ScrA7_Uzemo;

extern struct StruTxt	ScrA8[5];

extern struct StruTxt	ScrA9_Cim;
extern struct StruTxt	ScrA10_Mennyi;
extern struct StruTxt	ScrAstop_Mennyi;

extern struct StruTxt	ScrH1_Kartya;

extern struct StruTxt	ScrH2_Napi;
extern struct StruTxt	ScrH2_Tankol;
extern struct StruTxt	ScrH2_Kimerit;

extern struct StruTxt	ScrH3_Kartya;
extern struct StruTxt	ScrH3_Kutfo;
extern struct StruTxt	ScrH3_Nemtank;

extern struct StruTxt	ScrS1_Szerviz;

extern struct StruTxt	ScrS2_Menu;
extern struct StruTxt	ScrS2_Sor1;
extern struct StruTxt	ScrS2_Sor2;
extern struct StruTxt	ScrS2_Sor3;

extern struct StruTxt	ScrS3_Kutfok;
//extern struct StruTxt	ScrS3_Kutak;

extern struct StruTxt	ScrS4[4];

extern struct StruTxt	ScrS5[4];

extern struct StruTxt	ScrS6_Kijelz;
extern struct StruTxt	ScrS6_KijelBe;
extern struct StruTxt	ScrS6_KijelKi;

extern struct StruTxt	ScrS7_Kontr;
extern struct StruTxt	ScrS7_Csokk;
extern struct StruTxt	ScrS7_Homer;
extern struct StruTxt	ScrS7_Kcsokk;

extern struct StruTxt	ScrS8[8];

extern struct StruTxt	ScrS9_Valtozok;
extern struct StruTxt	ScrS9_Tankdb;
extern struct StruTxt	ScrS9_Kartyak;
extern struct StruTxt	ScrS9_Cegek;

extern struct StruTxt	ScrS10_Rendszer;
extern struct StruTxt	ScrS10_Fejleszt;

extern const char	PrnByteInit[4];
extern const char	PrnByteClose[8];			//half cut
extern const char	PrnByteClose2[8];			//no cut +2sor
extern const char*	Prn_Vonal;
extern const char*	Prn_Elado	[NYELV_DB];
extern const char*	Prn_Vevo	[NYELV_DB];
extern const char*	Prn_Kezd	[NYELV_DB];
extern const char*	Prn_Vege	[NYELV_DB];
extern const char*	Prn_Ember	[NYELV_DB];
extern const char*	Prn_Rendsz	[NYELV_DB];
extern const char*	Prn_Km		[NYELV_DB];
extern const char*	Prn_Uzemora	[NYELV_DB];
extern const char*	Prn_Menlev	[NYELV_DB];
extern const char*	Prn_Sorszam	[NYELV_DB];
extern const char*	Prn_OszLit	[NYELV_DB];
extern const char*	Prn_OszKomp	[NYELV_DB];
extern const char*	Prn_Liter	[NYELV_DB];
extern const char*	Prn_Hom		[NYELV_DB];
extern const char*	Prn_Megnev	[NYELV_DB];
extern const char*	Prn_MegnevB	[NYELV_DB];
extern const char*	Prn_MegnevG	[NYELV_DB];
extern const char*	Prn_BazisHo	[NYELV_DB];
extern const char*	Prn_LitKomp	[NYELV_DB];
extern const char*	Prn_ArAlap	[NYELV_DB];
extern const char*	Prn_ArNetto	[NYELV_DB];
extern const char*	Prn_ArBrutto[NYELV_DB];
extern const char*	Prn_RosszBiz[NYELV_DB];
extern const char*	Prn_Jelezze	[NYELV_DB];
//===============================================END
#endif
