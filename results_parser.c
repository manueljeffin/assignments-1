#include <stdio.h>

struct Stud{
	int sno;
	char name[30];
	int marks[5];
	int total;
	char res;
	float cutoff;
};

/*
	Values are directly accessed in total_compute() and cutoff_compute() instead of retrieving them using loop
	inorder to save time
*/

void total_compute(struct Stud s[], int i){

	s[i].total = s[i].marks[0] + s[i].marks[1] + s[i].marks[2] + s[i].marks[3] + s[i].marks[4];

}

void cutoff_compute(struct Stud s[], int i){

	s[i].cutoff = ((s[i].marks[0] / 2) + ( (s[i].marks[1] + s[i].marks[2]) / 4));

}
void result_compute(struct Stud s[], int i){

	if( s[i].marks[0] >= 70 && s[i].marks[1] >= 70 && s[i].marks[2] >= 70 && s[i].marks[3] >= 70 && s[i].marks[4] >= 70){
		s[i].res = 'p';
	}else{
		s[i].res = 'f';
	}

}

void swapit(struct Stud s[], int i, int j){

	struct Stud t;
	t = s[i];
	s[i] = s[j];
	s[j] = t;

}

int main(){

	FILE *fp = fopen( "std.csv" , "r" );
	FILE *fp1 = fopen( "rank.csv" , "w");
	struct Stud s[15];
	struct Stud t;
	int i,j;

	i=0;

	while(!feof(fp)){
		
		fscanf(fp,"%d,%[^,],%d,%d,%d,%d,%d", &s[i].sno, s[i].name, &s[i].marks[0],
			&s[i].marks[1] , &s[i].marks[2], &s[i].marks[3], &s[i].marks[4]);
		
		total_compute(s,i);
		
		cutoff_compute(s,i);
		
		result_compute(s,i);

		//Sorting while getting the input will save huge amount of time...

		for(j=0;j<i;j++){

				if( s[j].cutoff < s[i].cutoff ){
					swapit(s,i,j);
				}else if( s[j].cutoff == s[i].cutoff && s[j].total < s[i].total ){
					swapit(s,i,j);
				}else if( s[j].total == s[i].total && s[j].marks[3] < s[i].marks[3] ){
					swapit(s,i,j);
				}

		}

		i++;
	}

	

	for(i=0;i<15;i++){
		if(s[i].res == 'p'){
			printf("Rank:%d Name:%s\n", i+1, s[i].name);
			fprintf(fp1, "%d,%s,%f,%d,%c,%d,%d,%d,%d,%d\n",i+1,s[i].name,s[i].cutoff,s[i].total,
				s[i].res,s[i].marks[0],s[i].marks[1],s[i].marks[2],s[i].marks[3],s[i].marks[4]);
		}
		
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}