//编写一个程序，打印输入单词长度的直方图 水平方向和竖直方向


// 打印水平直方图
#include<stdio.h>
#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0

int main(){
    int c, i, nc, state;
    int len;
    int maxvalue;
    int ovflow;
    int wl[MAXWORD];// 统计指定长度的单词的个数
    state = OUT;
    nc = 0;// 记录单词长度
    ovflow = 0;

    for(i = 0; i < MAXWORD; ++i)
        wl[i] = 0;

    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            if(nc > 0){
                if(nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;
            }
            nc = 0;
        // 单词开头
        }else if(state == OUT){
            state = IN;
            nc = 1;
        }else//单词内部
            ++nc;
    }
    for (int i = 0; i < MAXWORD; i++)
    {
        /* code */
        printf("%d",wl[i]);
    }
    
    maxvalue = 0;
    // 找最大值
    for(i = 1; i < MAXWORD; ++i)
        if(wl[i] > maxvalue)
            maxvalue = wl[i];
    for(i = 1; i < MAXWORD; ++i){
        printf("%5d - %5d : ", i, wl[i]);
        if(wl[i] > 0){
            // 如果计算得到的len小于0，则至少打印一个*
            if((len = wl[i] * MAXHIST / maxvalue) <= 0)
                len = 1;
        }else
            len = 0;
        while(len > 0){
            putchar('*');
            --len;
        }
        putchar('\n');
    }
    if(ovflow > 0)
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
    return 0;
}
