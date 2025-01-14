#include <bits/stdc++.h>
using namespace std;

struct lazysum {
    vector<int> diff;
    lazysum(int _n) : diff(_n, 0) {}

    void add(int l, int r) {
        if(l > r) return;
        diff[l]++;
        diff[r + 1]--;
    }

    void push(vector<int> &d) {
        int sum = 0;
        for (size_t i = 0; i < diff.size(); i++) {
            sum += diff[i];
            diff[i] = 0;
            if(i < d.size()) d[i] += sum;
        }
    }
};

void solve() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> raw(n + 1, 0);
    vector<int> S(n + 1, 0);
    vector<int> dp(m + 1, 0);
    dp[0] = 0;
    // dp[i], 0 <= i <= m
    for (int i = 1; i <= n; i++) {
        cin >> raw[i];
        S[i] = S[i - 1] + (raw[i] == 0);
    }
    lazysum ls(m + 2);
    for (int i = 1; i <= n; i++) {
        if (!raw[i]) {
            ls.push(dp);
            for (int I = S[i]; I >= 1; I--) {
                // the same reason as the 01 backpack
                dp[I] = max(dp[I - 1], dp[I]);
            }
        }

        if (raw[i] > 0) {
            // [d[raw[i]] ~ d.end()] += 1
            ls.add(raw[i], S[i]); 
            // if replace `s[i]` with `m`, dp should be initialized by -inf
            /*
            if (i >= raw[i])
                dp[i] = dp[i] + 1;
            */
        }
        if (raw[i] < 0) {
            // [d.begin() ~ d[s[i] - abs(raw[i])]] += 1
            ls.add(0, S[i] - abs(raw[i]));
            /*
            if (s[i] - i >= abs(raw[i]))
                dp[i] = dp[i] + 1;
            */
        }
        //}
    }
    ls.push(dp);
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

// !unaccepted wrong thought
// 既不能二分也不能直接贪心。

#ifdef wrong_thought
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
