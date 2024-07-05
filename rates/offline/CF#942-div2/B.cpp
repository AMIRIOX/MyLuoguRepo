#include <bits/stdc++.h>
using namespace std;
#define coin cin

void solve() {
    int n = 0, U = 0;
    coin >> n;
    string s; coin >> s;
    for(auto c: s) {
        if(c=='U') U++;
    }
    if(U % 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; coin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
