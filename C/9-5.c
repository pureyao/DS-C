//数组做函数实参——输入十个数，值最大的元素已经是第几个数
#include<stdio.h>
int main(){
    int max(int x,int y);
    int a[10],m,n,i;

    printf("please enter 10 integer number:");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    printf("\n");

    for(i=1,m=a[0],n=0;i<10;i++){
        if(max(m,a[i])>m){          //若 max 函数返回值大于 m
            m = max(m,a[i]);        //max 函数的返回值取代 m
            n = i;                  //把数组元素的序号记下来，放到 n 中
        }
    }
    printf("the largest number is %d\n it is the %dth number \n",m,n+1);

    return 0;
}

int max(int x,int y){
    return(x>y?x:y);
}