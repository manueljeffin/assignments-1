#include<stdio.h>

void combination(int n){
    int a[n];
    int i,j,k;    
    
    for(i=1;i<=n;i++){
        a[i-1]=i;
    }
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            printf("%d ",a[j]);
            for(k=j+1;k<=i;k++){
                printf("%d ",a[k]);
            }
            printf("\n");
        }
        
    }
    
}

int main(){
    int n,i,j,k;
    printf("Enter the number..\n");
    scanf("%d",&n);
    combination(n);
    return 0;

}
