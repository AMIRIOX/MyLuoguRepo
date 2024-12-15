#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define mii map<int, int>

void solve() {
    /*
    a1b1 a1b2 a1b3 a1b4
    a2b1 a2b2 a2b3 a2b4
    a3b1 a3b2 a3b3 a3b3
    a4b1 a4b2 a4b3 a4b4
    */
    // sum[i][j] = presum[1, ai] * presum[1, bi]
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n + 2, 0);
    vector<ll> b(m + 2, 0);
    vector<ll> sufsuma(n + 2, 0);
    vector<ll> sufsumb(m + 2, 0);
    vector<ll> presuma(n + 2, 0);
    vector<ll> presumb(m + 2, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        presuma[i] = presuma[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--)
        sufsuma[i] = sufsuma[i + 1] + a[i];

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        presumb[i] = presumb[i - 1] + b[i];
    }
    for (int i = m; i >= 1; i--)
        sufsumb[i] = sufsumb[i + 1] + b[i];

    map<int, int> qry;
    vector<int> qrys;
    for (int i = 1; i <= q; i++) {
        ll x;
        cin >> x;
        qry[x] = 1;
        qrys.push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll tmp = presuma[i - 1] * presumb[j - 1] + presuma[i - 1] * sufsumb[j + 1] +
                     sufsuma[i + 1] * presumb[j - 1] + sufsuma[i + 1] * sufsumb[j + 1];
            if (qry[tmp])
                qry[tmp] = 2;
        }
    }

    for (const auto &x : qrys) {
        if (qry[x] == 2)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
