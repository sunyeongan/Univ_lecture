#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/times.h>
#include <limits.h>
#include <unistd.h>
clock_t times(struct tms *buffer);
#define CLK_TCK sysconf(_SC_CLK_TCK)

void func_O1(char *buf, int size);
void func_ON(char *buf, int size);
void func_ON2(char *buf, int size);

char* buf;
int main(void){

	time_t  t;
	struct tms mytms;
	clock_t t1,t2;
	

	
	if((t1 = times(&mytms)) == -1){
		perror("times 1");
		exit(1);

	}
	func_O1(buf,100000);
	
	if((t2 = times(&mytms)) == -1){
		perror("times 2");
		exit(1);
	}
	printf("func_O1 takes %.1f seconds\n", (double)(t2-t1)/CLK_TCK);

		
	if((t1 = times(&mytms)) == -1){
		perror("times 1");
		exit(1);

	}
	func_ON(buf,100000);
	
	if((t2 = times(&mytms)) == -1){
		perror("times 2");
		exit(1);
	}

	printf("func_ON takes %.1f seconds\n", (double)(t2-t1)/CLK_TCK);

	
	
	if((t1 = times(&mytms)) == -1){
		perror("times 1");
		exit(1);

	}
	func_ON2(buf,100000);
	
	if((t2 = times(&mytms)) == -1){
		perror("times 2");
		exit(1);
	}
	printf("func_ON2 takes %.1f seconds\n", (double)(t2-t1)/CLK_TCK);

	
	
	
	free(buf);

	return 0;
}

void func_O1(char *buf, int size){
	
	buf = (char*)malloc(sizeof(char)*size);
	buf[size] = 1;
	printf("%c",buf[size]);
}
void func_ON(char *buf, int size){
	
	buf = (char*)malloc(sizeof(char)*size);
	for(int i = 0; i<size; i++){
	
		buf[i] = i;	
	}
}

void func_ON2(char *buf, int size){
	
	buf = (char*)malloc(sizeof(char)*size);
	for(int i = 2; i<size; i++){
		for(int j = 1; j<size; j++){
		       buf[i] = i*j;
		}
	}
}


	


