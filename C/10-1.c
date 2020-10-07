//指针变量
//*p = 1;   把1赋值给指针指向的变量——a=1
#include<stdio.h>
int main(){
    int a=100,b=10;
    int *point1,*point2;

    point1 = &a;    //&——取地址符号，取a的地址
    point2 = &b;    //地址赋值给point1,point2，而不是*point1,*point2
    printf("a=%d,b=%d\n",a,b);
    printf("a:%p,b:%p\n",point1,point2);
    printf("*point1=%d,*point2=%d\n",*point1,*point2);  //*——指向变量
    return 0;
}