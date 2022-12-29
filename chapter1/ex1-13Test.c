#include<stdio.h>
#define MAXWORD 11


int main()
{
    int wordLengthList[MAXWORD];
    int input;
    int wordLength = 0;

    for(int i = 0; i < MAXWORD; ++i){
    wordLengthList[i] = 0;
    }
    
    while((input = getchar()) != EOF){

        ++wordLength;

        if(input == ' ' || input == '\t' || input == '\n'){

            printf("此时wordLength的值是 %d\n", wordLength);
            ++wordLengthList[wordLength];
            printf("此时wordLengthList的值是 %d\n",wordLengthList[wordLength]);
            wordLength = 0;
         }
    }

    printf("输入结束\n");

       for (int i = 0; i < MAXWORD; i++)
    {
        /* code */
        printf("%d",wordLengthList[i]);
    }
    return 0;
}
