#include"total.h"
int *temp=new int[2000000];
int bucket[10];
void BinsertSort(SqList& L, int& compare, int& move) {
    for (int i = 1; i < L.length; i++) {
        L.T[0] = L.T[i]; move++;
        int low = 1;
        int high = i - 1;
        while (low <= high) {
            compare++;
            int mid = (low + high) / 2;
            if (L.T[0].key < L.T[mid].key) high = mid - 1;
            else low = mid + 1;
        }
        for (int j = i - 1; j >= high + 1; j--) { L.T[j + 1] = L.T[j]; move++; }
        L.T[high + 1] = L.T[0]; move++;             //放入要排序的元素
    }
}
void HeapAdjust(SqList& R, int s, int m, int& comparecount, int& movecount) {
    int j;
    RedType rc = R.T[s];
    for (j = 2 * s; j <= m; j *= 2) {                   //找到当前节点的左子节点。
        if (j < m && R.T[j].key < R.T[j + 1].key)++j;       //如果 j 小于 m 且左子节点的键值小于右子节点的键值，则 j 自增1。这是为了找到左右子节点中键值较大的节点。

        comparecount++;
        if (rc.key >= R.T[j].key)break;                         //如果当前节点的键值大于等于左右子节点中键值较大的节点，则跳出循环。
        R.T[s] = R.T[j]; s = j;                                 //将左右子节点中键值较大的节点的值赋给当前节点。更新当前节点的索引为左右子节点中键值较大的节点的索引。
        movecount++;
    }
    R.T[s] = rc;                                                //将原始节点的值赋给最终位置的节点。
}
void HeapSort(SqList& R, int n, int& comparecount, int& movecount) {
    int i;
    for (i = n / 2; i >= 1; i--)//从最后一个非叶子节点开始，逐个向前调整，最终得到一个大顶堆。
        HeapAdjust(R, i, n, comparecount, movecount);
    for (i = n; i > 1; i--) {
        Swap(R.T[1].key, R.T[i].key);
        movecount++;            //排序的逻辑，每次将堆顶（序列的第一个元素）与当前最后一个元素交换，并将最后一个元素排除在外，再对剩下的部分重新调整为大顶堆。循环直至所有元素有序排列，完成排序过程。
        HeapAdjust(R, 1, i - 1, comparecount, movecount);
    }
}
void Swap(int& t1, int& t2) {
    int temp = t1;
    t1 = t2;
    t2 = temp;
    temp = 0;
}
int maxBit(SqList& data, int n, int& comparecount)
{
    //求n个元素的最大值 
    int maxData = data.T[1].key;
    for (int i = 2; i < n; i++)
    {
        if (maxData < data.T[i].key)
            maxData = data.T[i].key;
        comparecount++;
    }

    //求最大值的位数是几位
    int d = 1;    //d用来计数最大值的位数，至少有1位 
    while (maxData >= 10)  //计算位数 
    {
        maxData /= 10;
        d++;
        comparecount++;
    }
    return d;
}

void radixsort(SqList& data, int n, int& comparecount, int& movecount)  //基数排序 
{
    int d = maxBit(data, n, comparecount);  //求出最大位数
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++)   //进行d次排序
    {
        for (j = 0; j < 10; j++)   //清空计数器
        {
            bucket[j] = 0;
        }
        for (j = 1; j < n; j++)    //统计每个桶的元素个数 
        {
            k = (data.T[j].key / radix) % 10;
            bucket[k]++;
        }


        for (j = 1; j < 10; j++)
            bucket[j] = bucket[j - 1] + bucket[j];      //进行每个桶数据的累加，将这个桶本来的个数与它之前所有桶的个数加起来作为这个桶的新的个数

        for (j = n - 1; j >= 1; j--)
        {
            k = (data.T[j].key / radix) % 10;
            temp[bucket[k] - 1] = data.T[j].key;
            bucket[k]--;                                            //当前桶的个数减一      //分别存储桶中   temp中有序
            movecount++;
        }
        
        for (j = 1; j < n; j++) //将临时数组的内容复制到data中
            data.T[j].key = temp[j - 1];  //由于temp从0开始存储，而data.T是从1开始存储，所以要将j-1赋值给j
        movecount++;
        radix = radix * 10;
    }
}
void bubblesort(SqList& L, int& comparecount, int& movecount) {
    int i, j;
    RedType x;
    for (i = 1; i <= L.length - 1; i++) {
        for (j = 1; j <= L.length - i - 1; j++) {
            comparecount++;
            if (L.T[j].key > L.T[j + 1].key) {
                x = L.T[j]; L.T[j] = L.T[j + 1]; L.T[j + 1] = x;
                movecount += 3;
            }
        }
    }
}
int Partition(SqList& L, int low, int high, int& comparecount, int& movecount) {
    int pivotkey;
    L.T[0] = L.T[low]; pivotkey = L.T[low].key;
    while (low < high) {
        while (low < high && L.T[high].key >= pivotkey) {
            --high;
            comparecount++;
        }       //从右侧开始，找到第一个小于 pivotkey 的元素，并将其移到左侧（对应 low 位置），每次比较的结果计数增加。
        L.T[low] = L.T[high];
        movecount++;
        while (low < high && L.T[low].key <= pivotkey) {
            ++low;
            comparecount++;
        }//接着从左侧开始，找到第一个大于 pivotkey 的元素，并将其移到右侧（对应 high 位置），同样计数。
        L.T[high] = L.T[low];
        movecount++;
    }//重复以上两个步骤，直到 low >= high，表示本轮分区结束。
    L.T[low] = L.T[0];//将基准元素 pivotkey 放置在当前 low 的位置上，完成一次分区操作。
    movecount++;
    return low;
}
void Qsort(SqList& L, int low, int high, int& comparecount, int& movecount) {
    //原先的递归算法在读取文件10000个数据进行排序时，发生栈溢出，采取尾递归实现排序算法
    while (low < high) {
        int pivott = Partition(L, low, high, comparecount, movecount);      //使用 Partition 函数将数组分为两部分，并得到基准元素的位置 pivott
        Qsort(L, low, pivott - 1, comparecount, movecount);     //递归调用 Qsort 函数对左侧子数组进行排序，即 low 到 pivott - 1 的部分。
        low = pivott + 1;       //更新 low 的位置为 pivott + 1，对右侧子数组进行排序。这里采用尾递归的方式避免了常规递归造成的栈溢出问题，因为它只在尾部调用递归函数
 //       Qsort(L, pivott + 1, high, comparecount, movecount);
    }
}

