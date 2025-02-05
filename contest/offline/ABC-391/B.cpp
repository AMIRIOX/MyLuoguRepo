#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector S(n, vector<char>(n)), T(m, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> S[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> T[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto check = [&]() {
                for (int di = 0; di < m; di++) {
                    for (int dj = 0; dj < m; dj++) {
                        if (i + di >= n || j + dj >= n || S[i + di][j + dj] != T[di][dj])
                            return false;
                    }
                }
                return true;
            };
            if (check()) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return;
            }
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
