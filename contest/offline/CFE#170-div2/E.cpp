#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 998244353;

ll add(ll a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
    return a;
}

ll mul(ll a, ll b) {
    return a * b % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector ways(m + 1, vector<ll>(m + 1));
    ways[0][0] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j <= i; j++) {
            ways[i + 1][j + 1] = add(ways[i + 1][j + 1], ways[i][j]);
            if(j) ways[i + 1][j - 1] = add(ways[i + 1][j - 1], ways[i][j]);
        }
    }

    vector dp(n + 1, vector<ll>(m + 1));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k <= m; k++) {
                int ex = i ? j - k : j + k;
                if(0 <= ex && ex <= m) dp[i + 1][ex] = add(dp[i + 1][ex], mul(dp[i][j], ways[m][k]));
            }
        }
    }
    
    cout << dp[n][0] << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; //cin >> tt;
    while(tt--) solve();
    return 0;
}
