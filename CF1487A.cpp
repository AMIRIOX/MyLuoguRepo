#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        int a[520], minx = 0x7fffffff, ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            minx = min(minx, a[i]);
        }
        for (int i = 1; i <= n; i++) {
            ans += !(a[i] == minx);
        }
        printf("%d\n", ans);
    }
    return 0;
}