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

void merge(int nums[], int left, int right, int mid)
{
    int * tmp = (int *)malloc(sizeof(int) * (right - left + 1));
    int i = left, j = mid+1, k = 0;

    while (i <= mid && j <= right){
        tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
    } 
    while (i <= mid) tmp[k++] = nums[i++];
    while (j <= right) tmp[k++] = nums[j++];

    for (int i = left, k = 0; i <= right; ){
        nums[i++]  = tmp[k++];
    }
    free(tmp);
}

void merge_sort(int nums[], int left, int right)
{
    if (left >= right){
        return;
    }

    int mid = (left + right) >> 1;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid+1, right);

    merge(nums, left, right, mid);
}

void merge_sort_test()
{
	int test[10] = {5, 8, 9, 23, 67, 1, 3, 7, 31, 56};

	merge_sort(test, 0, 9);

	dump(test, 10);
}

int main()
{
	merge_sort_test();
	return 0;
}