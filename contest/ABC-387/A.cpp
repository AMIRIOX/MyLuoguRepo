#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b;
    cin >> a >> b;
    a += b;
    cout << a * a << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}
