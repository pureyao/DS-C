/* 
交换排序
 */

/* 
冒泡排序——稳定排序——O(n²)
比较相邻，第一次过完锁定最后一个
 */
void BubbleSort(int *array){
    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - 1 - i; j++){
            // 交换
            if (array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/* 
快速排序——不稳定排序——O(nlogn)
选中心，左小右大，重复
 */
int Partition(int *array, int low, int high){
    int pivotkey = array[low];
    array[0] = array[low];
    // 判断大小进行分配
    while (low < high){
        while (low < high && array[high] >= pivotkey){
            high--;
        }
        array[low] = array[high];
        while (low < high && array[low] <= pivotkey){
            low++;
        }
        array[high] = array[low];
    }
    array[low] = array[0];
    return low;
}
void QuickSort(int *array, int low, int high){
    if (low < high){
        int pivotloc = Partition(array, low, high);
        QuickSort(array, low, pivotloc - 1);
        QuickSort(array, pivotloc + 1, high);
    }
}