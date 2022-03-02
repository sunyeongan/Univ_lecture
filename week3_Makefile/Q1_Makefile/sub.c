#include <stdio.h>
#include "calc.h"
int sub(int a, int b){
	int result1 = 0;

	result1 = a - b;
	printf("Result : %d - %d = %d\n",a,b,result1);
	return result1;
}
