#ifndef _SOROS_MOD_232_H
#define _SOROS_MOD_232_H
//-----------------------------------------------
#define		HIBA_BUSY	6
#define		HIBA_ADDR	2

extern uint8_t			Rs232Vesz[256];	//vevõ puffer
extern uint8_t			Rs232Ad[256];	//adó puffer
//-----------------------------------------------
extern void				UART1_Init(void);
extern uint16_t			ModBus_BeCrcCalc(uint8_t *msg, uint8_t db);
extern void				ModBus_KiCrcCalc(uint8_t *msg, uint8_t db);
extern void 			Soros_232_100u(void);
extern void 			Soros_232_1ms(void);
extern void				Rs232_RdFls_Valasz(uint8_t len);
//-----------------------------------------------END
#endif
