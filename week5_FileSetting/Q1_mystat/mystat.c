#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	
	struct stat buf;
	int kind = buf.st_mode & S_IFMT;
	int fd;

	if(argc == 2){

		int kind = buf.st_mode & S_IFMT;
		stat(argv[1],&buf);

		printf("FileName : %s\n",argv[1]);
		printf("-inode number : %d\n", (int)buf.st_ino);

		if(S_ISFIFO(buf.st_mode)) printf("-File type : FIFO\n");
		if(S_ISDIR(buf.st_mode)) printf("-File type : Directory\n");
		if(S_ISREG(buf.st_mode)) printf("-File type :  regular File\n");
		
		printf("-Permission : %o\n", (unsigned int)(buf.st_mode & (S_IRWXU + S_IRWXG +S_IRWXO)));
		printf("-Number of link: %d\n",(int)buf.st_nlink);
		printf("-Size : %d\n",(int)buf.st_size);
	}
	return 0;
}
