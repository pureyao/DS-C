/*
打开文件——fopen(文件名,使用方式)
FILE *fp;
fp = fopen("a1","r");   r:read读入

关闭文件——fclose(文件指针)
fclose(fp);
*/
//顺序读写
//fgetc(fp)——从fp处读取一个字符
//fputc(ch,fp)——想fp处写入ch字符

//从键盘输入一些字符，逐个把它们送到磁盘上去，直到用户输入一个“ # ”为止。
#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp;
    char ch,filename[10];
    printf("Please enter the file name:");
    scanf("%s",filename);
    // 如果文件不存在，fopen 会建立该文件
    if((fp=fopen(filename,"w"))==NULL){    // 打开输出文件并使 fp 指向此文件
        printf("Unable to open this file\n");     // 如果打开出错，就输出“打不开”的信息
        exit(0);     // 终止程序
    }
    ch=getchar();     // 用来接收最后输入的回车符
    printf("Please enter a string  in the disk（Ends with a #）：");
    ch=getchar();     // 接收从键盘输入的第一个字符
    while(ch!='#'){     // 当输入 # 时结束循环
        fputc(ch,fp);
        putchar(ch);
        ch=getchar();
    }
    fclose(fp);
    putchar(10);
    return 0;
}