#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    long long tot = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        int t; cin >> t;
        if(t >= k) {
            tot += t;
        }else if(!t) {
            if(tot > 0) ans++, tot--;
        }
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
