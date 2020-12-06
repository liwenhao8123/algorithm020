#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

static int heapSize;
static int capacity;
static int * heap;

bool minheap_isEmpty() { return heapSize == 0; }
bool minheap_isFull() { return heapSize == capacity; }
int minheap_parent(int i) { return (i - 1) / 2; }
int minheap_kthChild(int i, int k) { return 2 * i + k; }

/**
 * This will initialize our heap with default size.
*/
void minheap_init(int date) {
    heapSize = 0;
    capacity = date;
    heap = (int *)malloc(sizeof(int) * (capacity + 5));
}

void minheap_free(){
     free(heap);
}

int minheap_minChild(int i) {
    //根据当前节点的索引找到左右子节点
    int leftChild = minheap_kthChild(i, 1);
    int rightChild = minheap_kthChild(i, 2);
    return heap[leftChild] < heap[rightChild] ? leftChild : rightChild;
}

/**
 * Maintains the heap property while inserting an element.
 */
void minheap_heapifyUp(int i) {
    int insertValue = heap[i];
    while (i > 0 && insertValue < heap[minheap_parent(i)]) {
        heap[i] = heap[minheap_parent(i)];
        i = minheap_parent(i);
    }
    heap[i] = insertValue;
}

/**
 * Maintains the heap property while deleting an element.
 */
void minheap_heapifyDown(int i) {
    int child;
    int temp = heap[i];
    while (minheap_kthChild(i, 1) < heapSize) {
        child = minheap_minChild(i);
        if (temp <= heap[child]) {
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
int minheap_insert(int x) {
    if (minheap_isFull()){
        printf("Heap is full, No space to insert new element\n");
        return -1;
    } 
        
    heap[heapSize] = x;
    heapSize++;
    minheap_heapifyUp(heapSize - 1);
    return 0;
}

/**
 * Deletes element at index x
 * Complexity: O(log N)
 */
int minheap_erase(int x) {
    if (minheap_isEmpty()) {
        printf("Heap is empty, No element to delete\n");
        return -1;
    }

    int minElement = heap[x];
    heap[x] = heap[heapSize - 1];
    heapSize--;
    minheap_heapifyDown(x);
    return minElement;
}

/**
 * This method returns the max element of the heap.
 * complexity: O(1)
 */
int minheap_findMin() {
    if (minheap_isEmpty()){
        printf("Heap is empty\n");
        return -1;
    } 
    return heap[0];
}

/**
 * Prints all elements of the heap
 */
void minheap_printHeap() {
    printf("minheap = ");
    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i]);
    printf("\n");
}


int main() {
    minheap_init(10);

    minheap_insert(10);
    minheap_insert(5);
    minheap_insert(8);
    minheap_insert(7); 
    minheap_insert(20);
    minheap_insert(1);

    minheap_printHeap();
    minheap_erase(5);
    minheap_printHeap();
    minheap_erase(2);
    minheap_printHeap();

    minheap_free();
    return 0;
}
