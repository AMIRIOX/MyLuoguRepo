#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e6 + 1;
string x;
int q, n, i;
signed main() {
    cin >> x;
    cin >> q;
    int n = x.length();
    //? COW -> COW WCO -> COWWCO OCOWWC
    while (n < q) {
        i = n;
        while (q > i) i *= 2;
        i /= 2;
        q -= (1 + i);
        if (q == 0) q = i;
    }
    cout << x[q - 1];
    return 0;
}