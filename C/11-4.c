//1.数组名做参数
// #include<stdio.h>
// int main(){
//     void copy_string(char from[],char to[]);
//     char a[] = "I'm a teacher";
//     char b[] = "I'm a programer";
//     printf("string a:%s\nstring b:%s\n\n",a,b);
//     printf("copy a to b:\n");
//     copy_string(a,b);
//     printf("string a:%s\nstring b:%s",a,b);
//     return 0;
// }
// void copy_string(char from[],char to[]){
//     int i = 0;
//     while (from[i]!='\0')
//     {
//         to[i] = from[i];
//         i++;
//     }
//     to[i] = '\0';
    
// }



//字符指针做实参
// #include<stdio.h>
// int main(){
//     void copy_string(char from[],char to[]);
//     char a[] = "I'm a teacher";
//     char b[] = "I'm a programer";
//     char *from = a,*to = b;
//     printf("string a:%s\nstring b:%s\n\n",a,b);
//     copy_string(from,to);
//     printf("copy a to b:\n");
//     printf("string a:%s\nstring b:%s\n\n",a,b);
//     return 0;
// }
// void copy_string(char from[],char to[]){
//     int i = 0;
//     while (from[i]!='\0')
//     {
//         to[i] = from[i];
//         i++;
//     }
//     to[i] = '\0';
    
// }


//字符指针做形参和实参
#include<stdio.h>
int main(){
    void copy_string(char *from,char *to);
    char *a = "i am a teacher";
    char b[] = "i am a programer";
    char *p = b;
    printf("string a=%s\nstring b=%s\n",a,b);
    printf("copy string a to string b:\n");
    copy_string(a,p);
    printf("\n string a=%s\n string b=%s\n",a,b);
    return 0;
}
void copy_string(char *from,char *to){
    for(;*from!='\0';from++,to++)
    {
        *to = *from;
    }
    *to = '\0';
    
}