#include <cstdio>
#include <iostream>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e2 + 1;
char a[maxn][maxn];
int n, m;
int mov[8][2] = {{0, 1},   {1, 0}, {-1, 0}, {0, -1},
                 {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
int cnt, which[maxn][maxn], vis[maxn][maxn];
void dfs(int x, int y) {
    if (a[x][y] == '@') vis[x][y] = 1;
    which[x][y] = cnt;
    for (int i = 0; i < 8; i++) {
        int nx = x + mov[i][0];
        int ny = y + mov[i][1];
        if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] ||
            a[x][y] != '@') {
            continue;
        }
        cout << "> >?" << endl;
        dfs(nx, ny);
    }
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!which[i][j] && a[i][j] == '@') {
                cnt++;
                cout << i << ' ' << j << "is a new block's elem" << endl;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
    return 0;
}