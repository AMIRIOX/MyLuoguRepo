// 去你妈的, 去你妈的, 去你妈的!

// !unaccpected WA on #2
/*
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    int single = 0, twice = 0, color = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        if (!cnt[tmp])
            color++;
        cnt[tmp]++;
    }
    for (const auto &i : cnt)
        if (i.second == 1)
            single++;
        else if (i.second == 2)
            twice++;
    // A B A B
    int st1 = ceil(single / 2.0);
    int alice = ceil(n / 2.0) - st1;
    int ans = st1 * 2, remc = color - single;
    if (single % 2 == 0) {
        // A B A B
        ans += ceil(remc / 2.0);
        alice -= ceil(remc / 2.0);
        if (remc % 2 == 0) {
            // A B A B A B
            ans += min((int)ceil(twice / 2.0), alice);
        } else {
            ans += min(twice / 2, alice);
        }
    } else {
        // A B A B A
        ans += remc / 2;
        alice -= remc / 2;
        if (remc % 2 == 0) {
            ans += min(twice / 2, alice);
        } else {
            ans += min((int)ceil(twice / 2.0), alice);
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int single = 0, tot = 0;
    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        if(!cnt[tmp]) single++, tot++;
        else if(cnt[tmp] == 1) single--;
        cnt[tmp]++;
    }
    int st1 = ceil(single / 2.0);
    cout << st1 * 2 + (tot - single) << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
