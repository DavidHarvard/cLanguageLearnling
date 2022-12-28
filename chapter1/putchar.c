#include<stdio.h>
/*copy input to output ; 1st version*/
int main(){
    int c;
    while((c = getchar()) != EOF){
        printf("输入的字符：");
        putchar(c);
    }
    printf("%d\n", EOF);
return 0;
}