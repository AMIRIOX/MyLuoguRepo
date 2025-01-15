#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    const int n = s.length();
    if(s[n - 1] == 'n' && s[n - 2] == 'a' && s[n - 3] == 's') {
        cout << "Yes" << '\n';
    }else {
        cout << "No" << '\n';
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

