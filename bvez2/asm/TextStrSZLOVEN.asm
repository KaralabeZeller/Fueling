;======================================
; Benzin vez�rl� LCD stringek (SZLOV�N)
;--------------------------------------
.message "Nyelv= Szlov�n"
;--------------------------------------Global
;Szoveg stuct:		.db x,y,width,table,	str
;TextVISSZA:		.db   1, 52, 8,1,	"Vissza",0,0
TextVISSZA:		.db   1, 52, 8,1,	"Nazaj",0
;TextVISSZARENDBEN:	.db   1, 52, 8,1,	"Vissza                 Rendben",0,0
TextVISSZARENDBEN:	.db   1, 52, 8,1,	"Nazaj                   V redu",0,0
;--------------------------------------F�men�:Alap
;Szoveg stuct:	.db x,y,width,table,str
;ScrA1txt1:	.db 54, 28, 8,1,"V�lasszon kutat",0
ScrA1txt1:	.db 54, 28, 8,1,"Izberi �rpalko",0
;ScrA1txt2:	.db 50, 42, 8,1,"RATIO HOMINI KFT",0,0
ScrA1txt2:	.db 50, 42, 8,1,"RATIO HOMINI d.o.o.",0
;ScrA1txt3:	.db 41, 54, 8,1,"Tel.: 36 1 3063039",0,0
ScrA1txt3:	.db 41, 54, 8,1,"  Tel.: 041 653 951 ",0,0
;--------------------------------------St�tusz kijelz�s
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
;ScrA2txtTankKi:.db   1,  1, 8,1,"Tankol�s-ki",0
ScrA2txtTankKi:	.db   1,  1, 8,1,"To�enje DA",0,0
;ScrA2txtTankBe:.db   1,  1, 8,1,"Tankol�s-be",0
ScrA2txtTankBe:	.db   1,  1, 8,1,"To�enje NE",0,0
;ScrA2txtVlimit:.db   1,  1, 8,1,"Ment�s: limit",0
ScrA2txtVlimit:	.db   1,  1, 8,1,"Shrani: limit",0
;ScrA2txtVfej:	.db   1,  1, 8,1,"Ment�s: fej",0
ScrA2txtVfej:	.db   1,  1, 8,1,"Shrani: pi",css,"tola",0
;ScrA2txtVido:	.db   1,  1, 8,1,"Ment�s: id�hat�r",0,0
ScrA2txtVido:	.db   1,  1, 8,1,"Shrani: �as.obd.",0,0
;ScrA2txtVlopas:.db   1,  1, 8,1,"Ment�s: Lop�s!!!",0,0
ScrA2txtVlopas:	.db   1,  1, 8,1,"Shrani: Kraja!!!",0,0
;ScrA2txtVfesz:	.db   1,  1, 8,1,"Ment�s: Fesz�lts�g hiba!",0,0
ScrA2txtVfesz:	.db   1,  1, 8,1,"Shrani: Napaka napetosti!",0
;ScrA2txtSlimit:.db   1,  1, 8,1,"V�ge: limit",0
ScrA2txtSlimit:	.db   1,  1, 8,1,"Konec: limit",0,0
;ScrA2txtSfej:	.db   1,  1, 8,1,"V�ge: fej",0
ScrA2txtSfej:	.db   1,  1, 8,1,"Konec: pi",css,"tola",0,0
;ScrA2txtSido:	.db   1,  1, 8,1,"V�ge: id�hat�r",0,0
ScrA2txtSido:	.db   1,  1, 8,1,"Konec: �as.obd.",0
;ScrA2txtSlopas:.db   1,  1, 8,1,"V�ge: Lop�s!!!",0,0
ScrA2txtSlopas:	.db   1,  1, 8,1,"Konec: Kraja!!!",0
;ScrA2txtSfesz:	.db   1,  1, 8,1,"V�ge: Fesz�lts�g hiba!",0,0
ScrA2txtSfesz:	.db   1,  1, 8,1,"Konec: Napaka napetosti!",0,0
;ScrA2txtVar:	.db   1,  1, 8,1,"�jra v�r",0,0
ScrA2txtVar:	.db   1,  1, 8,1,"�aka naslednjega",0,0			;***�
;ScrA2txtError:	.db   1,  1, 8,1,"Rossz st�tusz!",0,0
ScrA2txtError:	.db   1,  1, 8,1,"Napa�en status!",0
;--------------------------------------K�rtya bevitel
;Sz�veg stuct:.db x,y,width,table,str
;ScrA3txtKUT:	.db 10,  1, 8,1,".K�tf�:",0
ScrA3txtKUT:	.db 10,  1, 8,1,".Krmilnik:",0,0
;ScrA3txtHIBA:	.db 80,  1, 8,1,"K�rtya HIBA",0
ScrA3txtHIBA:	.db 80,  1, 8,1,"NAPAKA kartice",0,0
;ScrA3txtHINO:	.db 80,  1, 8,1,"           ",0
ScrA3txtHINO:	.db 80,  1, 8,1,"               ",0
;ScrA3txtCARD2:	.db 80, 13, 8,1,"K�rem a k�rty�kat",0
ScrA3txtCARD2:	.db 80, 13, 8,1,"Prosim kartice ",0
;ScrA3txtCARD1:	.db 80, 13, 8,1,"K�rem a k�rty�t",0
ScrA3txtCARD1:	.db 80, 13, 8,1,"Prosim kartico ",0
;ScrA3txtPIN0:	.db 80, 13, 8,1,"PIN k�d: ____    ",0
ScrA3txtPIN0:	.db 80, 13, 8,1,"PIN koda:____    ",0
;ScrA3txtPIN1:	.db 80, 13, 8,1,"PIN k�d: *___    ",0
ScrA3txtPIN1:	.db 80, 13, 8,1,"PIN koda:*___    ",0
;ScrA3txtPIN2:	.db 80, 13, 8,1,"PIN k�d: **__    ",0
ScrA3txtPIN2:	.db 80, 13, 8,1,"PIN koda:**__    ",0
;ScrA3txtPIN3:	.db 80, 13, 8,1,"PIN k�d: ***_    ",0
ScrA3txtPIN3:	.db 80, 13, 8,1,"PIN koda:***_    ",0
;ScrA3txtPIN4:	.db 80, 13, 8,1,"PIN k�d: ****    ",0
ScrA3txtPIN4:	.db 80, 13, 8,1,"PIN koda:****    ",0
;ScrA3txtNEV:	.db  1, 28, 8,1,"N�v:",0,0
ScrA3txtNEV:	.db  1, 28, 8,1,"Ime:",0,0
;ScrA3txtAUTO:	.db  1, 40, 8,1,"J�rm�:",0,0
ScrA3txtAUTO:	.db  1, 40, 8,1,"Vozilo:",0
;--------------------------------------Km �ra bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA4txtFoCim:	.db  0,  0, 8,1,"Km �ra �ll�sa:",0,0
ScrA4txtFoCim:	.db  0,  0, 8,1,"Stanje ",css,"tevca Km:",0	;'"css,"
;ScrA4txtHiba:	.db  1, 52, 8,1,"Az el�z�n�l nem lehet kisebb! ",0,0
ScrA4txtHiba:	.db  1, 52, 8,1,"Ne more biti manj od prej! ",0
;--------------------------------------Menetlev�l bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA5txt1:	.db  0,  0, 8,1,"Menetlev�l sz�ma:",0
ScrA5txt1:	.db  0,  0, 8,1,css,"tevilka Naloga: ",0			;�***
;--------------------------------------Tankolhat
;Szoveg stuct:	.db x,y,width,table,str
;ScrA6txt0:	.db 30,  6, 8,1,"Mai nap         .tankol�s",0
ScrA6txt0:	.db 30,  6, 8,1,"Dana",css,"nje        .to�enje ",0
;ScrA6txt1:	.db 30, 20, 8,1,"Tankolhat       litert",0,0
ScrA6txt1:	.db 30, 20, 8,1,"Lahko to�i      litrov",0,0
;ScrA6txt2:	.db 30, 34, 8,1,"      m�g       -szer.",0,0
ScrA6txt2:	.db 30, 34, 8,1,"      ",css,"e        -krat.",0,0
;--------------------------------------�zem�ra bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA7txt1:	.db  0,  0, 8,1,"�zem�ra �ll�sa:",0
ScrA7txt1:	.db  0,  0, 8,1,"Stanje ",css,"tevca del.ur:",0
;--------------------------------------Mester k�rtya bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA8txt1:	.db  0,  0, 8,1,"J�rm� k�rtya k�dja:",0
ScrA8txt1:	.db  0,  0, 8,1,"Koda kartice vozila:",0,0
;ScrA8txtKell:	.db  1, 52, 8,1,"Vissza                Nem kell",0,0
ScrA8txtKell:	.db  1, 52, 8,1,"Nazaj                       Ne",0,0
;ScrA8txtTorol:	.db  1, 52, 8,1,"T�r�l                         ",0,0
ScrA8txtTorol:	.db  1, 52, 8,1,"Bri",css,"i                         ",0,0
;ScrA8txtRendben:.db  1, 52, 8,1,"T�r�l                  Rendben",0,0
ScrA8txtRendben: .db  1, 52, 8,1,"Bri",css,"i	                  V redu",0,0
;--------------------------------------Nyomtat�s
;Szoveg stuct:	.db x,y,width,table,str
;ScrA9txtFoCim:	.db  0,  0, 8,1,"Nyomtat�s:",0,0
ScrA9txtFoCim:	.db  0,  0, 8,1,"Tiskanje: ",0,0
PrnTxtInit:	.db 0x1b,0x52,0x02,0

;PrnTxtKezd:	.db "M�r�s kezdete: ____.__.__ __:__:__",0x0a,0
PrnTxtKezd:	.db "Za�etek meritve: ____.__.__ __:__:__",0x0a,0	//***
;PrnTxtVege:	.db "M�r�s v�ge   : ____.__.__ __:__:__",0x0a,0
PrnTxtVege:	.db "Konec meritve: ____.__.__ __:__:__",0x0a,0
;PrnTxtEmber:	.db "Szem�ly           : _____________",0x0a,0,0
PrnTxtEmber:	.db "Oseba             : _____________",0x0a,0,0
;PrnTxtRendsz:	.db "J�rm� rendsz�ma   : _____________",0x0a,0,0
PrnTxtRendsz:	.db "Reg.",css,"t.vozila     : _____________",0x0a,0,0
;PrnTxtKm:	.db "Kilom�ter          :   ________ km",0x0a,0
PrnTxtKm:	.db "Kilom�ter          :   ________ km",0x0a,0
;PrnTxtUzemora:	.db "�zem�ra            :   ________ �",0x0a,0,0
PrnTxtUzemora:	.db "Stanje ",css,"tevca del.ur:  ________ �",0x0a,0,0
;PrnTxtMenlev:	.db "Menetlev�l         :   ________ ",0x0a,0
PrnTxtMenlev:	.db "Potni nalog        :   ________ ",0x0a,0
;PrnTxtSorSzam:	.db "Kim�r�s sorsz�ma Nr:     _____/_",0x0a,0
PrnTxtSorSzam:	.db "Zap.",css,"t. to�enja  Nr:     _____/_",0x0a,0
;PrnTxtOszLit:	.db "Sz�ml�l� �ll�sa   V:__________,__l",0x0a,0
PrnTxtOszLit:	.db "Stanje ",css,"tevca     V:__________,__l",0x0a,0
;PrnTxtOszKomp:	.db "�sszegezett m�r�sVo:__________,__l",0x0a,0
PrnTxtOszKomp:	.db "Meritev skupaj   Vo:__________,__l",0x0a,0
PrnTxtVonal:	.db "---------------------:------------",0x0a,0
;PrnTxtLiter:	.db "Kim�rt mennyis�g   Vt: ______,__ l",0x0a,0
PrnTxtLiter:	.db "Izto�ena koli�ina  Vt: ______,__ l",0x0a,0
;PrnTxtHom:	.db "Term�kh�m�rs�klet   t:    ___,_ �C",0x0a,0
PrnTxtHom:	.db "Temperatura goriva  t:    ___,_ �C",0x0a,0
;PrnTxtMegnev:	.db "Term�kmegnevez�s     :     G�zolaj",0x0a,0
PrnTxtMegnev:	.db "Naziv goriva         :Plinsko olje",0x0a,0
;PrnTxtBazisHo:	.db "B�zish�m�rs�klet   to:     15,0 �C",0x0a,0
PrnTxtBazisHo:	.db "Temperatura pri    to:     15,0 �C",0x0a,0
;PrnTxtLitKomp:	.db "Mennyis�g to-�n    Vo: ______,__ l",0x0a,0
PrnTxtLitKomp:	.db "Koli�ina pri to    Vo: ______,__ l",0x0a,0

PrnTxtClose:	.db 0x0a,0x0a,0x0a,0x0a,0x0a,0x1b,0x6d,0;half cut
;--------------------------------------Hiba:K�rtya
;Szoveg stuct:.db x,y,width,table,str
;ScrH1txt1:	.db 44,  6, 8,1,"K�rtya HIBA",0
ScrH1txt1:	.db 44,  6, 8,1,"NAPAKA kartice",0,0
;--------------------------------------Hiba:Kimer�tve
;Szoveg stuct:.db x,y,width,table,str
;ScrH2txt0:	.db 40,  0,10,1,"Napi megengedett",0,0
ScrH2txt0:	.db 40,  0,10,1,"Dnevno dovoljeno",0,0
;ScrH2txt1:	.db 40, 16,10,1,"tankol�sok sz�ma",0,0
ScrH2txt1:	.db 40, 16,10,1,css,"tevilo to�enj",0,0			;�***
;ScrH2txt2:	.db 40, 32,10,1,"   kimer�tve.",0
ScrH2txt2:	.db 40, 32,10,1,"   Izkori",css,"�eno.",0
;--------------------------------------Szerviz:Bel�p�s
;Szoveg stuct:	.db x,y,width,table,str
;ScrS1txtCIM:	.db  0,  0, 8,1,"K�rem a szerviz k�rty�t:",0,0
ScrS1txtCIM:	.db  0,  0, 8,1,"Prosim servisno karto:",0,0
;--------------------------------------Szerviz
;Szoveg stuct:	.db x,y,width,table,str
;ScrS2txt1:	.db   0,  0, 8,1,"Szerviz men�:",0
ScrS2txt1:	.db   0,  0, 8,1,"Servisni meni:",0,0
;ScrS2txt2:	.db   0, 14, 8,1,"1-K�tf�k       2-K�rtya inf.",0,0
ScrS2txt2:	.db   0, 14, 8,1,"1-Krmilniki    2-Info.kartice.",0,0
;ScrS2txt3:	.db   0, 26, 8,1,"3-Be�ll�t�sok  4-V�ltoz�k.",0,0
ScrS2txt3:	.db   0, 26, 8,1,"3-Nastvitve    4-Spremembe.",0
;ScrS2txt4:	.db   0, 38, 8,1,"5-Rendszer ",0
ScrS2txt4:	.db   0, 38, 8,1,"5-Sistem   ",0
;--------------------------------------Szerv�z:K�tf�k
;Szoveg stuct:	.db x,y,width,table,str
;ScrS3txtKUTFOK:.db   0,  0, 8,1,"K�tf�k:",0
ScrS3txtKUTFOK:	.db   0,  0, 8,1,"Krmilniki:",0,0
;ScrS3txtKUTAKBE:.db   0, 36, 8,1,"Gomb1-8 kutak be/ki",0
ScrS3txtKUTAKBE: .db   0, 36, 8,1,"Tipka1-8 �rpalke to�enje/konec",0,0
;--------------------------------------Szerviz:K�rty�k
;Szoveg stuct:	.db x,y,width,table,str
;ScrS4txt1:	.db   0,  0, 8,1,"K�rtya inform�ci�k:",0
ScrS4txt1:	.db   0,  0, 8,1,"Informacije o karticah:",0
;ScrS4txt2:	.db   0, 20, 8,1,"1 - K�rty�k sz�ma",0
ScrS4txt2:	.db   0, 20, 8,1,"1 - ",css,"tevilka kartice",0,0		;�***
;ScrS4txtEGY:	.db   0, 36, 8,1,"Egyk�rty�s rendszer",0
ScrS4txtEGY:	.db   0, 36, 8,1,"Enokarti�ni sistem ",0
;ScrS4txtKET:	.db   0, 36, 8,1,"K�tk�rty�s rendszer",0
ScrS4txtKET:	.db   0, 36, 8,1,"Dvokarti�ni sistem ",0
;--------------------------------------Szerviz:Be�ll�t�sok
;Szoveg stuct:	.db x,y,width,table,str
;ScrS5_txt1:	.db  0,  0, 8,1,"Be�ll�t�sok:",0,0
ScrS5_txt1:	.db  0,  0, 8,1,"Nastavitve: ",0,0
;ScrS5_txt2:	.db  0, 12, 8,1,"1-Kijelz�sek   2-Kontraszt",0,0
ScrS5_txt2:	.db  0, 12, 8,1,"1-Display       2-Kontrast",0,0
;ScrS5_txt3:	.db  0, 24, 8,1,"3-Id�",0
ScrS5_txt3:	.db  0, 24, 8,1,"3-�as",0				;�***
;ScrS5_txt4:	.db  0, 36, 8,1,"4-Testre szab�s",0
ScrS5_txt4:	.db  0, 36, 8,1,"4-Po meri",0
;--------------------------------------Szerviz:Be�ll�t�s:Literkijelz�s
;Szoveg stuct:	.db x,y,width,table,str
;ScrS6txtCIM:	.db   0,  0, 8,1,"Kijelz�sek:",0
ScrS6txtCIM:	.db   0,  0, 8,1,"Display:",0,0
;ScrS6txtBE:	.db   0, 20, 8,1,"1 - Liter kijelz�s: BE",0,0
ScrS6txtBE:	.db   0, 20, 8,1,"1 - Liter poka�i: DA",0,0		;�***
;ScrS6txtKI:	.db   0, 20, 8,1,"1 - Liter kijelz�s: KI",0,0
ScrS6txtKI:	.db   0, 20, 8,1,"1 - Liter poka�i: NE",0,0		;�***
;--------------------------------------Szerviz:Be�ll�t�s:Kontraszt
;Szoveg stuct:	.db x,y,width,table,str
;ScrS7_txt1:	.db   0,  0, 8,1,"Kontraszt:",0,0
ScrS7_txt1:	.db   0,  0, 8,1,"Kontrast: ",0,0
;ScrS7_txt2:	.db   0, 16, 8,1,"1 - cs�kkent       3 - n�vel",0,0
ScrS7_txt2:	.db   0, 16, 8,1,"1 - upada          3 - raste",0,0
;ScrS7_txt3:	.db   0, 28, 8,1,"H�m�rs�klet:",0,0
ScrS7_txt3:	.db   0, 28, 8,1,"Temperatura:",0,0
;ScrS7_txt4:	.db   0, 40, 8,1,"7 - k cs�kkent     9 - k n�vel",0,0
ScrS7_txt4:	.db   0, 40, 8,1,"7 - upada          9 - raste",0,0
;--------------------------------------Szerviz:Testreszab�s
;Szoveg stuct:	.db x,y,width,table,str
;ScrS8txtCIM:	.db   0,  0, 8,1,"Testre szab�s:",0,0
ScrS8txtCIM:	.db   0,  0, 8,1,"Po meri:",0,0
;crS8txtKMBENOV:.db   0, 16, 8,1,"1 - Km bek�r�s: BE-n�vekv�",0,0
ScrS8txtKMBENOV:.db   0, 16, 8,1,"1 - Stanje Km:  DA-raste",0,0
;ScrS8txtKMBE:	.db   0, 16, 8,1,"1 - Km bek�r�s: BE",0,0
ScrS8txtKMBE:	.db   0, 16, 8,1,"1 - Stanje Km:  DA",0,0
;ScrS8txtKMKI:	.db   0, 16, 8,1,"1 - Km bek�r�s: KI",0,0
ScrS8txtKMKI:	.db   0, 16, 8,1,"1 - Stanje Km:  NE",0,0
;ScrS8txtMENLBE:.db   0, 28, 8,1,"2 - Menetlev�l bek�r�s: BE",0,0
ScrS8txtMENLBE:	.db   0, 28, 8,1,"2 - Potni nalog: DA",0
;ScrS8txtMENLKI:.db   0, 28, 8,1,"2 - Menetlev�l bek�r�s: KI",0,0
ScrS8txtMENLKI:	.db   0, 28, 8,1,"2 - Potni nalog: NE",0
;ScrS8txtUZEMBE:.db   0, 40, 8,1,"3 - �zem�ra bek�r�s: BE",0
ScrS8txtUZEMBE:	.db   0, 40, 8,1,"3 - Stanje ",css,"tevca del.ur: DA",0,0
;ScrS8txtUZEMKI:.db   0, 40, 8,1,"3 - �zem�ra bek�r�s: KI",0
ScrS8txtUZEMKI:	.db   0, 40, 8,1,"3 - Stanje ",css,"tevca del.ur: NE",0,0
;--------------------------------------Szerviz:V�ltoz�k
;Szoveg stuct:	.db x,y,width,table,str
;ScrS9_txt1:	.db   0,  0, 8,1,"V�ltoz�k kijelz�se:",0
ScrS9_txt1:	.db   0,  0, 8,1,"Prikaz sprememb:",0,0
;ScrS9_txt2:	.db   0, 20, 8,1,"Fejleszt�s alatt",0,0
ScrS9_txt2:	.db   0, 20, 8,1,"V razvoju",0
;--------------------------------------Szerviz:Rendszer
;Szoveg stuct:	.db x,y,width,table,str
;ScrS10_txt1:	.db   0,  0, 8,1,"Rendszer:",0
ScrS10_txt1:	.db   0,  0, 8,1,"Sistem:",0
;ScrS10_txt2:	.db   0, 20, 8,1,"Fejleszt�s alatt",0,0
ScrS10_txt2:	.db   0, 20, 8,1,"V razvoju",0
;--------------------------------------Szerviz:OraBe
;Szoveg stuct:	.db x,y,width,table,str
;======================================END
