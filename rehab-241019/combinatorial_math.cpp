#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

template <typename T>
T qpower(T a, T n) {
    T res = 1;
    while(n) {
        if(n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
signed main() {
    string s;
    cin >> s;
    int minn = 0x7fffffff, maxn = -0x7fffffff;
    for(size_t i = 0; i < s.length(); ++i) {
        minn = min(minn, s[i] - 'A' + 1);
        maxn = max(maxn, s[i] - 'A' + 1);
    }
    int tg = (minn - 1) + (26 - maxn);
    constexpr string::size_type BASE = 26;
    cout << qpower(BASE - 1, s.length()) - tg << endl;
    return 0;
}
