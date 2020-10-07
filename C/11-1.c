//指针——字符串
#include<stdio.h>
int main(){
    char string[] = "i love china";
    char *string2 = "i love china,too";     //字符指针指向字符串常量
    printf("%s\n",string);
    printf("%c\n",string[5]);
    return 0;
}