
/*
#include <bis/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

void solve() {
    // [l,r] 中有多少互质的三个数
    int l = 0, r = 0;
    cin >> l >> r;
    int ans = 0;
    for(int i = l; i <= r; i++) {
// 10 11 12 13 14 15 16 17 18 19 20 21
// 10                         19    21
//    11                         20

//
// 10 11    13
//       12       15    17 
//             14             19    21
//
//                   16                   23    25

// 10                   17          21
//    11                      19 20
//       12          16    18
//          13 14 15
//
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
}

*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l = 0, r = 0;
    cin >> l >> r;
    cout << ((((r + 1) >> 1) - ((l - 1 + 1) >> 1)) >> 1) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
