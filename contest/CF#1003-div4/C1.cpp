#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, b;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    cin >> b;
    if(b - a[0] < a[0]) a[0] = b - a[0];
    for(int i = 1; i < n; i++) {
        if(b - a[i] >= a[i - 1] && b - a[i] < a[i]) {
            a[i] = b - a[i];
        }
        if(a[i] < a[i - 1]) {
            if(b - a[i] >= a[i - 1]) {
                a[i] = b - a[i];
            }else {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
