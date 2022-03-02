#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){

	if(argc == 3){
	
		
		if(rename(argv[1],argv[2]) == -1){
			perror("file rename");
			exit(1);
		}
		

	}

	return 0;
}
