#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex1,mutex2,m3;


		   


void *deadlock1(){
	printf("thread1 start\n");
	pthread_mutex_lock(&m3);
	printf("thread1 lock mutex3\n");
	pthread_mutex_lock(&mutex1);
	printf("thread1 lock mutex1\n");
	sleep(1);
     	pthread_mutex_lock(&mutex2);
        printf("thread1 lock mutex2\n"); 
        pthread_mutex_unlock(&mutex2);   

	printf("thread1 unlock mutex2\n");    
	pthread_mutex_unlock(&mutex1);  
	printf("thread1 unlock mutex1\n");
	pthread_mutex_unlock(&m3);
	printf("thread1 unlock mutex3\n");
	return 0;
}


void *deadlock2(){ 
	printf("thread2 start\n");
	pthread_mutex_lock(&m3);
	printf("thread2 lock mutex3\n");
	pthread_mutex_lock(&mutex2);
	printf("thread2 lock mutex2\n");
	sleep(1); 
        pthread_mutex_lock(&mutex1);
	printf("thread2 lock mutex1\n");

        pthread_mutex_unlock(&mutex1);   
	printf("thread2 unlock mutex1\n");
	pthread_mutex_unlock(&mutex2);  
	printf("thread2 unlock mutex2\n");
	pthread_mutex_unlock(&m3);
	printf("thread2 unlock mutex3\n");
	return 0;
}


int main(){
	pthread_t t1,t2;
	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);
	pthread_mutex_init(&m3,NULL);

	pthread_create(&t1,NULL, deadlock1 , NULL);
	pthread_create(&t2,NULL, deadlock2 , NULL);
    
	pthread_join(t1,NULL);  
	pthread_join(t2,NULL);

	printf("main return\n");

	return 0;
}
