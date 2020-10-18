#include <cstdio>
#include <iostream>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e6 + 1;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        int ans = x;
        int ans2 = x*(x-3)/2;
        cout << ans+ans2;
    }
    return 0;
}