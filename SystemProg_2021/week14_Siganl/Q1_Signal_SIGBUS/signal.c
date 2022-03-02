#include <stdio.h>
#include <signal.h>

int main(void){

	sigset_t st;
	sigfillset(&st);//모든 시그널 집합에 추가

	if(sigismember(&st,SIGBUS))
		printf("SIGBUS is set.\n");
	else
		printf("SIGBUS is not set\n");
	
	return 0;

}
