#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void handler(int signo){

	for(int i = 0; i < 10; i++){
		printf("Hallym SoftWare\n");
		sleep(1);
	}

}
int main(void){

	sigset_t new;
	
	sigemptyset(&new);
	sigaddset(&new, SIGINT);

	sigprocmask(SIG_BLOCK, &new, (sigset_t *)NULL);//시그널 집합에 대해 블로킹 설정

	printf("Blocking Signal : SIGINT\n");
	printf("SIGINT를 보내세요!\n");
	pause();

	kill(getpid(),SIGINT);

	

	return 0;


}
