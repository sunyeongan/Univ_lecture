#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>

int main(void){

	DIR *dp,*dp2;
	struct dirent *dent;
	struct stat sbuf;
	char path[100];
	char file_list[100];
	if((dp = opendir("./")) == NULL){
		
		perror("opendir");
		exit(1);
	}
	
	if((dp2 = opendir("./")) == NULL){
		
		perror("opendir");
		exit(1);
	}
	
	printf("<Regular Files>\n");


	while((dent = readdir(dp))){
	
		stat(dent->d_name,&sbuf);

		if(dent->d_name[0] == '.') continue;
		
		if(S_ISREG(sbuf.st_mode)){
			printf("%s\n",dent->d_name);
		}	
	}
	printf("<Diretories>\n");
	while(dent = readdir(dp2)){

		stat(dent->d_name,&sbuf);

		if(dent->d_name[0] == '.') continue;

		if(S_ISDIR(sbuf.st_mode)){
			printf("%s\n",dent->d_name);
		}	
			
	}
	closedir(dp);
	return 0;

}
