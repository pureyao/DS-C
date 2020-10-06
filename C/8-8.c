#include<stdio.h>

int main(){
    int num[20];
    int ave,sum;
    int flag = 0;               //大于平均数的个数

    //输入
    for(int i=0;i<20;i++)
        scanf("%d",&num[i]);

    //求和
    for(int i=0;i<20;i++)
        sum += num[i];

    ave = sum / 20;

    for(int i=0;i<20;i++)
       if(num[i]>ave)
            flag++;

    printf("ave=%d,num bigger than ave is %d",ave,flag);

    return 0;
}