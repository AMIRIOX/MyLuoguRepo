#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_map<char, int> pos;
void solve() {
    string keyboard;
    cin >> keyboard;
    for(size_t i = 0; i < keyboard.length(); i++) {
        pos[keyboard[i]] = i + 1;
    }
    ll ans = 0;
    int lst = pos['A'];
    for(char c = 'B'; c <= 'Z'; c++) {
        ans += abs(pos[c] - lst);
        lst = pos[c];
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

