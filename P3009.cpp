#include <cstdio>
#include <iostream>
using namespace std;
int dp[100200], n, a[100200], ans = -100;
signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}