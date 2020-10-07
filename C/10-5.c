//指针数组
//1.p=&a[0]; == p=a;  等价，数组名代表首元素地址
//2. p+1 实际地址 a+1*d ,地址加一个元素大小。
//3.*(p+i),*(a+i),a[i]
#include<stdio.h>
int main(){
    int a[10];
    int i;
    int *p;
    printf("please enter 10 numbers:");
    for (i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }
    // 方法一
    for (i = 0; i < 10; i++)
    {
        printf("%d\t",a[i]);        //数组名和下标标识          这两种方法效率相似
        // printf("%d\t",*(a+i));   //数组名和序号计算地址
    }

    // 方法二
    for (p = a; p < (a+10); p++)    //用指针指向当前的数组元素
    {
        printf("%d\t",*p);          //直接访问，不需要计算地址——效率高
    }
    

    return 0;   
}