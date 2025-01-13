#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int kth = 0, klen = 0;
    bool inside = false;
    size_t front = 0;
    size_t kpos = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            if (!inside) {
                kth++;
                if(kth == k - 1) front = i;
                else if(kth == k) kpos = i;
                inside = true;
            }
            if (kth == k) klen++;
        } else if (s[i] == '0') {
            inside = false;
        }
    }
    for(size_t i = 0; i < s.length(); i++) {
        if(i == front) 
            for(int c = 1; c <= klen; c++) cout << 1;

        if(i == kpos) {
            i += klen - 1;
            continue;
        }
        cout << s[i];
    }
    endl(cout);
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
