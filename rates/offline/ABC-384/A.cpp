#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; char c1, c2;
    string s;
    cin >> n >> c1 >> c2 >> s;
    for_each(s.begin(), s.end(), [&](char &c) { if(c != c1) c = c2; });
    cout << s << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}
