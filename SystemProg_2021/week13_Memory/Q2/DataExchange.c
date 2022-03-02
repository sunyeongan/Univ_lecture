#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	int fd;
	pid_t pid;
	caddr_t addr;
	struct stat statbuf;

	if (argc != 2){

		fprintf(stderr, "Usage %s filename\n", argv[0]);//인자로 파일명 전달
		exit(1);
	}

	if(stat(argv[1], &statbuf) == -1){// 파일 정보 조회

		perror("stat");
		exit(1);
	}

	if (( fd = open(argv[1], O_RDWR)) == -1){
		perror("open");
		exit(1);
	}

	addr = mmap(NULL,statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, (off_t)0);//메모리 매핑
	
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
			printf("1. Child Process : addr=%s", addr);
			sleep(1);
			addr[0] = 'x';//자식 프로세스가 매핑된 내용을 수정
			printf("2. Child Process : addr=%s", addr);
			sleep(2);
			printf("3. Child Process : addr=%s", addr);//매핑된 내용 읽기
			break;
		default: // 부모 프로세스
			printf("1. Parent process : addr=%s", addr);//매핑된 내용 읽기
			sleep(3);
			printf("2. Parent process : addr=%s", addr);
			addr[1] = 'y';//부모 프로세스가 매핑된 내용 수정
			printf("3. Parent process : addr=%s", addr);
			break;
	}
	return 0;
}

