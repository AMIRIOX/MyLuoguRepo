#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e3 + 1;
const int testDatan = 23;
int a[maxn][maxn];
int n, m, vis[maxn][maxn];
int path[maxn];
int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct coord {
    int x, y, id, parent;
    coord() {}
    coord(int xi, int yi, int idi, int pari = 0)
        : x(xi), y(yi), id(idi), parent(pari) {}
};
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    queue<coord> q;
    q.push(coord(1, 1, 1, 0));
    vis[1][1] = 1;
    while (!q.empty()) {
        coord u = q.front();
        q.pop();
        path[u.id] = u.parent;
        for (int i = 0; i < 4; i++) {
            int vx = u.x + mov[i][0];
            int vy = u.y + mov[i][1];
            if (a[vx][vy] == 0 || vx < 1 || vx > n || vy < 1 || vy > n ||
                vis[vx][vy]) {
                continue;
            }
            vis[vx][vy] = 1;
            q.push(coord(vx, vy, a[vx][vy], u.id));
        }
    }
    stack<int> ans;
    int p = testDatan;
    while (p) {
        ans.push(p);
        p = path[p];
    }
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << endl;
    return 0;
}