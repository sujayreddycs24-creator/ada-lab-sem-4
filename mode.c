#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findMode(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    int mode = arr[0];
    int maxCount = 1;
    int currentCount = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                mode = arr[i - 1];
            }
            currentCount = 1;
        }
    }

    // Final check for last sequence
    if (currentCount > maxCount) {
        maxCount = currentCount;
        mode = arr[n - 1];
    }

    return mode;
}

int main() {
    int arr[] = {4, 1, 2, 2, 3, 5, 2, 4, 4, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int mode = findMode(arr, n);
    printf("Mode value is: %d\n", mode);

    return 0;
}
