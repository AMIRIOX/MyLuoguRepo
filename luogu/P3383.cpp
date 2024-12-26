#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e8 + 10;

inline int read() {
    int val = 0, flg = 1;
    char ch = (char) getchar();

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

vector<int> pri;
bool np[maxn];
int n, q;
signed main() {
    n = read(); q = read();
    for(int i = 2; i <= n; ++i) {
        if(!np[i]) pri.push_back(i);
        for(int prij: pri) {
            if(i * prij > n) break;
            np[i * prij] = true;
            if(i % prij == 0) break;
        }
    }
    for(int i = 1; i <= q; i++) {
        int v = read();
        printf("%d\n", pri[v - 1]);
    }
    return 0;
}
