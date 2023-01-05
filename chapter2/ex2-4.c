/*
重新编写函数squeeze(s1, s2)，将字符串s1中任何与字符串s2中字符匹配的字符都删除。
*/

#include<stdio.h>

int main(){
    return 0;
}

void squeeze(char[] s1,char[] s2){
    for(int i=0; s1[i] != '\0'; i++){
        for(int j=0; s2[j] != '\0'; j++){
            if(s1[i] == s2[j]){
                s1[i] = s1[i+1];
            }
        }
    }
};

void squeeze(char s1[], char s2[]){
    int i, j, k;
    for(i = k = 0; s1[i] != '\0'; ++i){
        // 遍历s2，执行到字符串结束或者找到一个匹配字符
        for(j = 0; s2[j] != '\0' && s2[j] != s1[i]; ++j)
            ;
        // 如果没有找到匹配的，就添加，如果找到匹配的，就跳过
        if(s2[j] == '\0')
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}