#include <cstdio>
#include <iostream>
using namespace std;
int a[12200];
signed main() {
    int n, c = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c += a[i];
    }
    c /= n;
    for (int i = 1; i <= n; i++)
        a[i] -= c;
    for (int i = 1; i < n; i++)
        if (a[i]) {
            a[i + 1] += a[i];
            ans++;
        }
    printf("%d\n", ans);
    return 0;
}