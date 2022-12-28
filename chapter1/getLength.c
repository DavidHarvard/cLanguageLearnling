#include<stdio.h>

#define MAXLINE 1000 /* maximum input line length*/
int lineLength(char line[],int maxline);
void copy(char to[] , char from[]);
int main()
{
   
 
    int len ; /*current line length*/
    int max ; /*maximum length seen so far*/
    char line[MAXLINE] ; /*current input line*/
    char longest[MAXLINE] ; /*longest line saved here */

    max = 0;

    while ((len = lineLength(line,MAXLINE)) > 0 )
    {
     if(len > max){
        max = len;
        copy(longest,line);
     }  

     if(max > 0){
        printf("%s",longest);
     }
    }
   printf("最长单词的长度是%d\n" , max);
    return 0;
}

int lineLength(char s[],int lim){
    int input, length;
    printf("请输入你想验证的单词: \n");
    for(length = 0; length < lim - 1 && ((input = getchar())!= EOF && input != '\n'); ++length)
    {
        s[length] = input;
    }
        if(input == '\n'){
            s[length] = input;
            ++length;
        }
        s[length] = '\0';
        return length;
    
}

/*copy 'from' into 'to' ; assume to is big enough  */
void copy(char to[] , char from[]){
        int i = 0;
            while((to[i] = from[i]) != '\0'){
                ++i;
            }
}
