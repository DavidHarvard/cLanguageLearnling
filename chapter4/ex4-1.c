

## 练习4-1  
### 问题描述  
编写函数strrindex(s, t)，它返回字符串t在s中最右边出现的位置。如果s中不包含t，则返回-1。  
### 问题解答  
解法一：  
``` C
int strrindex(char s[], char t[]){
    int i, j, k, pos;
    pos = -1;
    for(i = 0; s[i] != '\0'; ++i){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k){
            ;
        }
        if(k > 0 && t[k] == '\0')
            pos = i;
    }
    return pos;
}
```  
类似于教材P59的strindex函数，只是教材上找到匹配即返回，该函数不返回，而仅仅记录本次匹配的位置，所以退出循环后， `pos` 保存的是最后一次匹配的位置，即最右边的位置。  

解法二：  
``` C
#include<string.h>
int strrindex(char s[], char t[]){
    int i, j, k;
    for(i = strlen(s) - strlen(t); i >= 0; --i){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k){
            ;
        }
        if(k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

    int striindex(char []s,char []t){
        int index , i , j , k;
        for(i = 0 ; i < strlen(s) ; i++){
            for(j = 0 , k = i; j < strlen(t) && s[k] == t[j]; j++ , k++){
                ;
            }
            if(j = (strlen(t) - 1)) index = i;
            if( index != 0) return index;
        }
        return -1;
    }

    