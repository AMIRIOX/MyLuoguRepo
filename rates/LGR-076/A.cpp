#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int base = 261;
const int mod = 10007;
int isSrchd[mod];
// map<string, int> ds;
inline int strHash(string str) {
    register int hashv = 1;
    for (register int i = 0; i < str.length(); i++) {
        hashv = (hashv * 1ll * base * str[i]) % mod;
    }
    return hashv;
}
inline int findst(string stra, string suba) {
    register int results = 0;
    char* resu = const_cast<char*>(stra.c_str());
    char* subst = const_cast<char*>(suba.c_str());
    while ((resu = std::strstr(resu, subst)) != nullptr) {
        ++results;
        ++resu;
    }
    return results;
}

signed main() {
    register int ans = 0;
    string x;
    cin >> x;
    // ds[x] = x.length();
    // abababab
    // 01234567
    for (register int i = 0; i < x.length(); i++) {
        for (register int j = i; j < x.length(); j++) {
            string cur = x.substr(i, j - i);
            if (cur.empty()) continue;
            if (register int hashval = strHash(cur); !isSrchd[hashval]) {
                // ds[cur] = 1;
                isSrchd[hashval]++;
                int nu = findst(x, cur);
                if (nu > ans) ans = nu;
            }
        }
    }
    // for (auto iv = ds.begin(); iv != ds.end(); iv++) {
    //     if (iv->second > ans) ans = iv->second;
    // }
    cout << ans;
    return 0;
}