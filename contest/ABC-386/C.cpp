#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int k; string s, t;
    cin >> k >> s >> t;
    if(s == t) cout << "Yes\n";
    else {
        if(s.length() == t.length()) {
            ll diff = 0;
            for(size_t i = 0; i < s.length(); ++i) if(s[i] != t[i]) diff++;
            if(diff == 1) cout << "Yes\n";
            else cout << "No\n";
        }else {
            if(abs((int)s.length() - (int)t.length()) != 1) {
                cout << "No\n";
                return;
            }
            if(s.length() > t.length()) swap(s, t);
            // |s| < |t|
            size_t si = 0;
            bool ked = false;
            for(size_t ti = 0; ti < t.length(); ++ti, ++si) {
                if(s[si] != t[ti]) {
                    if(ked) {
                        cout << "No\n";
                        return;
                    }
                    ++ti;
                    ked = true;
                }
            }
            cout << "Yes\n";
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}
