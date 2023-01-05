chapter4 函数与程序结构

4.3 外部变量

计算逆波兰表达式的代码
 #include <stdio.h>
 #include <stdlib.h> /* for atof() */
 #define MAXOP 100 /* max size of operand or operator */
 #define NUMBER '0' /* signal that a number was found */
 int getop(char []);
 void push(double);
 double pop(void);
 /* reverse Polish calculator */
 main()
 {
 int type;
 double op2;
 char s[MAXOP];
  while ((type = getop(s)) != EOF) {
    switch (type) {
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
    case '/':
        op2 = pop();
        if (op2 != 0.0)
            push(pop() / op2);
        else
            printf("error: zero divisor\n");
 break;
    case '\n':
        printf("\t%.8g\n", pop());
 break;
    default:
        printf("error: unknown command %s\n", s);
 break;
      }
    }
    return 0;
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
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
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

 4.6静态变量
 static char buf[BUFSIZE];
 static int bufp = 0;

 int getch(void){}

 void ungetch(int c){}

 此时bufp和buf是外部变量但是不能被getch与ungetch函数所调用
 外部的static也可以用于申明与函数 通常情况下 函数名字是可以全局访问的
 对整个程序的各个部分可见外 但是如果把函数声明为static类型 则函数名除了对待该函数所在的文件可见之外，其他文件都无法访问

 static也可以声明在内部变量 static类型的内部变量同自动变量一样，是某个
 特定函数的局部变量，只能在该函数中使用，但是他与自动变量不同的是，无论函数是否被调用，他一直存在，而不是像自动变量那样，随着所在函数被调用和退出而存在和消失。 换句话说，static类型的内部变量是一种只能在某个特定函数中使用但是一直占据存储空间得变量

4.8 程序块结构
变量i的作用域是if语句的真分支 这个i与程序块外声明的i无关 每次进入程序块时
在程序块内部声明以及初始化的内部分量都被初始化。静态变量只在第一次进入程序块时初始化一次
if(n > 0){
    int i;

    for(i = 0; i < n i++){

    }
}
