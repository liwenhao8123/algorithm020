/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


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

/*
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

//方法一：利用二叉堆，构建一个有K个元素的大顶堆
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int * res = malloc(sizeof(int) * k);
    *returnSize = 0;
    if (arrSize < k || k < 0){
        return NULL;
    }   
    maxheap_init(arrSize);
    for (int i = 0; i < k; i++){
        maxheap_insert(arr[i]);
    }
    for (int i = k; i < arrSize; i++){
        if (arr[i] < maxheap_findMax()){
            maxheap_erase(0);
            maxheap_insert(arr[i]); 
        }
    }
    //从堆中取出K个数字
    for (int i = 0; i < k; i++){
        res[i] = maxheap_erase(0);
        (*returnSize)++;
    }
    maxheap_free();
    //返回结果
    return res;
}

//方法二：快速排序，再后面学习以后再做一遍