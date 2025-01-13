#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long;

inline char trans(const char &c) {
    // 65 97
    if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    else return c - 'a' + 'A';
}
void solve() {
    string s; int q = 0;
    cin >> s >> q;
    const ll n = s.size();
    auto f = [&](auto &&self, ll k) -> char{
        if(k - 1 < n) return s[k - 1];

        ll base = n, p = 0;
        while(base < k) {
            p++;
            base *= 2LL;
        }
        p--;
        // ll p = (log2(k / n));
        // if(k == (1LL << p) * n) p--;
        k -= (1LL << p) * n;
        return trans(self(self, k));
    };
    while (q--) {
        ll k = 0;
        cin >> k;
        cout << f(f, k) << ' ';
    }
    endl(cout);
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
