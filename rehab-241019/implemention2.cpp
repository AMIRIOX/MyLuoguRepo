#include <bits/stdc++.h>
using namespace std;

signed main() {
    string s;
    cin >> s;
    bool got = false;
    int ans = 0, n = s.length();
    for(int len = 2; len <= n && !got; len++) {
        for(int i = 0; i + len - 1 < s.length(); i++) {
            bool ok = true;
            for(int j = 0; j < len / 2; j++) {
                if(s[i + j] != s[i + len - j - 1]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                /*
                for(int j = 0; j < len; j++) {
                    cout << s[i + j];
                }
                cout << endl;
                */
                ans = len; got = true;
                break;
            }
        }
    }
    cout << (ans ? ans : -1) << endl;
    return 0;
}
