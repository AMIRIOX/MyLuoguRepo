#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll L, R, G;
    cin >> L >> R >> G;
    for(ll a = L; a <= R; a++) {
        if(a % G) continue;
        for(ll f = R / G; f * G >= a; f--) {
            ll at = a / G, bt = f;
            if(std::gcd(at, bt) == 1) {
                cout << a << " " << f * G << '\n';
                return;
            }
        }
    }
    cout << -1 << " " << -1 << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
