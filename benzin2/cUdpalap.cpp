#include <vcl.h>
#include <winsock2.h>
#pragma hdrstop
#include "cUdpalap.h"
#include "cModbusSoros.h"

SOCKET			Socket;
struct sockaddr_in	Destination;
char				DestinationAddress[20];
char				DestinationPort[20];

unsigned int		TimeOutMsec=UDP_TIMEOUT;	//Vetel mennyi ideig tartson max (millisecond)
fd_set			SelectSet;
struct timeval		TimeOut;
//-------------------------------------
bool	InitUdp(void)
{
bool		ok=false;
WORD		wVersionRequested;
WSADATA	wsaData;

wVersionRequested = MAKEWORD(2,0);
if(!WSAStartup(wVersionRequested,&wsaData))
 if (LOBYTE(wsaData.wVersion)!=2 || HIBYTE(wsaData.wVersion)!= 0)
  WSACleanup();
 else
  ok=true;
return ok;
}
//-------------------------------------
bool	OpenUdp(char *Address, char *Port)
{
bool				ok;
int				SourceLength;
struct sockaddr_in	Source;
struct hostent		*DestinationEntry;

strcpy(DestinationAddress,Address);
strcpy(DestinationPort,Port);

Source.sin_family=AF_INET;
Source.sin_addr.s_addr=htonl(INADDR_ANY);
Source.sin_port=htons(0);

Destination.sin_family=AF_INET;
Destination.sin_port=htons((u_short)atoi(DestinationPort));
SourceLength=sizeof(Source);

ok=(INVALID_SOCKET!=(Socket=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP))
	     && !bind(Socket,(struct sockaddr*)&Source,sizeof(Source))
	     && !getsockname(Socket,(struct sockaddr*)&Source,&SourceLength));
if(ok) DestinationEntry=gethostbyname(DestinationAddress);
if(ok) memcpy(&Destination.sin_addr,DestinationEntry->h_addr,DestinationEntry->h_length);
else	CloseUdp();
return(ok);
}
//-------------------------------------
bool	CloseUdp(void)
{
return(Socket != INVALID_SOCKET)&&!closesocket(Socket);
}
//-------------------------------------
bool	SendDataUdp(Byte *data,int len)
{
return(0 < sendto(Socket,(char*)data,len,0,(struct sockaddr*)&Destination,sizeof(Destination)));
}
//-------------------------------------
int	ReceiveDataUdp(Byte *data)
{
int				len,ReceivedLen;
struct sockaddr_in	Received;

FD_ZERO(&SelectSet);
FD_SET(Socket,&SelectSet);
TimeOut.tv_sec=0;
TimeOut.tv_usec=1000*TimeOutMsec;
if(0<=select(Socket+1,&SelectSet,NULL,NULL,&TimeOut))
 if(FD_ISSET(Socket,&SelectSet))
  if(0<(len=recvfrom(Socket,(char*)data,256,0,(struct sockaddr*)&Received,&ReceivedLen)))
   if(!strcmp(DestinationAddress,inet_ntoa(Received.sin_addr)))
    return(len);
return(0);
}
//-------------------------------------END
