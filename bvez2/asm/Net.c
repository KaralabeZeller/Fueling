;--------------------------------------
; BENZIN soros (AtMEGA103-6Mhz)
;--------------------------------------
;Módosítva: 2003.05.05.
;======================================Int-5ms
;BENZIN SOROS NETPC-COMMAND csomag (RECEIVE-SEND 63byte block)
;======================================Int-5msec
;ciklikus vevõ block ellenõrzés	Used:a,b,c,x,y,z
Net_Ciklus:	lds	a,NetRx+TIMEOUT
		cpi	a,NET_TIMEOUT
		brcc	Net_BlkEnd	;if(timeout)error
		inc	a
		sts	NetRx+TIMEOUT,a
Net_ShiftBack:	lds	a,NetRx+POS
		cpi	a,5
		brcs	Net_BlkRet	;if(SR_pos<5)ret
		lds	a,NetRxBuf
		cpi	a,0xa5
		brne	Net_ShiftLe	;if(elsõ!=0xa5) shiftle()

		lds	b,NetRxBuf+1	;db
		cpi	b,NET_BUFMAX-2
		brcc	Net_BlkEnd	;if(db>=126)error
		lds	a,NetRx+POS
		inc	b
		cp	a,b
		brcs	Net_BlkRet	;if(db>RxSpos)var

		ldiZ	NetRxBuf+1	;a block megjött
		clrX
		clr	c
		subi	b,2+1		;a szumma byteok nélkül
Net_BlkSumma:	ld	a,z+
		add	xl,a		;summa+=vett byte
		adc	xh,c
		dec	b
		brne	Net_BlkSumma	;while(db>0)
		ld	yh,z+
		ld	yl,z+		;az eredeti summa
		cp	yh,xh
		brne	Net_BlkEnd
		cp	yl,xl
		brne	Net_BlkEnd
		rcall	Net_Command	;a block értékelése
Net_BlkEnd:	clr	a
		sts	NetRx+TIMEOUT,a
		sts	NetRx+POS,a
Net_BlkRet:	ret
;--------------------------------------
Net_ShiftLe:	ldiZ	NetRxBuf
		ldi	b,126
Net_ShiftLe_1:	ldd	a,z+1
		st	z+,a
		dec	b
		brne	Net_ShiftLe_1
		cli
		lds	a,NetRx+POS
		dec	a
		sts	NetRx+POS,a
		sei
		rjmp	Net_ShiftBack
;--------------------------------------Int-5ms	#kb.15u
Net_Command:	ldi	a,100
		mov	NetBusy,a	;foglalt max.0,5 mp-re
		clr	a
		sts	NetTxDb,a	;Stop adás
		sts	NetTxPos,a
		ldiZ	NetTxBuf
		ldi	b,0xcc
		st	z+,b		;TxSbuf[0]=0xcc
		ldi	b,0xa5
		st	z+,b		;TxSbuf[1]=0xa5
		lds	a,NetRxBuf+2	;parancs byte
		cpi	a,S_RDRAM	;read ram
		breq	Net_RdRam	;(12,AdrH,AdrL,Len)			#183u
		cpi	a,S_WRRAM	;write ram
		breq	Net_WrRam	;(14,AdrH,AdrL,Len,Data[240])	#147u
		cpi	a,S_RDEPR	;read eeprom
		brne	Net_comm_c2	;(17,AdrH,AdrL,Len)			#298u
		rjmp	Net_RdEpr
Net_comm_c2:	cpi	a,S_WREPR	;write eeprom
		brne	Net_comm_c3
		rjmp	Net_WrEpr	;(18,AdrH,AdrL,Len,Data[240])	#152u
Net_comm_c3:	cpi	a,S_RDFLS	;read flash
		brne	Net_comm_c4
		rjmp	Net_RdFls	;(1b,Page,AdrH,AdrL,Len)		#396u
Net_comm_c4:	cpi	a,S_WRFLS	;write flash
		brne	Net_comm_c5
		rjmp	Net_WrFls	;(1d,Page,AdrH,AdrL,Len,Data[240])
Net_comm_c5:	;cpi	a,S_CLFLS	;clr flash
		;brne	Net_ret
		;rjmp	Net_ClrFls	;(1e)
Net_Ret:	clr	NetBusy
		ret
;--------------------------------------Int-5ms
; S_RDRAM	=0x12 ;0010-RD_RAM 12,AH,AL,Len	->12,AH,AL,D[1-48]
Net_RdRam:				;z=TxSbuf+2
		ldsY	NetRxBuf+3	;ram address (h,l)
		lds	a,NetRxBuf+5	;ram byte count (max48)
		cpi	a,NET_DATMAX+1
		brcc	Net_Ret
		mov	xl,a
		subi	xl,-6
		st	z+,xl		;TxSbuf[2]=BlkLen=a+6
		push	xl
		rcall	Ser_RdRam
		pop	a
		subi	a,-2		;0xcc,0xa5 miatt +2
		sts	NetTxDb,a
		rjmp	Net_Ret
;--------------------------------------Int-5ms
; S_WRRAM	=0x14 ;0100-WR_RAM 14,AH,AL,Len,D[247]	->14,AH,AL,Len
Net_WrRam:	ldiY	NetRxBuf+3	;z=TxSbuf+2
		ld	xh,y+		;ram address high
		ld	xl,y+		;ram address low
		ld	a,y+		;ram byte count
		cpi	a,NET_DATMAX+1
		brcc	Net_Ret		;if(len>max)error
		rcall	Ser_WrRam
		lds	a,NetRxBuf+3	;AddrH
		st	z+,a		;ST_buf[4]=AddrH
		add	xl,a
		adc	xh,c
		lds	a,NetRxBuf+4	;AddrL
		st	z+,a		;ST_buf[5]=AddrL
		add	xl,a
		adc	xh,c
		lds	a,NetRxBuf+5	;Len
		st	z+,a		;ST_buf[6]=Len
		add	xl,a
		adc	xh,c
		st	z+,xh
		st	z+,xl
		ldi	a,2+1+1+3+2
		sts	NetTxDb,a
		rjmp	Net_Ret
;--------------------------------------Int-5ms
; S_RDEPR	=0x17 ;0111-RD_EPR 17,AH,AL,Len		->17,AH,AL,D[1-248]
Net_RdEpr:				;z=TxSbuf+2
		lds	a,EEsyscnt
		tst	a
		brne	Net_RdEpr_Ret	;if(vanmég)noválasz
		lds	a,EEpccnt
		tst	a
		brne	Net_RdEpr_Ret	;if(vanmég)noválasz
		sbic	EECR,EEWE
Net_RdEpr_Ret:	rjmp	Net_Ret		;if(foglalt)noválasz
		ldsY	NetRxBuf+3	;ram address (h,l)
		lds	a,NetRxBuf+5	;ram byte count
		cpi	a,NET_DATMAX+1
		brcc	Net_RdEpr_Ret	;if(len>max)ret
		mov	xl,a
		subi	xl,-6
		st	z+,xl		;TxSbuf[2]=BlkLen=a+6
		push	xl
		rcall	Ser_RdEpr
		pop	a
		subi	a,-2		;0xcc,0xa5 miatt +2
		sts	NetTxDb,a
		rjmp	Net_Ret
;--------------------------------------Int-5ms
; S_WREPR	=0x18 ;1000-WR_EPR 18,AH,AL,Len,D[247]	->18,AH,AL,Len
Net_WrEpr:				;z=ST_buf+2
		lds	a,EEpccnt
		tst	a
		breq	Net_WrEpr_Ok	;if(vanmég)noválasz
Net_WrEpr_Ret:	rjmp	Net_Ret		;if(foglalt)noválasz
Net_WrEpr_Ok:	ldiY	NetRxBuf+3
		ld	xh,y+		;address high
		ld	xl,y+		;address low
		ld	a,y+		;byte count
		cpi	a,NET_DATMAX+1
		brcc	Net_WrEpr_Ret	;if(len>max)ret
		rcall	Ser_WrEpr
		lds	a,NetRxBuf+3	;AddrH
		st	z+,a		;ST_buf[4]=AddrH
		add	xl,a
		adc	xh,c
		lds	a,NetRxBuf+4	;AddrL
		st	z+,a		;ST_buf[5]=AddrL
		add	xl,a
		adc	xh,c
		lds	a,NetRxBuf+5	;Len
		st	z+,a		;ST_buf[6]=Len
		add	xl,a
		adc	xh,c
		st	z+,xh
		st	z+,xl
		ldi	a,2+1+1+3+2
		sts	NetTxDb,a
		rjmp	Net_Ret
;--------------------------------------Int-5ms
; S_RDFLS	1b,BlkH,BlkL,RecNum -> 1b,BlkH,BlkL,RecNum,D[16]
Net_RdFls:	sbrc	Sys,SYS_FLS	;z=ST_buf+2
		rjmp	Net_Ret		;if(foglalt)ret
		lds	a,FlsNetCnt
		tst	a
		brne	Net_RdFlsErr	;if(Cnt!=0)még tele van
		
		ldsY	NetRxBuf+3	;Blk
		lds	b,NetRxBuf+5	;RecNum
		ldi	xl,1+4+16+2
		st	z+,xl		;TxSbuf[2]=BlkLen
		rcall	Ser_RdFls
		brts	Net_RdFlsErr

		ldiZ	F1RxBuf+1
		ldiY	NetTxBuf+7
		ldi	b,16
Net_RdFls_2:	ld	a,z+		;copy RAM
		st	y+,a
		dec	b
		brne	Net_RdFls_2

		ldiY	NetTxBuf+2
		clrX			;x=szumma
		clr	c
		ldi	b,16+5
Net_RdFls_3:	ld	a,y+		;read RAM
		add	xl,a
		adc	xh,c
		dec	b
		brne	Net_RdFls_3
		st	y+,xh		;szumma
		st	y+,xl

		ldi	a,2+1+4+16+2	;0xcc,0xa5 miatt +2
		sts	NetTxDb,a
Net_RdFlsErr:	rjmp	Net_Ret
;--------------------------------------Int-5ms
;S_WRFLS=0x1d ;1101-WR_FLS 1d,Page,AH,AL,D[16]	->1d,Pg,AH,Al
Net_WrFls:	lds	a,FlsNetCnt
		tst	a
		brne	Net_WrFls_Err	;if(Cnt!=0)még tele van
		lds	a,NetRxBuf+1	;Len
		cpi	a,1+1+48+2
		brne	Net_WrFls_Err	;if(len!=48)error
		ldiX	NetRxBuf+3
		rcall	Ser_CardJo_e
		brts	Net_WrFls_Err	;if(kártyaszumma nemjó)eldob
		ldiY	NetRxBuf+3
		ldiX	FlsNetTar	;hova
		rcall	Ser_WrFls
		ldi	a,48
		sts	FlsNetCnt,a	;db
		ldi	a,2+1+1+2
		sts	NetTxDb,a
Net_WrFls_Err:	rjmp	Net_Ret
;======================================END
