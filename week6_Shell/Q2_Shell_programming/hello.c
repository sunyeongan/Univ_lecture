#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void){
	
	int n;

	srand(time(NULL));
	printf("Hello world begins\n");
	n = rand() % (30-10+1)+10;
	sleep(n);
	printf("sleep : %d\n",n);
	printf("Hello world ends\n");



}
