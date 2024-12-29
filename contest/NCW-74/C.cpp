#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    while(n > 2 && m > 0) {
        n = ceil(sqrt(n));
        m--;
    }
    cout << n - m << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
