#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5 + 10; //TODO

int cnt[maxn];
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    string s; cin >> s;
    if(s.length() % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < s.length(); i += 2) {
        if(s[i] != s[i + 1]) {
            cout << "No" << endl;
            return 0;
        }
        cnt[s[i]] += 2;
        if(cnt[s[i]] != 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
