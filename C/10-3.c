//指针变量做函数参数
//改变两个值的大小
#include<stdio.h>
int main(){
    void swap(int*point1,int *point2);
    int *p1,*p2,a,b;
    printf("please enter 2 number:");
    scanf("%d,%d,",&a,&b);
    p1 = &a;
    p2 = &b;
    if (a<b)
    {
        swap(p1,p2);
    }
    printf("max=%d,min=%d",*p1,*p2);        //p1仍指向a,p2仍指向b
    return 0;
}
void swap(int *point1,int *point2){
    int temp;
    temp  = *point1;        //a,b值发生变化，指针未发生变化
    *point1 = *point2;
    *point2 = temp;
}