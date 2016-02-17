#include <stdio.h>
#include <math.h>
int digitize(int n){
	int i=0,q;
	while( (q = n/10) >	 0){
		i++;
		n = n/10;
	}
	
	return i+1;
}
int nxtPalin(int n){
	int i,p=0,palin=n,pow_10,pf=0,rem,prev,val;
	
	while(pf != 1){
		pow_10 = digitize(palin);
		int a[pow_10+1];
		prev = 0;
		for(i=1;i<=pow_10;i++){
			rem = palin % (int)pow(10,i);
			val = (rem - prev) / (int)pow(10,i-1);
			prev = rem;
			a[i-1] = val;
			
		}
		for(i=0;i<pow_10/2;i++){
			if(a[i] != a[pow_10 -1 -i]){
				p=1;
			}
		}
		if( p == 0) {
			pf = 1;
			break;
		}else{
			p=0;
			palin++;
		}
	}

	return palin;

}

int main(){
	int n,next;
	printf("Enter the number: ");
	scanf("%d",&n);
	next=nxtPalin(n+1);
	printf("The next palindrome is %d\n", next );
	return 0;
}