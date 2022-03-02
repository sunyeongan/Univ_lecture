#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]){


	int n, n2;
	extern char *optarg;
	FILE *rfp,*wfp;
	char buf[10];


	if(argc == 3){

		rfp = fopen(argv[1], "r");
		
		if(rfp == NULL){
			perror("open error");
			exit(1);
		}

		wfp = fopen(argv[2],"w");

		if(wfp == NULL){
			perror("open error2");
			exit(1);
		}

		while((n = fread(buf,sizeof(char)*2, 3, rfp)) > 0){
			buf[6]='\0';
			if(fwrite(buf, sizeof(char)*2, n, wfp) !=n) perror("wrtie");
		}
		if(n==-1) perror("Read");

		fclose(rfp);
		fclose(wfp);

		return 0;
		
	}

	if(argc == 5){


		while((n2 = getopt(argc, argv, "d:"))!= -1){
			switch(n2){
						
				case 'd':
					rfp = fopen(argv[3],"r");

					if(rfp == NULL){
						perror("open error");
						exit(1);
					}

					wfp = fopen(argv[4],"w");

					if(wfp == NULL){
						perror("open error2");
						exit(1);
					}


					while((n = fread(buf,sizeof(char)*2, 4, rfp)) > 0){
						
						printf("n : %d\n",n); 	
						for(int i = 0; i<n*2; i++){
							buf[i] = buf[i]-atoi(argv[2]);
							printf("i %d : buf[i] =%d\n",i,buf[i]);
						}
						
						if(fwrite(buf,sizeof(char)*2,n,wfp) !=n)
							perror("write");
						
					}
					break;

			}

			
		}
		fclose(rfp);
		fclose(wfp);
		
	}


	printf("\n");
}
