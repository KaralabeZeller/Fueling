#ifndef ASMFLASH_H
#define	ASMFLASH_H

extern void ReadLatch64_L(int page,int addr);	//use:-
extern void ReadLatch64_H(int page,int addr);	//use:-
extern void WriteLatch64_L(int page,int addr);	//use:-
extern void WriteLatch64_H(int page,int addr);	//use:-
extern void EraseFls_L(int pag,int cim);		//use:-
extern void EraseFls_H(int pag,int cim);		//use:-

extern void ResetK4_H(void);//use:-

#endif

