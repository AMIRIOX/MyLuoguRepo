#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    map<int, int> cnt;
    ll sum = 0;
    for (auto c : s) {
        cnt[c - '0']++;
        sum += c - '0';
    }
    ll yc = sum % 9;
#define TWO cnt[2]
#define SIX cnt[3]
    // 给定若干个2, 若干个6
    // 问能否拼成 9 - y, 18 - y ,..., 9*i - y
    // 45 % 9 = 0
    if(!yc) {
        cout << "YES" << endl;
        return;
    }
    for(int i = 1; i <= 9; i++) {
        ll tgt = 9 * i - yc;
        for(int cnt2 = 0; cnt2 <= TWO; cnt2++) {
            ll dt = tgt - 2 * cnt2;
            if(dt % 6 == 0 && dt / 6 <= SIX) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    /*
    auto check = [&cnt](int y) {
        if (!y)
            return true;
        else if (y == 1) {
            if ((cnt[2] >= 1 && cnt[3] >= 1) || cnt[2] >= 4)
                return true;
        } else if (y == 3) {
            if ((cnt[3] >= 1) || (cnt[2] >= 3))
                return true;
        } else if (y == 5 && cnt[2] >= 2)
            return true;
        else if (y == 7 && cnt[2] >= 1)
            return true;

        return false;
    };
    if(check(yc) || 1) {

    }
    */
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
