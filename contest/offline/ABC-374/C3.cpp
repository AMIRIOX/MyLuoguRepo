// !unaccepted TLE

#ifdef TLE_ALLOWED
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll tot = accumulate(a.begin(), a.end(), 0LL);
    ll target = tot / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = target; j >= a[i]; j--) {
            dp[j] = dp[j] || dp[j - a[i]];
        }
    }

    ll ans = 0;
    for (int j = target; j >= 0; j--) {
        if (dp[j]) {
            ans = j;
            break;
        }
    }

    cout << max(ans, tot - ans) << '\n';  
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

#endif
