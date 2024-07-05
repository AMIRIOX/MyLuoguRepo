#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0; cin >> n; 
    bool rflag = false;
    vector<int> p(n+1);
    int placen = 0;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        if(p[i] == n) 
            placen = i;
    }
    if(placen % 2 == 0) {
        rflag = true;
        reverse(p.begin() + 1, p.end());
        placen = n - placen + 1;  // n=6, pn=2, rpn=5
    }
    
    /*
    for(int i = 1; i <= n; i++)
        cout << p[i] << ", ";
    cout << endl; 
    */

    vector<pair<int, int> > even;
    vector<pair<int, int> > odd;
    // value, key
    
    for(int i = 1; i <= n; i++) {
        if(i % 2) { /*odd*/
            odd.push_back(pair<int, int>(p[i], i));
        }else {   /*even*/
            even.push_back(pair<int, int>(p[i], i));
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    
    /*
    cout << "odd: " << endl;
    for(auto oi: odd) 
        cout << oi.second << "," << oi.first << " ";
    cout << endl;
    cout << "even: " << endl;
    for(auto ei: even)
        cout << ei.second << "," << ei.first << " ";
    cout << endl;
    */

    vector<int> ans(n+1);
    int filln = n;
    for(int i = 0; i < odd.size(); i++) {
        // cout << "fill " << odd[i].second << " with " << filln << endl;
        ans[odd[i].second] = filln--;  
    }
    for(int i = 0; i < even.size(); i++) {
        // cout << "fill " << even[i].second << " with " << filln << endl;
        ans[even[i].second] = filln--;
    }
    if(rflag) 
        for(int i = n; i >= 1; i--) {
            cout << ans[i] << " ";
        }
    else for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
