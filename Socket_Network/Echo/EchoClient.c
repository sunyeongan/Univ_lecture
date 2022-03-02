#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define PORTNUM 9002
#define QUIT "quit"
int main(void){

	int sd;
	char w_buf[256];
	char r_buf[256];
	char buf[256];

	struct sockaddr_in sin;

	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("192.168.200.106");

	if((sd = socket(AF_INET, SOCK_STREAM,0)) == -1){
		perror("socket");
		exit(1);
	}


	if(connect(sd,(struct sockaddr *)&sin, sizeof(sin))){
		perror("connect");
		exit(1);
	}
	
	while(1){
		memset(buf,0x00,256);
		
		printf("Enter message : ");
		fgets(buf,256,stdin);
	
	

		if(send(sd,buf,sizeof(buf),0) == -1){
			perror("send");
			exit(1);
		}


		
		//memset(buf,0x00,256);	
		
		if(recv(sd,buf,sizeof(buf), 0) == -1){
			perror("recv");
			exit(1);
		}

		if(strncmp(buf,QUIT,strlen(QUIT)) == 0){
			printf("quit\n");
			break;
		}
		
		printf("Recv from Server : %s\n",buf);

		
		


	}
	close(sd);
	return 0;
}

