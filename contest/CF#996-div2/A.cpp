#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int step = abs(a - b) - 1;
    if(step % 2 == 0) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
