#include <iostream>
using namespace std;
const int maxn = 100010;
const int inf = 0x7fffffff;
int a[maxn], dp[maxn];
int ans = -inf, n;
int main() {
    scanf("%d", &n);

    // O(n^2)
    //? dp[i]=max{dp[j]+1 | j<i, Aj<Ai}
    if (0) {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), dp[i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (a[j] < a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
    }

    // O(nlogn)
    for(int i=0;i<n;i++) scanf("%d", &a[i]),dp[i]=inf;
    dp[0]=a[0]; int pos = 0;
    for(int i=1;i<n;i++) {
        if(a[i]>=dp[pos]) dp[++pos] = a[i];
        else {
            *lower_bound(dp,dp+n,a[i]) = a[i];
        }   
    }
    // printf("%d", ans);
    printf("%d", pos + 1);
    return 0;
}