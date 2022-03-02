#!/bin/sh

for var in $(seq 100)
do 
	echo "${var} 번째 명령어 실행 중"
	./start game.txt;
	cat game.txt;
	./memPlay2 game.txt;
	./countP game.txt;
	cat game.txt;
done
	


