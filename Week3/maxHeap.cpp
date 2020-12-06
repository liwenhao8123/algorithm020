#include <iostream>
using namespace std;

class BinaryHeap {
public:
    BinaryHeap(int capacity);
    void insert(int x);
    int erase(int x);
    int findMax();
    void printHeap();

    bool isEmpty() { return heapSize == 0; }
    bool isFull() { return heapSize == capacity; }
    ~BinaryHeap() { delete[] heap; }

private:
    void heapifyUp(int i);
    void heapifyDown(int i);
    int maxChild(int i);

    int parent(int i) { return (i - 1) / 2; }
    int kthChild(int i, int k) { return 2 * i + k; }

private:
    int *heap;
    int heapSize;
    int capacity;
};

/**
 * This will initialize our heap with default size.
*/
BinaryHeap::BinaryHeap(int capacity) {
    this->heapSize = 0;
    this->capacity = capacity;
    this->heap = new int[capacity + 5];
}

/**
 * Inserts new element in to heap
 * Complexity: O(log N)
 * As worst case scenario, we need to traverse till the root
 */
void BinaryHeap::insert(int x) {
    try {
        if (isFull()) 
            throw -1;
        
        heap[heapSize] = x;
        heapSize ++;
        heapifyUp(heapSize - 1);
        return ;
    } catch (int e) {
        cout << "Heap is full, No space to insert new element" << endl;
        exit(-1);
    }
}

/**
 * Deletes element at index x
 * Complexity: O(log N)
 */
int BinaryHeap::erase(int x) {
    try {
        if (isEmpty()) 
            throw -1;

        int maxElement = heap[x];
        heap[x] = heap[heapSize - 1];
        heapSize--;
        heapifyDown(x);
        return maxElement;
    } catch (int e) {
        cout << "Heap is empty, No element to delete" << endl;
        exit(-1);
    }
}

/**
 * Maintains the heap property while inserting an element.
 */
void BinaryHeap::heapifyUp(int i) {
    int insertValue = heap[i];
    while (i > 0 && insertValue > heap[parent(i)]) {
        heap[i] = heap[parent(i)];
        i = parent(i);
    }
    heap[i] = insertValue;
}

/**
 * Maintains the heap property while deleting an element.
 */
void BinaryHeap::heapifyDown(int i) {
    int child;
    int temp = heap[i];
    while (kthChild(i, 1) < heapSize) {
        child = maxChild(i);
        if (temp >= heap[child]) {
            break;
        }
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = temp;
}

int BinaryHeap::maxChild(int i) {
    int leftChild = kthChild(i, 1);
    int rightChild = kthChild(i, 2);
    return heap[leftChild] > heap[rightChild] ? leftChild : rightChild;
}

/**
 * This method returns the max element of the heap.
 * complexity: O(1)
 */
int BinaryHeap::findMax() {
    try {
        if (isEmpty()) 
            throw -1;

        return heap[0];
    } catch (int e) {
        cout << "Heap is empty." << endl;
        exit(-1);
    }
}

/**
 * Prints all elements of the heap
 */
void BinaryHeap::printHeap() {
    cout << "nHeap = ";
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
    return ;
}


int main() {
    BinaryHeap maxHeap(10);

    maxHeap.insert(10);
    maxHeap.insert(4);
    maxHeap.insert(9);
    maxHeap.insert(1);
    maxHeap.insert(7);
    maxHeap.insert(5);
    maxHeap.insert(3);

    maxHeap.printHeap();
    maxHeap.erase(5);
    maxHeap.printHeap();
    maxHeap.erase(2);
    maxHeap.printHeap();

    return 0;
}