#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 200;
struct node {
    int x, y, d;
    node(int _x = 0, int _y = 0, int _d = 0): x(_x), y(_y), d(_d) {}
};
char a[maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dis[maxn][maxn];
int vis[maxn][maxn];
int n, ax, ay, bx, by;

bool check(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > n || a[x][y] == 'x') return false;
    return true;
}
int bfs(int sx, int sy) {
    queue<node> q;
    dis[sx][sy] = 0;
    q.push(node(sx, sy, -1));
    vis[sx][sy] = 1;
    while(!q.empty()) {
        node cur = q.front(); q.pop();
        if(cur.x == bx && cur.y == by) return cur.d;
        for(int i = 0; i < 4; i++) {
            node nxt = node(cur.x + dx[i], cur.y + dy[i]);
            while(check(nxt.x, nxt.y)) {
                if(!vis[nxt.x][nxt.y]) {
                    nxt.d = cur.d + 1;
                    vis[nxt.x][nxt.y] = 1;
                    q.push(nxt);
                }
                nxt.x += dx[i]; nxt.y += dy[i];
            }
        }
    }
    return -1;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n;
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'A') ax = i, ay = j;
            if(a[i][j] == 'B') bx = i, by = j;
        }
    }
    cout << bfs(ax, ay) << '\n';
    return 0;
}
