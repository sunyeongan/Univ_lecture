#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/un.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <time.h>


#define TIME_PORT 5018

int main(void){
	int sock, sock2;
	struct sockaddr_in server, client;
	int len;
	char buf[256];
	char buf_in[256];
	time_t today;

	if((sock=socket(AF_INET,SOCK_STREAM,0)) == -1)
		exit(1);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(TIME_PORT);

	if(bind(sock, (struct sockaddr *)&server, sizeof(server)))
		exit(1);
	if(listen(sock,5))
		exit(1);
	if((sock2 = accept(sock,(struct sockaddr *)&client,&len)) == -1){
		perror("accept");
		exit(1);
	}	

	for(int i = 0; i<5; i++){
		
		memset(buf_in,0x00,256);
		printf("input data: ");
		fgets(buf_in,256,stdin);

		strcpy(buf,buf_in);


		if(send(sock2,buf,strlen(buf)+1,0) == -1){
			perror("send");
			exit(1);
		}

		if(strcmp(buf,"quit\n") == 0)
			break;

		memset(buf,0x00,256);

		if(recv(sock2,buf,sizeof(buf),0) == -1){
			perror("recv");
			exit(1);
		}

		if(strcmp(buf,"quit\n") == 0 )
			break;
	
		printf("[YOU] %s\n",buf);
	}
	close(sock);
	close(sock2);
	
}


