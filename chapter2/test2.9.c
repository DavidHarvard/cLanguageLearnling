#include<stdio.h>
int main(){
    int a  = 1 ;
    int b = 2 ;
    int c  = a & b;
    int d = a && b;
    int e = b << 2;
    printf("%d %d %d" , c, d,e);
    return 0;
}