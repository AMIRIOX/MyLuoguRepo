#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    ll ans = 0;
    size_t l = 0, r = 0;
    while (r + 1 < s.length()) {
        ll ansp = 0;
        while (r + 1 < s.length() && s[r + 1] != s[r]) {
            r++;
            // 010 + 1
            if(r - l + 1 == 2) ans++;
            if(r - l + 1 > 2) {
                ans += (r - l);
            }
        }
        l = r + 1, r = r + 1;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
