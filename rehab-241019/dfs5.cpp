#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
char mp[maxn][maxn];
int r, c, k, ans;

// 注意搜索方向, 不能转弯的
void dfs(int x, int y, int cur, int direct) {
    if(cur == k) {
        ans++;
    }
    if(x + 1 <= r && mp[x + 1][y] == '.' && !direct) dfs(x + 1, y, cur + 1, direct);
    if(y + 1 <= c && mp[x][y + 1] == '.' && direct) dfs(x, y + 1, cur + 1, direct);
}
signed main() {
    cin >> r >> c >> k;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            cin >> mp[i][j];
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(mp[i][j] == '.') {
                dfs(i, j, 1, 0);
                dfs(i, j, 1, 1);
            }
        }
    }
    cout << (k == 1 ? ans/2 : ans) << endl;
    return 0;
}
