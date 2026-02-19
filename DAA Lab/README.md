

---

## Experiment 1: Linear Search

**Aim:** To implement Linear Search and determine the time required to search for an element.

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int main() {
    int n, x, result;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) arr[i] = i; // Best case/Average case setup

    printf("Enter element to search: ");
    scanf("%d", &x);

    start = clock();
    result = linearSearch(arr, n, x);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found\n");

    printf("Time taken: %f seconds\n", cpu_time_used);
    free(arr);
    return 0;
}

```

**Sample Output:**

```text
Enter number of elements: 10000
Enter element to search: 9999
Element found at index: 9999
Time taken: 0.000032 seconds

```

---

## Experiment 2: Recursive Binary Search

**Aim:** To implement recursive Binary Search and determine the time required to search for an element.

```c
#include <stdio.h>
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
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    clock_t start = clock();
    int result = binarySearch(arr, 0, n - 1, x);
    clock_t end = clock();
    
    if (result != -1) printf("Element found at index %d\n", result);
    else printf("Element not found\n");
    
    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

```

**Sample Output:**

```text
Element found at index 3
Time taken: 0.000002

```

---

## Experiment 3: Pattern Searching (KMP/Naive)

**Aim:** To print all occurrences of a pattern `pat[]` in a text `txt[]`.

```c
#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j]) break;
        if (j == M) printf("Pattern found at index %d\n", i);
    }
}

int main() {
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";
    search(pat, txt);
    return 0;
}

```

**Sample Output:**

```text
Pattern found at index 0
Pattern found at index 9
Pattern found at index 13

```

---

## Experiment 4: Insertion Sort and Heap Sort

**Aim:** To sort elements using Insertion and Heap sort and determine time complexity.

```c
#include <stdio.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

void heapify(int arr[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) { swap(&arr[i], &arr[largest]); heapify(arr, n, largest); }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) { swap(&arr[0], &arr[i]); heapify(arr, i, 0); }
}

int main() {
    int data[] = {12, 11, 13, 5, 6};
    int n = 5;
    heapSort(data, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", data[i]);
    return 0;
}

```

**Sample Output:**

```text
Sorted array: 5 6 11 12 13 

```

---

## Experiment 5: Breadth First Search (BFS)

**Aim:** To implement graph traversal using Breadth First Search.

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void BFS(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    int queue[MAX], front = -1, rear = -1;
    for(int i=0; i<n; i++) visited[i] = 0;

    visited[start] = 1;
    queue[++rear] = start;

    while(front != rear) {
        int current = queue[++front];
        printf("%d ", current);
        for(int i = 0; i < n; i++) {
            if(adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int n = 4;
    int adj[MAX][MAX] = {{0,1,1,0}, {1,0,0,1}, {1,0,0,1}, {0,1,1,0}};
    int visited[MAX];
    printf("BFS Traversal starting from vertex 0: ");
    BFS(adj, visited, 0, n);
    return 0;
}

```

**Sample Output:**

```text
BFS Traversal starting from vertex 0: 0 1 2 3 

```

