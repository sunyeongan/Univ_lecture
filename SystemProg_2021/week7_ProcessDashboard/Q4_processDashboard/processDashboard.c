#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

#define TRUE 1
#define SIZ 32
int main(){

	//int row, col;
	initscr();
	//getmaxyx(stdscr,row,col);
	int i = 0;
	int cnt = 5;
	char buf[SIZ] = {0,};
	
	while(TRUE){

		mvprintw(0,0,"<Process Dashboard>");
		mvprintw(1,0, " ");
		sprintf(buf, "* Running Process (%d) :",cnt);
		mvprintw(2,0, "%s", buf);
		system("./extract-sleepFor-pids.sh > pids.txt");

		FILE* fp = fopen("pids.txt","r");
		
		i = 0;

		while(fgets(buf,SIZ,fp)){
			
			mvprintw(3+i,0,"%s",buf);
			memset(buf,'\0',SIZ);
			i+=1;
			if( i >= cnt ) break;
		}
		
		
		refresh();
		fclose(fp);
		sleep(1);
		
	}
	endwin();
}
