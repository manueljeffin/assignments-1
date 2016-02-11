#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Marks of different subjects made into a single array since the name of the subjects might change.*/


struct Student
{
    char stdname[27];
    int s_no,marks[5],isHighest[5];
    
} *s;

char sub_names[5][20];

float avg_mark[5];

void highestMark(int n){
    int i,j,k,index,l,t,max,maxMark;
    for(j=0;j<5;j++){
        max = 0;
        maxMark = s[0].marks[j];
        for(i=0;i<n;i++){
            for(k=i;k<n;k++){
                if(s[max].marks[j]<s[k].marks[j]){
                    max=k;
                    maxMark = s[k].marks[j];
                }
            }
        }
        for(l=0;l<n;l++){
            if(maxMark == s[l].marks[j]){
                s[l].isHighest[j] = 1;
            }else{
                s[l].isHighest[j] = 0;
            }
        }
    }
}

void avg(int n){
    int i,j,k;
    float sum = 0;
    for(i = 0;i < 5;i++){
        sum = 0;
        for(j = 0 ; j < n; j++){
            sum += s[j].marks[i];
        }
        avg_mark[i] = (sum * 1.0)/n;
    }
}

int main()
{
    int n = 0;
    FILE * fp;
    fp = fopen("std.csv","r");
    char *line;
    char c,traverser[7][20];
    int i,j;
    
    if(fp!=NULL){
        while( (c = fgetc(fp)) != EOF){
            if(c == '\n'){
                n++;
            }
        }
        
        printf("%d\n",n );
        rewind(fp);
        
        s = (struct Student *)malloc(sizeof(struct Student *) * (n));
        
        i=1;j=0;
        for(i=0;i<7;i++){
            fscanf(fp,"%[^,\n],",traverser[i]);
            if(i>1){
                strcpy(sub_names[i-2] , traverser[i]);
            }
            printf("%s\n",traverser[i] );
        }
        for(i=0;i<n;i++){
            fscanf(fp, "%d,%[^,],%d,%d,%d,%d,%d", &s[i].s_no, s[i].stdname,
                   &s[i].marks[0], &s[i].marks[1], &s[i].marks[2],
                   &s[i].marks[3], &s[i].marks[4]);
            
        }
        
        
        highestMark(n);
        avg(n);
        
        printf("Average Marks are....\n");
        
        for(i=0;i<5;i++){
            printf("%s = %f\n", sub_names[i] ,avg_mark[i] );
        }
        
        printf("Students who have secured the highest mark....\n");
        
        for(i=0;i<n;i++){
            for ( j = 0; j < 5; ++j)
            {
                if(s[i].isHighest[j] == 1){
                    printf("%s has scored the highest mark in %s\n", s[i].stdname,sub_names[j]);
                }
            }
        }
        
        
    }
    
    free(s);
    return 0;
}