#include <bits/stdc++.h>
using namespace std;

inline bool cxk(int k, int l, int r) {
    return (k >= l && k <= r);
}

// 贪心 + 滑动窗口
void solve() {
    int n = 0, l = 0, r = 0;
    cin >> n >> l >> r;
    vector<int> a(n);
    for(auto &i: a) cin >> i;
    int cur = 0, ans = 0, cnt = 0;
    vector<vector<int> > seg(n);
    for(auto ai: a) {
        if(ai < l) seg[cnt].push_back(ai);
        else if(ai > r) cnt++;
        else{
            ans++; cnt++;
        }
    }
    for(auto vi: seg) {
        if(!vi.size()) continue;
        int L = 0, R = 0, tot = 0;
        while(R < vi.size()) {
            while(R < vi.size() && tot + vi[R] <= r) {
                tot += vi[R++];
                if(cxk(tot, l, r)) {
                    ans++;
                    //cout << L << " " << R << " " << tot << endl;
                    L = R; tot = 0;
                    //cout << "to: " << L << " " << R << endl;
                }
            }
            tot -= vi[L++];
        }
        // cout << "---" << endl;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
