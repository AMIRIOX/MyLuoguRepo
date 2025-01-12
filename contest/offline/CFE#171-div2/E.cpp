// unaccepted: Wrong thought
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<ll, map<ll, ll>> dp;

    for (ll S = 0; S <= (1 << n); S++) {
        auto getor = [&](long long Si) {
            ll orres = 0;
            for (int i = 1; i <= n; i++) {
                if ((Si >> (i - 1)) & 1)
                    orres |= a[i];
            }
            return orres;
        };

        for (int i = 1; i <= n; i++) {
            if ((S >> (i - 1)) & 1) {
                //! 由于 and 操作不可撤销, 所以不能 dp
                dp[i][S] = max(dp[i - 1][S ^ (1 << (i - 1))] + 1 + __builtin_popcount(S), dp[i - 1][S]);
            }
        }
    }
    return 0;
}
