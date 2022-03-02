#include <stdio.h>
#include <unistd.h>


int main(int argc, char* argv[]){


	int input;

	input = atoi(argv[1]);

	sleep(input);

	return 0;
}
