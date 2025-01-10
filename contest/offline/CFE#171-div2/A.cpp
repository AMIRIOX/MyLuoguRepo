#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    x = min(x, y);
    y = min(x, y);

    cout << "0 0 " << x << ' ' << y << "\n0 " << x << ' ' << y << " 0\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
