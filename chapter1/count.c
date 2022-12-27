#include<stdio.h>
// count characters in input;1 st version
int main(){
    long nc;
    nc = 0;
    while(getchar() != EOF){
        ++nc;
    }
    printf("%ld\n",nc);
    return 0;
}