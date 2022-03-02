#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	


	int fd;
	char temp[100];
	struct stat statbuf;

	if (argc != 2){
		fprintf(stderr, "Usage %s filename\n",argv[0]);
		exit(1);
	}

	if (( fd = open(argv[1], O_RDWR | O_CREAT, 0644)) > 0){
	
		for(int i = 0; i< 51; i++){
			temp[i] = 'p';
			printf("p : %d\n",i);
		}

		for(int j = 51; j < 101; j++){
			temp[j] = 'c';
			printf("c : %d\n",j);
		}

		write(fd,temp,strlen(temp));

	}else{
		perror("open");
		exit(1);

	}

	if(stat(argv[1], &statbuf) == -1){
		perror("stat");
		exit(1);
	}

}
