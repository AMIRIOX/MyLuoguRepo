#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int q; cin >> q;
    vector<ll> fl;
    ll addend = 0;
    int valid = 0;
    while(q--) {
        short op = 0; cin >> op;
        if(op == 1) {
            fl.push_back(-addend);
        }else if(op == 2) {
            ll T; cin >> T;
            addend += T;
        }else if(op == 3) {
            ll H; cin >> H;
            ll target = H - addend;
            auto start = fl.begin() + valid;
            if(start > fl.end()) start = fl.end();
            int ans = upper_bound(start, fl.end(), target, std::greater()) - start;
            cout << ans << '\n';
            valid += ans;
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

