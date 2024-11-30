#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    string s; cin >> s;
    for(int i = s.length() - 1; i >= 0; i--) {
        if(k && s[i] == '@') {
            s[i] = '.';
            k--;
        }
    }
    cout << s << endl;
    return 0;
}
