    /*
重新编写大写字母转小写字母的函数lower，并用条件表达式代替其中的if-else结构。
    */
    int lower(int c){
        return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c; 
    }