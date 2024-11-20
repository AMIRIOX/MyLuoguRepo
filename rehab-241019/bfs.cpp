#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
constexpr int maxn = 1000;

int movx[] = {+1, +2, +1, +2, -1, -2, -1, -2};
int movy[] = {-2, -1, +2, +1, +2, +1, -2, -1};
int vis[maxn][maxn], dis[maxn][maxn];
int n, m, sx, sy;
void bfs() {
    queue<pii> q;
    q.push(pii(sx, sy));
    vis[sx][sy] = 1;
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        int cx = cur.first, cy = cur.second;
        for(int i = 0; i < 8; i++) {
            int nx = cx + movx[i], ny = cy + movy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny]) continue;
            dis[nx][ny] = dis[cx][cy] + 1;
            vis[nx][ny] = 1;
            q.push(pii(nx, ny));
        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n >> m >> sx >> sy;
    bfs();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int v = dis[i][j];
            if(v) cout << v << " ";
            else if(i == sx && j == sy) cout << 0 << " ";
            else cout << -1 << " ";
        }
        endl(cout);
    }
    return 0;
}
