#include <bits/stdc++.h>
using namespace std;

void updates(int& ans, int nevv){
    ans = nevv > ans ? nevv : ans;
}

int calc(vector<pair<int, int> >& v, int pre_lcm) {
    int rlcm = 0, c = 0;
    for(auto [a, t]: v) {
        if(pre_lcm % a == 0) {
            if(!rlcm) rlcm = a;
            else rlcm = lcm(rlcm, a);
            c += t;
        }
    }
    if(rlcm != pre_lcm) return 0;
    return c;
}



void solve() {
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;
    long long LCM = 1;
    map<int, int> mp;  // key, val
    int mx = *max_element(v.begin(), v.end());
    for(auto a: v) {
        // mp[a]++;
        LCM = lcm(LCM, a);
        if(LCM > mx) {
            cout << n << endl;
            return;
        }
    }
    for(auto a: v) mp[a]++;
    vector<pair<int, int> > mpv;
    for(auto i: mp) {
        mpv.push_back(i);
    }
    int ans = 0;
    
    for(int i = 1; i * i <= mx; i++) {
        if(mx % i == 0) {
            if(!mp.contains(i)) 
                updates(ans, calc(mpv, i));
            if(!mp.contains(mx / i)) 
                updates(ans, calc(mpv, mx / i));
        }
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
