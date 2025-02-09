// 你妈的, 这写的是什么寄吧玩意?
// Accepted
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    //  0  1
    cin >> n >> m >> k;
    if (abs(n - m) > k || k > max(n, m)) {
        cout << -1 << '\n';
        return;
    }
    int ZERO = 0, ONE = 1;
    if (n < m) {
        swap(n, m);
        swap(ZERO, ONE);
    }
    ll monitor = n + m;
    for (int i = 1; i <= k; i++) {
        cout << ZERO;
        monitor--;
    }
    if (m - (n - k) == k) {
        for (int i = 1; i <= k; i++) {
            cout << ONE;
        }
        for (int i = 1; i <= (n - k); i++) {
            cout << ZERO << ONE;
        }
        cout << '\n';
        return;
    }
    if (monitor > m - (n - k)) {
        cout << ONE;
        monitor--;
    }
    for (int i = 1; i <= m - (n - k); i++) {
        cout << ONE;
        monitor--;
    }
    if (monitor > 0)
        cout << ZERO;
    for (int i = 1; i <= (n - k - 1); i++) {
        cout << ONE << ZERO;
        monitor -= 2;
    }
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
