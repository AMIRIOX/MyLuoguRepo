#include <bits/stdc++.h>
using namespace std;

int cxk(deque<int>& a, deque<int>& b, int n, int& s) {
    for(int i = s; i < n; i++) 
        if(a[i] > b[i]) return s = i;
    return -1;
}

void solve() {
    int n = 0; cin >> n;
    deque<int> a;
    deque<int> b;
    for(int i = 1; i <= n; i++) {
        int tmp = 0; cin >> tmp;
        a.push_back(tmp);
    }
    for(int i = 1; i <= n; i++) {
        int tmp = 0; cin >> tmp;
        b.push_back(tmp);
    }
    int ans = 0, ls = 0;
    while(cxk(a, b, n, ls) != -1) {
        a.push_front(b.front());
        a.pop_back();
        ans++;
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
