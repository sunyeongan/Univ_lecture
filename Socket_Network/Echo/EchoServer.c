#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#define QUIT "quit"
#define PORTNUM 9002



int main(void){
	
	char w_buf[256];
	char r_buf[256];
	char buf[256];
	struct sockaddr_in sin;
	struct sockaddr_in cli;
	int sd, ns, clientlen = sizeof(cli);
	int client_cnt;
	int len;

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket");
		exit(1);
	}
	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("192.168.200.106");
	
	

	if(bind(sd,(struct sockaddr *)&sin, sizeof(sin))){
		perror("bind");
		exit(1);
	}
	
	if(listen(sd,5)){
		perror("listen");
		exit(1);
	}
	

	while(1){
		
		
		if((ns = accept(sd,(struct sockaddr *)&cli, &clientlen)) == -1){
			perror("accept");
			exit(1);
		}

		
		pid_t t = fork();
		
		if(t == 0){
			while(1){
				
				close(sd);

			

				
				
				if(recv(ns, buf,sizeof(buf), 0) == -1){
					perror("recv");
					exit(1);
				}
				
				if(strncmp(buf,QUIT,strlen(QUIT)) == 0){
					break;
				}

				
				
				//strcpy(w_buf,r_buf);
				
				if(send(ns,buf,sizeof(buf), 0) == -1){
					perror("send");
					exit(1);
				}
				
				printf("Recv from Client : %s\n",buf);

				memset(buf,0x00,256);

				
				usleep(5);
				
			}
			
			exit(0);
		}
		
		
		close(ns);
		client_cnt++;
		
		printf("\nNew Client\n");
		printf("Number of service client : %d\n",client_cnt);
	}
	
	
}

