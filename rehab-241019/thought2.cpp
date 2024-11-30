#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    if(k <= 4 * n - 4) cout << (k + 1) / 2 << endl;
    else if(k == 4 * n - 3) cout << 2 * n - 1 << endl;
    else cout << 2 * n << endl;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
