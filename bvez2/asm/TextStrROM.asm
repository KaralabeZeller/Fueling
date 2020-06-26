;======================================
; Benzin vez�rl� LCD stringek
;--------------------------------------
;M�dos�tva: 2007.01.17.
.message "Nyelv= Rom�n"
;--------------------------------------Global
;Szoveg stuct:		.db x,y,width,table,str
;TextVISSZA:		.db   1, 52, 8,1,"Vissza",0,
TextVISSZA:		.db   1, 52, 8,1,"Inapoi",0,0
;TextVISSZARENDBEN:	.db   1, 52, 8,1,"Vissza                 Rendben",0,0
TextVISSZARENDBEN:	.db   1, 52, 8,1,"Inapoi               in ordine",0,0
;--------------------------------------F�men�:Alap
;Szoveg stuct:	.db x,y,width,table,str
;ScrA1txt1:	.db 54, 28, 8,1,"V�lasszon kutat",0
ScrA1txt1:	.db 54, 28, 8,1,"Alegeti sursa",0
ScrA1txt2:	.db 50, 42, 8,1,"RATIO HOMINI KFT",0,0
ScrA1txt3:	.db 41, 54, 8,1,"Tel.: 36 1 3063039",0,0
;--------------------------------------St�tusz kijelz�s***
;Szoveg stuct:.db x,y,width,table,str
;ScrA2txtFfent:	.db   1,  1, 8,1,"Fej fent",0,0
ScrA2txtFfent:	.db   1,  1, 8,1,"",0,0
;ScrA2txtFlent:	.db   1,  1, 8,1,"Fej lent",0,0
ScrA2txtFlent:	.db   1,  1, 8,1,"",0,0
;ScrA2txtTankol:.db   1,  1, 8,1,"Tankol�s",0,0
ScrA2txtTankol:	.db   1,  1, 8,1,"",0,0
;ScrA2txtVfent:	.db   1,  1, 8,1,"V�ge: fej",0
ScrA2txtVfent:	.db   1,  1, 8,1,"",0,0
;ScrA2txtVido:	.db   1,  1, 8,1,"V�ge: id�hat�r",0,0
ScrA2txtVido:	.db   1,  1, 8,1,"",0,0
;ScrA2txtVlimit:.db   1,  1, 8,1,"V�ge: limit",0
ScrA2txtVlimit:	.db   1,  1, 8,1,"",0,0
;ScrA2txtLopas:	.db   1,  1, 8,1,"Lop�s!!!",0,0
ScrA2txtLopas:	.db   1,  1, 8,1,"",0,0
;ScrA2txtKisfesz:db   1,  1, 8,1,"Fesz�lts�g hiba!",0,0
ScrA2txtKisfesz:.db   1,  1, 8,1,"",0,0
;ScrA2txtError:	.db   1,  1, 8,1,"Rossz st�tusz!",0,0
ScrA2txtError:	.db   1,  1, 8,1,"",0,0
;--------------------------------------K�rtya bevitel
;Sz�veg stuct:.db x,y,width,table,str
;ScrA3txtKUT:	.db 10,  1, 8,1,".K�tf�:',0
ScrA3txtKUT:	.db 10,  1, 8,1,".Sursa",0,0
;ScrA3txtHIBA:	.db 80,  1, 8,1,"K�rtya HIBA",0
ScrA3txtHIBA:	.db 80,  1, 8,1,"Eror la card",0,0
ScrA3txtHINO:	.db 80,  1, 8,1,"           ",0
;ScrA3txtCARD2:	.db 80, 13, 8,1,"K�rem a k�rty�kat",0
ScrA3txtCARD2:	.db 80, 13, 8,1,"Introduce cardul",0,0
;ScrA3txtCARD1:	.db 80, 13, 8,1,"K�rem a k�rty�t",0
ScrA3txtCARD1:	.db 80, 13, 8,1,"Introduce cardul",0,0
;ScrA3txtPIN0:	.db 80, 13, 8,1,"PIN k�d: ____    ",0
ScrA3txtPIN0:	.db 80, 13, 8,1,"COD PIN: ____    ",0
;ScrA3txtPIN1:	.db 80, 13, 8,1,"PIN k�d: *___    ",0
ScrA3txtPIN1:	.db 80, 13, 8,1,"COD PIN: *___    ",0
;ScrA3txtPIN2:	.db 80, 13, 8,1,"PIN k�d: **__    ",0
ScrA3txtPIN2:	.db 80, 13, 8,1,"COD PIN: **__    ",0
;ScrA3txtPIN3:	.db 80, 13, 8,1,"PIN k�d: ***_    ",0
ScrA3txtPIN3:	.db 80, 13, 8,1,"COD PIN: ***_    ",0
;ScrA3txtPIN4:	.db 80, 13, 8,1,"PIN k�d: ****    ",0
ScrA3txtPIN4:	.db 80, 13, 8,1,"COD PIN: ****    ",0
;ScrA3txtNEV:	.db  1, 28, 8,1,"N�v:",0,0
ScrA3txtNEV:	.db  1, 28, 8,1,"Nume:",0
;ScrA3txtAUTO:	.db  1, 40, 8,1,"J�rm�:",0,0
ScrA3txtAUTO:	.db  1, 40, 8,1,"Vehicul:",0,0
;--------------------------------------Km �ra bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA4txtFoCim:	.db  0,  0, 8,1,"Km �ra �ll�sa:",0,0
ScrA4txtFoCim:	.db  0,  0, 8,1,"Pozitia Km:",0			;POZITIA KILOMETRAJULUI
;ScrA4txtHiba:	.db  1, 52, 8,1,"Az el�z�n�l nem lehet kisebb!",0
ScrA4txtHiba:	.db  1, 52, 8,1,"Nu poate fii mai mic de!",0,0	;NUPOATEFII MAIMIC DE
;--------------------------------------Menetlev�l bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA5txt1:	.db  0,  0, 8,1,"Menetlev�l sz�ma:",0
ScrA5txt1:	.db  0,  0, 8,1,"Numr foii de parc.:",0		;NUMARUL FOII DE PARCURS
;--------------------------------------Tankolhat
;Szoveg stuct:	.db x,y,width,table,str
;ScrA6txt0:	.db  0,  6, 8,1,"    Mai nap         .tankol�s",0
ScrA6txt0:	.db  0,  6, 8,1," Ziua de azi        .altimentare",0,0
;ScrA6txt1:	.db  0, 20, 8,1,"    Tankolhat       litert",0,0
ScrA6txt1:	.db  0, 20, 8,1,"Se poate alimenta   litrii",0,0;SE POATE ALIMENTA... LITRII
;ScrA6txt2:	.db 30, 34, 8,1,"      m�g       -szor.",0,0
ScrA6txt2:	.db 30, 34, 8,1,"     inca       -de ori.",0,0
;--------------------------------------�zem�ra bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA7txt1:	.db  0,  0, 8,1,"�zem�ra �ll�sa:",0
ScrA7txt1:	.db  0,  0, 8,1,"Pozitia ceasului de expoatare:",0,0
;--------------------------------------Mester k�rtya bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA8txt1:	.db  0,  0, 8,1,"J�rm� k�rtya k�dja:",0
ScrA8txt1:	.db  0,  0, 8,1,"Codul cardului vehiculului:",0
;ScrA8txtKell:	.db  1, 52, 8,1,"Vissza                Nem kell",0,0
ScrA8txtKell:	.db  1, 52, 8,1,"Inapoi              Nu trebuie",0,0
;ScrA8txtTorol:	.db  1, 52, 8,1,"T�r�l",0,0
ScrA8txtTorol:	.db  1, 52, 8,1,"Clear",0;***
;ScrA8txtRendben:.db  1, 52, 8,1,"T�r�l                  Rendben",0,0
ScrA8txtRendben:.db  1, 52, 8,1,"Clear                 In ordine",0;***
;--------------------------------------Nyomtat�s
;Szoveg stuct:	.db x,y,width,table,str
;ScrA9txtFoCim:	.db  0,  0, 8,1,"Nyomtat�s:",0,0
ScrA9txtFoCim:	.db  0,  0, 8,1,"Imprimare:",0,0
PrnTxtInit:	.db 0x1b,0x52,0x02,0

;PrnTxtKezd:	.db "M�r�s kezdete: ____.__.__ __:__:__",0x0a,0
PrnTxtKezd:	.db "Incep. alim. : ____.__.__ __:__:__",0x0a,0		;INCEPUTUL ALIMENTARII
;PrnTxtVege:	.db "M�r�s v�ge   : ____.__.__ __:__:__",0x0a,0
PrnTxtVege:	.db "Sfars. alim. : ____.__.__ __:__:__",0x0a,0		;SFARSITUL ALMIMENTARII
;PrnTxtEmber:	.db "Szem�ly           : _____________",0x0a,0,0
PrnTxtEmber:	.db "Persoana          : _____________",0x0a,0,0
;PrnTxtRendsz:	.db "J�rm� rendsz�ma   : _____________",0x0a,0,0
PrnTxtRendsz:	.db "Numar inmatriculare:_____________",0x0a,0,0	;NUMARUL DE INMATEICULARE AL VEHICULULUI
;PrnTxtKm:	.db "Kilom�ter          :   ________ km",0x0a,0
PrnTxtKm:	.db "Kilometraj         :   ________ km",0x0a,0
;PrnTxtUzemora:	.db "�zem�ra            :   ________ �",0x0a,0,0
PrnTxtUzemora:	.db "Ceasul de exploatare:  ________ �",0x0a,0,0
;PrnTxtMenlev:	.db "Menetlev�l         :   ________ ",0x0a,0
PrnTxtMenlev:	.db "Foaia de parcurs   :   ________ ",0x0a,0
;PrnTxtSorSzam:	.db "Kim�r�s sorsz�ma Nr:     _____/_",0x0a,0
PrnTxtSorSzam:	.db "Numarul alimentarii:     _____/_",0x0a,0
;PrnTxtOszLit:	.db "Sz�ml�l� �ll�sa   V:__________,__l",0x0a,0
PrnTxtOszLit:	.db "Poz.numaratorului V:__________,__l",0x0a,0		;POZITIA NUMARATORULUI
;PrnTxtOszKomp:	.db "�sszegezett m�r�sVo:__________,__l",0x0a,0
PrnTxtOszKomp:	.db "Alim totalizata  Vo:__________,__l",0x0a,0		;ALUMENTRE TOTALIZATA
PrnTxtVonal:	.db "---------------------:------------",0x0a,0
;PrnTxtLiter:	.db "Kim�rt mennyis�g   Vt: ______,__ l",0x0a,0
PrnTxtLiter:	.db "Cantit. aliment.   Vt: ______,__ l",0x0a,0		;CANTITATEA ALIMENTATA
;PrnTxtHom:	.db "Term�kh�m�rs�klet   t:    ___,_ �C",0x0a,0
PrnTxtHom:	.db "Temperatura produsului t: ___,_ �C",0x0a,0
;PrnTxtMegnev:	.db "Term�kmegnevez�s     :     G�zolaj",0x0a,0
PrnTxtMegnev:	.db "Denumirea produsului :    Motorina",0x0a,0
;PrnTxtBazisHo:	.db "B�zish�m�rs�klet   to:     15,0 �C",0x0a,0
PrnTxtBazisHo:	.db "Temp. de baza      to:     15,0 �C",0x0a,0
;PrnTxtLitKomp:	.db "Mennyis�g to-�n    Vo: ______,__ l",0x0a,0
PrnTxtLitKomp:	.db "Cantitate (to)     Vo: ______,__ l",0x0a,0

PrnTxtClose:	.db 0x0a,0x0a,0x0a,0x0a,0x0a,0x1b,0x6d,0;half cut
;--------------------------------------Hiba:K�rtya
;Szoveg stuct:.db x,y,width,table,str
;ScrH1txt1:	.db 44,  6, 8,1,"K�rtya HIBA",0
ScrH1txt1:	.db 44,  6, 8,1,"Eroare la card",0,0		;EROARE LA CARTELA
;--------------------------------------Hiba:Kimer�tve
;Szoveg stuct:.db x,y,width,table,str
;ScrH2txt0:	.db 40,  0,10,1,"Napi megengedett",0,0
ScrH2txt0:	.db 40,  0,10,1,"Limita pe zi",0,0
;ScrH2txt1:	.db 40, 16,10,1,"tankol�sok sz�ma",0,0
ScrH2txt1:	.db 40, 16,10,1,"numarul alimantarii",0		;NUMARUL ALIM.
;ScrH2txt2:	.db 40, 32,10,1,"   kimer�tve.",0
ScrH2txt2:	.db 40, 32,10,1,"   epuizat.",0
;--------------------------------------Szerviz:Bel�p�s
;Szoveg stuct:	.db x,y,width,table,str
;ScrS1txtCIM:	.db  0,  0, 8,1,"K�rem a szerviz k�rty�t:",0,0
ScrS1txtCIM:	.db  0,  0, 8,1,"Rog cartela de servis:",0,0
;--------------------------------------Szerviz
;Szoveg stuct:	.db x,y,width,table,str
;ScrS2txt1:	.db   0,  0, 8,1,"Szerviz men�:",0
ScrS2txt1:	.db   0,  0, 8,1,"Meniul servis:",0,0
;ScrS2txt2:	.db   0, 14, 8,1,"1-K�tf�k       2-K�rtya inf.",0,0
ScrS2txt2:	.db   0, 14, 8,1,"1-Sursele      2-Informatii card",0,0
;ScrS2txt3:	.db   0, 26, 8,1,"3-Be�ll�t�sok  4-V�ltoz�k.",0,0
ScrS2txt3:	.db   0, 26, 8,1,"3-Setari       4-Variabile",0,0
;ScrS2txt4:	.db   0, 38, 8,1,"5-Rendszer",0
ScrS2txt4:	.db   0, 38, 8,1,"5-Sistem",0,0
;--------------------------------------Szerv�z:K�tf�k
;Szoveg stuct:	.db x,y,width,table,str
;ScrS3txtKUTFOK:.db   0,  0, 8,1,"K�tf�k:",0
ScrS3txtKUTFOK:	.db   0,  0, 8,1,"Surse:",0,0
;ScrS3txtKUTAKBE:.db   0, 36, 8,1,"Gomb1-8 kutak be/ki",0
ScrS3txtKUTAKBE:.db   0, 36, 8,1,"Buton 1-8 surse pornit/oprit",0,0
;--------------------------------------Szerviz:K�rty�k
;Szoveg stuct:	.db x,y,width,table,str
;ScrS4txt1:	.db   0,  0, 8,1,"K�rtya inform�ci�k:",0
ScrS4txt1:	.db   0,  0, 8,1,"Informatii card:",0,0		;INFORMATII DESPRE CARTELA
;ScrS4txt2:	.db   0, 20, 8,1,"1 - K�rty�k sz�ma",0
ScrS4txt2:	.db   0, 20, 8,1,"1 - Cant.cardurilor",0	;NUMARUL CARTELELOR
;ScrS4txtEGY:	.db   0, 36, 8,1,"Egyk�rty�s rendszer",0
ScrS4txtEGY:	.db   0, 36, 8,1,"sistem cu un card",0		;SISTEM CU O CARTELA
;ScrS4txtKET:	.db   0, 36, 8,1,"K�tk�rty�s rendszer",0
ScrS4txtKET:	.db   0, 36, 8,1,"sistem cu doua carduri",0,0	;SISTEM CU DOUA CARTELE
;--------------------------------------Szerviz:Be�ll�t�sok
;Szoveg stuct:	.db x,y,width,table,str
;ScrS5_txt1:	.db  0,  0, 8,1,"Be�ll�t�sok:",0,0
ScrS5_txt1:	.db  0,  0, 8,1,"Setari:",0
;ScrS5_txt2:	.db  0, 12, 8,1,"1-Kijelz�sek   2-Kontraszt",0,0
ScrS5_txt2:	.db  0, 12, 8,1,"1-Indicari     2-Contrast",0
;ScrS5_txt3:	.db  0, 24, 8,1,"3-Id�k",0,0
ScrS5_txt3:	.db  0, 24, 8,1,"3-Timpuri",0
;ScrS5_txt4:	.db  0, 36, 8,1,"4-Testre szab�s",0
ScrS5_txt4:	.db  0, 36, 8,1,"4-Stare configurare personala",0
;--------------------------------------Szerviz:Be�ll�t�s:Literkijelz�s
;Szoveg stuct:	.db x,y,width,table,str
;ScrS6txtCIM:	.db   0,  0, 8,1,"Kijelz�sek:",0
ScrS6txtCIM:	.db   0,  0, 8,1,"Indicari:",0
;ScrS6txtBE:	.db   0, 20, 8,1,"1 - Liter kijelz�s: BE",0,0
ScrS6txtBE:	.db   0, 20, 8,1,"1 - Ind. cant. de comb.: PORNIT",0	;INDICAREA CANTITATII DE COMBUSTIBIL: PORNIT
;ScrS6txtKI:	.db   0, 20, 8,1,"1 - Liter kijelz�s: KI",0,0
ScrS6txtKI:	.db   0, 20, 8,1,"1 - Ind. cant. de comb.: OPRIT",0,0	;INDICAREA CANTITATII DE COMBUSTIBIL: OPRIT
;--------------------------------------Szerviz:Be�ll�t�s:Kontraszt
;Szoveg stuct:	.db x,y,width,table,str
;ScrS7_txt1:	.db   0,  0, 8,1,"Kontraszt:",0,0
ScrS7_txt1:	.db   0,  0, 8,1,"Contrast:",0
;ScrS7_txt2:	.db   0, 16, 8,1,"1 - cs�kkent       3 - n�vel",0,0
ScrS7_txt2:	.db   0, 16, 8,1,"1 - scazut         3 - marit",0,0
;ScrS7_txt3:	.db   0, 28, 8,1,"H�m�rs�klet:",0,0
ScrS7_txt3:	.db   0, 28, 8,1,"Temperatura:",0,0
;ScrS7_txt4:	.db   0, 40, 8,1,"7 - k cs�kkent     9 - k n�vel",0,0
ScrS7_txt4:	.db   0, 40, 8,1,"7 - k scazut       9 - k marit",0,0
;--------------------------------------Szerviz:Testreszab�s
;Szoveg stuct:	.db x,y,width,table,str
;				 "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";max. ekkora lehet a sor
;ScrS8txtCIM:	.db   0,  0, 8,1,"Testre szab�s:",0,0
ScrS8txtCIM:	.db   0,  0, 8,1,"Stare configurare personala:",0,0
;ScrS8txtKMBENOV:db   0, 16, 8,1,"1-Km bek�r�s: BE-n�vekv�",0,0
ScrS8txtKMBENOV:.db   0, 16, 8,1,"1-Pozitia km: PORNIT,CRESCATOR",0
;ScrS8txtKMBE:	.db   0, 16, 8,1,"1-Km bek�r�s: BE",0,0
ScrS8txtKMBE:	.db   0, 16, 8,1,"1-Pozitia km: PORNIT",0,0
;ScrS8txtKMKI:	.db   0, 16, 8,1,"1-Km bek�r�s: KI",0,0
ScrS8txtKMKI:	.db   0, 16, 8,1,"1-Pozitia km: OPRIT",0
;ScrS8txtMENLBE:.db   0, 28, 8,1,"2-Menetlev�l bek�r�s: BE",0,0
ScrS8txtMENLBE:	.db   0, 28, 8,1,"2-Prez. foii de parcurs:PORNIT",0,0
;ScrS8txtMENLKI:.db   0, 28, 8,1,"2-Menetlev�l bek�r�s: KI",0,0
ScrS8txtMENLKI:	.db   0, 28, 8,1,"2-Prez. foii de parcurs:OPRIT",0
;ScrS8txtUZEMBE:.db   0, 40, 8,1,"3-�zem�ra bek�r�s: BE",0
ScrS8txtUZEMBE:	.db   0, 40, 8,1,"3-Prez.timpului de expl:PORNIT",0,0
;ScrS8txtUZEMBE:	.db   0, 40, 8,1,"3-Prezenteria timpului de exploatare: PORNIT",0,0
;ScrS8txtUZEMKI:.db   0, 40, 8,1,"3-�zem�ra bek�r�s: KI",0
ScrS8txtUZEMKI:	.db   0, 40, 8,1,"3-Prez.timpului de expl:OPRIT",0
;ScrS8txtUZEMKI:	.db   0, 40, 8,1,"3-Prezenteria timpului de exploatare: OPRIT",0
;--------------------------------------Szerviz:V�ltoz�k
;Szoveg stuct:	.db x,y,width,table,str
;ScrS9_txt1:	.db   0,  0, 8,1,"V�ltoz�k kijelz�se:",0
ScrS9_txt1:	.db   0,  0, 8,1,"Indicarea variabilelor:",0
;ScrS9_txt2:	.db   0, 20, 8,1,"Fejleszt�s alatt",0,0
ScrS9_txt2:	.db   0, 20, 8,1,"sub dezvoltare",0,0
;--------------------------------------Szerviz:Rendszer
;Szoveg stuct:	.db x,y,width,table,str
;ScrS10_txt1:	.db   0,  0, 8,1,"Rendszer:",0
ScrS10_txt1:	.db   0,  0, 8,1,"Sistem:",0
;ScrS10_txt2:	.db   0, 20, 8,1,"Fejleszt�s alatt",0,0
ScrS10_txt2:	.db   0, 20, 8,1,"sub dezvoltare",0,0
;--------------------------------------Szerviz:OraBe
;Szoveg stuct:	.db x,y,width,table,str
;======================================END
