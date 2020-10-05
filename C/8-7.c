//任意键入 3 个字符串，编程找出最小的一个。
#include<stdio.h>
#include<string.h>

int main(){
    char str[50];
    char ch[3][50];
    for (int i = 0; i < 3; i++)
    {
        gets(ch[i]);
    }
    strcpy(str,ch[0]);
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(ch[i],str)<0)
        {
            strcpy(str,ch[i]);
        }        
    }
    printf("the result is\n%s",str);
    return 0; 
}