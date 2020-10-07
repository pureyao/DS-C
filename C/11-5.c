//输入月份，返回英文
#include<stdio.h>
int main(){
    int num;
    printf("please input a month:");
    scanf("%d",&num);
    const char *month[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    printf("%s",*(month+num-1));
}