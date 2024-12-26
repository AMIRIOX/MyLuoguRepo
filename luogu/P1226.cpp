#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e6 + 1;
int mod, p, k;
int quickPower(int a, int n) {
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return quickPower(a, n - 1) * a % mod;
    else {
        int tmp = quickPower(a, n / 2);
        return tmp * tmp % mod;
    }
}
int quickpower2(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
signed main() {
    cin >> p >> k >> mod;
    int ans = quickpower2(p, k);
    printf("%lld^%lld mod %d=%d", p, k, mod, ans % mod);
    return 0;
}