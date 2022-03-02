#include <stdio.h>
#include "calc.h"
int mul(int a, int b){
	int result2 = 0;
	result2 = a * b;

	printf("Result : %d * %d = %d\n",a,b,result2);
	return result2;
}
