//字符串puts(),gets()函数
#include<stdio.h>
#include<string.h>  //字符串函数引用
int main(){
    char str[] = "China\nChengdu";
    puts(str);
    printf("Enter a new string：");
    gets(str);      //gets()函数不安全
    puts(str);
    return 0;
}