#include <iostream>
using namespace std;
const int maxn = 100010;
const int inf = 0x7fffffff;
int a[maxn],dp[maxn];
int ans = -inf, n;
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]), dp[i]=1;
    for(int i=2;i<=n;i++) {
        for(int j=1;j<i;j++) {
            if(a[j]<a[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}