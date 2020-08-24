#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 100010;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
signed main() {
    int x, y, ans = 0;
    cin >> x >> y;
    for (int k = 1; k * k <= y; k++) {
        // PQ=xy, (y/k)Q=xy, Q=xy/(y/k)=xyk/y=xk
        if (y % k == 0) {
            if (gcd(k, y / k * x) == x) ans++;
            if (y / k != k && gcd(y / k, x * k) == x) ans++;
        }
    }
    cout << ans;
    return 0;
}