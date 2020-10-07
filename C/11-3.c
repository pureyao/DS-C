//p++遍历数组
#include<stdio.h>
int main(){
    char a[] = "i love china",b[20],*p1,*p2;
    p1 = a;
    p2 = b;
    for (;*p1!='\0'; p1++,p2++)
    {
        *p2 = *p1;
    }
    *p2 = '\0';
    printf("string a:%s\n",a);
    printf("string b:%s\n",b);
    return 0;
}