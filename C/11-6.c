#include <stdio.h>
#define N 128                                    //人数
int main()
  {
      int a[N] = {0}, out = 0, num = 0, *p;
      p = a;
      while (1){                                  //循环报数
          if(*p == 0){                            //如果没有淘汰
              if (out == (N - 1)) break;          //如果仅剩一人
              num++;                              //报数
              num %= 3;                           //最大为3，到了3就从0开始
              if(num == 0) {                      //为0(即3)出局
                  *p = 1;
                  out++;}
          }
          p++;
          if (p == a + N)
              p = a;                              //循环转向下一人
      }
      printf("最后剩余者的编号是：%d", p + 1 - a);
  }