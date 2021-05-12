#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <time.h>
#include <fcntl.h>
#define QUIT "quit"
#define SERVERIP "192.168.200.106"
#define PORTNUM 5011
// week9/server.c
int main(void){
	char buf[256];
	struct sockaddr_un server;
	struct sockaddr_un client;
	int sd, sd2, len1,len;

	//inet
	int sock;
	char buf2[256];
	struct sockaddr_in client_in;
	
	unlink("sock_addr");

	sd = socket(AF_UNIX, SOCK_STREAM,0);

	if(sd == -1){
		perror("socket");
		exit(1);
	}
	
	

	
	memset((char *)&server, 0, sizeof(struct sockaddr_un));
	server.sun_family = AF_UNIX;
	strcpy(server.sun_path,"./sock_addr");
	len1 = sizeof(server.sun_family) + strlen(server.sun_path);
	printf("[Info] Unix socket : waiting for conn req\n");

	if(bind(sd,(struct sockaddr *)&server, len1)){
		perror("bind");
		exit(1);
	}
	if(listen(sd,5) < 0){
		perror("listen");
		exit(1);
	}
	
	
	if((sd2 = accept(sd,(struct sockaddr *)&client,&len))==-1){
		perror("accept");
		exit(1);
	}

	int flags = fcntl(sd2,F_GETFL,0);
	fcntl(sd2,F_SETFL,flags | O_NONBLOCK);
	

	printf("[Info] Unix socket : Client connected\n");


	//int flags = fcntl(sock2,F_GETFL,0);
	//fcntl(sock2,F_SETFL,flags | O_NONBLOCK);

	
		
	//from user S

	//inet
	//
	if((sock = socket(AF_INET,SOCK_STREAM,0)) == -1){
		perror("socket");
		exit(1);
	}

	int flags2 = fcntl(sock,F_GETFL,0);
	fcntl(sock,F_SETFL,flags2 | O_NONBLOCK);

	memset((char *)&client_in,'\0',sizeof(client_in));
	client_in.sin_family = AF_INET;
	client_in.sin_addr.s_addr = inet_addr(SERVERIP);
	client_in.sin_port = htons(PORTNUM);

	if(connect(sock,(struct sockaddr *)&client_in, sizeof(client_in))){		
		
	}

	
	
	
	while(1){
		
		
		if(recv(sd2,buf,sizeof(buf),0) > 0){
			printf("[ME] : %s",buf);
			if(send(sock,buf,strlen(buf)+1,0)== -1){
				perror("send");
				break;
				}
			
		}
		if(strncmp(buf,QUIT,strlen(QUIT)) == 0){
			printf("[Server] quit\n");
			break;
		}
	

		memset(buf2,0x00,256);
		//strcpy(buf2,buf);
		if(recv(sock,buf2,sizeof(buf2),0)>0){
			printf("[YOU] %s",buf2);
			
		}
		
		
		memset(buf2,0,256);
		usleep(100);

	}
	
	close(sd);
	close(sd2);
	close(sock);
//	close(sock_i2);

		

}
