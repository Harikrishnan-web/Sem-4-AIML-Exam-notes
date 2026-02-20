

---

# ✅ EXPERIMENT 1

## **TITLE: Linear Search – Time vs n Graph Plotting**

### **C PROGRAM (Generates linear.txt)**

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linearSearch(int a[],int n,int x){
    for(int i=0;i<n;i++)
        if(a[i]==x)
            return i;
    return -1;
}

int main(){
    FILE *fp=fopen("linear.txt","w");
    int x=-1;
    clock_t start,end;
    double time;
    for(int n=1000;n<=10000;n+=1000){
        int *a=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
            a[i]=i;
        start=clock();
        linearSearch(a,n,x);
        end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC;
        fprintf(fp,"%d %f\n",n,time);
        free(a);
    }
    fclose(fp);
    return 0;
}
```

### Output File (linear.txt)

```
1000 0.00001
2000 0.00002
...
10000 0.00010
```

---

# ✅ EXPERIMENT 2

## **TITLE: Recursive Binary Search – Time vs n Graph Plotting**

### **C PROGRAM (Generates binary.txt)**

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binarySearch(int a[],int l,int r,int x){
    if(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==x) return mid;
        if(a[mid]>x) return binarySearch(a,l,mid-1,x);
        return binarySearch(a,mid+1,r,x);
    }
    return -1;
}

int main(){
    FILE *fp=fopen("binary.txt","w");
    clock_t start,end;
    double time;
    int x=-1;
    for(int n=1000;n<=10000;n+=1000){
        int *a=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
            a[i]=i;
        start=clock();
        binarySearch(a,0,n-1,x);
        end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC;
        fprintf(fp,"%d %f\n",n,time);
        free(a);
    }
    fclose(fp);
    return 0;
}
```

---

# ✅ EXPERIMENT 4

## **TITLE: Insertion Sort and Heap Sort – Time vs n Graph Plotting**

### **C PROGRAM (Generates sort.txt)**

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void heapify(int a[],int n,int i){
    int largest=i,l=2*i+1,r=2*i+2;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i){
        int t=a[i]; a[i]=a[largest]; a[largest]=t;
        heapify(a,n,largest);
    }
}

void heapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>0;i--){
        int t=a[0]; a[0]=a[i]; a[i]=t;
        heapify(a,i,0);
    }
}

int main(){
    FILE *fp=fopen("sort.txt","w");
    clock_t start,end;
    double t1,t2;
    for(int n=1000;n<=10000;n+=1000){
        int *a=(int*)malloc(n*sizeof(int));
        int *b=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++){
            a[i]=rand()%10000;
            b[i]=a[i];
        }
        start=clock();
        insertionSort(a,n);
        end=clock();
        t1=(double)(end-start)/CLOCKS_PER_SEC;

        start=clock();
        heapSort(b,n);
        end=clock();
        t2=(double)(end-start)/CLOCKS_PER_SEC;

        fprintf(fp,"%d %f %f\n",n,t1,t2);
        free(a);
        free(b);
    }
    fclose(fp);
    return 0;
}
```

Output Format:

```
n   insertion_time   heap_time
```

---

# ✅ EXPERIMENT 5

## **TITLE: BFS Traversal – Time vs n Graph Plotting**

### **C PROGRAM (Generates bfs.txt)**

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1000
int adj[MAX][MAX],visited[MAX],queue[MAX];

void bfs(int n){
    int front=0,rear=0;
    queue[rear++]=0;
    visited[0]=1;
    while(front<rear){
        int v=queue[front++];
        for(int i=0;i<n;i++){
            if(adj[v][i] && !visited[i]){
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
}

int main(){
    FILE *fp=fopen("bfs.txt","w");
    clock_t start,end;
    double time;
    for(int n=100;n<=1000;n+=100){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                adj[i][j]=rand()%2;

        for(int i=0;i<n;i++)
            visited[i]=0;

        start=clock();
        bfs(n);
        end=clock();

        time=(double)(end-start)/CLOCKS_PER_SEC;
        fprintf(fp,"%d %f\n",n,time);
    }
    fclose(fp);
    return 0;
}
```

---

# ✅ How to Plot Graph

### Using Excel:

1. Open generated `.txt` file
2. Separate columns
3. Select data
4. Insert → Line Chart
5. X-axis → n
6. Y-axis → Time

---

Now your lab record contains:

* Program
* Observation table (from .txt file)
* Graph
* Conclusion (Time Complexity)
```
# 4 and 5 with grapgh
Below are **separate C programs** to plot graphs for **Experiment 4 (Sorting)** and **Experiment 5 (BFS)** using **gnuplot**.

These programs assume:

* `sort.txt` → contains: `n insertion_time heap_time`
* `bfs.txt` → contains: `n time`

Make sure **gnuplot is installed** on your system.

---

# ✅ EXPERIMENT 4

## **TITLE: Graph Plotting for Insertion Sort and Heap Sort**

### **C PROGRAM TO PLOT GRAPH (sort_plot.c)**

```c
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *gp=popen("gnuplot -persistent","w");
    fprintf(gp,"set title 'Insertion Sort vs Heap Sort'\n");
    fprintf(gp,"set xlabel 'Number of Elements (n)'\n");
    fprintf(gp,"set ylabel 'Time (seconds)'\n");
    fprintf(gp,"set grid\n");
    fprintf(gp,"plot 'sort.txt' using 1:2 with linespoints title 'Insertion Sort',");
    fprintf(gp,"'sort.txt' using 1:3 with linespoints title 'Heap Sort'\n");
    pclose(gp);
    return 0;
}
```

### 📌 How to Run

```
gcc sort_plot.c
./a.out
```

Graph window will open showing:

* X-axis → n
* Y-axis → Time
* Two curves (Insertion & Heap)

---

# ✅ EXPERIMENT 5

## **TITLE: Graph Plotting for BFS Traversal**

### **C PROGRAM TO PLOT GRAPH (bfs_plot.c)**

```c
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *gp=popen("gnuplot -persistent","w");
    fprintf(gp,"set title 'BFS Time Complexity'\n");
    fprintf(gp,"set xlabel 'Number of Vertices (n)'\n");
    fprintf(gp,"set ylabel 'Time (seconds)'\n");
    fprintf(gp,"set grid\n");
    fprintf(gp,"plot 'bfs.txt' using 1:2 with linespoints title 'BFS'\n");
    pclose(gp);
    return 0;
}
```

### 📌 How to Run

```
gcc bfs_plot.c
./a.out
```

Graph window will open showing:

* X-axis → n
* Y-axis → Time

---

# ✅ What to Write in Record (Conclusion)

**Experiment 4:**

> Insertion Sort shows quadratic growth O(n²).
> Heap Sort shows O(n log n) growth.

**Experiment 5:**

> BFS shows linear growth with respect to vertices and edges, approximately O(V + E).

---


