#ifndef UDPALAP_H
#define UDPALAP_H
//-------------------------------------
bool	InitUdp		(void);				//inicilizalni kell a program indulasakor
bool	OpenUdp		(char *Address, char *Port);	//kapcsolatot megnyitni vetel elott
bool	CloseUdp	(void);				//kapcsolatot lezarni vetel utan
bool	SendDataUdp	(Byte *data,int len);		//adat kuldes (adatok+hossz)
int	ReceiveDataUdp	(Byte *data);			//adat vetel  (adatok+hossz)
#endif
//-------------------------------------END

