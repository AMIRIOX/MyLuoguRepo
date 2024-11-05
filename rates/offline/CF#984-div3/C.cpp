#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int k; cin >> k;
    map<int, int> mp;
    int cnt = 0;
    for(int i = 0; i < s.length() - 3; i++) {
        if(s[i] == '1' && s[i + 1] == '1' &&
            s[i + 2] == '0' && s[i + 3] == '0') {
            cnt++;
            mp[i] = 1; mp[i + 1] = 2; mp[i + 2] = 3; mp[i + 3] = 4;
        }
    }
    // mp 0-based
    // s 0-based
    // i 1-based
    for(int _i = 1; _i <= k; _i++) {
        int i, v;
        cin >> i >> v;
        i--;
        if(v != s[i] - '0') {
            s[i] = (v + '0');
            if(mp[i] > 0) {
                    cnt--;
                    if(mp[i] == 1 && i + 3 < s.length()) {
                        mp[i] = mp[i + 1] = mp[i + 2] = mp[i + 3] = 0;
                    }else if(mp[i] == 2 && i - 1 >= 0 && i + 2 < s.length()) {
                        mp[i - 1] = mp[i] = mp[i + 1] = mp[i + 2] = 0;
                    }else if(mp[i] == 3 && i - 2 >= 0 && i + 1 < s.length()) {
                        mp[i - 2] = mp[i - 1] = mp[i] = mp[i + 1] = 0;
                    }else if(mp[i] == 4 && i - 3 >= 0) {
                        mp[i - 3] = mp[i - 2] = mp[i - 1] = mp[i] = 0;
                    }
            }
            if(i + 3 < s.length() && 
                    s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
                cnt++;
                mp[i] = 1; mp[i + 1] = 2; mp[i + 2] = 3; mp[i + 3] = 4;
            }else if(i - 1 >= 0 && i + 2 < s.length() && 
                    s[i - 1] == '1' && s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '0') {
                cnt++;
                mp[i - 1] = 1; mp[i] = 2; mp[i + 1] = 3; mp[i + 2] = 4;
            }else if(i - 2 >= 0 && i + 1 < s.length() && 
                    s[i - 2] == '1' && s[i - 1] == '1' && s[i] == '0' && s[i + 1] == '0') {
                cnt++;
                mp[i - 2] = 1; mp[i - 1] = 2; mp[i] = 3; mp[i + 1] = 4;
            }else if(i - 3 >= 0 
                    && s[i - 3] == '1' && s[i - 2] == '1' && s[i - 1] == '0' && s[i] == '0') {
                cnt++;
                mp[i - 3] = 1; mp[i - 2] = 2; mp[i - 1] = 3; mp[i] = 4;
            } 
        }

        if(cnt) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

signed main() {
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
