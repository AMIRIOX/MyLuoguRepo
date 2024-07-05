// sort or binary search

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n = 0; ll k = 0;
    cin >> n >> k;
    vector<ll> a(n);
    // a[i] 张 i
    for(auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll lst = a.back(); int cnt = 0;
    while(!a.empty() && a.back() == lst) {
        a.pop_back();
        cnt++; 
    }
    ll dt = 0;
    while(!a.empty() && k) {
        dt = a.back() - lst;
        if(k < dt * cnt) break;
        k -= dt * cnt;
        lst = a.back();
        while(!a.empty() && a.back() == lst) {
            a.pop_back();
            cnt++;
        }
    }
    // w+(n-1)(w-1)+m, m = n - cnt + k/delta
    // ll sum = cnt - k / cnt; 
    /*
    cout << "/" << lst << " " << k << " " << cnt << " " << dt << endl;
    ll w = lst, m = n - cnt;
    if(dt) m += k / dt;
    cout << ":" << n << "*" << lst << "-" << n << "+1+" << m << endl;
    cout << n * w - n + 1 + m << endl;
    */
    lst += k/cnt;
    k %= cnt;
    cout << lst * n + 1 - (cnt - k) << endl; 
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
