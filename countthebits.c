/**
*
* This program calculates the number of bits required to represent a decimal number 
*
**/

#include <stdio.h>

int countthebits(unsigned long long number){
	int count=0;
	while (number > 0){
		number = number/2;
		count++;
	}
	return count;
}



int main(){
	unsigned long long n;
	int num;
	printf("Enter the decimal number: ");
	scanf("%llu",&n);
	if (n == 0){
		num = 1;
	}else{
	num  = countthebits(n);
	}
	printf("Number of digits required : %d\n",num);
	return 0;
}
