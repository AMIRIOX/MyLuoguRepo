#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    long long tot = 0, mx = -2e18;
    for(int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        tot++;
        cnt[tmp]++;
        mx = max(mx, cnt[tmp]);
    }
    cout << tot - mx << endl;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
