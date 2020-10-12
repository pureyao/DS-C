/* 
查找
 */

/* 
二分查找——折半查找
数据多效率低
int *array  目标数组
int key 待查找关键词
int low,high    查找区间的上限，下限
 */
//若找到返回位置，否则为0
int BinarySearch(int *array,int key,int low,int high){
    int mid;
    while(low <= high){
        mid = (low+high)/2;
        if(key == array[mid]){
            return mid;
        }else if (key<array[mid]){
            high = mid-1;       //前面子表查找
        }else{
            low = mid+1;        //后面子表查找
        }       
    }
    return 0;
}

/* 
散列查找——散列函数(哈希函数)
 */
//哈希函数
//直接定址法    f(key) = a * key +b     简单不常用
//数学分析法    分析使其不重复
//平方取中法    关键字平方的中间几位
//折叠法       关键字分成位数相等几部分，相加
//除留余数法    f(key) = key(mod)p     (p<=m)   p取散列表长最大质数，散列效果较好
//随机数法      关键字的随机函数值

//处理冲突
//开放定址法    fi(key) = (f(key)+di) mod m     (di = 1,2,3...m-1)相当于向后+1(线性探测法)
//二次探测法                                    (di = 12,-12,22,-22)
//随机探测法                                    (di为随机数数列)
//再哈希法      再哈希函数一次，总能解决，但是增加计算时间
//链地址法      冲突了向下链接，遍历单链表性能损耗
//建立公共溢出区    散列表分为基本表和溢出表，冲突了填入溢出表
