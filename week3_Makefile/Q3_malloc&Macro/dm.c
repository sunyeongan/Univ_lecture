#include <stdio.h>
#include <stdlib.h>



int  main(void){

	int size = 10;//arr size
	int n = 0;
	int* arr;//arr
	int sum = 0;
	int i = 1;

	arr = (int *)malloc(sizeof(int)*size);//40byte
	printf("n : %d , size: %d , sum %d\n",n,size,sum);

	while(n<100){
	
		//printf("arr[%d]=%d\n",n,i);
		arr[n]=i;//n=0 i=1
		sum+=arr[n];
		i++;
		n++;

		if(size<=n){
#ifdef DEBUG
			printf("size up : %d",size);
			size*=2;
			arr = (int *)realloc(arr,size*sizeof(int));
			printf("=>%d\n",size);
#endif
		}


	}

	printf("n : %d , size: %d , sum : %d\n",n,size,sum);
	free(arr);

	while(n>11){
		
		arr[n]=0;
		sum+=arr[n];
		n--;
		if(n<=size/4){
#ifdef DEBUG
			printf("Size down: %d",size);
			size/=2;
			arr = (int *)realloc(arr,size*sizeof(int));
			printf("=>%d\n",size);
#endif
		}

		
	}
	printf("n : %d, size : %d, sum : %d\n",n,size,sum);
	free(arr);

	return 0;

			

		
}
