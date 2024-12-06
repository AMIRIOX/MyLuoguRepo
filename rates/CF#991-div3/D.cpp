#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string input; cin >> input;
    vector<int> a;
    for(auto c : input) a.push_back(c - '0');
    for(int i = 1 ; i < a.size(); i++) {
        int pos = i;
        while(pos > 0 && a[pos] > a[pos - 1] + 1) {
            swap(a[pos], a[pos - 1]);
            pos--;
            a[pos]--;
        }
    }
    for(auto i : a) cout << i;
    cout << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
