#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll ans = 0;
    ll x; cin >> x;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            if(i * j - x) ans += i * j;
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}
