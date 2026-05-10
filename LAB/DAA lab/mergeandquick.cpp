#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    int *L = malloc(n1 * sizeof(int)), *R = malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
        }
    }
    int t = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = t;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n_list[] = {5000, 10000, 15000, 20000};
    double m_times[4], q_times[4];
    int gd = DETECT, gm, k, i;

    for (k = 0; k < 4; k++) {
        int n = n_list[k];
        int *a1 = malloc(n * sizeof(int)), *a2 = malloc(n * sizeof(int));
        for (i = 0; i < n; i++) a1[i] = a2[i] = rand() % 1000;

        clock_t s1 = clock(); mergeSort(a1, 0, n - 1); clock_t e1 = clock();
        m_times[k] = (double)(e1 - s1) / CLOCKS_PER_SEC;

        clock_t s2 = clock(); quickSort(a2, 0, n - 1); clock_t e2 = clock();
        q_times[k] = (double)(e2 - s2) / CLOCKS_PER_SEC;

        free(a1); free(a2);
    }

    initgraph(&gd, &gm, "");
    line(50, 400, 500, 400); line(50, 400, 50, 50);
    outtextxy(50, 30, "Green: Merge Sort | Red: Quick Sort");

    for (k = 0; k < 4; k++) {
        int px = 50 + (k + 1) * 100;
        int py_m = 400 - (int)(m_times[k] * 10000); 
        int py_q = 400 - (int)(q_times[k] * 10000);

        setcolor(GREEN); circle(px, py_m, 3);
        setcolor(RED); circle(px, py_q, 3);
        if (k > 0) {
            setcolor(GREEN); line(50 + k * 100, 400 - (int)(m_times[k-1] * 10000), px, py_m);
            setcolor(RED); line(50 + k * 100, 400 - (int)(q_times[k-1] * 10000), px, py_q);
        }
    }
    getch(); closegraph(); return 0;
}