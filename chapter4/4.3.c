 #include <stdio.h>
 #include <stdlib.h> /* for atof() */
 #include <string.h>
 #include <math.h>

 #define MAXOP 100 /* max size of operand or operator */
 #define NUMBER '0' /* signal that a number was found */
 #define NAME 'n' // 标记库函数名字


 int getop(char []);
 void push(double);
 double pop(void);
 void mathfnc(char s[]);
 /* reverse Polish calculator 逆波兰表达式的计算*/
 main()
 {
 int type , i , var = 0;
 double op2 , op2;
 char s[MAXOP];
 double variable[26];

 for( i = 0; i < 26; i++){
    variable[i] = 0.0;
 }

  while ((type = getop(s)) != EOF) {
    switch (type) {
/*
## 练习4-6  
### 问题描述  
给计算器程序增加处理变量的命令（提供26个具有单个英文字母变量名的变量很容易）。
增加一个变量存放最近打印的值。
*/
    case '=' : 
    //var 在swich循环的末尾用var = type 来进行赋值了
         pop();
        if(var >= 'A' && var <= 'Z')
            variable[var - 'A'] = pop();
        else
            printf("error: no variable name \n")
        break;
    case NUMBER:
        push(atof(s));
        break;
            case '+':
                push(pop() + pop());
        break;
            case '*':
                push(pop() * pop());
        break;
            case '-':
                op2 = pop();
                push(pop() - op2);
 break;
    case NAME:
    mathfnc(s);
 /* 
    ## 练习4-3  
    ### 问题描述  
    在基本框架上对计算器程序进行扩充。在该程序中加入取模 `%` 运算，并注意负数的情况。  
  */
    case'%':
        op2 = pop();
        if(op2 != 0) {
            push(fmod(pop() , op2));
        else
            printf("error: zero divisor\n");
            break;
        }
    case '/':
        op2 = pop();
        if (op2 != 0.0)
            push(pop() / op2);
        else
            printf("error: zero divisor\n");
        break;
    //打印栈顶元素
        case:'?':
        op2 = pop();
        printf("\t%.8g\n", op2);
        push(op2);
        break;

    //清空栈
        case:'c':
        clear();
        break;

    //复制栈顶元素
        case 'd':
        op2 = pop();
        push(op2);
        push(op2); 
        break;   

        case 's':
        op1 = pop();
        op2 = pop()
        push(op1);
        push(op2);
        break;

        case '\n':
            printf("\t%.8g\n", pop());
    break;
    default:
        if(type >= 'A' && type <= 'Z')
            push(variable[type - 'A']);
        else if(type == 'v')
            push(v);
        else
            printf("error: unknown command %s\n", s);
        break;
      }
      var = type
    }
    return 0;
 }

/*
## 练习4-7  
### 问题描述  
编写一个函数ungets(s)，将整个字符串压回到输入中。ungets函数
需要使用buf和bufp吗？它能否仅使用ungetch函数？
*/

    void ungets(char []s){
        int len = strlen(s);
        void ungetch(int c);
        while(len > 0){
            ungetch(s[--len]);
        }
}

//ungets函数不需要直接对buf和bufp进行操作，buf，bufp和出错检查将由函数ungetch处理。  


 void clear(void){
    //sp是堆栈的指针 清空栈函数 只需将sp设为0
    sp = 0;
 }

/*
## 练习4-5  
### 问题描述  
给计算器程序增加访问sin、exp与pow等库函数的操作。 
*/

//处理math相关的函数
 void mathfnc(char []s){
    double op2;
    //strcpm 是用于对两个字符串进行比较(区分大小写)
    // 如果返回值 < 0 , 则表示str1 小于 str2
    if(strcmp(s,"sin") == 0)
        push(sin(pop()));
    else if(strcpm(s,"exp") == 0)
        push(exp(pop()));
    else if(strcmp(s,"cos") == 0)
        push(cos(pop()));
    else if(strcpm(s,'pow') == 0)
        push(pow(pop(),op2));
    else 
        prinf("error: %s not supported\n",s);
 }

 #define MAXVAL 100 /* maximum depth of val stack */
 int sp = 0; /* next free stack position */
 double val[MAXVAL]; /* value stack */
 /* push: push f onto value stack */
 void push(double f)
 {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
 }
 /* pop: pop and return top value from stack */
 double pop(void)
 {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
    return 0.0;
    }
 }
/*
    该函数获取下一个运算符或操作数。他需要跳过空格与制表符 如果下一个字符不是数字或者小数点则返回 
    否则将这些数字字符串收集起来 并返回NUMBER
    通过调用库函数优化
*/

 #include <ctype.h>
 int getch(void);
 void ungetch(int);
 /* getop: get next character or numeric operand */
 int getop(char s[])
 {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
 ;
    s[1] = '\0';
    i = 0;
    if(isLower(c)){
        while(islower(s[++i]) = c = getchar())
            ;
            if(c != EOF) ungetch(c);
        if(strlen(s) > 1) return NAME; //长度大于1，是函数
        else return c; //长度为1，可能是个命令
    }
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
    ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
    ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
 }

/*
    我们如果不超前读取输入的话 无法确定获取的输入是否是数字的最后一位
    getch函数就是从缓冲区中读取字符 当缓冲区位空时就从getchar()函数直接从输入中读取字符 这里还需要一个下标变量来记住缓冲区中当前字符的变量
    getch函数用于读入下一个待处理的字符 而 ungetch函数则用于把字符放回到输入中
*/

 #define BUFSIZE 100
 char buf[BUFSIZE]; /* buffer for ungetch */
 int bufp = 0; /* next free position in buf */
 int getch(void) /* get a (possibly pushed-back) character */
 {
    return (bufp > 0) ? buf[--bufp] : getchar();
 }
    void ungetch(int c) /* push character back on input */
 {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
 }