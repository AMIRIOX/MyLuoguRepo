#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    char lst = s[0];
    cout << lst;
    bool ok = false;
    for(size_t i = 1; i < s.size(); ++i) {
        if(s[i] == lst && !ok) {
            cout << (s[i] == 'a' ? 'b' : 'a');
            ok = true;
        }
        cout << s[i];
        lst = s[i];
    }
    if(!ok) {
        cout << (lst == 'a' ? 'b' : 'a');
    }
    cout << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
