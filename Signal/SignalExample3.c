#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig){

	printf("\nHandler is called.\n");
	exit(EXIT_SUCCESS);

}
int main(void){

	signal(SIGINT, handler);
	while(1){
		printf("Sleep begins!\n");
		sleep(1000);
		printf("Wake up!\n");
	}

}
