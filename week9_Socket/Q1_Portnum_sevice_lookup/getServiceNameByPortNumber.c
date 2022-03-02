#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(void){
	struct servent *port;
	int n;
	int input;
	//char proto[4] = "TCP";

	printf("Input PortNum : ");
	scanf("%d",&input);

	port = getservbyport(htons(input),NULL);
	printf("Name %s, Port%d\n", port->s_name, port->s_port);


	return 0;
}
