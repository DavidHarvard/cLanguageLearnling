#include<stdio.h>

    int main(){
        int c ;
        int a;
        while((c = getchar()) != EOF){
            a = c - '0';
            printf("a的值是");
            printf("%d", a);
        }
        return 0;
    }