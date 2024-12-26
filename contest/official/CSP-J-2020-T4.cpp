#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int maxn = 1e3 + 10;
const LL mins = -1e18;
int n, m;
LL a[maxn][maxn];
LL mem[maxn][maxn][2];
LL dfs(int x, int y, int from) {
    if (x < 1 || x > n || y < 1 || y > m)
        return mins;
    if (mem[x][y][from] != mins)
        return mem[x][y][from];
    if (from == 0) {
        mem[x][y][from] =
            max(max(dfs(x + 1, y, 0), dfs(x, y - 1, 0)), dfs(x, y - 1, 1)) +
            a[x][y];
    } else {
        mem[x][y][from] =
            max(max(dfs(x - 1, y, 1), dfs(x, y - 1, 0)), dfs(x, y - 1, 1)) +
            a[x][y];
    }
    return mem[x][y][from];
}
int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &a[i][j]);
            mem[i][j][0] = mem[i][j][1] = mins;
        }
    }
    mem[1][1][0] = mem[1][1][1] = a[1][1];
    printf("%lld\n", dfs(n, m, 1));
    return 0;
}