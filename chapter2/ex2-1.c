/*
练习2-1
### 问题描述
编写一个程序以确定分别由 `signed` 及 `unsigned` 限定的 `char` 、 `short` 、 `int` 与 `long` 类型变量的取值范围。采用打印标准头文件中的相应值以及直接计算两种方式实现。
### 问题解答
利用标准头文件来确定
*/ 
#include<stdio.h>
#include<limits.h>

int main(){
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("signed char max = %d\n", SCHAR_MAX);
    printf("signed short min = %d\n", SHRT_MIN);
    printf("signed short max = %d\n", SHRT_MAX);
    printf("signed int min = %d\n", INT_MIN);
    printf("signed int max = %d\n", INT_MAX);
    printf("signed long min = %ld\n", LONG_MIN);
    printf("signed long max = %ld\n", LONG_MAX);

    printf("unsigned char max = %u\n", UCHAR_MAX);
    printf("unsigned short max = %u\n", USHRT_MAX);
    printf("unsigned int max = %u\n", UINT_MAX);
    printf("unsigned long max = %lu\n", ULONG_MAX);
    return 0;
}