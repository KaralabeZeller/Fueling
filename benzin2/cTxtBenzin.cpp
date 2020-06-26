#include <vcl.h>
#pragma hdrstop
#include "cTxtBenzin.h"
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtVez[28][2]={
/* 0*/{"K4 vezérlõ karbantartás"			,"K4 controller maintenance"},

/* 1*/{"Adatkezelés"					,"Data maintenance"},
/* 2*/{"Tankolási adatok letöltése file-ba"	,"Download refuel data"},
/* 3*/{"Kártya adatok kezelése"			,"Manage card data"},

/* 4*/{"Beállítások"					,"Settings"},
/* 5*/{"Cégnevek beállítása"				,"Set firm names"},
/* 6*/{"Árak beállítása"					,"Set prices"},
/* 7*/{"EEprom init beállítása"			,"Set EEPROM init"},
/* 8*/{"Óra beállítás"					,"Set time"},

/* 9*/{"Tesztek"						,"Test"},
/*10*/{"Nyomtató teszt"					,"Printer test"},
/*11*/{"Kútfõ teszt"					,"Fuelpump test"},
/*12*/{"Tankolás teszt"					,"Refuel test"},
/*13*/{"Gyûrûs fej teszt"				,"Ring head test"},

/*14*/{"Szintmérõ teszt"			     	,"ATG test"},
/*15*/{"Analóg mérések"					,"Analog measurements"},
/*16*/{"Memória kijelzés"				,"Memory map"},

/*17*/{"Kapcsolat"				     	,"Connection"},
/*18*/{"IP cím:"						,"IP address:"},
/*19*/{"UDP port:"				     	,"UDP port:"},
/*20*/{"Kút szám:"				     	,"Pump num:"},
/*21*/{"NET3 soros port:"				,"NET3 serial port:"},
/*22*/{"0-régi verzió"					,"0-old version"},
/*23*/{"1-Rs485/232"					,"1-Rs485/232"},
/*24*/{"2-Rs232"						,"2-Rs232"},

/*25*/{"Upgrade"						,"Upgrade"},
/*26*/{"Törlés"						,"Erase"},
/*27*/{"Szint tábla"					,"Level table"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtBenzMent[6][2]={
/* 0*/{"Tankolási adatok letöltése"		,"Save refuelling data"},
/* 1*/{"Letöltés"						,"Save"},
/* 2*/{"Megszakítás"					,"Interrupt"},
/* 3*/{"Tank"							,"Refuel"},
/* 4*/{"Javítva"						,"Reaired"},
/* 5*/{"Kezdõ cím:"						,"Start address:"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtCardKonv[34][2]={
/* 0*/{"Kártya konvertálás"				,"Card konversion"},

/* 1*/{"K4 olvasás"						,"Read K4"},
/* 2*/{"Dump"							,"Dump"},
/* 3*/{"Beírás K4-be"					,"Write K4"},
/* 4*/{"Új kártya bevitel"				,"Register new card"},
/* 5*/{"Vissza"						,"Back"},

/* 6*/{"File"							,"File"},
/* 7*/{"Olvasás"						,"Read"},
/* 8*/{"Írás"							,"Write"},

/* 9*/{"Kijelölt sor kezelése"			,"Highlighted row maintenence"},
/*10*/{"Hozzáad"						,"Add"},
/*11*/{"Beszúr"						,"Insert"},
/*12*/{"Töröl"							,"Remove"},

/*13*/{"Táblázat kezelése"				,"Table maintenence"},
/*14*/{"Ellenõrzés"						,"Cheking"},
/*15*/{"Táblázat törlés"				  	,"Table erase"},

/*16*/{"Stop"						  	,"Stop"},

/*17*/{"RTip/Cím"					  	,"RType/Addr"},
/*18*/{"Card Id"					  	,"Card Id"},
/*19*/{"Tipus"					  		,"Type"},
/*20*/{"Liter"					  		,"Litres"},
/*21*/{"Db"					  		,"Times"},
/*22*/{"Pin"					  		,"Pin"},
/*23*/{"Kut [hex]"					  	,"Pump.[hex]"},
/*24*/{"Sorsz"					  		,"Serial"},
/*25*/{"Csop"					  		,"Group"},
/*26*/{"Prn"					  		,"Prn"},
/*27*/{"Név"					  		,"Name"},

/*28*/{"hiba"					  		,"error"},
/*29*/{"Kiírási HIBA!"		 	  		,"Write out ERROR!"},
/*30*/{"File megnyitási hiba!"		 	,"File open error!"},
/*31*/{"Ellenõrzés"					 	,"Check"},
/*32*/{"Ellenõrzés HIBA!"			 	,"Check error!"},
/*33*/{"Ellenõrzés sikeres!"			 	,"Check OK!"},
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtUjKartyaBe[19][2]={
/* 0*/{"Új kártya bevitel"				,"New card input"},

/* 1*/{"Kártya ID"						,"Card ID"},
/* 2*/{"Olvasó"						,"Reader"},
/* 3*/{"Gyûrû"							,"Ring"},
/* 4*/{"Kézi"							,"Manual"},

/* 5*/{"Tipus"							,"Type"},
/* 6*/{"Ember"							,"Man"},
/* 7*/{"Auto"							,"Wehicle"},
/* 8*/{"Mester"						,"Master"},
/* 9*/{"Szerviz"						,"Service"},

/*10*/{"MaxLiter:"						,"MaxLitres:"},
/*11*/{"MaxDb:"						,"MaxNo:"},
/*12*/{"PIN:"							,"PIN:"},
/*13*/{"Kutak:"						,"Pumps:"},
/*14*/{"Csoport:"						,"Group:"},
/*15*/{"Print:"						,"Print:"},
/*16*/{"Név [20betû]:"					,"Name [20char]:"},

/*17*/{"Mégse"							,"Cancel"},
/*18*/{"Új kártya hozzáadás"				,"Add new card"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtCegnevek[25][2]={
/* 0*/{"Cégnevek beállítása"				,"Firm names setting"},
/* 1*/{"Meglévõ cégadatok"				,"Exist. firm names"},
/* 2*/{"CégDb:"						,"FirmNo:"},
/* 3*/{"CardDb:"						,"CardNo:"},
/* 4*/{"TankDb:"						,"FuelNo:"},

/* 5*/{"Mentés"						,"Save"},
/* 6*/{"Csoport"						,"Group"},
/* 7*/{"Megszakítás"					,"Interrupt"},

/* 8*/{"Kiolvasás"						,"Read"},
/* 9*/{"Beírás"						,"Write"},
/*10*/{"Vissza"						,"Back"},

/*11*/{"Név 1.sor"						,"Name 1.row"},
/*12*/{"Név 2.sor"						,"Name 2.row"},
/*13*/{"Név 3.sor"						,"Name 3.row"},
/*14*/{"Név 4.sor"						,"Name 4.row"},
/*15*/{"Név 5.sor"						,"Name 5.row"},
/*16*/{"Név 6.sor"						,"Name 6.row"},

/*17*/{"Cég"							,"Firm"},
/*18*/{"Javítva"					  	,"Corrected"},
/*19*/{"File létrehozás nem sikerült!"	  	,"File creation fault!"},
/*20*/{"Rossz CSOPORT"	  				,"Bad GROUP"},
/*21*/{"Olvasás"		  				,"Read"},
/*22*/{"Írás OK"		  				,"Write OK"},
/*23*/{"Írás HIBA"		  				,"Write ERROR"},
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtSzintTbl[13][2]={
/* 0*/{"Szintmérõ táblázat beállítása"		,"Level measurement table setting"},
/* 1*/{"Tábla mentés"				   	,"Save table"},
/* 2*/{"-"							,"-"},
/* 3*/{"Szint"						,"Level"},

/* 4*/{"Kiolvasás"    					,"Read"},
/* 5*/{"Beírás"						,"Write"},
/* 6*/{"Vissza"						,"Back"},

/* 7*/{"Cég"						,"Firm"},
/* 8*/{"Javítva"					  	,"Corrected"},
/* 9*/{"File létrehozás nem sikerült!"	  	,"File creation fault!"},

/*10*/{"Olvasás"		  				,"Read"},
/*11*/{"Írás OK"		  				,"Write OK"},
/*12*/{"Írás HIBA"		  			,"Write ERROR"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtArak[23][2]={
/* 0*/{"Árak beállítása"					,"Price setting"},
/* 1*/{"Meglévõ árak"					,"Exist. prices"},
/* 2*/{"Db:"							,"No:"},
/* 3*/{"Mentés"						,"Save"},
/* 4*/{"Csoport:"						,"Group:"},
/* 5*/{"Megszakítás"					,"Interrupt"},
/* 6*/{"Kiolvasás"						,"Read out"},
/* 7*/{"Beírás"						,"Write in"},
/* 8*/{"Vissza"						,"Back"},

/* 9*/{"Csoport"						,"Group"},
/*10*/{"0 - Gázolaj"					,"0 - Diesel"},
/*11*/{"1 - Benzin"						,"1 - Petrol"},

/*12*/{"Ár"							,"Price"},
/*13*/{"Javítva"						,"Repaired"},
/*14*/{"File létrehozás nem sikerült!"		,"File creation failed!"},

/*15*/{"Csoport"						,"Group"},
/*16*/{"Rossz CSOPORT"				 	,"Bad GROUP"},
/*17*/{"Olvasás: HIBA "					,"Read: ERROR "},
/*18*/{"Olvasás: OK "					,"Read: OK "},

/*19*/{"*** 0. ÁR HIBA ***"				,"*** 0. PRICE ERROR ***"},
/*20*/{"*** 1. ÁR HIBA ***"				,"*** 1. PRICE ERROR ***"},
/*21*/{"Írás OK"						,"Write OK"},
/*22*/{"Írás HIBA"						,"Write ERROR"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtEEprom[55][2]={
/* 0*/{"EEprom inicializálás beállítása"    	,"EEprom init setting"},
/* 1*/{" Kútfõk "   				 	," Station "},
/* 2*/{"Be"  		 				 	,"On"},
/* 3*/{"0=Olaj"  		 				,"0=Diesel"},
/* 4*/{"1=Benzin"  		 				,"1=Petrol"},
/* 5*/{"2=Virtuális"  				 	,"2=Virtual"},

/* 6*/{" 1.szinmérõ "	 				," 1.level meter "},
/* 7*/{" 2.szinmérõ "	 				," 2.level meter "},

/* 8*/{" Funkció beállítás "	 			," Function setup "},
/* 9*/{"Liter kijelzés"		 			,"Litres display"},
/*10*/{"2 kártyás"			 			,"2 card"},
/*11*/{"1kút auto start"	 				,"1station auto start"},
/*12*/{"Km bekérés"			 			,"Km input"},
/*13*/{"Km növekvõ"	 					,"Km increasing"},
/*14*/{"Km kétszer"	 					,"Km two times"},
/*15*/{"Vezérlõ szám:"	 			   	,"K4 number:"},
/*16*/{"Menetlevél bekérés"				,"Logbook no. input"},
/*17*/{"Üzemóra bekérés"	 				,"Engine hours input"},
/*18*/{"Sofõr kód bekérés"	 	   		,"Driver code input"},
/*19*/{"Nyelv:"	 					,"Language:"},

/*20*/{" Kontraszt "	 				," Contrast "},
/*21*/{"Kontraszt:"	 					,"Contrast:"},
/*22*/{"Kompenz.:"	 					,"Compens.:"},
/*23*/{"Hõm. szorzó:" 					,"Temp.multip.:"},
/*24*/{"Hõm. offset:" 					,"Temp.offset:"},

/*25*/{" Gyûrûs pisztoly " 				," Nozzle RF read "},
/*26*/{"Pisztoly 1:"	 				,"Nozzle 1:"},
/*27*/{"Pisztoly 2:"	 				,"Nozzle 2:"},
/*28*/{"Pisztoly 3:"	 				,"Nozzle 3:"},
/*29*/{"0=nincs"	 					,"0=no"},
/*30*/{"1-14=kútfõ"	 					,"1-14=pump"},

/*31*/{" Kártyaolvasó 1"	 		   	," Card reader 1"},
/*32*/{"1 - régi(DEC-[#+10+1+3])"	 		,"1 - old(DEC-[#+10+1+3])"},
/*33*/{"2 - új(DEC-[#+10+1])"	 			,"2 - new(DEC-[#+10+1])"},
/*34*/{"3 - HEX[x2+08x+x3]"				,"3 - HEX[x2+08x+x3]"},
/*35*/{"4 - [x1+10c+x2]"	 			 	,"4 - [x1+10c+x2]"},
/*36*/{"5 - Mifare"	 					,"5 - Mifare"},
/*37*/{"6 - CrossPoint"	 			    	,"6 - CrossPoint"},
/*38*/{"7 - DEC10 [#+10]"	 		  	,"7 - DEC10 [#+10]"},

/*39*/{" Nyomtatás "					," Printing "},
/*40*/{"Példányszám (0,1,2,9):"	 		,"Copies (0,1,2,9):"},

/*41*/{" Idõzítések "					," Timings "},
/*42*/{"Menü visszalépés:"	 			,"Menu back time:"},
/*43*/{"Menü utánvilágítás:"	 			,"Menu over light:"},
/*44*/{"(1-254s, 0v.255=nincs)"	 	   	,"(1-254s, 0or255=no)"},
/*45*/{"(0-254s, 255=állandó)"	 	   	,"(0-254s, 255=const.)"},

/*46*/{"Kiolvasás"	 					,"Read K4"},
/*47*/{"Beírás"	 					,"Write K4"},
/*48*/{"Vissza"	 					,"Back"},

/*49*/{"Írás OK"	 					,"Write OK"},
/*50*/{"Írás HIBA"	 					,"Write ERROR"},

/*51*/{" Kártyaolvasó 2"			    		," Card reader 2"},
/*52*/{"0 - nincs"				 		,"0 - no"},
/*53*/{"1 - régi(DEC-[#+10+1+3])"	 		,"1 - old(DEC-[#+10+1+3])"},
/*54*/{"MaxStop bekérés)"	 			,"MaxStop input"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtOraBe[12][2]={
/* 0*/{"Óra beállítás"					,"Clock set"},
/* 1*/{"Idõ"							,"Time:"},
/* 2*/{"Utolsó beállítás:"				,"Last set:"},
/* 3*/{"Beállítás"						,"Set"},

/* 4*/{"Korrekció"						,"Correction"},
/* 5*/{"16384percenként 0..127mp"			,"16384min. period 0..127s"},
/* 6*/{"Elõre(késik)"					,"Foreward(late)"},
/* 7*/{"Hátra(siet)"					,"Backward(hurry)"},
/* 8*/{"Beírás"						,"Write in"},

/* 9*/{"Vissza"						,"Back"},
/*10*/{"OK"							,"OK"},
/*11*/{"HIBA!"							,"ERROR!"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtNyomtato[2][2]={
/* 0*/{"Nyomtató teszt"					,"Printer test"},
/* 1*/{"Törlés"						,"Clear"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtKutfoTst[23][2]={
/* 0*/{"Kútfõ teszt"					,"Fuelpump test"},
/* 1*/{"Kútfõ"							,"Pump"},

/* 2*/{"Hiba:"							,"Error:"},
/* 3*/{"Parancs:"						,"Command:"},
/* 4*/{"Limit:"  						,"Limit:"},
/* 5*/{"Státusz:"						,"Status:"},

/* 6*/{"Fej:"							,"Nozzle:"},
/* 7*/{"Kézi:"							,"Manual:"},
/* 8*/{"Sum1:"							,"Sum1:"},
/* 9*/{"Sum2:"							,"Sum2:"},
/*10*/{"LopCl:"						,"AbuseCl:"},
/*11*/{"Relé:"							,"Relay:"},
/*12*/{"Vez:"							,"Cont:"},
/*13*/{"Komp:"							,"Comp:"},

/*14*/{"GyûrûsPisztoly:"					,"RingHead:"},
/*15*/{"Hõmérséklet:"					,"Temperature:"},

/*16*/{"LiterKomp:"						,"LiterComp:"},
/*17*/{"GörgetettKomp:"					,"SumComp:"},
/*18*/{"Liter:"						,"Liter:"},
/*19*/{"Görgetett:"						,"Sum:"},

/*20*/{"LiterOld:"						,"LiterOld:"},
/*21*/{"TimeOut:"						,"TimeOut:"},
/*22*/{"Utóvilágítás:"					,"LightOver:"},
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtTankTst[31][2]={
/* 0*/{"Tankolás teszt"					,"Refuleing test"},
/* 1*/{"Kútfõ"							,"Pump"},

/* 2*/{"Kezdés"						,"Start"},
/* 3*/{"Verzió:"						,"Version:"},
/* 4*/{"Idõ:"							,"Time:"},
/* 5*/{"VezNum:"						,"BCUNum:"},
/* 6*/{"KutNum:"						,"PumpNum:"},

/* 7*/{"EmberNum:"						,"PersonNum:"},
/* 8*/{"EmberID:"						,"PersonID:"},
/* 9*/{"Ember:"						,"Person:"},

/*10*/{"AutoNum:"						,"VehiNum:"},
/*11*/{"AutoID:"						,"VehiID:"},
/*12*/{"Auto:"							,"Vehicle:"},

/*13*/{"Csoport:"						,"Group:"},
/*14*/{"Km:"							,"Kms:"},
/*15*/{"Menlev:"						,"Logbook:"},
/*16*/{"Üzemóra:"						,"EngineHrs:"},

/*17*/{"GörgKomp:"						,"CumuComp:"},
/*18*/{"EgysÁr:"						,"UnitPr:"},
/*19*/{"Sorsz.:"						,"Serial:"},

/*20*/{"Görgetett:"						,"Cumulative:"},
/*21*/{"Szint:"						,"Level:"},

/*22*/{"Zárás"							,"End"},

/*23*/{"Netto:"						,"Net:"},
/*24*/{"Nyomtat:"						,"Print:"},

/*25*/{"LitKomp:"						,"LtComp:"},
/*26*/{"Hõmérs.:"						,"Temp.:"},
/*27*/{"Brutto:"						,"Gross:"},

/*28*/{"Liter:"						,"Litres:"},
/*29*/{"VégeKód:"						,"EndCode:"},
/*30*/{"Sum:"							,"Sum:"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtGyurus[5][2]={
/* 0*/{"Gyûrûs pisztoly teszt"			,"Nozzle RF read test"},
/* 1*/{"Pisztoly kapcsolat"				,"Nozzle connection"},
/* 2*/{"Van:"							,"Exist:"},
/* 3*/{"Idõ:"							,"Time:"},
/* 4*/{"Kód:"							,"Code:"},
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtAnalog[18][2]={
/* 0*/{"Analóg mérések"					,"Analog measurements"},
/* 1*/{"Kiolv"							,"Read"},

/* 2*/{"Tápfeszültségek"					,"Power supply voltages:"},
/* 3*/{"Beír U11"						,"Write U11"},

/* 4*/{"4..20mA 1-es bemenet:"			,"4..20mA input 1:"},
/* 5*/{"Szorzó:"						,"Multiplier:"},
/* 6*/{"Nulla:"							,"Offset:"},
/* 7*/{"Beír Ma1"						,"Write Ma1"},

/* 8*/{"4..20mA 2-es bemenet:"			,"4..20mA input 2:"},
/* 9*/{"Beír Ma2"						,"Write Ma2"},

/*10*/{"OK"								,"OK"},
/*11*/{"HIBA"							,"ERROR"},
/*12*/{"Kiolvasás OK"	   				,"Read OK"},
/*13*/{"Kiolvasás HIBA"   				,"Read ERROR"},

/*14*/{"4..20mA 3-as bemenet:"			,"4..20mA input 3:"},
/*15*/{"Beír Ma3"						,"Write Ma3"},
/*16*/{"4..20mA 4-es bemenet:"			,"4..20mA input 4:"},
/*17*/{"Beír Ma4"						,"Write Ma4"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtSzintTst[7][2]={
/* 0*/{"Szintmérõ teszt"					,"ATG test"},
/* 1*/{"Szintmérõ csomagok:"				,"ATG packages:"},
/* 2*/{"Mintavétel"						,"Sampling"},
/* 3*/{"Start"							,"Start"},
/* 4*/{"Stop"							,"Stop"},
/* 5*/{"Törlés"						,"Erase"},
/* 6*/{"Kilépés"						,"Exit"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtTeszt[1][2]={
/* 0*/{"Memória kijelzés"				,"Memory display"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtBeall[2][2]={
/* 0*/{"Cím beállítás"					,"Set address"},
/* 1*/{"Cím:"							,"Addr.:"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtUpgrade[35][2]={
/* 0*/{"Upgrade"						,"Upgrade"},
/* 1*/{"Program letöltés"				,"Program download"},

/* 2*/{"Automatikus"					,"Automatic"},
/* 3*/{"Lépésenként"					,"StepByStep"},
/* 4*/{"HexFile"						,"HexFile"},

/* 5*/{"Új program letöltés:"				,"New program download:"},

/* 6*/{"K4 upgrade törlés"				,"K4 upgrade erase"},
/* 7*/{"K4 upgrade írás"					,"K4 upgrade write"},
/* 8*/{"K4 upgrade olvasás"				,"K4 upgrade read"},

/* 9*/{" K4 program verzió kezelés "		," K4 program version maintenence "},
/*10*/{"Élõ verzió olvasás:"				,"Live version read:"},
/*11*/{"Kútfõk állapota:"				,"Fuelpump status:"},
/*12*/{"Verzió csere"					,"Change version"},
/*13*/{"Program kiolvasás:"				,"Program readout:"},
/*14*/{"Program töltõ csere"				,"Change program loader"},

/*15*/{" Memória kezelés "				," Memory maintetnence "},
/*16*/{"Hex file"						,"Hex file"},
/*17*/{"Program memória"					,"Program memory"},
/*18*/{"Memória kijelzés"				,"Memory display"},
/*20*/{"DUMP file írás"					,"Write DUMP file"},

/*21*/{"DUMP file megnyitási hiba!"		,"DUMP file open error!"},
/*22*/{"kiírás nem teljes!"				,"Write not complete!"},
/*23*/{"kiírás sikerült!"				,"Write completed!"},
/*24*/{"SIKERES letöltés !"				,"Download Sucsess !"},
/*25*/{"Hibák száma"					,"No of errors"},

/*26*/{"HEX file túl nagy!"				,"HEX file too big!"},
/*27*/{"beolvasás nem teljes!"		    	,"Read not complete!"},
/*28*/{"beolvasás sikerült!"				,"Read completed!"},

/*29*/{"*** VERZIÓ CSERE ***"				,"*** CHANGE VERSION ***"},
/*30*/{"Biztosan ki akarod cserélni a futó verziót ?","Do you want to replace current version ?"},
/*31*/{"*** PROGRAM TÖLTÕ CSERE ***"	    	,"*** REPLACE PROGRAM LOADER ***"},
/*32*/{"Biztosan ki akarod cserélni a program töltõt ?","Do you want to replace the program loader ?"},

/*33*/{"Program Verzió"					,"Program version"},
/*34*/{"Töltõ Verzió"					,"Loader version"},
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtHexFile[13][2]={
/* 0*/{"Hex file"						,"Hex file"},
/* 1*/{"Hex file"						,"Hex file"},
/* 2*/{"Byte"							,"Byte"},
/* 3*/{"Cím"							,"Addr."},
/* 4*/{"Típus"							,"Type"},
/* 5*/{"Word1"							,"Word1"},
/* 6*/{"Word2"							,"Word2"},
/* 7*/{"Word3"							,"Word3"},
/* 8*/{"Word4"							,"Word4"},
/* 9*/{"Word5"							,"Word5"},
/*10*/{"Word6"							,"Word6"},
/*11*/{"Word7"							,"Word7"},
/*12*/{"Word8"							,"Word8"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtMemo[2][2]={
/* 0*/{"Program memória"					,"Program memory"},
/* 1*/{"Cím"							,"Address"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtFlsClear[20][2]={
/* 0*/{"Flash Clear"					,"Flash Clear"},
/* 1*/{"VIGYÁZZ TÖRÖLSZ !!!"				,"ATTENTION ERASING !!!"},
/* 2*/{" Tankolások "					," Refuellings "},
/* 3*/{" Kártyák "						," Cards "},
/* 4*/{" Árak "						," Prices "},
/* 5*/{" Cégek "						," Firms "},
/* 6*/{"Olvas"							,"Read"},
/* 7*/{"Törlés"						,"Erase"},
/* 8*/{"Stop"							,"Stop"},
/* 9*/{"Vissza"						,"Back"},

/*10*/{"db rekord foglalt"				," record used"},
/*11*/{"db rekord törölve"				," record erased"},

/*12*/{"Tankolások törlése"			 	,"Delete fueling log"},
/*13*/{"Törölni akarod a tankolásokat ?" 	,"Do you want to delete fueling log ?"},
/*14*/{"Kártyák törlése"			 		,"Delete cards"},
/*15*/{"Törölni akarod a kártyákat ?" 		,"Do you want to delete cards ?"},
/*16*/{"Árak törlése"				 	,"Delet prices"},
/*17*/{"Törölni akarod az árakat ?" 		,"Do you want to delete prices ?"},
/*18*/{"Cégek törlése"				 	,"Delete companies"},
/*19*/{"Törölni akarod a cégeket ?" 		,"Do you want to delete companies ?"}
};
//---------------------------------------------------------------------------

