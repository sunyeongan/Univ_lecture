#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main(){
	
	char mesg[]="Just a string";
	int row, col;
	int row_random, col_random;

	initscr();
	getmaxyx(stdscr,row,col);
	
	srand((unsigned int)time(NULL));

	row_random = rand() % (row+1);
	col_random = rand() % (col+1);
	mvprintw(row_random,col_random,"%s",mesg);

	mvprintw(row-2,0,"This screen has %d rows and %d columns \n",row,col);
	//printw("Try resizing your windo(if possible) and then run this program again\n");
	printw("random row : %d , random col : %d\n",row_random,col_random); 
	refresh();
	getch();
	endwin();

	return 0;
}
