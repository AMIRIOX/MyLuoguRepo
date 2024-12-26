#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 3e5 + 10;
long long a[maxn];

struct segment{
    int l;
    int r;
    bool operator<(const segment& b) {
        if(this->r == b.r) return this->l < b.l;
        return this->r < b.r;
    }
}seg[maxn];
void solve() {
    memset(seg, 0, sizeof seg);
    memset(a, 0, sizeof a);
    int n = 0, idx = 0;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(!a[i]) {
            seg[++idx].l = i;
            seg[idx].r = i;
        }
        a[i] += a[i - 1];
    }

    map<long long, int> mp;
    for(int i = 0; i <= n; i++) {
        if(mp.contains(a[i])) {
            // [ mp[a[i]] + 1, i] 
            seg[++idx].l = mp[a[i]] + 1;
            seg[idx].r = i;
        }
        mp[a[i]] = i;
    }

    if(!idx) {
        cout << "0" << endl;
        return;
    }

    sort(seg + 1, seg + idx + 1);
    int lst = seg[1].r, cur = 2;
    long long ans = 1;
    while(cur <= idx) {
        if(seg[cur].l > lst) {
            ans++;
            lst = seg[cur].r;
        }
        cur++;
    }
    cout << ans << endl;
}

signed main() {
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
