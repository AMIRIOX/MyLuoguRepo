#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        bool ok = true;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(abs(a[i] - a[j]) % k == 0) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << "YES\n" << i << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
