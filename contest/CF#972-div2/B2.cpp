#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 0x7fffffff;
bool cxk(vector<int>& v, vector<int>::iterator i) {
    return (i >= v.begin() && i < v.end());
}
void solve() {
    int n = 0, m = 0, q = 0;
    cin >> n >> m >> q;
    vector<int> b(m);
    vector<int> a(q);
    for(auto &bi: b) cin >> bi; 
    for(auto &ai: a) cin >> ai;
    sort(b.begin(), b.end());
    
    for(int qi = 0; qi < q; qi++){
        int d1 = a[qi];
        auto iter_t2 = upper_bound(b.begin(), b.end(), d1);
        auto iter_t1 = iter_t2 - 1;

        int t1 = 0, t2= 0;
        bool t1ok = cxk(b, iter_t1), t2ok = cxk(b, iter_t2);
        if(t1ok && t2ok) {
            t2 = *iter_t2;
            t1 = *iter_t1;
        }else if(t1ok && !t2ok){
            // t1  d1  t2(inf)
            t1 = *iter_t1;
            t2 = *iter_t1;
        }else if(!t1ok && t2ok) {
            // t1(-inf) d1  t2 
            t1 = *iter_t2;
            t2 = *iter_t2;
        }

        if(d1 == t1 || d1 == t2) cout << 0 << endl;
        else if(d1 > t1 && d1 < t2) {
            int cnt = 0;
            cout << (t2 - t1)/2 << endl;
        }
        else if(d1 < t1) cout << t1 - d1 + (d1 - 1) << endl;
        else if(d1 > t2) cout << d1 - t2 + (n - d1) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
