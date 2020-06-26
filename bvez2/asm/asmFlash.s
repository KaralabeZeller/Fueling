;================================================
; BVEZ2 vezérlõ (dsPIC33GP708-8Mhz)
;================================================
;#include <p33FJ128GP708a.h>
.equ		WR,15
;------------------------------------------------
; 0x000200-0x0002ff = 0x100w = 512byte
; 1 row = 64 instuction = 192 byte	(0x0080w)
; 1 page = 8 row = 512 insturction = 1536 byte (ERASE) (0x0400w)
;------------------------------------------------START section
; page0 = 0x000000-0x0003ff
;   0x000000-0x0001ff - Normal+Alternate Vector table
; page1 = 0x000400-0x0007ff
;================================================
;.section	PgmFlash_L,address(0x000206),code
.section	PgmFlash_L,code
;------------------------------------------------Flash olvasás
.global		_ReadLatch64_L
.align		2
;extern void ReadLatch64_L(int page,int addr);//use:-
_ReadLatch64_L:
	push	TBLPAG
	push	W1
	push	W2
	push	W3

	mov		W0,TBLPAG
	mov		#_FlsRow,W2
	mov		#64,W3
1:	tblrdl	[W1],[W2++]
	tblrdh	[W1++],[W2++]
	dec		W3,W3
	bra		NZ,1b

	pop		W3
	pop		W2
	pop		W1
	pop		TBLPAG
	return
;------------------------------------------------Flash töltés
.global		_WriteLatch64_L
.align		2
;extern void WriteLatch64_L(int page,int addr);//use:-
_WriteLatch64_L:
	push	TBLPAG
	push	W0
	push	W1
	push	W2

	mov		W0,TBLPAG
	mov		#_FlsRow,W2
	mov		#64,W0
1:	tblwtl	[W2++],[W1]
	tblwth	[W2++],[W1++]
	dec		W0,W0
	bra		NZ,1b

	mov		#0x4001,W0			;ROW_WRITE
	mov		W0,NVMCON

	disi	#5
	mov		#0x55,W0            ;Unlock
	mov		W0,NVMKEY
	mov		#0xAA,W0
	mov		W0,NVMKEY
	bset	NVMCON,#WR
	nop							;2nop kötelez?
	nop
2:	btsc	NVMCON,#WR          ;Wait
	bra		2b

	pop		W2
	pop		W1
	pop		W0
	pop		TBLPAG
	return
;//-----------------------------------------------Flash erase
.global		_EraseFls_L
.align		2
;extern void EraseFls_L(int pag,int cim);//use:-
_EraseFls_L:
	push    TBLPAG
	push	W0
	push	W1
	push	W2

	mov     #0x4042,W2			;ROW_ERASE
	mov     W2,NVMCON
	mov     w0,TBLPAG
	tblwtl  w1,[w1]				;select row

	disi	#5
	mov     #0x55,W0			;Unlock
	mov     W0,NVMKEY
	mov     #0xAA,W0
	mov     W0,NVMKEY
	bset    NVMCON,#WR
	nop							;2nop kötelez?
	nop
1:	btsc    NVMCON,#WR
	bra		1b

	pop		W2
	pop		W1
	pop		W0
	pop     TBLPAG
	return
;------------------------------------------------END section
;================================================
.section	PgmFlash_H,address(0x015006),code
;------------------------------------------------Flash olvasás
.global		_ReadLatch64_H
.align		2
;extern void ReadLatch64_H(int page,int addr);//use:-
_ReadLatch64_H:
	push	TBLPAG
	push	W1
	push	W2
	push	W3

	mov		W0,TBLPAG
	mov		#_FlsRow,W2
	mov		#64,W3
1:	tblrdl	[W1],[W2++]
	tblrdh	[W1++],[W2++]
	dec		W3,W3
	bra		NZ,1b

	pop		W3
	pop		W2
	pop		W1
	pop		TBLPAG
	return
;------------------------------------------------Flash töltés
.global		_WriteLatch64_H
.align		2
;extern void WriteLatch64_H(int page,int addr);//use:-
_WriteLatch64_H:
	push	TBLPAG
	push	W0
	push	W1
	push	W2

	mov		W0,TBLPAG
	mov		#_FlsRow,W2
	mov		#64,W0
1:	tblwtl	[W2++],[W1]
	tblwth	[W2++],[W1++]
	dec		W0,W0
	bra		NZ,1b

	mov		#0x4001,W0			;ROW_WRITE
	mov		W0,NVMCON

	disi	#5
	mov		#0x55,W0            ;Unlock
	mov		W0,NVMKEY
	mov		#0xAA,W0
	mov		W0,NVMKEY
	bset	NVMCON,#WR
	nop							;2nop kötelez?
	nop
2:	btsc	NVMCON,#WR          ;Wait
	bra		2b

	pop		W2
	pop		W1
	pop		W0
	pop		TBLPAG
	return
;------------------------------------------------Flash erase
.global		_EraseFls_H
.align		2
;extern void EraseFls_H(int pag,int cim);//use:-
_EraseFls_H:
	push    TBLPAG
	push	W0
	push	W1
	push	W2

	mov     #0x4042,W2			;ROW_ERASE
	mov     W2,NVMCON
	mov     w0,TBLPAG
	tblwtl  w1,[w1]				;select row

	disi	#5
	mov     #0x55,W0			;Unlock
	mov     W0,NVMKEY
	mov     #0xAA,W0
	mov     W0,NVMKEY
	bset    NVMCON,#WR
	nop							;2nop kötelez?
	nop
1:	btsc    NVMCON,#WR
	bra		1b

	pop		W2
	pop		W1
	pop		W0
	pop     TBLPAG
	return
;------------------------------------------------Reset
.global		_ResetK4_H
.align		2
;extern void ResetK4_H(void);//use:-
_ResetK4_H:
	reset
;------------------------------------------------END section
;================================================END

