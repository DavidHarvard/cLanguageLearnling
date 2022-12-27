#include<stdio.h>
//验证布尔表达式中getchar()!=EOF的取值是0还是1
int main(){
    int c ;
    while(c = (getchar() != EOF)){
        printf("%d\n",c);
    }
    printf("%d\n",c);
}