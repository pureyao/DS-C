#include<stdio.h>
int main(){
    int *p1,*p2,*p,a,b;
    printf("please input 2 number");
    scanf("%d,%d",&a,&b);
    p1 = &a;
    p2 = &b;
    if (a<b)
    {
        p = p1;     //p1,p2指针的值交换，a,b变量并没有改变
        p1 = p2;    //可代替简化：p1 = &b;p2 = &a;
        p2 = p1;
    }
    printf("a=%d,b=%d\n",a,b);
    printf("max=%d,min=%d\n",*p1,*p2);
    return 0;
}