#ifdef DFS_METHOD
#include <iostream>
using namespace std;
const int maxn = 120;
int n, m, a[maxn][maxn];
int ans, vis[maxn][maxn];
int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool isp(int x) {
    return x != 0;
}
void dfs(int i, int j) {
    a[i][j] = 0;
    for (int t = 0; t < 4; t++) {
        if (i <= 0 || j <= 0 || j > m || i > n)
            continue;
        if (isp(a[i + mov[t][0]][j + mov[t][1]]))
            dfs(i + mov[t][0], j + mov[t][1]);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    // cout << n << m << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d", &a[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (isp(a[i][j]))
                ans++, dfs(i, j);
    printf("%d", ans);
    return 0;
}
#endif

#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 120;
int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool isp(int x) {
    return x != 0;
}

int n, m, ans;
int a[maxn][maxn], vis[maxn][maxn];
void bfs(int sx, int sy) {
    queue<pair<int, int> > q;
    q.push({sx, sy});
    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        vis[curx][cury] = 1;
        a[curx][cury] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = curx + mov[i][0];
            int ny = cury + mov[i][1];
            if (nx <= 0 || ny <= 0 || ny > m || nx > n || !isp(a[nx][ny]))
                continue;
            q.push({nx, ny});
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    // cout << n << m << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (isp(a[i][j]))
                ans++, bfs(i, j);
    printf("%d", ans);

    return 0;
}