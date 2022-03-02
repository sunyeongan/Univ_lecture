#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	

	if(mkdir(argv[1], 0755) == -1){
		
		perror("make folder");
		exit(1);
	}

	chdir(argv[1]);//change dir
	creat("./README.TXT",0644);

	return 0;
	
}


