#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 100;
int t, n;
signed main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        int a[maxn];
        a[0] = -1;
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        bool ok = true;
        for (int i = 1; i < n; i++) {
            int q = a[i] - a[i - 1] - 1;
            if (a[i] - q >= a[i + 1] + q) {
                ok = false;
                printf("NO\n");
                break;
            }
            a[i] -= q;
            a[i + 1] += q;
        }
        if (ok) {
            printf("YES\n");
        }
    }
    return 0;
}