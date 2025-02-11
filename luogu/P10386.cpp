// 群友在讨论才看的
// 这寄吧玩意怎么标黄题了

#include <bits/stdc++.h>
using namespace std;

int a[10][10];
bool vis[10][10];

long long ans;
bool check(int x, int y) {
    if(!((x == 12 && y == 13) || (x == 13 && y == 12))) return false;
    for (int i = 1; i <= 5; i++) {
        if ((a[i][1] == a[i][2]) && (a[i][2] == a[i][3]) && (a[i][3] == a[i][4]) &&
            (a[i][4] == a[i][5]))
            return false;
    }
    for (int j = 1; j <= 5; j++) {
        if ((a[1][j] == a[2][j]) && (a[2][j] == a[3][j]) && (a[3][j] == a[4][j]) &&
            (a[4][j] == a[5][j]))
            return false;
    }
    if (a[1][1] == a[2][2] && a[2][2] == a[3][3] && a[3][3] == a[4][4] && a[4][4] == a[5][5])
        return false;
    if (a[5][1] == a[4][2] && a[4][2] == a[3][3] && a[3][3] == a[2][4] && a[2][4] == a[1][5])
        return false;
    return true;
}

void dfs(int x, int y, int n) {
    if (n > 25) {
        if (check(x, y))
            ans++;
        return;
    }
    int nx = (n - 1) / 5 + 1;
    int ny = (n - 1) % 5 + 1;
    if (nx >= 1 && ny >= 1 && nx <= 5 && ny <= 5 && !vis[nx][ny]) {
        for (int k = 1; k < 3; k++) {
            vis[nx][ny] = true;
            a[nx][ny] = k;
            dfs(x + (k == 1), y + (k == 2), n + 1);
            vis[nx][ny] = false;
        }
    }
}

signed main() {
    dfs(0, 0, 1);
    cout << ans / 2 << endl;
}

