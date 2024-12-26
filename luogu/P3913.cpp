#include <algorithm>
#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e6 + 10;
int x[maxn], y[maxn];
signed main() {
    int n, k;
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    sort(x + 1, x + k + 1);
    sort(y + 1, y + k + 1);
    int xs = unique(x + 1, x + k + 1) - x - 1;
    int ys = unique(y + 1, y + k + 1) - y - 1;
    printf("%lld\n", xs * n + ys * n - xs * ys);
    return 0;
}