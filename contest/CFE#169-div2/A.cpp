#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> p(n);
    for(auto &ai: p) cin >> ai;
    if(n == 2 && abs(p[0] - p[1]) > 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
