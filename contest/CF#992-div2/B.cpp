#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    
    /*
    ll cur = 1, ans = 1;
    while(cur < n) {
        cur = (cur + 1) * 2;
        ans++;
    }
    */

    ll ans2 = ceil(log2(ceil((n + 2) / 3.0))) + 1;

    cout << ans2 << '\n';
}
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
