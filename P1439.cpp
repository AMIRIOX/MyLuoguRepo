#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn];
int maps[maxn], f[maxn];
int t = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        maps[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = maps[b[i]];
    }
    // 求b数组的LIS
    for (int i = 1; i <= n; i++) {
        if (t==0 || b[i] >= f[t]) {
            f[++t] = b[i];
        } else {
            int* pos = lower_bound(f + 1, f + t + 1, b[i]);
            *pos = b[i];
        }
    }
    printf("%d\n", t);
    return 0;
}