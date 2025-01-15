// !unaccepted dp incorrect
// correct dp see C3.cpp

// 在 01 dp 定义状态下, 这个问题不具有最优子结构
// 子问题的最优解不是全局最优解, 且决策方案有后效性
// 比较 CF 849 E, 那个问题子问题做出任何操作决策都不会影响后面的
// 但是这个问题中可能选了某个元素, 若这个元素不属于全局最优解, 就无法得出答案了。
// 正确的方式是对子集动态规划。

/*
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;

ll closer(ll a, ll b, ll target) {
    if(abs(target - a) < abs(target - b)) return a;
    else return b;
}
void solve() {
    int n = 0;
    cin >> n;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll tot = accumulate(a.begin(), a.end(), 0LL);
    vector dp(n + 1, vector<ll>(2, -2e16));
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = closer(dp[i - 1][0], dp[i - 1][1], tot / 2);
        dp[i][1] = closer(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i], tot / 2);
    }
    for(int i = 1; i <= n; i++) {
        cout << dp[i][0] << " \n"[i == n];
    }
    for(int i = 1; i <= n; i++) {
        cout << dp[i][1] << " \n"[i == n];
    }
    ll ans = min(dp[n][0], dp[n][1]);
    cout << max(ans, tot - ans) << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}
*/
