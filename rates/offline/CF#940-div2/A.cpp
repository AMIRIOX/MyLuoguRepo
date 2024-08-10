#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> cnt(120);
    vector<int> a(n);
    for(int i = 1; i <= n; i++) {
        int tmp = 0; cin >> tmp;
        if(!cnt[tmp]) a.push_back(tmp);
        cnt[tmp]++;
    }

    int ans = 0;
    for(auto i: a) {
        ans += cnt[i]/3;
    }
    
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
