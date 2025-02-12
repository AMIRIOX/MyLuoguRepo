#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, tmp; cin >> n;
    ll sum = 0;
    ll ans = 0x7fffffff;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp;
        ans = min(ans, sum);
    }
    cout << sum + max(-ans, 0LL) << '\n'; // (sum < 0 ? -sum : 0)
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

