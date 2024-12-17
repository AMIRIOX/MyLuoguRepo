#include <algorithm>
#include <bits/stdc++.h>
#include <cwchar>
using namespace std;

using ll = long long;

char c;
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    std::for_each(v.begin(), v.end(), [&](ll &i) { cin >> c; i = (c == '0' ? -1 : 1); });

    for (int i = n - 2; i >= 0; i--) {
        v[i] += v[i + 1];
    }
    v.erase(v.begin()); 
    sort(v.begin(), v.end(), std::greater());

    ll tot = 0, idx = 0;
    while (tot < k && idx < n - 1) {
        tot += v[idx++];
    }

    cout << (tot >= k ? idx + 1 : -1) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
