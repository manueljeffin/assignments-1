#include <string.h>
#include <stdio.h>

// Function to get numberoflines in a file.
int getnumoflines(char *a){
	FILE* myfile = fopen(a, "r");
	int ch, number_of_lines = 0;

	do 
	{
	    ch = fgetc(myfile);
	    if(ch == '\n')
	    	number_of_lines++;
	} while (ch != EOF);


	if(ch != '\n' && number_of_lines != 0) 
	    number_of_lines++;

	fclose(myfile);
	return number_of_lines;
}

float avgmark(int n,int sub[]){
	float avg;
	int i,sum=0;
	for(i=0;i<n;i++){
		sum+=sub[i];
		//printf("sub: %d\n",sub[i] );
	}
	avg = (sum * 1.0) / n;
	return avg;
}

void maxofsub(int n,int sub[],char std[][20],char *sname){
	int i,max=sub[0];
	//max mark
	for(i=0;i<n;i++){
		if(max < sub[i]){
			max = sub[i];
		}
	}
	printf("Students who have scored the maximum mark in %s is..\n",sname);
	for(i=0;i<n;i++){
		if (max == sub[i]){
			printf("%s\n",std[i]);
		}
	}
}
int main()
{
   int n = getnumoflines("std.csv");
   FILE * fp = fopen("std.csv","r");
   int a,b,c,i,j,nm;
   int eng[n],mat[n],cse[n],elec[n],ntw[n],sno[n];
   char  stdname[n][20];
   char *line,*token;
   float avg;
   /* walk through other tokens */
   i=1;j=0;
   fscanf(fp,"%s",line);
   while(!feof(fp)){
   		fscanf(fp,"%s",line);
   		token = strtok(line,",");
   		i = 1;
   		while( token != NULL ) {	
		      //printf( " %s\n", token );
		      if(i == 1){
		      	/*This just fetches the serial number ... we may 
		      	want to store this if it is 
		      	without pattern(2,3,1,4,..) 
		      	but here it is (1,2,3...)*/
		      }
		      if(i == 2){
		      	strcpy(stdname[j], token);
		      	//printf("%s\n",stdname[j] );
		      }
		      if(i == 3){
		      	 a = token[0] - 48;
		      	 b = token[1] - 48 ;
		      	c = token[2] - 48;
		      	//If the mark is 100
		      	if(c >= 0 && c <=9 ){
		      		 nm = a * 100 + b * 10 +c;
		      	}else{
		      		nm = a * 10 + b;
		      	}
		      	eng[j] = nm;
		      	//printf("Eng: %d\n",eng[j]);
		      }
		      if(i == 4){
		      	 a = token[0] - 48;
		      	 b = token[1] - 48 ;
		      	c = token[2] - 48;
		      	if(c >= 0 && c <=9){
		      		 nm = a * 100 + b * 10 +c;
		      	}else{
		      		nm = a * 10 + b;
		      	}
		      	mat[j] = nm;
		      	//printf("%d\n",nm);
		      }
		      if(i == 5){
		      	 a = token[0] - 48;
		      	 b = token[1] - 48 ;
		      	c = token[2] - 48;
		      	if(c >= 0 && c <=9){
		      		 nm = a * 100 + b * 10 +c;
		      	}else{
		      		nm = a * 10 + b;
		      	}
		      	cse[j] = nm;
		      	//printf("%d\n",nm);
		      }
		      if(i == 6){
		      	 a = token[0] - 48;
		      	 b = token[1] - 48 ;
		      	c = token[2] - 48;
		      	if(c >= 0 && c <=9){
		      		 nm = a * 100 + b * 10 +c;
		      	}else{
		      		nm = a * 10 + b;
		      	}
		      	elec[j] = nm;
		      	//printf("%d\n",nm);
		      }
		      if(i == 7){
		      	 a = token[0] - 48;
		      	 b = token[1] - 48 ;
		      	 c = token[2] - 48;
		      	if(c >= 0 && c <=9){
		      		 nm = a * 100 + b * 10 +c;
		      	}else{
		      		nm = a * 10 + b;
		      	}
		      	ntw[j] = nm;
		      	//printf("%d\n",nm);
		      }
		      token = strtok(NULL, ",");
		      i++;
		   }
		   j++;
   }

   avg = avgmark(n-1,eng);
   printf("Avg mark in English: %f\n",avg);
   avg = avgmark(n-1,mat);
   printf("Avg mark in Math: %f\n",avg);
   avg = avgmark(n-1,cse);
   printf("Avg mark in Cse: %f\n",avg);
   avg = avgmark(n-1,elec);
   printf("Avg mark in Elec: %f\n",avg);
   avg = avgmark(n-1,ntw);
   printf("Avg mark in Ntw: %f\n",avg);

   maxofsub(n-1,eng,stdname,"English");
   maxofsub(n-1,mat,stdname,"Math");
   maxofsub(n-1,cse,stdname,"Cse");
   maxofsub(n-1,elec,stdname,"Electronics");
   maxofsub(n-1,ntw,stdname,"Networks");
  
   return(0);
}