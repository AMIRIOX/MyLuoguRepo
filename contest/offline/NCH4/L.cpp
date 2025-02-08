#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector pa(n + 1, vector<int>(31, 0));
    vector pb(n + 1, vector<int>(31, 0));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pa[i] = pa[i - 1];
        for(int k = 0; k <= 30; k++) {
            if((a[i] >> k) & 1) pa[i][k]++;
        }
    }

    vector sans(n + 2, 1LL); 
    // sans[i]: func[i, n]
    // ai * bi + ai ^ bi+1 ... 
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pb[i] = pb[i - 1];
        for(int k = 0; k <= 30; k++) {
            if((b[i] >> k) & 1) pb[i][k]++;
        }
    }

    for(int i = n; i >= 1; i--) {
        sans[i] = sans[i + 1];
        for(int k = 0; k <= 30; k++) {
            ll cntb1 = pb[n][k] - pb[i - 1][k];
            ll cntb0 = n - i + 1 - cntb1;
            if((a[i] >> k) & 1) sans[i] += cntb0 * (1LL << k) % mod;
            else sans[i] += cntb1 * (1LL << k) % mod;
            sans[i] %= mod;
        }
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        ll ans = (sans[l] - sans[r + 1] + mod) % mod;
        for(int k = 0; k <= 30; k++) {
            ll cnta1 = pa[r][k] - pa[l - 1][k];
            ll cnta0 = (r - l + 1) - cnta1;
            ll cntb1 = pb[n][k] - pb[r][k];
            ll cntb0 = (n - r) - cntb1;
            ll addend = cnta1 * cntb0 + cnta0 * cntb1;
            ans -= (addend % mod) * (1LL << k) % mod;
            ans = (ans + mod) % mod;
        }
        cout << ans << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
