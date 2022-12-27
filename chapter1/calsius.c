#include<stdio.h>
// %d 按照十进制整型数打印
// %6d 按照十进制整型数打印,至少有6个字符宽
// %6.2f 按照浮点数打印，至少6个字符宽，小数点后有两位小数

//类似于java里面定义常量 定义的#define指令行的结尾没有；
#define LOWER 0 //lower limit of table
#define UPPER 300//upper limit
#define STEP 20 // STEP SIZE
int main(){
    float fahr , celsius ;
    float lower , upper , step;
    fahr = 0;
    lower = 0;
    upper = 300;
    step = 20;

    while(fahr <= upper){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f\t%6.1f\n",fahr,celsius);
        fahr += step;
    }
    printf("接下来将逆序输出温度函数\n");
    for(fahr = UPPER; fahr >= LOWER; fahr -= STEP){
       celsius = (5.0/9.0) * (fahr-32.0);
       printf("%3.0f\t%6.1f\n",fahr,celsius); 
    }
    return 0;
}