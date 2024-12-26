#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, p = 1;
    cin >> n;
    vector<ll> a(n + 1, 0);
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (abs(a[i]) - 1)
            p = i;
        pre[i] = pre[i - 1] + a[i];
    }
    // [1, p - 1], [p], [p + 1, n]
    vector<ll> ans;
    auto getv = [&](int l, int r) {
        ll mx, mn, ansl = 2e18, ansr = -2e18;
        mx = mn = pre[l - 1]; // 记录最小/最大的 pre[l - 1]
        for (int i = l; i <= r; i++) {
            ansl = min(ansl, pre[i] - mx);
            ansr = max(ansr, pre[i] - mn);

            // 更新
            mx = max(mx, pre[i]);
            mn = min(mn, pre[i]);
        }
        for (ll i = ansl; i <= ansr; i++) {
            ans.push_back(i);
        }
    };
    getv(1, p - 1);
    getv(p + 1, n);

    ll ansl1 = 2e18, ansr1 = -2e18;
    ll ansl2 = 2e18, ansr2 = -2e18;
    for (int i = 1; i <= p; i++) {
        ll t = pre[p] - pre[i - 1];
        ansl1 = min(ansl1, t);
        ansr1 = max(ansr1, t);
    }
    for (int i = p; i <= n; i++) {
        ll t = pre[i] - pre[p - 1];
        ansl2 = min(ansl2, t);
        ansr2 = max(ansr2, t);
    }

    // [1, p] 最值 + [p, n] 最值 - a[p] == [1, n] 最值
    // 注意必须包括 p, a[p] 如果是负数会影响子数组选择
    for (ll i = ansl1 + ansl2 - a[p]; i <= ansr1 + ansr2 - a[p]; i++) {
        ans.push_back(i);
    }

    ans.push_back(0);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for(const auto &i : ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
