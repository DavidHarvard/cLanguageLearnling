/*
## 练习2-2
### 问题描述
在不使用 `&&` 或 `||` 的条件下编写一个与上面的 `for` 循环语句等价的循环语句。*/


/*
原来的for循环语句
for(i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
*/

enum loop{YES, NO};
enum loop isLoop = YES;
while(isLoop == YES) {
    if(i >= lim -1) isLoop = NO;
    else if ((c = getchar()) != '\n') isLoop = NO;
    else if(c == EOF) isLoop = NO;
    else{
        s[i] = c; 
        ++i;
    } 
}