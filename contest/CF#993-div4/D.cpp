#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define mii map<int, int>

void solve() {
    int n; cin >> n;
    vector<ll> ans(n + 1);
    map<ll, ll> cnt, cnt2;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i], cnt2[a[i]]++;

    vector<ll> placed;
    for(int i = 1; i <= n; i++) if(!cnt2[i]) placed.push_back(i);
    auto p = placed.size();
    for(int i = 1; i <= n; i++) {
        if(cnt[a[i]]) ans[i] = placed[--p];
        else ans[i] = a[i];
        cnt[a[i]]++;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
