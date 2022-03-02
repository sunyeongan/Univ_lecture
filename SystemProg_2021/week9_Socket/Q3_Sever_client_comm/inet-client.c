#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9001

int main(void){
	int sd;
	char buf[256];
	struct sockaddr_in sin;

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket");
		exit(1);
	}

	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");


	if (connect(sd, (struct sockaddr *)&sin, sizeof(sin))){
		perror("connect");
		exit(1);
	}
	while(1){
		memset(buf,'\0',256);
		printf("Input Mesaage : ");
		scanf("%s",buf);

		if(send(sd,buf,strlen(buf) + 1, 0) == -1){
			perror("send");
			exit(1);
		}

		if(recv(sd,buf,sizeof(buf),0) == -1){
			perror("recv");
			exit(1);
		}
		if(strcmp(buf,"exit")==0)
			break;
	
	
		
		printf("From Server : %s\n",buf);
	}
	close(sd);
	
	return 0;
}






