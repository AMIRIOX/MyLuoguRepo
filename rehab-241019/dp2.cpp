#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 1e3 + 10;

int dp[maxn][maxn], a[maxn];
signed main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) { 
        cin >> a[i]; 
    }
    
    // dp[i][j] = dp[i-1][j] + (dp[i-1][j - a[i] % k] + a[i]);
    // dp[n][0]

    for(int i = 1; i < k; i++) dp[0][i] = -1e17;
    for(int i = 1; i <= n; i++) {
        // dp[i][(a[i] + k) % k] += (dp[i - 1][(a[i] + k) % k] + a[i]);
        // dp[i][a[i] % k] += (dp[i - 1][a[i] % k] + a[i]); 
        // dp[i][k - a[i] % k] += (dp[i - 1][k - a[i] % k] + a[i]);
        
        for(int j = 0; j < k; j++) {
            dp[i][j] = dp[i - 1][j]; 
        }

        for(int j = k - 1; j >= 0; j--) {
            dp[i][(j + a[i]) % k] = max(dp[i][(j + a[i]) % k], dp[i - 1][j] + a[i]);
        }
        // dp[i][a[i] % k] += dp[i - 1][j];
    }
    cout << (dp[n][0] > 0 ? dp[n][0] : -1) << endl;
    return 0;
}
