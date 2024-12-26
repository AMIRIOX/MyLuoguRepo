#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if(n < 5) cout << -1 << endl;
    else {
        for(int i = 2; i <= n; i += 2) {
            if(i != 4) cout << i << " ";
        }
        cout << 4 << " "  << 5 << " ";
        for(int i = 1; i <= n; i += 2) {
            if(i != 5) cout << i << " ";
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
