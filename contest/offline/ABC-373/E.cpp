#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
using namespace std;
using ll = long long;

void solve() {
    int n, m; ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(auto &i : a) {
        cin >> i;
        k -= i;
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] > a[j]; });

    vector<ll> b = a;
    sort(b.begin(), b.end(), std::greater<ll>());

    vector<ll> pre(n + 1, 0ll);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + b[i - 1];
    }
    auto check = [&](ll x, int i) -> bool {
        ll val = b[i];
        auto lid = lower_bound(b.begin(), b.end(), x + val + 1, std::greater<ll>()) - b.begin();
        auto rid = m; if(i < m) rid++;
        ll cnt = 0;
        if(lid < rid) cnt += (x + val + 1) * (rid - lid) - (pre[rid] - pre[lid]);

        if(i >= lid && i < rid) cnt -= x + 1;
        cnt += x;
        // (x + val + 1) * L - sum(0, 0 + L) > k - x
        return cnt > k;
    };
    vector<ll> ans(n, 0ll);
    for(int i = 0; i < n; i++) {
        ll l = 0, r = k;
        while(l < r) {
            ll mid = (l + r) >> 1;
            if(check(mid, i)) r = mid;
            else l = mid + 1;
        }
        if(check(l, i)) ans[ord[i]] = l;
        else ans[ord[i]] = -1;
    }
    for(int i = 0; i < n; i++) 
        cout << ans[i] << " \n"[i == n - 1];
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

