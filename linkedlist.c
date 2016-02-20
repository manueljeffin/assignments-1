#include <stdio.h>
#include <stdlib.h>

// for testing with different inputs modify the insert statements in main()

typedef struct Node * List;

struct Node{
	int data;
	List next;
};

List createList(){
	List l = (List)malloc(sizeof(struct Node));
	l->next = NULL;
	return l;
}

int isEmpty( List l ){
	return l->next == NULL;
}

void insert (List l,int data){
	List t = (List)malloc(sizeof(struct Node));
	t->next = l->next;
	t->data = data;
	l->next = t;
}

void Display(List l){
	if(!isEmpty(l)){
		l=l->next;
		printf("Displaying List..");
		while(l!=NULL){
			printf("%d..",l->data );
			l=l->next;
		}
	}else{
		printf("The list is empty\n");
	}
	printf("\n");
}

int listLen(List l){
	int len = 0;
	while(l->next!=NULL){
		l=l->next;
		len++;
	}
	return len;
}

void add(List l,List m,int lenL,int lenM){
	int i,j,k,num1,num2,carry=0,dsum=0,tsum;
	int sarr[lenL+1];
	for(i=0;i<lenL+1;i++){sarr[i]=0;}
	for(i=lenL,k=lenM;k>0;i--,k--){
		List t = l;
		j = i;
		while(j>0){
			t = t->next;
			j--;
		}
		num1 = t->data;
		t = m;
		j = k;
		while(j>0){
			t = t->next;
			j--;
		}
		num2 = t->data;
		tsum = num1+num2+carry;
		dsum = tsum % 10;
		carry = tsum / 10;
		sarr[i]= dsum;
		//printf("i::%d sarr[]::%d\n",i,sarr[i] );
	}
		
	int diff = lenL - lenM;
	for(i = diff;i>0;i--){
		List t = l;
		j = i;
		while(j>0){
			t = t->next;
			j--;
		}
		num1 = t->data;
		tsum = num1 + carry;
		dsum = tsum % 10;
		carry = tsum /10;
		sarr[i] = dsum;
	}
	sarr[0] = carry;
	printf("Sum:");
	for(i=0;i<=lenL;i++){
		printf("%d",sarr[i] );
	}
	printf("\n");
}
int main(int argc, char* argv[]){
	List l = createList();
	List m = createList();
	insert(l,6);
	insert(l,6);
	insert(m,6);
	insert(m,6);
	insert(m,6);
	Display(l);
	Display(m);
	int len1,len2;
	len1 = listLen(l);
	len2 = listLen(m);
	if(len1 > len2){
		add(l,m,len1,len2);
	}else{
		add(m,l,len2,len1);
	}
	return 0;
}