#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PORTNUM 9003

int main(void){

	char buf[256];
	struct sockaddr_in sin, cli;
	int sd, ns, clientlen = sizeof(cli);

	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(sd,(struct sockaddr *)&sin, sizeof(sin))){
		perror("bind");
		exit(1);
	}

	if (listen(sd, 5)){
		perror("listen");
		exit(1);
	}

	while(1){

		if ((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1){
			perror("accept");
			exit(1);
		}
		switch (fork()){
			case 0:
				while(1){
					close(sd);

					if(recv(ns,buf,sizeof(buf), 0) == -1){
						perror("recv");
						exit(1);
					}

					if(strcmp(buf,"quit") ==10)
						break;

				
					if(send(ns,buf,strlen(buf) + 1 , 0) == -1){
						perror("send");
						exit(1);
					}

					printf("[From Client] :  %s\n",buf);
				
					usleep(1);
					memset(buf,0x00,256);
				}
				exit(0);
		}
		close(ns);

	}
	return 0;
}
