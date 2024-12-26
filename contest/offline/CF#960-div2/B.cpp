#include <bits/stdc++.h>
using namespace std;

// 构造一个仅有1,-1的数组a，满足：
// 最短的和最大前缀长度为x
// 最短的和最大后缀长度为n-y+1

void solve() {
    int n = 0, x = 0, y = 0;
    cin >> n >> x >> y;
    // 6, x=5, y=1
    // 1 -1 1 1 1 -1
    // [1  ]y 1*i x[  n]
    vector<int> ans(n + 1);
    int cnti = x - y + 1;
    
    bool flg1 = false;
    if((y - 1) % 2) flg1 = false;
    else flg1 = true;
    for(int i = 1; i < y; ++i) {
        if(flg1) cout << "1 ";
        else cout << "-1 ";
        flg1 = !flg1;
    }
    for(int i = y; i <= x; ++i) {
        cout << "1 ";
    }
    flg1 = false;
    for(int i = x + 1; i <= n; ++i) {
        if(flg1) cout << "1 ";
        else cout << "-1 " ;
        flg1 = !flg1;
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
