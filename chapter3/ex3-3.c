/*
## 练习3-3  
### 问题描述  
编写函数expand(s1, s2)，将字符串s1中类似a-z一类的速记符号在字符串s2中扩展为等价的完整列表abc···xyz。该函数能够处理大小写字母和数字，并可以处理a-b-c、a-z0-9与-a-z等类似情况。作为前导和尾随的-字符原样打印。 
*/
#include<stdio.h>

    void expand(char s1[],char s2[]);

    int main(){
        char s1[] = "a-z";
        char s2[100] = "";
        expand(s1,s2);
        for(int i = 0; s2[i] != '\0' ; i++){
            printf("%c",s2[i]);
        } 
        return 0;
    }

    void expand(char s1[],char s2[]){
        char c;
        int indexOFs1 , indexOFs2;
        indexOFs1 = indexOFs2 = 0;
        while((c = s1[indexOFs1++]) != '\0'){
            //遇到 - （1-2） 此时c的值是1 s1[indexOFs1]的值是'-' s1[indexOF1 + 1] 的值是3
            if(s1[indexOFs1] == '-' && s1[indexOFs1 + 1] > c){
                indexOFs1++;
                while(c < s1[indexOFs1]){
                    s2[indexOFs2++] = c++;
                }

            }
        }
        s2[indexOFs2] = '\0';
    }