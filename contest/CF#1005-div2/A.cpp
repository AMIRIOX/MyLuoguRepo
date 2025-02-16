#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; string s;
    cin >> n >> s;
    bool in1 = false;
    int cnt = 0;
    for(size_t i = 0; i < s.length(); i++) {
        if(s[i] == '0') {
            if(in1) {
                in1 = false;
            }
        }else {
            if(!in1) {
                cnt++;
                in1 = true;
            }
        }
    }
    cnt *= 2;
    cout << (s.back() == '1' ? cnt - 1 : cnt) << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
