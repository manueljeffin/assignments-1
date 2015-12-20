/**
*
* This program converts a decimal number to a binary number 
*
**/

#include <stdio.h>

unsigned long long dectobin(number){
	int q = number/2 , r = number % 2;
	if (number ==1){
		return 1;
	}
	else if (q == 1){
		return q * 10 + r;
	}
	else{
		return dectobin(q) * 10 + r;
	}
}

/**
*
* This approach is apt for converting numbers within ~1,000,000
*
**/


int main(){
	unsigned long long n, num;
	printf("Enter the decimal number: ");
	scanf("%llu",&n);
	num  = dectobin(n);
	printf("The binary number is %llu\n",num);
	return 0;
}