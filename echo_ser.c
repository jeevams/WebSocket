#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>
#define SA struct sockaddr
int main(int argc,char **argv)
{

int sockfd,accfd;
struct sockaddr_in servaddr;
char recv[100],type[100];
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


if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
	{
		printf("\nERROR in binding\n");
	}
	else
	{
		printf("\nSUCCESS in binding\n");
	}
listen(sockfd,10);
accfd=accept(sockfd,(SA*)NULL,NULL);
if(accfd<0)
	{
		printf("\nCONNECTION FAILURE\n");
	}
	else
	{
		printf("\nCONNECTION SUCCESS\n");
	}


while(1)
{

bzero(recv,100);
read(accfd,recv,100);
int i;
for( i=0;recv[i]!=' ';i++)
{
type[i]=recv[i];
}
type[i]='\0';
i++;
printf("%s",type);
char buf1[100]="HTTP/1.1 101 Switching Protocols";
char buf2[100]="400 Bad Request";
char buf3[100]="Upgrade: websocket";
char buf4[100]="Connection: Upgrade";
char buf5[100]="Sec-WebSocket-Accept: s3pPLMBiTxaQ9kYGzzhZRbK+xOo";
char buf6[100]="Sec-WebSocket-Protocol: chat";

if(strcmp(type,"GET")==0)
{
  write(accfd,buf1,strlen(buf1)+1);
}
else
{
write(accfd,buf2,strlen(buf2)+1);
}

if(strcmp(type,"GET")==0)
{
  write(accfd,buf1,strlen(buf1)+1);
}
else
{
write(accfd,buf2,strlen(buf2)+1);
}	

 

}



}
