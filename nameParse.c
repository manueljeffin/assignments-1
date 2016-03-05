#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name{
	char name[30];
	int sno;
};

struct result{
	char name[50];
	int count;
	int index[50];
};

int main(){
	char str[5][50],num[10],nm[30];
	int i,j,k,l,len,cnt=1;
	struct name * nme;
	struct result tmp[5];
	for(i=0;i<5;i++){
		tmp[i].name[0]='\0';
		tmp[i].count=0;
		tmp[i].index[0]='\0';
	}
	nme = (struct name *)malloc(sizeof(struct name)*5);
	for(i=0;i<5;i++){
		gets(str[i]);
	}
	for(i=0;i<5;i++){
		
		for(j=0;str[i][j]!=' ';j++){
			num[j]=str[i][j];
		}
		num[j] = '\0';
		nme[i].sno = atoi(num);
		for(k=j+1,l=0;str[i][k]!='\0';k++,l++){
			nm[l]=str[i][k];
			if(str[i][k]=='.'){
				l=-1;
			}
			if(str[i][k]==' '){
				break;
			}
		}
		nm[l]='\0';
		strcpy(nme[i].name,nm);
	}

	// Finding the count of occurrence the name
	
	j=-1;k=0;
	for(i=0;i<5;i++){
		if(j>=0){
			l=k-1;
			while(l>=0){
				if(strcmp(tmp[l].name,nme[i].name) == 0 ){
					tmp[l].index[tmp[l].count]=nme[i].sno;
					tmp[l].count++;
					cnt = 0;
					break;
				}
				l--;
			}
			if(cnt != 0){
				strcpy(tmp[k].name,nme[i].name);
				tmp[k].index[tmp[k].count]=nme[i].sno;
				tmp[k].count++;
				k++;
			}
			
		}else{
			j++;
			strcpy(tmp[k].name , nme[i].name);
			tmp[k].index[tmp[k].count]=nme[i].sno;
			tmp[k].count++;
			k++;
		}
		cnt = 1;
		
	}
	for(i=0;i<k;i++){
		printf("%s,",tmp[i].name);
		printf("%d,[%d",tmp[i].count,tmp[i].index[0] );
		for(l=1;l<tmp[i].count;l++){
			printf(",%d",tmp[i].index[l]);
		}
		printf("]\n");
	}
	return 0;
}