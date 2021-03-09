#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e3 + 10;
int n, m, a[maxn][maxn], vis[maxn][maxn];
int mov[3][2] = {{-1, 0}, {1, 0}, {0, 1}};
int ans = -0x7fffffff;
// int mem[maxn][maxn];
void dfs(int x, int y, int cur) {
    if (x == n && y == m) {
        ans = max(ans, cur + a[x][y]);
        return;
    } else {
        for (int i = 0; i < 3; i++) {
            int nx = x + mov[i][0], ny = y + mov[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny])
                continue;
            vis[nx][ny] = 1;
            dfs(nx, ny, cur + a[x][y]);
            vis[nx][ny] = 0;
        }
    }
}
signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    dfs(1, 1, 0);
    printf("%lld\n", ans);
    return 0;
}