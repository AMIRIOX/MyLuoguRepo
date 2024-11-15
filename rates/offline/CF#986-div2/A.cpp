#include <bits/stdc++.h>
using namespace std;

int movx[200], movy[200];

inline bool eq(int x1, int y1, int x2, int y2) {
    if(x1 == x2 && y1 == y2) return true;
    return false;
}
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s; cin >> s;
    int crx = 0, cry = 0;
    if(eq(crx, cry, a, b)) {
        cout << "YES" << endl;
        return;
    }
    // length == 6
    // 0 1 2 3 4 5
    // 1 2 3 4 5 6
    // 7 8 9 
    int len = s.length();
    //    0 1 
    //    1 2 3 4 5
    //    1 0 1 0 1 0
    for(int i = 1; i <= 200; i++) {
        int opt = (i % len == 0 ? len : i % len);
        crx += movx[s[opt - 1]];
        cry += movy[s[opt - 1]];

        if(eq(crx, cry, a, b)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    movy['N'] = 1; movx['E'] = 1;
    movy['S'] = -1; movx['W'] = -1; 
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
