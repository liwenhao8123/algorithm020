#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void dump(int a[], int size)
{
    printf("\r\n");
    for (int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\r\n");
    return;
}

// i 表示从哪个节点开始进行堆状态调整
void heapify(int array[], int length, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2;
    int largest = i;

    if (left < length && array[left] > array[largest]){
        largest = left;
    }
    if (right < length && array[right] > array[largest]){
        largest = right;
    }

    if (largest != i){
        int tmp = array[i]; array[i] = array[largest]; array[largest] = tmp;
        heapify(array, length, largest);  //注意如果跟子节点进行调整，那么需要迭代进入子节点进行调整
    }
    return ;
}

void heap_sort(int array[], int length)
{
    if (length <= 0){
        return ;
    }

    for (int i = length / 2 - 1; i >= 0; i--){
        heapify(array, length, i);   //数组原地按照大顶堆方式进行调整
    }

    for (int i = length - 1; i >= 0; i--){  // i = lenght - 1处理等于是把构成堆的数组空间减一，用最后的空间存放最大值
        int tmp = array[0];  //取大顶堆当前第一个元素（最大值）与堆尾进行交换，再调整堆状态
        array[0] = array[i];
        array[i] = tmp;
        heapify(array, i, 0);  //注意：array[0]值取出交互后堆空间的值不是length，而是随着 i 动态变小
    }
    return ;
}

int main()
{
	int test[10] = {5, 8, 9, 23, 67, 1, 3, 7, 31, 56};

	heap_sort(test, 10);

	dump(test, 10);

	return 0;
}