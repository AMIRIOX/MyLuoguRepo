#include <cmath>
#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
signed main() {
    int t;
    scanf("%lld", &t);
    while (t--) {
        int n;
        scanf("%lld", &n);
        printf("%lld\n", (long long)(sqrt(2 * n - 1) - 1) / 2);
    }
    return 0;
}