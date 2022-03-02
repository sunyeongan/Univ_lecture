#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]){

	int fd;
	int pcount = 0;
	char buf[100];

	if (argc != 2){

		fprintf(stderr, "Usage %s filename\n", argv[0]);
		exit(1);
	}

	if (( fd = open(argv[1], O_RDWR, 0644)) > 0){

		read(fd,buf,sizeof(buf));
		close(fd);
	}

	for(int i = 0; i < sizeof(buf); i++){

		if(buf[i] == 'p'){

			pcount++;
		}
	
	}

	if (pcount > 50)
		printf("p count : %d , Parent win!\n",pcount);
	else if ( pcount < 50)
		printf("p count : %d , Child win!\n",pcount);
	else
		printf("Even!");

}
