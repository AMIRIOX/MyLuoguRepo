#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    ll cnt = 0;
    for(size_t i = 1; i < s.length(); i++) {
        if(s[i] == '|') {
            cout << cnt << ' ';
            cnt = 0;
        }else {
            cnt++;
        }
    }
    endl(cout);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

