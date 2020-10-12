/* 
选择排序
 */

/* 
简单选择排序——不稳定排序——O(n²)
对比选出最x的，重复
 */
void SelectSort(int *array){
    int i, j, k, temp;
    // n 趟排序
    for (i = 0; i < n; i++){
        k = i;
        // 寻找最小的元素下标
        for (j = i + 1; j < n; j++){
            if (array[j] < array[k]){
                k = j;
            }
        }
        // 如果这个不是第 i 个，则交换第 i 个和第 k 个
        if (k != i){
            temp = array[i];
            array[i] = array[k];
            array[k] = temp;
        }
    }
}

/* 
堆排序——不稳定排序——O(nlogn)
最坏是O(nlogn)
先建堆，然后加入无序在堆顶，再调整
 */
#include <stdio.h>
#include <stdlib.h>
int n;
//生成堆
void HeapAdjust(int *array, int s, int m){
    int i;
    array[0] = array[s];
    for (i = s * 2; i <= m; i *= 2){
        if (i < m && array[i] < array[i + 1]){
            i++;
        }
        if (!(array[0] < array[i])){
            break;
        }
        array[s] = array[i];
        s = i;
    }
    array[s] = array[0];
}
//堆排序
void HeapSort(int *array){
    int i;
    for (i = n / 2; i > 0; i--){
        HeapAdjust(array, i, n);
    }
    for (i = n; i > 1; i--){
        array[0] = array[1];
        array[1] = array[i];
        array[i] = array[0];
        HeapAdjust(array, 1, i - 1);
    }
}
int main(){
    int i;
    int *array;
    printf("请输入数组的大小：");
    scanf("%d", &n);
    array = (int*) malloc(sizeof(int) * (n + 1));
    printf("请输入数据（用空格分隔）：");
    for (i = 1; i <= n; i++){
        scanf("%d", &array[i]);
    }
    HeapSort(array);
    printf("排序后为：");
    for (i = 1; i <= n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}