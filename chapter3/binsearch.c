#include<stdio.h>

    int binsearch(int x , int v [], int n);
    int main(){
    
        int v[] = {0,1,2,3,4,5,6};
        int result = binsearch(5,v,7); 
        printf("%d\n",result);

    }
/*
用二分查找的方式找在x是否在数组v中 变量n为数组的长度
*/
int binsearch(int x , int v[] , int n)
{
    int low , high , mid;
    low = 0;
    high = n - 1;
    while(low < high){
        mid = (high + low) / 2;
        
        if(x < v[mid]){
            high = mid;
        }
        else if(x > v[mid]){
            low = mid;
        }
        else return mid;
    }
    return -1;
}