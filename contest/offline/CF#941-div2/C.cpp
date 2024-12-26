#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for(auto &a: v) {
        cin >> a; 
    }
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int a = v[v.size()-1];
    int b = 1;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == b) b++;
        else break;
    }
    if(b > a) {
        if(a % 2) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }else if(b < a) {
        if(b % 2) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
