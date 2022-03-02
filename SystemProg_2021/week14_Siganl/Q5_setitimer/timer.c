#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int signo){

	printf("Nice to meet you!\n");
}

int main(void){
	

	struct itimerval it;
	sigset(SIGALRM, handler);
	it.it_value.tv_sec = 1;
	it.it_value.tv_usec = 0;
	it.it_interval.tv_sec = 1;//1초 간격으로 시그널 발생
	it.it_interval.tv_usec = 0;

	if(setitimer(ITIMER_REAL, &it, (struct itimerval *)NULL) == -1){
		perror("setitimer");
		exit(1);
	}

	while(1){
	
		if(getitimer(ITIMER_REAL, &it) == -1){
			perror("getitimer");
			exit(1);
		}

		printf("%d sec \n",((int)it.it_value.tv_sec +1) );
		sleep(1);

	}
	
	

	return 0;

}
