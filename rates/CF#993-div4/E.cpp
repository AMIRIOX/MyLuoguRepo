#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define mii map<int, int>

void solve() {
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll ans = 0, base = 0, n = 0;
    for(int n = 0; n <= 30; n++) {
        // y = k^n * x
        // 在[l1, r1]二分x判断y是不是在[l2, r2]
        base = pow(k, n);
        if(base > r2/l1) break;
        auto checkl = [&](const ll &x) {
            return base * x >= l2;
        };
        auto checkr = [&](const ll &x) {
            return base * x <= r2;
        };

        ll l = l1, r = r1;
        while(l < r) {
            ll mid = (l + r) >> 1;
            if(checkl(mid)) r = mid;
            else l = mid + 1;
        }
        ll ansl = l;

        l = l1, r = r1;
        while(l < r) {
            ll mid = (l + r + 1) >> 1;
            if(checkr(mid)) l = mid;
            else r = mid - 1;
        }
        ll ansr = l;
        
        if(checkl(ansl) && checkr(ansr) && ansr >= ansl) ans += ansr - ansl + 1;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
