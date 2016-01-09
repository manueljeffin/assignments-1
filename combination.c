/**
* 
*  Displaying different combination of numbers.
* 
* */


#include<stdio.h>

void bin_init(int b[],int n){
    int i;
    for(i = 0 ;i<n;i++){
        b[i]=0;
    }

}

void combination(int n){
    int a[n];
    int i,j,k,count=0,total;    
    int bin[n];
    total = 2 << (n-1);
    //initialising the number array
    for(i=0;i<n;i++){
            a[i]=i+1;
        }
    while(count < total){
        //generating binary num for comparison
        bin_init(bin,n);
        i=count;
        j=0;
        while(i>0){
            bin[j] = i%2;
            i/=2;
            j++;
        }
        //for(i=0;i<n;i++){printf("%d ",bin[0] );}printf("\n");
        for(i=0;i<n;i++){ 
            if(bin[i]!=0){
                printf("%d ",a[i]); 
            }
        }
        printf("\n");
        count++;
    }
    
    
}

int main(){
    int n,i,j,k;
    printf("Enter the number..\n");
    scanf("%d",&n);
    combination(n);
    return 0;
}
