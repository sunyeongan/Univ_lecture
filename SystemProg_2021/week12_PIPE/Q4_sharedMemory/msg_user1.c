/*program to design fullduplex msg queue(user 1)*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/mman.h>
#include<signal.h>
#include<sys/shm.h>

void handler(int dummy){
	;
}

struct msgbuf  //msg queue structure
{

	long mtype;
	char data[10];
};


int main()
{
	char s[30];
	struct msgbuf v1,v2;
	int id;

	key_t key;
	int shmid;
	void *shmaddr;
	char buf[1024];
	sigset_t mask;

	key = ftok("shmfil",1);
	shmid = shmget(key,1024,IPC_CREAT|0666);
	sigfillset(&mask);
	sigdelset(&mask, SIGUSR1);
	sigset(SIGUSR1, handler);

	sigsuspend(&mask);


	id=msgget(4,IPC_CREAT|0644);  //opened msg queue with key 4
	if(id<0)
	{
		perror("msgget");
		return 0;
	}

	//              printf("%d\n",id);

	if(fork())	
	{//parent//msg_snd
		shmaddr = shmat(shmid,NULL,0);//shared memory connect
		while(1)
		{
			v1.mtype=2;

			printf("A: ");

			scanf(" %[^\n]s",s);
			
			strcpy(shmaddr,s);

			msgsnd(id,&shmaddr,strlen(v1.data)+1,0); /* sending user 1 parent data to user2 child process with mtype 2*/
			//perror("msgsnd");

		}
	}
	else
	{//child//msg_rcv

		while(1)
		{
			msgrcv(id,&v2,sizeof(v2),3,0);  /* recieving from user 2 parent data to user1 child process with mtype 3*/

			printf("\rB: %s\n",v2.data);
			printf("A: ");
			fflush(stdout); //flushing output stearm to print me 
		}
	}
}
