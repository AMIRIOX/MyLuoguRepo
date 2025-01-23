#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int q = 0; cin >> q;
    deque<pair<ll, ll>> sn;
    ll lstx = 0, lstl = 0;
    ll addend = 0;
    while(q--) {
        short op; cin >> op;
        if(op == 1) {
            ll l = 0; cin >> l;
            sn.push_back(pair<ll, ll>(lstx + lstl, l));
            lstx = lstx + lstl;
            lstl = l;
        }else if(op == 2) {
            addend += sn.front().second;
            sn.pop_front();
        }else if(op == 3) {
            int k = 0; cin >> k;
            cout << sn[k - 1].first - addend << '\n';
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

