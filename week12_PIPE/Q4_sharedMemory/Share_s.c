#include <sys/types.h>
#include <sys/mman.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

void handler(int dummy){
	;
}

int main(void){

	key_t key;
	int shmid;

}
