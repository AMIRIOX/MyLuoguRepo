#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    if (k < max(n, m)) {
        cout << -1 << '\n';
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == n && j == m)
                    goto end;

                if (j > min(n, m) && i == n) {
                    cout << 1 << ' ';
                    k--;
                } else if (i > min(n, m) && j == m) {
                    cout << 1 << ' ';
                    k--;
                } else if (i == j) {
                    cout << 1 << ' ';
                    k--;
                }else cout << 0 << ' ';
            }
            cout << '\n';
        }
    end:
        cout << k << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
