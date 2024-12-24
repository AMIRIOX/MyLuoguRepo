#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    ll k = log2(n)/log2(4);
    cout << (1 << k) << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
