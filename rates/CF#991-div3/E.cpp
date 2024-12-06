#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string ia, ib, ic;
    cin >> ia >> ib >> ic;
    int na = ia.size(), nb = ib.size();
    vector<vector<int> > dp(na + 1, vector<int>(nb + 1, na + nb + 1));
    dp[0][0] = 0;
    for(int a = 0; a <= na; a++) {
        for(int b = 0; b <= nb; b++) {
            if(a + 1 <= na) dp[a + 1][b] = min(dp[a + 1][b], dp[a][b] + int(ia[a] != ic[a + b]));
            if(b + 1 <= nb) dp[a][b + 1] = min(dp[a][b + 1], dp[a][b] + int(ib[b] != ic[a + b]));
        }
    }
    cout << dp[na][nb] << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
