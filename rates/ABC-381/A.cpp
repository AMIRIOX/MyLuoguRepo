#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5 + 10; //TODO

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n; string s;
    cin >> n >> s;
    if(n % 2 == 0) { cout << "No" << endl; return 0; }
    bool ok = true;
    for(int i = 0; i < (s.length() + 1) / 2 - 1; i++) if(s[i] != '1') { ok = false; break; }
    if(s[(s.length() + 1) / 2 - 1] != '/') { ok = false; }
    for(int i = (s.length() + 1) / 2; i < s.length(); i++) if(s[i] != '2') { ok = false; break; }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
