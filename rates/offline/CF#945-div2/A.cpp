// win 2; lose 0; draw 1;
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x = 0, y = 0, z = 0, ans= 0;
    cin >> x >> y >> z;
    priority_queue<int> q;
    if(x) q.push(x); if(y) q.push(y); if(z) q.push(z);
    while(q.size() >= 2) {
        int fst = q.top(); q.pop();
        int sec = q.top(); q.pop();
        fst--; sec--; ans++;
        if(fst) q.push(fst);
        if(sec) q.push(sec);
    }
    if(!q.empty() && q.top()%2) ans = -1;
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
