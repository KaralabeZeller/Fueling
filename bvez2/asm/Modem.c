;--------------------------------------
; BENZIN MODEM soros (AtMEGA103-6Mhz)
;--------------------------------------
;Módosítva: 2002.09.28.
;--------------------------------------
.equ	MOD_VALASZ	=64	;max. válasz hossza
.equ	MODTIM_OK1	=5	;mp	AT-ra válasz vár
.equ	MODTIM_STR1	=10	;mp	STR1 küld
.equ	MODTIM_OK2	=10	;mp	STR1-re válasz vár
.equ	MODTIM_STR2	=10	;mp	STR2 küld
.equ	MODTIM_OK3	=10	;mp	STR2-re válasz vár
.equ	MODTIM_RING	=60	;mp	RING vár
.equ	MODCNT_RING	=3	;	hanyadik csengetésre felvesz
.equ	MODTIM_RINGTIM	=10	;mp	csöngetések közötti idõ
.equ	MODTIM_CONNECT	=60	;mp	CONNECT vár
.equ	MODTIM_BIN	=30	;mp	no jó blokk -> HangUp
.equ	MODTIM_UJRA	=10	;mp	HangUp után újra AT
;--------------------------------------munkafázisok
;	C_MOD_AT	=0	;AT ki - itt van-e?
.equ	C_MOD_OK1	=1	;OK be - itt van
.equ	C_MOD_STR1	=2	;STR1 ki - felprogram
.equ	C_MOD_OK2	=3	;OK be - program OK
.equ	C_MOD_STR2	=4	;STR2 ki - GSM creg
.equ	C_MOD_OK3	=5	;OK be - CREG ok
.equ	C_MOD_RING	=6	;RING be - csengõre vár
.equ	C_MOD_CONNECT	=7	;CONNECT be - bináris mehet
.equ	C_MOD_BINARY	=10	;bináris mód
;======================================Int-5ms
;BENZIN SOROS MODEMPC-COMMAND csomag (RECEIVE-SEND 63byte block)
;======================================Int-5msec
Mod_Ciklus:	lds	a,ModemTim
		subi	a,1
		brcs	Mod_TxtCiklTim	;if(Tim==0)go
		sts	ModemTim,a
		lds	a,ModemVez
		cpi	a,10
		brcs	Mod_TxtRet	;if(Stat<10)ret
		rjmp	Mod_BinCikl
Mod_TxtCiklTim:	ldi	a,200		;---1mp
		sts	ModemTim,a
		lds	a,ModemWait
		subi	a,1
		brcs	Mod_TxtWait
		sts	ModemWait,a	;if(Wait>0)Wait--
Mod_TxtWait:
		lds	a,ModemVez
		tst	a
		breq	Mod_AT		;AT kérdez
		cpi	a,C_MOD_OK1
		breq	Mod_OK1		;OK?->wait
		cpi	a,C_MOD_STR1
		brne	Mod_TxtNoStr1
		rjmp	Mod_STR1	;String1 ki
Mod_TxtNoStr1:	cpi	a,C_MOD_OK2
		brne	Mod_TxtNoOk2
		rjmp	Mod_OK2		;OK?->wait
Mod_TxtNoOk2:	cpi	a,C_MOD_STR2
		brne	Mod_TxtNoStr2
		rjmp	Mod_STR2	;String2 ki
Mod_TxtNoStr2:	cpi	a,C_MOD_OK3
		brne	Mod_TxtNoOk3
		rjmp	Mod_OK3		;OK?->wait
Mod_TxtNoOk3:	cpi	a,C_MOD_RING
		brne	Mod_TxtNoRing
		rjmp	Mod_RING	;RING?->ATA
Mod_TxtNoRing:	cpi	a,C_MOD_CONNECT
		brne	Mod_TxtNoConn
		rjmp	Mod_CONNECT	;CON? ->bin(10)
Mod_TxtNoConn:
		cpi	a,C_MOD_BINARY
		brne	Mod_TxtErr
		lds	a,ModemWait
		tst	a
		breq	Mod_BinEnd
		rjmp	Mod_BinCikl	;binary
Mod_BinEnd:	rjmp	Mod_HANG
Mod_TxtErr:	clr	a
		sts	ModemVez,a	;if(érvénytelen)Stat=0
Mod_TxtRet:	ret
;--------------------------------------Int-5msec		
Mod_AT:		ldi	a,'A'		;AT kérdez
		sts	ModTxBuf,a
		ldi	a,'T'
		sts	ModTxBuf+1,a
		ldi	a,13
		sts	ModTxBuf+2,a
		clr	a
		sts	ModTxPos,a
		ldi	a,3
		sts	ModTxDb,a
		ldi	a,C_MOD_OK1
		sts	ModemVez,a
		ldi	a,MODTIM_OK1
		sts	ModemWait,a
		rjmp	Mod_End
;--------------------------------------Int-5msec
Mod_OK1:	ldiZ	ModRxBuf	;OK?
		ldi	b,MOD_VALASZ
Mod_OK1_1:	ld	a,z+
		cpi	a,'O'
		brne	Mod_OK1_tova
		ld	a,z
		cpi	a,'K'
		breq	Mod_OK1_OK	;megvan
Mod_OK1_tova:	dec	b
		brne	Mod_OK1_1
		lds	a,ModemWait
		tst	a
		breq	Mod_OK1_Wait
		ret
Mod_OK1_Wait:	clr	a		;if(lejárt)Vez=0
		sts	ModemVez,a
		rjmp	Mod_End
Mod_OK1_OK:	ldi	a,C_MOD_STR1	;Megjött
		sts	ModemVez,a
		ldi	a,MODTIM_STR1
		sts	ModemWait,a
		rjmp	Mod_End
;--------------------------------------Int-5msec
Mod_STR1:	ldiX	EE_ModInit1	;STR1 kérdez
		ldiY	ModTxBuf
		clr	b
Mod_STR1_ad:	_EErd_XtoA
		tst	a
		breq	Mod_STR1_end	;if(0)vége
		cpi	a,13
		breq	Mod_STR1_end	;if(13)vége
		st	y+,a
		adiw	xl,1
		inc	b
		cpi	b,30		;max30 byte
		brcs	Mod_STR1_ad
Mod_STR1_end:	ldi	a,13		;záró CR
		st	y+,a
		clr	a
		inc	b
		sts	ModTxPos,a
		sts	ModTxDb,b

		ldi	a,C_MOD_OK2
		sts	ModemVez,a
		ldi	a,MODTIM_OK2
		sts	ModemWait,a
		rjmp	Mod_End
;--------------------------------------Int-5msec
Mod_OK2:	ldiZ	ModRxBuf	;OK?
		ldi	b,MOD_VALASZ
Mod_OK2_1:	ld	a,z+
		cpi	a,'O'
		brne	Mod_OK2_tova
		ld	a,z
		cpi	a,'K'
		breq	Mod_OK2_OK	;megvan
Mod_OK2_tova:	dec	b
		brne	Mod_OK2_1
		lds	a,ModemWait
		tst	a
		breq	Mod_OK2_Wait
		ret
Mod_OK2_Wait:	clr	a		;if(lejárt)Vez=0
		sts	ModemVez,a
		rjmp	Mod_End
Mod_OK2_OK:	ldi	a,C_MOD_STR2	;megvan
		sts	ModemVez,a
		ldi	a,MODTIM_STR2
		sts	ModemWait,a
		rjmp	Mod_End
;--------------------------------------Int-5msec
Mod_STR2:	ldiX	EE_ModInit2	;STR2 kérdez	(AT +CREG=1 ->OK)
		ldiY	ModTxBuf
		clr	b
Mod_STR2_ad:	_EErd_XtoA
		tst	a
		breq	Mod_STR2_end	;if(0)vége
		cpi	a,13
		breq	Mod_STR2_end	;if(13)vége
		st	y+,a
		adiw	xl,1
		inc	b
		cpi	b,30		;max30 byte
		brcs	Mod_STR2_ad
Mod_STR2_end:	ldi	a,13		;záró CR
		st	y+,a
		inc	b
		clr	a
		sts	ModTxPos,a
		sts	ModTxDb,b

		ldi	a,C_MOD_OK3
		sts	ModemVez,a
		ldi	a,MODTIM_OK3
		sts	ModemWait,a
		rjmp	Mod_End
;--------------------------------------Int-5msec
Mod_OK3:	ldiZ	ModRxBuf	;OK?
		ldi	b,MOD_VALASZ
Mod_OK3_1:	ld	a,z+
		cpi	a,'O'
		brne	Mod_OK3_tova
		ld	a,z
		cpi	a,'K'
		breq	Mod_OK3_OK	;megvan
Mod_OK3_tova:	dec	b
		brne	Mod_OK3_1
		lds	a,ModemWait
		tst	a
		breq	Mod_OK3_Wait
		ret
Mod_OK3_Wait:	clr	a		;if(lejárt)Vez=0
		sts	ModemVez,a
		rjmp	Mod_End
Mod_OK3_OK:	ldi	a,C_MOD_RING
		sts	ModemVez,a
		clr	a
		sts	ModemRingCnt,a
		ldi	a,MODTIM_RING
		sts	ModemWait,a
		rjmp	Mod_End
;--------------------------------------Int-5msec
Mod_RING:	ldiZ	ModRxBuf	;RIN?
		ldi	b,MOD_VALASZ
Mod_RING_1:	ld	a,z+
		cpi	a,'R'
		brne	Mod_RING_tova
		ld	a,z
		cpi	a,'I'
		brne	Mod_RING_tova
		ldd	a,z+1
		cpi	a,'N'
		breq	Mod_RING_ok
Mod_RING_tova:	dec	b
		brne	Mod_RING_1
		lds	a,ModemWait
		tst	a
		breq	Mod_RING_W
		ret
Mod_RING_W:	clr	a		;if(lejárt)Vez=0
		sts	ModemVez,a
		rjmp	Mod_End
Mod_RING_ok:	lds	a,ModemRingCnt
		inc	a
		sts	ModemRingCnt,a
		cpi	a,MODCNT_RING
		brcc	Mod_RING_ring
		ldi	a,MODTIM_RINGTIM
		sts	ModemWait,a
		rjmp	Mod_End
Mod_RING_ring:
		ldi	a,'A'		;ATA kérdez
		sts	ModTxBuf,a
		ldi	a,'T'
		sts	ModTxBuf+1,a
		ldi	a,'A'
		sts	ModTxBuf+2,a
		ldi	a,13
		sts	ModTxBuf+3,a
		clr	a
		sts	ModTxPos,a
		ldi	a,4
		sts	ModTxDb,a
		ldi	a,C_MOD_CONNECT
		sts	ModemVez,a
		ldi	a,MODTIM_CONNECT
		sts	ModemWait,a
		rjmp	Mod_End
;--------------------------------------Int-5msec
Mod_CONNECT:	ldiZ	ModRxBuf	;CON?
	ldiY	TstModem
	ldi	b,64
tst1:	ld	a,z+
	st	y+,a
	dec	b
	brne	tst1
	ldiZ	ModRxBuf	;CON?

		ldi	b,MOD_VALASZ
Mod_CONN_1:	ld	a,z+
		cpi	a,'C'
		brne	Mod_CONN_tova
		ld	a,z
		cpi	a,'O'
		brne	Mod_CONN_tova
		ldd	a,z+1
		cpi	a,'N'
		breq	Mod_CONN_ok
Mod_CONN_tova:	dec	b
		brne	Mod_CONN_1
		lds	a,ModemWait
		tst	a
		breq	Mod_CONN_W
		ret
Mod_CONN_W:	clr	a		;if(lejárt)Vez=0
		sts	ModemVez,a
		rjmp	Mod_End
Mod_CONN_ok:	
		ldi	a,C_MOD_BINARY	;binary
		sts	ModemVez,a
		ldi	a,MODTIM_BIN
		sts	ModemWait,a
		rjmp	Mod_End
;--------------------------------------Int-5msec
Mod_HANG:	ldi	a,'+'		;+++ kérdez
		sts	ModTxBuf,a
		sts	ModTxBuf+1,a
		sts	ModTxBuf+2,a
		ldi	a,13
		sts	ModTxBuf+3,a
		clr	a
		sts	ModTxPos,a
		ldi	a,4
		sts	ModTxDb,a
		ldi	a,0
		sts	ModemVez,a
		ldi	a,MODTIM_UJRA
		sts	ModemWait,a	;10s
;		rjmp	Modem_End
;--------------------------------------Int-5msec
Mod_End:	clr	a
		ldiZ	ModRxBuf
		ldi	b,MOD_VALASZ
Mod_End_1:	st	z+,a		;clr Rx buffer
		dec	b
		brne	Mod_End_1
		rjmp	Mod_BlkEnd	;reset vevõ
;--------------------------------------Int-5msec
;ciklikus vevõ block ellenõrzés	Used:a,b,c,x,y,z
Mod_BinCikl:	lds	a,ModRx+TIMEOUT
		cpi	a,MOD_TIMEOUT
		brcc	Mod_BlkEnd	;if(timeout)error
		inc	a
		sts	ModRx+TIMEOUT,a
Mod_ShiftBack:	lds	a,ModRx+POS
		cpi	a,5
		brcs	Mod_BlkRet	;if(SR_pos<5)ret
		lds	a,ModRxBuf
		cpi	a,0xa5
		brne	Mod_ShiftLe	;if(elsõ!=0xa5) shiftle()
		
		lds	b,ModRxBuf+1	;db
		cpi	b,MOD_BUFMAX-2
		brcc	Mod_BlkEnd	;if(db>=62)error
		lds	a,ModRx+POS
		inc	b
		cp	a,b
		brcs	Mod_BlkRet	;if(db>RxSpos)var

		ldiZ	ModRxBuf+1	;a block megjött
		clrX
		clr	c
		subi	b,2+1		;a szumma byteok nélkül
Mod_BlkSumma:	ld	a,z+
		add	xl,a		;summa+=vett byte
		adc	xh,c
		dec	b
		brne	Mod_BlkSumma	;while(db>0)
		ld	yh,z+
		ld	yl,z+		;az eredeti summa
		cp	yh,xh
		brne	Mod_BlkEnd
		cp	yl,xl
		brne	Mod_BlkEnd
		rcall	Mod_Command	;a block értékelése
Mod_BlkEnd:	clr	a
		sts	ModRx+TIMEOUT,a
		sts	ModRx+POS,a
Mod_BlkRet:	ret
;--------------------------------------Int-5msec
Mod_ShiftLe:	ldiZ	ModRxBuf
		ldi	b,126
Mod_ShiftLe_1:	ldd	a,z+1
		st	z+,a
		dec	b
		brne	Mod_ShiftLe_1
		cli
		lds	a,ModRx+POS
		dec	a
		sts	ModRx+POS,a
		sei
		rjmp	Mod_ShiftBack
;--------------------------------------Int-5ms	#kb.15u
Mod_Command:	ldi	a,MODTIM_BIN
		sts	ModemWait,a
		ldi	a,100
		mov	ModemBusy,a	;foglalt max.0,5 mp-re
		clr	a
		sts	ModTxDb,a	;Stop adás
		sts	ModTxPos,a
		ldiZ	ModTxBuf
		ldi	b,0xcc
		st	z+,b		;TxSbuf[0]=0xcc
		ldi	b,0xa5
		st	z+,b		;TxSbuf[1]=0xa5
		lds	a,ModRxBuf+2	;parancs byte
		cpi	a,S_RDRAM	;read ram
		breq	Mod_RdRam	;(12,AdrH,AdrL,Len)			#183u
		cpi	a,S_WRRAM	;write ram
		breq	Mod_WrRam	;(14,AdrH,AdrL,Len,Data[240])	#147u
		cpi	a,S_RDEPR	;read eeprom
		brne	Mod_comm_c2	;(17,AdrH,AdrL,Len)			#298u
		rjmp	Mod_RdEpr
Mod_comm_c2:	cpi	a,S_WREPR	;write eeprom
		brne	Mod_comm_c3
		rjmp	Mod_WrEpr	;(18,AdrH,AdrL,Len,Data[240])	#152u
Mod_comm_c3:	cpi	a,S_RDFLS	;read flash
		brne	Mod_comm_c4
		rjmp	Mod_RdFls	;(1b,Page,AdrH,AdrL,Len)		#396u
Mod_comm_c4:	cpi	a,S_WRFLS	;write flash
		brne	Mod_comm_c5
		rjmp	Mod_WrFls	;(1d,Page,AdrH,AdrL,Len,Data[240])
Mod_comm_c5:	;cpi	a,S_CLFLS	;clr flash
		;brne	Mod_ret
		;rjmp	Mod_ClrFls	;(1e)
Mod_Ret:	clr	ModemBusy
		ret
;--------------------------------------Int-5ms
; S_RDRAM	=0x12 ;0010-RD_RAM 12,AH,AL,Len	->12,AH,AL,D[1-48]
Mod_RdRam:				;z=TxSbuf+2
		ldsY	ModRxBuf+3	;ram address (h,l)
		lds	a,ModRxBuf+5	;ram byte count (max48)
		cpi	a,MOD_DATMAX+1
		brcc	Mod_Ret
		mov	xl,a
		subi	xl,-6
		st	z+,xl		;TxSbuf[2]=BlkLen=a+6
		push	xl
		rcall	Ser_RdRam
		pop	a
		subi	a,-2		;0xcc,0xa5 miatt +1
		sts	ModTxDb,a
		rjmp	Mod_Ret
;--------------------------------------Int-5ms
; S_WRRAM	=0x14 ;0100-WR_RAM 14,AH,AL,Len,D[247]	->14,AH,AL,Len
Mod_WrRam:	ldiY	ModRxBuf+3	;z=TxSbuf+2
		ld	xh,y+		;ram address high
		ld	xl,y+		;ram address low
		ld	a,y+		;ram byte count
		cpi	a,MOD_DATMAX+1
		brcc	Mod_Ret		;if(len>max)error
		rcall	Ser_WrRam
		lds	a,ModRxBuf+3	;AddrH
		st	z+,a		;ST_buf[4]=AddrH
		add	xl,a
		adc	xh,c
		lds	a,ModRxBuf+4	;AddrL
		st	z+,a		;ST_buf[5]=AddrL
		add	xl,a
		adc	xh,c
		lds	a,ModRxBuf+5	;Len
		st	z+,a		;ST_buf[6]=Len
		add	xl,a
		adc	xh,c
		st	z+,xh
		st	z+,xl
		ldi	a,2+1+1+3+2
		sts	ModTxDb,a
		rjmp	Mod_Ret
;--------------------------------------Int-5ms
; S_RDEPR	=0x17 ;0111-RD_EPR 17,AH,AL,Len		->17,AH,AL,D[1-248]
Mod_RdEpr:				;z=TxSbuf+2
		lds	a,EEsyscnt
		tst	a
		brne	Mod_RdEpr_Ret	;if(vanmég)noválasz
		lds	a,EEpccnt
		tst	a
		brne	Mod_RdEpr_Ret	;if(vanmég)noválasz
		sbic	EECR,EEWE
Mod_RdEpr_Ret:	rjmp	Mod_Ret		;if(foglalt)noválasz
		ldsY	ModRxBuf+3	;ram address (h,l)
		lds	a,ModRxBuf+5	;ram byte count
		cpi	a,MOD_DATMAX+1
		brcc	Mod_RdEpr_Ret	;if(len>max)ret
		mov	xl,a
		subi	xl,-6
		st	z+,xl		;TxSbuf[2]=BlkLen=a+6
		push	xl
		rcall	Ser_RdEpr
		pop	a
		subi	a,-2		;0xcc,0xa5 miatt +2
		sts	ModTxDb,a
		rjmp	Mod_Ret
;--------------------------------------Int-5ms
; S_WREPR	=0x18 ;1000-WR_EPR 18,AH,AL,Len,D[247]	->18,AH,AL,Len
Mod_WrEpr:				;z=ST_buf+2
		lds	a,EEpccnt
		tst	a
		breq	Mod_WrEpr_Ok
Mod_WrEpr_Ret:	rjmp	Mod_Ret		;if(foglalt)noválasz
Mod_WrEpr_Ok:	ldiY	ModRxBuf+3
		ld	xh,y+		;address high
		ld	xl,y+		;address low
		ld	a,y+		;byte count
		cpi	a,MOD_DATMAX+1
		brcc	Mod_WrEpr_Ret	;if(len>max)ret
		rcall	Mod_WrEpr
		lds	a,ModRxBuf+3	;AddrH
		st	z+,a		;ST_buf[4]=AddrH
		add	xl,a
		adc	xh,c
		lds	a,ModRxBuf+4	;AddrL
		st	z+,a		;ST_buf[5]=AddrL
		add	xl,a
		adc	xh,c
		lds	a,ModRxBuf+5	;Len
		st	z+,a		;ST_buf[6]=Len
		add	xl,a
		adc	xh,c
		st	z+,xh
		st	z+,xl
		ldi	a,2+1+1+3+2
		sts	ModTxDb,a
		rjmp	Mod_Ret
;--------------------------------------Int-5ms
; S_RDFLS	1b,Page,AH,AL,Len	->1b,Pg,AH,AL,D[16]
Mod_RdFls:	sbrc	Sys,SYS_FLS	;z=ST_buf+2
		rjmp	Mod_Ret		;if(foglalt)ret
		lds	a,FlsModCnt
		tst	a
		brne	Mod_RdFlsErr	;if(Cnt!=0)még tele van
		
		ldsY	ModRxBuf+3	;Blk
		lds	b,ModRxBuf+5	;RecNum
		ldi	xl,1+4+16+2
		st	z+,xl		;TxSbuf[2]=BlkLen
		rcall	Ser_RdFls
		brts	Mod_RdFlsErr

		ldiZ	F1RxBuf+1
		ldiY	ModTxBuf+7
		ldi	b,16
Mod_RdFls_2:	ld	a,z+		;copy RAM
		st	y+,a
		dec	b
		brne	Mod_RdFls_2

		ldiY	ModTxBuf+2
		clrX			;x=szumma
		clr	c
		ldi	b,16+5
Mod_RdFls_3:	ld	a,y+		;read RAM
		add	xl,a
		adc	xh,c
		dec	b
		brne	Mod_RdFls_3
		st	y+,xh		;szumma
		st	y+,xl

		ldi	a,2+1+4+16+2	;0xcc,0xa5 miatt +1
		sts	ModTxDb,a
Mod_RdFlsErr:	rjmp	Mod_Ret
;--------------------------------------Int-5ms
;S_WRFLS=0x1d ;1101-WR_FLS 1d,Page,AH,AL,D[16]	->1d,Pg,AH,Al
Mod_WrFls:	lds	a,FlsModCnt
		tst	a
		brne	Mod_WrFls_Err	;if(Cnt!=0)még tele van
		lds	a,ModRxBuf+1	;Len
		cpi	a,1+1+48+2
		brne	Mod_WrFls_Err	;if(len!=48)error
		ldiX	ModRxBuf+3
		rcall	Ser_CardJo_e
		brts	Mod_WrFls_Err	;if(kártyaszumma nemjó)eldob
		ldiY	ModRxBuf+3
		ldiX	FlsModTar	;hova
		rcall	Ser_WrFls
		ldi	a,48
		sts	FlsModCnt,a	;db
		ldi	a,2+1+1+2
		sts	ModTxDb,a
Mod_WrFls_Err:	rjmp	Mod_Ret
;======================================END
