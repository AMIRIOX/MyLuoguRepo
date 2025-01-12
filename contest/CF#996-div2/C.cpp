#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, m; cin >> n >> m;
    vector a(n + 1, vector<ll>(m + 1, 0));
    string path; cin >> path;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            cin >> a[i][j];
    auto nxt = [&](int cx, int cy, char d) {
        if (d == 'D') return pii(cx + 1, cy);
        else return pii(cx, cy + 1);
    };

    vector<ll> sumrow(n + 1, 0);
    vector<ll> sumcol(m + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sumrow[i] += a[i][j];
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
            sumcol[j] += a[i][j];

    vector<int> row(n + 1, 0);
    vector<int> col(m + 1, 0);
    int cx = 1, cy = 1;
    row[cx]++;
    col[cy]++;
    for (size_t i = 0; i < path.size(); i++) {
        auto np = nxt(cx, cy, path[i]);
        cx = np.first; cy = np.second;
        row[cx]++; col[cy]++;
    }

    vector vis(n + 1, vector<int>(m + 1, 0));
    int rem = n + m - 1 - 1;
    const ll x = 0;
    auto upd = [&](int _x, int _y, int _val) {
        a[_x][_y] = _val;
        row[_x]--; col[_y]--;
        rem--; vis[_x][_y] = 1;
        sumrow[_x] += a[_x][_y];
        sumcol[_y] += a[_x][_y];
    };

    upd(1, 1, (row[1] == 1 ? -sumrow[1] : -sumcol[1]));
    cx = 1, cy = 1;
    for (size_t i = 0; i < path.size(); i++) {
        auto np = nxt(cx, cy, path[i]);
        cx = np.first; cy = np.second;
        if (row[cx] == 1 || col[cy] == 1) {
            if (row[cx] == 1) upd(cx, cy, x - sumrow[cx]);
            else if (col[cy] == 1) upd(cx, cy, x - sumcol[cy]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
