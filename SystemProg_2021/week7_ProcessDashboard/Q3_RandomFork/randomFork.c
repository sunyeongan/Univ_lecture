#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char* argv[]){


	int status;
	double randTmp;
	double prob;
	pid_t pid;
	pid_t pid_wait;

	prob= atof(argv[1]);

	printf("prob : %f\n", prob);
	
	srand(time(0));


	while((randTmp = rand() / (RAND_MAX * 1.0))  <= prob ){
	       
		pid = fork();
	        printf("My PID (%d), My Parent PID (%d)\n",getpid(),getppid());
		if (pid > 0 ){
			pid_wait = wait(&status);
			printf("waitPid : %d\n",pid_wait);
		}
		
		
	}	

	
	return 0;


}
