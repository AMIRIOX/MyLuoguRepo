#include <cstdio>
#include <iostream>
#include <queue>
// #define int long long
using namespace std;
const int maxn = 50;
int n, a[maxn][maxn], vis[maxn * maxn][maxn * maxn];
int mov[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
struct coord {
    int x, y;
    coord(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    coord(const coord& c) {
        this->x = c.x;
        this->y = c.y;
    }
};
bool check(int a, int b) {
    if (a >= 1 && a <= n && b >= 1 && b <= n) return true;
    return false;
}
void bfs(int x, int y) {
    queue<coord> q;
    q.push(coord(x, y));
    vis[x][y] = 1;
    while (!q.empty()) {
        coord curd = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ux = curd.x + mov[i][0];
            int uy = curd.y + mov[i][1];
            if (check(ux, uy) && a[ux][uy] != 1 && !vis[ux][uy]) {
                a[ux][uy] = 0;
                vis[ux][uy] = 1;
                q.push(coord(ux, uy));
            }
        }
    }
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) a[i][j] = 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i == 1 || i == n || j == 1 || j == n) && (a[i][j] != 1)) {
                a[i][j] = 0;
                bfs(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}