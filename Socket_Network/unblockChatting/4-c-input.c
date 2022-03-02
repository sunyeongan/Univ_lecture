#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/un.h>
#include <fcntl.h>
#include <arpa/inet.h>

#define TIME_SERVER "192.168.200.106"
#define TIME_PORT 5011
#define QUIT "quit"

int  main(void){

	int client_sock;
	int len1;
	struct sockaddr_un server_addr;
	char buf[256];

	//inet
	
	int sock;
	char buf2[256];
	struct sockaddr_in server_inn;
	
	client_sock = socket(AF_UNIX,SOCK_STREAM,0);

	if(client_sock  == -1){
		exit(1);
	}

	memset((char *)&server_addr,'\0',sizeof(server_addr));
	server_addr.sun_family = AF_UNIX;
	strcpy(server_addr.sun_path,"./sock_addr");
	len1 = sizeof(server_addr.sun_family) + strlen(server_addr.sun_path);
	if(connect(client_sock,(struct sockaddr * )&server_addr,len1)<0){
		exit(1);
	}
	printf("[Info] Unix socket : connected to the server\n");

	while(1){
		memset(buf,0x00,256);
		printf("Enter : ");
		fgets(buf,256,stdin);

		

		if(send(client_sock,buf,strlen(buf)+1,0) == -1){
			perror("send");
			exit(1);
			break;
		}
		if(strncmp(buf,QUIT,strlen(QUIT)) == 0){
			printf("quit\n");
			break;
		}
	}

	//inet
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket");
		exit(1);
	}
	printf("[Info] : Inet socket : waiting for con req\n");

	memset((char *)&server_inn, '\0', sizeof(server_inn));
	server_inn.sin_family = AF_INET;
	server_inn.sin_addr.s_addr = inet_addr(TIME_SERVER);
	server_inn.sin_port = htons(TIME_PORT);

	if(connect(sock,(struct sockaddr *)&server_inn, sizeof(server_inn))) {
		perror("connect");
		exit(1);

	}
	printf("[Info] : Inet socket : client connected\n");
	while(1){
		memset(buf2,'\0',256);
		if(recv(sock,buf2,256,0) == -1){
			perror("recv");
			break;
		}
		printf("[YOU] : %s",buf2);
	}

	close(client_sock);
	printf("[Info] Closing sockets\n");
	
}
