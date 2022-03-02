#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <time.h>

#define PORTNUM 9002

int main(void){

	struct sockaddr_in sin, cli;
	struct servent *port;
	struct hostent *hent;

	char buf[256];
	char menu[4096] = "<Available Services>\n1. Echo server <ECHO>\n2. Get server info <SINFO>\n3. Getserver time <STIME>\n";

	int sd,ns,clientlen = sizeof(cli);

	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket");
		exit(1);
	}

	if (bind (sd, (struct sockaddr *)&sin, sizeof(sin))){
		perror("bind");
		exit(1);
	}

	if (listen(sd, 5)){
		perror("listen");
		exit(1);

	}

	while(1){
		if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1){
			perror("accept");
			exit(1);
		}
		strcpy(buf,menu);
		if (send (ns, buf, strlen(buf) + 1, 0) == -1){//send menu
			perror("send");
			exit(1);
		}

		memset(buf,0x00,256);

		if (recv(ns, buf, sizeof(buf),0) == -1){//recv menu choice
			perror("recv");
			exit(1);
		}

		printf("** From client : %s\n", buf);
				
		char serv1[] = "<ECHO>";
		char serv2[] = "<SINFO>";
		char serv3[] = "<STIME>";
		int ret1 = strcmp(buf,serv1);
		int ret2 = strcmp(buf,serv2);
		int ret3 = strcmp(buf,serv3);
				
				

		if(ret1 == 10){//echo
					
					
			memset(buf,0x00,256);

			if (recv(ns, buf, sizeof(buf), 0) == -1){
				perror("recv");
				exit(1);
			}

			if(strcmp(buf,"<QUIT>") == 0)
				break;

			if(send(ns, buf, strlen(buf) +1, 0) == -1){
				perror("send");
				exit(1);
			}

			printf("%s\n",buf);
			
		}
		

		else if(ret2 == 10){//send info

			memset(buf,0x00,256);
			
			
			sprintf(buf,"PORT NUM : %d\n", sin.sin_port);
			strcat(buf,"IP Address : ");
			strcat(buf,inet_ntoa(sin.sin_addr));
			strcat(buf,"\nNAME :");

			sethostent(0);

			while((hent = gethostent()) != NULL){

				strcat(buf,hent->h_name);
			}
			endhostent();


			if(send(ns, buf, strlen(buf) +1, 0) == -1){
				perror("send");
				exit(1);
			}
					
		}
		else if(ret3 == 10){//send time

			memset(buf,0x00,256);
			time_t now;
			time(&now);

			sprintf(buf,"%s",ctime(&now));

			if(send(ns, buf, strlen(buf) + 1, 0) == -1){
				perror("send");
				exit(1);
			}
		}
	}

	close(ns);
	close(sd);

	return 0;


}
