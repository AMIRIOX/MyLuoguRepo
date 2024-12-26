#include <cstdio>
#include <iostream>
// #define int long long
using namespace std;
const int maxn = 1e3;

int n=8, tot, vis[maxn][maxn];
void dfs(int cur) {
    if (cur == n)
        tot++;
    else
        for (int i = 0; i < n; i++) {
            if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) {
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
                dfs(cur + 1);
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
            }
        }
}
signed main() {
    dfs(0);
    cout << tot << endl;
    return 0;
}