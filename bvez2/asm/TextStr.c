//===============================================
// Benzin vezérlõ LCD stringek
//-----------------------------------------------
#include "TextStr.h"
#include "Bvez2.h"
//-------Global-------------------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
const struct StruTxt TxtVISSZA=	{ 1, 52,{"Vissza"							,"<<Back"							}};
const struct StruTxt TxtRENDBEN={185,52,{"Rendben"							,"   OK  "							}};
const struct StruTxt TxtSETUP=	{185,52,{"  Setup"							,"  Setup"							}};
const struct StruTxt TxtTARTALY={ 1,  1,{"Tartály szint"					,"Tank level"						}};
//-------Fõmenü:Alap--------------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA1_valassz=	{56, 28,{  "Válasszon kutat"				,  "  Select Pump"					}};
struct StruTxt	ScrA1_Ratio=	{40, 42,{" VRC FUEL EXPERTS"				,"VRC FUELEXPERTS LTD"				}};
struct StruTxt	ScrA1_tel=		{48, 54,{ "   www.vrc.hu"					, "Call 0800 FUELMAN"				}};
//-------Státusz kijelzés---------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA2[21]={		{ 1,  1,{"Kikapcsolva"						,"Out Of Service"					}},/*0*/
								{ 1,  1,{"Fej fent"							,"Nozzle on"						}},
								{ 1,  1,{"Fej fent-Sum1"					,"Nozzle on-Sum1"					}},
								{ 1,  1,{"Fej fent-Sum2"					,"Nozzle on-Sum2"					}},
								{ 1,  1,{"Fej lent"							,"Nozzle off"						}},
				/* 5*/			{ 1,  1,{"Tankolás-ki"						,"Filling-OFF"						}},/*5*/
								{ 1,  1,{"Tankolás-be"						,"Filling-ON"						}},
								{ 1,  1,{"Vége: limit"						,"Over: Limit"						}},/*7*/
								{ 1,  1,{"Vége: fej"						,"Over: Nozzle"						}},
								{ 1,  1,{"Vége: idõhatár"					,"Over: Time Limit"					}},
				/*10*/			{ 1,  1,{"Vége: Lopás!!!"					,"Over: THEFT!"						}},
								{ 1,  1,{"Vége: Feszültség hiba!"			,"Over: Voltage Error!"				}},
								{ 1,  1,{"Mentés: limit"					,"Save: Limit"						}},/*12*/
								{ 1,  1,{"Mentés: fej"						,"Save: Nozzle"						}},
								{ 1,  1,{"Mentés: idõhatár"					,"Save: Time Limit"					}},
				/*15*/			{ 1,  1,{"Mentés: Lopás!!!"					,"Save: THEFT!"						}},
								{ 1,  1,{"Mentés: Feszültség hiba!"			,"Save: Voltage Error!"				}},
								{ 1,  1,{"Újra vár"							,"Ready"							}},/*17*/
								{ 1,  1,{"Rossz státusz!"					,"Incorrect status!"				}},
				/*19*/			{177,52,{"Tankolás"							,"Filling"							}},
				/*20*/			{128,52,{"l/p"								,"l/m"								}}};
//-------Kártya bevitel-----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA3_Kutfo=	{ 1,  1,{"  .Kútfõ:"						,"  .Bowser:"						}};
//struct StruTxt	ScrA3_Hiba=	{80,  1,{"Kártya HIBA"						,"Card ERROR"						}};
struct StruTxt	ScrA3_Ures=		{80, 13,{"                 "				,"             "					}};
struct StruTxt	ScrA3_Card1=	{80, 13,{"Kérem a kártyát  "				,"Present card "					}};
struct StruTxt	ScrA3_Card2=	{80, 13,{"Kérem a kártyákat"				,"Present cards"					}};
struct StruTxt	ScrA3_Nev=		{ 1, 28,{"Név:"								,"Name:"							}};
struct StruTxt	ScrA3_Jarmu=	{ 1, 40,{"Jármû:"							,"Vehicle:"							}};
struct StruTxt	ScrA3_Pin0=		{80, 13,{"PIN kód: ____    "				,"   PIN : ____    "				}};
struct StruTxt	ScrA3_Pin1=		{80, 13,{"PIN kód: *___    "				,"   PIN : *___    "				}};
struct StruTxt	ScrA3_Pin2=		{80, 13,{"PIN kód: **__    "				,"   PIN : **__    "				}};
struct StruTxt	ScrA3_Pin3=		{80, 13,{"PIN kód: ***_    "				,"   PIN : ***_    "				}};
struct StruTxt	ScrA3_Pin4=		{80, 13,{"PIN kód: ****    "				,"   PIN : ****    "				}};
struct StruTxt	ScrA3_Ember=	{185,52,{" NévKód"							," NameCode"						}};
//-------Km óra bevitel-----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA4_KmOra=	{ 0,  0,{"Km óra állása:"					,"Enter odo reading:"				}};
struct StruTxt	ScrA4_KmKis=	{ 1, 52,{"Az elõzõnél nem lehet kisebb! "	,"Cannot be less than previous!"	}};
struct StruTxt	ScrA4_KmKetto=	{ 1, 52,{"Kérem mégegyszer!             "	,"Please enter one more time!  "	}};
struct StruTxt	ScrA4_KmKulonb=	{ 1, 52,{"A két érték különbözik!       "	,"The two entries don´t match! "	}};
//-------Menetlevél bevitel-------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA5_Menlev=	{ 0,  0,{"Menetlevél száma:"				,"Logbook #:"						}};
//-------Tankolhat----------------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA6_MaiNap=	{22,  6,{" Mai nap         .tankolás"		,"Refuelling       today."			}};
struct StruTxt	ScrA6_Litert=	{30, 20,{ "Tankolhat       litert"			, "Can fill        litres"			}};
struct StruTxt	ScrA6_Szer=		{30, 34,{ "      még       -szer."			, "another         times."			}};
//-------Üzemóra bevitel----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA7_Uzemo=	{ 0,  0,{"Üzemóra állása:"					,"Engine hours reading:"			}};
//-------Mester kártya bevitel----x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA8[5]={		{ 0,  0,{"Jármû kártya kódja:"				,"Vehicle card code:"				}},
								{ 1, 52,{"Vissza                Nem kell"	,"<<Back              Not needed"	}},
								{ 1, 52,{"Vissza                        "	,"<<Back                        "	}},
								{ 1, 52,{"Töröl                         "	,"Clear                         "	}},
								{ 1, 52,{"Töröl                  Rendben"	,"Clear                      OK "	}}};
//-------Soför kódja bevitel------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA9_Cim=		{ 0,  0,{"Sofõr kódja:"						,"Operator code:"					}};
//-------Kézi mennyiség-----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrA10_Mennyi=	{ 0,  0,{"Kivett mennyiség:"				,"Filled value:"					}};
//-------MaxStop mennyiség--------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrAstop_Mennyi={ 0,  0,{"Tankolt mennyiség:"				,"Filled value:"					}};
//-------Hiba:Kártya--------------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrH1_Kartya=	{44,  6,{"Kártya HIBA"						,"Card ERROR"						}};
//-------Hiba:Kimerítve-----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrH2_Napi=		{40,  0,{"Napi megengedett"					,"Daily allowed"					}};
struct StruTxt	ScrH2_Tankol=	{40, 16,{"tankolások száma"					,"number of fills"					}};
struct StruTxt	ScrH2_Kimerit=	{40, 32,{"   kimerítve."					,"   exhausted."					}};
//-------Hiba:Rossz kártya kútfõ--x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrH3_Kartya=	{40,  0,{"Ezzel a kártyával"				," With this card"					}};
struct StruTxt	ScrH3_Kutfo=	{40, 16,{"  ezen a kútfõn"					,"you may NOT FILL"					}};
struct StruTxt	ScrH3_Nemtank=	{40, 32,{" NEM TANKOLHAT !"					," on this pump !"					}};
//-------Szerviz:Belépés----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS1_Szerviz=	{ 0,  0,{"Kérem a szerviz kártyát:"			,"Present service card:"			}};
//-------Szerviz------------------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS2_Menu=		{ 0,  0,{"Szerviz menü:"					,"Maintenance menu:"				}};
struct StruTxt	ScrS2_Sor1=		{ 0, 14,{"1-Kútfõk       2-Kártya inf."		,"1-Pumps     2-Card info"			}};
struct StruTxt	ScrS2_Sor2=		{ 0, 26,{"3-Beállítások  4-Változók."		,"3-Settings  4-Variables"			}};
struct StruTxt	ScrS2_Sor3=		{ 0, 38,{"5-Rendszer "						,"5-System "						}};
//-------Szervíz:Kútfõk-----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS3_Kutfok=	{ 0,  0,{"Kútfõk:     1-15 kutak be/ki"		,"Bowsers:     1-15 pumps on/off"	}};
//struct StruTxt	ScrS3_Kutak={ 0, 36,{"-"								,"-"								}};
//-------Szerviz:Kártyák----------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS4[4]={		{ 0,  0,{"Kártya információk:"				,"Card info:"						}},
								{ 0, 20,{"1 - Kártyák száma"				,"1 - Number of cards"				}},
								{ 0, 36,{"Egykártyás rendszer"				,"Single card system "				}},
								{ 0, 36,{"Kétkártyás rendszer"				,"Dual card system   "				}}};
//-------Szerviz:Beállítások------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS5[4]={		{ 0,  0,{"Beállítások:"						,"Settings:"						}},
								{ 0, 12,{"1-Kijelzések   2-Kontraszt"		,"1-Display   2-Contrast"			}},
								{ 0, 24,{"3-Idõ"							,"3-Time"							}},
								{ 0, 36,{"4-Testre szabás"					,"4-Customize"						}}};
//-------Szerviz:Beállítás:Litkij-x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS6_Kijelz=	{ 0,  0,{"Kijelzések:"						,"Display:"							}};
struct StruTxt	ScrS6_KijelBe=	{ 0, 20,{"1 - Liter kijelzés: BE"			,"1 - Litres display: ON"			}};
struct StruTxt	ScrS6_KijelKi=	{ 0, 20,{"1 - Liter kijelzés: KI"			,"1 - Litres display: OFF"			}};
//-------Szerviz:Beállítás:Kontra-x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS7_Kontr=	{ 0,  0,{"Kontraszt:"						,"Contrast:"						}};
struct StruTxt	ScrS7_Csokk=	{ 0, 16,{"1 - csökkent       3 - növel"		,"1 - decrease     3 - increase"	}};
struct StruTxt	ScrS7_Homer=	{ 0, 28,{"Hõmérséklet:"						,"Temperature:"						}};
struct StruTxt	ScrS7_Kcsokk=	{ 0, 40,{"7 - k csökkent     9 - k növel"	,"7 - k decrease   9 - k increase"	}};
//-------Szerviz:Testreszabás-----x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS8[8]={		{ 0,  0,{"Testre szabás:"					,"Customize:"						}},
								{ 0, 16,{"1 - Km bekérés: BE-növekvõ"		,"1 - Kms polling: ON-increasing"	}},
								{ 0, 16,{"1 - Km bekérés: BE        "		,"1 - Kms polling: ON           "	}},
								{ 0, 16,{"1 - Km bekérés: KI        "		,"1 - Kms polling: OFF          "	}},
								{ 0, 28,{"2 - Menetlevél bekérés: BE"		,"2 - Logbook polling: ON       "	}},
								{ 0, 28,{"2 - Menetlevél bekérés: KI"		,"2 - Logbook polling: OFF      "	}},
								{ 0, 40,{"3 - Üzemóra bekérés: BE   "		,"3 - Engine hrs polling: ON    "	}},
								{ 0, 40,{"3 - Üzemóra bekérés: KI   "		,"3 - Engine hrs polling: OFF   "	}}};
//-------Szerviz:Változók---------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS9_Valtozok=	{ 0,  0,{"Változók kijelzése:"				,"Variables displayed:"				}};
struct StruTxt	ScrS9_Tankdb=	{ 0, 14,{"Tankolások száma:"				,"Number of fillings:"				}};
struct StruTxt	ScrS9_Kartyak=	{ 0, 26,{"Kártyák száma:"					,"Number of cards:"					}};
struct StruTxt	ScrS9_Cegek=	{ 0, 38,{"Cégek száma:"						,"Number of firms:"					}};
//-------Szerviz:Rendszer---------x,--y,-"12345678901234567890123456789012"	,"12345678901234567890123456789012"	}};
struct StruTxt	ScrS10_Rendszer={ 0,  0,{"Rendszer:"						,"System:"							}};
struct StruTxt	ScrS10_Fejleszt={ 0, 20,{"Fejlesztés alatt"					,"Under Development"				}};
//-----------------------------------------------Nyomtatóra
const char  PrnByteInit[4]=		{0x1b,0x52,0x02,0};
const char  PrnByteClose[8]=	{0x0a,0x0a,0x0a,0x0a,0x0a,0x1b,0x6d,0};		//half cut
const char  PrnByteClose2[8]=	{0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0};		//no cut +2sor
const char  *Prn_Vonal=			{"----------------------------------"};//"----------------------------------"
#if		C_SEREG!=1
#warning	"NORMAL szoveg" 
const char	*Prn_Elado[]=		{"Eladó:"								,"Vendor:"								};
const char	*Prn_Vevo[]=		{"Vevõ:"								,"Buyer:"								};
const char	*Prn_Kezd[]=		{"Mérés kezdete: 20__.__.__ __:__:__"	,"Start meter  : __:__:__ __.__.20__"	};
const char	*Prn_Vege[]=		{"Mérés vége   : 20__.__.__ __:__:__"	,"End meter    : __:__:__ __.__.20__"	};
const char	*Prn_Ember[]=		{"Személy    : ____________________ "	,"Person     : ____________________ "	};
const char	*Prn_Rendsz[]=		{"Rendszám   : ____________________ "	,"Licence No.: ____________________ "	};
const char	*Prn_Km[]=			{"Kilométer          :   ________ km"	,"Odometer           :   ________kms"	};
const char	*Prn_Uzemora[]=		{"Üzemóra            :   ________ ó "	,"Engine hours       :   ________hrs"	};
const char	*Prn_Menlev[]=		{"Menetlevél         :   ________   "	,"Logbook #          :   ________   "	};
const char	*Prn_Sorszam[]=		{"Kimérés sorszáma Nr:     _____/_  "	,"Filling          Nr:     _____/_  "	};
const char	*Prn_OszLit[]=		{"Számláló állása   V:__________,__l"	,"Counter reading   V:__________,__l"	};
const char	*Prn_OszKomp[]=		{"Összegezett mérésVo:__________,__l"	,"Cumulative volumeVo:__________,__l"	};
const char	*Prn_Liter[]=		{"Kimért mennyiség   Vt: ______,__ l"	,"Dispensed volume   Vt: ______,__ l"	};
const char	*Prn_Hom[]=			{"Termékhõmérséklet   t:    ___,_ °C"	,"Product temperat.   t:    ___,_ °C"	};
const char	*Prn_Megnev[]=		{"Termék megnevezés:"					,"Product name:"						};
const char	*Prn_MegnevB[]=		{"    Benzin95 max.10ppm kéntart    "	,"   Petrol 95octane max.10ppm Sulph"	};
const char	*Prn_MegnevG[]=		{"    UN 1202 DIZELOLAJ, 3,III,(D/I)"	,"    UN 1202 DIESEL,   3,III,(D/I) "	};
const char	*Prn_BazisHo[]=		{"Bázishõmérséklet   to:     15,0 °C"	,"Base temperature   to:     15,0 °C"	};
const char	*Prn_LitKomp[]=		{"Mennyiség to-án    Vo: ______,__ l"	,"Volume at to       Vo: ______,__ l"	};
const char	*Prn_ArAlap[]=		{"Egységár (netto):00000000,00 Ft/l"	,"Unit price(net) :00000000,00 $/l"		};
const char	*Prn_ArNetto[]=		{"Ár (netto)      :00000000,00 Ft"		,"Price (net)     :00000000,00 $"		};
const char	*Prn_ArBrutto[]=	{"Ár (brutto)     :00000000,00 Ft"		,"Price (gross)   :00000000,00 $"		};
const char	*Prn_RosszBiz[]=	{"Nem megfelel? bizonylat !"			,"Bad voucher !"						};
const char	*Prn_Jelezze[]=		{"Kérjük jelezze a kútkezel?nek !"		,"Plase call the operator !"			};
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
const char	*Prn_Hom[]=			{"Termekhomerseklet   t:    ___,_ °C"	,"Product temperat.   t:    ___,_ °C"	};
const char	*Prn_Megnev[]=		{"Termek megnevezes:"					,"Product name:"						};
const char	*Prn_MegnevB[]=		{"                       gazolaj    "	,"                      diesel      "	};
const char	*Prn_MegnevG[]=		{"                       gazolaj    "	,"                      diesel      "	};
const char	*Prn_BazisHo[]=		{"Bazishomerseklet   to:     15,0 °C"	,"Base temperature   to:     15,0 °C"	};
const char	*Prn_LitKomp[]=		{"Mennyiseg to-an    Vo: ______,__ l"	,"Volume at to       Vo: ______,__ l"	};
const char	*Prn_ArAlap[]=		{"Egysegar (netto):00000000,00 Ft/l"	,"Unit price(net) :00000000,00 $/l"		};
const char	*Prn_ArNetto[]=		{"Ar (netto)      :00000000,00 Ft"		,"Price (net)     :00000000,00 $"		};
const char	*Prn_ArBrutto[]=	{"Ar (brutto)     :00000000,00 Ft"		,"Price (gross)   :00000000,00 $"		};
const char	*Prn_RosszBiz[]=	{"Nem megfelelo bizonylat !"			,"Bad voucher !"						};
const char	*Prn_Jelezze[]=		{"Kérjük jelezze a kutkezelonek !"		,"Plase call the operator !"			};
#endif
//===============================================END
