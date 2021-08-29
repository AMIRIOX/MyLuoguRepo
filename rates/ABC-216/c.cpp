#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 200;
bool getans = false;
long long tgt;
char ans[maxn];
void dfs(long long lvl, long long n) {
    if (!getans) {
        // printf("%lld %lld\n", lvl, n);
        if (!n) {
            getans = true;
            for (int i = lvl - 1; i >= 1; i--)
                printf("%c", ans[i]);
            puts("");
        } else {
            if (n % 2 == 0) {
                ans[lvl] = 'B';
                dfs(lvl + 1, n / 2);
            }
            ans[lvl] = 'A';
            dfs(lvl + 1, n - 1);
        }
    }
}
signed main() {
    cin >> tgt;
    dfs(1, tgt);
    return 0;
}