#include<stdio.h>
int main(){
    void change(int x[],int n);
    int i,a[10] =  {3,5,6,7,1,7,4,8,9,10};
    printf("the original array:");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    change(a,10);
    printf("the inverted array:");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
void change(int x[],int n){
    int temp,i,j,m =(n-1)/2;
    for (i = 0; i <= m; i++)
    {
        j = n-i-1;
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;
    }
}