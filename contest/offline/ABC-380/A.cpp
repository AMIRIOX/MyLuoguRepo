#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(const auto &i : s) {
        if(i == '1') cnt1++;
        if(i == '2') cnt2++;
        if(i == '3') cnt3++;
    }
    if(cnt1 == 1 && cnt2 == 2 && cnt3 == 3) {
        cout << "Yes" << '\n';
    }else cout << "No" << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

