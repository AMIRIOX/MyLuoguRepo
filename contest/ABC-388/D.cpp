#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b(n + 2, 0);
    int cur = 0;
    for(int i = 1; i < n; i++) {
        cur += b[i];
        a[i] += cur;

        b[i + 1] += 1;
        b[min(i + a[i], n) + 1] -= 1;
        a[i] -= min(a[i], n - i);
    }
    cur += b[n];
    a[n] += cur;
    for(int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

