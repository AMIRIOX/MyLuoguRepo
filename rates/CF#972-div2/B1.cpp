#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, q, t1, t2, d1;
    cin >> n >> m >> q >> t1 >> t2 >> d1;
    if(d1 == t1 || d1 == t2) cout << 0 << endl;
    else if(d1 > min(t1, t2) && d1 < max(t1,t2)) {
        // min(t1, t2)    d1    max(t1, t2)
        int cnt = 0;
        if(t1 > t2) swap(t1, t2);
        cout << (t2 - t1)/2 << endl;
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
