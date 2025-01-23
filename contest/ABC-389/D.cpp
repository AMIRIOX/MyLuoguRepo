#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int x, double cmp) {
    return 1LL * x * x + x <= cmp;
}
void solve() {
    int R = 0; cin >> R;
    ll ans = 0;
    for(int y = 1; y <= R; y++) {
        const double M = 1LL * R * R - 1LL * y * y - y - 0.5;
        // find the maximum x s.t. x^2 + x <= M
        int l = 0, r = R;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(check(mid, M)) l = mid;
            else r = mid - 1;
        }
        if(check(l, M)) ans += l;
    }
    cout << ans * 4 + (R - 1) * 4 + 1 << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

