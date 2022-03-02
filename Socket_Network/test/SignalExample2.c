#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/un.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

#define PORTNUM 9003
	



void handler(int sig){

	f_cleanup();
	printf("Handler is called\n");
	exit(EXIT_SUCCESS);
}
void f_setup(){


	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}



	if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))){
		perror("bind");
		exit(1);
	}
	if(listen(sd,5)){
		perror("listen");
		exit(1);
	}

}
void f_accept(){

	while(1){
		if((ns = accept(sd,(struct sockaddr *)&cli, &clientlen)) == -1){
			perror("accept");
			exit(1);
		}
	}

}

void f_fork(){

	switch(fork()){
		case 0:
			close(sd);
			strcpy(buf,"welcom server");
			if(send(ns,buf,strlen(buf) + 1, 0) == -1){
				perror("send");
				exit(1);
			}
			if(recv(ns,buf,strlen(buf),0) == -1){
				perror("recv");
				exit(1);
			}
			printf("** From client : %s\n ", buf);
			sleep(5);
			exit(0);

	}
	close(ns);

}

void f_cleanup(){

}

int main(void){

	char buf[256];
	struct sockaddr_in sin;
	struct sockaddr_in cli;
	int sd, ns, clientlen = sizeof(cli);

	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("192.168.200.106");

	sd = f_setup();
	
	signal(SIGINT, handler);
	
	while(1)
	{
		f_accept();
		f_fork();



	}

	return 0;

}
