#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

int partition(int arr[], int l, int r) {
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int randomPartition(int arr[], int l, int r) {
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return partition(arr, l, r);
}

int kthSmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int pos = randomPartition(arr, l, r);
        if (pos - l == k - 1) return arr[pos];
        if (pos - l > k - 1) return kthSmallest(arr, l, pos - 1, k);
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
    return -1;
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26}, n = 7, k = 3;
    srand(time(NULL));
    printf("%d-th smallest element is %d", k, kthSmallest(arr, 0, n - 1, k));
    return 0;
}