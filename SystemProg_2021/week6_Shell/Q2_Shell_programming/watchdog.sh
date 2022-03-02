#!/bin/bash


while :
do
	pid=`ps -ef | grep "hello.exe" | grep -v 'grep' |  awk '{print $2}'`
     	
	if [ -z $pid ]
	then
		./hello.exe
	fi
	sleep .2
done
	
