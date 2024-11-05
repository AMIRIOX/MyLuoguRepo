#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;
    bool ok = true;
    for(int i = 1; i < n; i++) {
        int y = abs(v[i] - v[i - 1]);
        if(y != 5 && y != 7) {
            ok = false;
            break;
        } 
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
