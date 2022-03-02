#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#define h_addr h_addr_list[0]
int main(int argc, char* argv[]){

	struct hostent *hent;
	
	
	sethostent(0);

	while((hent = gethostent()) != NULL){
		
		if(strcmp(argv[1],hent->h_name) == 0){
			for(int i = 0; NULL != hent->h_addr_list[i]; i++){
				printf("IP Address : %s\n",inet_ntoa(*(struct in_addr*)hent->h_addr_list[i]));
			}
		       	break;
		}
		else{
			printf("Not Found\n");
		       	break;
		}

	}

	endhostent();

	return 0;

}
