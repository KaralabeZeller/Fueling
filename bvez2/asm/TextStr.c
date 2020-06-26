//===============================================
// Benzin vez�rl� LCD stringek
//-----------------------------------------------
#include "TextStr.h"
#include "Bvez2.h"
//-------Global-------------------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
const struct StruTxt TxtVISSZA=	{ 1, 52,{"Vissza"							,"<<Back"							}};
const struct StruTxt TxtRENDBEN={185,52,{"Rendben"							,"   OK  "							}};
const struct StruTxt TxtSETUP=	{185,52,{"  Setup"							,"  Setup"							}};
const struct StruTxt TxtTARTALY={ 1,  1,{"Tart�ly szint"					,"Tank level"						}};
//-------F�men�:Alap--------------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA1_valassz=	{56, 28,{  "V�lasszon kutat"				,  "  Select Pump"					}};
struct StruTxt	ScrA1_Ratio=	{40, 42,{" VRC FUEL EXPERTS"				,"VRC FUELEXPERTS LTD"				}};
struct StruTxt	ScrA1_tel=		{48, 54,{ "   www.vrc.hu"					, "Call 0800 FUELMAN"				}};
//-------St�tusz kijelz�s---------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA2[21]={		{ 1,  1,{"Kikapcsolva"						,"Out Of Service"					}},/*0*/
								{ 1,  1,{"Fej fent"							,"Nozzle on"						}},
								{ 1,  1,{"Fej fent-Sum1"					,"Nozzle on-Sum1"					}},
								{ 1,  1,{"Fej fent-Sum2"					,"Nozzle on-Sum2"					}},
								{ 1,  1,{"Fej lent"							,"Nozzle off"						}},
				/* 5*/			{ 1,  1,{"Tankol�s-ki"						,"Filling-OFF"						}},/*5*/
								{ 1,  1,{"Tankol�s-be"						,"Filling-ON"						}},
								{ 1,  1,{"V�ge: limit"						,"Over: Limit"						}},/*7*/
								{ 1,  1,{"V�ge: fej"						,"Over: Nozzle"						}},
								{ 1,  1,{"V�ge: id�hat�r"					,"Over: Time Limit"					}},
				/*10*/			{ 1,  1,{"V�ge: Lop�s!!!"					,"Over: THEFT!"						}},
								{ 1,  1,{"V�ge: Fesz�lts�g hiba!"			,"Over: Voltage Error!"				}},
								{ 1,  1,{"Ment�s: limit"					,"Save: Limit"						}},/*12*/
								{ 1,  1,{"Ment�s: fej"						,"Save: Nozzle"						}},
								{ 1,  1,{"Ment�s: id�hat�r"					,"Save: Time Limit"					}},
				/*15*/			{ 1,  1,{"Ment�s: Lop�s!!!"					,"Save: THEFT!"						}},
								{ 1,  1,{"Ment�s: Fesz�lts�g hiba!"			,"Save: Voltage Error!"				}},
								{ 1,  1,{"�jra v�r"							,"Ready"							}},/*17*/
								{ 1,  1,{"Rossz st�tusz!"					,"Incorrect status!"				}},
				/*19*/			{177,52,{"Tankol�s"							,"Filling"							}},
				/*20*/			{128,52,{"l/p"								,"l/m"								}}};
//-------K�rtya bevitel-----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA3_Kutfo=	{ 1,  1,{"  .K�tf�:"						,"  .Bowser:"						}};
//struct StruTxt	ScrA3_Hiba=	{80,  1,{"K�rtya HIBA"						,"Card ERROR"						}};
struct StruTxt	ScrA3_Ures=		{80, 13,{"                 "				,"             "					}};
struct StruTxt	ScrA3_Card1=	{80, 13,{"K�rem a k�rty�t  "				,"Present card "					}};
struct StruTxt	ScrA3_Card2=	{80, 13,{"K�rem a k�rty�kat"				,"Present cards"					}};
struct StruTxt	ScrA3_Nev=		{ 1, 28,{"N�v:"								,"Name:"							}};
struct StruTxt	ScrA3_Jarmu=	{ 1, 40,{"J�rm�:"							,"Vehicle:"							}};
struct StruTxt	ScrA3_Pin0=		{80, 13,{"PIN k�d: ____    "				,"   PIN : ____    "				}};
struct StruTxt	ScrA3_Pin1=		{80, 13,{"PIN k�d: *___    "				,"   PIN : *___    "				}};
struct StruTxt	ScrA3_Pin2=		{80, 13,{"PIN k�d: **__    "				,"   PIN : **__    "				}};
struct StruTxt	ScrA3_Pin3=		{80, 13,{"PIN k�d: ***_    "				,"   PIN : ***_    "				}};
struct StruTxt	ScrA3_Pin4=		{80, 13,{"PIN k�d: ****    "				,"   PIN : ****    "				}};
struct StruTxt	ScrA3_Ember=	{185,52,{" N�vK�d"							," NameCode"						}};
//-------Km �ra bevitel-----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA4_KmOra=	{ 0,  0,{"Km �ra �ll�sa:"					,"Enter odo reading:"				}};
struct StruTxt	ScrA4_KmKis=	{ 1, 52,{"Az el�z�n�l nem lehet kisebb! "	,"Cannot be less than previous!"	}};
struct StruTxt	ScrA4_KmKetto=	{ 1, 52,{"K�rem m�gegyszer!             "	,"Please enter one more time!  "	}};
struct StruTxt	ScrA4_KmKulonb=	{ 1, 52,{"A k�t �rt�k k�l�nb�zik!       "	,"The two entries don�t match! "	}};
//-------Menetlev�l bevitel-------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA5_Menlev=	{ 0,  0,{"Menetlev�l sz�ma:"				,"Logbook #:"						}};
//-------Tankolhat----------------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA6_MaiNap=	{22,  6,{" Mai nap         .tankol�s"		,"Refuelling       today."			}};
struct StruTxt	ScrA6_Litert=	{30, 20,{ "Tankolhat       litert"			, "Can fill        litres"			}};
struct StruTxt	ScrA6_Szer=		{30, 34,{ "      m�g       -szer."			, "another         times."			}};
//-------�zem�ra bevitel----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA7_Uzemo=	{ 0,  0,{"�zem�ra �ll�sa:"					,"Engine hours reading:"			}};
//-------Mester k�rtya bevitel----x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA8[5]={		{ 0,  0,{"J�rm� k�rtya k�dja:"				,"Vehicle card code:"				}},
								{ 1, 52,{"Vissza                Nem kell"	,"<<Back              Not needed"	}},
								{ 1, 52,{"Vissza                        "	,"<<Back                        "	}},
								{ 1, 52,{"T�r�l                         "	,"Clear                         "	}},
								{ 1, 52,{"T�r�l                  Rendben"	,"Clear                      OK "	}}};
//-------Sof�r k�dja bevitel------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA9_Cim=		{ 0,  0,{"Sof�r k�dja:"						,"Operator code:"					}};
//-------K�zi mennyis�g-----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA10_Mennyi=	{ 0,  0,{"Kivett mennyis�g:"				,"Filled value:"					}};
//-------MaxStop mennyis�g--------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrAstop_Mennyi={ 0,  0,{"Tankolt mennyis�g:"				,"Filled value:"					}};
//-------Hiba:K�rtya--------------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrH1_Kartya=	{44,  6,{"K�rtya HIBA"						,"Card ERROR"						}};
//-------Hiba:Kimer�tve-----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrH2_Napi=		{40,  0,{"Napi megengedett"					,"Daily allowed"					}};
struct StruTxt	ScrH2_Tankol=	{40, 16,{"tankol�sok sz�ma"					,"number of fills"					}};
struct StruTxt	ScrH2_Kimerit=	{40, 32,{"   kimer�tve."					,"   exhausted."					}};
//-------Hiba:Rossz k�rtya k�tf�--x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrH3_Kartya=	{40,  0,{"Ezzel a k�rty�val"				," With this card"					}};
struct StruTxt	ScrH3_Kutfo=	{40, 16,{"  ezen a k�tf�n"					,"you may NOT FILL"					}};
struct StruTxt	ScrH3_Nemtank=	{40, 32,{" NEM TANKOLHAT !"					," on this pump !"					}};
//-------Szerviz:Bel�p�s----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS1_Szerviz=	{ 0,  0,{"K�rem a szerviz k�rty�t:"			,"Present service card:"			}};
//-------Szerviz------------------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS2_Menu=		{ 0,  0,{"Szerviz men�:"					,"Maintenance menu:"				}};
struct StruTxt	ScrS2_Sor1=		{ 0, 14,{"1-K�tf�k       2-K�rtya inf."		,"1-Pumps     2-Card info"			}};
struct StruTxt	ScrS2_Sor2=		{ 0, 26,{"3-Be�ll�t�sok  4-V�ltoz�k."		,"3-Settings  4-Variables"			}};
struct StruTxt	ScrS2_Sor3=		{ 0, 38,{"5-Rendszer "						,"5-System "						}};
//-------Szerv�z:K�tf�k-----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS3_Kutfok=	{ 0,  0,{"K�tf�k:     1-15 kutak be/ki"		,"Bowsers:     1-15 pumps on/off"	}};
//struct StruTxt	ScrS3_Kutak={ 0, 36,{"-"								,"-"								}};
//-------Szerviz:K�rty�k----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS4[4]={		{ 0,  0,{"K�rtya inform�ci�k:"				,"Card info:"						}},
								{ 0, 20,{"1 - K�rty�k sz�ma"				,"1 - Number of cards"				}},
								{ 0, 36,{"Egyk�rty�s rendszer"				,"Single card system "				}},
								{ 0, 36,{"K�tk�rty�s rendszer"				,"Dual card system   "				}}};
//-------Szerviz:Be�ll�t�sok------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS5[4]={		{ 0,  0,{"Be�ll�t�sok:"						,"Settings:"						}},
								{ 0, 12,{"1-Kijelz�sek   2-Kontraszt"		,"1-Display   2-Contrast"			}},
								{ 0, 24,{"3-Id�"							,"3-Time"							}},
								{ 0, 36,{"4-Testre szab�s"					,"4-Customize"						}}};
//-------Szerviz:Be�ll�t�s:Litkij-x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS6_Kijelz=	{ 0,  0,{"Kijelz�sek:"						,"Display:"							}};
struct StruTxt	ScrS6_KijelBe=	{ 0, 20,{"1 - Liter kijelz�s: BE"			,"1 - Litres display: ON"			}};
struct StruTxt	ScrS6_KijelKi=	{ 0, 20,{"1 - Liter kijelz�s: KI"			,"1 - Litres display: OFF"			}};
//-------Szerviz:Be�ll�t�s:Kontra-x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS7_Kontr=	{ 0,  0,{"Kontraszt:"						,"Contrast:"						}};
struct StruTxt	ScrS7_Csokk=	{ 0, 16,{"1 - cs�kkent       3 - n�vel"		,"1 - decrease     3 - increase"	}};
struct StruTxt	ScrS7_Homer=	{ 0, 28,{"H�m�rs�klet:"						,"Temperature:"						}};
struct StruTxt	ScrS7_Kcsokk=	{ 0, 40,{"7 - k cs�kkent     9 - k n�vel"	,"7 - k decrease   9 - k increase"	}};
//-------Szerviz:Testreszab�s-----x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS8[8]={		{ 0,  0,{"Testre szab�s:"					,"Customize:"						}},
								{ 0, 16,{"1 - Km bek�r�s: BE-n�vekv�"		,"1 - Kms polling: ON-increasing"	}},
								{ 0, 16,{"1 - Km bek�r�s: BE        "		,"1 - Kms polling: ON           "	}},
								{ 0, 16,{"1 - Km bek�r�s: KI        "		,"1 - Kms polling: OFF          "	}},
								{ 0, 28,{"2 - Menetlev�l bek�r�s: BE"		,"2 - Logbook polling: ON       "	}},
								{ 0, 28,{"2 - Menetlev�l bek�r�s: KI"		,"2 - Logbook polling: OFF      "	}},
								{ 0, 40,{"3 - �zem�ra bek�r�s: BE   "		,"3 - Engine hrs polling: ON    "	}},
								{ 0, 40,{"3 - �zem�ra bek�r�s: KI   "		,"3 - Engine hrs polling: OFF   "	}}};
//-------Szerviz:V�ltoz�k---------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS9_Valtozok=	{ 0,  0,{"V�ltoz�k kijelz�se:"				,"Variables displayed:"				}};
struct StruTxt	ScrS9_Tankdb=	{ 0, 14,{"Tankol�sok sz�ma:"				,"Number of fillings:"				}};
struct StruTxt	ScrS9_Kartyak=	{ 0, 26,{"K�rty�k sz�ma:"					,"Number of cards:"					}};
struct StruTxt	ScrS9_Cegek=	{ 0, 38,{"C�gek sz�ma:"						,"Number of firms:"					}};
//-------Szerviz:Rendszer---------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS10_Rendszer={ 0,  0,{"Rendszer:"						,"System:"							}};
struct StruTxt	ScrS10_Fejleszt={ 0, 20,{"Fejleszt�s alatt"					,"Under Development"				}};
//-----------------------------------------------Nyomtat�ra
const char  PrnByteInit[4]=		{0x1b,0x52,0x02,0};
const char  PrnByteClose[8]=	{0x0a,0x0a,0x0a,0x0a,0x0a,0x1b,0x6d,0};		//half cut
const char  PrnByteClose2[8]=	{0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0};		//no cut +2sor
const char  *Prn_Vonal=			{"----------------------------------"};//"----------------------------------"
#if		C_SEREG!=1
#warning	"NORMAL szoveg" 
const char	*Prn_Elado[]=		{"Elad�:"								,"Vendor:"								};
const char	*Prn_Vevo[]=		{"Vev�:"								,"Buyer:"								};
const char	*Prn_Kezd[]=		{"M�r�s kezdete: 20__.__.__ __:__:__"	,"Start meter  : __:__:__ __.__.20__"	};
const char	*Prn_Vege[]=		{"M�r�s v�ge   : 20__.__.__ __:__:__"	,"End meter    : __:__:__ __.__.20__"	};
const char	*Prn_Ember[]=		{"Szem�ly    : ____________________ "	,"Person     : ____________________ "	};
const char	*Prn_Rendsz[]=		{"Rendsz�m   : ____________________ "	,"Licence No.: ____________________ "	};
const char	*Prn_Km[]=			{"Kilom�ter          :   ________ km"	,"Odometer           :   ________kms"	};
const char	*Prn_Uzemora[]=		{"�zem�ra            :   ________ � "	,"Engine hours       :   ________hrs"	};
const char	*Prn_Menlev[]=		{"Menetlev�l         :   ________   "	,"Logbook #          :   ________   "	};
const char	*Prn_Sorszam[]=		{"Kim�r�s sorsz�ma Nr:     _____/_  "	,"Filling          Nr:     _____/_  "	};
const char	*Prn_OszLit[]=		{"Sz�ml�l� �ll�sa   V:__________,__l"	,"Counter reading   V:__________,__l"	};
const char	*Prn_OszKomp[]=		{"�sszegezett m�r�sVo:__________,__l"	,"Cumulative volumeVo:__________,__l"	};
const char	*Prn_Liter[]=		{"Kim�rt mennyis�g   Vt: ______,__ l"	,"Dispensed volume   Vt: ______,__ l"	};
const char	*Prn_Hom[]=			{"Term�kh�m�rs�klet   t:    ___,_ �C"	,"Product temperat.   t:    ___,_ �C"	};
const char	*Prn_Megnev[]=		{"Term�k megnevez�s:"					,"Product name:"						};
const char	*Prn_MegnevB[]=		{"    Benzin95 max.10ppm k�ntart    "	,"   Petrol 95octane max.10ppm Sulph"	};
const char	*Prn_MegnevG[]=		{"    UN 1202 DIZELOLAJ, 3,III,(D/I)"	,"    UN 1202 DIESEL,   3,III,(D/I) "	};
const char	*Prn_BazisHo[]=		{"B�zish�m�rs�klet   to:     15,0 �C"	,"Base temperature   to:     15,0 �C"	};
const char	*Prn_LitKomp[]=		{"Mennyis�g to-�n    Vo: ______,__ l"	,"Volume at to       Vo: ______,__ l"	};
const char	*Prn_ArAlap[]=		{"Egys�g�r (netto):00000000,00 Ft/l"	,"Unit price(net) :00000000,00 $/l"		};
const char	*Prn_ArNetto[]=		{"�r (netto)      :00000000,00 Ft"		,"Price (net)     :00000000,00 $"		};
const char	*Prn_ArBrutto[]=	{"�r (brutto)     :00000000,00 Ft"		,"Price (gross)   :00000000,00 $"		};
const char	*Prn_RosszBiz[]=	{"Nem megfelel? bizonylat !"			,"Bad voucher !"						};
const char	*Prn_Jelezze[]=		{"K�rj�k jelezze a k�tkezel?nek !"		,"Plase call the operator !"			};
#else
#warning	"SEREG szoveg" 
const char	*Prn_Elado[]=		{"Elado:"								,"Vendor:"								};
const char	*Prn_Vevo[]=		{"Vevo:"								,"Buyer:"								};
const char	*Prn_Kezd[]=		{"Meres kezdete: 20__.__.__ __:__:__"	,"Start meter  : __:__:__ __.__.20__"	};
const char	*Prn_Vege[]=		{"Meres vege   : 20__.__.__ __:__:__"	,"End meter    : __:__:__ __.__.20__"	};
const char	*Prn_Ember[]=		{"Szemely    : ____________________ "	,"Person     : ____________________ "	};
const char	*Prn_Rendsz[]=		{"Rendszam   : ____________________ "	,"Licence No.: ____________________ "	};
const char	*Prn_Km[]=			{"Kilometer          :   ________ km"	,"Odometer           :   ________kms"	};
const char	*Prn_Uzemora[]=		{"Uzemora            :   ________ o "	,"Engine hours       :   ________hrs"	};
const char	*Prn_Menlev[]=		{"Menetlevel         :   ________   "	,"Logbook #          :   ________   "	};
const char	*Prn_Sorszam[]=		{"Kimeres sorszama Nr:     _____/_  "	,"Filling          Nr:     _____/_  "	};
const char	*Prn_OszLit[]=		{"Szamlalo allasa   V:__________,__l"	,"Counter reading   V:__________,__l"	};
const char	*Prn_OszKomp[]=		{"Osszegezett meresVo:__________,__l"	,"Cumulative volumeVo:__________,__l"	};
const char	*Prn_Liter[]=		{"Kimert mennyiseg   Vt: ______,__ l"	,"Dispensed volume   Vt: ______,__ l"	};
const char	*Prn_Hom[]=			{"Termekhomerseklet   t:    ___,_ �C"	,"Product temperat.   t:    ___,_ �C"	};
const char	*Prn_Megnev[]=		{"Termek megnevezes:"					,"Product name:"						};
const char	*Prn_MegnevB[]=		{"                       gazolaj    "	,"                      diesel      "	};
const char	*Prn_MegnevG[]=		{"                       gazolaj    "	,"                      diesel      "	};
const char	*Prn_BazisHo[]=		{"Bazishomerseklet   to:     15,0 �C"	,"Base temperature   to:     15,0 �C"	};
const char	*Prn_LitKomp[]=		{"Mennyiseg to-an    Vo: ______,__ l"	,"Volume at to       Vo: ______,__ l"	};
const char	*Prn_ArAlap[]=		{"Egysegar (netto):00000000,00 Ft/l"	,"Unit price(net) :00000000,00 $/l"		};
const char	*Prn_ArNetto[]=		{"Ar (netto)      :00000000,00 Ft"		,"Price (net)     :00000000,00 $"		};
const char	*Prn_ArBrutto[]=	{"Ar (brutto)     :00000000,00 Ft"		,"Price (gross)   :00000000,00 $"		};
const char	*Prn_RosszBiz[]=	{"Nem megfelelo bizonylat !"			,"Bad voucher !"						};
const char	*Prn_Jelezze[]=		{"K�rj�k jelezze a kutkezelonek !"		,"Plase call the operator !"			};
#endif
//===============================================END
