#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct wordList{
    int num_times;
    char str[30];
    struct wordList * next;
};

//Create a word list
struct wordList * CreateList(){
    struct wordList * tmp;
    tmp = (struct wordList*)malloc(sizeof(struct wordList));
    tmp->next = NULL;
    return tmp;
}

//Insert into a word list
void  Insert(char *str,struct  wordList * wrd){
    struct wordList * tmp;
    tmp = (struct wordList *)malloc(sizeof(struct wordList));
    if(tmp != NULL){
        strcpy(tmp->str,str);
        tmp->num_times = 1;
        tmp->next = wrd->next;
        wrd->next = tmp;
    }
}

//Find a word from a word list
int findWord(char * word, struct wordList * wrd){
    struct wordList * tmp;
    tmp = wrd->next;
    while(tmp != NULL){
        if(strcmp(word,tmp->str) == 0){
            tmp->num_times++;
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

//Top 3 Common words
void topThreeWords(struct wordList * wrd){
    struct wordList *common_words[3];
    struct wordList * tmp,* tmp1;
    tmp = wrd -> next;
    
    tmp1 = (struct wordList *)malloc(sizeof(struct wordList));
    strcpy(tmp1->str,"");
    tmp1->num_times=0;
    tmp1->next=NULL;
    common_words[0]=common_words[1]=common_words[2]=tmp1;
    while(tmp != NULL){
        if(tmp->num_times > common_words[0]->num_times){
            if(tmp->num_times > common_words[1]->num_times){
                if(tmp->num_times > common_words[2]->num_times){
                    common_words[1] = common_words[2];
                    common_words[2] = tmp;
                }else{
                    common_words[0] = common_words[1];
                    common_words[1] = tmp;
                }
            }else{
                common_words[0] = tmp;
            }
        }
        tmp = tmp->next;
    }
    printf("\nCommon words:\n");
    printf("%s occurs %d times\n",common_words[2]->str,common_words[2]->num_times);
    printf("%s occurs %d times\n",common_words[1]->str,common_words[1]->num_times);
    printf("%s occurs %d times\n",common_words[0]->str,common_words[0]->num_times);
}

void topThreeLetters(int letters_arr[]){
    char tmp_chr;
    int i,j,tmp;
    char alpha[26];
    
    for(i=0;i<26;i++){
        alpha[i] = (char) i+97;
    }
    for(i=0;i<26;i++){
        for(j=i;j<26;j++){
            if(letters_arr[i] < letters_arr[j]){
                tmp = letters_arr[i];
                letters_arr[i]=letters_arr[j];
                letters_arr[j] = tmp;
                tmp_chr = alpha[i];
                alpha[i] = alpha[j];
                alpha[j] = tmp_chr;
            }
        }
    }
    printf("\nCommon letters:\n");
    printf("%c occurs %d times\n",alpha[0],letters_arr[0]);
    printf("%c occurs %d times\n",alpha[1],letters_arr[1]);
    printf("%c occurs %d times\n",alpha[2],letters_arr[2]);
}

//Displays the words that occur only once
void occuringOnce(struct wordList * wrd){
    struct wordList * tmp;
    tmp = wrd->next;
    printf("\nWords occuring only once:\n");
    while(tmp!=NULL){
        if(tmp->num_times == 1){
            printf("%s occurs only once\n",tmp->str);
        }
        tmp = tmp->next;
    }
}

//Displays the letters that aren't used
void letterUnused(int letters_arr[]){
    int i;
    printf("\nLetters unsued:\n");
    for(i=0;i<26;i++){
        if(letters_arr[i] == 0){
            printf("%c isn't used\n", (char)(i+97) );
        }
    }
}

int main(){
    struct wordList * word_list;
    word_list = CreateList();
    int i,num_letters=0,num_words=0,num_symbols=0,pureword=1;
    int delimiter,letters_arr[26],buffer_arr[26];
    char line[255],buffer[255];
    FILE *fp;
    fp = fopen("file.txt","r");
    
    //initalising letters array
    for(i=0;i<26;i++){
        letters_arr[i] = buffer_arr[i] = 0;
    }
    
    while(!feof(fp)){
        delimiter=0;
        fgets(line,255,fp);
        for(i=0;i<strlen(line);i++){
            //letter count
            if( line[i]  <=  122 && line[i] >= 65 ){
                num_letters++;
                buffer[delimiter]=tolower(line[i]);
                letters_arr[buffer[delimiter++]-97]++;
            }else if( line[i] != ' '){
                if( line[i] != '\n'){
                    pureword=0;
                }
                if( line[i] <= 48 || line[i] >= 57){
                    num_symbols++;
                }
            }
            if(line[i] == ' ' || line[i] == '\n'){
                if( pureword ){
                    buffer[delimiter]='\0';
                    if(!findWord(buffer,word_list)){
                        Insert(buffer,word_list);
                    }
                    delimiter=0;
                    num_words++;
                }else{
                    pureword = 1;
                }
            }
        }
    }
    
    for(i=0;i<26;i++){
        buffer_arr[i] = letters_arr[i];
    }
    topThreeWords(word_list);
    topThreeLetters(letters_arr);
    occuringOnce(word_list);
    letterUnused(buffer_arr);
    
    printf("\n");
    printf("Total Words:%d\nTotal Letters:%d\nTotal Symbols:%d\n\n",num_words,num_letters,num_symbols);
    
    return 0;
}
