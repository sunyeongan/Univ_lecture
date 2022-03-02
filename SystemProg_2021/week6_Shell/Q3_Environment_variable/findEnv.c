#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	char *val;

	val = getenv(argv[2]);
	if(val == NULL)
		printf("%s does not have %s!\n",argv[0],argv[2]);
	else
		printf("%s has %s\n",argv[0],argv[2]);

	return 0;
}
