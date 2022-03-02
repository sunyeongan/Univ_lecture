#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main(void){

	int rpd, wpd ,n;
	char msg[80];
	char buf[256];
	char filename[20]="";
	char down[30]="download_";

	system("rm ./FIFO -f");
	
	if(mkfifo("./FIFO",0666) != 0){
		perror("mkfifo");
		exit(1);
	}

	if((wpd = open("./FIFO",O_WRONLY)) == -1){
		perror("open");
		exit(1);
	}


	printf("파일 이름을 입력하세요 :");
       	fgets(msg,80,stdin);

	msg[strlen(msg) -1] = '\0';
		

	n = write(wpd,msg,strlen(msg)+1);

	if( n == -1){
		perror("write");
		exit(1);
	}
	close(wpd);

	if((rpd = open("./FIFO",O_RDONLY)) == -1){
		perror("openRD");
		exit(1);
	}

	while((n = read(rpd,buf,sizeof(buf))) > 0){
		
		if(strcmp(buf,"error")==0)
			printf("File does not exist\n");

		write(1,buf,n);
		strcat(down,msg);

		wpd = open(down,O_CREAT|O_WRONLY|O_TRUNC);

		if(wpd == -1){
			perror("open down_txt");
			exit(1);
		}

		write(wpd,buf,n);
	}
	
	close(rpd);
	

	return 0;
}
