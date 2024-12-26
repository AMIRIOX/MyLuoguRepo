#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, ans = 1;
    cin >> n;

    while(n > 3) {
        ans <<= 1;
        n >>= 2;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
