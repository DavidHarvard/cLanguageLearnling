#include<stdio.h>
#define IN  1 //inside a word
#define OUT 0 //outside a word
//计算输入单词的数量
int main(int argc, char const *argv[])
{
    /* code */
    int c, nl, nw, nc,state;

    state = OUT;
    //这样的赋值语句等同于n1 = (nw = (nc = 0)); 赋值次序是从右至左的
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n'){
            ++nl;
        }
        if(c == ' '|| c == '\n' || c == '\t'){
                state = OUT;
        }
        else if ( state == OUT ){
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n",nl,nw,nc);
    return 0;
}
