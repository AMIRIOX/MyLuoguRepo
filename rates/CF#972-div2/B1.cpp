#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, q, t1, t2, d1;
    cin >> n >> m >> q >> t1 >> t2 >> d1;
    if(d1 == t1 || d1 == t2) cout << 0 << endl;
    else if(d1 > min(t1, t2) && d1 < max(t1,t2)) {
        int tmp = (max(t1, t2) - d1) - (d1 - min(t1, t2));
        int tmp2 = (max(t1, t2) - d1) - (d1 - min(t1, t2) + 1);
        if(tmp % 2 == 0) cout << tmp / 2 + (d1 - min(t1, t2)) << endl;
        else cout << tmp2 / 2 + (d1 - min(t1, t2)) << endl;
    }
        /*cout << min(d1 - min(t1, t2), max(t1, t2) - d1) << endl;*/
    else if(d1 < min(t1, t2)) /*if(min(t1, t2) - d1 < d1 - 1) cout << d1 - 1 << endl; else*/ cout << min(t1, t2) - d1 + (d1 - 1) << endl;
    else if(d1 > max(t1, t2)) /*if(d1 - max(t1, t2)*/ cout << d1 - max(t1, t2) + (n - d1) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
