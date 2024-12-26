#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    if (!k) {
        if(!a && !b) {
            cout << "" << '\n';
            return;
        }
        if(a && b) {
            cout << "-1" << '\n';
            return;
        }
    } else if (/*a >= 1 && b >= 1 && !k*/ a + b - 1 < k) {
        cout << -1 << '\n';
        return;
    }
    int flg[2] = {a, b};
    string ans;

    auto test = [&](int bit) {
        for (int i = 1; i <= k; i++) {
            if (flg[1 - bit] <= 0) {
                return -1;
            }
            ans += (bit = 1 - bit) + '0';
            flg[bit]--;
        }
        if (flg[bit] && !flg[1 - bit])
            return -1;
        return bit;
    };

    int bit = 0;
    if ((bit = test(1)) != -1) {
        while (flg[bit] > 0) {
            ans += bit + '0';
            flg[bit]--;
        }
        while (flg[1 - bit] > 0) {
            ans += 1 - bit + '0';
            flg[1 - bit]--;
        }
        cout << ans << '\n';
        return;
    }

    flg[0] = a;
    flg[1] = b;
    ans = "";
    if ((bit = test(0)) != -1) {
        while (flg[bit] > 0) {
            ans += bit + '0';
            flg[bit]--;
        }
        while (flg[1 - bit] > 0) {
            ans += 1 - bit + '0';
            flg[1 - bit]--;
        }
        cout << ans << '\n';
        return;
    }
    cout << -1 << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
