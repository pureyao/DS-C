#include<stdio.h>
int main(){
    int max(int x,int y);
    int a = 10,b = 20;
    int c = max(a,b);
    printf("%d",c);
    return 0;
}
int max(int x,int y){
    int z;
    z = x>y?x:y;        //三元运算符：条件？结果1:结果2         满足条件->结果1，不满足条件->结果2
    return z;
}