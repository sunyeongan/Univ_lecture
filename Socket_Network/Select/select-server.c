#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/select.h>

#define PORTNUM 9003



int main(void){

	char buf[256];
	struct sockaddr_in sin, cli;
	int access_sock, clientlen = sizeof(cli);
	int comm_sock[10];
	int N_CLIENT = 3; 
	int ret,i;

	fd_set readfds;

	int maxArr(int *sock, int number_cli){
		int maxNumber = 0;
		for(int i = 0; i<N_CLIENT; i++){

			if(sock[i] > maxNumber){
				maxNumber = sock[i];
			}
		}
		return maxNumber;

	}

	if((access_sock = socket(AF_INET, SOCK_STREAM,0)) == -1){
		perror("socket");
		exit(1);
	}

	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("192.168.200.106");

	if(bind(access_sock,(struct sockaddr *)&sin, sizeof(sin))){
		perror("bind");
		exit(1);
	}

	if(listen(access_sock,5)){
		perror("listen");
		exit(1);
	}

	
	for(int i = 0; i<N_CLIENT; i++){
		if((comm_sock[i] = accept(access_sock, (struct sockaddr *)&cli, &clientlen)) == -1){
			perror("accept");
			break;
		}
		else{
			printf("Client #%d connected.\n",i+1);
		}
	}

	while(1){
		FD_ZERO(&readfds);
		for(int i = 0; i<N_CLIENT; i++)
			FD_SET(comm_sock[i], &readfds);
		printf("waiting at select...\n");

		ret = select(maxArr(comm_sock,N_CLIENT)+1, &readfds, NULL, NULL, NULL);

		printf("select returned : %d\n", ret);

		switch(ret){
			case -1:
				perror("error");
			case 0:
				printf("select returns : 0\n");
				break;
			default:
				i = 0;
				while( ret > 0){
					if(FD_ISSET(comm_sock[i], &readfds) ) {
						memset(buf,0,256);
						if(recv(comm_sock[i], buf, 256, 0) == -1){
							perror("recv");
							break;
						}
						ret--;
						printf("MSG from client %d: %s\n", i , buf);
					}else;
					i++;
				}
				break;
		}


	}
	
	N_CLIENT++;
}


