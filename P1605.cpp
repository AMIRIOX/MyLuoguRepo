#include <cstdio>
#include <iostream>
#define re register
using namespace std;
const int maxn = 1000;
int n, m, t, ans;
int vis[maxn][maxn], obs[maxn][maxn];
int sx, sy, fx, fy;
int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int x, int y) {
    if (vis[x][y] || obs[x][y]) return;
    if (x == fx && y == fy) {
        ans++;
        return;
    }
    /*if(x==2 && y==1)*/  // cout << vis[x][y] << ' ' << obs[x][y] << endl;
    // cout << "current position: " << x << ' ' << y << ';' << endl;
    for (int i = 0; i < 4; i++) {
        int ux = x + mov[i][0];
        int uy = y + mov[i][1];
        // cout << x << '+' << mov[i][0] << "; " << y << '+' <<mov[i][1] <<
        // endl; if(ux==2 && uy==2) cout << "(wow: "<< bool(ux >= 1 && ux <= n
        // && uy >= 1 && uy <= m) << endl;
        if (ux >= 1 && ux <= n && uy >= 1 && uy <= m) {
            vis[x][y] = 1;
            // cout << endl << "going to: " << ux << ' ' << uy << ';' << endl;
            dfs(ux, uy);
            // cout << "back to: " << x << ' ' << y << ';' << endl << endl;
            vis[x][y] = 0;
        }
    }
}
int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        obs[a][b] = 1;
    }
    dfs(sx, sy);
    cout << ans;
    return 0;
}