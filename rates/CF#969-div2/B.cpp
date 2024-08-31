#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n = 0, m = 0;
    cin >> n >> m;
    ll tmp = 0, maxa = 0;
    for(int i = 1; i <= n; i++) {
        cin >> tmp;
        if(tmp > maxa) maxa = tmp;
    }
    for(int i = 1; i <= m; i++) {
        char c = ' '; int l = 0, r = 0;
        cin >> c >> l >> r;
        if(c == '+' && maxa >= l && maxa <= r) 
            maxa++;
        else if(c == '-' && maxa >= l && maxa <= r)
            maxa--;
        cout << maxa << " ";
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 
