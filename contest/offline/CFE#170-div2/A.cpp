#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s, t;
    cin >> s >> t;
    ll prefix = 0;
    if(s.length() > t.length()) swap(s, t);
    for(size_t i = 0; i < s.length(); i++) {
        if(s[i] == t[i]) {
            prefix++;
        }else break;
    }

    cout << s.length() + t.length() - prefix + (prefix != 0)<< endl;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
