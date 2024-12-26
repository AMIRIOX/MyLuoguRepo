#include <iostream>
#include <cstdio>
using namespace std;
int a[20][20];
int main() {
    int n;
    scanf("%d", &n);

    int c = 1;
    int x = 1, y = 0;
    while(c <= n * n) {
        while(y < n && a[x][y + 1] == 0) a[x][++y] = c++;
        while(x < n && a[x + 1][y] == 0) a[++x][y] = c++;
        while(y > 1 && a[x][y - 1] == 0) a[x][--y] = c++;
        while(x > 1 && a[x - 1][y] == 0) a[--x][y] = c++;
    }
    for (int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}