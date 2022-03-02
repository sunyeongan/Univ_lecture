#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <unistd.h>

#define QUIT "quit"
#define PORTNUM 9003
#define TIME_SERVER "127.0.0.1"

int main(void){

	int sd;
	struct sockaddr_in sin;
	char buf[256];


	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(TIME_SERVER);
	sin.sin_port  = htons(PORTNUM);


	if((sd = socket(AF_INET,SOCK_STREAM,0)) == -1)
		exit(1);

	if (connect(sd, (struct sockaddr *)&sin, sizeof(sin))){
		perror("socket");
		exit(1);
	}


	while(1){
		memset(buf,0x00,256);
		printf("[Client] : ");
		fgets(buf,256,stdin);

		if( strcmp(buf,QUIT) == 10)
			break;


		if(send(sd, buf,strlen(buf)+1, 0) == -1){// echo 
			perror("send");
			exit(1);
		}

		if(recv(sd,buf,sizeof(buf),0) == -1){
			perror("recv");
			exit(1);
		}

		printf("[From Server] : %s\n",buf);
	}
	

	
	close(sd);

	return 0;


	
}
