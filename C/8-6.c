//strcat(a,b) 拼接函数   strlen(a)求长度(不含\0)   strcpy(a,b)复制b到a
//不能用赋值语句将一个字符串常量直接给一个字符数组。如下面两行是错误的：str1 = str2;

//strcmp(a,b) 对比函数
// 如果全部字符相同，则认为两个字符串相同。
// 若出现不同的字符，则以第 1 对不相同的字符的比较结果为准。例如："A"<"D"，"e">"E"，"these">"that"，"computer">"compare"。
// 比较结果由函数值带回。
// 字符串 1=字符串 2，则函数值为 0
// 字符串 1>字符串 2，则函数值为一个正整数
// 字符串 1<字符串 2，则函数值为一个负整数
// 关于字符串处理函数，还有 strlwr 函数（转换为小写的函数）、strupr 函数（转换为大写的函数）strncpy 函数等其它函数，我们这里不再一一阐述，有兴趣的小伙伴可以查询相关内容。
#include<stdio.h>
#include<string.h>  //字符串函数引用
int main(){
    char str1[30] = "This is str1 ";
    char str2[] = "and str2";
    char str3[] = "new";
    printf("%s\n",strcat(str1,str2));
    char str4[50];
    strcpy(str4,str3);  //复制后到前
    printf("%s",str4);
    return 0;
}