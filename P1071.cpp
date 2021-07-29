#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<char, char> m;
string ans;
map<char, char> rev;

signed main() {
    string key, org, ins;
    cin >> key >> org >> ins;

    for (int i = 0; i < key.length(); i++) {
        if (m.count(key[i]) && m[key[i]] != org[i]) {
            printf("Failed");
            return 0;
        }
        if(rev.count(org[i]) && rev[org[i]]!=key[i]) {
            printf("Failed");
            return 0;
        }
        m[key[i]] = org[i];
        rev[org[i]]=key[i];
    }
    for (char c = 'A'; c <= 'Z'; c++)
        if (!m.count(c)) {
            printf("Failed");
            return 0;
        }

    for (int i = 0; i < ins.length(); i++) {
        ans.push_back(m[ins[i]]);
    }
    cout << ans << endl;
    return 0;
}