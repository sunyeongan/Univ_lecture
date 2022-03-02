#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){

	int fd;
	char temp[100];
	int k;
	pid_t pid;
	caddr_t addr;
	struct stat statbuf;


	if (argc != 2){

		fprintf(stderr, "Usage %s filename\n", argv[0]);//인자로 파일명 전달
		exit(1);
	}


	if (( fd = open(argv[1], O_RDWR | O_CREAT, 0644)) == -1){//game.txt
		perror("open");
		exit(1);
	}

	if(stat(argv[1], &statbuf) == -1){// 파일 정보 조회
		perror("stat");
		exit(1);
	}


	addr = mmap(NULL,statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, (off_t)0);
	//gam.txt파일 addr 변수에 매핑
	
	if (addr == MAP_FAILED) {

		perror("mmap");	
		exit(1);
	}

	close(fd);

	

	switch (pid = fork()) {

		case -1: 
			perror("fork");	
			exit(1);
			break;
		case 0:// 자식 프로세스
			for (int cnt = 0; cnt < 101; cnt ++){
				
				addr[(cnt % 50)] = 'c';
				sleep(1);
				
			}
			break;
		default: // 부모 프로세스
			for (int cnt = 0; cnt < 101; cnt ++){

				srand(time(NULL));
				k = rand() % 100;
				addr[k] = 'p';
				sleep(1);
			}
			break;
	}
	
	return 0;
}

