#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n = 0; cin >> n;
    // contruct the longest sequence 
    // ai < n; ai-1 < ai; ai-1 | a = n
    vector<int> bit(64);
    int h = -1, l = -1, ans = 0;

    for(ll b = 60; b >= 0; b--) {
        if(n & (1LL << b)) {
            if(h == -1) h = b;
            bit[b] = 1;
            l = b;
            ans++;
        } else bit[b] = 0;
    }

    if(ans == 1) {
        cout << 1 << endl << n << endl;
        return;
    }

    cout << ans + 1 << endl;
    for(int b = h; b >= l; b--) {
        if(bit[b]) {
            ll tmp = 0;
            for(int j = l; j <= h; j++) {
                if(bit[j] && j != b) tmp |= (1LL << j);
            }
            cout << tmp << " ";
        }
    }
    cout << n << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
