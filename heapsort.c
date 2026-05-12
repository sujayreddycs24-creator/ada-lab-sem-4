#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// ---------- MAX HEAPIFY ----------
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

// ---------- MIN HEAPIFY ----------
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

// ---------- BOTTOM-UP HEAP SORT ----------
void heapSortBottomUp(int arr[], int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract elements
    for (int i = n-1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);
    }
}

// ---------- TOP-DOWN HEAP INSERT ----------
void insertTopDown(int heap[], int *size, int value) {
    heap[*size] = value;
    int i = *size;
    (*size)++;

    while (i > 0 && heap[(i-1)/2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

// ---------- TOP-DOWN HEAP SORT ----------
void heapSortTopDown(int arr[], int n) {
    int heap[n];
    int size = 0;

    // Build heap incrementally
    for (int i = 0; i < n; i++)
        insertTopDown(heap, &size, arr[i]);

    // Extract elements
    for (int i = n-1; i >= 0; i--) {
        arr[i] = heap[0];
        heap[0] = heap[size-1];
        size--;
        maxHeapify(heap, size, 0);
    }
}

// ---------- MIN HEAP SORT (Descending) ----------
void heapSortDescending(int arr[], int n) {
    // Build min heap
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Extract elements
    for (int i = n-1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        minHeapify(arr, i, 0);
    }
}

// // ---------- UTILITY ----------
// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// ---------- MAIN ----------
int main() {
    srand(time(NULL));
    int n = 100000;
    int arr[n];
    
    // Generate 1000 random integers between 1 and 10000
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000 + 1;
    }

    

    clock_t start, end;

    // Bottom-up
    int arr1[n];
    for (int i = 0; i < n; i++) arr1[i] = arr[i];
    start = clock();
    heapSortBottomUp(arr1, n);
    end = clock();
    printf("Bottom-up ascending: ");
    
    printf("Time: %f seconds\n", (double)(end-start)/CLOCKS_PER_SEC);

    // Top-down
    int arr2[n];
    for (int i = 0; i < n; i++) arr2[i] = arr[i];
    start = clock();
    heapSortTopDown(arr2, n);
    end = clock();
    printf("Top-down ascending: ");
   
    printf("Time: %f seconds\n", (double)(end-start)/CLOCKS_PER_SEC);

    // Min-heap descending
    int arr3[n];
    for (int i = 0; i < n; i++) arr3[i] = arr[i];
    start = clock();
    heapSortDescending(arr3, n);
    end = clock();
    printf("Min-heap descending: ");
    
    printf("Time: %f seconds\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
