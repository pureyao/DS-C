#include<stdio.h>
int main(){
    int a[3][4] = {
        {3,4,6,8},
        {8,4,2,7},
        {1,6,8,3}
    };
    int i,j,row = 0,colum = 0,max = a[0][0];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i][j]>max)
            {
                max = a[i][j];
                row = i+1;
                colum = j+1;
            }
        }
    }
    printf("max:%d,row:%d,colum:%d",max,row,colum);
}