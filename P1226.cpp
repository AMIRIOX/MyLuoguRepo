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
signed main() {
    cin >> p >> k >> mod;
    int ans = quickPower(p, k);
    printf("%lld^%lld mod %d=%d", p, k, mod, ans%mod);
    return 0;
}