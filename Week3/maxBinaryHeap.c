#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

static int heapSize;
static int capacity;
static int * heap;

bool maxheap_isEmpty() { return heapSize == 0; }
bool maxheap_isFull() { return heapSize == capacity; }
int maxheap_parent(int i) { return (i - 1) / 2; }
int maxheap_kthChild(int i, int k) { return 2 * i + k; }

/**
 * This will initialize our heap with default size.
*/
void maxheap_init(int date) {
    heapSize = 0;
    capacity = date;
    heap = (int *)malloc(sizeof(int) * (capacity + 5));
}

void maxheap_free(){
     free(heap);
}

int maxheap_maxChild(int i) {
    //根据当前节点的索引找到左右子节点
    int leftChild = maxheap_kthChild(i, 1);
    int rightChild = maxheap_kthChild(i, 2);
    return heap[leftChild] > heap[rightChild] ? leftChild : rightChild;
}

/**
 * Maintains the heap property while inserting an element.
 */
void maxheap_heapifyUp(int i) {
    int insertValue = heap[i];
    while (i > 0 && insertValue > heap[maxheap_parent(i)]) {
        heap[i] = heap[maxheap_parent(i)];
        i = maxheap_parent(i);
    }
    heap[i] = insertValue;
}

/**
 * Maintains the heap property while deleting an element.
 */
void maxheap_heapifyDown(int i) {
    int child;
    int temp = heap[i];
    while (maxheap_kthChild(i, 1) < heapSize) {
        child = maxheap_maxChild(i);
        if (temp >= heap[child]) {
            break;
        }
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = temp;
}

/**
 * Inserts new element in to heap
 * Complexity: O(log N)
 * As worst case scenario, we need to traverse till the root
 */
int maxheap_insert(int x) {
    if (maxheap_isFull()){
        printf("Heap is full, No space to insert new element\n");
        return -1;
    } 
        
    heap[heapSize] = x;
    heapSize++;
    maxheap_heapifyUp(heapSize - 1);
    return 0;
}

/**
 * Deletes element at index x
 * Complexity: O(log N)
 */
int maxheap_erase(int x) {
    if (maxheap_isEmpty()) {
        printf("Heap is empty, No element to delete\n");
        return -1;
    }

    int maxElement = heap[x];
    heap[x] = heap[heapSize - 1];
    heapSize--;
    maxheap_heapifyDown(x);
    return maxElement;
}

/* 
 * This method returns index of the element equal data
 * complexity: O(n)
 */
int maxheap_getindex(int data){
    for(int i = 0; i < heapSize; i++)
        if (data == heap[i])
            return i;
    return -1;
}

/**
 * Deletes element if value is data
 * Complexity: O(log N)
 */

int maxheap_delete(int data) {
    if (maxheap_isEmpty()) {
        printf("Heap is empty, No element to delete\n");
        return -1;
    }
    int x = maxheap_getindex(data);
    if (x < 0)
        return x;
    int delElement = heap[x];
    heap[x] = heap[heapSize - 1];
    heapSize--;
    maxheap_heapifyDown(x);
    return delElement;
}

/**
 * This method returns the max element of the heap.
 * complexity: O(1)
 */
int maxheap_findMax() {
    if (maxheap_isEmpty()){
        printf("Heap is empty\n");
        return -1;
    } 
    return heap[0];
}

/**
 * Prints all elements of the heap
 */
void maxheap_printHeap() {
    printf("maxheap = ");
    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int * res = (int *)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = 0;

    if (numsSize == 0 || k == 0){
        return NULL;
    }

    maxheap_init(k);
    for (int cur = 0; cur < numsSize; cur++){
        int start = cur - k;
        if (start >= 0){
            maxheap_delete(nums[start]);
            maxheap_printHeap();
        }

        maxheap_insert(nums[cur]);
        maxheap_printHeap();
        if (heapSize == k){
            res[cur-k+1] = maxheap_findMax(); //当滑动窗口填充满，则取最大值
            maxheap_printHeap();
            (*returnSize)++;
        }
    }
    maxheap_free();
    return res;
}

int main(){
    int array[] = {1,3,-1,-3,5,3,6,7};
    int retSize = 0;
    int * res = maxSlidingWindow(array, sizeof(array)/sizeof(int), 3, &retSize);
    printf("retSize is %d\n",retSize);
    for (int i = 0 ; i < retSize; i++){
        printf("%d ", res[i]);
    }
    free(res);
    return 0;
}
/*
int main() {
    maxheap_init(10);

    maxheap_insert(10);
    maxheap_insert(5);
    maxheap_insert(8);
    maxheap_insert(7); 
    maxheap_insert(20);
    maxheap_insert(1);

    maxheap_printHeap();
    maxheap_erase(5);
    maxheap_printHeap();
    maxheap_delete(10);
    maxheap_printHeap();
    maxheap_erase(2);
    maxheap_printHeap();

    maxheap_free();
    return 0;
}
*/