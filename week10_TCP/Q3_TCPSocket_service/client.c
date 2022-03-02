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

#define PORTNUM 9002
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


	if(recv(sd, buf, sizeof(buf), 0 ) == -1){//menu recv
		perror("recv");
		exit(1);
	}

	printf("%s\n",buf);

	memset(buf,0x00,256);
	printf("Enter : ");
	fgets(buf,256,stdin);

	if(send(sd, buf,strlen(buf) + 1, 0) == -1){//menu choice
		perror("send");
		exit(1);
	}

	char serv1[] = "<ECHO>";
	char serv2[] = "<SINFO>";
	char serv3[] = "<STIME>";
	int ret1 = strcmp(buf,serv1);
	int ret2 = strcmp(buf,serv2);
	int ret3 = strcmp(buf,serv3);

	//if(strcmp(buf,"<QUIT>") == 0 )
		

	if(ret1 == 10){
		memset(buf,0x00,256);
		printf("Input Msg: ");
		fgets(buf,256,stdin);

			

		if(send(sd, buf,strlen(buf)+1, 0) == -1){// echo 
			perror("send");
			exit(1);
		}

		if(recv(sd,buf,sizeof(buf),0) == -1){
			perror("recv");
			exit(1);
		}

		printf("Echo : %s\n",buf);

	}

	if(ret2 == 10) {

		memset(buf,0x00,256);

		if(recv(sd,buf,sizeof(buf),0) == -1){//server info 
			perror("recv");
			exit(1);
		}
		printf("%s\n",buf);
		
	}

	if(ret3 == 10){

		memset(buf,0x00,256);

		if(recv(sd,buf,sizeof(buf),0) == -1){
			perror("recv");
			exit(1);
		}

		printf("%s\n",buf);
		
	}

	
	close(sd);

	return 0;


	
}
