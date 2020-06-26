;======================================
; Benzin vezérlõ LCD stringek
;--------------------------------------
;Módosítva: 2007.01.17.
.message "Nyelv= Román"
;--------------------------------------Global
;Szoveg stuct:		.db x,y,width,table,str
;TextVISSZA:		.db   1, 52, 8,1,"Vissza",0,
TextVISSZA:		.db   1, 52, 8,1,"Inapoi",0,0
;TextVISSZARENDBEN:	.db   1, 52, 8,1,"Vissza                 Rendben",0,0
TextVISSZARENDBEN:	.db   1, 52, 8,1,"Inapoi               in ordine",0,0
;--------------------------------------Fõmenü:Alap
;Szoveg stuct:	.db x,y,width,table,str
;ScrA1txt1:	.db 54, 28, 8,1,"Válasszon kutat",0
ScrA1txt1:	.db 54, 28, 8,1,"Alegeti sursa",0
ScrA1txt2:	.db 50, 42, 8,1,"RATIO HOMINI KFT",0,0
ScrA1txt3:	.db 41, 54, 8,1,"Tel.: 36 1 3063039",0,0
;--------------------------------------Státusz kijelzés***
;Szoveg stuct:.db x,y,width,table,str
;ScrA2txtFfent:	.db   1,  1, 8,1,"Fej fent",0,0
ScrA2txtFfent:	.db   1,  1, 8,1,"",0,0
;ScrA2txtFlent:	.db   1,  1, 8,1,"Fej lent",0,0
ScrA2txtFlent:	.db   1,  1, 8,1,"",0,0
;ScrA2txtTankol:.db   1,  1, 8,1,"Tankolás",0,0
ScrA2txtTankol:	.db   1,  1, 8,1,"",0,0
;ScrA2txtVfent:	.db   1,  1, 8,1,"Vége: fej",0
ScrA2txtVfent:	.db   1,  1, 8,1,"",0,0
;ScrA2txtVido:	.db   1,  1, 8,1,"Vége: idõhatár",0,0
ScrA2txtVido:	.db   1,  1, 8,1,"",0,0
;ScrA2txtVlimit:.db   1,  1, 8,1,"Vége: limit",0
ScrA2txtVlimit:	.db   1,  1, 8,1,"",0,0
;ScrA2txtLopas:	.db   1,  1, 8,1,"Lopás!!!",0,0
ScrA2txtLopas:	.db   1,  1, 8,1,"",0,0
;ScrA2txtKisfesz:db   1,  1, 8,1,"Feszültség hiba!",0,0
ScrA2txtKisfesz:.db   1,  1, 8,1,"",0,0
;ScrA2txtError:	.db   1,  1, 8,1,"Rossz státusz!",0,0
ScrA2txtError:	.db   1,  1, 8,1,"",0,0
;--------------------------------------Kártya bevitel
;Szöveg stuct:.db x,y,width,table,str
;ScrA3txtKUT:	.db 10,  1, 8,1,".Kútfõ:',0
ScrA3txtKUT:	.db 10,  1, 8,1,".Sursa",0,0
;ScrA3txtHIBA:	.db 80,  1, 8,1,"Kártya HIBA",0
ScrA3txtHIBA:	.db 80,  1, 8,1,"Eror la card",0,0
ScrA3txtHINO:	.db 80,  1, 8,1,"           ",0
;ScrA3txtCARD2:	.db 80, 13, 8,1,"Kérem a kártyákat",0
ScrA3txtCARD2:	.db 80, 13, 8,1,"Introduce cardul",0,0
;ScrA3txtCARD1:	.db 80, 13, 8,1,"Kérem a kártyát",0
ScrA3txtCARD1:	.db 80, 13, 8,1,"Introduce cardul",0,0
;ScrA3txtPIN0:	.db 80, 13, 8,1,"PIN kód: ____    ",0
ScrA3txtPIN0:	.db 80, 13, 8,1,"COD PIN: ____    ",0
;ScrA3txtPIN1:	.db 80, 13, 8,1,"PIN kód: *___    ",0
ScrA3txtPIN1:	.db 80, 13, 8,1,"COD PIN: *___    ",0
;ScrA3txtPIN2:	.db 80, 13, 8,1,"PIN kód: **__    ",0
ScrA3txtPIN2:	.db 80, 13, 8,1,"COD PIN: **__    ",0
;ScrA3txtPIN3:	.db 80, 13, 8,1,"PIN kód: ***_    ",0
ScrA3txtPIN3:	.db 80, 13, 8,1,"COD PIN: ***_    ",0
;ScrA3txtPIN4:	.db 80, 13, 8,1,"PIN kód: ****    ",0
ScrA3txtPIN4:	.db 80, 13, 8,1,"COD PIN: ****    ",0
;ScrA3txtNEV:	.db  1, 28, 8,1,"Név:",0,0
ScrA3txtNEV:	.db  1, 28, 8,1,"Nume:",0
;ScrA3txtAUTO:	.db  1, 40, 8,1,"Jármû:",0,0
ScrA3txtAUTO:	.db  1, 40, 8,1,"Vehicul:",0,0
;--------------------------------------Km óra bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA4txtFoCim:	.db  0,  0, 8,1,"Km óra állása:",0,0
ScrA4txtFoCim:	.db  0,  0, 8,1,"Pozitia Km:",0			;POZITIA KILOMETRAJULUI
;ScrA4txtHiba:	.db  1, 52, 8,1,"Az elõzõnél nem lehet kisebb!",0
ScrA4txtHiba:	.db  1, 52, 8,1,"Nu poate fii mai mic de!",0,0	;NUPOATEFII MAIMIC DE
;--------------------------------------Menetlevél bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA5txt1:	.db  0,  0, 8,1,"Menetlevél száma:",0
ScrA5txt1:	.db  0,  0, 8,1,"Numr foii de parc.:",0		;NUMARUL FOII DE PARCURS
;--------------------------------------Tankolhat
;Szoveg stuct:	.db x,y,width,table,str
;ScrA6txt0:	.db  0,  6, 8,1,"    Mai nap         .tankolás",0
ScrA6txt0:	.db  0,  6, 8,1," Ziua de azi        .altimentare",0,0
;ScrA6txt1:	.db  0, 20, 8,1,"    Tankolhat       litert",0,0
ScrA6txt1:	.db  0, 20, 8,1,"Se poate alimenta   litrii",0,0;SE POATE ALIMENTA... LITRII
;ScrA6txt2:	.db 30, 34, 8,1,"      még       -szor.",0,0
ScrA6txt2:	.db 30, 34, 8,1,"     inca       -de ori.",0,0
;--------------------------------------Üzemóra bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA7txt1:	.db  0,  0, 8,1,"Üzemóra állása:",0
ScrA7txt1:	.db  0,  0, 8,1,"Pozitia ceasului de expoatare:",0,0
;--------------------------------------Mester kártya bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA8txt1:	.db  0,  0, 8,1,"Jármû kártya kódja:",0
ScrA8txt1:	.db  0,  0, 8,1,"Codul cardului vehiculului:",0
;ScrA8txtKell:	.db  1, 52, 8,1,"Vissza                Nem kell",0,0
ScrA8txtKell:	.db  1, 52, 8,1,"Inapoi              Nu trebuie",0,0
;ScrA8txtTorol:	.db  1, 52, 8,1,"Töröl",0,0
ScrA8txtTorol:	.db  1, 52, 8,1,"Clear",0;***
;ScrA8txtRendben:.db  1, 52, 8,1,"Töröl                  Rendben",0,0
ScrA8txtRendben:.db  1, 52, 8,1,"Clear                 In ordine",0;***
;--------------------------------------Nyomtatás
;Szoveg stuct:	.db x,y,width,table,str
;ScrA9txtFoCim:	.db  0,  0, 8,1,"Nyomtatás:",0,0
ScrA9txtFoCim:	.db  0,  0, 8,1,"Imprimare:",0,0
PrnTxtInit:	.db 0x1b,0x52,0x02,0

;PrnTxtKezd:	.db "Mérés kezdete: ____.__.__ __:__:__",0x0a,0
PrnTxtKezd:	.db "Incep. alim. : ____.__.__ __:__:__",0x0a,0		;INCEPUTUL ALIMENTARII
;PrnTxtVege:	.db "Mérés vége   : ____.__.__ __:__:__",0x0a,0
PrnTxtVege:	.db "Sfars. alim. : ____.__.__ __:__:__",0x0a,0		;SFARSITUL ALMIMENTARII
;PrnTxtEmber:	.db "Személy           : _____________",0x0a,0,0
PrnTxtEmber:	.db "Persoana          : _____________",0x0a,0,0
;PrnTxtRendsz:	.db "Jármû rendszáma   : _____________",0x0a,0,0
PrnTxtRendsz:	.db "Numar inmatriculare:_____________",0x0a,0,0	;NUMARUL DE INMATEICULARE AL VEHICULULUI
;PrnTxtKm:	.db "Kilométer          :   ________ km",0x0a,0
PrnTxtKm:	.db "Kilometraj         :   ________ km",0x0a,0
;PrnTxtUzemora:	.db "Üzemóra            :   ________ ó",0x0a,0,0
PrnTxtUzemora:	.db "Ceasul de exploatare:  ________ ó",0x0a,0,0
;PrnTxtMenlev:	.db "Menetlevél         :   ________ ",0x0a,0
PrnTxtMenlev:	.db "Foaia de parcurs   :   ________ ",0x0a,0
;PrnTxtSorSzam:	.db "Kimérés sorszáma Nr:     _____/_",0x0a,0
PrnTxtSorSzam:	.db "Numarul alimentarii:     _____/_",0x0a,0
;PrnTxtOszLit:	.db "Számláló állása   V:__________,__l",0x0a,0
PrnTxtOszLit:	.db "Poz.numaratorului V:__________,__l",0x0a,0		;POZITIA NUMARATORULUI
;PrnTxtOszKomp:	.db "Összegezett mérésVo:__________,__l",0x0a,0
PrnTxtOszKomp:	.db "Alim totalizata  Vo:__________,__l",0x0a,0		;ALUMENTRE TOTALIZATA
PrnTxtVonal:	.db "---------------------:------------",0x0a,0
;PrnTxtLiter:	.db "Kimért mennyiség   Vt: ______,__ l",0x0a,0
PrnTxtLiter:	.db "Cantit. aliment.   Vt: ______,__ l",0x0a,0		;CANTITATEA ALIMENTATA
;PrnTxtHom:	.db "Termékhõmérséklet   t:    ___,_ °C",0x0a,0
PrnTxtHom:	.db "Temperatura produsului t: ___,_ °C",0x0a,0
;PrnTxtMegnev:	.db "Termékmegnevezés     :     Gázolaj",0x0a,0
PrnTxtMegnev:	.db "Denumirea produsului :    Motorina",0x0a,0
;PrnTxtBazisHo:	.db "Bázishõmérséklet   to:     15,0 °C",0x0a,0
PrnTxtBazisHo:	.db "Temp. de baza      to:     15,0 °C",0x0a,0
;PrnTxtLitKomp:	.db "Mennyiség to-án    Vo: ______,__ l",0x0a,0
PrnTxtLitKomp:	.db "Cantitate (to)     Vo: ______,__ l",0x0a,0

PrnTxtClose:	.db 0x0a,0x0a,0x0a,0x0a,0x0a,0x1b,0x6d,0;half cut
;--------------------------------------Hiba:Kártya
;Szoveg stuct:.db x,y,width,table,str
;ScrH1txt1:	.db 44,  6, 8,1,"Kártya HIBA",0
ScrH1txt1:	.db 44,  6, 8,1,"Eroare la card",0,0		;EROARE LA CARTELA
;--------------------------------------Hiba:Kimerítve
;Szoveg stuct:.db x,y,width,table,str
;ScrH2txt0:	.db 40,  0,10,1,"Napi megengedett",0,0
ScrH2txt0:	.db 40,  0,10,1,"Limita pe zi",0,0
;ScrH2txt1:	.db 40, 16,10,1,"tankolások száma",0,0
ScrH2txt1:	.db 40, 16,10,1,"numarul alimantarii",0		;NUMARUL ALIM.
;ScrH2txt2:	.db 40, 32,10,1,"   kimerítve.",0
ScrH2txt2:	.db 40, 32,10,1,"   epuizat.",0
;--------------------------------------Szerviz:Belépés
;Szoveg stuct:	.db x,y,width,table,str
;ScrS1txtCIM:	.db  0,  0, 8,1,"Kérem a szerviz kártyát:",0,0
ScrS1txtCIM:	.db  0,  0, 8,1,"Rog cartela de servis:",0,0
;--------------------------------------Szerviz
;Szoveg stuct:	.db x,y,width,table,str
;ScrS2txt1:	.db   0,  0, 8,1,"Szerviz menü:",0
ScrS2txt1:	.db   0,  0, 8,1,"Meniul servis:",0,0
;ScrS2txt2:	.db   0, 14, 8,1,"1-Kútfõk       2-Kártya inf.",0,0
ScrS2txt2:	.db   0, 14, 8,1,"1-Sursele      2-Informatii card",0,0
;ScrS2txt3:	.db   0, 26, 8,1,"3-Beállítások  4-Változók.",0,0
ScrS2txt3:	.db   0, 26, 8,1,"3-Setari       4-Variabile",0,0
;ScrS2txt4:	.db   0, 38, 8,1,"5-Rendszer",0
ScrS2txt4:	.db   0, 38, 8,1,"5-Sistem",0,0
;--------------------------------------Szervíz:Kútfõk
;Szoveg stuct:	.db x,y,width,table,str
;ScrS3txtKUTFOK:.db   0,  0, 8,1,"Kútfõk:",0
ScrS3txtKUTFOK:	.db   0,  0, 8,1,"Surse:",0,0
;ScrS3txtKUTAKBE:.db   0, 36, 8,1,"Gomb1-8 kutak be/ki",0
ScrS3txtKUTAKBE:.db   0, 36, 8,1,"Buton 1-8 surse pornit/oprit",0,0
;--------------------------------------Szerviz:Kártyák
;Szoveg stuct:	.db x,y,width,table,str
;ScrS4txt1:	.db   0,  0, 8,1,"Kártya információk:",0
ScrS4txt1:	.db   0,  0, 8,1,"Informatii card:",0,0		;INFORMATII DESPRE CARTELA
;ScrS4txt2:	.db   0, 20, 8,1,"1 - Kártyák száma",0
ScrS4txt2:	.db   0, 20, 8,1,"1 - Cant.cardurilor",0	;NUMARUL CARTELELOR
;ScrS4txtEGY:	.db   0, 36, 8,1,"Egykártyás rendszer",0
ScrS4txtEGY:	.db   0, 36, 8,1,"sistem cu un card",0		;SISTEM CU O CARTELA
;ScrS4txtKET:	.db   0, 36, 8,1,"Kétkártyás rendszer",0
ScrS4txtKET:	.db   0, 36, 8,1,"sistem cu doua carduri",0,0	;SISTEM CU DOUA CARTELE
;--------------------------------------Szerviz:Beállítások
;Szoveg stuct:	.db x,y,width,table,str
;ScrS5_txt1:	.db  0,  0, 8,1,"Beállítások:",0,0
ScrS5_txt1:	.db  0,  0, 8,1,"Setari:",0
;ScrS5_txt2:	.db  0, 12, 8,1,"1-Kijelzések   2-Kontraszt",0,0
ScrS5_txt2:	.db  0, 12, 8,1,"1-Indicari     2-Contrast",0
;ScrS5_txt3:	.db  0, 24, 8,1,"3-Idõk",0,0
ScrS5_txt3:	.db  0, 24, 8,1,"3-Timpuri",0
;ScrS5_txt4:	.db  0, 36, 8,1,"4-Testre szabás",0
ScrS5_txt4:	.db  0, 36, 8,1,"4-Stare configurare personala",0
;--------------------------------------Szerviz:Beállítás:Literkijelzés
;Szoveg stuct:	.db x,y,width,table,str
;ScrS6txtCIM:	.db   0,  0, 8,1,"Kijelzések:",0
ScrS6txtCIM:	.db   0,  0, 8,1,"Indicari:",0
;ScrS6txtBE:	.db   0, 20, 8,1,"1 - Liter kijelzés: BE",0,0
ScrS6txtBE:	.db   0, 20, 8,1,"1 - Ind. cant. de comb.: PORNIT",0	;INDICAREA CANTITATII DE COMBUSTIBIL: PORNIT
;ScrS6txtKI:	.db   0, 20, 8,1,"1 - Liter kijelzés: KI",0,0
ScrS6txtKI:	.db   0, 20, 8,1,"1 - Ind. cant. de comb.: OPRIT",0,0	;INDICAREA CANTITATII DE COMBUSTIBIL: OPRIT
;--------------------------------------Szerviz:Beállítás:Kontraszt
;Szoveg stuct:	.db x,y,width,table,str
;ScrS7_txt1:	.db   0,  0, 8,1,"Kontraszt:",0,0
ScrS7_txt1:	.db   0,  0, 8,1,"Contrast:",0
;ScrS7_txt2:	.db   0, 16, 8,1,"1 - csökkent       3 - növel",0,0
ScrS7_txt2:	.db   0, 16, 8,1,"1 - scazut         3 - marit",0,0
;ScrS7_txt3:	.db   0, 28, 8,1,"Hõmérséklet:",0,0
ScrS7_txt3:	.db   0, 28, 8,1,"Temperatura:",0,0
;ScrS7_txt4:	.db   0, 40, 8,1,"7 - k csökkent     9 - k növel",0,0
ScrS7_txt4:	.db   0, 40, 8,1,"7 - k scazut       9 - k marit",0,0
;--------------------------------------Szerviz:Testreszabás
;Szoveg stuct:	.db x,y,width,table,str
;				 "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";max. ekkora lehet a sor
;ScrS8txtCIM:	.db   0,  0, 8,1,"Testre szabás:",0,0
ScrS8txtCIM:	.db   0,  0, 8,1,"Stare configurare personala:",0,0
;ScrS8txtKMBENOV:db   0, 16, 8,1,"1-Km bekérés: BE-növekvõ",0,0
ScrS8txtKMBENOV:.db   0, 16, 8,1,"1-Pozitia km: PORNIT,CRESCATOR",0
;ScrS8txtKMBE:	.db   0, 16, 8,1,"1-Km bekérés: BE",0,0
ScrS8txtKMBE:	.db   0, 16, 8,1,"1-Pozitia km: PORNIT",0,0
;ScrS8txtKMKI:	.db   0, 16, 8,1,"1-Km bekérés: KI",0,0
ScrS8txtKMKI:	.db   0, 16, 8,1,"1-Pozitia km: OPRIT",0
;ScrS8txtMENLBE:.db   0, 28, 8,1,"2-Menetlevél bekérés: BE",0,0
ScrS8txtMENLBE:	.db   0, 28, 8,1,"2-Prez. foii de parcurs:PORNIT",0,0
;ScrS8txtMENLKI:.db   0, 28, 8,1,"2-Menetlevél bekérés: KI",0,0
ScrS8txtMENLKI:	.db   0, 28, 8,1,"2-Prez. foii de parcurs:OPRIT",0
;ScrS8txtUZEMBE:.db   0, 40, 8,1,"3-Üzemóra bekérés: BE",0
ScrS8txtUZEMBE:	.db   0, 40, 8,1,"3-Prez.timpului de expl:PORNIT",0,0
;ScrS8txtUZEMBE:	.db   0, 40, 8,1,"3-Prezenteria timpului de exploatare: PORNIT",0,0
;ScrS8txtUZEMKI:.db   0, 40, 8,1,"3-Üzemóra bekérés: KI",0
ScrS8txtUZEMKI:	.db   0, 40, 8,1,"3-Prez.timpului de expl:OPRIT",0
;ScrS8txtUZEMKI:	.db   0, 40, 8,1,"3-Prezenteria timpului de exploatare: OPRIT",0
;--------------------------------------Szerviz:Változók
;Szoveg stuct:	.db x,y,width,table,str
;ScrS9_txt1:	.db   0,  0, 8,1,"Változók kijelzése:",0
ScrS9_txt1:	.db   0,  0, 8,1,"Indicarea variabilelor:",0
;ScrS9_txt2:	.db   0, 20, 8,1,"Fejlesztés alatt",0,0
ScrS9_txt2:	.db   0, 20, 8,1,"sub dezvoltare",0,0
;--------------------------------------Szerviz:Rendszer
;Szoveg stuct:	.db x,y,width,table,str
;ScrS10_txt1:	.db   0,  0, 8,1,"Rendszer:",0
ScrS10_txt1:	.db   0,  0, 8,1,"Sistem:",0
;ScrS10_txt2:	.db   0, 20, 8,1,"Fejlesztés alatt",0,0
ScrS10_txt2:	.db   0, 20, 8,1,"sub dezvoltare",0,0
;--------------------------------------Szerviz:OraBe
;Szoveg stuct:	.db x,y,width,table,str
;======================================END
