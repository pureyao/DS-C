/* 
插入排序(内排序：放入内存再排序)
 */

/* 
直接插入排序——无序表中取出元素依次放入合适有序表
arr[0]暂存调整的数
 */
void InsertSort(int *arr){
    int i,j;
    for(i=2;i<=n;i++){
        //判断是否需要调整
        if(arr[i] < arr[i-1]){
            arr[0] = arr[i];
            //记录后移
            arr[i] = arr[i-1];
            for(j=i-2;arr[0]<arr[j];j++){
                arr[j+1] = arr[j];
            }
            //插入到有序子数组中
            arr[j+1] = arr[0];
        }
    }
}

/* 
希尔排序(缩小增量排序)——直接插入排序的升级，效率高
增量抽取划分为组，组内直接插入排序，直到增量=1
一般取序列的一般作为增量
 */
void ShellSort(int *array){
    int k = n / 2; //增量序列（仅作举例）
    while (k > 0){
        int i, j;
        // 划分子序列
        for (i = k + 1; i <= n; i++){
            // 插入排序
            if (array[i] < array[i - k]){
                array[0] = array[i];
                for (j = i - k; j > 0 && array[0] < array[j]; j -= k){
                    array[j + k] = array[j];
                }
                array[j + k] = array[0];
            }
        }
        // 重新赋值 k
        k = k / 2;
    }
}