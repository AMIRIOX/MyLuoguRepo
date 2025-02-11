#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, y;
    cin >> x >> y;
    if(x <= y) {
        cout << (y - x == 1 ? "Yes" : "No") << '\n';
        return;
    }
    cout << ((x - y + 1) % 9 == 0 ? "Yes" : "No") << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
