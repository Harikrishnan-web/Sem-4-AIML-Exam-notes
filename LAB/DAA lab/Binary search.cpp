#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, low, mid - 1, x);
        return binarySearch(arr, mid + 1, high, x);
    }
    return -1;
}

int main() {
    int n_list[] = {10000, 20000, 30000, 40000, 50000};
    double results[5];
    int i, k;

    for (k = 0; k < 5; k++) {
        int n = n_list[k];
        int *arr = (int *)malloc(n * sizeof(int));
        for (i = 0; i < n; i++) arr[i] = i; 

        clock_t start = clock();
        binarySearch(arr, 0, n - 1, -1);
        clock_t end = clock();

        results[k] = ((double)(end - start)) / CLOCKS_PER_SEC;
        free(arr);
        printf("n = %d, Time = %f\n", n, results[k]);
    }
    return 0;
}
