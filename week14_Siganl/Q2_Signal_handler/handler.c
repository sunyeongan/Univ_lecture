#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void handler(int signo){

	printf("SIGQUIT handler is called!\n");

}

int main(void){

	void (*hand)(int);

	hand = signal(SIGQUIT, handler);	


	printf("Wait 1st Ctrl + w..: SIGQUIT\n");
	pause();


	return 0;
	


}
