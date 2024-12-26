#include <bits/stdc++.h>
using namespace std;
int n,m;
void solve() {
    cin >> n >> m;
    if(n < m) cout << "No" << endl;
    else if((n-m)%2==0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
