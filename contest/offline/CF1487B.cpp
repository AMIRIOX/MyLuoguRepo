#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
signed main() {
    int t;
    scanf("%lld", &t);
    while (t--) {
        int n, k;
        scanf("%lld %lld", &n, &k);
        if (n & 1) {
            // 周期 T=(n-1)/2
            // 频率 (n-1)/2+1=(n+1)/2
            // 主体 k/T * (n+1)/2
            // 剩余 k%T
            k--;
            int T = (n - 1) / 2;
            printf("%lld\n", (k / T * (T + 1) + k % T) % n + 1);
        } else {
            printf("%lld\n", (k - 1) % n + 1);
        }
    }
    return 0;
}