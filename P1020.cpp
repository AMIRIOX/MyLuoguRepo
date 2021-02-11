#include <algorithm>
#include <cstdio>
#include <iostream>
// #define int long long
// #define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e6 + 1;
int a[maxn], n, t1, t2;
int f1[maxn], f2[maxn];
signed main() {
    while (cin >> a[++n])
        ;
    n--;
    for (int i = 1; i <= n; i++) {
        if (t1 == 0 || a[i] <= f1[t1]) {
            f1[++t1] = a[i];
        } else {
            // int l = 1, r = t1 + 1;
            // while (l < r) {
            //     int mid = l + (r - l) / 2;
            //     if (f1[mid] > a[i])
            //         l = mid + 1;
            //     else
            //         r = mid;
            // }
            // f1[l] = a[i];
            int* pos = upper_bound(f1 + 1, f1 + t1 + 1, a[i], greater<int>());
            *pos = a[i];
        }
    }
    printf("%d\n", t1);

    for (int i = 1; i <= n; i++) {
        if (t2 == 0 || a[i] > f2[t2]) {
            f2[++t2] = a[i];
        } else {
            int* pos = lower_bound(f2 + 1, f2 + t2 + 1, a[i]);
            *pos = a[i];
        }
    }
    printf("%d\n", t2);
    return 0;
}
