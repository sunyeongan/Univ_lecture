#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]){

	int n;
	int fd;
	int start1;
	char buf[2];
	char wbuf[100];//
       	char start2[5];	
	int rdbyte = atoi(argv[3]);
	int cur_offset;
	bool asci;
	
	if(argc == 4){

		fd = open(argv[1],O_RDONLY);

		if(fd == -1){
			perror("open error");
			exit(1);
		}


		if(atoi(argv[2])==0){//argv[2] == alphabet
			
					
			if(strcmp(argv[2],"begin")==0){

				lseek(fd,0,SEEK_SET);
				
			
				for(int i = 0; i<rdbyte; i++){
					n = read(fd,buf,1);//o
					buf[n] = '\0';	
					if(n == 0){
						lseek(fd,0,SEEK_SET);
						continue;
					}
					printf("buf[%d] :  %c\n",i,buf[0]);

				}
			}	
	

			if(strcmp(argv[2],"mid")==0){

				int end_offset = lseek(fd,0,SEEK_END);
				int mid_offset = lseek(fd,-(end_offset/2),SEEK_END);
				cur_offset = lseek(fd,0,SEEK_CUR);
				printf("cur : %d\n",cur_offset);

				lseek(fd,0,SEEK_SET);
				
			
				for(int i = 0; i<rdbyte; i++){
					n = read(fd,buf,1);//o
					buf[n] = '\0';	
					if(n == 0){
						lseek(fd,0,SEEK_SET);
						continue;
					}
					printf("buf[%d] :  %c\n",i,buf[0]);

				}		
			
			}
			if(strcmp(argv[2],"end")==0){

				int end_offset = lseek(fd,0,SEEK_END);
			
			
				for(int i = 0; i<rdbyte; i++){
					n = read(fd,buf,1);//o
					buf[n] = '\0';	
					if(n == 0){
						lseek(fd,0,SEEK_SET);
						continue;
					}
					printf("buf[%d] :  %c\n",i,buf[0]);

				}		
			
			}
		}
		
		else if(argv[2]!=0){// argv[2] == digit
		
			start1 = atoi(argv[2]);
		
			if(start1 < 0){

				lseek(fd,start1,SEEK_END);

				cur_offset = lseek(fd,0,SEEK_CUR);
			
				printf("cur_offset : %d\n",cur_offset);
				//lseek(fd,start,SEEK_SET);
			
				//printf("cur_offset : %d\n",cur_offset);
		

				while((n = read(fd,buf,rdbyte)) > 0){

					for(int i = 0; i<rdbyte; i++){
						printf("buf[%d] = %c\n",i,buf[i]);

					}
					break;
				}


			}
		
			else {

		
				lseek(fd,start1,SEEK_SET);
				
				for(int i = 0; i<rdbyte; i++){
					n = read(fd,buf,1);
					buf[n] = '\0';
					if(n == 0){
						lseek(fd,0,SEEK_SET);
						continue;
					}
					printf("buf[%d] :  %c\n", i, buf[0]);
				}
			
			}
		}

		close(fd);	
	}
	
}
