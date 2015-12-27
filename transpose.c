/**
*
*Tranpose of a square matrix using pointers
*
*
**/

#include <stdio.h>
#include <stdlib.h>

//Function for swapping two numbers
void swap(int *a,int *b){
    int t;
    t = *a;
    *a = *b;
    *b=t;
}

//Function for printing a matrix

void dispMat(int *a,int m){
	int i,j;
    int msq = m*m;

	for(i=0;i<msq;i++){
		
			printf("%d ",*(a+i));
		if((i+1)%m == 0)
			printf("\n");
	}

}


//This function generates the matrix n finds its transpose

void transpose(int m){
	int val,msq=m*m,count;
    int *a = malloc(msq*sizeof(int));
	int iterator,t,rowshifter,colshifter;
	
	printf("Enter the elements of the given matrix\n");
	
	for(iterator=0;iterator<msq;iterator++){
        scanf("%d",(a+iterator));
        }
	
	printf("The given matrix...\n");
	dispMat(a,m);
    
    colshifter=0;
    rowshifter=colshifter;
    iterator=0;
    
	while(iterator< msq){
        if(rowshifter < msq){
            if( iterator%m > colshifter){
                swap((a+iterator),(a+rowshifter));
            }
            rowshifter+=m;
            iterator++;
        }
        else{
            colshifter++;
            rowshifter = colshifter;
            if( iterator%m > colshifter){
                 swap((a+iterator),(a+rowshifter));
            }
            rowshifter+=m;
            iterator++;
            }
    }
	
    printf("The transpose is...\n");
	dispMat(a,m);
	
}

int main(){
	int m;
	printf("Enter the order of the matrix: ");
	scanf("%d",&m);
	transpose(m);
	return 0;
}