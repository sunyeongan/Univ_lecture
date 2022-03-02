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

#define PORTNUM 5011

// week9/server.c
int main(void){
	char buf[256];
	struct sockaddr_un server;
	struct sockaddr_un client;
	int sd, sd2, len1,len;

	///inet
	int sock, sock2,leni;
	struct sockaddr_in server_in,client_in;
	char buf2[256];

	
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
	
	///inet
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket");
		
		exit(1);
		
	}
	printf("create socket");
	memset((char *)&server_in,'\0',sizeof(server_in));
	server_in.sin_family = AF_INET;
	server_in.sin_addr.s_addr = htonl(INADDR_ANY);
	server_in.sin_port = htons(PORTNUM);


	//int flags = fcntl(sock2,F_GETFL,0);
	//fcntl(sock2,F_SETFL,flags | O_NONBLOCK)
	//user c 
	
	if(bind(sock,(struct sockaddr *)&server_in, sizeof(server_in))){	   
	       	perror("bind");
		exit(1);
	}
	printf("[Info] inet socket : waiting for con req\n");
	if(listen(sock,5))
		exit(1);

	if((sock2 = accept(sock,(struct sockaddr * )&server_in,&leni)) == -1){
		perror("accept");
		printf("[Info] :  Inet socket : client connected\n");
		exit(1);
	}

	int flags2 = fcntl(sock2,F_GETFL,0);
	fcntl(sock2,F_SETFL,flags2 | O_NONBLOCK);
	
	
	while(1){

		if(recv(sd2,buf,sizeof(buf),0) > 0) {//unix
			printf("[ME] : %s", buf);
			if(send(sock2,buf,strlen(buf)+1, 0)==-1){//inet
				perror("send");
				exit(1);
			}

		}
		if(strncmp(buf,QUIT,strlen(QUIT)) == 0){
			break;
		}

	
		memset(buf2,0,256);
		//strcpy(buf2,buf);
		//int server_in_size = sizeof(server_in);
		

		if(recv(sock2,buf2,sizeof(buf2),0) > 0){
			printf("[YOU] : %s", buf2);
			
		}
		
		if(strncmp(buf2,QUIT,strlen(QUIT)) == 0 ){
			break;
		}
		usleep(100);

	
	}	
	close(sd);
	close(sd2);
	close(sock);
	close(sock2);
	
	}

		


