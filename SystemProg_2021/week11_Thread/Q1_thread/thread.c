#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>



struct studentInfo{
	char name[20];
	char major[50];
	char univ[20];
};

void *start_thread(void *sInfo){
	int i;
	struct studentInfo *temp = (struct studentInfo *)sInfo;
	for (i = 0 ; i < 10 ; i++){
//		sleep(1);
		printf("%s, %s, %s\n", temp->name, temp->major, temp->univ);
//		sleep(1);
	}

	return sInfo;
}


int main(void){
	pthread_t th1, th2;
	struct studentInfo s1 = {"Brad pitt", "Computer Engineering", "Holly University"};
	struct studentInfo s2 = {"Angelina Jollie", "Computer Science", "Wood University"};

	
	pthread_create(&th1, NULL, start_thread, (void*)&s1);
	pthread_create(&th2, NULL, start_thread, (void*)&s2);

	

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	return 0;
}
