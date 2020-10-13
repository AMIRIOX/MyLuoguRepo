#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e6 + 1;
int calc(int a, int d, int n) { return (a * n + d * (n * (n - 1) / 2)); }
signed main() {
    int a1, a2, n;

    cin >> a1 >> a2 >> n;
    cout << calc(a1, a2 - a1, n);

    return 0;
}