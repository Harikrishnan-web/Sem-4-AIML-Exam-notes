#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

int main() {
    int n_list[] = {10000, 20000, 30000, 40000, 50000};
    double results[5];
    int gd = DETECT, gm;
    int i, k, x = -1;

    for (k = 0; k < 5; k++) {
        int n = n_list[k];
        int *arr = (int *)malloc(n * sizeof(int));
        for (i = 0; i < n; i++) arr[i] = i;

        clock_t start = clock();
        for (i = 0; i < n; i++) {
            if (arr[i] == x) break;
        }
        clock_t end = clock();

        results[k] = ((double)(end - start)) / CLOCKS_PER_SEC;
        free(arr);
    }

    initgraph(&gd, &gm, "");
    line(50, 400, 500, 400); 
    line(50, 400, 50, 50);   
    outtextxy(200, 420, "Number of Elements (n)");
    outtextxy(10, 100, "Time");

    for (k = 0; k < 5; k++) {
        int px = 50 + (k + 1) * 70;
        int py = 400 - (int)(results[k] * 10000000); 
        circle(px, py, 3);
        if (k > 0) {
            int prevX = 50 + k * 70;
            int prevY = 400 - (int)(results[k-1] * 10000000);
            line(prevX, prevY, px, py);
        }
    }

    getch();
    closegraph();
    return 0;
}