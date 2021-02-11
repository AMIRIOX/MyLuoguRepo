#include <iostream>
using namespace std;
const int maxn = 500;
int G[maxn][maxn];
int n, m, t;
int main() {
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                G[i][j] = 0x3f3f3f3f;
            else
                G[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        G[x][y] = v;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
    for (int i = 1; i <= t; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", G[s][e] == 0x3f3f3f3f ? -1 : G[s][e]);
    }
    return 0;
}