#include <stdio.h>

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



int main(){
	int order;
	printf("Enter the order\n");
	scanf("%d",&order);
	even_odd_switch(order);
	linear(order);
}