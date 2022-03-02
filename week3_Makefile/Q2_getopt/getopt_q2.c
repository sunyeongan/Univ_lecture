#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char *argv[]){

	int n;
	extern char *optarg;
	extern int optind;

	if(argv[1]==NULL)
		printf("ERROR:please provide at least one option\n");
	while((n = getopt(argc, argv, "au:h")) != -1){

		
		switch(n) {

			case 'a':
				printf("welcome to System Programming (2021-2)\n");
				break;
			case 'u':
				printf("Nice to meet you,%s\n",optarg);
				break;
			case 'h':
				printf("[Option]\n");
				printf("\t-a : Print \"welcom to System Programming (2021-2)\"\n");
				printf("\t-u : Print \"Nice to meet you [factor]\"\n");
				printf("\t-h : Print Option list\n");
				break;	
		}
		

	}
	
	return 0;
}

