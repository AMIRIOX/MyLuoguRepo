#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<int> > dp(n + 1, vector<int>(2, 0));
    // dp[i][f]表示前i个数中，是否翻转a[i-1]和a[i]，的答案 
    dp[0][0] = dp[0][1] = 0; 
    dp[1][0] = a[1];
    dp[2][0] = a[1] + a[2];
    dp[2][1] = - a[1] - a[2];
    for(int i = 3; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
        dp[i][1] = max(dp[i - 1][0] - a[i - 1] - a[i] - a[i - 1],
                        dp[i - 1][1] + (-a[i] + a[i - 1]) + a[i - 1]);
    } 
    cout << max(dp[n][0], dp[n][1]) << '\n';
}
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
