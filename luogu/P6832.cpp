#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
string x;
int a[50], ans = 0;
signed main() {
    cin >> x;
    for (int i = 0; i < x.length(); i++) {
        a[x[i] - 96]++;
    }
    for (int i = 1; i <= 26; i++) {
        if (a[i] > ans) ans = a[i];
    }
    cout << ans;
    return 0;
}