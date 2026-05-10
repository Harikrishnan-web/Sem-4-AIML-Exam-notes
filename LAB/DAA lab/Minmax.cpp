#include <stdio.h>

struct pair {
    int min;
    int max;
};

struct pair getMinMax(int arr[], int low, int high) {
    struct pair minmax, left, right;
    int mid;

    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    mid = (low + high) / 2;
    left = getMinMax(arr, low, mid);
    right = getMinMax(arr, mid + 1, high);

    minmax.max = (left.max > right.max) ? left.max : right.max;
    minmax.min = (left.min < right.min) ? left.min : right.min;

    return minmax;
}

int main() {
    int arr[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct pair result = getMinMax(arr, 0, n - 1);

    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);

    return 0;
}