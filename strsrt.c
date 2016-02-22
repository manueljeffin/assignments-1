#include <stdio.h>

int main(){
	char *str[] = {"1", "3", "11","21","12", "100", "19", "2", "5"},*temp;
	int i,j,m;
	m=9;
	printf("Before sorting...\n");
	int a[m],tmp;
	for(i=0;i<m;i++){
		a[i]=0;
		printf("%s ",str[i] );
	}
	printf("\n");
	for(i=0;i<m;i++){
		for(j=0;str[i][j]!='\0';j++){
			a[i] = str[i][j]+a[i]*10; 
			//since  '+' and '*' are commutative...'21' & '12' will be the same after performing any of those operations
		}
	}
	for(i=0;i<m;i++){
		for(j=i;j<m;j++){
			if(a[i]>a[j]){
				 temp = str[i];
				 str[i] = str[j];
				 str[j] = temp;
				 tmp  = a[i];
				 a[i] = a[j];
				 a[j] = tmp;
			}
		}
	}
	printf("After sorting...\n");
	for(i=0;i<m;i++){
		printf("%s ",str[i] );
	}
	printf("\n");
	return 0;
}