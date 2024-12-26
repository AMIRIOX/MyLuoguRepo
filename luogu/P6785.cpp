#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e6 + 10;
int n, k, sum[maxn << 1], maxi;
signed main() {
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%lld %lld", &x, &y);
        sum[x] += y;
        maxi = max(maxi, x);
    }
    if (k == 0) {
        int ans = -0x7fffffff;
        for (int i = 0; i <= maxi; i++) {
            if (sum[i] > 1) {
                ans = max(ans, i * sum[i]);
            }
        }
        if (ans != -0x7fffffff)
            printf("%lld\n", ans);
        else
            printf("NO\n");
        return 0;
    } else {
        int ans = -0x7fffffff;
        for (int i = 0; i <= maxi; i++) {
            int a = i, b = i + k;
            if (sum[a] && sum[b]) {
                ans = max(ans, (a + b) * min(sum[a], sum[b]));
            }
        }
        if (ans != -0x7fffffff)
            printf("%lld\n", ans);
        else
            printf("NO\n");
    }
    return 0;
}