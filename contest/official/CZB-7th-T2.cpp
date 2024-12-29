#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    // q >= 2e5 -> ans[q] = 0
    vector<ll> ans(2e5 + 1, 0);
    // 第 i 天 打掉 mp[i] 个果子
    int n, q;
    cin >> n >> q;
    vector<int> a;
    map<int, int> cnt, mp;

    int maxc = 0;
    for (int i = 0, tmp = 0; i < n; i++) {
        cin >> tmp;
        if (!cnt[tmp])
            a.push_back(tmp);
        mp[cnt[tmp]] -= cnt[tmp];
        cnt[tmp]++;
        mp[cnt[tmp]] += cnt[tmp];

        if(cnt[tmp] > maxc) maxc = cnt[tmp];
    }

    for(int i = 1; i <= maxc; i++) {
        ans[i] = ans[i - 1] + mp[i];
    }

    for(int i = 0, qi = 0; i < q; i++) {
        cin >> qi;
        if(qi >= maxc) cout << 0 << ' ';
        else cout << n - ans[qi] << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
}
