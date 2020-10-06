// 递归函数
// 计算n!
#include<stdio.h>
int main(){
    int fac(int n);
    int n,y;
    printf("please input a number:");
    scanf("%d",&n);
    if (n<0)
    {
        printf("error");
    }
    else
    {
        y = fac(n);
        printf("%d!=%d",n,y);
    }
    return 0;   
}
int fac(int n){
    int f;
    if (n==0||n==1)
    {
        f = 1;
    }
    else
    {
        f = fac(n-1)*n;
    }
    return f;    
}