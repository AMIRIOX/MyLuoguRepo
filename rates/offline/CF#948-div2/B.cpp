#include <bits/stdc++.h>
using namespace std;
const int maxn = 33;
typedef long long ll;
void solve(){
    vector<int> a(maxn);
    long long x = 0; cin >> x;
    for(int i = 0; i < 31; i++) {
        if(x & (1<<i)) a[i] = 1;
    }
    // 从0 到30位遍历，考虑对每个连续的 1 子序列
    // 0 1 1 1 0 变为 0 -1 0 0 1，然后继续从最后一个1遍历
    int l = -1, last = -1;
    for(int i = 0; i < 31; i++) {
        if(a[i] == 1 && l == -1) l = i;
        else if(a[i] != 1 && i - l <= 1) l = -1;
        else if(a[i] != 1 && l != -1 && i - l > 1) {
            a[i] = 1; a[l] = -1;
            for(int j = i-1; j > l; --j) a[j] = 0;
            l = i;
        }
        if(a[i]==1) last = i;
    }
    cout << last+1 << endl;
    for(int i = 0; i <= last; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 0; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
