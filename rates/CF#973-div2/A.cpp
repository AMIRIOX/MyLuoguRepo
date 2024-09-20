#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0, x = 0, y = 0;
    cin >> n >> x >> y;
    int ard = 0;
    if(x <= y) {
        //cout << n / x + ceil((n % x + y % x) * 1.0 / x) << endl;
        cout << ceil(n * 1.0 / x) << endl;
    }else cout << ceil(n * 1.0 / y) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
