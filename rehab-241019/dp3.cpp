#include <bits/stdc++.h>
using namespace std;

const int maxn = 200;
int n;
int ta[maxn], tb[maxn], tc[maxn];
int dp[maxn][5];
signed main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d %d %d", &ta[i], &tb[i], &tc[i]);
    }
    for(int i = 1; i <= n; i++) {
        //dp[i][t]表示0~i, t结尾的最少培训费  答案为max dp[n][a/b/c]
        dp[i][1] = min(dp[i - 1][2] + ta[i], dp[i - 1][3] + ta[i]);
        dp[i][2] = min(dp[i - 1][1] + tb[i], dp[i - 1][3] + tb[i]);
        dp[i][3] = min(dp[i - 1][1] + tc[i], dp[i - 1][2] + tc[i]);
    }
    cout << min(min(dp[n][1], dp[n][2]), dp[n][3]) << endl;
    return 0;
}
