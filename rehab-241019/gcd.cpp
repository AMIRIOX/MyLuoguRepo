#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 1e5 + 10;

int n;
int a[maxn];

inline int read() {
    char ch = (char) getchar_unlocked();
    int flg = 1, val = 0;
    while(ch < '0' || ch > '9') {
        if(ch == '-') flg = 0;
        ch = (char) getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9') {
        val = (val << 1) + (val << 3) + (ch ^ 48);
        ch = (char) getchar_unlocked();
    }
    return flg ? val : ~(val - 1);
}

inline int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}
signed main() {
    n = read();
    int ansv = 0;
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        if(i == 1) ansv = a[1];
        else ansv = gcd(a[i], ansv);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += (a[i] / ansv - 1);
    }
    cout << ans << endl;
    return 0;
}
