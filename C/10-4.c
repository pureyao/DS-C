//三个数由大到小排列
#include<stdio.h>
int main(){
    void exchange(int *p1,int *p2,int *p3);
    int a,b,c,*p1,*p2,*p3;
    printf("please enter 3 number:");
    scanf("%d,%d,%d",&a,&b,&c);
    p1 = &a;
    p2 = &b;
    p3 = &c;
    exchange(p1,p2,p3);
    printf("the order is:%d,%d,%d",a,b,c);
    return 0;
}

void exchange(int *p1,int *p2,int *p3){
    void swap(int *q1,int *q2);
    if(*p1<*p2) swap(p1,p2);
    if(*p1<*p3) swap(p1,p3);
    if(*p2<*p3) swap(p2,p3);
}

void swap(int *q1,int *q2){
    int temp;
    temp = *q1;
    *q1 = *q2;
    *q2 = temp;
}