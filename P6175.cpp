#include <cstdio>
#include <iostream>
#define re register
using namespace std;
#define int long long

const int maxn = 150;
const int inf = 0x7fffffff;
int n, m, x, y, d, ans = inf, st;
int gr[maxn][maxn], vis[maxn], mp[maxn][maxn];

// // 求出以st为起点的环的权最小值
// void dfs(int already, int u, int dis, int last) {
//     if (u == st && already >= 3 && vis[u] != 2) {
//         ans = min(ans, dis + gr[last][u]);
//         vis[u] = 2;
//         return;
//     }
//     if (vis[u]) return;
//     for (int i = 1; i <= n; i++) {
//         if (gr[u][i] > 0 && !vis[gr[u][i]]) {
//             cout << "on point: " << u << endl;
//             vis[u] = 1;
//             cout << "goto child: " << gr[u][i] << endl;
//             dfs(already + 1, gr[u][i], dis + gr[last][u], u);
//             cout << "back father: " << gr[u][i] << endl;
//             vis[u] = 0;
//         }
//     }
// }

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) gr[i][j] = mp[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> d;
        gr[x][y] = min(gr[x][y], d);
        gr[y][x] = min(gr[y][x], d);

        mp[x][y] = min(mp[x][y], d);
        mp[y][x] = min(mp[y][x], d);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i < k; i++)
            for (int j = i + 1; j < k; j++)
                ans = min(ans, gr[i][j] + mp[k][j] + mp[i][k]);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
                gr[j][i] = gr[i][j];
            }
    }

    // for (int i = 1; i <= n; i++) {
    //     st = i;
    //     dfs(0, i, 0, -1);
    // }
    if (ans == inf)
        cout << "No solution." << endl;
    else
        cout << ans << endl;
    return 0;
}