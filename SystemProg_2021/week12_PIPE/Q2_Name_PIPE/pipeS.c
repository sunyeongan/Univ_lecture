#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){

	int rpd, wpd, n;
	char buf[256];
	char inmsg[80];
	char filepath[20]="./";

	if((rpd = open("./FIFO",O_RDONLY)) == -1){

		perror("open");
		exit(1);
	}
	printf("Server ===>\n");


	while((n = read(rpd,inmsg,80))>0){


		//write(1,inmsg,n);//print
		
		if(n == -1){
			perror("read");
			exit(1);
		}
		if(strcmp(inmsg,"exit") == 0)
			break;
	}
	close(rpd);

	strcat(filepath,inmsg);


	if((wpd = open("./FIFO",O_WRONLY)) == -1){

		perror("openWR");
		exit(1);
	}
	
	
	if(access(filepath,F_OK) == 0){//file exist
				

		if((rpd = open(filepath,O_RDONLY)) == -1){

			perror("open");
			exit(1);
		}
	
		n = read(rpd,buf,sizeof(buf));
		buf[n] = '\0';

		write(wpd,buf,strlen(buf)+1);

	}else{
		sprintf(buf,"error");
		write(wpd,buf,strlen(buf)+1);
		exit(1);
			
			
	}

		
	printf("\n");
	close(wpd);

	return 0;
}

