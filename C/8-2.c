/*
冒泡排序-数组训练
现在输入 10 个用户的有效学习时间，要求对它们按由小到大的顺序排序。
*/
#include<stdio.h>
int main(){
    int LearnTime[10];
    printf("please enter 10 number:");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&LearnTime[i]);
    }
    for (int j = 0; j < 9; j++)
        for (int i = 0; i < 9-j; i++)
            if (LearnTime[j]<LearnTime[j+1])
                {
                    int t = LearnTime[j];
                    LearnTime[j] = LearnTime[j+1];
                    LearnTime[j+1] = t;
                }
    printf("after:");
    for ( int i = 0; i < 10; i++)
    {
        printf("%d\t",LearnTime[i]);
    }
    
    return 0;
}