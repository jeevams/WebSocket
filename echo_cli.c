#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>
#define SA struct sockaddr

int  main(int argc,char **argv)
{
int sockfd;
struct sockaddr_in servaddr;

char send[100];
char recv[100];

sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
	{
		printf("\nERROR in creating socket\n");
	}
	else
	{
		printf("\nSUCCESS in creating socket\n");
	}


bzero(&servaddr,sizeof(servaddr));


servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(atoi(argv[1]));
servaddr.sin_addr.s_addr=htons(INADDR_ANY);




connect(sockfd,(SA*)&servaddr,sizeof(servaddr));


while(1)
{

bzero(send,100);
bzero(recv,100);
printf("ENTER YOUR Request URI\n");
fgets(send,100,stdin);
write(sockfd,send,strlen(send)+1);
read(sockfd,recv,100);
printf("%s\n",recv);

bzero(send,100);
bzero(recv,100);
printf("ENTER YOUR  SERVER NAME\n");
fgets(send,100,stdin);
write(sockfd,send,strlen(send)+1);
read(sockfd,recv,100);
printf("%s\n",recv);


bzero(send,100);
bzero(recv,100);
printf("Upgrade Type\n");
fgets(send,100,stdin);
write(sockfd,send,strlen(send)+1);
read(sockfd,recv,100);
printf("%s\n",recv);

bzero(send,100);
bzero(recv,100);
printf("Connection Type\n");
fgets(send,100,stdin);
write(sockfd,send,strlen(send)+1);
read(sockfd,recv,100);
printf("%s\n",recv);


bzero(send,100);
bzero(recv,100);
printf("ENTER Your Sec-WebSocket-Key:\n");
fgets(send,100,stdin);
write(sockfd,send,strlen(send)+1);
read(sockfd,recv,100);
printf("%s\n",recv);

bzero(send,100);
bzero(recv,100);
printf("ENTER Your Sec-WebSocket-:\n");
fgets(send,100,stdin);
write(sockfd,send,strlen(send)+1);
read(sockfd,recv,100);
printf("%s\n",recv);

        
        HTTP/1.1 101 Switching Protocols
        Upgrade: websocket
        Connection: Upgrade
        Sec-WebSocket-Accept: s3pPLMBiTxaQ9kYGzzhZRbK+xOo=
        Sec-WebSocket-Protocol: chat


}
}

