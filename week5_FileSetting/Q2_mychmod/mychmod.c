#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
int main(int argc, char *argv[]){

	struct stat buf;


	stat(argv[1],&buf);

	if(argc == 2){

		printf("-Permisson : %s%s%s%s%s%s%s%s%s\n",(buf.st_mode & S_IRUSR)?"r":"-",(buf.st_mode & S_IWUSR)?"w":"-",(buf.st_mode & S_IXUSR)?"x":"-",(buf.st_mode & S_IRGRP)?"r":"-",(buf.st_mode & S_IWGRP)?"w":"-",(buf.st_mode & S_IXGRP)?"x":"-",(buf.st_mode & S_IROTH)?"r":"-",(buf.st_mode & S_IWOTH)?"w":"-",(buf.st_mode & S_IXOTH)?"x":"-");
	}

	
	if(argc == 3){
		
		printf("Permisson (before) : %s%s%s%s%s%s%s%s%s\n",(buf.st_mode & S_IRUSR)?"r":"-",(buf.st_mode & S_IWUSR)?"w":"-",(buf.st_mode & S_IXUSR)?"x":"-",(buf.st_mode & S_IRGRP)?"r":"-",(buf.st_mode & S_IWGRP)?"w":"-",(buf.st_mode & S_IXGRP)?"x":"-",(buf.st_mode & S_IROTH)?"r":"-",(buf.st_mode & S_IWOTH)?"w":"-",(buf.st_mode & S_IXOTH)?"x":"-");
		

		chmod(argv[2],atoi(argv[1]));

		printf("Permisson (after) : %s%s%s%s%s%s%s%s%s\n",(buf.st_mode & S_IRUSR)?"r":"-",(buf.st_mode & S_IWUSR)?"w":"-",(buf.st_mode & S_IXUSR)?"x":"-",(buf.st_mode & S_IRGRP)?"r":"-",(buf.st_mode & S_IWGRP)?"w":"-",(buf.st_mode & S_IXGRP)?"x":"-",(buf.st_mode & S_IROTH)?"r":"-",(buf.st_mode & S_IWOTH)?"w":"-",(buf.st_mode & S_IXOTH)?"x":"-");
	

		

	}

	return 0;
}
