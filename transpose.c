/**
*
*Tranpose of a matrix 
*
*
**/

#include <stdio.h>

//This function prints the matrix

void dispMat(int *a,int m){
	int i,j,msq=m*m;

	for(i=0;i<msq;i++){
		
			printf("%d ",*(a+i));
		if((i+1)%m == 0)
			printf("\n");
	}

}


//This function generates the matrix n finds its transpose

void transpose(int m){
	int a[m][m];
	int i,j,t;
	
	printf("Enter the elements of the given matrix\n");
	
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("The given matrix...\n");
	dispMat(a,m);
	
	for(i=0;i<m ;i++){
		for(j=i;j<m;j++){
			t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
			
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