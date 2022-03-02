#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]){

	int n,n2;
	extern char *optarg;
	int rfd, wfd;
	char buf[10];
	if(argc == 3){

		rfd = open(argv[1],O_RDONLY);
		if(rfd == -1){
			perror("open error");
			exit(1);
		}
		wfd = open(argv[2],O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if( wfd == -1){

			perror("open error2");
			exit(1);
		}

		while((n = read(rfd, buf , 6)) > 0)
			if(write(wfd,buf,n) != n) perror("write");

		if(n==-1) perror("Read");

		close(rfd);
		close(wfd);

		return 0;

	}
	if (argc == 5){

		while((n2 = getopt(argc,argv, "c:"))!= -1){

			switch(n2){
	
				case 'c':

					
					rfd = open(argv[3],O_RDONLY);
					if(rfd == -1){
						perror("open error");
						exit(1);
					}

					wfd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
					
					while((n = read(rfd,buf,6)) > 0){

						
						for(int i = 0; i<10; i++){
							buf[i] = buf[i]+atoi(argv[2]);									
						}
							if(write(wfd, buf, n) !=n)
								perror("write");
					}
					
				
			}
			close(rfd);
			close(wfd);
				


		}
	}
}
