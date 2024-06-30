// offline

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x = 0, y = 0, k = 0;
    cin >> x >> y >> k;
    while(k && x != 1) {
        int cnt = min(k, y - x % y);
        k -= cnt; x += cnt;
        while(x % y == 0) x /= y;
    }
    k %= (y-1);
    cout << x + k << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
