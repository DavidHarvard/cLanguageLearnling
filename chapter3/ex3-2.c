/*
## 练习3-2  
### 问题描述  
编写一个函数escape(s, t)，将字符串t复制到字符串s中，
并在复制过程中将换行符、制表符等不可见字符分别转换为 `\n` , `\t` 等
相应可见的转义字符序列。要求使用switch语句。再编写一个具有相关功能的函数，
在复制过程中将转义字符转换为实际字符。
*/

#include<stdio.h>

void escape(char s[] , char t[]);

int main(){
    //printf("\n");
    char t[] = "Hello\n";
    char s[10];

    //printf("这是还没有使用函数的数组t");

    for(int i = 0 ; s[i] != '\0' ; i++){
        printf("%c", s[i]);
    }  
    
    escape(s,t);

    for(int i = 0 ; s[i] != '\0' ; i++){
        printf("%c", s[i]);
    } 
    return 0;
}

// void escape(char s[] , char t[]){
//     int indexOfs , indexOft;
//     for(indexOft = 0 , indexOft = 0; t[indexOft] != '\0'; indexOft++ ){
//         //分为三种情况 
//         // 1.一般实际字符
//         // 2.转义字符'\n'
//         // 3.转义字符'\t'\t是水平制表符 从当前位置移到下一个tab的位置
//         switch(t[indexOft]){
//         case '\n':
//             s[indexOfs++] = '\\';
//             s[indexOfs++] = 'n';
//             break;
//         case '\t':
//             s[indexOfs++] = '\\';
//             s[indexOfs++] = 't';
//             break;
//         default:
//             s[indexOfs++] = t[indexOft];
//             break;

//         }
//     }
//     s[indexOfs++] = '\0';
// }

void escape(char s[], char t[]){
    int i, j;
    for(i = j = 0; t[i] != '\0'; ++i){
        switch(t[i]){
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}  