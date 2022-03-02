#include <stdio.h>
#include "calc.h"

int main(int argc, char* argv[]){

	int input;
	int num1, num2;

	printf("<Caluculator Menu>\n1. Add\n2. Sub\n3. Mul\nEnter :");
	scanf("%d",&input);

	if(argc!=0){
		printf("Enter two numbers : ");
		scanf("%d %d",&num1, &num2);
		if(input == 1)
			add(num1,num2);
		if(input == 2)
			sub(num1,num2);
		if(input == 3)
			mul(num1,num2);
	}

}
