#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9+10;
int t, l, r;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> l >> r;
        cout << __lg(r) << endl;
    }
    return 0; 
}
