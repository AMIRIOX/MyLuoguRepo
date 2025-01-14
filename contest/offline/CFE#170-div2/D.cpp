


// !unaccepted wrong thought
// 既不能二分也不能直接贪心。

#ifdef WRONG_THOUGHT
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    // vector<int> attr(n + 1, 0);
    vector<int> points(n + 1, 0);
    vector<int> raw(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        // attr[i] = attr[i - 1];
        points[i] = points[i - 1];
        cin >> raw[i];
        // if(!raw[i]) attr[i]++; else
        points[i] += (raw[i] == 0);
    }
    ll at = 0, ans = 0;
    ll tki = 0, tkp = 0;
    for (int i = 1; i <= n; i++) {
        // for each ri > 0, takes attr
        // for each ri < 0, takes attr
        at += (raw[i] == 0);
        if (raw[i] > 0) {
            if (at >= abs(raw[i]) - tki) {
                ans++;
                cout << i << " has been passed" << endl;
                at -= abs(raw[i]) - tki;
            }
            tki = max(tki, (ll)raw[i]);
        } else if (raw[i] < 0) {
            if (at >= abs(raw[i]) - tkp) {
                ans++;
                cout << i << " has been passed" << endl;
                at -= abs(raw[i]) - tkp;
            }
            tkp = max(tkp, (ll)abs(raw[i]));
        }
        cout << "info: " << at << ' ' << tki << ' ' << tkp << endl;
    }
    cout << ans << '\n';
    /*
    auto check = [&](const int kth) -> bool {
        ll at = 0;
        ll tki = 0, tkp = 0;
        for (int i = 1; i <= kth; i++) {
            // for each ri > 0, takes attr
            // for each ri < 0, takes attr
            at += (raw[i] == 0);
            if (raw[i] > 0) {
                at -= abs(raw[i]) - tki;
                tki += raw[i];
            } else if (raw[i] < 0) {
                at -= abs(raw[i]) - tkp;
                tkp += -raw[i];
            }
            if (at < 0)
                return false;
        }
        return true;
    };

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    if (check(l))
        cout << points[l] << '\n';
    else
        cout << 0 << '\n';
    for (int i = 1; i <= n; i++) {
        cout << check(i) << ' ';
    }
    */
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
#endif
