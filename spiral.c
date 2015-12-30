/**
*
* Program to print the martix in spiral
*
*
*
* Ex. If we give a matrix like the one below as input
*
* | 1 2 3 |
* | 4 5 6 |
* | 7 8 9 |
*
* an output 1 2 3 6 9 8 7 4 5 should be printed
*
*/

#include <stdio.h>

void spiral (int m,int n){
	int a[m][n],lmax,rmax;
	int dmax,umax,rowise=1,colwise=0;
	int i,j,count,left=0,up=0;

	printf("Get the elements of array:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("Array is\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	lmax = 0;
	rmax = n;
	dmax = m;
	umax = 1;
	count = 0;
	i = 0;
	j = 0;
	while(count < m*n){
		if(rowise == 1){
			if(left == 0){
				for(;i<rmax;i++){
					printf("%d ",a[j][i]);
					count++;
				}
				left = 1;
				i--;
				j++;
				rmax--;
			} else {
					for( ; i >=lmax ; i-- ){
						printf("%d ",a[j][i]);
						count++;
					}
					i++;
					lmax++;
					left = 0;
					j--;
				}
			colwise = 1;
			rowise = 0;
			
		} else if (colwise == 1) {
			if(up == 0){
				for(;j<dmax;j++){
					printf("%d ",a[j][i]);
					count++;
				}
				j--;
				i--;
				dmax--;
				up=1;
				
				
			} else {
				for(;j>=umax;j--){
					printf("%d ",a[j][i]);
					count++;
				}
				j++;
				i++;
				umax++;
				up=0;
				rowise = 1;
				colwise = 0;
				
			}
			rowise = 1;
			colwise = 0;
			
		}
		
	}
}

int main(){
	int m,n;
	printf("Enter the dimensions of matrix:\n");
	scanf("%d%d",&m,&n);
	spiral(m,n);
	return 0 ;
}