#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
const int MOD = 1e9+7;

int dp[maxn];
void solve() {
    memset(dp, 0, sizeof(dp));
    int n = 0, k = 0;
    cin >> n >> k;
    int m = n;
    for(int i = 1; i <= k; i++) {
        int r0 = 0, c0 = 0;
        cin >> r0 >> c0;
        m -= (2 - (r0 == c0));
    }
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= m; i++)
        dp[i] = int((dp[i-1] + (2ll * (i - 1) * dp[i - 2]) % MOD) % MOD) ; 
    
    cout << dp[m] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve(); 
    //return 0;
}
// -Wall -Werror -Wextra -pedantic -Wimplicit-fallthrough -Wsequence-point -Wswitch-default -Wswitch-unreachable -Wswitch-enum -Wstringop-truncation -Wbool-compare -Wtautological-compare -Wfloat-equal -Wshadow=global -Wpointer-arith -Wpointer-compare -Wcast-align -Wcast-qual -Wwrite-strings -Wdangling-else -Wlogical-op -std=c++11

