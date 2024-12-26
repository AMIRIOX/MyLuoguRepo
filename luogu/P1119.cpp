#include <cstdio>
#include <iostream>
using namespace std;
const int N = 500, M = 150000;
int adj[N][N];  // 图
int n, m, q;    // nmq
int t[N];       // N点建好的时间
int lk = 0;     // 上次的时间

// 你又把变量意义搞错了！！
void floyd(int _k) {
    int k = _k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] > adj[i][k] + adj[k][j])
                adj[i][j] = adj[i][k] + adj[k][j];
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            adj[i][j] = /*0x3f3f3f3f*/ 99999999;
    }
    for (int i = 0; i < n; i++)
        adj[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        adj[a][b] = adj[b][a] = w;
    }

    cin >> q;
    while (q--) {
        int x, y, rt;
        scanf("%d %d %d", &x, &y, &rt);
        while (t[lk] <= rt && lk < n) {
            floyd(lk);
            lk++;
        }
        if (t[x] > rt || t[y] > rt || adj[x][y] == 99999999)
            printf("-1\n");
        else
            printf("%d\n", adj[x][y]);
    }
    return 0;
}