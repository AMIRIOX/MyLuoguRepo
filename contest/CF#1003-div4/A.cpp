#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    for(size_t i = 0; i < s.length() - 2; i++) {
        cout << s[i];
    }
    cout << 'i' << '\n' ;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
