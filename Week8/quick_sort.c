#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define SWAP(a,b) \
do{\
    (a) ^= (b);\
    (b) ^= (a);\
    (a) ^= (b);\
}while(0)

int random_partition_1(int a[], int left, int right)
{
    int random_pivot_index = rand() % (right - left + 1) + left;
    int pivot = a[random_pivot_index];
    SWAP(pivot, a[right]);
    int i = left;

    for (int j = left; j < right; j++){
        if (a[j] < pivot){
            if (i != j){
                SWAP(a[i], a[j]);
            }
            i++;
        }
    }
    SWAP(a[i], a[right]);
    return i;
}

int random_partition_2(int a[], int left, int right)
{
    int random_pivot_index = rand() % (right - left + 1) + left;
    int pivot = a[random_pivot_index];
    SWAP(pivot, a[right]);
    int counter = left;
    
    for (int j = left; j < right; j++){
        if (a[j] < pivot){
            SWAP(a[counter], a[j]);
            counter++;
        }
    }
    SWAP(a[counter], a[right]);
    return counter;
}

int partition(int a[], int left, int right)
{
    int i = left;
    int j = left;

    for (; j < right; j++){
        if (a[j] < a[right]){
            if (i != j){
                SWAP(a[i], a[j]);
            }
            i++;
        }
    }
    if (i != right){
        SWAP(a[i], a[right]);
    }
    return i;
}

void quick_sort(int a[], int left, int right)
{
    if (left >= right){
        return;
    }
    int q = partition(a, left, right);
    quick_sort(a, left, q-1);
    quick_sort(a, q+1, right);
    return;
}

void dump(int a[], int size)
{
    printf("\r\n");
    for (int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\r\n");
    return;
}

/*求无序数组中从小到大第K个元素的数值*/
int findKthlagest(int a[], int left, int right, int k)
{
    int q = partition(a, left, right);

    if (q > k-1){
        return findKthlagest(a, left, q-1, k);
    }
    else if (q < k-1){
        return findKthlagest(a, q+1, right, k);    
    }

    return a[q];
}

int main()
{
    int k = 0;
    int a[10] = {30, 20, 10, 15, 4, 8, 40, 80, 20, 9};
    dump(a, 10);
    printf("请输入 : ");
    scanf("%d", &k);
    printf("\r\n无序数组中第%d个元素数值是%d\r\n", k, findKthlagest(a, 0, 9, k));
    printf("\r\n从小到大排序，采用快排方法\r\n");
    quick_sort(a, 0, 9);
    dump(a, 10);
    return 0;
}