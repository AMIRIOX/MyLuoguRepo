#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve_seg(vector<ll>& a, int k) {
    int l = 0, r = min(int(a.size()) - 1, l + k - 1);
    ll cur = accumulate(a.begin(), a.begin() + r + 1, 0ll);
    ll ansp = cur;
    while (r + 1 < int(a.size())) {
        cur -= a[l];
        r++;
        l++;
        cur += a[r];
        ansp = max(ansp, cur);
    }
    return ansp;
}
void solve() {
    int n, k; cin >> n >> k;
    vector<ll> in(n); for (auto &i : in) cin >> i;

    sort(in.begin(), in.end());
    ll lst = in[0];
    vector<ll> a;
    a.push_back(1);
    ll ans = -2e5;
    for (int i = 1; i < n; i++) {
        ll ai = in[i];
        if (ai == lst) {
            a.back()++;
        }else if(ai == lst + 1) {
            a.push_back(1);
            lst = ai;
        }else {
            ans = max(ans, solve_seg(a, k));
            a.clear();
            a.push_back(1);
            lst = ai;
        }
    }
    ans = max(ans, solve_seg(a, k));
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
