#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    cout << a[0] << ' ';
    for(int i = 1; i < n; i++) {
        int L = a[i - 1], R = a[i];
        for(int j = L + 1; j < R; j++) cout << j << ' ';
        for(int j = L - 1; j > R; j--) cout << j << ' ';
        cout << a[i] << ' ';
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

