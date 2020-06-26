;======================================
; Benzin vez�rl� LCD stringek (SZLOV�K)
;--------------------------------------
.message "Nyelv= Szlov�k"
;--------------------------------------Global
;Szoveg stuct:		.db x,y,width,table,str
;TextVISSZA:		.db   1, 52, 8,1,"Vissza",0,0
TextVISSZA:		.db   1, 52, 8,1,"Sp�",ht,0,0
;TextVISSZARENDBEN:	.db   1, 52, 8,1,"Vissza                 Rendben",0,0
TextVISSZARENDBEN:	.db   1, 52, 8,1,"Sp�",ht,"             v poriadku/ok",0,0
;--------------------------------------F�men�:Alap
;Szoveg stuct:	.db x,y,width,table,str
;ScrA1txt1:	.db 54, 28, 8,1,"V�lasszon kutat",0
ScrA1txt1:	.db 54, 28, 8,1,"Zvolte si stojan",0,0
;ScrA1txt2:	.db 50, 42, 8,1,"RATIO HOMINI KFT",0,0
ScrA1txt2:	.db  1, 42, 8,1,"Ratio Homini Slovakia kft./sro/",0
;ScrA1txt3:	.db 41, 54, 8,1,"Tel.: 36 1 3063039",0,0
ScrA1txt3:	.db 41, 54, 8,1,"Tel.: 36 1 3063039",0,0
;--------------------------------------St�tusz kijelz�s***
;Szoveg stuct:.db x,y,width,table,str
;ScrA2txtKikapcs:.db   1,  1, 8,1,"Kikapcsolva",0
ScrA2txtKikapcs:.db   1,  1, 8,1,"",0,0
;ScrA2txtFejFent:.db   1,  1, 8,1,"Fej fent",0,0
ScrA2txtFejFent:.db   1,  1, 8,1,"",0,0
;ScrA2txtSum1:	.db   1,  1, 8,1,"Fej fent-Sum1",0
ScrA2txtSum1:	.db   1,  1, 8,1,"",0,0
;ScrA2txtSum2:	.db   1,  1, 8,1,"Fej fent-Sum2",0
ScrA2txtSum2:	.db   1,  1, 8,1,"",0,0
;ScrA2txtFejLent:.db   1,  1, 8,1,"Fej lent",0,0
ScrA2txtFejLent:.db   1,  1, 8,1,"",0,0
;ScrA2txtTankKi:.db   1,  1, 8,1,"Tankol�s-ki",0
ScrA2txtTankKi:	.db   1,  1, 8,1,"",0,0
;ScrA2txtTankBe:.db   1,  1, 8,1,"Tankol�s-be",0
ScrA2txtTankBe:	.db   1,  1, 8,1,"",0,0
;ScrA2txtVlimit:.db   1,  1, 8,1,"Ment�s: limit",0
ScrA2txtVlimit:	.db   1,  1, 8,1,"",0,0
;ScrA2txtVfej:	.db   1,  1, 8,1,"Ment�s: fej",0
ScrA2txtVfej:	.db   1,  1, 8,1,"",0,0
;ScrA2txtVido:	.db   1,  1, 8,1,"Ment�s: id�hat�r",0,0
ScrA2txtVido:	.db   1,  1, 8,1,"",0,0
;ScrA2txtVlopas:.db   1,  1, 8,1,"Ment�s: Lop�s!!!",0,0
ScrA2txtVlopas:	.db   1,  1, 8,1,"",0,0
;ScrA2txtVfesz:	.db   1,  1, 8,1,"Ment�s: Fesz�lts�g hiba!",0,0
ScrA2txtVfesz:	.db   1,  1, 8,1,"",0,0
;ScrA2txtSlimit:.db   1,  1, 8,1,"V�ge: limit",0
ScrA2txtSlimit:	.db   1,  1, 8,1,"",0,0
;ScrA2txtSfej:	.db   1,  1, 8,1,"V�ge: fej",0
ScrA2txtSfej:	.db   1,  1, 8,1,"",0,0
;ScrA2txtSido:	.db   1,  1, 8,1,"V�ge: id�hat�r",0,0
ScrA2txtSido:	.db   1,  1, 8,1,"",0,0
;ScrA2txtSlopas:.db   1,  1, 8,1,"V�ge: Lop�s!!!",0,0
ScrA2txtSlopas:	.db   1,  1, 8,1,"",0,0
;ScrA2txtSfesz:	.db   1,  1, 8,1,"V�ge: Fesz�lts�g hiba!",0,0
ScrA2txtSfesz:	.db   1,  1, 8,1,"",0,0
;ScrA2txtVar:	.db   1,  1, 8,1,"�jra v�r",0,0
ScrA2txtVar:	.db   1,  1, 8,1,"",0,0
;ScrA2txtError:	.db   1,  1, 8,1,"Rossz st�tusz!",0,0
ScrA2txtError:	.db   1,  1, 8,1,"",0,0
;--------------------------------------K�rtya bevitel
;Sz�veg stuct:.db x,y,width,table,str
;ScrA3txtKUT:	.db 10,  1, 8,1,".K�tf�:",0
ScrA3txtKUT:	.db 10,  1, 8,1,".stojan:",0,0
;ScrA3txtHIBA:	.db 80,  1, 8,1,"K�rtya HIBA",0
ScrA3txtHIBA:	.db 80,  1, 8,1,"Chyba karty",0
;ScrA3txtHINO:	.db 80,  1, 8,1,"           ",0
ScrA3txtHINO:	.db 80,  1, 8,1,"           ",0
;ScrA3txtCARD2:	.db 80, 13, 8,1,"K�rem a k�rty�kat",0
ScrA3txtCARD2:	.db 80, 13, 8,1,"Pros",hi,"m karty",0,0
;ScrA3txtCARD1:	.db 80, 13, 8,1,"K�rem a k�rty�t",0
ScrA3txtCARD1:	.db 80, 13, 8,1,"Pros",hi,"m karta",0,0
;ScrA3txtPIN0:	.db 80, 13, 8,1,"PIN k�d: ____    ",0
ScrA3txtPIN0:	.db 80, 13, 8,1,"PIN k�d: ____    ",0
;ScrA3txtPIN1:	.db 80, 13, 8,1,"PIN k�d: *___    ",0
ScrA3txtPIN1:	.db 80, 13, 8,1,"PIN k�d: *___    ",0
;ScrA3txtPIN2:	.db 80, 13, 8,1,"PIN k�d: **__    ",0
ScrA3txtPIN2:	.db 80, 13, 8,1,"PIN k�d: **__    ",0
;ScrA3txtPIN3:	.db 80, 13, 8,1,"PIN k�d: ***_    ",0
ScrA3txtPIN3:	.db 80, 13, 8,1,"PIN k�d: ***_    ",0
;ScrA3txtPIN4:	.db 80, 13, 8,1,"PIN k�d: ****    ",0
ScrA3txtPIN4:	.db 80, 13, 8,1,"PIN k�d: ****    ",0
;ScrA3txtNEV:	.db  1, 28, 8,1,"N�v:",0,0
ScrA3txtNEV:	.db  1, 28, 8,1,"Meno:",0
;ScrA3txtAUTO:	.db  1, 40, 8,1,"J�rm�:",0,0
ScrA3txtAUTO:	.db  1, 40, 8,1,"Vozidlo:",0,0
;--------------------------------------Km �ra bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA4txtFoCim:	.db  0,  0, 8,1,"Km �ra �ll�sa:",0,0
ScrA4txtFoCim:	.db  0,  0, 8,1,"Stav tachometra:",0,0
;ScrA4txtHiba:	.db  1, 52, 8,1,"Az el�z�n�l nem lehet kisebb!",0
ScrA4txtHiba:	.db  1, 52, 8,1,"Nemoze by",ht," men",css,hi," ako predo",css,'l',hi,'!',0,0
;--------------------------------------Menetlev�l bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA5txt1:	.db  0,  0, 8,1,"Menetlev�l sz�ma:",0
ScrA5txt1:	.db  0,  0, 8,1,'C',hi,"slo vlakopisu:",0,0
;--------------------------------------Tankolhat
;Szoveg stuct:	.db x,y,width,table,str
;ScrA6txt0:	.db 30,  6, 8,1,"Mai nap         .tankol�s",0
ScrA6txt0:	.db 30,  6, 8,1,"Dnes           .tankovanie",0,0
;ScrA6txt1:	.db 30, 20, 8,1,"Tankolhat       litert",0,0
ScrA6txt1:	.db 14, 20, 8,1,"Natankujte        litrov",0,0
;ScrA6txt2:	.db 30, 34, 8,1,"      m�g       -szor.",0,0
ScrA6txt2:	.db 22, 34, 8,1,"      e",css,"te       -kr�t.",0
;--------------------------------------�zem�ra bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA7txt1:	.db  0,  0, 8,1,"�zem�ra �ll�sa:",0
ScrA7txt1:	.db  0,  0, 8,1,"Stav prev�dzkovej hodiny:",0
;--------------------------------------Mester k�rtya bevitel
;Szoveg stuct:	.db x,y,width,table,str
;ScrA8txt1:	.db  0,  0, 8,1,"J�rm",du," k�rtya k�dja:",0
ScrA8txt1:	.db  0,  0, 8,1,"K�d karty vozidla:",0,0
;ScrA8txtKell:	.db  1, 52, 8,1,"Vissza                Nem kell",0,0
ScrA8txtKell:	.db  1, 52, 8,1,"Sp�",ht,"                  Netreba",0
;ScrA8txtTorol:	.db  1, 52, 8,1,'T',ro,'r',ro,"l                         ",0,0
ScrA8txtTorol:	.db  1, 52, 8,1,"Vymaza",ht,0
;ScrA8txtRendben:.db  1, 52, 8,1,'T',ro,'r',ro,"l                  Rendben",0,0
ScrA8txtRendben:.db  1, 52, 8,1,"Vymaza",ht,"                    OK ",0,0
;--------------------------------------Nyomtat�s***
;Szoveg stuct:	.db x,y,width,table,str
ScrA9txtFoCim:	.db  0,  0, 8,1,"Nyomtat�s:",0,0
PrnTxtInit:	.db 0x1b,0x52,0x02,0

PrnTxtKezd:	.db "M�r�s kezdete: ____.__.__ __:__:__",0x0a,0
PrnTxtVege:	.db "M�r�s v�ge   : ____.__.__ __:__:__",0x0a,0
PrnTxtEmber:	.db "Szem�ly           : _____________",0x0a,0,0
PrnTxtRendsz:	.db "J�rm� rendsz�ma   : _____________",0x0a,0,0
PrnTxtKm:	.db "Kilom�ter          :   ________ km",0x0a,0
PrnTxtUzemora:	.db "�zem�ra            :   ________ �",0x0a,0,0
PrnTxtMenlev:	.db "Menetlev�l         :   ________ ",0x0a,0
PrnTxtSorSzam:	.db "Kim�r�s sorsz�ma Nr:     _____/_",0x0a,0
PrnTxtOszLit:	.db "Sz�ml�l� �ll�sa   V:__________,__l",0x0a,0
PrnTxtOszKomp:	.db "�sszegezett m�r�sVo:__________,__l",0x0a,0
PrnTxtVonal:	.db "---------------------:------------",0x0a,0
PrnTxtLiter:	.db "Kim�rt mennyis�g   Vt: ______,__ l",0x0a,0
PrnTxtHom:	.db "Term�kh�m�rs�klet   t:    ___,_ �C",0x0a,0
;PrnTxtMegnev:	.db "Term�kmegnevez�s Nr5 OMTLAN91/EN91",0x0a,0
PrnTxtMegnev:	.db "Term�kmegnevez�s     :     G�zolaj",0x0a,0
;PrnTxtSuruseg:	.db "Kat./S�r�s�g      d15:   760 kg/m3",0x0a,0
PrnTxtBazisHo:	.db "B�zish�m�rs�klet   to:     15,0 �C",0x0a,0
PrnTxtLitKomp:	.db "Mennyis�g to-�n    Vo: ______,__ l",0x0a,0

PrnTxtClose:	.db 0x0a,0x0a,0x0a,0x0a,0x0a,0x1b,0x6d,0;half cut
;--------------------------------------Hiba:K�rtya
;Szoveg stuct:.db x,y,width,table,str
;ScrH1txt1:	.db 44,  6, 8,1,"K�rtya HIBA",0
ScrH1txt1:	.db 44,  6, 8,1,"Chyba karty",0
;--------------------------------------Hiba:Kimer�tve
;Szoveg stuct:.db x,y,width,table,str
;ScrH2txt0:	.db 40,  0,10,1,"Napi megengedett",0,0
ScrH2txt0:	.db 40,  0,10,1,"dovolen� d�vka",0,0
;ScrH2txt1:	.db 40, 16,10,1,"tankol�sok sz�ma",0,0
ScrH2txt1:	.db 40, 16,10,1,"po�et tankovan",hi,0
;ScrH2txt2:	.db 40, 32,10,1,"   kimer",hi,"tve.",0
ScrH2txt2:	.db 40, 32,10,1,"   vy�erpan�.",0
;--------------------------------------Szerviz:Bel�p�s
;Szoveg stuct:	.db x,y,width,table,str
;ScrS1txtCIM:	.db  0,  0, 8,1,"K�rem a szerviz k�rty�t:",0,0
ScrS1txtCIM:	.db  0,  0, 8,1,"Pros",hi,"m servisn� kartu:",0,0
;--------------------------------------Szerviz
;Szoveg stuct:	.db x,y,width,table,str
;ScrS2txt1:	.db   0,  0, 8,1,"Szerviz men�:",0
ScrS2txt1:	.db   0,  0, 8,1,"Servisn� menu:",0,0
;ScrS2txt2:	.db   0, 14, 8,1,"1-K�tf",do,"k       2-K�rtya inf.",0,0
ScrS2txt2:	.db   0, 14, 8,1,"1-Stojany          2-Inf.karty",0,0
;ScrS2txt3:	.db   0, 26, 8,1,"3-Be�ll",hi,"t�sok  4-V�ltoz�k.",0,0
ScrS2txt3:	.db   0, 26, 8,1,"3-Nastavenia       4-Zmeny",0,0
;ScrS2txt4:	.db   0, 38, 8,1,"5-Rendszer ",0
ScrS2txt4:	.db   0, 38, 8,1,"5-Syst�m",0,0
;--------------------------------------Szerv�z:K�tf�k
;Szoveg stuct:	.db x,y,width,table,str
;ScrS3txtKUTFOK:	.db   0,  0, 8,1,"K�tf",do,"k:",0
ScrS3txtKUTFOK:	.db   0,  0, 8,1,"Stojany:",0,0
;ScrS3txtKUTAKBE:.db   0, 36, 8,1,"Gomb1-9 kutak be/ki",0
ScrS3txtKUTAKBE:.db   0, 36, 8,1,"Gomb",hi,"k 1-9 stojany do/z",0
;--------------------------------------Szerviz:K�rty�k
;Szoveg stuct:	.db x,y,width,table,str
;ScrS4txt1:	.db   0,  0, 8,1,"K�rtya inform�ci�k:",0
ScrS4txt1:	.db   0,  0, 8,1,"Inf.karty:",0,0
;ScrS4txt2:	.db   0, 20, 8,1,"1 - K�rty�k sz�ma",0
ScrS4txt2:	.db   0, 20, 8,1,"1 - e",hi,"slo kariet",0,0
;ScrS4txtEGY:	.db   0, 36, 8,1,"Egyk�rty�s rendszer",0
ScrS4txtEGY:	.db   0, 36, 8,1,"Jednokartovy syst�m",0
;ScrS4txtKET:	.db   0, 36, 8,1,"K�tk�rty�s rendszer",0
ScrS4txtKET:	.db   0, 36, 8,1,"Dvojkartovy syst�m",0,0
;--------------------------------------Szerviz:Be�ll�t�sok
;Szoveg stuct:	.db x,y,width,table,str
;ScrS5_txt1:	.db  0,  0, 8,1,"Be�ll�t�sok:",0,0
ScrS5_txt1:	.db  0,  0, 8,1,"Nastavenia:",0
;ScrS5_txt2:	.db  0, 12, 8,1,"1-Kijelz�sek   2-Kontraszt",0,0
ScrS5_txt2:	.db  0, 12, 8,1,"1-Vysignalizovania 2-Kontrast",0
;ScrS5_txt3:	.db  0, 24, 8,1,"3-Id�k",0,0
ScrS5_txt3:	.db  0, 24, 8,1,"3-Easy",0,0
;ScrS5_txt4:	.db  0, 36, 8,1,"4-Testre szab�s",0
ScrS5_txt4:	.db  0, 36, 8,1,"4-Prisp�sobenie",0
;--------------------------------------Szerviz:Be�ll�t�s:Literkijelz�s
;Szoveg stuct:	.db x,y,width,table,str
;ScrS6txtCIM:	.db   0,  0, 8,1,"Kijelz�sek:",0
ScrS6txtCIM:	.db   0,  0, 8,1,"Vysignalizovania:",0
;ScrS6txtBE:	.db   0, 20, 8,1,"1 - Liter kijelz�s: BE",0,0
ScrS6txtBE:	.db   0, 20, 8,1,"1 - Indik�tor litrov: do",0,0
;ScrS6txtKI:	.db   0, 20, 8,1,"1 - Liter kijelz�s: KI",0,0
ScrS6txtKI:	.db   0, 20, 8,1,"1 - Indik�tor litrov: z",0
;--------------------------------------Szerviz:Be�ll�t�s:Kontraszt
;Szoveg stuct:	.db x,y,width,table,str
;ScrS7_txt1:	.db   0,  0, 8,1,"Kontraszt:",0,0
ScrS7_txt1:	.db   0,  0, 8,1,"Kontrast:",0
;ScrS7_txt2:	.db   0, 16, 8,1,"1 - cs�kkent         3 - n�vel",0,0
ScrS7_txt2:	.db   0, 16, 8,1,"1 - zmen",css,"uje      3 - zv�e",css,"uje",0,0
;ScrS7_txt3:	.db   0, 28, 8,1,"H�m�rs�klet:",0,0
ScrS7_txt3:	.db   0, 28, 8,1,"Temp.:",0,0
;ScrS7_txt4:	.db   0, 40, 8,1,"7 - k cs�kkent     9 - k n�vel",0,0
ScrS7_txt4:	.db   0, 40, 8,1,"7 - k zmen",css,"uje    9 - k zv�e",css,"uje",0,0
;--------------------------------------Szerviz:Testreszab�s
;Szoveg stuct:	.db x,y,width,table,str
;ScrS8txtCIM:	.db   0,  0, 8,1,"Testre szab�s:",0,0
ScrS8txtCIM:	.db   0,  0, 8,1,"Prisp�sobenie:",0,0
;ScrS8txtKMBENOV:.db   0, 16, 8,1,"1 - Km bek�r�s: BE-n�vekv�",0,0
ScrS8txtKMBENOV:.db   0, 16, 8,1,"1 - stav Km   : DO-rast�ci",0,0
;ScrS8txtKMBE:	.db   0, 16, 8,1,"1 - Km bek�r�s: BE",0,0
ScrS8txtKMBE:	.db   0, 16, 8,1,"1 - stav Km   : DO",0,0
;ScrS8txtKMKI:	.db   0, 16, 8,1,"1 - Km bek�r�s: KI",0,0
ScrS8txtKMKI:	.db   0, 16, 8,1,"1 - stav Km   : Z",0
;ScrS8txtMENLBE:.db   0, 28, 8,1,"2 - Menetlev�l bek�r�s: BE",0,0
ScrS8txtMENLBE:	.db   0, 28, 8,1,"2 - pr",hi,"jem vlakopisu: DO",0,0
;ScrS8txtMENLKI:.db   0, 28, 8,1,"2 - Menetlev�l bek�r�s: KI",0,0
ScrS8txtMENLKI:	.db   0, 28, 8,1,"2 - pr",hi,"jem vlakopisu: Z",0
;ScrS8txtUZEMBE:.db   0, 40, 8,1,"3 - �zem�ra bek�r�s: BE",0
ScrS8txtUZEMBE:	.db   0, 40, 8,1,"3 - stav prev�dzkovej hod.: DO",0,0
;ScrS8txtUZEMKI:.db   0, 40, 8,1,"3 - �zem�ra bek�r�s: KI",0
ScrS8txtUZEMKI:	.db   0, 40, 8,1,"3 - stav prev�dzkovej hod.: Z",0
;--------------------------------------Szerviz:V�ltoz�k
;Szoveg stuct:	.db x,y,width,table,str
;ScrS9_txt1:	.db   0,  0, 8,1,"V�ltoz�k kijelz�se:",0
ScrS9_txt1:	.db   0,  0, 8,1,"Vysignalizovania zmien:",0
;ScrS9_txt2:	.db   0, 20, 8,1,"Fejleszt�s alatt",0,0
ScrS9_txt2:	.db   0, 20, 8,1,"Pod rekon",css,"trukciou",0,0
;--------------------------------------Szerviz:Rendszer
;Szoveg stuct:	.db x,y,width,table,str
;ScrS10_txt1:	.db   0,  0, 8,1,"Rendszer:",0
ScrS10_txt1:	.db   0,  0, 8,1,"System:",0
;ScrS10_txt2:	.db   0, 20, 8,1,"Fejleszt�s alatt",0,0
ScrS10_txt2:	.db   0, 20, 8,1,"Pod rekon",css,"trukciou",0,0
;--------------------------------------Szerviz:OraBe
;Szoveg stuct:	.db x,y,width,table,str
;======================================END
