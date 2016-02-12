#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int alphacheck(int a[]){
	int flag=1,i;
	for(i=0;i<26;i++){
		if(a[i]>1){
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int i,len,sublen,j,alpha[26],sprev=0,k;
	char str[50],temp[50],maxstr[50];
	printf("Enter the string...\n");
	scanf("%s",str);
	len = strlen(str);
	for(i=0;i<26;i++){
		alpha[i] = 0;
	}
	for(i=0; i<len;i++){
		str[i] = tolower(str[i]);
	}
	for( i=0; i<len ;i++){
		sublen=0;
		for(j=i,k=0; j<len; j++){
			alpha[str[j]-97]+=1;
			
			if(alphacheck(alpha) == 1){
				sublen++;
				temp[k]=str[j];
				k++;
			}
			else{
				break;
			}
		}
		for(k=0;k<26;k++){alpha[k]=0;}
		if(sublen > sprev){
			sprev = sublen;
			for(k=0;k<sublen;k++){
				maxstr[k]=temp[k];
			}
			maxstr[k]='\0';
		}

	}
	printf("The maximum length string is \"%s\" and its length is %d\n",maxstr,sprev );
	return 0;
}