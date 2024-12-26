#include <algorithm>
#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
int T, n;
const int maxn = 1010;
signed main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n);
        int x[maxn], y[maxn];
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", &x[i], &y[i]);
        }
        if (n & 1)
            printf("1\n");
        else {
            sort(x + 1, x + n + 1);
            sort(y + 1, y + n + 1);
            int chx = x[n / 2 + 1] - x[n / 2] + 1;
            int chy = y[n / 2 + 1] - y[n / 2] + 1;
            printf("%lld\n", chx * chy);
        }
    }
    return 0;
}