#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include<sys/un.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>

#define TIME_SERVER "127.0.0.1"

#define TIME_PORT 5018

int main(void){
	int sock;
	struct sockaddr_in server;
	char buf[256];
	char buf_in[256];
	char buf_get[256];


	if((sock = socket(AF_INET,SOCK_STREAM,0)) == -1)
		exit(1);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(TIME_SERVER);
	server.sin_port = htons(TIME_PORT);

	if(connect(sock,(struct sockaddr *)&server, sizeof(server)))
			exit(1);

	for(int i = 0; i<5; i++){
	
		if(recv(sock,buf,sizeof(buf),0) == -1){
			perror("recv");
			exit(1);	
		}

		if(strcmp(buf,"quit\n") == 0 )
			break;

		printf("[YOU] %s\n", buf);

		memset(buf_in,0x00,256);
		printf("input data : ");
		fgets(buf_in,256,stdin);

		strcpy(buf,buf_in);


		if(send(sock,buf,strlen(buf)+1,0) == -1){
			perror("send");
			exit(1);
		}
		memset(buf,0x00,256);
	}
	

	
	close(sock);

}
