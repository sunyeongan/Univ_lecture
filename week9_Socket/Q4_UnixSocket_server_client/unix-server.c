#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/un.h>
#include <fcntl.h>



#define SOCKET_NAME "hsocket3"

int main(void){
	char buf[256];
	char wbuf[256];
	struct sockaddr_un ser, cli;
	int sd, nsd, len, clen;
	int fd,n;

	if((sd = socket(AF_UNIX,SOCK_STREAM,0)) == -1){
		perror("socket");
		exit(1);
	}

	memset((char *)&ser, 0 , sizeof(struct sockaddr_un));
	ser.sun_family = AF_UNIX;
	strcpy(ser.sun_path, SOCKET_NAME);
	len = sizeof(ser.sun_family) + strlen(ser.sun_path);
	clen = sizeof(cli);

	unlink(SOCKET_NAME);
	if(bind(sd,(struct sockaddr *)&ser, len)){
		perror("bind");
		exit(1);
	}
	if(listen(sd,5) < 0){
		perror("listen");
		exit(1);
	}

	printf("waiting...\n");

	if((nsd = accept(sd,(struct sockaddr *)&cli, &clen)) == -1){
		perror("accept");
		exit(1);
	}

	if(recv(nsd,buf,sizeof(buf),0) == -1){
		perror("recv");
		exit(1);
	}

	printf("Received Message : %s\n", buf);
	
	
	fd = open(buf,O_RDONLY);	
	if (fd == -1){

		memset(buf,0,256);
		strcpy(buf,"File not exist!!");

		if(send(nsd,buf,strlen(buf) + 1, 0) == -1){
			perror("send");
		}
		exit(1);
	}else{

		memset(buf,0,256);
	
		n = read(fd,buf,sizeof(buf));
		printf("buf : %s\n", buf);
	
		if(send(nsd,buf,strlen(buf) + 1, 0) == -1){
			perror("send");
			exit(1);
		}
	}
	
	close(nsd);
	close(sd);
	close(fd);

	return 0;
}
