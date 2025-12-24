#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, t;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    vector<int> cost(n * m, 0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> t; t--;
            a[i][j] = t;
            if(cost[t] == 0) cost[t] = 1;
            if(i - 1 >= 0 && a[i - 1][j] == t) cost[t] = 2;
            if(j - 1 >= 0 && a[i][j - 1] == t) cost[t] = 2;
        }
    cout << accumulate(cost.begin(), cost.end(), 0) - *max_element(cost.begin(), cost.end()) << '\n';
}
signed main() {
    int tt = 1; cin >> tt;
    while(tt--) solve();
}


// !unaccepted
/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {-1, +1, -1, +1};
int dy[] = {-1, +1, +1, -1};
int dx2[] = {-1, +1, 0, 0};
int dy2[] = {+0, 0, +1, -1};

void solve() {
    // 最大同色陌生集合 的数量 + 相邻色块的大小的和 -   最大的相邻色快大小
    int n, m;
    cin >> n >> m;
    vector a(n + 1, vector<int>(m + 1, 0));
    vector vis1 = a, vis2 = a;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt1 = 0, cnt2 = 0;

    int s = 0;
    // 同色 陌生人
    // 1 1 1 1 0
    auto dfs1 = [&](auto &&self, int x, int y) -> int {
        vis1[x][y] = cnt1;

        int sub = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis1[nx][ny]) {
                if (a[nx][ny] == a[x][y])
                    sub += self(self, nx, ny);
            }
        }
        return sub + 1;
    };

    int ans2 = 0, k = 0;
    // 同色 相邻
    auto dfs2 = [&](auto &&self, int x, int y) -> int {
        vis2[x][y] = cnt2;

        int sub = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx2[i], ny = y + dy2[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis2[nx][ny]) {
                if (a[nx][ny] == a[x][y])
                    sub += self(self, nx, ny);
            }
        }
        return sub + 1;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // x, y, idx, lst, tot
            if (!vis1[i][j]) {
                cnt1++;
                if (dfs1(dfs1, i, j) == 1)
                    s++;
            }
            if (!vis2[i][j]) {
                cnt2++;
                int r = dfs2(dfs2, i, j);
                ans2 += r;
                k = max(k, r);
            }
        }
    }
    cout << cnt1 - s + ans2 - k << '\n';
    cout << cnt1 << ' ' << s << ' ' << ans2 << ' ' << k << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
*/
