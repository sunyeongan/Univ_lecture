#include <unistd.h>
#include <signal.h>
#include <stdio.h>


void handler(int signo){

	printf("At handler : Wake up!\n");

}
int main (void){

	signal(SIGALRM, handler);
	
	for(int i = 0; i < 5; i++){
		alarm(2);
		printf("Pause...\n");
		pause();
	}

	printf("Bye~\n");
	return 0;
	

}
