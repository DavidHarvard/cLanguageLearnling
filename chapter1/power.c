#include<stdio.h>

int power(int m,int n);

/* test power function*/

int main(int argc, char const *argv[])
{
    /* code */
    int i;
    // for(i = 1; i < 3 ;i++){
    //     printf("%d %d %d\n",i,power(2,i),power(-3,i));
    // }
    printf("%d",power(2,5));
    return 0;
}
/*power raise base to n-th power; n >= 0*/
int power(int base, int n)
{
    int i , p;
    p = 1;
    for(i = 1; i <= n;++i){
        p = p * base; 
    }
    return p;
}
