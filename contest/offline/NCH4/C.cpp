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
    // ll c1 = (1LL << (k + 1)) % mod;
    // ll c2 = (1LL << k) % mod * (s.length() - 2) % mod;
    ll ans = 1;

    if(s[0] == '?' && s.back() == '?') {
        // cout << (c1 + c2) / 4 * 2 % mod << '\n';
        for(int i = 1; i <= k; i++) {
            ans = (ans * 2LL) % mod;
        }
        ans = s.length() * ans / 2 % mod;
        cout << ans % mod << '\n';

    }
    else if((s[0] == '1' && s.back() == '0') || (s[0] == '0' && s.back() == '1')) {
        for(int i = 1; i <= k + 1; i++) {
            ans = (ans * 2LL) % mod;
        }
        cout << ans << '\n';
    }
    else if(s[0] == s.back()) {
        for(int i = 1; i <= k; i++) {
            ans = (ans * 2LL) % mod;
        }
        ans = (s.length() - 2) % mod * ans % mod;
        cout << ans << '\n';
    }else {
        for(int i = 1; i <= k; i++) {
            ans = (ans * 2LL) % mod;
        }
        ans = s.length() * ans / 2 % mod;
        cout << ans % mod << '\n';
    }
}

signed main() {
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
