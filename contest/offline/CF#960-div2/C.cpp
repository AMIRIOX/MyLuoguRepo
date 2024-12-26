//!unaccpeted 性质观察不够仔细，多模拟几遍吧

/*
#include <bits/stdc++.h>
using namespace std;

int cnt[(int)2e5+10];

bool zro(vector<int>& a) {
    for(auto i: a) {
        if(i != 0) return false;
    }
    return true;
}

void solve() {
    // 注意MAD定义：1.重复的 2.最大的
    // 因此能观察到不降性质
    // 从b1开始从前往后，维护cnt[ai]，和MADi
    // 更新MADi, 直接ai=MADi
    
    int n = 0, ans = 0, MAD = 0;
    cin >> n;
    vector<int> a(n);
    for(auto &i: a) {
        cin >> i;
        ans += i;
    }

    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if(cnt[a[i]] > 1) MAD = max(MAD, a[i]);
        a[i] = MAD; ans += a[i];
    }

    while(!zro(a)) {
        MAD = 0;
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < n; i++) {
            cnt[a[i]]++;
            if(cnt[a[i]] > 1) MAD = a[i];
            a[i] = MAD; ans += a[i];
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
*/
