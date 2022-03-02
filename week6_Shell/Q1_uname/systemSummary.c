#include <sys/utsname.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>

void insert(char *m, char *s, int n);


int main(int argc, char *argv[]){

	struct utsname uts;
	int n;
	extern char *optarg;
	char buf[100]="This is a ";

	if(uname(&uts) == -1){
		perror("uname");
		exit(1);
	}

	
	
	if(argc == 1){	
		
		printf("systemSummary availalbe options: \n");
		printf("-s : print OS name\n");
		printf("-n : print nodename (hostname)\n");
		printf("-v : print release\n");
		printf("-m : print machine info\n");
	}
	while((n = getopt(argc, argv, "snvma:")) != -1){
		switch (n){

			case 's':
				strcat(buf,uts.sysname);
				strcat(buf," machine");
				break;

			case 'n':
				strcat(buf," named ");
				strcat(buf,uts.nodename);
				strcat(buf,".");
				break;

			case 'v':
				
				insert(buf,uts.release,10);	
				break;

			case 'm':
				insert(buf,uts.machine,10);
				break;
			
			}
	}

	if(argc>=2){

		for(int i = 0; i<sizeof(buf); i++){
				printf("%c",buf[i]);
			}
				printf("\n");
		}
	//printf("%d\n",strlen(uts.release));
	return 0;

	}
void insert(char *m, char *s, int n){
	
	memmove(m+n, m, strlen(m));
	memmove(m+n, s, strlen(s));
}
