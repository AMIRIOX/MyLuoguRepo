#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n = 0, x = 0, y = 0;
    cin >> n >> x >> y;
    cout << (int)ceil(n * 1.0 / min(x, y)) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
