#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    ll cnt = 0, ccnt = 0;
    for(size_t i = 0; i < s.length(); i++) {
        if(s[i] == 'O') {
            ccnt++;
        }else if(s[i] == 'X') {
            if(ccnt >= k) cnt += ccnt / k;
            ccnt = 0;
        }
    }
    if(ccnt >= k) cnt += ccnt / k;
    cout << cnt << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

