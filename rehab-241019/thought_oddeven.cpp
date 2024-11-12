#include <bits/stdc++.h>
using namespace std;

#define int long long
using i64 = long long;

inline int read() {
    char ch = (char) getchar();
    int flg = 1, val = 0;
    while(ch < '0' || ch > '9') {
        if(ch == '-') flg = 0;
        ch = (char) getchar();
    }
    while(ch >= '0' && ch <= '9') {
        val = (val << 1) + (val << 3) + (ch ^ 48);
        ch = (char) getchar();
    }
    return flg ? val : ~(val - 1);
}

void solve() {
    int n, k;
    n = read(), k = read();
    
    if(k % 2 == 0) {
        if((k / 2) % 2 == 0) printf("YES\n");
        else printf("NO\n");
    }else {
        int odd = 0;
        odd = (k - 1) / 2;
        if(n % 2 != 0) odd++;

        if(odd % 2 == 0) printf("YES\n");
        else printf("NO\n");
    }
}

signed main(void) {
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
