#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 15;

int n;
int a[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n;
    int x, y, v;
    while(1) {
        cin >> x >> y >> v;
        if(!x && !y && !v) break;
        a[x][y] = v;
    }
    /*
    dp[i][j][k][l]是一条路线走到(i, j) 另一条走到(k, l)时的答案
    dp[i][j][k][l] = max {
                dp[i-1][j][k][l-1]
                dp[i-1][j][k-1][l]
                dp[i][j-1][k][l-1]
                dp[i][j-1][k-1][l]
                }
                + a[i][j] + a[k][l]
                - ↑ * [i == k && j == l]
    */
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                for(int l = 1; l <= n; l++) {
                    dp[i][j][k][l] = max({
                        dp[i-1][j][k][l-1],
                        dp[i-1][j][k-1][l],
                        dp[i][j-1][k][l-1],
                        dp[i][j-1][k-1][l]}) + a[i][j] + a[k][l];
                    if(i == k && j == l) 
                        dp[i][j][k][l] -= a[i][j];
                }
            }
        }
    }
    cout << dp[n][n][n][n] << '\n';
    return 0;
}
