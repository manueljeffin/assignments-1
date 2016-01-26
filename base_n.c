/**
*
* This program converts a decimal number to a number of base-n
*
**/

#include <stdio.h>
#include <stdlib.h>
//If the base is less than 10
unsigned long long basels10(unsigned long long number,int base){
	int q = number/base , r = number % base;
    
	if (number == 1){
		return 1;
	}
	else if (q <= 1){
		return q * 10 + r;
	}
	else{
		return basels10(q,base) * 10 + r;
	}
}
//If the base is greater than 10
char * basegt10(unsigned long long number,int base){
    char digits[36] = {'0','1','2','3','4',
                '5','6','7','8','9',
                'A','B','C','D',
                'E','F','G','H','I',
                'J','K','L','M','N',
                'O','P','Q','R','S',
                'T','U','V','W','X',
                'Y','Z'};
    int i,size=0;
    char *num ,t;
    num = (char *) malloc(20);
    while (number > 0){
        int r = number % base;
        num[size]=digits[r];
        num[++size]='\0';
        number=number/base;
    }
    
    for(int i =0; i< size/2; i++){
        t = num[i];
        num[i] = num[size-1-i];
        num[size-1-i] = t;
    }
    num = (char *) realloc(num, size);
    return num;
}

/**
*
* This approach is apt for converting numbers within ~1,000,000
*
**/


int main(){
	unsigned long long n, num;
    int base; char * num1;
	printf("Enter the decimal number: ");
	scanf("%llu",&n);
    printf("Enter the base : ");
    scanf("%d",&base);

    if(base > 10){
        num1 = basegt10(n,base);
        printf("The converted number is %s\n",num1);
    } else if (base >= 2){
        num  = basels10(n,base);
        printf("The converted number is %llu\n",num);
    }
    
	return 0;
}