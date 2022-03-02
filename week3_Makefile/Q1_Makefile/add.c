#include <stdio.h>
#include "calc.h"
int add(int a, int b){
	int sum = 0;
	sum = a + b;
	printf("Result : %d + %d = %d\n",a,b,sum);
	return sum;
}
