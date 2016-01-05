#include <stdio.h>

//Linear Triangle
void linear(int order){
	int i,number=1,j;
	printf("The linear growing triangle is...\n");
	for(i =1 ;i<=order ;i++){
		for(j=0;j<i;j++){
			printf("%d ",number++);
		}
		printf("\n");
	}

}

//Even and Odd Switch triangle
void even_odd_switch(int order){
	int i,number=1,buffer[2],j;
	printf("The even/odd switching triangle is...\n");
	// The transition between 1 to 2 is the only transition without a pattern. So we hardcode it.
	// Other transitions follow a pattern
	printf("%d ",number++);
	printf("\n");
	buffer[0]=2;
	buffer[1]=3;

	for(i =2 ;i<=order ;i++){
		number=buffer[i%2];
		for(j=0;j<i;j++){
			printf("%d ",number);
			number+=2;
			buffer[i%2]=number;
		}
		printf("\n");
	}
}

//Pascal Triangle
void pascal(int order){
	int a[order][order],i,j,orderminus=order-1;
	printf("The pascal's triangle is...\n");
	
	if(order >= 2){
		a[0][0]=1;
		a[1][0]=1;
		a[1][1]=1;
	}else{
		a[0][0]=1;
	}
	
	for(i=2;i<order;i++){
		a[i][0]=1;
		for(j=1;j<i;j++){
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
		a[i][j]=1;
	}
	for(i=0;i<order;i++){
		for(j=0;j<=i;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}


int main(){
	int order;
	printf("Enter the order\n");
	scanf("%d",&order);
	linear(order);
	even_odd_switch(order);
	pascal(order);
}