#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    ll zero = 0; ll nonzero = 0;
    for(size_t i = 0; i < s.length(); ++i) {
        if(s[i] == '0') {
            ll cz = 1;
            while(i + 1 < s.length() && s[i + 1] == '0') i++, cz++;
            zero += ceil(cz / 2.0);
        }else nonzero++;
    }
    cout << zero + nonzero << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}
