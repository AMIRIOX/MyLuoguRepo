#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 6e4 + 10;
int maxh[maxn];
signed main() {
    int l, h, r;
    while(scanf("%d %d %d", &l, &h, &r) != EOF) {
        for(int i = l; i < r; i++) maxh[i] = max(maxh[i], h);
    }
    for(int i = 1; i <= 50000; i++) {
        if(maxh[i] != maxh[i - 1]) {
            printf("%d %d ", i, maxh[i]);
        }
    }
    return 0;
}
