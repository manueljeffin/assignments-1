#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* 
    Words here are considered to be a string containing only aplhabets such as "abc"
    Others strings such as "abc1ac","ab,ad" etc.. are not considered as words
 */

struct wordList{
    
    int num_times;
    char str[30];
    int firstword;
    struct wordList * next;
    
};

struct wordList * CreateList();
void  Insert(char *str,struct  wordList * wrd,int firstword);
int findWord(char * word, struct wordList * wrd,int firstword);
void topThreeWords(struct wordList * wrd);
void topThreeLetters(int letters_arr[]);
void commonFirstWord(struct wordList * wrd);
void occuringOnce(struct wordList * wrd);
void letterUnused(int letters_arr[]);

int main(){
    
    struct wordList * word_list;
    word_list = CreateList();
    int i,num_letters=0,num_words=0,num_symbols=0,pureword=1,len;
    int delimiter,letters_arr[26],buffer_arr[26],prevVal,firstword=1;
    char line[255],buffer[255];#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
    
    /*
     Words here are considered to be a string containing only aplhabets such as "abc"
     Others strings such as "abc1ac","ab,ad" etc.. are not considered as words
     */
    
    struct wordList{
        
        int num_times;
        char str[30];
        int firstword;
        struct wordList * next;
        
    };
    
    struct wordList * CreateList();
    void  Insert(char *str,struct  wordList * wrd,int firstword);
    int findWord(char * word, struct wordList * wrd,int firstword);
    void topThreeWords(struct wordList * wrd);
    void topThreeLetters(int letters_arr[]);
    void commonFirstWord(struct wordList * wrd);
    void occuringOnce(struct wordList * wrd);
    void letterUnused(int letters_arr[]);
    
    int main(){
        
        struct wordList * word_list;
        word_list = CreateList();
        int i,num_letters=0,num_words=0,num_symbols=0,pureword=1,len;
        int delimiter,letters_arr[26],buffer_arr[26],prevVal,firstword=1;
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
            len = strlen(line);
            
            /*
             The increment block in 'for loop' also does the job of assigning the last
             value of the files currently read line to variable to keep track of the paragraph
             */
            
            for(i=0;i<len;i++,prevVal=line[i-1]){
                
                //Paragraph checker 1/2
                if( line[i] == 10 && prevVal == 10){
                    
                    firstword = 1;
                    pureword = 0;
                    
                }else if( line[i]  <=  122 && line[i] >= 65 ){
                    
                    //Counting the number of letters
                    num_letters++;
                    buffer[delimiter]=tolower(line[i]);
                    letters_arr[buffer[delimiter++]-97]++;
                    
                }else if( line[i] != ' '){
                    
                    if( line[i] != '\n'){
                        pureword=0;
                    }
                    
                    //This helps to count the number of symbols
                    if( line[i] <= 48 || line[i] >= 57){
                        num_symbols++;
                    }
                    
                }
                
                if(line[i] == ' ' || line[i] == '\n'){
                    
                    if( pureword ){
                        
                        buffer[delimiter]='\0';
                        
                        //The first condition in 'if' is to eliminate linefeeds
                        if(buffer[0] != 0 && !findWord(buffer,word_list,firstword)){
                            
                            Insert(buffer,word_list,firstword);
                            firstword = 0;
                            
                        }
                        
                        delimiter=0;
                        num_words++;
                        
                    }else{
                        pureword = 1;
                    }
                    
                    //Paragraph checker 2/2
                    firstword = (line[i] == ' ')? 0 : firstword;
                    
                }
                
                
            }
            
            //It is always better to empty the buffer
            buffer[0]='\0';
            
        }
        
        for(i=0;i<26;i++){
            buffer_arr[i] = letters_arr[i];
        }
        
        printf("1)\nTotal Words:%d\n2)\nTotal Letters:%d\n3)\nTotal Symbols:%d\n",
               num_words,num_letters,num_symbols);
        
        printf("4)");
        topThreeWords(word_list);
        
        printf("5)");
        topThreeLetters(letters_arr);
        
        printf("6)");
        commonFirstWord(word_list);
        
        printf("7)");
        occuringOnce(word_list);
        
        printf("8)");
        letterUnused(buffer_arr);
        
        return 0;
        
    }
    
    //Create a word list
    struct wordList * CreateList(){
        
        struct wordList * tmp;
        tmp = (struct wordList*)malloc(sizeof(struct wordList));
        tmp->next = NULL;
        return tmp;
        
    }
    
    //Insert into a word list
    void  Insert(char *str,struct  wordList * wrd,int firstword){
        
        struct wordList * tmp;
        tmp = (struct wordList *)malloc(sizeof(struct wordList));
        
        if(tmp != NULL){
            
            strcpy(tmp->str,str);
            tmp->num_times = 1;
            tmp->next = wrd->next;
            tmp->firstword = firstword;
            wrd->next = tmp;
            
        }
        
    }
    
    //Find a word from a word list
    int findWord(char * word, struct wordList * wrd,int firstword){
        
        struct wordList * tmp;
        tmp = wrd->next;
        
        while(tmp != NULL){
            
            if(strcmp(word,tmp->str) == 0){
                
                tmp->num_times++;
                tmp->firstword += firstword;
                return 1;
                
            }
            
            tmp = tmp->next;
        }
        
        return 0;
        
    }
    
    //Top three most common words [Requirement 4]
    void topThreeWords(struct wordList * wrd){
        
        struct wordList *common_words[3];
        struct wordList * tmp,* tmp1;
        int i;
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
        
        printf("\nTop three most common words:\n");
        
        for(i=2;i>=0;i--){
            printf("'%s' occurs %d times\n",common_words[i]->str,common_words[i]->num_times);
        }
        
    }
    
    //Top three most common letters [Requirement 5]
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
        
        printf("\nTop three most common letters:\n");
        
        for(i=0;i<3;i++){
            printf("'%c' occurs %d times\n",alpha[i],letters_arr[i]);
        }
        
    }
    
    //Most common first word of a paragraph [Requirement 6]
    void commonFirstWord(struct wordList * wrd){
        
        char firstCommonWord[30];
        struct wordList * tmp;
        int i,m=0;
        tmp = wrd -> next;
        
        while( tmp != NULL ){
            
            if(tmp->firstword > m){
                m = tmp->firstword;
                strcpy(firstCommonWord,tmp->str);
            }
            tmp = tmp->next;
            
        }
        
        printf("\nMost common first word of a paragraph is '%s'\n",firstCommonWord);
    }
    //Number of words only used once [Requirement 7]
    void occuringOnce(struct wordList * wrd){
        
        struct wordList * tmp;
        int count = 0;
        tmp = wrd->next;
        
        
        while(tmp!=NULL){
            if(tmp->num_times == 1){
                count++;
            }
            tmp = tmp->next;
        }
        
        printf("\nWords occuring only once:%d\n",count);
        
    }
    
    //All letters not used in the document [Requirement 8]
    void letterUnused(int letters_arr[]){
        
        int i;
        printf("\nLetters unsued:\n");
        
        for(i=0;i<26;i++){
            if(letters_arr[i] == 0){
                printf("'%c' isn't used\n", (char)(i+97) );
            }
        }
        
    }
    

    FILE *fp;
    fp = fopen("file.txt","r");
    
    //initalising letters array
    for(i=0;i<26;i++){
        letters_arr[i] = buffer_arr[i] = 0;
    }
    
    while(!feof(fp)){
        
        delimiter=0;
        
        fgets(line,255,fp);
        len = strlen(line);
        
        /*
        	The increment block in 'for loop' also does the job of assigning the last
        	value of the files currently read line to variable to keep track of the paragraph
         */
        
        for(i=0;i<len;i++,prevVal=line[i-1]){
            
            //Paragraph checker 1/2
            if( line[i] == 10 && prevVal == 10){
                
                firstword = 1;
                pureword = 0;
                
            }else if( line[i]  <=  122 && line[i] >= 65 ){
                
                //Counting the number of letters
                num_letters++;
                buffer[delimiter]=tolower(line[i]);
                letters_arr[buffer[delimiter++]-97]++;
                
            }else if( line[i] != ' '){
                
                if( line[i] != '\n'){
                    pureword=0;
                }
                
                //This helps to count the number of symbols
                if( line[i] <= 48 || line[i] >= 57){
                    num_symbols++;
                }
                
            }
            
            if(line[i] == ' ' || line[i] == '\n'){
                
                if( pureword ){
                    
                    buffer[delimiter]='\0';
                    
                    //The first condition in 'if' is to eliminate linefeeds
                    if(buffer[0] != 0 && !findWord(buffer,word_list,firstword)){
                        
                        Insert(buffer,word_list,firstword);
                        firstword = 0;
                        
                    }
                    
                    delimiter=0;
                    num_words++;
                    
                }else{
                    pureword = 1;
                }
                
                //Paragraph checker 2/2
                firstword = (line[i] == ' ')? 0 : firstword;
                
            }
            
            
        }
        
        //It is always better to empty the buffer
        buffer[0]='\0';
        
    }
    
    for(i=0;i<26;i++){
        buffer_arr[i] = letters_arr[i];
    }
    
    printf("1)\nTotal Words:%d\n2)\nTotal Letters:%d\n3)\nTotal Symbols:%d\n",
           num_words,num_letters,num_symbols);
    
    printf("4)");
    topThreeWords(word_list);
    
    printf("5)");
    topThreeLetters(letters_arr);
    
    printf("6)");
    commonFirstWord(word_list);
    
    printf("7)");
    occuringOnce(word_list);
    
    printf("8)");
    letterUnused(buffer_arr);
    
    return 0;
    
}

//Create a word list
struct wordList * CreateList(){
    
    struct wordList * tmp;
    tmp = (struct wordList*)malloc(sizeof(struct wordList));
    tmp->next = NULL;
    return tmp;
    
}

//Insert into a word list
void  Insert(char *str,struct  wordList * wrd,int firstword){
    
    struct wordList * tmp;
    tmp = (struct wordList *)malloc(sizeof(struct wordList));
    
    if(tmp != NULL){
        
        strcpy(tmp->str,str);
        tmp->num_times = 1;
        tmp->next = wrd->next;
        tmp->firstword = firstword;
        wrd->next = tmp;
        
    }
    
}

//Find a word from a word list
int findWord(char * word, struct wordList * wrd,int firstword){
    
    struct wordList * tmp;
    tmp = wrd->next;
    
    while(tmp != NULL){
        
        if(strcmp(word,tmp->str) == 0){
            
            tmp->num_times++;
            tmp->firstword += firstword;
            return 1;
            
        }
        
        tmp = tmp->next;
    }
    
    return 0;
    
}

//Top three most common words [Requirement 4]
void topThreeWords(struct wordList * wrd){
    
    struct wordList *common_words[3];
    struct wordList * tmp,* tmp1;
    int i;
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
    
    printf("\nTop three most common words:\n");
    
    for(i=2;i>=0;i--){
        printf("'%s' occurs %d times\n",common_words[i]->str,common_words[i]->num_times);
    }
    
}

//Top three most common letters [Requirement 5]
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
    
    printf("\nTop three most common letters:\n");
    
    for(i=0;i<3;i++){
        printf("'%c' occurs %d times\n",alpha[i],letters_arr[i]);
    }
    
}

//Most common first word of a paragraph [Requirement 6]
void commonFirstWord(struct wordList * wrd){
    
    char firstCommonWord[30];
    struct wordList * tmp;
    int i,m=0;
    tmp = wrd -> next;
    
    while( tmp != NULL ){
        
        if(tmp->firstword > m){
            m = tmp->firstword;
            strcpy(firstCommonWord,tmp->str);
        }
        tmp = tmp->next;
        
    }
    
    printf("\nMost common first word of a paragraph is '%s'\n",firstCommonWord);
}
//Number of words only used once [Requirement 7]
void occuringOnce(struct wordList * wrd){
    
    struct wordList * tmp;
    int count = 0;
    tmp = wrd->next;
    
    
    while(tmp!=NULL){
        if(tmp->num_times == 1){
            count++;
        }
        tmp = tmp->next;
    }
    
    printf("\nWords occuring only once:%d\n",count);
    
}

//All letters not used in the document [Requirement 8]
void letterUnused(int letters_arr[]){
    
    int i;
    printf("\nLetters unsued:\n");
    
    for(i=0;i<26;i++){
        if(letters_arr[i] == 0){
            printf("'%c' isn't used\n", (char)(i+97) );
        }
    }
    
}

