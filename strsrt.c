#include <stdio.h>

int main(){
    //char *str[9] = {"1", "3", "11","21","12", "100", "19", "2", "5"},*temp;
    char *str[9] = {"1234","412","12","7","5","21","12","1","99"},*temp;
    int i,j,k,mazSize,m;
    m = 9; //Number of Strings
    mazSize = 4; //Maximum length of a string
    printf("Before sorting...\n");
    for(i=0;i<m;i++){
        printf("%s ", str[i] );
    }
    printf("\n");
    int a[m],tmp,prevK;
    for(i=0;i<m;i++){
        a[i]=1;
    }
    // As 'k' increases most of the iterations are skipped
    for(k=0;k<mazSize;k++){
        prevK = (k >= 1 )? k-1 : 0;
        for(i=0;i<m;i++){
            for(j=0;j<(m-1);j++){
                
                if( a[j] ){
                    if( str[j][k]== '\0' ){ //Size filter
                        a[j]=0;
                        break;
                    }
                    if (str[j+1][k]=='\0'){
                        a[j+1]=0;
                    }
                    if(a[j]>a[j+1]){ //Comparision based on size
                        temp=str[j];
                        str[j]=str[j+1];
                        str[j+1]=temp;
                        tmp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=tmp;
                    }else if(str[j][prevK] > str[j+1][prevK]){ //Comparision based on value
                        temp=str[j];
                        str[j]=str[j+1];
                        str[j+1]=temp;
                    }else if( str[j][prevK] == str[j+1][prevK]&& str[j][k] > str[j+1][k]){
                        temp=str[j];
                        str[j]=str[j+1];
                        str[j+1]=temp;
                    }
                }
            }
            
        }
    }
    printf("After Sorting...\n");
    for(i=0;i<m;i++){
        printf("%s ", str[i]);
    }
    printf("\n");
    return 0;
}