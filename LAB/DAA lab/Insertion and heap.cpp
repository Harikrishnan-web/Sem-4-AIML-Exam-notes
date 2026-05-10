#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        int temp = arr[i]; arr[i] = arr[largest]; arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0]; arr[0] = arr[i]; arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int n_list[] = {5000, 10000, 15000, 20000};
    double i_times[4], h_times[4];
    int gd = DETECT, gm, k, i;

    for (k = 0; k < 4; k++) {
        int n = n_list[k];
        int *a1 = malloc(n * sizeof(int)), *a2 = malloc(n * sizeof(int));
        for (i = 0; i < n; i++) a1[i] = a2[i] = rand() % 1000;

        clock_t s1 = clock(); insertionSort(a1, n); clock_t e1 = clock();
        i_times[k] = (double)(e1 - s1) / CLOCKS_PER_SEC;

        clock_t s2 = clock(); heapSort(a2, n); clock_t e2 = clock();
        h_times[k] = (double)(e2 - s2) / CLOCKS_PER_SEC;

        free(a1); free(a2);
    }

    initgraph(&gd, &gm, "");
    line(50, 400, 500, 400); line(50, 400, 50, 50);
    outtextxy(50, 30, "Yellow: Insertion | White: Heap");

    for (k = 0; k < 4; k++) {
        int px = 50 + (k + 1) * 100;
        int py_i = 400 - (int)(i_times[k] * 1000); // Scaled for display
        int py_h = 400 - (int)(h_times[k] * 1000);

        setcolor(YELLOW); circle(px, py_i, 3);
        setcolor(WHITE); circle(px, py_h, 3);
        if (k > 0) {
            setcolor(YELLOW); line(50 + k * 100, 400 - (int)(i_times[k-1] * 1000), px, py_i);
            setcolor(WHITE); line(50 + k * 100, 400 - (int)(h_times[k-1] * 1000), px, py_h);
        }
    }
    getch(); closegraph(); return 0;
}