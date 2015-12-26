/**
*
* This program is used to determine the determinant of a matrix 
* using Gaussian Elimination method.
*
**/

#include <stdio.h>

float determinant(int n){
	float a[n][n],fact,det=1,t[n],f,temp;
	int i,j,k,swap=0;
	printf("Enter the elements of %d by %d matrix:\n ",n,n);
	
    //populating the matrix
	for( i = 0; i < n; i++ )
		for( j = 0; j < n; j++ ){
			printf("a[%d][%d]: ",i,j);
			scanf("%f" , &f);
			a[i][j] = f ;
        }
	
	//swap the rows if the first element is a zero
	if(a[0][0] == 0){
	i=0;
	while((a[0][0] == 0) && i<n){
		for(j=0; j<n; j++){
				temp= a[0][j];
				a[0][j] = a[i+1][j];	
				a[i+1][j]	= temp;	
			}
		i++;
		swap++;
		}
	}
	//Performing Gaussian elimination
	for( i = 0; i < n; i++ ){
		k = i;
		
        while(k < n-1){
			
			fact = a[k+1][i] / a[i][i];
			
			for(j = 0; j < n ; j++){
				t[j] = a[i][j] * fact;
				}
            
			for(j = 0; j < n ; j++){
				a[k+1][j] = a[k+1][j] - t[j] ;
				}
            
			k++;
		}

	}

	//calculating the determinant
	for( i = 0 ; i < n; i++){
			
			det *= a[i][i];
		}

	if(swap % 2 == 1) {
		det *= -1;
	}
	return det;

}


int main(){
    
	int n;
	printf("Enter the size of the matrix: ");
	scanf("%d",&n);
	printf("\n");


	printf("The determinant is %f",determinant(n));

	return 0;
}
