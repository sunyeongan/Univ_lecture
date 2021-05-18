#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/un.h>
#include <fcntl.h>

#define TIME_SERVER "192.168.200.106"
#define TIME_PORT 5011
#define QUIT "quit"

int  main(void){

	int client_sock;
	int len1;
	struct sockaddr_un server_addr;
	char buf[256];
	
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

	close(client_sock);
	printf("[Info] Closing sockets\n");
	
}
