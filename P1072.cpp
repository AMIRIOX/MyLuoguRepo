#include <cstdio>
#include <iostream>
#define re register
using namespace std;
const int maxn = 100010;
int T, a0, a1, b0, b1, ans;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
int main() {
    cin >> T;
    while (T--) {
        cin >> a0 >> a1 >> b0 >> b1;
        for (int i = 1; i <= b1 / i; i++) {
            if (b1 % i == 0) {
                if (gcd(i, a0) == a1 && lcm(i, b0) == b1) ans++;
                if (b1 / i != i) {
                    if (gcd(b1 / i, a0) == a1 && lcm(b1 / i, b0) == b1) ans++;
                }
            }
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
