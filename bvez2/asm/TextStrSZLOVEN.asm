;======================================
; Benzin vezérlõ LCD stringek (SZLOVÉN)
;--------------------------------------
.message "Nyelv= Szlovén"
;--------------------------------------Global
;Szoveg stuct:		.db x,y,width,table,	str
;TextVISSZA:		.db   1, 52, 8,1,	"Vissza",0,0
TextVISSZA:		.db   1, 52, 8,1,	"Nazaj",0
;TextVISSZARENDBEN:	.db   1, 52, 8,1,	"Vissza                 Rendben",0,0
TextVISSZARENDBEN:	.db   1, 52, 8,1,	"Nazaj                   V redu",0,0
;--------------------------------------Fõmenü:Alap
;Szoveg stuct:	.db x,y,width,table,str
;ScrA1txt1:	.db 54, 28, 8,1,"Válasszon kutat",0
ScrA1txt1:	.db 54, 28, 8,1,"Izberi èrpalko",0
;ScrA1txt2:	.db 50, 42, 8,1,"RATIO HOMINI KFT",0,0
ScrA1txt2:	.db 50, 42, 8,1,"RATIO HOMINI d.o.o.",0
;ScrA1txt3:	.db 41, 54, 8,1,"Tel.: 36 1 3063039",0,0
ScrA1txt3:	.db 41, 54, 8,1,"  Tel.: 041 653 951 ",0,0
;--------------------------------------Státusz kijelzés
;Szoveg stuct:.db x,y,width,table,str
;crA2txtKikapcs:.db   1,  1, 8,1,"Kikapcsolva",0
ScrA2txtKikapcs:.db   1,  1, 8,1,"Izklopljeno",0
;crA2txtFejFent:.db   1,  1, 8,1,"Fej fent",0,0
ScrA2txtFejFent:.db   1,  1, 8,1,"Pi",css,"tola gor",0
;ScrA2txtSum1:	.db   1,  1, 8,1,"Fej fent-Sum1",0
ScrA2txtSum1:	.db   1,  1, 8,1,"Pi",css,"tola gor-Sum1",0,0
;ScrA2txtSum2:	.db   1,  1, 8,1,"Fej fent-Sum2",0
ScrA2txtSum2:	.db   1,  1, 8,1,"Pi",css,"tola gor-Sum2",0,0
;crA2txtFejLent:.db   1,  1, 8,1,"Fej lent",0,0
ScrA2txtFejLent:.db   1,  1, 8,1,"Pi",css,"tola dol",0
;ScrA2txtTankKi:.db   1,  1, 8,1,"Tankolás-ki",0
ScrA2txtTankKi:	.db   1,  1, 8,1,"Toèenje DA",0,0
;ScrA2txtTankBe:.db   1,  1, 8,1,"Tankolás-be",0
ScrA2txtTankBe:	.db   1,  1, 8,1,"Toèenje NE",0,0
;ScrA2txtVlimit:.db   1,  1, 8,1,"Mentés: limit",0
ScrA2txtVlimit:	.db   1,  1, 8,1,"Shrani: limit",0
;ScrA2txtVfej:	.db   1,  1, 8,1,"Mentés: fej",0
ScrA2txtVfej:	.db   1,  1, 8,1,"Shrani: pi",css,"tola",0
;ScrA2txtVido:	.db   1,  1, 8,1,"Mentés: idõhatár",0,0
ScrA2txtVido:	.db   1,  1, 8,1,"Shrani: èas.obd.",0,0
;ScrA2txtVlopas:.db   1,  1, 8,1,"Mentés: Lopás!!!",0,0
ScrA2txtVlopas:	.db   1,  1, 8,1,"Shrani: Kraja!!!",0,0
;ScrA2txtVfesz:	.db   1,  1, 8,1,"Mentés: Feszültség hiba!",0,0
ScrA2txtVfesz:	.db   1,  1, 8,1,"Shrani: Napaka napetosti!",0
;ScrA2txtSlimit:.db   1,  1, 8,1,"Vége: limit",0
ScrA2txtSlimit:	.db   1,  1, 8,1,"Konec: limit",0,0
;ScrA2txtSfej:	.db   1,  1, 8,1,"Vége: fej",0
ScrA2txtSfej:	.db   1,  1, 8,1,"Konec: pi",css,"tola",0,0
;ScrA2txtSido:	.db   1,  1, 8,1,"Vége: idõhatár",0,0
ScrA2txtSido:	.db   1,  1, 8,1,"Konec: èas.obd.",0
;ScrA2txtSlopas:.db   1,  1, 8,1,"Vége: Lopás!!!",0,0
ScrA2txtSlopas:	.db   1,  1, 8,1,"Konec: Kraja!!!",0
;ScrA2txtSfesz:	.db   1,  1, 8,1,"Vége: Feszültség hiba!",0,0
ScrA2txtSfesz:	.db   1,  1, 8,1,"Konec: Napaka napetosti!",0,0
;ScrA2txtVar:	.db   1,  1, 8,1,"Újra vár",0,0
ScrA2txtVar:	.db   1,  1, 8,1,"èaka naslednjega",0,0			;***È
;ScrA2txtError:	.db   1,  1, 8,1,"Rossz státusz!",0,0
ScrA2txtError:	.db   1,  1, 8,1,"Napaèen status!",0
;--------------------------------------Kártya bevitel
;Szöveg stuct:.db x,y,width,table,str
;ScrA3txtKUT:	.db 10,  1, 8,1,".Kútfõ:",0
ScrA3txtKUT:	.db 10,  1, 8,1,".Krmilnik:",0,0
;ScrA3txtHIBA:	.db 80,  1, 8,1,"Kártya HIBA",0
ScrA3txtHIBA:	.db 80,  1, 8,1,"NAPAKA kartice",0,0
;ScrA3txtHINO:	.db 80,  1, 8,1,"           ",0
ScrA3txtHINO:	.db 80,  1, 8,1,"               ",0
;ScrA3txtCARD2:	.db 80, 13, 8,1,"Kérem a kártyákat",0
ScrA3txtCARD2:	.db 80, 13, 8,1,"Prosim kartice ",0
;ScrA3txtCARD1:	.db 80, 13, 8,1,"Kérem a kártyát",0
ScrA3txtCARD1:	.db 80, 13, 8,1,"Prosim kartico ",0
;ScrA3txtPIN0:	.db 80, 13, 8,1,"PIN kód: ____    ",0
ScrA3txtPIN0:	.db 80, 13, 8,1,"PIN koda:____    ",0
;ScrA3txtPIN1:	.db 80, 13, 8,1,"PIN kód: *___    ",0
ScrA3txtPIN1:	.db 80, 13, 8,1,"PIN koda:*___    ",0
;ScrA3txtPIN2:	.db 80, 13, 8,1,"PIN kód: **__    ",0
ScrA3txtPIN2:	.db 80, 13, 8,1,"PIN koda:**__    ",0
;ScrA3txtPIN3:	.db 80, 13, 8,1,"PIN kód: ***_    ",0
ScrA3txtPIN3:	.db 80, 13, 8,1,"PIN koda:***_    ",0
;ScrA3txtPIN4:	.db 80, 13, 8,1,"PIN kód: ****    ",0
ScrA3txtPIN4:	.db 80, 13, 8,1,"PIN koda:****    ",0
;ScrA3txtNEV:	.db  1, 28, 8,1,"Név:",0,0
ScrA3txtNEV:	.db  1, 28, 8,1,"Ime:",0,0
;ScrA3txtAUTO:	.db  1, 40, 8,1,"Jármû:",0,0
ScrA3txtAUTO:	.db  1, 40, 8,1,"Vozilo:",0
;--------------------------------------Km óra bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA4txtFoCim:	.db  0,  0, 8,1,"Km óra állása:",0,0
ScrA4txtFoCim:	.db  0,  0, 8,1,"Stanje ",css,"tevca Km:",0	;'"css,"
;ScrA4txtHiba:	.db  1, 52, 8,1,"Az elõzõnél nem lehet kisebb! ",0,0
ScrA4txtHiba:	.db  1, 52, 8,1,"Ne more biti manj od prej! ",0
;--------------------------------------Menetlevél bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA5txt1:	.db  0,  0, 8,1,"Menetlevél száma:",0
ScrA5txt1:	.db  0,  0, 8,1,css,"tevilka Naloga: ",0			;Š***
;--------------------------------------Tankolhat
;Szoveg stuct:	.db x,y,width,table,str
;ScrA6txt0:	.db 30,  6, 8,1,"Mai nap         .tankolás",0
ScrA6txt0:	.db 30,  6, 8,1,"Dana",css,"nje        .toèenje ",0
;ScrA6txt1:	.db 30, 20, 8,1,"Tankolhat       litert",0,0
ScrA6txt1:	.db 30, 20, 8,1,"Lahko toèi      litrov",0,0
;ScrA6txt2:	.db 30, 34, 8,1,"      még       -szer.",0,0
ScrA6txt2:	.db 30, 34, 8,1,"      ",css,"e        -krat.",0,0
;--------------------------------------Üzemóra bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA7txt1:	.db  0,  0, 8,1,"Üzemóra állása:",0
ScrA7txt1:	.db  0,  0, 8,1,"Stanje ",css,"tevca del.ur:",0
;--------------------------------------Mester kártya bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA8txt1:	.db  0,  0, 8,1,"Jármû kártya kódja:",0
ScrA8txt1:	.db  0,  0, 8,1,"Koda kartice vozila:",0,0
;ScrA8txtKell:	.db  1, 52, 8,1,"Vissza                Nem kell",0,0
ScrA8txtKell:	.db  1, 52, 8,1,"Nazaj                       Ne",0,0
;ScrA8txtTorol:	.db  1, 52, 8,1,"Töröl                         ",0,0
ScrA8txtTorol:	.db  1, 52, 8,1,"Bri",css,"i                         ",0,0
;ScrA8txtRendben:.db  1, 52, 8,1,"Töröl                  Rendben",0,0
ScrA8txtRendben: .db  1, 52, 8,1,"Bri",css,"i	                  V redu",0,0
;--------------------------------------Nyomtatás
;Szoveg stuct:	.db x,y,width,table,str
;ScrA9txtFoCim:	.db  0,  0, 8,1,"Nyomtatás:",0,0
ScrA9txtFoCim:	.db  0,  0, 8,1,"Tiskanje: ",0,0
PrnTxtInit:	.db 0x1b,0x52,0x02,0

;PrnTxtKezd:	.db "Mérés kezdete: ____.__.__ __:__:__",0x0a,0
PrnTxtKezd:	.db "Zaèetek meritve: ____.__.__ __:__:__",0x0a,0	//***
;PrnTxtVege:	.db "Mérés vége   : ____.__.__ __:__:__",0x0a,0
PrnTxtVege:	.db "Konec meritve: ____.__.__ __:__:__",0x0a,0
;PrnTxtEmber:	.db "Személy           : _____________",0x0a,0,0
PrnTxtEmber:	.db "Oseba             : _____________",0x0a,0,0
;PrnTxtRendsz:	.db "Jármû rendszáma   : _____________",0x0a,0,0
PrnTxtRendsz:	.db "Reg.",css,"t.vozila     : _____________",0x0a,0,0
;PrnTxtKm:	.db "Kilométer          :   ________ km",0x0a,0
PrnTxtKm:	.db "Kilométer          :   ________ km",0x0a,0
;PrnTxtUzemora:	.db "Üzemóra            :   ________ ó",0x0a,0,0
PrnTxtUzemora:	.db "Stanje ",css,"tevca del.ur:  ________ ó",0x0a,0,0
;PrnTxtMenlev:	.db "Menetlevél         :   ________ ",0x0a,0
PrnTxtMenlev:	.db "Potni nalog        :   ________ ",0x0a,0
;PrnTxtSorSzam:	.db "Kimérés sorszáma Nr:     _____/_",0x0a,0
PrnTxtSorSzam:	.db "Zap.",css,"t. toèenja  Nr:     _____/_",0x0a,0
;PrnTxtOszLit:	.db "Számláló állása   V:__________,__l",0x0a,0
PrnTxtOszLit:	.db "Stanje ",css,"tevca     V:__________,__l",0x0a,0
;PrnTxtOszKomp:	.db "Összegezett mérésVo:__________,__l",0x0a,0
PrnTxtOszKomp:	.db "Meritev skupaj   Vo:__________,__l",0x0a,0
PrnTxtVonal:	.db "---------------------:------------",0x0a,0
;PrnTxtLiter:	.db "Kimért mennyiség   Vt: ______,__ l",0x0a,0
PrnTxtLiter:	.db "Iztoèena kolièina  Vt: ______,__ l",0x0a,0
;PrnTxtHom:	.db "Termékhõmérséklet   t:    ___,_ °C",0x0a,0
PrnTxtHom:	.db "Temperatura goriva  t:    ___,_ °C",0x0a,0
;PrnTxtMegnev:	.db "Termékmegnevezés     :     Gázolaj",0x0a,0
PrnTxtMegnev:	.db "Naziv goriva         :Plinsko olje",0x0a,0
;PrnTxtBazisHo:	.db "Bázishõmérséklet   to:     15,0 °C",0x0a,0
PrnTxtBazisHo:	.db "Temperatura pri    to:     15,0 °C",0x0a,0
;PrnTxtLitKomp:	.db "Mennyiség to-án    Vo: ______,__ l",0x0a,0
PrnTxtLitKomp:	.db "Kolièina pri to    Vo: ______,__ l",0x0a,0

PrnTxtClose:	.db 0x0a,0x0a,0x0a,0x0a,0x0a,0x1b,0x6d,0;half cut
;--------------------------------------Hiba:Kártya
;Szoveg stuct:.db x,y,width,table,str
;ScrH1txt1:	.db 44,  6, 8,1,"Kártya HIBA",0
ScrH1txt1:	.db 44,  6, 8,1,"NAPAKA kartice",0,0
;--------------------------------------Hiba:Kimerítve
;Szoveg stuct:.db x,y,width,table,str
;ScrH2txt0:	.db 40,  0,10,1,"Napi megengedett",0,0
ScrH2txt0:	.db 40,  0,10,1,"Dnevno dovoljeno",0,0
;ScrH2txt1:	.db 40, 16,10,1,"tankolások száma",0,0
ScrH2txt1:	.db 40, 16,10,1,css,"tevilo toèenj",0,0			;Š***
;ScrH2txt2:	.db 40, 32,10,1,"   kimerítve.",0
ScrH2txt2:	.db 40, 32,10,1,"   Izkori",css,"èeno.",0
;--------------------------------------Szerviz:Belépés
;Szoveg stuct:	.db x,y,width,table,str
;ScrS1txtCIM:	.db  0,  0, 8,1,"Kérem a szerviz kártyát:",0,0
ScrS1txtCIM:	.db  0,  0, 8,1,"Prosim servisno karto:",0,0
;--------------------------------------Szerviz
;Szoveg stuct:	.db x,y,width,table,str
;ScrS2txt1:	.db   0,  0, 8,1,"Szerviz menü:",0
ScrS2txt1:	.db   0,  0, 8,1,"Servisni meni:",0,0
;ScrS2txt2:	.db   0, 14, 8,1,"1-Kútfõk       2-Kártya inf.",0,0
ScrS2txt2:	.db   0, 14, 8,1,"1-Krmilniki    2-Info.kartice.",0,0
;ScrS2txt3:	.db   0, 26, 8,1,"3-Beállítások  4-Változók.",0,0
ScrS2txt3:	.db   0, 26, 8,1,"3-Nastvitve    4-Spremembe.",0
;ScrS2txt4:	.db   0, 38, 8,1,"5-Rendszer ",0
ScrS2txt4:	.db   0, 38, 8,1,"5-Sistem   ",0
;--------------------------------------Szervíz:Kútfõk
;Szoveg stuct:	.db x,y,width,table,str
;ScrS3txtKUTFOK:.db   0,  0, 8,1,"Kútfõk:",0
ScrS3txtKUTFOK:	.db   0,  0, 8,1,"Krmilniki:",0,0
;ScrS3txtKUTAKBE:.db   0, 36, 8,1,"Gomb1-8 kutak be/ki",0
ScrS3txtKUTAKBE: .db   0, 36, 8,1,"Tipka1-8 èrpalke toèenje/konec",0,0
;--------------------------------------Szerviz:Kártyák
;Szoveg stuct:	.db x,y,width,table,str
;ScrS4txt1:	.db   0,  0, 8,1,"Kártya információk:",0
ScrS4txt1:	.db   0,  0, 8,1,"Informacije o karticah:",0
;ScrS4txt2:	.db   0, 20, 8,1,"1 - Kártyák száma",0
ScrS4txt2:	.db   0, 20, 8,1,"1 - ",css,"tevilka kartice",0,0		;Š***
;ScrS4txtEGY:	.db   0, 36, 8,1,"Egykártyás rendszer",0
ScrS4txtEGY:	.db   0, 36, 8,1,"Enokartièni sistem ",0
;ScrS4txtKET:	.db   0, 36, 8,1,"Kétkártyás rendszer",0
ScrS4txtKET:	.db   0, 36, 8,1,"Dvokartièni sistem ",0
;--------------------------------------Szerviz:Beállítások
;Szoveg stuct:	.db x,y,width,table,str
;ScrS5_txt1:	.db  0,  0, 8,1,"Beállítások:",0,0
ScrS5_txt1:	.db  0,  0, 8,1,"Nastavitve: ",0,0
;ScrS5_txt2:	.db  0, 12, 8,1,"1-Kijelzések   2-Kontraszt",0,0
ScrS5_txt2:	.db  0, 12, 8,1,"1-Display       2-Kontrast",0,0
;ScrS5_txt3:	.db  0, 24, 8,1,"3-Idõ",0
ScrS5_txt3:	.db  0, 24, 8,1,"3-èas",0				;È***
;ScrS5_txt4:	.db  0, 36, 8,1,"4-Testre szabás",0
ScrS5_txt4:	.db  0, 36, 8,1,"4-Po meri",0
;--------------------------------------Szerviz:Beállítás:Literkijelzés
;Szoveg stuct:	.db x,y,width,table,str
;ScrS6txtCIM:	.db   0,  0, 8,1,"Kijelzések:",0
ScrS6txtCIM:	.db   0,  0, 8,1,"Display:",0,0
;ScrS6txtBE:	.db   0, 20, 8,1,"1 - Liter kijelzés: BE",0,0
ScrS6txtBE:	.db   0, 20, 8,1,"1 - Liter pokaži: DA",0,0		;ž***
;ScrS6txtKI:	.db   0, 20, 8,1,"1 - Liter kijelzés: KI",0,0
ScrS6txtKI:	.db   0, 20, 8,1,"1 - Liter pokaži: NE",0,0		;ž***
;--------------------------------------Szerviz:Beállítás:Kontraszt
;Szoveg stuct:	.db x,y,width,table,str
;ScrS7_txt1:	.db   0,  0, 8,1,"Kontraszt:",0,0
ScrS7_txt1:	.db   0,  0, 8,1,"Kontrast: ",0,0
;ScrS7_txt2:	.db   0, 16, 8,1,"1 - csökkent       3 - növel",0,0
ScrS7_txt2:	.db   0, 16, 8,1,"1 - upada          3 - raste",0,0
;ScrS7_txt3:	.db   0, 28, 8,1,"Hõmérséklet:",0,0
ScrS7_txt3:	.db   0, 28, 8,1,"Temperatura:",0,0
;ScrS7_txt4:	.db   0, 40, 8,1,"7 - k csökkent     9 - k növel",0,0
ScrS7_txt4:	.db   0, 40, 8,1,"7 - upada          9 - raste",0,0
;--------------------------------------Szerviz:Testreszabás
;Szoveg stuct:	.db x,y,width,table,str
;ScrS8txtCIM:	.db   0,  0, 8,1,"Testre szabás:",0,0
ScrS8txtCIM:	.db   0,  0, 8,1,"Po meri:",0,0
;crS8txtKMBENOV:.db   0, 16, 8,1,"1 - Km bekérés: BE-növekvõ",0,0
ScrS8txtKMBENOV:.db   0, 16, 8,1,"1 - Stanje Km:  DA-raste",0,0
;ScrS8txtKMBE:	.db   0, 16, 8,1,"1 - Km bekérés: BE",0,0
ScrS8txtKMBE:	.db   0, 16, 8,1,"1 - Stanje Km:  DA",0,0
;ScrS8txtKMKI:	.db   0, 16, 8,1,"1 - Km bekérés: KI",0,0
ScrS8txtKMKI:	.db   0, 16, 8,1,"1 - Stanje Km:  NE",0,0
;ScrS8txtMENLBE:.db   0, 28, 8,1,"2 - Menetlevél bekérés: BE",0,0
ScrS8txtMENLBE:	.db   0, 28, 8,1,"2 - Potni nalog: DA",0
;ScrS8txtMENLKI:.db   0, 28, 8,1,"2 - Menetlevél bekérés: KI",0,0
ScrS8txtMENLKI:	.db   0, 28, 8,1,"2 - Potni nalog: NE",0
;ScrS8txtUZEMBE:.db   0, 40, 8,1,"3 - Üzemóra bekérés: BE",0
ScrS8txtUZEMBE:	.db   0, 40, 8,1,"3 - Stanje ",css,"tevca del.ur: DA",0,0
;ScrS8txtUZEMKI:.db   0, 40, 8,1,"3 - Üzemóra bekérés: KI",0
ScrS8txtUZEMKI:	.db   0, 40, 8,1,"3 - Stanje ",css,"tevca del.ur: NE",0,0
;--------------------------------------Szerviz:Változók
;Szoveg stuct:	.db x,y,width,table,str
;ScrS9_txt1:	.db   0,  0, 8,1,"Változók kijelzése:",0
ScrS9_txt1:	.db   0,  0, 8,1,"Prikaz sprememb:",0,0
;ScrS9_txt2:	.db   0, 20, 8,1,"Fejlesztés alatt",0,0
ScrS9_txt2:	.db   0, 20, 8,1,"V razvoju",0
;--------------------------------------Szerviz:Rendszer
;Szoveg stuct:	.db x,y,width,table,str
;ScrS10_txt1:	.db   0,  0, 8,1,"Rendszer:",0
ScrS10_txt1:	.db   0,  0, 8,1,"Sistem:",0
;ScrS10_txt2:	.db   0, 20, 8,1,"Fejlesztés alatt",0,0
ScrS10_txt2:	.db   0, 20, 8,1,"V razvoju",0
;--------------------------------------Szerviz:OraBe
;Szoveg stuct:	.db x,y,width,table,str
;======================================END
