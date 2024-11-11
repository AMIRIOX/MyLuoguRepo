#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int n;
int np[maxn], a[maxn];

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

int eratothenes_sieve(int N) {
    np[0] = np[1] = 1;
    int cnt = 0;
    for(int i = 2; i <= N / i; i++) {
        if(!np[i]) {
            cnt++;
            for(int j = i << 1; j <= N; j += i) 
                np[j] = 1;
        }
    }
    return cnt;
}
signed main() {
    n = read();
    eratothenes_sieve(1e6 + 5);
    for(int i = 1; i <= n; ++i) a[i] = read();
    int ans = -1, tot = 0;
    for(int i = 2; i <= n; ++i) {
        if(/*np[a[i] + a[i - 1]]*/a[i] % 2 == a[i - 1] % 2) {
            tot++;
            if(tot == 1) ans = i;
        }
    }
    if(tot <= 2 && ~ans) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
