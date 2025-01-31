#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, tmp; cin >> n;
    ll x = 0;
    for(int i = 0; i < n; i++) { 
        cin >> tmp;
        x ^= tmp;
    }
    cout << (x ? "Yes" : "No") << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
