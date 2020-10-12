/* 
归并排序——稳定排序——O(nlogn)
分治再排序，归并再排序
 */
#include <stdio.h>
#include <stdlib.h>
int n;
//合并
void Merge(int *source, int *target, int i, int m, int n){
    int j, k;
    for (j = m + 1, k = i; i <= m && j <= n; k++){
        if (source[i] <= source[j]){
            target[k] = source[i++];
        }
        else{
            target[k] = source[j++];
        }
    }
    while (i <= m){
        target[k++] = source[i++];
    }
    while (j <= n){
        target[k++] = source[j++];
    }
}
//归并排序
 void MergeSort(int *source, int *target, int s, int t){
     int m, *temp;
     if (s == t){
         target[s] = source[s];
     }
     else{
         temp = (int*) malloc(sizeof(int) * (t - s + 1));
         m = (s + t) / 2;
         MergeSort(source, temp, s, m);
         MergeSort(source, temp, m + 1, t);
         Merge(temp, target, s, m, t);
     }
 }
 int main(){
     int i;
    int *array;
    printf("请输入数组的大小：");
    scanf("%d", &n);
    array = (int*) malloc(sizeof(int) * n);
    printf("请输入数据（用空格分隔）：");
    for (i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    MergeSort(array, array, 0, n - 1);
    printf("排序后为：");
    for (i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
 }

/* 
基数排序（LSD）——稳定排序——O(kn)
分桶
 */
void RadixSort(int *array){
    int radix = 10;
    int *count, *bucket, i, j, k;
    count = (int*) malloc(sizeof(int) * radix);
    bucket = (int*) malloc(sizeof(int) * n);
    for (k = 1; k <= bit_num; k++){
        for (i = 0; i < radix; i++){
            count[i] = 0;
        }
        //统计各个桶中所盛数据个数
        for (i = 0; i < n; i++){
            count[GetNumInPos(array[i], k)]++;
        }
        //count[i]表示第i个桶的右边界索引
        for (i = 1; i < radix; i++){
            count[i] = count[i] + count[i - 1];
        }
        //分配
        for (i = n - 1; i >= 0; i--){
            j = GetNumInPos(array[i], k);
            bucket[count[j] - 1] = array[i];
            count[j]--;
        }
        //收集
        for (i = 0, j = 0; i < n; i++, j++){
            array[i] = bucket[j];
        }
    }
}