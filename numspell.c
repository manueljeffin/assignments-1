#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//This program will accurately print untill 999

int digitize(int n){
    int i=0,q;
    while( (q = n/10) >	 0){
        i++;
        n = n/10;
    }
    //printf("Pow: %d\n",i+1 );
    return i+1;
}


void numspell(int n){
    int pow_10,rem,prev=0,val,init=1,numd,i;
    char numwrd1[][12]={"zero","one","two",
        "three","four","five",
        "six","seven","eight",
        "nine","ten","eleven",
        "twelve","thirteen","fourteen",
        "fifteen","sixteen","seventeen",
        "eighteen","nineteen"};
    char numwrd2[][12]={"twenty","thirty","forty",
        "fifty","sixty","seventy",
        "eighty","ninety"};
    char pow_10_wrd [][12]= {"hundred","thousand"};
    pow_10 = digitize(n);
    int a[pow_10],j,len;
    for(i=1;i<=pow_10;i++){
        rem = n % (int)pow(10,i);
        val = (rem - prev) / (int)pow(10,i-1);
        prev = rem;
        a[i-1] = val;
        //printf("a[%d]: %d\n",i-1, a[i-1]);
    }
    for(i=pow_10-1;i>=0;i--){
        //printf("i::%d\n",i );
        if(i>=2){
            //printf("%s %s\n",numwrd1[a[i]],pow_10_wrd[i-2] );
            //len=strlen(numwrd1[a[i]]);
            for(j=0; numwrd1[a[i]][j]!='\0' ;j++){
                if(init == 1){
                    printf("%c",toupper(numwrd1[a[i]][j]) );
                    init = 0;
                }else
                    printf("%c", numwrd1[a[i]][j]);
            }
            printf(" ");
            //len=strlen(pow_10_wrd[i-2]);
            for(j=0;pow_10_wrd[i-2][j] != '\0' ; j++){
                printf("%c", pow_10_wrd[i-2][j]);
            }
            printf(" ");
            if(a[i-1] == 0 && a[i-2] == 0){break;}
        }
        else if(i == 1){
            //printf("inn i==1 \n");
            if( a[i] == 0){
                printf("and ");
            }else if( a[i] == 1){
                if(init != 1){
                    printf("and ");
                }
                numd = a[i]*10 + a[i-1];
                //printf("numd:%d\n",numd );
                for(j=0; numwrd1[numd][j]!='\0'; j++){
                    if(init == 1){
                        printf("%c", toupper(numwrd1[numd][j]));
                        init=0;
                    }else
                        printf("%c",numwrd1[numd][j] );
                }
                printf(" ");
                break;
            }else{
                if(init != 1){
                    printf("and ");
                }
                for(j=0; numwrd2[a[i]-2][j]!='\0'; j++){
                    if(init == 1){
                        printf("%c", toupper(numwrd2[a[i]-2][j]));
                        init=0;
                    }else
                        printf("%c",numwrd2[a[i]-2][j] );
                }
                printf(" ");
                if(a[i-1]==0){break;}
            }
            
        }else{
            for(j=0; numwrd1[a[i]][j]!='\0' ;j++){
                if(init == 1){
                    printf("%c",toupper(numwrd1[a[i]][j]) );
                    init = 0;
                }else
                    printf("%c", numwrd1[a[i]][j]);
            }
        }
    }
    printf("\n");
}


int main(){
    int n;
    printf("Enter the number...\n");
    scanf("%d",&n);
    numspell(n);
    return 0;
}