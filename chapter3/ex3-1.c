/*
## 练习3-1  
### 问题描述  
在上面有关折半查找的例子中，while循环语句内共执行了两次测试，其实只要一次就足够（代价是将更多的测试在循环外进行）。重写该函数，使得在循环内只执行一次测试。比较两个版本函数的运行时间。  
### 问题解答  
*/

/*
用二分查找的方式找在x是否在数组v中 变量n为数组的长度
*/
int binsearch(int x , int v[] , int n)
{
    int low , high , mid;
    low = 0;
    high = n - 1;
    int mid = (high + low) / 2;
    while(low < high && x != v[mid]){
        
        if(x < v[mid]){
            high = mid;
        }
        else if(x > v[mid]){
            low = mid;
        }
      mid = (low + high) / 2; 
    }
    if(x == v[mid]) return mid;
    else{
        return -1;
    }
}

// 两种 方案的执行时间上没有什么差异 我们并没有得到多大的性能改进，反而失掉了代码的可读性