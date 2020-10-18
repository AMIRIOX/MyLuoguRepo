#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1100;
int n, m, p[maxn][maxn], vis[maxn][maxn];
int ans = INF;
int L = INF, R = -INF;
struct coord {
    int x, y;
    coord(int x1, int y1) : x(x1), y(y1) {}
};
signed mov[4][2]{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};
bool bfs(coord start, int x) {
    memset(vis,0,sizeof(vis));
    vis[start.x][start.y] = 1;
    queue<coord> q;
    q.push(start);
    while (!q.empty()) {
        coord curc = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            coord nxtc(curc.x + mov[i][0], curc.y + mov[i][1]);
            if (nxtc.x < 1 || nxtc.x > n || nxtc.y < 1 || nxtc.y > m ||
                vis[nxtc.x][nxtc.y] || p[nxtc.x][nxtc.y] > x)
                continue;
            vis[nxtc.x][nxtc.y]=1;
            if (nxtc.x == n) return true;
            q.push(nxtc);
        }
    }
    return false;
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> p[i][j];
            L=min(L,p[i][j]);
            R=max(R,p[i][j]);
        }
    }
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (bfs(coord(1, 1), mid)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    cout << ans;
    return 0;
}