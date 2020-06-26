#ifndef _SOROS_MOD_NET_H
#define _SOROS_MOD_NET_H
//-----------------------------------------------
#define		NET_AMAX	18			//9b
#define		NET_VMAX	36			//34b
struct	StruNet{
	uint8_t		Apos;				//b		ad� ptr
	uint8_t		Anum;				//b		adand� db
	uint8_t		Vpos;				//b		vett ptr
	uint8_t		Ad[NET_AMAX];		//ad� puffer
	uint8_t		Vesz[NET_VMAX];		//vev� puffer
	};
extern struct StruNet	Net;
//-----------------------------------------------
extern void		UART2_Init(void);
extern void		Soros_NET_100us(void);
extern void		NetKerdez_150ms(void);	//(7+28)*2ms=70ms
//-----------------------------------------------END
#endif
