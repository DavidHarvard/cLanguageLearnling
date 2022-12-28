#include<stdio.h>
//计算输入的字符有多少是数字有多少是其他字符 简单学习一下数组
int main(){
    int c , i, nwhite , nother ;
    int ndigit[10];

    nwhite = nother = 0;
    for(int i=0; i<10; ++i){
        ndigit[i] = 0;
    }
    while((c = getchar()) != EOF){
        //用于判断c中的字符是否为数字 如果是数字那么对应的数值是 c - '0'
        if(c >= '0' && c <= '9'){
            ++ndigit[c-'0'];
        }
        else if(c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;
    }
    printf("digits = ");
    for(int i=0; i<10; ++i){
        printf("%d", ndigit[i]);
    }
    printf(", white space = %d , other = %d\n", nwhite, nother);
    return 0;
}