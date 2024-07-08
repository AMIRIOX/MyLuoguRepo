#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0, k = 0;
    cin >> n >> k;
    map<int, int> c;
    int ans = n;
    for(int i = 1; i <= n; i++) {
        int tmp = 0; cin >> tmp;
        c[tmp]++; 
        if(c[tmp] >= k) ans = k - 1;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
