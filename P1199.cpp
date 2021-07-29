#include <algorithm>
#include <cstdio>
#include <iostream>
int n, a[12200][12200];
int ans;
signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            a[j][i] = a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        std::sort(a[i] + 1, a[i] + n + 1);
        ans = std::max(ans, a[i][n - 1]);
    }
    printf("1\n%d\n", ans);
    return 0;
}