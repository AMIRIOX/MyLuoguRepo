#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &i: a) cin >> i;
    sort(a.begin(), a.end(), std::greater());
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        if(tot + a[i] <= k) tot += a[i];
        else break;
    }
    cout << max(0ll, k - tot) << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
