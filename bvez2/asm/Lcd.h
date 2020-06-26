#ifndef _LCD_H
#define _LCD_H
//-----------------------------------------------
extern void		Lcd_PortBe(void);
extern void		Lcd_Init(void);
extern void		Lcd_Clear(void);
extern void		Lcd_Kimasol(void);
extern void		PutPixel(uint16_t x, uint16_t y, char color);
//-----------------------------------------------END
#endif
