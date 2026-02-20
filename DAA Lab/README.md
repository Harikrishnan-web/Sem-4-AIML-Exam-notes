

---

# ✅ EXPERIMENT 1

## **TITLE: Linear Search – Time Complexity Analysis with Graph Plotting**

### **PROGRAM (linear.c)**

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linear(int a[],int n,int key){
    for(int i=0;i<n;i++)
        if(a[i]==key)
            return i;
    return -1;
}

int main(){
    FILE *fp=fopen("linear.txt","w");
    clock_t start,end;
    double t;
    for(int n=1000;n<=10000;n+=1000){
        int *a=malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
            a[i]=i;
        start=clock();
        linear(a,n,-1);
        end=clock();
        t=(double)(end-start)/CLOCKS_PER_SEC;
        fprintf(fp,"%d %f\n",n,t);
        free(a);
    }
    fclose(fp);

    FILE *gp=popen("gnuplot -persistent","w");
    fprintf(gp,"set title 'Linear Search Time Analysis'\n");
    fprintf(gp,"set xlabel 'Number of Elements'\n");
    fprintf(gp,"set ylabel 'Time (seconds)'\n");
    fprintf(gp,"set grid\n");
    fprintf(gp,"plot 'linear.txt' using 1:2 with linespoints title 'Linear Search'\n");
    pclose(gp);
    return 0;
}
```

---

# ✅ EXPERIMENT 2

## **TITLE: Recursive Binary Search – Time Complexity Analysis with Graph Plotting**

### **PROGRAM (binary.c)**

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binary(int a[],int l,int r,int key){
    if(l<=r){
        int m=(l+r)/2;
        if(a[m]==key) return m;
        if(key<a[m]) return binary(a,l,m-1,key);
        return binary(a,m+1,r,key);
    }
    return -1;
}

int main(){
    FILE *fp=fopen("binary.txt","w");
    clock_t start,end;
    double t;
    for(int n=1000;n<=10000;n+=1000){
        int *a=malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
            a[i]=i;
        start=clock();
        binary(a,0,n-1,-1);
        end=clock();
        t=(double)(end-start)/CLOCKS_PER_SEC;
        fprintf(fp,"%d %f\n",n,t);
        free(a);
    }
    fclose(fp);

    FILE *gp=popen("gnuplot -persistent","w");
    fprintf(gp,"set title 'Binary Search Time Analysis'\n");
    fprintf(gp,"set xlabel 'Number of Elements'\n");
    fprintf(gp,"set ylabel 'Time (seconds)'\n");
    fprintf(gp,"set grid\n");
    fprintf(gp,"plot 'binary.txt' using 1:2 with linespoints title 'Binary Search'\n");
    pclose(gp);
    return 0;
}
```

---

# ✅ EXPERIMENT 3

## **TITLE: Pattern Searching – Occurrence Detection**

### **PROGRAM (pattern.c)**

```c
#include<stdio.h>
#include<string.h>

void find(char text[],char pat[]){
    int n=strlen(text),m=strlen(pat);
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++)
            if(text[i+j]!=pat[j])
                break;
        if(j==m)
            printf("Pattern at index %d\n",i);
    }
}

int main(){
    char text[100],pat[100];
    printf("Enter text: ");
    scanf("%s",text);
    printf("Enter pattern: ");
    scanf("%s",pat);
    find(text,pat);
    return 0;
}
```

---

# ✅ EXPERIMENT 4

## **TITLE: Insertion Sort and Heap Sort – Time Complexity Analysis with Graph**

### **PROGRAM (sort.c)**

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion(int a[],int n){
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
    int l=2*i+1,r=2*i+2,largest=i;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i){
        int t=a[i]; a[i]=a[largest]; a[largest]=t;
        heapify(a,n,largest);
    }
}

void heap(int a[],int n){
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>0;i--){
        int t=a[0]; a[0]=a[i]; a[i]=t;
        heapify(a,i,0);
    }
}

int main(){
    FILE *fp=fopen("sort.txt","w");
    clock_t s,e;
    double t1,t2;
    for(int n=1000;n<=10000;n+=1000){
        int *a=malloc(n*sizeof(int));
        int *b=malloc(n*sizeof(int));
        for(int i=0;i<n;i++){
            a[i]=rand()%10000;
            b[i]=a[i];
        }
        s=clock(); insertion(a,n); e=clock();
        t1=(double)(e-s)/CLOCKS_PER_SEC;
        s=clock(); heap(b,n); e=clock();
        t2=(double)(e-s)/CLOCKS_PER_SEC;
        fprintf(fp,"%d %f %f\n",n,t1,t2);
        free(a); free(b);
    }
    fclose(fp);

    FILE *gp=popen("gnuplot -persistent","w");
    fprintf(gp,"set title 'Insertion vs Heap Sort'\n");
    fprintf(gp,"set xlabel 'Number of Elements'\n");
    fprintf(gp,"set ylabel 'Time (seconds)'\n");
    fprintf(gp,"set grid\n");
    fprintf(gp,"plot 'sort.txt' using 1:2 with linespoints title 'Insertion',");
    fprintf(gp,"'sort.txt' using 1:3 with linespoints title 'Heap'\n");
    pclose(gp);
    return 0;
}
```

---

# ✅ EXPERIMENT 5

## **TITLE: Breadth First Search – Time Complexity Analysis with Graph**

### **PROGRAM (bfs.c)**

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1000
int adj[MAX][MAX],visit[MAX],q[MAX];

void bfs(int n){
    int f=0,r=0;
    q[r++]=0;
    visit[0]=1;
    while(f<r){
        int v=q[f++];
        for(int i=0;i<n;i++)
            if(adj[v][i] && !visit[i]){
                q[r++]=i;
                visit[i]=1;
            }
    }
}

int main(){
    FILE *fp=fopen("bfs.txt","w");
    clock_t s,e;
    double t;
    for(int n=100;n<=1000;n+=100){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                adj[i][j]=rand()%2;
        for(int i=0;i<n;i++)
            visit[i]=0;
        s=clock();
        bfs(n);
        e=clock();
        t=(double)(e-s)/CLOCKS_PER_SEC;
        fprintf(fp,"%d %f\n",n,t);
    }
    fclose(fp);

    FILE *gp=popen("gnuplot -persistent","w");
    fprintf(gp,"set title 'BFS Time Analysis'\n");
    fprintf(gp,"set xlabel 'Number of Vertices'\n");
    fprintf(gp,"set ylabel 'Time (seconds)'\n");
    fprintf(gp,"set grid\n");
    fprintf(gp,"plot 'bfs.txt' using 1:2 with linespoints title 'BFS'\n");
    pclose(gp);
    return 0;
}
```

---

# ✅ FINAL RECORD CONCLUSION SUMMARY

| Experiment     | Observed Growth | Complexity |
| -------------- | --------------- | ---------- |
| Linear Search  | Straight Line   | O(n)       |
| Binary Search  | Slow Curve      | O(log n)   |
| Pattern Search | Depends on n×m  | O(nm)      |
| Insertion Sort | Parabolic       | O(n²)      |
| Heap Sort      | n log n         | O(n log n) |
| BFS            | Linear Growth   | O(V + E)   |

---

* Compact versions for quick record writing
* Single combined file version for submission
