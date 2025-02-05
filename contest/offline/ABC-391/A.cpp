#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    for(size_t i = 0; i < s.length(); i++) {
        if(s[i] == 'N') cout << 'S';
        else if(s[i] == 'S') cout << 'N';
        else if(s[i] == 'E') cout << 'W';
        else cout << 'E';
    }
    cout << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

