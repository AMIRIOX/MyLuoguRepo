#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 0);
    vector<int> cnt(n, 1);
    ll cur = 0;
    while(q--) {
        short op; cin >> op;
        if(op == 1) {
            int P, H; cin >> P >> H; P--, H--;
            cnt[pos[P]]--; cnt[H]++;
            if(cnt[pos[P]] == 1) cur--;
            if(cnt[H] == 2) cur++;
            pos[P] = H;
        }else if(op == 2) {
            cout << cur << '\n';
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

