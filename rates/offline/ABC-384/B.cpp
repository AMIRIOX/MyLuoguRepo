#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, r;
    cin >> n >> r;
    vector<int> d(n + 1), a(n + 1);
    for(int i = 1; i <= n; i++) cin >> d[i] >> a[i];

    for(int i = 1; i <= n; i++) {
        if(d[i] == 1 && r >= 1600 && r <= 2799)
            r += a[i];

        if(d[i] == 2 && r >= 1200 && r <= 2399)
            r += a[i];
    }

    cout << r << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}
