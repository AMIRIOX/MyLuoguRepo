#include <iostream>
using namespace std;
int vis[120][120], ans;
char mp[120][120];
int n, m;
int walk[8][2] = {{0, 1},   {1, 0}, {-1, 0}, {0, -1},
                  {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int nx = x + walk[i][0], ny = y + walk[i][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == 'W' &&
            !vis[nx][ny])
            dfs(nx, ny);
    }
}
signed main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            // scanf("%s", mp[i]);
            cin >> mp[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(mp[i][j]=='W' && !vis[i][j]) {
                dfs(i,j);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
