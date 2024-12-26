#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0; string s;
    cin >> n >> s;
    int c0 = 0, c1 = 0;
    vector<int> v(n);
    if(s[0] == '0') c0++;
    if(s[s.length() - 1] == '0') c0++;
    int indl = 0, indr = s.length() - 1;
    while(indl < s.length() && s[indl] == '0') indl++;
    while(indr >= 0 && s[indr] == '0') indr--;
    int last = 1;
    for(int i = indl; i <= indr; i++) {
        if(s[i] == '0' && last != '0') c1--; 
        if(s[i] == '1') c1++;
        last = s[i];
    }
    if(c1 > c0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
