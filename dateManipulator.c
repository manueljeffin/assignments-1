/*
*
*  Date Manipulator
*	
*											- Akash.G
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int leapDays[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int Days[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int leap(int yr){
	if(yr % 400 == 0){
		return 1;
	}else if(yr % 100 == 0){
		return 0;
	}else if(yr % 4 == 0){
		return 1;
	}else{
		return 0;
	}
}

struct date{
	int year;
	int month;
	int day;
};


/* Validations are mandatory in most of the modules since the components of dates
are accessed in separate modules like year(),month(),... */


// 1. Returns the year

int year(struct date * dt){
	if(dt->year > 0){
		return dt->year;
	}else{
		printf("Invaild yea1r\n");
		exit(0);
	}
}

// 2. Returns the previous year

int prevYear(struct date * dt){
	int diff = dt->year - 1;
	if(diff > 0){
		return diff;
	}else{
		printf("Invaild year\n");
		exit(0);
	}
}

// 3. Month in number

int month(struct date * dt){
	if(year(dt) && dt->month > 0 && dt->month <= 12){
		return dt->month;
	}else{
		printf("Invaild month\n");
		exit(0);
	}
}

// 4. Month in words

char * monthWord(struct date * dt){
	char **month2 = (char *[]){"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug",
						"Sep","Oct","Nov","Dec"};
	if(dt->month > 0 && dt->month <= 12){
		return month2[dt->month-1];
	}else{
		printf("Invaild month\n");
		exit(0);
	}
}

// 5. Previous month in words

char * prevMonthWord(struct date * dt){
	char **month2 = (char *[]){"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug",
						"Sep","Oct","Nov","Dec"};
	if(dt->month > 1 && dt->month <= 12){
		return month2[dt->month-2];
	}else{
		printf("Invaild month\n");
		exit(0);
	}
}

// 6. Day in number

int day(struct date *dt){
	int leaap;
	int thirty_months[12]={0,0,0,1,0,1,0,0,1,0,1,0};
	int thirty1_months[12]={1,0,1,0,1,0,1,1,0,1,0,1};
	if(year(dt)){
		leaap = leap(dt->year);
		//printf("leap::%d\n",leaap );
		if(dt->month == 2 && leaap && dt->day >= 1 && dt->day <= 29){
			return dt->day;
		}else if(dt->month == 2 && dt->day >= 1 && dt->day <=28){
			return dt->day;
		}else if(thirty1_months[dt->month - 1] && dt->day >= 1 && dt->day <= 31){
			return dt->day;
		}else if(thirty_months[dt->month - 1] && dt->day >= 1 && dt->day <= 30){
			return dt->day;
		}else{
			printf("Invalid Date\n");
			exit(0);
		}

	}else{
		printf("Invalid date\n");
		exit(0);
	}
}



int validate(struct date * dt){
	if(year(dt) && month(dt) && day(dt)){
		//printf("Validated::%d::%d::%d\n",dt->year,dt->month,dt->day );
		return 1;
	}else{
		return 0;
	}
}
// 8. Day index of the year

int dayIndex(struct date * dt){
	int index = 0,i,mprev;
	if(validate(dt)){
		if(leap(dt->year)){
			index += dt->day;
			mprev = dt->month - 1;
			for(i=0;i < mprev; i++){
				index += leapDays[i];
			}
			return index;
		}else{
			index += dt->day;
			mprev = dt->month - 1;
			for(i=0;i < mprev; i++){
				index += Days[i];
			}
			return index;
		}
	}else{
		printf("Invaild Date\n");
		exit(0);
	}
}

// 9. Date before N days

struct date * dateBefore(struct date * dt,int n){
	if(validate(dt)){
		int diff = dt->day - n;
		struct date * tmp;
		tmp = (struct date *)malloc(sizeof(struct date));
		if( diff > 0){
			tmp->year = dt-> year;
			tmp->month = dt->month;
			tmp->day= diff;
			return tmp;
		} else if ( diff == 0){
			int monthDiff = dt->month - 1;
			if ( monthDiff > 0){
				tmp->year = dt->year;
				tmp->month = dt->month - 1;
				if(leap(dt->year)){
					tmp->day = leapDays[tmp->month - 1];
				}else{
					tmp->day = Days[tmp->month - 1];
				}
			}else if (monthDiff == 0){
				tmp->year = prevYear(dt);
				tmp->month = 12;
				tmp->day = 31;
			}
			return tmp;
		}else{
			int monthDiff = dt->month - 1;
			if ( monthDiff > 0){
				tmp->year = dt->year;
				tmp->month = dt->month - 1;
				if(leap(dt->year)){
					tmp->day = leapDays[tmp->month - 1];
				}else{
					tmp->day = Days[tmp->month - 1];
				}
			}else if (monthDiff == 0){
				tmp->year = prevYear(dt);
				tmp->month = 12;
				tmp->day = 31;
			}
			diff *= -1;
			
		}
		return dateBefore(tmp,diff);
	}else{
		printf("Invaild date\n");
		exit(0);
	}
}



int numberOfDays(struct date * dt){
	int num = 0,year = dt->year,month=dt->month,day=dt->day,i;
	int mprev,a,b;
	if(validate(dt)){
		mprev=month-1;
		a = year / 4;
		b= year - a - 1 ;
		num = a * 366 + b * 365;
		if(leap(year)){
			for(i=0;i<mprev;i++){
				num += leapDays[i];
			}
		}else{
			for(i=0;i<mprev;i++){
				num += Days[i];
			}
		}
		num += day;
	}else{
		printf("Invalid date\n");
		exit(0);
	}
	return num;
}

// 10. Difference in days between 2 days

int dateDifference(struct date *dt1,struct date * dt2){
	int a,b;
	a = numberOfDays(dt1);
	b = numberOfDays(dt2);
	return abs(a-b);
}

// 7. Day Name

 char * dayWord(struct date * dt){
 	char ** day = (char *[]){"Sunday","Monday","Tuesday","Wednesday","Thrusday","Friday","Saturday"};
 	int num = numberOfDays(dt)-2;
 	return day[(num%7)];
 }

int main(int argc, char* argv[]){
	char s[12];
	int y=1,opt;
	struct date dt,*dt2;
	printf("Enter the date\n");
	scanf("%[^\n]",s);
	dt.year=atoi(strtok(s,"-"));
	dt.month=atoi(strtok(NULL,"-"));
	dt.day=atoi(strtok(NULL,"-"));
	char * str;
	str =  dayWord(&dt);
	while(y){
		printf("Menu..\n1. Returns the year\n");
		printf("2. Returns the previous year\n");
		printf("3. Month in number\n4. Month in words\n");
		printf("5. Previous month in words\n6. Day in number\n");
		printf("7. Day Name\n8. Day index of the year\n");
		printf("9. Date before N days\n10. Difference in days between two days\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:{
				int year1 = year(&dt);
				printf("The year is..%d\n",year1);
				break;
			}
			case 2:{
				int prevYr = prevYear(&dt);
				printf("The previous year is...%d\n",prevYr );
				break;
			}
			case 3:{
				int month1 = month(&dt);
				printf("The month is...%d\n",month1 );
				break;
			}
			case 4:{
				char * mon = monthWord(&dt);
				printf("Month in words is....%s\n",mon );
				break;
			}
			case 5:{
				char * mon = prevMonthWord(&dt);
				printf("Previous month in words is...%s\n",mon );
				break;
			}
			case 6:{
				int dy = day(&dt);
				printf("Day in number is...%d\n",dy );
				break;
			}
			case 7:{
				char *dname = dayWord(&dt);
				printf("Day in word is...%s\n", dname );
				break;
			}
			case 8:{
				int dayInd = dayIndex(&dt);
				printf("Day index of the year...%d\n",dayInd );
				break;
			}
			case 9:{
				struct date * dt2;
				int no;
				printf("Enter the number of days u want to go back..\n");
				scanf("%d",&no);
				dt2 = dateBefore(&dt,no);
				printf("The date is..%d::%d::%d\n",dt2->year,dt2->month,dt2->day );
				break;
			}
			case 10:{
				struct date * dt2;
				int diff;
				char  s2[12];
				printf("Enter the 2nd date\n");
				scanf("\n");	
				scanf("%[^\n]",s2);
				dt2->year = atoi(strtok(s2,"-"));
				dt2->month = atoi(strtok(NULL,"-"));
				dt2->day = atoi(strtok(NULL,"-"));
				diff = dateDifference(&dt,dt2);
				printf("The difference is %d days\n", diff);
				break;
			}
		}
		printf("Press 1 to continue or 0 to exit...\n");
		scanf("%d",&y);
	} 
	return 0;

}