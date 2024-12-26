// binary answer
#include <bits/stdc++.h>
using namespace std;
int n, tot;

/*
bool cxk(int k, vector<int>& v) {
    int ans = 0;
    for(int i = 0; i <= v.size() - k; i++) {
        int tmp = 0;
        for(int j = 0; j < k; j++) {
            tmp |= v[i+j];
        }
        if(!i) ans = tmp;
        else if(tmp != ans) return false;
    }
    return true;
}*/

bool cxk(int k, vector<int>& v) {
    int totc = 0;
    vector<int> t(31);
    for(int i = 0; i < k; i++) {
        int tmp = v[i];
        for(int b = 30; b >= 0; b--) {
            if(tmp >= (1<<b)) {
                tmp -= (1<<b);
                t[b]++;
            }
        }
    }
    for(int b = 30; b>=0; b--) {
        if(t[b]) totc += (1<<b);
    }
    if(totc != tot) return false;
    for(int i = 1; i <= n - k; i++) {
        // remove i-1, add i+k-1
        int tmp = v[i-1];
        for(int b = 30; b >= 0; b--) {
            if(tmp >= (1<<b)) {
                tmp -= (1<<b);
                t[b]--;
                if(!t[b]) totc -= (1<<b);
            }
        } 
        tmp = v[i + k - 1];
        for(int b = 30; b >= 0; b--) {
            if(tmp >= (1<<b)) {
                tmp -= (1<<b);
                t[b]++;
                if(t[b] == 1) totc += (1<<b); 
            }
        }
        if(totc != tot) return false;
    }
    return true;
}

void solve() {
    cin >> n;   tot = 0;
    vector<int> a(n); 
    for(auto &i: a) { cin >> i; tot |= i; }
    int l = 1, r = n + 1;
    while(l < r) {
        int mid = l + ((r - l)>>1);
        if(cxk(mid, a)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
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
