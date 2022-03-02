#include <stdlib.h>
#include <stdio.h>


int main(void){

	FILE *fp;
	char buf[256];

	fp = popen("ls / |grep s", "r");
	if(fp == NULL){
		fprintf(stderr,"popen failed\n");
		exit(1);
	}
	
	while(fgets(buf,sizeof(buf),fp)){
		printf("Recv : %s",buf);
	}


	pclose(fp);

	return 0;


}
