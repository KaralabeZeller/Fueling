#include <vcl.h>
#pragma hdrstop
#include "cTxtBenzin.h"
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtVez[28][2]={
/* 0*/{"K4 vez�rl� karbantart�s"			,"K4 controller maintenance"},

/* 1*/{"Adatkezel�s"					,"Data maintenance"},
/* 2*/{"Tankol�si adatok let�lt�se file-ba"	,"Download refuel data"},
/* 3*/{"K�rtya adatok kezel�se"			,"Manage card data"},

/* 4*/{"Be�ll�t�sok"					,"Settings"},
/* 5*/{"C�gnevek be�ll�t�sa"				,"Set firm names"},
/* 6*/{"�rak be�ll�t�sa"					,"Set prices"},
/* 7*/{"EEprom init be�ll�t�sa"			,"Set EEPROM init"},
/* 8*/{"�ra be�ll�t�s"					,"Set time"},

/* 9*/{"Tesztek"						,"Test"},
/*10*/{"Nyomtat� teszt"					,"Printer test"},
/*11*/{"K�tf� teszt"					,"Fuelpump test"},
/*12*/{"Tankol�s teszt"					,"Refuel test"},
/*13*/{"Gy�r�s fej teszt"				,"Ring head test"},

/*14*/{"Szintm�r� teszt"			     	,"ATG test"},
/*15*/{"Anal�g m�r�sek"					,"Analog measurements"},
/*16*/{"Mem�ria kijelz�s"				,"Memory map"},

/*17*/{"Kapcsolat"				     	,"Connection"},
/*18*/{"IP c�m:"						,"IP address:"},
/*19*/{"UDP port:"				     	,"UDP port:"},
/*20*/{"K�t sz�m:"				     	,"Pump num:"},
/*21*/{"NET3 soros port:"				,"NET3 serial port:"},
/*22*/{"0-r�gi verzi�"					,"0-old version"},
/*23*/{"1-Rs485/232"					,"1-Rs485/232"},
/*24*/{"2-Rs232"						,"2-Rs232"},

/*25*/{"Upgrade"						,"Upgrade"},
/*26*/{"T�rl�s"						,"Erase"},
/*27*/{"Szint t�bla"					,"Level table"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtBenzMent[6][2]={
/* 0*/{"Tankol�si adatok let�lt�se"		,"Save refuelling data"},
/* 1*/{"Let�lt�s"						,"Save"},
/* 2*/{"Megszak�t�s"					,"Interrupt"},
/* 3*/{"Tank"							,"Refuel"},
/* 4*/{"Jav�tva"						,"Reaired"},
/* 5*/{"Kezd� c�m:"						,"Start address:"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtCardKonv[34][2]={
/* 0*/{"K�rtya konvert�l�s"				,"Card konversion"},

/* 1*/{"K4 olvas�s"						,"Read K4"},
/* 2*/{"Dump"							,"Dump"},
/* 3*/{"Be�r�s K4-be"					,"Write K4"},
/* 4*/{"�j k�rtya bevitel"				,"Register new card"},
/* 5*/{"Vissza"						,"Back"},

/* 6*/{"File"							,"File"},
/* 7*/{"Olvas�s"						,"Read"},
/* 8*/{"�r�s"							,"Write"},

/* 9*/{"Kijel�lt sor kezel�se"			,"Highlighted row maintenence"},
/*10*/{"Hozz�ad"						,"Add"},
/*11*/{"Besz�r"						,"Insert"},
/*12*/{"T�r�l"							,"Remove"},

/*13*/{"T�bl�zat kezel�se"				,"Table maintenence"},
/*14*/{"Ellen�rz�s"						,"Cheking"},
/*15*/{"T�bl�zat t�rl�s"				  	,"Table erase"},

/*16*/{"Stop"						  	,"Stop"},

/*17*/{"RTip/C�m"					  	,"RType/Addr"},
/*18*/{"Card Id"					  	,"Card Id"},
/*19*/{"Tipus"					  		,"Type"},
/*20*/{"Liter"					  		,"Litres"},
/*21*/{"Db"					  		,"Times"},
/*22*/{"Pin"					  		,"Pin"},
/*23*/{"Kut [hex]"					  	,"Pump.[hex]"},
/*24*/{"Sorsz"					  		,"Serial"},
/*25*/{"Csop"					  		,"Group"},
/*26*/{"Prn"					  		,"Prn"},
/*27*/{"N�v"					  		,"Name"},

/*28*/{"hiba"					  		,"error"},
/*29*/{"Ki�r�si HIBA!"		 	  		,"Write out ERROR!"},
/*30*/{"File megnyit�si hiba!"		 	,"File open error!"},
/*31*/{"Ellen�rz�s"					 	,"Check"},
/*32*/{"Ellen�rz�s HIBA!"			 	,"Check error!"},
/*33*/{"Ellen�rz�s sikeres!"			 	,"Check OK!"},
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtUjKartyaBe[19][2]={
/* 0*/{"�j k�rtya bevitel"				,"New card input"},

/* 1*/{"K�rtya ID"						,"Card ID"},
/* 2*/{"Olvas�"						,"Reader"},
/* 3*/{"Gy�r�"							,"Ring"},
/* 4*/{"K�zi"							,"Manual"},

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
/*16*/{"N�v [20bet�]:"					,"Name [20char]:"},

/*17*/{"M�gse"							,"Cancel"},
/*18*/{"�j k�rtya hozz�ad�s"				,"Add new card"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtCegnevek[25][2]={
/* 0*/{"C�gnevek be�ll�t�sa"				,"Firm names setting"},
/* 1*/{"Megl�v� c�gadatok"				,"Exist. firm names"},
/* 2*/{"C�gDb:"						,"FirmNo:"},
/* 3*/{"CardDb:"						,"CardNo:"},
/* 4*/{"TankDb:"						,"FuelNo:"},

/* 5*/{"Ment�s"						,"Save"},
/* 6*/{"Csoport"						,"Group"},
/* 7*/{"Megszak�t�s"					,"Interrupt"},

/* 8*/{"Kiolvas�s"						,"Read"},
/* 9*/{"Be�r�s"						,"Write"},
/*10*/{"Vissza"						,"Back"},

/*11*/{"N�v 1.sor"						,"Name 1.row"},
/*12*/{"N�v 2.sor"						,"Name 2.row"},
/*13*/{"N�v 3.sor"						,"Name 3.row"},
/*14*/{"N�v 4.sor"						,"Name 4.row"},
/*15*/{"N�v 5.sor"						,"Name 5.row"},
/*16*/{"N�v 6.sor"						,"Name 6.row"},

/*17*/{"C�g"							,"Firm"},
/*18*/{"Jav�tva"					  	,"Corrected"},
/*19*/{"File l�trehoz�s nem siker�lt!"	  	,"File creation fault!"},
/*20*/{"Rossz CSOPORT"	  				,"Bad GROUP"},
/*21*/{"Olvas�s"		  				,"Read"},
/*22*/{"�r�s OK"		  				,"Write OK"},
/*23*/{"�r�s HIBA"		  				,"Write ERROR"},
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtSzintTbl[13][2]={
/* 0*/{"Szintm�r� t�bl�zat be�ll�t�sa"		,"Level measurement table setting"},
/* 1*/{"T�bla ment�s"				   	,"Save table"},
/* 2*/{"-"							,"-"},
/* 3*/{"Szint"						,"Level"},

/* 4*/{"Kiolvas�s"    					,"Read"},
/* 5*/{"Be�r�s"						,"Write"},
/* 6*/{"Vissza"						,"Back"},

/* 7*/{"C�g"						,"Firm"},
/* 8*/{"Jav�tva"					  	,"Corrected"},
/* 9*/{"File l�trehoz�s nem siker�lt!"	  	,"File creation fault!"},

/*10*/{"Olvas�s"		  				,"Read"},
/*11*/{"�r�s OK"		  				,"Write OK"},
/*12*/{"�r�s HIBA"		  			,"Write ERROR"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtArak[23][2]={
/* 0*/{"�rak be�ll�t�sa"					,"Price setting"},
/* 1*/{"Megl�v� �rak"					,"Exist. prices"},
/* 2*/{"Db:"							,"No:"},
/* 3*/{"Ment�s"						,"Save"},
/* 4*/{"Csoport:"						,"Group:"},
/* 5*/{"Megszak�t�s"					,"Interrupt"},
/* 6*/{"Kiolvas�s"						,"Read out"},
/* 7*/{"Be�r�s"						,"Write in"},
/* 8*/{"Vissza"						,"Back"},

/* 9*/{"Csoport"						,"Group"},
/*10*/{"0 - G�zolaj"					,"0 - Diesel"},
/*11*/{"1 - Benzin"						,"1 - Petrol"},

/*12*/{"�r"							,"Price"},
/*13*/{"Jav�tva"						,"Repaired"},
/*14*/{"File l�trehoz�s nem siker�lt!"		,"File creation failed!"},

/*15*/{"Csoport"						,"Group"},
/*16*/{"Rossz CSOPORT"				 	,"Bad GROUP"},
/*17*/{"Olvas�s: HIBA "					,"Read: ERROR "},
/*18*/{"Olvas�s: OK "					,"Read: OK "},

/*19*/{"*** 0. �R HIBA ***"				,"*** 0. PRICE ERROR ***"},
/*20*/{"*** 1. �R HIBA ***"				,"*** 1. PRICE ERROR ***"},
/*21*/{"�r�s OK"						,"Write OK"},
/*22*/{"�r�s HIBA"						,"Write ERROR"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtEEprom[55][2]={
/* 0*/{"EEprom inicializ�l�s be�ll�t�sa"    	,"EEprom init setting"},
/* 1*/{" K�tf�k "   				 	," Station "},
/* 2*/{"Be"  		 				 	,"On"},
/* 3*/{"0=Olaj"  		 				,"0=Diesel"},
/* 4*/{"1=Benzin"  		 				,"1=Petrol"},
/* 5*/{"2=Virtu�lis"  				 	,"2=Virtual"},

/* 6*/{" 1.szinm�r� "	 				," 1.level meter "},
/* 7*/{" 2.szinm�r� "	 				," 2.level meter "},

/* 8*/{" Funkci� be�ll�t�s "	 			," Function setup "},
/* 9*/{"Liter kijelz�s"		 			,"Litres display"},
/*10*/{"2 k�rty�s"			 			,"2 card"},
/*11*/{"1k�t auto start"	 				,"1station auto start"},
/*12*/{"Km bek�r�s"			 			,"Km input"},
/*13*/{"Km n�vekv�"	 					,"Km increasing"},
/*14*/{"Km k�tszer"	 					,"Km two times"},
/*15*/{"Vez�rl� sz�m:"	 			   	,"K4 number:"},
/*16*/{"Menetlev�l bek�r�s"				,"Logbook no. input"},
/*17*/{"�zem�ra bek�r�s"	 				,"Engine hours input"},
/*18*/{"Sof�r k�d bek�r�s"	 	   		,"Driver code input"},
/*19*/{"Nyelv:"	 					,"Language:"},

/*20*/{" Kontraszt "	 				," Contrast "},
/*21*/{"Kontraszt:"	 					,"Contrast:"},
/*22*/{"Kompenz.:"	 					,"Compens.:"},
/*23*/{"H�m. szorz�:" 					,"Temp.multip.:"},
/*24*/{"H�m. offset:" 					,"Temp.offset:"},

/*25*/{" Gy�r�s pisztoly " 				," Nozzle RF read "},
/*26*/{"Pisztoly 1:"	 				,"Nozzle 1:"},
/*27*/{"Pisztoly 2:"	 				,"Nozzle 2:"},
/*28*/{"Pisztoly 3:"	 				,"Nozzle 3:"},
/*29*/{"0=nincs"	 					,"0=no"},
/*30*/{"1-14=k�tf�"	 					,"1-14=pump"},

/*31*/{" K�rtyaolvas� 1"	 		   	," Card reader 1"},
/*32*/{"1 - r�gi(DEC-[#+10+1+3])"	 		,"1 - old(DEC-[#+10+1+3])"},
/*33*/{"2 - �j(DEC-[#+10+1])"	 			,"2 - new(DEC-[#+10+1])"},
/*34*/{"3 - HEX[x2+08x+x3]"				,"3 - HEX[x2+08x+x3]"},
/*35*/{"4 - [x1+10c+x2]"	 			 	,"4 - [x1+10c+x2]"},
/*36*/{"5 - Mifare"	 					,"5 - Mifare"},
/*37*/{"6 - CrossPoint"	 			    	,"6 - CrossPoint"},
/*38*/{"7 - DEC10 [#+10]"	 		  	,"7 - DEC10 [#+10]"},

/*39*/{" Nyomtat�s "					," Printing "},
/*40*/{"P�ld�nysz�m (0,1,2,9):"	 		,"Copies (0,1,2,9):"},

/*41*/{" Id�z�t�sek "					," Timings "},
/*42*/{"Men� visszal�p�s:"	 			,"Menu back time:"},
/*43*/{"Men� ut�nvil�g�t�s:"	 			,"Menu over light:"},
/*44*/{"(1-254s, 0v.255=nincs)"	 	   	,"(1-254s, 0or255=no)"},
/*45*/{"(0-254s, 255=�lland�)"	 	   	,"(0-254s, 255=const.)"},

/*46*/{"Kiolvas�s"	 					,"Read K4"},
/*47*/{"Be�r�s"	 					,"Write K4"},
/*48*/{"Vissza"	 					,"Back"},

/*49*/{"�r�s OK"	 					,"Write OK"},
/*50*/{"�r�s HIBA"	 					,"Write ERROR"},

/*51*/{" K�rtyaolvas� 2"			    		," Card reader 2"},
/*52*/{"0 - nincs"				 		,"0 - no"},
/*53*/{"1 - r�gi(DEC-[#+10+1+3])"	 		,"1 - old(DEC-[#+10+1+3])"},
/*54*/{"MaxStop bek�r�s)"	 			,"MaxStop input"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtOraBe[12][2]={
/* 0*/{"�ra be�ll�t�s"					,"Clock set"},
/* 1*/{"Id�"							,"Time:"},
/* 2*/{"Utols� be�ll�t�s:"				,"Last set:"},
/* 3*/{"Be�ll�t�s"						,"Set"},

/* 4*/{"Korrekci�"						,"Correction"},
/* 5*/{"16384percenk�nt 0..127mp"			,"16384min. period 0..127s"},
/* 6*/{"El�re(k�sik)"					,"Foreward(late)"},
/* 7*/{"H�tra(siet)"					,"Backward(hurry)"},
/* 8*/{"Be�r�s"						,"Write in"},

/* 9*/{"Vissza"						,"Back"},
/*10*/{"OK"							,"OK"},
/*11*/{"HIBA!"							,"ERROR!"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtNyomtato[2][2]={
/* 0*/{"Nyomtat� teszt"					,"Printer test"},
/* 1*/{"T�rl�s"						,"Clear"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtKutfoTst[23][2]={
/* 0*/{"K�tf� teszt"					,"Fuelpump test"},
/* 1*/{"K�tf�"							,"Pump"},

/* 2*/{"Hiba:"							,"Error:"},
/* 3*/{"Parancs:"						,"Command:"},
/* 4*/{"Limit:"  						,"Limit:"},
/* 5*/{"St�tusz:"						,"Status:"},

/* 6*/{"Fej:"							,"Nozzle:"},
/* 7*/{"K�zi:"							,"Manual:"},
/* 8*/{"Sum1:"							,"Sum1:"},
/* 9*/{"Sum2:"							,"Sum2:"},
/*10*/{"LopCl:"						,"AbuseCl:"},
/*11*/{"Rel�:"							,"Relay:"},
/*12*/{"Vez:"							,"Cont:"},
/*13*/{"Komp:"							,"Comp:"},

/*14*/{"Gy�r�sPisztoly:"					,"RingHead:"},
/*15*/{"H�m�rs�klet:"					,"Temperature:"},

/*16*/{"LiterKomp:"						,"LiterComp:"},
/*17*/{"G�rgetettKomp:"					,"SumComp:"},
/*18*/{"Liter:"						,"Liter:"},
/*19*/{"G�rgetett:"						,"Sum:"},

/*20*/{"LiterOld:"						,"LiterOld:"},
/*21*/{"TimeOut:"						,"TimeOut:"},
/*22*/{"Ut�vil�g�t�s:"					,"LightOver:"},
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtTankTst[31][2]={
/* 0*/{"Tankol�s teszt"					,"Refuleing test"},
/* 1*/{"K�tf�"							,"Pump"},

/* 2*/{"Kezd�s"						,"Start"},
/* 3*/{"Verzi�:"						,"Version:"},
/* 4*/{"Id�:"							,"Time:"},
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
/*16*/{"�zem�ra:"						,"EngineHrs:"},

/*17*/{"G�rgKomp:"						,"CumuComp:"},
/*18*/{"Egys�r:"						,"UnitPr:"},
/*19*/{"Sorsz.:"						,"Serial:"},

/*20*/{"G�rgetett:"						,"Cumulative:"},
/*21*/{"Szint:"						,"Level:"},

/*22*/{"Z�r�s"							,"End"},

/*23*/{"Netto:"						,"Net:"},
/*24*/{"Nyomtat:"						,"Print:"},

/*25*/{"LitKomp:"						,"LtComp:"},
/*26*/{"H�m�rs.:"						,"Temp.:"},
/*27*/{"Brutto:"						,"Gross:"},

/*28*/{"Liter:"						,"Litres:"},
/*29*/{"V�geK�d:"						,"EndCode:"},
/*30*/{"Sum:"							,"Sum:"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtGyurus[5][2]={
/* 0*/{"Gy�r�s pisztoly teszt"			,"Nozzle RF read test"},
/* 1*/{"Pisztoly kapcsolat"				,"Nozzle connection"},
/* 2*/{"Van:"							,"Exist:"},
/* 3*/{"Id�:"							,"Time:"},
/* 4*/{"K�d:"							,"Code:"},
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtAnalog[18][2]={
/* 0*/{"Anal�g m�r�sek"					,"Analog measurements"},
/* 1*/{"Kiolv"							,"Read"},

/* 2*/{"T�pfesz�lts�gek"					,"Power supply voltages:"},
/* 3*/{"Be�r U11"						,"Write U11"},

/* 4*/{"4..20mA 1-es bemenet:"			,"4..20mA input 1:"},
/* 5*/{"Szorz�:"						,"Multiplier:"},
/* 6*/{"Nulla:"							,"Offset:"},
/* 7*/{"Be�r Ma1"						,"Write Ma1"},

/* 8*/{"4..20mA 2-es bemenet:"			,"4..20mA input 2:"},
/* 9*/{"Be�r Ma2"						,"Write Ma2"},

/*10*/{"OK"								,"OK"},
/*11*/{"HIBA"							,"ERROR"},
/*12*/{"Kiolvas�s OK"	   				,"Read OK"},
/*13*/{"Kiolvas�s HIBA"   				,"Read ERROR"},

/*14*/{"4..20mA 3-as bemenet:"			,"4..20mA input 3:"},
/*15*/{"Be�r Ma3"						,"Write Ma3"},
/*16*/{"4..20mA 4-es bemenet:"			,"4..20mA input 4:"},
/*17*/{"Be�r Ma4"						,"Write Ma4"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtSzintTst[7][2]={
/* 0*/{"Szintm�r� teszt"					,"ATG test"},
/* 1*/{"Szintm�r� csomagok:"				,"ATG packages:"},
/* 2*/{"Mintav�tel"						,"Sampling"},
/* 3*/{"Start"							,"Start"},
/* 4*/{"Stop"							,"Stop"},
/* 5*/{"T�rl�s"						,"Erase"},
/* 6*/{"Kil�p�s"						,"Exit"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtTeszt[1][2]={
/* 0*/{"Mem�ria kijelz�s"				,"Memory display"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtBeall[2][2]={
/* 0*/{"C�m be�ll�t�s"					,"Set address"},
/* 1*/{"C�m:"							,"Addr.:"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtUpgrade[35][2]={
/* 0*/{"Upgrade"						,"Upgrade"},
/* 1*/{"Program let�lt�s"				,"Program download"},

/* 2*/{"Automatikus"					,"Automatic"},
/* 3*/{"L�p�senk�nt"					,"StepByStep"},
/* 4*/{"HexFile"						,"HexFile"},

/* 5*/{"�j program let�lt�s:"				,"New program download:"},

/* 6*/{"K4 upgrade t�rl�s"				,"K4 upgrade erase"},
/* 7*/{"K4 upgrade �r�s"					,"K4 upgrade write"},
/* 8*/{"K4 upgrade olvas�s"				,"K4 upgrade read"},

/* 9*/{" K4 program verzi� kezel�s "		," K4 program version maintenence "},
/*10*/{"�l� verzi� olvas�s:"				,"Live version read:"},
/*11*/{"K�tf�k �llapota:"				,"Fuelpump status:"},
/*12*/{"Verzi� csere"					,"Change version"},
/*13*/{"Program kiolvas�s:"				,"Program readout:"},
/*14*/{"Program t�lt� csere"				,"Change program loader"},

/*15*/{" Mem�ria kezel�s "				," Memory maintetnence "},
/*16*/{"Hex file"						,"Hex file"},
/*17*/{"Program mem�ria"					,"Program memory"},
/*18*/{"Mem�ria kijelz�s"				,"Memory display"},
/*20*/{"DUMP file �r�s"					,"Write DUMP file"},

/*21*/{"DUMP file megnyit�si hiba!"		,"DUMP file open error!"},
/*22*/{"ki�r�s nem teljes!"				,"Write not complete!"},
/*23*/{"ki�r�s siker�lt!"				,"Write completed!"},
/*24*/{"SIKERES let�lt�s !"				,"Download Sucsess !"},
/*25*/{"Hib�k sz�ma"					,"No of errors"},

/*26*/{"HEX file t�l nagy!"				,"HEX file too big!"},
/*27*/{"beolvas�s nem teljes!"		    	,"Read not complete!"},
/*28*/{"beolvas�s siker�lt!"				,"Read completed!"},

/*29*/{"*** VERZI� CSERE ***"				,"*** CHANGE VERSION ***"},
/*30*/{"Biztosan ki akarod cser�lni a fut� verzi�t ?","Do you want to replace current version ?"},
/*31*/{"*** PROGRAM T�LT� CSERE ***"	    	,"*** REPLACE PROGRAM LOADER ***"},
/*32*/{"Biztosan ki akarod cser�lni a program t�lt�t ?","Do you want to replace the program loader ?"},

/*33*/{"Program Verzi�"					,"Program version"},
/*34*/{"T�lt� Verzi�"					,"Loader version"},
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtHexFile[13][2]={
/* 0*/{"Hex file"						,"Hex file"},
/* 1*/{"Hex file"						,"Hex file"},
/* 2*/{"Byte"							,"Byte"},
/* 3*/{"C�m"							,"Addr."},
/* 4*/{"T�pus"							,"Type"},
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
/* 0*/{"Program mem�ria"					,"Program memory"},
/* 1*/{"C�m"							,"Address"}
};
//---------------------------------------------------------------------------
//     "magyar"						,"angol"
AnsiString	TxtFlsClear[20][2]={
/* 0*/{"Flash Clear"					,"Flash Clear"},
/* 1*/{"VIGY�ZZ T�R�LSZ !!!"				,"ATTENTION ERASING !!!"},
/* 2*/{" Tankol�sok "					," Refuellings "},
/* 3*/{" K�rty�k "						," Cards "},
/* 4*/{" �rak "						," Prices "},
/* 5*/{" C�gek "						," Firms "},
/* 6*/{"Olvas"							,"Read"},
/* 7*/{"T�rl�s"						,"Erase"},
/* 8*/{"Stop"							,"Stop"},
/* 9*/{"Vissza"						,"Back"},

/*10*/{"db rekord foglalt"				," record used"},
/*11*/{"db rekord t�r�lve"				," record erased"},

/*12*/{"Tankol�sok t�rl�se"			 	,"Delete fueling log"},
/*13*/{"T�r�lni akarod a tankol�sokat ?" 	,"Do you want to delete fueling log ?"},
/*14*/{"K�rty�k t�rl�se"			 		,"Delete cards"},
/*15*/{"T�r�lni akarod a k�rty�kat ?" 		,"Do you want to delete cards ?"},
/*16*/{"�rak t�rl�se"				 	,"Delet prices"},
/*17*/{"T�r�lni akarod az �rakat ?" 		,"Do you want to delete prices ?"},
/*18*/{"C�gek t�rl�se"				 	,"Delete companies"},
/*19*/{"T�r�lni akarod a c�geket ?" 		,"Do you want to delete companies ?"}
};
//---------------------------------------------------------------------------

