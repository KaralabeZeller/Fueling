;======================================
; Benzin vezérlõ LCD stringek
;--------------------------------------
.message "Nyelv= Angol"
;TextMaxHossz:		.db    ,   ,  , ,"1...5....0....5....0....5....0",0,0
;--------------------------------------Global
;Szoveg stuct:		.db x,y,width,table,str
TextVISSZA:		.db   1, 52, 8,1,"Back",0,0
TextVISSZARENDBEN:	.db   1, 52, 8,1,"Back                        OK",0,0
;--------------------------------------Fõmenü:Alap
;Szoveg stuct:	.db x,y,width,table,str
ScrA1txt1:	.db 54, 28, 8,1,"  Select pump",0
ScrA1txt2:	.db 50, 42, 8,1,"RATIO HOMINI KFT",0,0
ScrA1txt3:	.db 41, 54, 8,1,"Tel.: 36 1 3063039",0,0
;--------------------------------------Státusz kijelzés
;Szoveg stuct:.db x,y,width,table,str
ScrA2txtKikapcs:.db   1,  1, 8,1,"Switched OFF",0,0
ScrA2txtFejFent:.db   1,  1, 8,1,"Head up",0
ScrA2txtSum1:	.db   1,  1, 8,1,"Head down-Sum1",0,0
ScrA2txtSum2:	.db   1,  1, 8,1,"Head down-Sum2",0,0
ScrA2txtFejLent:.db   1,  1, 8,1,"Head down",0
ScrA2txtTankKi:	.db   1,  1, 8,1,"Refuel-OFF",0,0
ScrA2txtTankBe:	.db   1,  1, 8,1,"Refuel-ON",0
ScrA2txtVlimit:	.db   1,  1, 8,1,"Save: limit",0
ScrA2txtVfej:	.db   1,  1, 8,1,"Save: head",0,0
ScrA2txtVido:	.db   1,  1, 8,1,"Save: time",0,0
ScrA2txtVlopas:	.db   1,  1, 8,1,"Save: steeling!!!",0
ScrA2txtVfesz:	.db   1,  1, 8,1,"Save: voltage error!",0,0
ScrA2txtSlimit:	.db   1,  1, 8,1,"End: limit",0,0
ScrA2txtSfej:	.db   1,  1, 8,1,"End: head",0
ScrA2txtSido:	.db   1,  1, 8,1,"End: time",0
ScrA2txtSlopas:	.db   1,  1, 8,1,"End: steeling!!!",0,0
ScrA2txtSfesz:	.db   1,  1, 8,1,"End: voltage error!",0
ScrA2txtVar:	.db   1,  1, 8,1,"Waiting",0
ScrA2txtError:	.db   1,  1, 8,1,"Bad state!",0,0
;--------------------------------------Kártya bevitel
;Szöveg stuct:.db x,y,width,table,str
ScrA3txtKUT:	.db 10,  1, 8,1,".Pump:",0,0
ScrA3txtHIBA:	.db 80,  1, 8,1,"Card ERROR",0,0
ScrA3txtHINO:	.db 80,  1, 8,1,"           ",0
ScrA3txtCARD2:	.db 80, 13, 8,1,"Insert cards",0,0
ScrA3txtCARD1:	.db 80, 13, 8,1,"Insert card",0
ScrA3txtPIN0:	.db 80, 13, 8,1,"PIN code: ____",0,0
ScrA3txtPIN1:	.db 80, 13, 8,1,"PIN code: *___",0,0
ScrA3txtPIN2:	.db 80, 13, 8,1,"PIN code: **__",0,0
ScrA3txtPIN3:	.db 80, 13, 8,1,"PIN code: ***_",0,0
ScrA3txtPIN4:	.db 80, 13, 8,1,"PIN code: ****",0,0
ScrA3txtNEV:	.db  1, 28, 8,1,"Name:",0
ScrA3txtAUTO:	.db  1, 40, 8,1,"Vehicle:",0,0
;--------------------------------------Km óra bevitel
;Szoveg stuct:	.db x,y,width,table,str
ScrA4txtFoCim:	.db  0,  0, 8,1,"Km indicator:",0
ScrA4txtHiba:	.db  1, 52, 8,1,"It must be increased!",0
;ScrA4txtHiba:	.db  1, 52, 8,1,"It shall not be lower than the previous!",0,0
;TextMaxHossz:	.db    ,  ,  , ,"1...5....0....5....0....5....0",0,0
;--------------------------------------Menetlevél bevitel
;Szoveg stuct:	.db x,y,width,table,str
ScrA5txt1:	.db  0,  0, 8,1,"Way-Bill number:",0,0
;--------------------------------------Tankolhat
;Szoveg stuct:	.db x,y,width,table,str
ScrA6txt0:	.db 30,  6, 8,1,"   Today        . refuel",0,0
ScrA6txt1:	.db 30, 20, 8,1,"Allowed         liters",0,0
ScrA6txt2:	.db 30, 34, 8,1,"                times more",0,0
;ScrA6txt1:	.db 30, 20, 8,1,"ALLOWED TO REFUEL        LITERS",0,0
;--------------------------------------Üzemóra bevitel
;Szoveg stuct:	.db x,y,width,table,str
ScrA7txt1:	.db  0,  0, 8,1,"Operating gauge reading:",0,0
;--------------------------------------Mester kártya bevitel
;Szoveg stuct:	.db x,y,width,table,str
ScrA8txt1:	.db  0,  0, 8,1,"Vehicle card code:",0,0
ScrA8txtKell:	.db  1, 52, 8,1,"Back              Not required",0,0
ScrA8txtTorol:	.db  1, 52, 8,1,"Clear                         ",0,0
ScrA8txtRendben:.db  1, 52, 8,1,"Clear                      OK ",0,0
;--------------------------------------Nyomtatás
;Szoveg stuct:	.db x,y,width,table,str
ScrA9txtFoCim:	.db  0,  0, 8,1,"Printing:",0
PrnTxtInit:	.db 0x1b,0x52,0x02,0

PrnTxtKezd:	.db "Start of meas: ____.__.__ __:__:__",0x0a,0
PrnTxtVege:	.db "End of meas. : ____.__.__ __:__:__",0x0a,0
PrnTxtEmber:	.db "Person            : _____________",0x0a,0,0
PrnTxtRendsz:	.db "Registration num. : _____________",0x0a,0,0
PrnTxtKm:	.db "Kilometre          :   ________ km",0x0a,0
PrnTxtUzemora:	.db "Operating gauge    :   ________ h",0x0a,0,0
PrnTxtMenlev:	.db "Way-Bill           :   ________ ",0x0a,0
PrnTxtSorSzam:	.db "Measurement num. Nr:     _____/_",0x0a,0
PrnTxtOszLit:	.db "Meter reading     V:__________,__l",0x0a,0
PrnTxtOszKomp:	.db "Summarised meas. Vo:__________,__l",0x0a,0
PrnTxtVonal:	.db "---------------------:------------",0x0a,0
PrnTxtLiter:	.db "Measured quantity  Vt: ______,__ l",0x0a,0
PrnTxtHom:	.db "Product temperature t:    ___,_ °C",0x0a,0
PrnTxtMegnev:	.db "Product description  :     Gasolin",0x0a,0
PrnTxtBazisHo:	.db "Base temperature   to:     15,0 °C",0x0a,0
PrnTxtLitKomp:	.db "Quantity at to     Vo: ______,__ l",0x0a,0

PrnTxtClose:	.db 0x0a,0x0a,0x0a,0x0a,0x0a,0x1b,0x6d,0;half cut
;--------------------------------------Hiba:Kártya
;Szoveg stuct:.db x,y,width,table,str
ScrH1txt1:	.db 44,  6, 8,1,"Card ERROR",0,0
;--------------------------------------Hiba:Kimerítve
;Szoveg stuct:.db x,y,width,table,str
ScrH2txt0:	.db 40,  0,10,1,"Allowed daily",0
ScrH2txt1:	.db 40, 16,10,1,"number of refuelling",0,0
ScrH2txt2:	.db 40, 32,10,1,"   eliminated.",0,0
;--------------------------------------Szerviz:Belépés
;Szoveg stuct:	.db x,y,width,table,str
ScrS1txtCIM:	.db  0,  0, 8,1,"Insert service card:",0,0
;--------------------------------------Szerviz
;Szoveg stuct:	.db x,y,width,table,str
ScrS2txt1:	.db   0,  0, 8,1,"Service menu:",0
ScrS2txt2:	.db   0, 14, 8,1,"1-Pumps     2-Card information",0,0
ScrS2txt3:	.db   0, 26, 8,1,"3-Settings  4-Variables",0
ScrS2txt4:	.db   0, 38, 8,1,"5-System",0,0
;--------------------------------------Szervíz:Kútfõk
;Szoveg stuct:	.db x,y,width,table,str
ScrS3txtKUTFOK:	.db   0,  0, 8,1,"Pumps:",0,0
ScrS3txtKUTAKBE:.db   0, 36, 8,1,"Button 1-8 pumps ON/OFF",0
;--------------------------------------Szerviz:Kártyák
;Szoveg stuct:	.db x,y,width,table,str
ScrS4txt1:	.db   0,  0, 8,1,"Card information:",0
ScrS4txt2:	.db   0, 20, 8,1,"1 - Number of Cards",0
ScrS4txtEGY:	.db   0, 36, 8,1,"One-Card system",0
ScrS4txtKET:	.db   0, 36, 8,1,"Two-Card system",0
;--------------------------------------Szerviz:Beállítások
;Szoveg stuct:	.db x,y,width,table,str
ScrS5_txt1:	.db  0,  0, 8,1,"Settings:",0
ScrS5_txt2:	.db  0, 12, 8,1,"1-Display      2-Contrast",0
ScrS5_txt3:	.db  0, 24, 8,1,"3-Time",0,0
ScrS5_txt4:	.db  0, 36, 8,1,"4-Customization",0
;--------------------------------------Szerviz:Beállítás:Literkijelzés
;Szoveg stuct:	.db x,y,width,table,str
ScrS6txtCIM:	.db   0,  0, 8,1,"Display:",0,0
ScrS6txtBE:	.db   0, 20, 8,1,"1 - Litre indication: ON",0,0
ScrS6txtKI:	.db   0, 20, 8,1,"1 - Litre indication: OFF",0
;--------------------------------------Szerviz:Beállítás:Kontraszt
;Szoveg stuct:	.db x,y,width,table,str
ScrS7_txt1:	.db   0,  0, 8,1,"Contrast:",0
ScrS7_txt2:	.db   0, 16, 8,1,"1 - decrease    3 - increase",0,0
ScrS7_txt3:	.db   0, 28, 8,1,"Temperature:",0,0
ScrS7_txt4:	.db   0, 40, 8,1,"7 - k decrease  9 - k increase",0,0
;--------------------------------------Szerviz:Testreszabás
;Szoveg stuct:	.db x,y,width,table,str
ScrS8txtCIM:	.db   0,  0, 8,1,"Customization:",0,0
ScrS8txtKMBENOV:.db   0, 16, 8,1,"1 - Km request: ON-increasing",0
ScrS8txtKMBE:	.db   0, 16, 8,1,"1 - Km request: ON",0,0
ScrS8txtKMKI:	.db   0, 16, 8,1,"1 - Km request: OFF",0
ScrS8txtMENLBE:	.db   0, 28, 8,1,"2 - Way-Bill request: ON",0,0
ScrS8txtMENLKI:	.db   0, 28, 8,1,"2 - Way-Bill request: OFF",0
ScrS8txtUZEMBE:	.db   0, 40, 8,1,"3 - Operating gaugage req.:ON",0
ScrS8txtUZEMKI:	.db   0, 40, 8,1,"3 - Operating gaugage req.:OFF",0,0
;--------------------------------------Szerviz:Változók
;Szoveg stuct:	.db x,y,width,table,str
ScrS9_txt1:	.db   0,  0, 8,1,"Variables display:",0,0
ScrS9_txt2:	.db   0, 20, 8,1,"Under construction",0,0
;--------------------------------------Szerviz:Rendszer
;Szoveg stuct:	.db x,y,width,table,str
ScrS10_txt1:	.db   0,  0, 8,1,"System:",0
ScrS10_txt2:	.db   0, 20, 8,1,"Under construction",0,0
;--------------------------------------Szerviz:OraBe
;Szoveg stuct:	.db x,y,width,table,str
;======================================END
