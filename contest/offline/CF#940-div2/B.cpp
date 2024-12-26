// !unaccepted 
// Load your brain ans solve the problem
/*
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0, k = 0;
    cin >> n >> k;
    
    vector<int> bit;
    int bits = 0;
    for(int b = 31; b >= 0; b--) {
        if(k & (1ll << b)) {
            bit.push_back(b);
            bits++;
//            cout << "L" << b << "R" << endl;
        }
    }
//    cout << "----------" << endl;
    if(bits <= n) {
        for(int i = 0; i < bits; i++) {
            cout << (1 << bit[i]) << " ";
        }
//        cout << ":" << n - bits << "; " << endl;
        for(int i = 1; i <= (n - bits); i++) {
            cout << "0 ";
        }
    }else {
        // bits - n
        for(int i = 0; i < n - 1; i++) {
            cout << (1 << bit[i]) << " ";
        }
        int rm = 0;
        for(int i = n - 1; i < bits; i++) {
            rm |= (1 << bit[i]);
//            cout << "( " << bit[i] << " )" << endl;
        }
        cout << rm;
    }
    cout << endl;
//    cout << "---------" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0, k = 0, x = 0;
    cin >> n >> k;
    if(n == 1) {
        cout << k << endl;
        return;
    }
    for(int b = 31; b >= 0; b--) {
        if(k & (1 << b)) {
            x = b;
            break;
        }
    }
    cout << ((1 << x) - 1) << " " << k - ((1 << x) -1) << " ";
    for(int i = 3; i <= n; i++) {
        cout << "0 ";
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
