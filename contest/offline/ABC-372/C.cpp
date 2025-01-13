#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n = 0, q = 0;
    string s;
    cin >> n >> q >> s;
    ll cnt = 0;
    const int len = s.length();
    unordered_map<size_t, char> mp;
    for (int i = 0; i + 2 < len; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
            cnt++;
            mp[i] = 'A';
            mp[i + 1] = 'B';
            mp[i + 2] = 'C';
        }
    }
    while (q--) {
        int kth;
        char c;
        cin >> kth >> c;
        kth--;
        if (s[kth] == c) {
            cout << cnt << '\n';
            continue;
        }
        if (mp[kth] && mp[kth] != c) {
            // 破坏了
            cnt--;
            if (mp[kth] == 'A') {
                mp[kth] = mp[kth + 1] = mp[kth + 2] = 0;
            } else if (mp[kth] == 'B') {
                mp[kth - 1] = mp[kth + 1] = mp[kth] = 0;
            } else if (mp[kth] == 'C') {
                mp[kth] = mp[kth - 1] = mp[kth - 2] = 0;
            }
        }
        int i = kth;
        if (c == 'A' && i + 2 < len && s[i + 1] == 'B' && s[i + 2] == 'C') {
            cnt++;
            mp[i] = 'A';
            mp[i + 1] = 'B';
            mp[i + 2] = 'C';
        } else if (c == 'B' && i - 1 >= 0 && i + 1 < len && s[i - 1] == 'A' && s[i + 1] == 'C') {
            cnt++;
            mp[i - 1] = 'A';
            mp[i] = 'B';
            mp[i + 1] = 'C';
        } else if (c == 'C' && i - 2 >= 0 && s[i - 1] == 'B' && s[i - 2] == 'A') {
            cnt++;
            mp[i - 2] = 'A';
            mp[i - 1] = 'B';
            mp[i] = 'C';
        }
        s[kth] = c;
        cout << cnt << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
