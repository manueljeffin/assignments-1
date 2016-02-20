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
        printf("Displaying List::");
        while(l!=NULL){
            printf("%d",l->data );
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



List add(List l,List m,int lenL,int lenM){
    int i,j,k,num1,num2,carry=0,dsum=0,tsum;
    List tt = createList();
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
        insert(tt,dsum);
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
        insert(tt,dsum);
    }
    if(carry>0){
        insert(tt,carry);
    }
    return tt;
}
int main(int argc, char* argv[]){
    List l = createList();
    List m = createList();
    List sum;
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
        sum=add(l,m,len1,len2);
    }else{
        sum=add(m,l,len2,len1);
    }
    Display(sum);
    return 0;
}