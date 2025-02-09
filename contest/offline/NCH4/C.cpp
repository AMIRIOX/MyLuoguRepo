//!pending
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

void solve() {
    int n; string s;
    cin >> n >> s;
    if(s.length() == 1) {
        cout << (s[0] == '?' ? 2 : 1) << '\n';
        return;
    }

    ll k = ranges::count(s.begin(), s.end(), '?');
    ll c1 = (1LL << (k + 1)) % mod;
    ll c2 = (1LL << k) % mod * (s.length() - 2) % mod;

    if(s[0] == '?' && s.back() == '?') cout << (c1 + c2) / 4 * 2 % mod << '\n';
    else if((s[0] == '1' && s.back() == '0') || (s[0] == '0' && s.back() == '1'))
        cout << c1 << '\n';
    else if(s[0] == s.back()) {
        cout << c2 << '\n';
    }else cout << (c1 + c2) / 2 % mod << '\n';
}

signed main() {
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
