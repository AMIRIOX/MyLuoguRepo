#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define mii map<int, int>

void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for(const auto i: s) {
        if(i == 'q') cout << 'p';
        else if(i == 'p') cout << 'q';
        else cout << i;
    }
    cout << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
